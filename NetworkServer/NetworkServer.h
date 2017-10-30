#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NetworkServer.h"
#include <QSqlDatabase>
#include <list>
#include <map>
class QTcpServer;
class QTcpSocket;


class NetworkServer : public QMainWindow
{
	Q_OBJECT

public:
	NetworkServer(QWidget *parent = Q_NULLPTR);
	private slots:
	void OnStartClick();
	void OnNewConnection();
	void OnSendClick();
	void OnClientReadyRead();


private:
	Ui::NetworkServerClass ui;
	QTcpServer* m_tcpServer;
	std::list<QTcpSocket*> m_clients;
	std::map<QTcpSocket*, std::string*> m_clientBuffs;
	QSqlDatabase * m_database;
};
