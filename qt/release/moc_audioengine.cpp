/****************************************************************************
** Meta object code from reading C++ file 'audioengine.h'
**
** Created: Wed Jul 18 18:42:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audioengine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audioengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AudioEngine[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      26,   24,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   12,   12,   12, 0x08,
      65,   12,   12,   12, 0x08,
      81,   75,   12,   12, 0x08,
     104,   98,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AudioEngine[] = {
    "AudioEngine\0\0finished()\0,\0"
    "dataReady(float,float)\0stopRecording()\0"
    "process()\0bytes\0procData(qint64)\0state\0"
    "stateChanged(QAudio::State)\0"
};

const QMetaObject AudioEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AudioEngine,
      qt_meta_data_AudioEngine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AudioEngine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AudioEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AudioEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AudioEngine))
        return static_cast<void*>(const_cast< AudioEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int AudioEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: dataReady((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: stopRecording(); break;
        case 3: process(); break;
        case 4: procData((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: stateChanged((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AudioEngine::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AudioEngine::dataReady(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
