#include "serverthread.h"

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
//创建TCP socket
	QTcpSocket tcpSocket;
	if(!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket.error());
		return ;
	}

//在Server端建立数据库链接
	QSqlDatabase filedb = QSqlDatabase::addDatabase("QMYSQL");
	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	filedb.setHostName("localhost");
    filedb.setDatabaseName("testDB");
    filedb.setUserName("root");
    filedb.setPassword("");
    if (!filedb.open())
	{
		QSqlError e = filedb.lastError();
		qDebug()<<e.text()<<'\n';
		//label->setText("Connectiong status:"+e.text());
		//QMessageBox::critical(this,tr("Server"),tr("Unable to connect to the database : %1.").arg(e.text()));
		return ;
	}

	else
	{
		qDebug()<< "open success !"<<'\n';
		//label->setText("Connectiong status: Open success!");
	}

//绑定数据库的表操�?
	QSqlQuery query;
	query.exec("select count(1) from data");
	query.next();
	int j = query.value(0).toInt();
	qDebug() << j;

//将�中的条目发�出�
	//while(!txtInput.atEnd())
	for(int i=1;i<=j;i++)
	{  
		QSqlQuery query;
	    
	    QByteArray block;
		QDataStream out(&block,QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_4);
		QString command = QString("select * from data where Number = '%1'").arg(i);
	    //lineStr = txtInput.readLine();
	    //执行查询操作
	    //query.exec("select * from data where Number = '%1'").arg(i);
	    query.exec(command);
	    query.next();

	    QString Number = query.value(0).toString();
	    QString Component = query.value(1).toString();
	    QString Date = query.value(2).toString();
	    QString Time = query.value(3).toString();
	    QString North = query.value(4).toString();
	    QString East = query.value(5).toString();
	    QString Down = query.value(6).toString();
	    QString Mom_Mag = query.value(7).toString();

	    out << (quint16)0;
	    //out << currentTime()+'\n'+lineStr;
	    out << '\n' + currentTime() + '\n'+ Number + ' ' + Component + ' ' + Date  + ' ' + Time + ' ' + North + ' ' + East  + ' ' + Down + ' ' + Mom_Mag;
	    //out << query.value(3).toString()+' '+query.value(4).toString()+' '+query.value(5).toString();

	    out.device()->seek(0);
	    out << (quint16)(block.size() - sizeof(quint16)); 

	    qDebug() << (quint16)(block.size() - sizeof(quint16));
	    //qDebug() << block.toHex();
		
		tcpSocket.write(block);
		tcpSocket.flush();

		qDebug() << block.isEmpty();
		//block.clear();
		msleep(1000);
	}  
	  
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
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

/**************************************************local txt testing***************************************************/
/*void serverthread::run()
{
	QFile f("D:\\Desktop\\research\\data.txt");
	//QFile f("D:\1-6 event data");
	
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text))  
	{  
	    qDebug() << "Open file failed." << endl;  
	    return ;  
	}

	QTcpSocket tcpSocket;
	if(!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket.error());
		return ;
	}

	QTextStream txtInput(&f);  
	QString lineStr;  
	
	while(!txtInput.atEnd())
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
		
		tcpSocket.write(block);
		tcpSocket.flush();

		qDebug() << block.isEmpty();
		//block.clear();
		msleep(1000);
	}  
	  
	f.close(); 
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}*/
/**************************************************local txt testing***************************************************/