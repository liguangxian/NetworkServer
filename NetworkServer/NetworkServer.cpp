#include <QTcpServer>
#include <QTcpSocket>

#include <QtSql>
#include <QUuid>
#include <QTabWidget>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QListWidgetItem>

#include "NetworkServer.h"
#include "command_def.h"
using namespace std;
NetworkServer::NetworkServer(QWidget *parent)
	: QMainWindow(parent), m_tcpServer(0), m_database(0)
{
	ui.setupUi(this);
	ui.m_btSend->setDisabled(true);
	QObject::connect(ui.m_btStart, SIGNAL(clicked()), this, SLOT(OnStartClick()));
	QObject::connect(ui.m_btSend, SIGNAL(clicked()), this, SLOT(OnSendClick()));

	if (m_database == 0)
	{
		m_database = new QSqlDatabase;
	}
	/**m_database = QSqlDatabase::addDatabase("QMYSQL");
	m_database->setHostName("127.0.0.1");
	m_database->setUserName("root");
	m_database->setPassword("123");
	m_database->setDatabaseName("im");
	*/
	*m_database = QSqlDatabase::addDatabase("QMYSQL");
	m_database->setHostName("127.0.0.1");
	m_database->setUserName("root");
	m_database->setPassword("123456");
	m_database->setDatabaseName("im");

	if (!m_database->open())
	{
		return;
	}
	QSqlQuery query;
	query.prepare("select * from users;");
	if (!query.isNull(0))
	{
		return;
	}
	if (query.exec())
	{
		while (query.next())
		{
			QString name = query.value("name").toString();
			QListWidgetItem *item = new QListWidgetItem(ui.listWidget);
			item->setText(name);

			QPixmap pix;
			QByteArray bytes = query.value("img").toByteArray();

#ifdef _DEBUG
			QFile file("C:\\Users\\me\\Desktop\\test.png");
			file.open(QFile::WriteOnly);
			file.write(bytes);
			file.close();
#endif
			if (pix.loadFromData(bytes))
			{
				QIcon icon(pix);
				item->setIcon(icon);
			}
		}
	}

}

void NetworkServer::OnStartClick()
{
	if (m_tcpServer == 0)
	{
		m_tcpServer = new QTcpServer(this);
		QObject::connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));

	}

	if (!m_tcpServer->listen(QHostAddress::Any, 8001))
	{
		return;
	}

	ui.m_btStart->setText("started");
	ui.m_btStart->setDisabled(true);
}

void NetworkServer::OnNewConnection()
{
	QTcpSocket* client = m_tcpServer->nextPendingConnection();

	if (client == 0)
	{
		return;
	}

	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(OnClientReadyRead()));
	ui.m_btSend->setEnabled(true);

	m_clients.push_back(client);
	m_clientBuffs.insert(std::pair<QTcpSocket*, std::string*>(client, new string));
}

void NetworkServer::OnSendClick()
{
	for (std::list<QTcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); it++)
	{
		QTcpSocket* socket = *it;
		if (socket->state() == QAbstractSocket::UnconnectedState)
		{
			it = m_clients.erase(it);
			string *val = m_clientBuffs[*it];
			//清理断开的链接以及占用的资源
			m_clientBuffs.erase(*it);
			delete val;
			delete socket;
			continue;
		}
		socket->write(QByteArray::fromStdString(ui.lineEdit->text().toStdString()));
	}
}

void NetworkServer::OnClientReadyRead()
{
	for (std::list<QTcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); it++)
	{
		QTcpSocket* socket = *it;
		if (!socket->isReadable())
		{
			continue;
		}


		QByteArray bytes = socket->readAll();

		string * buf = m_clientBuffs[socket];

		buf->append(bytes.toStdString());



		Package package;
		package.from_data(*buf);
		//	QString fff = QString::fromStdString(*buf);
		CommandRegister* cmd = (CommandRegister*)(package.getcmd());
		if (cmd == 0)
		{
			continue;
		}
		//socket->write(QByteArray::fromStdString(ui.lineEdit->text().toStdString()));
#ifdef _DEBUG
		QFile file("C:\\Users\\me\\Desktop\\test1.png");
		file.open(QFile::WriteOnly);
		file.write(cmd->img.data(), cmd->img.length());
		file.close();
#endif
		if (!m_database->isOpen() && !m_database->open())
		{
			continue;
		}
		QSqlQuery query;
		query.prepare("insert into users(id,name,pwd,img) values(:id,:name,:pwd,:img);");
		query.bindValue(":id", QUuid::createUuid().toString());
		query.bindValue(":name", cmd->name.c_str());
		query.bindValue(":pwd", cmd->pwd.c_str());
		query.bindValue(":img", QByteArray::fromStdString(cmd->img));
		if (!query.exec())
		{
			qDebug() << query.lastError();
		}
	}
}
