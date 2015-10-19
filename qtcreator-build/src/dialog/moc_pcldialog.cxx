/****************************************************************************
** Meta object code from reading C++ file 'pcldialog.h'
**
** Created: Thu Oct 15 18:17:13 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/dialog/pcldialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pcldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PclDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,   10,   10,   10, 0x08,
      52,   10,   10,   10, 0x08,
      77,   10,   10,   10, 0x08,
     102,   10,   10,   10, 0x08,
     127,   10,   10,   10, 0x08,
     159,   10,   10,   10, 0x08,
     186,   10,   10,   10, 0x08,
     222,   10,   10,   10, 0x08,
     250,   10,   10,   10, 0x08,
     282,   10,   10,   10, 0x08,
     313,   10,   10,   10, 0x08,
     358,   10,   10,   10, 0x08,
     399,   10,   10,   10, 0x08,
     441,   10,   10,   10, 0x08,
     496,  490,   10,   10, 0x08,
     554,  548,   10,   10, 0x08,
     586,   10,   10,   10, 0x08,
     606,   10,   10,   10, 0x08,
     627,   10,   10,   10, 0x08,
     655,   10,   10,   10, 0x08,
     690,  682,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PclDialog[] = {
    "PclDialog\0\0kinectSave()\0"
    "on_butSetDSetPath_clicked()\0"
    "on_butLoadItem_clicked()\0"
    "on_butPrevItem_clicked()\0"
    "on_butNextItem_clicked()\0"
    "on_butVoxelGridFilter_clicked()\0"
    "on_butCalNormals_clicked()\0"
    "on_butSaveNormalAngleHist_clicked()\0"
    "on_butRotateCloud_clicked()\0"
    "on_butScalePointCloud_clicked()\0"
    "on_butSavePointCloud_clicked()\0"
    "on_lEditInputCloudFileName_editingFinished()\0"
    "on_butApplyTransformationtoAll_clicked()\0"
    "on_butGeneratePointCloudBubbles_clicked()\0"
    "on_butCalculateAllNormalAngleHistogram_clicked()\0"
    "cloud\0handleKinectFrame(sensor_msgs::PointCloud2ConstPtr)\0"
    "frame\0handleKinectImageFrame(cv::Mat)\0"
    "handleKinectStart()\0handleKinectFailed()\0"
    "on_butKinectStart_clicked()\0"
    "on_butKinectSave_clicked()\0checked\0"
    "on_cBoxCloudVisualization_clicked(bool)\0"
};

void PclDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PclDialog *_t = static_cast<PclDialog *>(_o);
        switch (_id) {
        case 0: _t->kinectSave(); break;
        case 1: _t->on_butSetDSetPath_clicked(); break;
        case 2: _t->on_butLoadItem_clicked(); break;
        case 3: _t->on_butPrevItem_clicked(); break;
        case 4: _t->on_butNextItem_clicked(); break;
        case 5: _t->on_butVoxelGridFilter_clicked(); break;
        case 6: _t->on_butCalNormals_clicked(); break;
        case 7: _t->on_butSaveNormalAngleHist_clicked(); break;
        case 8: _t->on_butRotateCloud_clicked(); break;
        case 9: _t->on_butScalePointCloud_clicked(); break;
        case 10: _t->on_butSavePointCloud_clicked(); break;
        case 11: _t->on_lEditInputCloudFileName_editingFinished(); break;
        case 12: _t->on_butApplyTransformationtoAll_clicked(); break;
        case 13: _t->on_butGeneratePointCloudBubbles_clicked(); break;
        case 14: _t->on_butCalculateAllNormalAngleHistogram_clicked(); break;
        case 15: _t->handleKinectFrame((*reinterpret_cast< const sensor_msgs::PointCloud2ConstPtr(*)>(_a[1]))); break;
        case 16: _t->handleKinectImageFrame((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 17: _t->handleKinectStart(); break;
        case 18: _t->handleKinectFailed(); break;
        case 19: _t->on_butKinectStart_clicked(); break;
        case 20: _t->on_butKinectSave_clicked(); break;
        case 21: _t->on_cBoxCloudVisualization_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PclDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PclDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PclDialog,
      qt_meta_data_PclDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PclDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PclDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PclDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PclDialog))
        return static_cast<void*>(const_cast< PclDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PclDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void PclDialog::kinectSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
