#include "NetworkServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NetworkServer w;
	w.show();
	return a.exec();
}
