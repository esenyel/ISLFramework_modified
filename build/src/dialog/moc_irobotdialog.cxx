/****************************************************************************
** Meta object code from reading C++ file 'irobotdialog.h'
**
** Created: Mon Oct 19 12:42:25 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/dialog/irobotdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irobotdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IRobotDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   13,   13,   13, 0x08,
      65,   13,   13,   13, 0x08,
      92,   13,   13,   13, 0x08,
     118,   13,   13,   13, 0x08,
     144,   13,   13,   13, 0x08,
     170,   13,   13,   13, 0x08,
     200,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IRobotDialog[] = {
    "IRobotDialog\0\0setFirstOrientation()\0"
    "on_butRobotForward_clicked()\0"
    "on_butRobotRight_clicked()\0"
    "on_butRobotLeft_clicked()\0"
    "on_butRobotBack_clicked()\0"
    "on_butRobotStop_clicked()\0"
    "on_butIRobotConnect_clicked()\0"
    "on_butIRobotSetFirstOrientation_clicked()\0"
};

void IRobotDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IRobotDialog *_t = static_cast<IRobotDialog *>(_o);
        switch (_id) {
        case 0: _t->setFirstOrientation(); break;
        case 1: _t->on_butRobotForward_clicked(); break;
        case 2: _t->on_butRobotRight_clicked(); break;
        case 3: _t->on_butRobotLeft_clicked(); break;
        case 4: _t->on_butRobotBack_clicked(); break;
        case 5: _t->on_butRobotStop_clicked(); break;
        case 6: _t->on_butIRobotConnect_clicked(); break;
        case 7: _t->on_butIRobotSetFirstOrientation_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData IRobotDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IRobotDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IRobotDialog,
      qt_meta_data_IRobotDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IRobotDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IRobotDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IRobotDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IRobotDialog))
        return static_cast<void*>(const_cast< IRobotDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int IRobotDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void IRobotDialog::setFirstOrientation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
