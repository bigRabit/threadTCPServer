#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class tcpserver : public QTcpServer
{
	Q_OBJECT

public:
	tcpserver(QObject *parent = 0);
	~tcpserver();

protected:
	void incomingConnection(int socketDescriptor);

//private slots:
//	void changeString(const QString&);
};

#endif // TCPSERVER_H
