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
    /* System Volume - amixer */
    string my_volume = to_string(value);
    char const *cmd = my_volume.c_str();
    setenv("MDMZ_VOLUME", cmd, 1);

    system("amixer set Headphone $MDMZ_VOLUME%");
}


/*********************  MIDI LED HANDLERS *********************/

int handle_midi_event_osc1(void* data, fluid_midi_event_t *event)
{
    static int note_count = 0;
    char type_c[24];
    char key_c[24];
    ledCommand_t cmd, cmd_osc, cmd_pwr;
    QtWrapper *led = (QtWrapper*)data;

    /* Get pressed key */
    int key = fluid_midi_event_get_key(event);
    sprintf(key_c, "\nKey: %d\n", key);
    /* Get MIDI event type */
    int type = fluid_midi_event_get_type(event);
    sprintf(type_c, "Event type: %d\n", type);

    if(type==144)// Note On
    {
        if(note_count==0)
        {
            cmd = {key, OSC_1_BLK};
            led->led_ctrl->pushBuffer(cmd);
        }
        note_count++;
    }
    else if(type==128) // Note Off
    {
        note_count--;
        if(note_count==0)
        {
            cmd_osc = {key, OSC_1_OFF};
            cmd_pwr = {key, PWR_ON};
            led->led_ctrl->pushBuffer(cmd_osc);
            led->led_ctrl->pushBuffer(cmd_pwr);
        }
    }
    else if(type==208) // Aftertouch
    {
        cmd = {key, PWR_BLK};
        led->led_ctrl->pushBuffer(cmd);
    }

    /* Print key */
    fluid_log(FLUID_INFO, key_c);
    /* Print MIDI event type */
    fluid_log(FLUID_INFO, type_c);

    return FLUID_OK;
}

int handle_midi_event_osc2(void* data, fluid_midi_event_t *event)
{
    static int note_count = 0;
    char type_c[24];
    char key_c[24];
    ledCommand_t cmd, cmd_osc, cmd_pwr;
    QtWrapper *led = (QtWrapper*)data;

    /* Get pressed key */
    int key = fluid_midi_event_get_key(event);
    sprintf(key_c, "\nKey: %d\n", key);
    /* Get MIDI event type */
    int type = fluid_midi_event_get_type(event);
    sprintf(type_c, "Event type: %d\n", type);


    if(type==144) // Note On
    {
        if(note_count==0)
        {
            cmd = {key, OSC_2_BLK};
            led->led_ctrl->pushBuffer(cmd);
        }
        note_count++;
    }
    else if(type==128) // Note Off
    {
        note_count--;
        if(note_count==0)
        {
            cmd_osc = {key, OSC_2_OFF};
            cmd_pwr = {key, PWR_ON};
            led->led_ctrl->pushBuffer(cmd_osc);
            led->led_ctrl->pushBuffer(cmd_pwr);
        }

    }
    else if(type==208) // Aftertouch
    {
        cmd = {key, PWR_BLK};
        led->led_ctrl->pushBuffer(cmd);
    }

    /* Print key */
    fluid_log(FLUID_INFO, key_c);
    /* Print MIDI event type */
    fluid_log(FLUID_INFO, type_c);

    return FLUID_OK;
}

void MidiMizeForm::init_osc1Led_midi()
{
    this->osc1LedSettings = new_fluid_settings();
    fluid_settings_setint(this->osc1LedSettings, "midi.autoconnect", 0);
    fluid_settings_setstr(this->osc1LedSettings, "midi.driver", FS_MIDI_DRIVER);

    this->osc1LedRouter = new_fluid_midi_router(this->osc1LedSettings, handle_midi_event_osc1, &QtWrap);
    this->osc1LedDriver = new_fluid_midi_driver(this->osc1LedSettings, fluid_midi_router_handle_midi_event, this->osc1LedRouter);

}

