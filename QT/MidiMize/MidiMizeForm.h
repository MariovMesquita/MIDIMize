#ifndef MIDIMIZEFORM_H
#define MIDIMIZEFORM_H

#include "ui_MidiMizeForm.h"
#include "cmidimize.h"


class MidiMizeForm : public QMainWindow, private Ui::MidiMizeForm
{
    Q_OBJECT

public:
    explicit MidiMizeForm(QWidget *parent = nullptr);
    QtWrapper QtWrap;
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
    void on_osc2Pbutton_toggled(bool checked);
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
};


#endif // MIDIMIZEFORM_H
