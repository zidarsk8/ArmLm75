/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Feb 23 20:41:26 2011
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     130,  125,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     187,  181,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_clearButton_clicked()\0"
    "on_getLastTempButton_clicked()\0"
    "on_getTempButton_clicked()\0"
    "on_getTempAllButton_clicked()\0text\0"
    "DataReceived(QString)\0ConnectError()\0"
    "refreshData()\0event\0timerEvent(QTimerEvent*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_clearButton_clicked(); break;
        case 1: on_getLastTempButton_clicked(); break;
        case 2: on_getTempButton_clicked(); break;
        case 3: on_getTempAllButton_clicked(); break;
        case 4: DataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: ConnectError(); break;
        case 6: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
