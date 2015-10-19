/****************************************************************************
** Meta object code from reading C++ file 'kinectgrabber.h'
**
** Created: Mon Oct 19 12:42:25 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/kinect/kinectgrabber.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kinectgrabber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KinectGrabber[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      25,   14,   14,   14, 0x05,
      36,   14,   14,   14, 0x05,
      50,   44,   14,   14, 0x05,
     101,   90,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   14,   14,   14, 0x0a,
     141,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KinectGrabber[] = {
    "KinectGrabber\0\0started()\0finished()\0"
    "error()\0cloud\0frame(sensor_msgs::PointCloud2ConstPtr)\0"
    "imageFrame\0imageFrame(cv::Mat)\0"
    "handleSaveRequest()\0grabFromKinect()\0"
};

void KinectGrabber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KinectGrabber *_t = static_cast<KinectGrabber *>(_o);
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->finished(); break;
        case 2: _t->error(); break;
        case 3: _t->frame((*reinterpret_cast< const sensor_msgs::PointCloud2ConstPtr(*)>(_a[1]))); break;
        case 4: _t->imageFrame((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 5: _t->handleSaveRequest(); break;
        case 6: _t->grabFromKinect(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KinectGrabber::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KinectGrabber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KinectGrabber,
      qt_meta_data_KinectGrabber, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KinectGrabber::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KinectGrabber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KinectGrabber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KinectGrabber))
        return static_cast<void*>(const_cast< KinectGrabber*>(this));
    return QObject::qt_metacast(_clname);
}

int KinectGrabber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void KinectGrabber::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void KinectGrabber::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void KinectGrabber::error()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void KinectGrabber::frame(const sensor_msgs::PointCloud2ConstPtr & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KinectGrabber::imageFrame(const cv::Mat & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
