/****************************************************************************
** Meta object code from reading C++ file 'bubbleprocessdialog.h'
**
** Created: Mon Oct 19 12:42:24 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/dialog/bubbleprocessdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bubbleprocessdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BubbleProcessDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      62,   20,   20,   20, 0x08,
      98,   20,   20,   20, 0x08,
     134,  128,   20,   20, 0x08,
     188,   20,   20,   20, 0x08,
     220,   20,   20,   20, 0x08,
     256,   20,   20,   20, 0x08,
     282,   20,   20,   20, 0x08,
     324,  312,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BubbleProcessDialog[] = {
    "BubbleProcessDialog\0\0"
    "on_But_bubbleFilesSetRootDir_3_clicked()\0"
    "on_But_fetchBubbleFiles_3_clicked()\0"
    "on_But_chooseFile_3_clicked()\0index\0"
    "on_ComboBox_fetchedBubbles_3_currentIndexChanged(int)\0"
    "on_But_readPoseData_3_clicked()\0"
    "on_But_transformBubbles_3_clicked()\0"
    "on_But_calcDiff_clicked()\0"
    "on_but_SaveGLWidget_clicked()\0frameNumber\0"
    "handleGLBubbleViewerFrameChanged(int)\0"
};

void BubbleProcessDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BubbleProcessDialog *_t = static_cast<BubbleProcessDialog *>(_o);
        switch (_id) {
        case 0: _t->on_But_bubbleFilesSetRootDir_3_clicked(); break;
        case 1: _t->on_But_fetchBubbleFiles_3_clicked(); break;
        case 2: _t->on_But_chooseFile_3_clicked(); break;
        case 3: _t->on_ComboBox_fetchedBubbles_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_But_readPoseData_3_clicked(); break;
        case 5: _t->on_But_transformBubbles_3_clicked(); break;
        case 6: _t->on_But_calcDiff_clicked(); break;
        case 7: _t->on_but_SaveGLWidget_clicked(); break;
        case 8: _t->handleGLBubbleViewerFrameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BubbleProcessDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BubbleProcessDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BubbleProcessDialog,
      qt_meta_data_BubbleProcessDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BubbleProcessDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BubbleProcessDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BubbleProcessDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BubbleProcessDialog))
        return static_cast<void*>(const_cast< BubbleProcessDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BubbleProcessDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
