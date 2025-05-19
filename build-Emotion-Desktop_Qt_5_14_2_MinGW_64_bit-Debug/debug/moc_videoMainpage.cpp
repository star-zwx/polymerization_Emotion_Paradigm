/****************************************************************************
** Meta object code from reading C++ file 'videoMainpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Emotion/videoMainpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoMainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoMainPage_t {
    QByteArrayData data[13];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoMainPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoMainPage_t qt_meta_stringdata_VideoMainPage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VideoMainPage"
QT_MOC_LITERAL(1, 14, 10), // "toFixation"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "toVideo"
QT_MOC_LITERAL(4, 34, 6), // "toRest"
QT_MOC_LITERAL(5, 41, 8), // "toRating"
QT_MOC_LITERAL(6, 50, 11), // "toNextTrial"
QT_MOC_LITERAL(7, 62, 10), // "saveRating"
QT_MOC_LITERAL(8, 73, 7), // "valence"
QT_MOC_LITERAL(9, 81, 7), // "arousal"
QT_MOC_LITERAL(10, 89, 9), // "dominance"
QT_MOC_LITERAL(11, 99, 6), // "liking"
QT_MOC_LITERAL(12, 106, 12) // "serialConnet"

    },
    "VideoMainPage\0toFixation\0\0toVideo\0"
    "toRest\0toRating\0toNextTrial\0saveRating\0"
    "valence\0arousal\0dominance\0liking\0"
    "serialConnet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoMainPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    4,   54,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,    9,   10,   11,
    QMetaType::Void,

       0        // eod
};

void VideoMainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoMainPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toFixation(); break;
        case 1: _t->toVideo(); break;
        case 2: _t->toRest(); break;
        case 3: _t->toRating(); break;
        case 4: _t->toNextTrial(); break;
        case 5: _t->saveRating((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 6: _t->serialConnet(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoMainPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_VideoMainPage.data,
    qt_meta_data_VideoMainPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoMainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoMainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoMainPage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VideoMainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