void MidiMizeForm::init_osc2Led_midi()
{
    this->osc2LedSettings = new_fluid_settings();
    fluid_settings_setint(this->osc2LedSettings, "midi.autoconnect", 0);
    fluid_settings_setstr(this->osc2LedSettings, "midi.driver", FS_MIDI_DRIVER);

    this->osc2LedRouter = new_fluid_midi_router(this->osc2LedSettings, handle_midi_event_osc2, &QtWrap);
    this->osc2LedDriver = new_fluid_midi_driver(this->osc2LedSettings, fluid_midi_router_handle_midi_event, this->osc2LedRouter);
}

/********************* END OF MIDI LED HANDLERS *********************/

/********************* TURN OSCILLATOR 1 ON / OFF *******************/
void MidiMizeForm::on_osc1Pbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->synthOn=true; // OSCILLATOR 1 ON

        if(QtWrap.solo) // SOLO mode
        {
            QtWrap.synth[0]->setOscillator(); 
            if(QtWrap.synth[0]->current_note!=0)
            {
                QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
                ledCommand_t cmd={QtWrap.synth[0]->current_note, OSC_1_BLK};
                QtWrap.led_ctrl->pushBuffer(cmd);
            }
        }

        else if(!QtWrap.solo) // MIDI mode
        {
            system("aconnect 24 128"); // Connect midi driver - sound
            system("aconnect 24 130"); // Connect midi driver - LED
            QtWrap.synth[0]->setOscillator();
        }
    }

    else
    {
        QtWrap.synth[0]->synthOn=false; // OSCILLATOR 1 OFF
        
        if(QtWrap.solo) // SOLO mode
        {
            ledCommand_t cmd={ 55, OSC_1_OFF};
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(!QtWrap.solo) // MIDI mode
        {
            system("aconnect -d 24 128"); // Disconnect midi driver - sound
            system("aconnect -d 24 130"); // Disconnect midi driver - LED
        }
    }
}
/*****************************************************************/

void MidiMizeForm::on_osc1TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=AMBIANCE;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
        }
    }
}

void MidiMizeForm::on_osc1SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=COSMIC;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
        }
    }
}

void MidiMizeForm::on_osc1SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[0]->oscillator=ANALOG;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
        }
    }
}

/********************* TURN OSCILLATOR 2 ON / OFF *******************/
void MidiMizeForm::on_osc2Pbutton_clicked(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->synthOn=true;

        if(QtWrap.solo) // SOLO mode
        {
            QtWrap.synth[1]->setOscillator();
            if(QtWrap.synth[1]->current_note!=0)
            {
                ledCommand_t cmd={QtWrap.synth[1]->current_note, OSC_2_BLK};
                QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
                QtWrap.led_ctrl->pushBuffer(cmd);
            }
        }

        else if(!QtWrap.solo) // MIDI mode
        {
            system("aconnect 24 129");
            system("aconnect 24 131");
            QtWrap.synth[1]->setOscillator();
        }

    }
    else
    {
        QtWrap.synth[1]->synthOn=false;
        if(QtWrap.solo) // SOLO mode
        {
            ledCommand_t cmd={ 45, OSC_2_OFF};
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        else if(!QtWrap.solo) // MIDI mode
        {
            system("aconnect -d 24 129");
            system("aconnect -d 24 131");
        }
    }
}
/*****************************************************************/

void MidiMizeForm::on_osc2SineRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=COSMIC;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
        }
    }
}

void MidiMizeForm::on_osc2TriRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=AMBIANCE;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
        }
    }
}

void MidiMizeForm::on_osc2SawRbutton_toggled(bool checked)
{
    if (checked)
    {
        QtWrap.synth[1]->oscillator=ANALOG;

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->setOscillator();
        }


        if(QtWrap.synth[1]->synthOn && QtWrap.solo)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
        }
    }
}


void MidiMizeForm::on_osc1ReverbEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->reverb.active=true;
        QtWrap.synth[0]->setReverb();
    }
    else
    {
        QtWrap.synth[0]->reverb.active=false;
        QtWrap.synth[0]->setReverb();
    }
}

void MidiMizeForm::on_osc2ReverbEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->reverb.active=true;
        QtWrap.synth[1]->setReverb();
    }
    else
    {
        QtWrap.synth[1]->reverb.active=false;
        QtWrap.synth[1]->setReverb();
    }
}

