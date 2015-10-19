/****************************************************************************
** Meta object code from reading C++ file 'imageprocessdialog.h'
**
** Created: Tue Oct 13 18:52:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/dialog/imageprocessdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageProcessDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      49,   19,   19,   19, 0x08,
      79,   19,   19,   19, 0x08,
     108,   19,   19,   19, 0x08,
     133,   19,   19,   19, 0x08,
     169,   19,   19,   19, 0x08,
     202,   19,   19,   19, 0x08,
     239,   19,   19,   19, 0x08,
     279,  273,   19,   19, 0x08,
     318,  273,   19,   19, 0x08,
     357,  273,   19,   19, 0x08,
     396,  273,   19,   19, 0x08,
     435,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessDialog[] = {
    "ImageProcessDialog\0\0on_but_LoadImage_4_clicked()\0"
    "on_butSetDSetPath_4_clicked()\0"
    "on_butLoadFilter_4_clicked()\0"
    "on_butApplyAll_clicked()\0"
    "on_butAddtoInputFileNames_clicked()\0"
    "on_butAddtoFilterNames_clicked()\0"
    "on_butRemoveInputFileNames_clicked()\0"
    "on_butRemoveFilterNames_clicked()\0"
    "value\0on_horsliderSatUpper_valueChanged(int)\0"
    "on_horsliderSatLower_valueChanged(int)\0"
    "on_horsliderValUpper_valueChanged(int)\0"
    "on_horsliderValLower_valueChanged(int)\0"
    "on_butApplyFilter_4_clicked()\0"
};

void ImageProcessDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageProcessDialog *_t = static_cast<ImageProcessDialog *>(_o);
        switch (_id) {
        case 0: _t->on_but_LoadImage_4_clicked(); break;
        case 1: _t->on_butSetDSetPath_4_clicked(); break;
        case 2: _t->on_butLoadFilter_4_clicked(); break;
        case 3: _t->on_butApplyAll_clicked(); break;
        case 4: _t->on_butAddtoInputFileNames_clicked(); break;
        case 5: _t->on_butAddtoFilterNames_clicked(); break;
        case 6: _t->on_butRemoveInputFileNames_clicked(); break;
        case 7: _t->on_butRemoveFilterNames_clicked(); break;
        case 8: _t->on_horsliderSatUpper_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horsliderSatLower_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_horsliderValUpper_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_horsliderValLower_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_butApplyFilter_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageProcessDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageProcessDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ImageProcessDialog,
      qt_meta_data_ImageProcessDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageProcessDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageProcessDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageProcessDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessDialog))
        return static_cast<void*>(const_cast< ImageProcessDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ImageProcessDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
