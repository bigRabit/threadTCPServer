#include <QtGui/QApplication>
#include "threadtcpserver.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	threadTCPServer w;
	w.show();
	return a.exec();
}
