#ifndef THREADTCPSERVER_H
#define THREADTCPSERVER_H

#include <QtGui/QDialog>
#include "tcpserver.h"
#include <QGridLayout>

#include "ui_threadtcpserver.h"

class QLabel;
class QPushButton;
class QTextEdit;

class threadTCPServer : public QDialog
{
	Q_OBJECT

public:
	threadTCPServer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~threadTCPServer();

private:
	Ui::threadTCPServerClass ui;
	QLabel *statusLabel;
	QPushButton *closeButton;
	QPushButton *stopButton;
	QPushButton *continueButton;
	QTextEdit *textEdit;
	QGridLayout *mainLayout;

	tcpserver server;
};

#endif // THREADTCPSERVER_H
