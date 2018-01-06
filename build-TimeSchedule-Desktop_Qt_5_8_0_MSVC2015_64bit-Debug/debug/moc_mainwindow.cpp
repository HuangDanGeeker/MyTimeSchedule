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
#include <QtCore/QList>
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
    QByteArrayData data[26];
    char stringdata0[334];
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
QT_MOC_LITERAL(5, 43, 16), // "MissionUpdateAll"
QT_MOC_LITERAL(6, 60, 14), // "QList<MISSION>"
QT_MOC_LITERAL(7, 75, 8), // "missions"
QT_MOC_LITERAL(8, 84, 13), // "MissionDelete"
QT_MOC_LITERAL(9, 98, 6), // "rowNum"
QT_MOC_LITERAL(10, 105, 14), // "AbortTerminate"
QT_MOC_LITERAL(11, 120, 16), // "SetTerminateTime"
QT_MOC_LITERAL(12, 137, 18), // "PauseTerminateTime"
QT_MOC_LITERAL(13, 156, 10), // "addMission"
QT_MOC_LITERAL(14, 167, 5), // "title"
QT_MOC_LITERAL(15, 173, 7), // "remarks"
QT_MOC_LITERAL(16, 181, 9), // "startDate"
QT_MOC_LITERAL(17, 191, 7), // "endDate"
QT_MOC_LITERAL(18, 199, 10), // "infromTime"
QT_MOC_LITERAL(19, 210, 15), // "achievePercence"
QT_MOC_LITERAL(20, 226, 13), // "deleteMission"
QT_MOC_LITERAL(21, 240, 13), // "updateMission"
QT_MOC_LITERAL(22, 254, 16), // "updateAllMission"
QT_MOC_LITERAL(23, 271, 18), // "abortTerminateSlot"
QT_MOC_LITERAL(24, 290, 20), // "setTerminateTimeSlot"
QT_MOC_LITERAL(25, 311, 22) // "pauseTerminateTimeSlot"

    },
    "MainWindow\0MissionUpdate\0\0PMISSION\0"
    "mission\0MissionUpdateAll\0QList<MISSION>\0"
    "missions\0MissionDelete\0rowNum\0"
    "AbortTerminate\0SetTerminateTime\0"
    "PauseTerminateTime\0addMission\0title\0"
    "remarks\0startDate\0endDate\0infromTime\0"
    "achievePercence\0deleteMission\0"
    "updateMission\0updateAllMission\0"
    "abortTerminateSlot\0setTerminateTimeSlot\0"
    "pauseTerminateTimeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       8,    1,  100,    2, 0x06 /* Public */,
      10,    0,  103,    2, 0x06 /* Public */,
      11,    1,  104,    2, 0x06 /* Public */,
      12,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  108,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,
      13,    6,  112,    2, 0x0a /* Public */,
      20,    0,  125,    2, 0x0a /* Public */,
      21,    0,  126,    2, 0x0a /* Public */,
      21,    1,  127,    2, 0x0a /* Public */,
      22,    0,  130,    2, 0x0a /* Public */,
      23,    0,  131,    2, 0x0a /* Public */,
      24,    1,  132,    2, 0x0a /* Public */,
      25,    0,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    2,
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
        case 1: _t->MissionUpdateAll((*reinterpret_cast< QList<MISSION>(*)>(_a[1]))); break;
        case 2: _t->MissionDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->AbortTerminate(); break;
        case 4: _t->SetTerminateTime((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 5: _t->PauseTerminateTime(); break;
        case 6: _t->addMission(); break;
        case 7: _t->addMission((*reinterpret_cast< PMISSION(*)>(_a[1]))); break;
        case 8: _t->addMission((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 9: _t->deleteMission(); break;
        case 10: _t->updateMission(); break;
        case 11: _t->updateMission((*reinterpret_cast< PMISSION(*)>(_a[1]))); break;
        case 12: _t->updateAllMission(); break;
        case 13: _t->abortTerminateSlot(); break;
        case 14: _t->setTerminateTimeSlot((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 15: _t->pauseTerminateTimeSlot(); break;
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
            typedef void (MainWindow::*_t)(QList<MISSION> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionUpdateAll)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::MissionDelete)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::AbortTerminate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SetTerminateTime)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::PauseTerminateTime)) {
                *result = 5;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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
void MainWindow::MissionUpdateAll(QList<MISSION> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::MissionDelete(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::AbortTerminate()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::SetTerminateTime(QTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::PauseTerminateTime()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
