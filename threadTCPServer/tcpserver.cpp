#include "tcpserver.h"
#include "serverthread.h"

tcpserver::tcpserver(QObject *parent)
	: QTcpServer(parent)
{

}

tcpserver::~tcpserver()
{

}

void tcpserver::incomingConnection(int socketDescriptor)
{
	serverthread *thread = new serverthread(socketDescriptor,this);
	//connect(thread,SIGNAL(stringChanged(const Qstring&)),this,SLOT(changeString(const QString&)));
	connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
	thread->start();
}