void MidiMizeForm::on_osc1ChorusEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[0]->chorus.active=true;
        QtWrap.synth[0]->setChorus();
    }
    else
    {
        QtWrap.synth[0]->chorus.active=false;
        QtWrap.synth[0]->setChorus();
    }
}

void MidiMizeForm::on_osc2ChorusEnable_toggled(bool checked)
{
    if(checked)
    {
        QtWrap.synth[1]->chorus.active=true;
        QtWrap.synth[1]->setChorus();
    }
    else
    {
        QtWrap.synth[1]->chorus.active=false;
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
    system("aplay /etc/MIDImize/music/wake_up.wav &"); // This is for you Pires! \m/
}

/********************* CHANGE TO MIDI MODE ***********************/
void MidiMizeForm::on_midiRbutton_clicked(bool checked)
{
    if(checked)
    {
        /* CHANGE TO MIDI MODE */
        QtWrap.solo=false;

        QtWrap.synth[0]->init_midi();
        QtWrap.synth[1]->init_midi();
        init_osc1Led_midi();
        init_osc2Led_midi();

        /* TURN OFF LED's AND SOUND FROM SOLO MODE */
        if(QtWrap.synth[0]->synthOn)
        {
            system("aconnect 24 128");
            system("aconnect 24 130");
            ledCommand_t cmd={55, OSC_1_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            //QtWrap.synth[0]->current_note=0;
            QtWrap.synth[0]->setOscillator();

        }
        if(QtWrap.synth[1]->synthOn)
        {
            system("aconnect 24 129");
            system("aconnect 24 131");
            ledCommand_t cmd={55, OSC_2_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            //QtWrap.synth[1]->current_note=0;
            QtWrap.synth[1]->setOscillator();

        }

    }
}
/*****************************************************************/

/********************* CHANGE TO SOLO MODE ***********************/
void MidiMizeForm::on_soloRbutton_clicked(bool checked)
{
    if(checked)
    {   
        if(!QtWrap.solo) // MIDI mode
        {
            QtWrap.synth[0]->stop_midi();
            QtWrap.synth[1]->stop_midi();
            delete_fluid_midi_driver(this->osc1LedDriver);
            delete_fluid_midi_router(this->osc1LedRouter);
            delete_fluid_midi_driver(this->osc2LedDriver);
            delete_fluid_midi_router(this->osc2LedRouter);
            delete_fluid_settings(this->osc1LedSettings);
            delete_fluid_settings(this->osc2LedSettings);
        }

        QtWrap.solo=true;

        if(QtWrap.synth[0]->synthOn==false)
        {
            QtWrap.synth[0]->setOscillator();
        }

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
            if(QtWrap.synth[0]->current_note!=0)
            {
                ledCommand_t cmd={QtWrap.synth[0]->current_note, OSC_1_BLK};
                QtWrap.led_ctrl->pushBuffer(cmd);
            }
        }

        if(QtWrap.synth[1]->synthOn==false)
        {
            QtWrap.synth[1]->setOscillator();
        }

        if(QtWrap.synth[1]->synthOn)
        {
            if(QtWrap.synth[1]->synthOn)
            {
                QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
                if(QtWrap.synth[1]->current_note!=0)
                {
                    ledCommand_t cmd={QtWrap.synth[1]->current_note, OSC_2_BLK};
                    QtWrap.led_ctrl->pushBuffer(cmd);
                }
            }
        }
    }

}
/*****************************************************************/


/******************* MIDI Keyboard GUI functions ********************/

void MidiMizeForm::kbrdKeyOn(noteNames note)
{
    if(QtWrap.solo) // SOLO mode
    {
        if(QtWrap.synth[0]->current_note==0 && QtWrap.synth[0]->synthOn)
            QtWrap.synth[0]->current_note=note;

        if(QtWrap.synth[1]->current_note==0 && QtWrap.synth[1]->synthOn)
            QtWrap.synth[1]->current_note=note;

        if(QtWrap.synth[0]->synthOn)
        {
            QtWrap.synth[0]->noteOn(1, QtWrap.synth[0]->current_note, 80);
            ledCommand_t cmd={note, OSC_1_BLK};
            QtWrap.led_ctrl->pushBuffer(cmd);
        }

        if(QtWrap.synth[1]->synthOn)
        {
            QtWrap.synth[1]->noteOn(1, QtWrap.synth[1]->current_note, 80);
            ledCommand_t cmd={note, OSC_2_BLK};
            QtWrap.led_ctrl->pushBuffer(cmd);
        }
    }
}

void MidiMizeForm::kbrdKeyOff(noteNames note)
{
    if(QtWrap.solo) // SOLO mode
    {
        if(QtWrap.synth[0]->current_note==note)
        {
            QtWrap.synth[0]->noteOff(1, QtWrap.synth[0]->current_note);
            ledCommand_t cmd={note, OSC_1_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[0]->current_note=0;
        }


        if(QtWrap.synth[1]->current_note==note)
        {
            QtWrap.synth[1]->noteOff(1, QtWrap.synth[1]->current_note);
            ledCommand_t cmd={note, OSC_2_OFF};
            QtWrap.led_ctrl->pushBuffer(cmd);
            QtWrap.synth[1]->current_note=0;
        }
    }
    else
    {
        if(QtWrap.synth[0]->current_note==note)
            QtWrap.synth[0]->current_note=0;

        if(QtWrap.synth[1]->current_note==note)
            QtWrap.synth[1]->current_note=0;
    }
}

/*************************************************************/


void MidiMizeForm::on_C4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(C4);
    }
    else
    {
        kbrdKeyOff(C4);
    }
}


void MidiMizeForm::on_Db4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Db4);
    }
    else
    {
        kbrdKeyOff(Db4);
    }
}

