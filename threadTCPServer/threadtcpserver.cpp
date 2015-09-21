#include <QtGui>
#include <QtNetwork>

#include <stdlib.h>

#include "threadtcpserver.h"
#include "tcpserver.h"
#include "fileserver.h"

threadTCPServer::threadTCPServer(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	//ui.setupUi(this);
	statusLabel = new QLabel;
	closeButton = new QPushButton(tr("Close"));
	stopButton = new QPushButton(tr("Stop"));
	continueButton = new QPushButton(tr("Continue"));
	textEdit = new QTextEdit(this);
	mainLayout = new QGridLayout(this);

	stopButton->setAutoDefault(false);
	continueButton->setAutoDefault(false);

	mainLayout->addWidget(statusLabel,0,0);
	mainLayout->addWidget(stopButton,0,1);
	mainLayout->addWidget(continueButton,0,2);
	mainLayout->addWidget(closeButton,0,3);
	mainLayout->addWidget(textEdit,1,0,4,4);
	setLayout(mainLayout);

	if(!server.listen(QHostAddress::LocalHost,23333))
	{
		QMessageBox::critical(this,tr("Tcp Server"),tr("Unable to start the server : %1.").arg(server.errorString()));
		close();
		return;
	}

	if(!fServer.listen(QHostAddress::LocalHost,23334))
	{
		QMessageBox::critical(this,tr("File Server"),tr("Unable to start the server : %1.").arg(server.errorString()));
		close();
		return;
	}

	statusLabel->setText(tr("The server is running ~"));

	connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

	setWindowTitle(tr("The Tcp Server . "));
}

threadTCPServer::~threadTCPServer()
{

}
