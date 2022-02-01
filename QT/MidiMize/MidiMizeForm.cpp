#include "MidiMizeForm.h"
#include "aboutForm.h"
#include <QWidget>


MidiMizeForm::MidiMizeForm(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    CMidiMize* MIDImize = CMidiMize::getInstance(QtWrap);
}

MidiMizeForm::~MidiMizeForm(){}

void MidiMizeForm::on_gainDial_valueChanged(int value)
{
    QtWrap.synth[0]->setGain(((float)value)/10);
    QtWrap.synth[1]->setGain(((float)value)/10);
}

void MidiMizeForm::on_osc1Pbutton_clicked(bool checked)
{
    if(checked)
    {
        if(QtWrap.solo)
        {
            ledCommand_t cmd={55, OSC_1_BLK};
            QtWrap.synth[0]->synthOn=1;
            QtWrap.synth[0]->noteOn(1, 55, 100);
            QtWrap.synth[0]->current_note = 55;
            QtWrap.led_ctrl->pushBuffer(cmd);
        }
    }
    else
    {
        ledCommand_t cmd={ 55, OSC_1_OFF};
        QtWrap.synth[0]->synthOn=0;
        QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
        QtWrap.led_ctrl->pushBuffer(cmd);
    }
}

void MidiMizeForm::on_osc1TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=TRIANGLE;
        QtWrap.synth[0]->setOscillator();
        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 100);
        }
    }
}

void MidiMizeForm::on_osc1SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=SINE;
        QtWrap.synth[0]->setOscillator();
        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 100);
        }
    }
}

void MidiMizeForm::on_osc1SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=SAW;
        QtWrap.synth[0]->setOscillator();
        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 100);
        }
    }
}


void MidiMizeForm::on_osc2SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=SINE;
        QtWrap.synth[1]->setOscillator();
        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 100);
        }
    }
}

void MidiMizeForm::on_osc2TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=TRIANGLE;
        QtWrap.synth[1]->setOscillator();
        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 100);
        }
    }
}

void MidiMizeForm::on_osc2SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=SAW;
        QtWrap.synth[1]->setOscillator();
        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 100);
        }
    }
}

void MidiMizeForm::on_osc2Pbutton_toggled(bool checked)
{
    if(checked)
    {
        if(QtWrap.solo)
        {
            ledCommand_t cmd={45, OSC_2_BLK};
            QtWrap.synth[1]->synthOn=1;
            QtWrap.synth[1]->noteOn(1, 45, 100);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }
    }
    else
    {
        ledCommand_t cmd={45, OSC_2_OFF};
        QtWrap.synth[1]->synthOn=0;
        QtWrap.synth[1]->noteOff(1, 45);
        QtWrap.led_ctrl->pushBuffer(cmd);
    }
}


void MidiMizeForm::on_osc1ReverbEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->reverb.active=1;
        QtWrap.synth[0]->setReverb();
    }
    else
    {
        QtWrap.synth[0]->reverb.active=0;
        QtWrap.synth[0]->setReverb();
    }
}

void MidiMizeForm::on_osc2ReverbEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->reverb.active=1;
        QtWrap.synth[1]->setReverb();
    }
    else
    {
        QtWrap.synth[1]->reverb.active=0;
        QtWrap.synth[1]->setReverb();
    }
}

void MidiMizeForm::on_osc1ChorusEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->chorus.active=1;
        QtWrap.synth[0]->setChorus();
    }
    else
    {
        QtWrap.synth[0]->chorus.active=0;
        QtWrap.synth[0]->setChorus();
    }
}

void MidiMizeForm::on_osc2ChorusEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->chorus.active=1;
        QtWrap.synth[1]->setChorus();
    }
    else
    {
        QtWrap.synth[1]->chorus.active=0;
        QtWrap.synth[1]->setChorus();
    }
}

void MidiMizeForm::on_osc1ReverbWidth_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.width = value;

    if(QtWrap.synth[0]->reverb.active)
        QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc2ReverbWidth_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.width = value;

    if(QtWrap.synth[1]->reverb.active)
        QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc1ReverbLvl_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.lvl = (float)value;
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc1ReverbDamp_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.damp = (float)value;
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc1ReverbRoom_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.room = (float)value;
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc2ReverbLvl_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.lvl = (float)value;
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ReverbDamp_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.damp = (float)value;
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ReverbRoom_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.room = (float)value;
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ChorusNr_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.nr = value;
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusDepth_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.depth = ((float)value)/10;
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusLvl_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.lvl = ((float)value)/10;
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusSpeed_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.speed = ((float)value)/10;
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc1ChorusNr_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.nr = value;
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusDepth_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.depth = ((float)value)/10;
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusLvl_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.lvl = ((float)value)/10;
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusSpeed_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.speed = ((float)value)/10;
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_aboutButton_clicked()
{
    //aboutForm about;
    //about.exec();
}

void MidiMizeForm::on_midiRbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.solo=(bool*)0;
    }
}

void MidiMizeForm::on_soloRbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.solo=(bool*)1;
    }
}
