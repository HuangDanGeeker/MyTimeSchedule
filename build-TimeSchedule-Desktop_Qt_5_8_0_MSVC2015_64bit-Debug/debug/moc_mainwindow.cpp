/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TimeSchedule/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "MissionUpdate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "PMISSION"
QT_MOC_LITERAL(4, 35, 7), // "mission"
QT_MOC_LITERAL(5, 43, 6), // "rowNum"
QT_MOC_LITERAL(6, 50, 16), // "MissionUpdateAll"
QT_MOC_LITERAL(7, 67, 9), // "MISSION[]"
QT_MOC_LITERAL(8, 77, 8), // "missions"
QT_MOC_LITERAL(9, 86, 3), // "len"
QT_MOC_LITERAL(10, 90, 13), // "MissionDelete"
QT_MOC_LITERAL(11, 104, 10), // "addMission"
QT_MOC_LITERAL(12, 115, 5), // "title"
QT_MOC_LITERAL(13, 121, 7), // "remarks"
QT_MOC_LITERAL(14, 129, 9), // "startDate"
QT_MOC_LITERAL(15, 139, 7), // "endDate"
QT_MOC_LITERAL(16, 147, 10), // "infromTime"
QT_MOC_LITERAL(17, 158, 15), // "achievePercence"
QT_MOC_LITERAL(18, 174, 13), // "deleteMission"
QT_MOC_LITERAL(19, 188, 13), // "updateMission"
QT_MOC_LITERAL(20, 202, 16) // "updateAllMission"

    },
    "MainWindow\0MissionUpdate\0\0PMISSION\0"
    "mission\0rowNum\0MissionUpdateAll\0"
    "MISSION[]\0missions\0len\0MissionDelete\0"
    "addMission\0title\0remarks\0startDate\0"
    "endDate\0infromTime\0achievePercence\0"
    "deleteMission\0updateMission\0"
    "updateAllMission"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       1,    2,   72,    2, 0x06 /* Public */,
       6,    2,   77,    2, 0x06 /* Public */,
      10,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      11,    6,   89,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,
      19,    1,  104,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    5,    4,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MissionUpdate((*reinterpret_cast< PMISSION(*)>(_a[1]))); break;
        case 1: _t->MissionUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< PMISSION(*)>(_a[2]))); break;
        case 2: _t->MissionUpdateAll((*reinterpret_cast< MISSION(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->MissionDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addMission(); break;
        case 5: _t->addMission((*reinterpret_cast< PMISSION(*)>(_a[1]))); break;
        case 6: _t->addMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 7: _t->deleteMission(); break;
        case 8: _t->updateMission(); break;
        case 9: _t->updateMission((*reinterpret_cast< PMISSION(*)>(_a[1]))); break;
        case 10: _t->updateAllMission(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(PMISSION );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , PMISSION );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(MISSION [], int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionUpdateAll)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionDelete)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::MissionUpdate(PMISSION _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::MissionUpdate(int _t1, PMISSION _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::MissionUpdateAll(MISSION _t1[], int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::MissionDelete(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
