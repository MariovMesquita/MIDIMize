#include "MidiMizeForm.h"
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
//    string my_volume = to_string(value);
//    char const *cmd = my_volume.c_str();
//    setenv("MDMZ_VOLUME", cmd, 1);

//    system("amixer set Headphone $MDMZ_VOLUME%");

    //string cmd = "amixer set Headphone"value"%";
    //system(("amixer set Headphone "value"%").c_str());
    QtWrap.synth[0]->setGain(static_cast<float>((value)/10.0));
    QtWrap.synth[1]->setGain(static_cast<float>((value)/10.0));

}

void MidiMizeForm::on_osc1Pbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->synthOn=1;

        if(QtWrap.solo) // SOLO mode
        {
            QtWrap.synth[0]->setOscillator();
            ledCommand_t cmd={55, OSC_1_BLK};
            QtWrap.synth[0]->noteOn(1, 55, 50);
            QtWrap.synth[0]->current_note = 55;
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(QtWrap.solo==0) // MIDI mode
        {
            system("aconnect 24 128");
            QtWrap.synth[0]->setOscillator();
        }
    }

    else
    {
        QtWrap.synth[0]->synthOn=0;
        if(QtWrap.solo) // SOLO mode
        {
            ledCommand_t cmd={ 55, OSC_1_OFF};
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(QtWrap.solo==0) // MIDI mode
        {
            system("aconnect -d 24 128");
        }
    }
}

void MidiMizeForm::on_osc1TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=TRIANGLE;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 50);
        }
    }
}

void MidiMizeForm::on_osc1SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=SINE;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 50);
        }
    }
}

void MidiMizeForm::on_osc1SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=SAW;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 50);
        }
    }
}

void MidiMizeForm::on_osc2Pbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->synthOn=1;

        if(QtWrap.solo) // SOLO mode
        {
            QtWrap.synth[1]->setOscillator();
            ledCommand_t cmd={45, OSC_2_BLK};
            QtWrap.synth[1]->noteOn(1, 45, 50);
            QtWrap.synth[1]->current_note = 45;
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(QtWrap.solo==0) // MIDI mode
        {
            system("aconnect 24 129");
            QtWrap.synth[1]->setOscillator();
        }

    }
    else
    {
        QtWrap.synth[1]->synthOn=0;
        if(QtWrap.solo) // SOLO mode
        {
            ledCommand_t cmd={ 45, OSC_2_OFF};
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(QtWrap.solo==0) // MIDI mode
        {
            system("aconnect -d 24 129");
        }
    }
}

void MidiMizeForm::on_osc2SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=SINE;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 50);
        }
    }
}

void MidiMizeForm::on_osc2TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=TRIANGLE;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 50);
        }
    }
}

void MidiMizeForm::on_osc2SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=SAW;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 50);
        }
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
    QtWrap.synth[0]->reverb.width = static_cast<float>(value);
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc1ReverbLvl_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.lvl = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc1ReverbDamp_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.damp = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc1ReverbRoom_valueChanged(int value)
{
    QtWrap.synth[0]->reverb.room = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setReverb();
}

void MidiMizeForm::on_osc2ReverbWidth_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.width = static_cast<float>(value);
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ReverbLvl_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.lvl = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ReverbDamp_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.damp = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ReverbRoom_valueChanged(int value)
{
    QtWrap.synth[1]->reverb.room = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setReverb();
}

void MidiMizeForm::on_osc2ChorusNr_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.nr = value;
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusDepth_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.depth = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusLvl_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.lvl = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc2ChorusSpeed_valueChanged(int value)
{
    QtWrap.synth[1]->chorus.speed = static_cast<float>((value)/10.0);
    QtWrap.synth[1]->setChorus();
}

void MidiMizeForm::on_osc1ChorusNr_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.nr = value;
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusDepth_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.depth = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusLvl_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.lvl = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_osc1ChorusSpeed_valueChanged(int value)
{
    QtWrap.synth[0]->chorus.speed = static_cast<float>((value)/10.0);
    QtWrap.synth[0]->setChorus();
}

void MidiMizeForm::on_aboutButton_clicked()
{
    //aboutForm about;
    //about.exec();
}

int handle_midi_event_led(void* data, fluid_midi_event_t *event)
{
    QtWrapper *led = (QtWrapper*)data;
    int key = fluid_midi_event_get_key(event);
    int type = fluid_midi_event_get_type(event);
    char typec[24];
    ledCommand_t cmd, cmd_osc, cmd_pwr;
    sprintf(typec, "%d\n", type);
    if(type==144)
    {
        cmd = {key, OSC_2_BLK};
        led->led_ctrl->pushBuffer(cmd);
    }
    else if(type==128)
    {
        cmd_osc = {key, OSC_2_OFF};
        cmd_pwr = {key, PWR_ON};
        led->led_ctrl->pushBuffer(cmd_osc);
        led->led_ctrl->pushBuffer(cmd_pwr);
    }
    else if(type==208)
    {
        cmd = {key, PWR_BLK};
        led->led_ctrl->pushBuffer(cmd);
    }

    fluid_log(FLUID_INFO, typec);

    return FLUID_OK;
}

void MidiMizeForm::on_midiRbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.solo=0;
        QtWrap.synth[0]->init_midi();

        fluid_settings_t* ledSettings = new_fluid_settings();
        fluid_settings_setint(ledSettings, "midi.autoconnect", 1);
        fluid_settings_setstr(ledSettings, "midi.driver", FS_MIDI_DRIVER);

        QtWrap.synth[1]->init_midi();

        fluid_midi_router_t* ledRouter = new_fluid_midi_router(ledSettings, handle_midi_event_led, &QtWrap);
        fluid_midi_driver_t* leddriver = new_fluid_midi_driver(ledSettings, fluid_midi_router_handle_midi_event, ledRouter);

        if(QtWrap.synth[0]->synthOn)
        {
            ledCommand_t cmd={55, OSC_1_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[1]->setOscillator();
        }
        if(QtWrap.synth[1]->synthOn)
        {
            ledCommand_t cmd={55, OSC_2_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->setOscillator();
        }
    }
}

void MidiMizeForm::on_soloRbutton_clicked(bool checked)
{
    if(checked)
    {   
        if(QtWrap.solo==0) // MIDI mode
        {
            QtWrap.synth[0]->stop_midi();
            QtWrap.synth[1]->stop_midi();
        }

        QtWrap.solo=1;

        if(QtWrap.synth[0]->synthOn==0)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn)
        {
            ledCommand_t cmd={QtWrap.synth[0]->current_note, OSC_1_BLK};
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 50);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        if(QtWrap.synth[1]->synthOn==0)
        {
            QtWrap.synth[1]->setOscillator();
        }

        if(QtWrap.synth[1]->synthOn)
        {
            if(QtWrap.synth[1]->synthOn)
            {
                ledCommand_t cmd={QtWrap.synth[1]->current_note, OSC_2_BLK};
                QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 50);
                QtWrap.led_ctrl->pushBuffer(cmd);
            }

        }
    }

}
