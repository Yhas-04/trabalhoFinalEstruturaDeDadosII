/****************************************************************************
** Meta object code from reading C++ file 'telaarvore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../gui/telaarvore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telaarvore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_telaArvore_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_telaArvore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_telaArvore_t qt_meta_stringdata_telaArvore = {
    {
QT_MOC_LITERAL(0, 0, 10), // "telaArvore"
QT_MOC_LITERAL(1, 11, 16), // "on_btAdd_clicked"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "telaArvore\0on_btAdd_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_telaArvore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void telaArvore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<telaArvore *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btAdd_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject telaArvore::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_telaArvore.data,
    qt_meta_data_telaArvore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *telaArvore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *telaArvore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_telaArvore.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int telaArvore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
