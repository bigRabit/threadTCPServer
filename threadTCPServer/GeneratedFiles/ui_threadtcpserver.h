/********************************************************************************
** Form generated from reading ui file 'threadtcpserver.ui'
**
** Created: Fri Jul 17 15:19:44 2015
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_THREADTCPSERVER_H
#define UI_THREADTCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class Ui_threadTCPServerClass
{
public:

    void setupUi(QDialog *threadTCPServerClass)
    {
    if (threadTCPServerClass->objectName().isEmpty())
        threadTCPServerClass->setObjectName(QString::fromUtf8("threadTCPServerClass"));
    threadTCPServerClass->resize(600, 400);

    retranslateUi(threadTCPServerClass);

    QMetaObject::connectSlotsByName(threadTCPServerClass);
    } // setupUi

    void retranslateUi(QDialog *threadTCPServerClass)
    {
    threadTCPServerClass->setWindowTitle(QApplication::translate("threadTCPServerClass", "threadTCPServer", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(threadTCPServerClass);
    } // retranslateUi

};

namespace Ui {
    class threadTCPServerClass: public Ui_threadTCPServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADTCPSERVER_H
