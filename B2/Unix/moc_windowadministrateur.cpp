/****************************************************************************
** Meta object code from reading C++ file 'windowadministrateur.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "windowadministrateur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowadministrateur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowAdministrateur[] = {

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
      22,   21,   21,   21, 0x08,
      58,   21,   21,   21, 0x08,
      94,   21,   21,   21, 0x08,
     129,   21,   21,   21, 0x08,
     157,   21,   21,   21, 0x08,
     186,   21,   21,   21, 0x08,
     215,   21,   21,   21, 0x08,
     244,   21,   21,   21, 0x08,
     273,   21,   21,   21, 0x08,
     303,   21,   21,   21, 0x08,
     333,   21,   21,   21, 0x08,
     363,   21,   21,   21, 0x08,
     393,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WindowAdministrateur[] = {
    "WindowAdministrateur\0\0"
    "on_ButtonAccepteSelection_clicked()\0"
    "on_ButtonAccepterCommande_clicked()\0"
    "on_ButtonAnnulerCommande_clicked()\0"
    "on_ButtonTerminer_clicked()\0"
    "on_ButtonCommande1_clicked()\0"
    "on_ButtonCommande2_clicked()\0"
    "on_ButtonCommande3_clicked()\0"
    "on_ButtonCommande4_clicked()\0"
    "on_ButtonPersonnel1_clicked()\0"
    "on_ButtonPersonnel2_clicked()\0"
    "on_ButtonPersonnel3_clicked()\0"
    "on_ButtonPersonnel4_clicked()\0"
    "on_ButtonAnnulerSelection_clicked()\0"
};

void WindowAdministrateur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WindowAdministrateur *_t = static_cast<WindowAdministrateur *>(_o);
        switch (_id) {
        case 0: _t->on_ButtonAccepteSelection_clicked(); break;
        case 1: _t->on_ButtonAccepterCommande_clicked(); break;
        case 2: _t->on_ButtonAnnulerCommande_clicked(); break;
        case 3: _t->on_ButtonTerminer_clicked(); break;
        case 4: _t->on_ButtonCommande1_clicked(); break;
        case 5: _t->on_ButtonCommande2_clicked(); break;
        case 6: _t->on_ButtonCommande3_clicked(); break;
        case 7: _t->on_ButtonCommande4_clicked(); break;
        case 8: _t->on_ButtonPersonnel1_clicked(); break;
        case 9: _t->on_ButtonPersonnel2_clicked(); break;
        case 10: _t->on_ButtonPersonnel3_clicked(); break;
        case 11: _t->on_ButtonPersonnel4_clicked(); break;
        case 12: _t->on_ButtonAnnulerSelection_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WindowAdministrateur::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WindowAdministrateur::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WindowAdministrateur,
      qt_meta_data_WindowAdministrateur, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowAdministrateur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowAdministrateur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowAdministrateur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowAdministrateur))
        return static_cast<void*>(const_cast< WindowAdministrateur*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WindowAdministrateur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
