#ifndef FILETHREAD_H
#define FILETHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

class filethread : public QThread
{
	Q_OBJECT

public:
	filethread(int socketDescriptor,QObject *parent);
	~filethread();

	void run();

signals:
	void error(QTcpSocket::SocketError SocketError);

private:
	int socketDescriptor;
	//QSqlDatabase db;
	//void connectDB();
};

#endif // FILETHREAD_H
