/****************************************************************************
** Meta object code from reading C++ file 'application.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Teaching-Activities-Of-The-University-master/Application/application.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_application_t {
    QByteArrayData data[14];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_application_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_application_t qt_meta_stringdata_application = {
    {
QT_MOC_LITERAL(0, 0, 11), // "application"
QT_MOC_LITERAL(1, 12, 23), // "on_showTeachers_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_showWorkplans_clicked"
QT_MOC_LITERAL(4, 62, 22), // "on_showPulpits_clicked"
QT_MOC_LITERAL(5, 85, 23), // "on_showEditions_clicked"
QT_MOC_LITERAL(6, 109, 19), // "on_showLogs_clicked"
QT_MOC_LITERAL(7, 129, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(8, 150, 21), // "on_editButton_clicked"
QT_MOC_LITERAL(9, 172, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(10, 196, 21), // "on_funcButton_clicked"
QT_MOC_LITERAL(11, 218, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(12, 245, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 257, 5) // "index"

    },
    "application\0on_showTeachers_clicked\0"
    "\0on_showWorkplans_clicked\0"
    "on_showPulpits_clicked\0on_showEditions_clicked\0"
    "on_showLogs_clicked\0on_addButton_clicked\0"
    "on_editButton_clicked\0on_deleteButton_clicked\0"
    "on_funcButton_clicked\0on_tableView_doubleClicked\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_application[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<application *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_showTeachers_clicked(); break;
        case 1: _t->on_showWorkplans_clicked(); break;
        case 2: _t->on_showPulpits_clicked(); break;
        case 3: _t->on_showEditions_clicked(); break;
        case 4: _t->on_showLogs_clicked(); break;
        case 5: _t->on_addButton_clicked(); break;
        case 6: _t->on_editButton_clicked(); break;
        case 7: _t->on_deleteButton_clicked(); break;
        case 8: _t->on_funcButton_clicked(); break;
        case 9: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject application::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_application.data,
    qt_meta_data_application,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *application::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_application.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE