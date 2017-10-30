/********************************************************************************
** Form generated from reading UI file 'NetworkServer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSERVER_H
#define UI_NETWORKSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkServerClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QPushButton *m_btStart;
    QLineEdit *lineEdit;
    QPushButton *m_btSend;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NetworkServerClass)
    {
        if (NetworkServerClass->objectName().isEmpty())
            NetworkServerClass->setObjectName(QStringLiteral("NetworkServerClass"));
        NetworkServerClass->resize(851, 528);
        centralWidget = new QWidget(NetworkServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 821, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);

        gridLayout->addWidget(textEdit, 0, 1, 1, 4);

        m_btStart = new QPushButton(gridLayoutWidget);
        m_btStart->setObjectName(QStringLiteral("m_btStart"));

        gridLayout->addWidget(m_btStart, 1, 4, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 3);

        m_btSend = new QPushButton(gridLayoutWidget);
        m_btSend->setObjectName(QStringLiteral("m_btSend"));

        gridLayout->addWidget(m_btSend, 1, 3, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        NetworkServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NetworkServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 851, 26));
        NetworkServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NetworkServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NetworkServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NetworkServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NetworkServerClass->setStatusBar(statusBar);

        retranslateUi(NetworkServerClass);

        QMetaObject::connectSlotsByName(NetworkServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *NetworkServerClass)
    {
        NetworkServerClass->setWindowTitle(QApplication::translate("NetworkServerClass", "NetworkServer", Q_NULLPTR));
        m_btStart->setText(QApplication::translate("NetworkServerClass", "start", Q_NULLPTR));
        m_btSend->setText(QApplication::translate("NetworkServerClass", "send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NetworkServerClass: public Ui_NetworkServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSERVER_H
