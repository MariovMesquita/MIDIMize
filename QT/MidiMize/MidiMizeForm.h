#ifndef MIDIMIZEFORM_H
#define MIDIMIZEFORM_H

#include "ui_MidiMizeForm.h"
#include "cmidimize.h"

enum noteNames { A0=21, Bb0, B0, Db1, D1, Eb1, E1, F1, Gb1, G1, Ab1, \
                A1, Bb1, B1, C2, Db2, D2, Eb2, E2, F2, Gb2, G2, Ab2, \
                A2, Bb2, B2, C3, Db3, D3, Eb3, E3, F3, Gb3, G3, Ab3, \
                A3, Bb3, B3, C4, Db4, D4, Eb4, E4, F4, Gb4, G4, Ab4, \
                A4, Bb4, B4, C5, Db5, D5, Eb5, E5, F5, Gb5, G5, Ab5, \
                A5, Bb5, B5, C6, Db6, D6, Eb6, E6, F6, Gb6, G6, Ab6, \
                A6, Bb6, B6, C7, Db7, D7, Eb7, E7, F7, Gb7, G7, Ab7, \
                A7, Bb7, B7, C8, Db8, D8, Eb8, E8, F8, Gb8, G8, Ab8, \
                A8, Bb8, B8, C9, Db9, D9, Eb9, E9, F9, Gb9, G9 };


class MidiMizeForm : public QMainWindow, private Ui::MidiMizeForm
{
    Q_OBJECT

public:
    explicit MidiMizeForm(QWidget *parent = nullptr);
    QtWrapper QtWrap;
    void init_osc1Led_midi();
    void init_osc2Led_midi();
    void kbrdKeyOn(noteNames note);
    void kbrdKeyOff(noteNames note);

    fluid_midi_router_t* osc1LedRouter;
    fluid_midi_driver_t* osc1LedDriver;
    fluid_midi_router_t* osc2LedRouter;
    fluid_midi_driver_t* osc2LedDriver;
    fluid_settings_t* osc2LedSettings;
    fluid_settings_t* osc1LedSettings;

    noteNames notes;
    //bool osc1KeyBrd;
    //bool osc2KeyBrd;

    ~MidiMizeForm();

private slots:

    void on_gainDial_valueChanged(int value);
    void on_osc1Pbutton_clicked(bool checked);
    void on_osc1TriRbutton_toggled(bool checked);
    void on_osc1SineRbutton_toggled(bool checked);
    void on_osc1SawRbutton_toggled(bool checked);
    void on_osc2SineRbutton_toggled(bool checked);
    void on_osc2TriRbutton_toggled(bool checked);
    void on_osc2SawRbutton_toggled(bool checked);
    void on_osc2Pbutton_clicked(bool checked);
    void on_osc1ReverbEnable_toggled(bool checked);
    void on_osc2ReverbEnable_toggled(bool checked);
    void on_osc1ChorusEnable_toggled(bool checked);
    void on_osc2ChorusEnable_toggled(bool checked);
    void on_osc1ReverbWidth_valueChanged(int value);
    void on_osc2ReverbWidth_valueChanged(int value);
    void on_osc1ReverbLvl_valueChanged(int value);
    void on_osc1ReverbDamp_valueChanged(int value);
    void on_osc1ReverbRoom_valueChanged(int value);
    void on_osc2ReverbLvl_valueChanged(int value);
    void on_osc2ReverbDamp_valueChanged(int value);
    void on_osc2ReverbRoom_valueChanged(int value);
    void on_osc2ChorusNr_valueChanged(int value);
    void on_osc2ChorusDepth_valueChanged(int value);
    void on_osc2ChorusLvl_valueChanged(int value);
    void on_osc2ChorusSpeed_valueChanged(int value);
    void on_osc1ChorusNr_valueChanged(int value);
    void on_osc1ChorusDepth_valueChanged(int value);
    void on_osc1ChorusLvl_valueChanged(int value);
    void on_osc1ChorusSpeed_valueChanged(int value);
    void on_aboutButton_clicked();

    void on_midiRbutton_clicked(bool checked);
    void on_soloRbutton_clicked(bool checked);
    void on_C4_Pb_clicked(bool checked);
    void on_Db4_Pb_clicked(bool checked);
    void on_D4_Pb_clicked(bool checked);
    void on_Eb4_Pb_clicked(bool checked);
    void on_E4_Pb_clicked(bool checked);
    void on_F4_Pb_clicked(bool checked);
    void on_Gb4_Pb_clicked(bool checked);
    void on_G4_Pb_clicked(bool checked);
    void on_Ab4_Pb_clicked(bool checked);
    void on_A4_Pb_clicked(bool checked);
    void on_Bb4_Pb_clicked(bool checked);
    void on_B4_Pb_clicked(bool checked);
    void on_C5_Pb_clicked(bool checked);
    void on_Db5_Pb_clicked(bool checked);
    void on_D5_Pb_clicked(bool checked);
    void on_Eb5_Pb_clicked(bool checked);
    void on_E5_Pb_clicked(bool checked);
    void on_F5_Pb_clicked(bool checked);
    void on_Gb5_Pb_clicked(bool checked);
    void on_G5_Pb_clicked(bool checked);
};


#endif // MIDIMIZEFORM_H
