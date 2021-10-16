/****************************************************************************
** Meta object code from reading C++ file 'graphstat2d.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphstat2d.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphstat2d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphStat2D[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,
      71,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GraphStat2D[] = {
    "GraphStat2D\0\0on_ButtonTracer_clicked()\0"
    "on_ButtonSelectionner_clicked()\0"
    "on_ButtonAnnuler_clicked()\0"
};

void GraphStat2D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GraphStat2D *_t = static_cast<GraphStat2D *>(_o);
        switch (_id) {
        case 0: _t->on_ButtonTracer_clicked(); break;
        case 1: _t->on_ButtonSelectionner_clicked(); break;
        case 2: _t->on_ButtonAnnuler_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GraphStat2D::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GraphStat2D::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GraphStat2D,
      qt_meta_data_GraphStat2D, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GraphStat2D::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GraphStat2D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GraphStat2D::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphStat2D))
        return static_cast<void*>(const_cast< GraphStat2D*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GraphStat2D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
