#include "filethread.h"

/*filethread::filethread(QObject *parent)
	: QThread(parent)
{

}*/
filethread::filethread(int socketDescriptor,QObject *parent)
	:QThread(parent),socketDescriptor(socketDescriptor)
{

}


filethread::~filethread()
{

}

void filethread::run()
{
	QTcpSocket tcpSocket;
	if(!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket.error());
		return ;
	}


	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("testdb");
	db.setUserName("root");
	db.setPassword("");

	if (!db.open())
	{
		QSqlError e = db.lastError();
		qDebug()<<e.text()<<'\n';
		return ;
	}

	else
	{
		qDebug()<< "open success !"<<'\n';
	}
	//connectDB();

	QSqlQuery query;
	query.exec("select count(1) from filefolder");
	query.next();
	int fileNo = query.value(0).toInt();
	qDebug() << fileNo;

	query.exec("select * from filefolder");
	

	//qDebug() << query.value(0).toString()<< query.value(1).toString()<< query.value(2).toString() << query.value(3).toString();
	QString FileInfo;
	
	for (int m_i = 0;m_i<fileNo;m_i++)
	{
		query.next();
		QString FileName = query.value(0).toString();
		QString Size = query.value(1).toString();
		QString CreatedTime = query.value(2).toString();
		QString LastModifiedTime = query.value(3).toString();
		
		/*QTextCodec *code= QTextCodec::codecForName("utf8");
		QString fileInf = QString("\n%1\t%2\t%3\t%4").arg(FileName).arg(Size).arg(CreatedTime).arg(LastModifiedTime);
		qDebug() << fileInf;
		QByteArray tmpQba = code->fromUnicode(fileInf);
		out << tmpQba;*/
		QString tmpInfo = QString("\n%1\t%2\t%3\t%4").arg(FileName).arg(Size).arg(CreatedTime).arg(LastModifiedTime);
		FileInfo = FileInfo.append(tmpInfo);
		//qDebug() << query.value(0).toString()<< query.value(1).toString()<< query.value(2).toString() << query.value(3).toString();
	}

	//out << '\n' + FileName + '\t' + Size + '\t' + CreatedTime  + '\t' + LastModifiedTime;

	//query.next();
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_4);
	out << (quint16)0;
	
	out << FileInfo;
	qDebug() << FileInfo;

	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));
	qDebug() << (quint16)(block.size() - sizeof(quint16));

	tcpSocket.write(block);
	tcpSocket.flush();

	//msleep(1000);
	

	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}

/*void filethread::connectDB()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("testdb");
	db.setUserName("root");
	db.setPassword("");
	
	if (!db.open())
	{
		QSqlError e = db.lastError();
		qDebug()<<e.text()<<'\n';
		return ;
	}

	else
	{
		qDebug()<< "open success !"<<'\n';
	}

}*/
