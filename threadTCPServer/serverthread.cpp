#include "serverthread.h"

#include <QtNetwork>
#include <QDebug>
#include <QString>

/*serverthread::serverthread(QObject *parent)
	: QThread(parent)
{

}*/
serverthread::serverthread(int socketDescriptor,QObject *parent)
	:QThread(parent),socketDescriptor(socketDescriptor)
{

}

serverthread::~serverthread()
{

}

void serverthread::run()
{
	QFile f("D:\\Desktop\\research\\data2.txt");  
	
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text))  
	{  
	    qDebug() << "Open file failed." << endl;  
	    return ;  
	}

	QTcpSocket *tcpSocket = new QTcpSocket;
	if(!tcpSocket->setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket->error());
		return ;
	}

	//QTcpSocket *clientConnection = p_tcpServer.nextPendingConnection();
	//connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));

	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_4);

  
	QTextStream txtInput(&f);  
	QString lineStr;  
	
	block.resize(0);
	//while(!txtInput.atEnd())
	for(int i=0;i<=4;++i)  
	{  
/*************************************test data************************************************/	  
		/*out << (quint16)0;
		out << (tr("hello"));
		out.device()->seek(0);
		out << (quint16)(block.size()-sizeof(quint16));
		
		qDebug() << QString(block);
		tcpSocket->write(block); 
	    tcpSocket->flush();
	    block.clear();*/
/*************************************test data************************************************/

	    //pause.lock();
		QString lineStr;
	    lineStr = txtInput.readLine(); 
		//out << (quint16)0;

	    //qDebug() << (quint16)(sizeof(qint8));
		//qDebug() << lineStr;
		
		//out.device()->seek(0);
		quint16 len = lineStr.size();
		out << len;
		//out << (quint16)(block.size()-sizeof(quint16));
		out << lineStr;

		qDebug() << lineStr.toStdString().c_str();
		qDebug() << (quint16)block.size()-sizeof(quint16);
		//qDebug() << lineStr.size();
		
		/*QString string;
		string = QString(block);
		qDebug() << string;*/
	    
	    tcpSocket->write(block); 
	    tcpSocket->flush();
	    //emit stringChanged(lineStr);
	    qDebug() << block.isEmpty();
	    
	    block.clear();
	    block.resize(0);
	   
	    qDebug() << block.isEmpty();
	    //block.clear();
	    msleep(2000);

	   //pause.unlock();
	}  
	  
	f.close(); 
	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
}
