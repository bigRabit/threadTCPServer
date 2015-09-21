#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

class serverthread : public QThread
{
	Q_OBJECT

public:
	//serverthread(QObject *parent);
	serverthread(int socketDescriptor,QObject *parent);
	~serverthread();

	void run();

signals:
	void error(QTcpSocket::SocketError SocketError);

private:
	int socketDescriptor;
	QString currentTime();
//signals:
	//void stringChanged(const QString&);
};

#endif // SERVERTHREAD_H
