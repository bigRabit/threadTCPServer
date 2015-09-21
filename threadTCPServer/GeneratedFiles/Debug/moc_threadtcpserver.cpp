/****************************************************************************
** Meta object code from reading C++ file 'threadtcpserver.h'
**
** Created: Wed Sep 16 09:33:14 2015
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../threadtcpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadtcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_threadTCPServer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_threadTCPServer[] = {
    "threadTCPServer\0"
};

const QMetaObject threadTCPServer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_threadTCPServer,
      qt_meta_data_threadTCPServer, 0 }
};

const QMetaObject *threadTCPServer::metaObject() const
{
    return &staticMetaObject;
}

void *threadTCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_threadTCPServer))
	return static_cast<void*>(const_cast< threadTCPServer*>(this));
    return QDialog::qt_metacast(_clname);
}

int threadTCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
