#ifndef FILESERVER_H
#define FILESERVER_H

#include <QTcpServer>

class fileserver : public QTcpServer
{
	Q_OBJECT

public:
	fileserver(QObject *parent = 0);
	~fileserver();

//private:
protected:
	void incomingConnection(int socketDescriptor);
	
};

#endif // FILESERVER_H
