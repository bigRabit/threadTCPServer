#include "fileserver.h"
#include "filethread.h"

fileserver::fileserver(QObject *parent)
	: QTcpServer(parent)
{

}

fileserver::~fileserver()
{

}

void fileserver::incomingConnection(int socketDescriptor)
{
	filethread *fThread = new filethread(socketDescriptor,this);
	//connect(thread,SIGNAL(stringChanged(const Qstring&)),this,SLOT(changeString(const QString&)));
	connect(fThread,SIGNAL(finished()),fThread,SLOT(deleteLater()));
	fThread->start();	
}