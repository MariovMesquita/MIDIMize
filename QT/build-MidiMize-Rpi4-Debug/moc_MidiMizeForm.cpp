/****************************************************************************
** Meta object code from reading C++ file 'MidiMizeForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MidiMize/MidiMizeForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MidiMizeForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MidiMizeForm_t {
    QByteArrayData data[56];
    char stringdata0[1280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MidiMizeForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MidiMizeForm_t qt_meta_stringdata_MidiMizeForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MidiMizeForm"
QT_MOC_LITERAL(1, 13, 24), // "on_gainDial_valueChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "value"
QT_MOC_LITERAL(4, 45, 22), // "on_osc1Pbutton_clicked"
QT_MOC_LITERAL(5, 68, 7), // "checked"
QT_MOC_LITERAL(6, 76, 25), // "on_osc1TriRbutton_toggled"
QT_MOC_LITERAL(7, 102, 26), // "on_osc1SineRbutton_toggled"
QT_MOC_LITERAL(8, 129, 25), // "on_osc1SawRbutton_toggled"
QT_MOC_LITERAL(9, 155, 26), // "on_osc2SineRbutton_toggled"
QT_MOC_LITERAL(10, 182, 25), // "on_osc2TriRbutton_toggled"
QT_MOC_LITERAL(11, 208, 25), // "on_osc2SawRbutton_toggled"
QT_MOC_LITERAL(12, 234, 22), // "on_osc2Pbutton_clicked"
QT_MOC_LITERAL(13, 257, 27), // "on_osc1ReverbEnable_toggled"
QT_MOC_LITERAL(14, 285, 27), // "on_osc2ReverbEnable_toggled"
QT_MOC_LITERAL(15, 313, 27), // "on_osc1ChorusEnable_toggled"
QT_MOC_LITERAL(16, 341, 27), // "on_osc2ChorusEnable_toggled"
QT_MOC_LITERAL(17, 369, 31), // "on_osc1ReverbWidth_valueChanged"
QT_MOC_LITERAL(18, 401, 31), // "on_osc2ReverbWidth_valueChanged"
QT_MOC_LITERAL(19, 433, 29), // "on_osc1ReverbLvl_valueChanged"
QT_MOC_LITERAL(20, 463, 30), // "on_osc1ReverbDamp_valueChanged"
QT_MOC_LITERAL(21, 494, 30), // "on_osc1ReverbRoom_valueChanged"
QT_MOC_LITERAL(22, 525, 29), // "on_osc2ReverbLvl_valueChanged"
QT_MOC_LITERAL(23, 555, 30), // "on_osc2ReverbDamp_valueChanged"
QT_MOC_LITERAL(24, 586, 30), // "on_osc2ReverbRoom_valueChanged"
QT_MOC_LITERAL(25, 617, 28), // "on_osc2ChorusNr_valueChanged"
QT_MOC_LITERAL(26, 646, 31), // "on_osc2ChorusDepth_valueChanged"
QT_MOC_LITERAL(27, 678, 29), // "on_osc2ChorusLvl_valueChanged"
QT_MOC_LITERAL(28, 708, 31), // "on_osc2ChorusSpeed_valueChanged"
QT_MOC_LITERAL(29, 740, 28), // "on_osc1ChorusNr_valueChanged"
QT_MOC_LITERAL(30, 769, 31), // "on_osc1ChorusDepth_valueChanged"
QT_MOC_LITERAL(31, 801, 29), // "on_osc1ChorusLvl_valueChanged"
QT_MOC_LITERAL(32, 831, 31), // "on_osc1ChorusSpeed_valueChanged"
QT_MOC_LITERAL(33, 863, 22), // "on_aboutButton_clicked"
QT_MOC_LITERAL(34, 886, 22), // "on_midiRbutton_clicked"
QT_MOC_LITERAL(35, 909, 22), // "on_soloRbutton_clicked"
QT_MOC_LITERAL(36, 932, 16), // "on_C4_Pb_clicked"
QT_MOC_LITERAL(37, 949, 17), // "on_Db4_Pb_clicked"
QT_MOC_LITERAL(38, 967, 16), // "on_D4_Pb_clicked"
QT_MOC_LITERAL(39, 984, 17), // "on_Eb4_Pb_clicked"
QT_MOC_LITERAL(40, 1002, 16), // "on_E4_Pb_clicked"
QT_MOC_LITERAL(41, 1019, 16), // "on_F4_Pb_clicked"
QT_MOC_LITERAL(42, 1036, 17), // "on_Gb4_Pb_clicked"
QT_MOC_LITERAL(43, 1054, 16), // "on_G4_Pb_clicked"
QT_MOC_LITERAL(44, 1071, 17), // "on_Ab4_Pb_clicked"
QT_MOC_LITERAL(45, 1089, 16), // "on_A4_Pb_clicked"
QT_MOC_LITERAL(46, 1106, 17), // "on_Bb4_Pb_clicked"
QT_MOC_LITERAL(47, 1124, 16), // "on_B4_Pb_clicked"
QT_MOC_LITERAL(48, 1141, 16), // "on_C5_Pb_clicked"
QT_MOC_LITERAL(49, 1158, 17), // "on_Db5_Pb_clicked"
QT_MOC_LITERAL(50, 1176, 16), // "on_D5_Pb_clicked"
QT_MOC_LITERAL(51, 1193, 17), // "on_Eb5_Pb_clicked"
QT_MOC_LITERAL(52, 1211, 16), // "on_E5_Pb_clicked"
QT_MOC_LITERAL(53, 1228, 16), // "on_F5_Pb_clicked"
QT_MOC_LITERAL(54, 1245, 17), // "on_Gb5_Pb_clicked"
QT_MOC_LITERAL(55, 1263, 16) // "on_G5_Pb_clicked"

    },
    "MidiMizeForm\0on_gainDial_valueChanged\0"
    "\0value\0on_osc1Pbutton_clicked\0checked\0"
    "on_osc1TriRbutton_toggled\0"
    "on_osc1SineRbutton_toggled\0"
    "on_osc1SawRbutton_toggled\0"
    "on_osc2SineRbutton_toggled\0"
    "on_osc2TriRbutton_toggled\0"
    "on_osc2SawRbutton_toggled\0"
    "on_osc2Pbutton_clicked\0"
    "on_osc1ReverbEnable_toggled\0"
    "on_osc2ReverbEnable_toggled\0"
    "on_osc1ChorusEnable_toggled\0"
    "on_osc2ChorusEnable_toggled\0"
    "on_osc1ReverbWidth_valueChanged\0"
    "on_osc2ReverbWidth_valueChanged\0"
    "on_osc1ReverbLvl_valueChanged\0"
    "on_osc1ReverbDamp_valueChanged\0"
    "on_osc1ReverbRoom_valueChanged\0"
    "on_osc2ReverbLvl_valueChanged\0"
    "on_osc2ReverbDamp_valueChanged\0"
    "on_osc2ReverbRoom_valueChanged\0"
    "on_osc2ChorusNr_valueChanged\0"
    "on_osc2ChorusDepth_valueChanged\0"
    "on_osc2ChorusLvl_valueChanged\0"
    "on_osc2ChorusSpeed_valueChanged\0"
    "on_osc1ChorusNr_valueChanged\0"
    "on_osc1ChorusDepth_valueChanged\0"
    "on_osc1ChorusLvl_valueChanged\0"
    "on_osc1ChorusSpeed_valueChanged\0"
    "on_aboutButton_clicked\0on_midiRbutton_clicked\0"
    "on_soloRbutton_clicked\0on_C4_Pb_clicked\0"
    "on_Db4_Pb_clicked\0on_D4_Pb_clicked\0"
    "on_Eb4_Pb_clicked\0on_E4_Pb_clicked\0"
    "on_F4_Pb_clicked\0on_Gb4_Pb_clicked\0"
    "on_G4_Pb_clicked\0on_Ab4_Pb_clicked\0"
    "on_A4_Pb_clicked\0on_Bb4_Pb_clicked\0"
    "on_B4_Pb_clicked\0on_C5_Pb_clicked\0"
    "on_Db5_Pb_clicked\0on_D5_Pb_clicked\0"
    "on_Eb5_Pb_clicked\0on_E5_Pb_clicked\0"
    "on_F5_Pb_clicked\0on_Gb5_Pb_clicked\0"
    "on_G5_Pb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidiMizeForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  274,    2, 0x08 /* Private */,
       4,    1,  277,    2, 0x08 /* Private */,
       6,    1,  280,    2, 0x08 /* Private */,
       7,    1,  283,    2, 0x08 /* Private */,
       8,    1,  286,    2, 0x08 /* Private */,
       9,    1,  289,    2, 0x08 /* Private */,
      10,    1,  292,    2, 0x08 /* Private */,
      11,    1,  295,    2, 0x08 /* Private */,
      12,    1,  298,    2, 0x08 /* Private */,
      13,    1,  301,    2, 0x08 /* Private */,
      14,    1,  304,    2, 0x08 /* Private */,
      15,    1,  307,    2, 0x08 /* Private */,
      16,    1,  310,    2, 0x08 /* Private */,
      17,    1,  313,    2, 0x08 /* Private */,
      18,    1,  316,    2, 0x08 /* Private */,
      19,    1,  319,    2, 0x08 /* Private */,
      20,    1,  322,    2, 0x08 /* Private */,
      21,    1,  325,    2, 0x08 /* Private */,
      22,    1,  328,    2, 0x08 /* Private */,
      23,    1,  331,    2, 0x08 /* Private */,
      24,    1,  334,    2, 0x08 /* Private */,
      25,    1,  337,    2, 0x08 /* Private */,
      26,    1,  340,    2, 0x08 /* Private */,
      27,    1,  343,    2, 0x08 /* Private */,
      28,    1,  346,    2, 0x08 /* Private */,
      29,    1,  349,    2, 0x08 /* Private */,
      30,    1,  352,    2, 0x08 /* Private */,
      31,    1,  355,    2, 0x08 /* Private */,
      32,    1,  358,    2, 0x08 /* Private */,
      33,    0,  361,    2, 0x08 /* Private */,
      34,    1,  362,    2, 0x08 /* Private */,
      35,    1,  365,    2, 0x08 /* Private */,
      36,    1,  368,    2, 0x08 /* Private */,
      37,    1,  371,    2, 0x08 /* Private */,
      38,    1,  374,    2, 0x08 /* Private */,
      39,    1,  377,    2, 0x08 /* Private */,
      40,    1,  380,    2, 0x08 /* Private */,
      41,    1,  383,    2, 0x08 /* Private */,
      42,    1,  386,    2, 0x08 /* Private */,
      43,    1,  389,    2, 0x08 /* Private */,
      44,    1,  392,    2, 0x08 /* Private */,
      45,    1,  395,    2, 0x08 /* Private */,
      46,    1,  398,    2, 0x08 /* Private */,
      47,    1,  401,    2, 0x08 /* Private */,
      48,    1,  404,    2, 0x08 /* Private */,
      49,    1,  407,    2, 0x08 /* Private */,
      50,    1,  410,    2, 0x08 /* Private */,
      51,    1,  413,    2, 0x08 /* Private */,
      52,    1,  416,    2, 0x08 /* Private */,
      53,    1,  419,    2, 0x08 /* Private */,
      54,    1,  422,    2, 0x08 /* Private */,
      55,    1,  425,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void MidiMizeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MidiMizeForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_gainDial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_osc1Pbutton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_osc1TriRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_osc1SineRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_osc1SawRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_osc2SineRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_osc2TriRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_osc2SawRbutton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_osc2Pbutton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_osc1ReverbEnable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_osc2ReverbEnable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_osc1ChorusEnable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_osc2ChorusEnable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_osc1ReverbWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_osc2ReverbWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_osc1ReverbLvl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_osc1ReverbDamp_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_osc1ReverbRoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_osc2ReverbLvl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_osc2ReverbDamp_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_osc2ReverbRoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_osc2ChorusNr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_osc2ChorusDepth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_osc2ChorusLvl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_osc2ChorusSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_osc1ChorusNr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_osc1ChorusDepth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_osc1ChorusLvl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_osc1ChorusSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_aboutButton_clicked(); break;
        case 30: _t->on_midiRbutton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_soloRbutton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_C4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_Db4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_D4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_Eb4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_E4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_F4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_Gb4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_G4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_Ab4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_A4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_Bb4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_B4_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_C5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_Db5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->on_D5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_Eb5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_E5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_F5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->on_Gb5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_G5_Pb_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MidiMizeForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MidiMizeForm.data,
    qt_meta_data_MidiMizeForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MidiMizeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidiMizeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MidiMizeForm.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MidiMizeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 52;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
