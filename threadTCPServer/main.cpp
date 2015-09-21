#include <QtGui/QApplication>
#include "threadtcpserver.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr( QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings( QTextCodec::codecForLocale());
	QApplication a(argc, argv);
	threadTCPServer w;
	w.show();
	return a.exec();
}
