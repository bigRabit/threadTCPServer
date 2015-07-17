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
	QFile f("D:\\Desktop\\research\\data.txt");  
	
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

	QTextStream txtInput(&f);  
	QString lineStr;  
	
	for(int i=0;i<=4;++i)  
	{  

	    QByteArray block;
		QDataStream out(&block,QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_4);

	    lineStr = txtInput.readLine();

	    out << (quint16)0;
	    out << currentTime()+'\n'+lineStr;
	    out.device()->seek(0);
	    out << (quint16)(block.size() - sizeof(quint16)); 

	    qDebug() << (quint16)(block.size() - sizeof(quint16));
	    qDebug() << block.toHex();
		
		tcpSocket->write(block);
		tcpSocket->flush();

		qDebug() << block.isEmpty();
		//block.clear();
		msleep(1000);
	}  
	  
	f.close(); 
	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
}

QString serverthread::currentTime()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
 	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	return current_date;
}

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