void MidiMizeForm::on_D4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(D4);
    }
    else
    {
        kbrdKeyOff(D4);
    }
}

void MidiMizeForm::on_Eb4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Eb4);
    }
    else
    {
        kbrdKeyOff(Eb4);
    }
}

void MidiMizeForm::on_E4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(E4);
    }
    else
    {
        kbrdKeyOff(E4);
    }
}

void MidiMizeForm::on_F4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(F4);
    }
    else
    {
        kbrdKeyOff(F4);
    }
}

void MidiMizeForm::on_Gb4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Gb4);
    }
    else
    {
        kbrdKeyOff(Gb4);
    }
}

void MidiMizeForm::on_G4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(G4);
    }
    else
    {
        kbrdKeyOff(G4);
    }
}

void MidiMizeForm::on_Ab4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Ab4);
    }
    else
    {
        kbrdKeyOff(Ab4);
    }
}

void MidiMizeForm::on_A4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(A4);
    }
    else
    {
        kbrdKeyOff(A4);
    }
}

void MidiMizeForm::on_Bb4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Bb4);
    }
    else
    {
        kbrdKeyOff(Bb4);
    }
}

void MidiMizeForm::on_B4_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(B4);
    }
    else
    {
        kbrdKeyOff(B4);
    }
}

void MidiMizeForm::on_C5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(C5);
    }
    else
    {
        kbrdKeyOff(C5);
    }
}

void MidiMizeForm::on_Db5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Db5);
    }
    else
    {
        kbrdKeyOff(Db5);
    }
}

void MidiMizeForm::on_D5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(D5);
    }
    else
    {
        kbrdKeyOff(D5);
    }
}

void MidiMizeForm::on_Eb5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Eb5);
    }
    else
    {
        kbrdKeyOff(Eb5);
    }
}

void MidiMizeForm::on_E5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(E5);
    }
    else
    {
        kbrdKeyOff(E5);
    }
}

void MidiMizeForm::on_F5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(F5);
    }
    else
    {
        kbrdKeyOff(F5);
    }
}

void MidiMizeForm::on_Gb5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(Gb5);
    }
    else
    {
        kbrdKeyOff(Gb5);
    }
}

void MidiMizeForm::on_G5_Pb_clicked(bool checked)
{
    if(checked)
    {
        kbrdKeyOn(G5);
    }
    else
    {
        kbrdKeyOff(G5);
    }
}
