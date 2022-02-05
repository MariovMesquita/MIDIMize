#include "cSynth.h"
#include <fluidsynth.h>

using namespace std;

cSynth::cSynth()
{    
    /* Create settings object and pass init values */
    this->FsSettings = new_fluid_settings();
    fluid_settings_setnum(FsSettings, "synth.sample-rate", FS_SAMPLE_RATE);
    fluid_settings_setint(FsSettings, "synth.cpu-cores", FS_CPU_CORES);
    fluid_settings_setstr(FsSettings, "audio.driver", FS_AUDIO_DRIVER);
    fluid_settings_setstr(FsSettings, "midi.driver", FS_MIDI_DRIVER);
    fluid_settings_setint(FsSettings, "audio.period-size", FS_BUFFER_SIZE);
    fluid_settings_setint(FsSettings, "audio.periods", FS_N_BUFFERS);
    fluid_settings_setint(FsSettings, "synth.verbose", 1);
    fluid_settings_setint(FsSettings, "midi.autoconnect", 0);

    /* Create synth instance */
    this->FsSynth = new_fluid_synth(this->FsSettings);

    /* Load soundfonts */
    /*ANALOG*/
    this->sFonts[2].name="analog";
    this->sFonts[2].fileName=SF_ANALOG_PATH;
    this->sFonts[2].id = fluid_synth_sfload(this->FsSynth, this->sFonts[2].fileName, 1);
    /*AMBIANCE*/
    this->sFonts[1].name="ambiance";
    this->sFonts[1].fileName=SF_AMBIANCE_PATH;
    this->sFonts[1].id = fluid_synth_sfload(this->FsSynth, this->sFonts[1].fileName, 1);
    /*COSMIC*/
    this->sFonts[0].name="cosmic";
    this->sFonts[0].fileName=SF_COSMIC_PATH;
    this->sFonts[0].id = fluid_synth_sfload(this->FsSynth, this->sFonts[0].fileName, 1);

    /* Create Audio Driver */
    this->FsAudioDriver = new_fluid_audio_driver(this->FsSettings, this->FsSynth);

    /* Init Values */
    init_values();

}

void cSynth::init_midi()
{
    /* Create MIDI router */
    this->FsMidiRouter = new_fluid_midi_router(this->FsSettings, fluid_synth_handle_midi_event, this->FsSynth);

    /* Create MIDI driver */
    this->FsMidiDriver = new_fluid_midi_driver(this->FsSettings, fluid_midi_router_handle_midi_event, this->FsMidiRouter);
}

void cSynth::stop_midi()
{
    delete_fluid_midi_driver(this->FsMidiDriver);
    delete_fluid_midi_router(this->FsMidiRouter);
}

void cSynth::init_values()
{
    this->synthOn = false;
    this->pitchBend = 0;
    this->gain = 0.8; // meter aqui o ganho normalizado
    this->oscillator = COSMIC;

    this->chorus.active = 0;
    this->chorus.nr = 0;
    this->chorus.speed = 0;
    this->chorus.lvl = 0;
    this->chorus.depth = 0;
    this->chorus.waveType = FLUID_CHORUS_MOD_SINE;

    this->reverb.active = 0;
    this->reverb.width = 0;
    this->reverb.room = 0;
    this->reverb.lvl = 0;
    this->reverb.damp = 0;
}

/*
 * MIDI Note On
 * Sends note on (key) event to MIDI channel (chan)
 * ALL CHANNELS -> chan = -1
 * Key ->  0 - 127
 */
void cSynth::noteOn(int chan, int key, int vel)
{
    fluid_synth_noteon(this->FsSynth, chan, key, vel);
}

/*
 * MIDI Note OFF
 * Sends note off (key) to MIDI channel (chan)
 * ALL CHANNELS -> chan = -1
 * Key ->  0 - 127
 * Vel (velocity) -> 0-127 ( 0 = noteoff )
 */
void cSynth::noteOff(int chan, int key)
{
    fluid_synth_noteoff(this->FsSynth, chan, key);
}

/*
 * Turns reverb on or off
 * Sets reverb values
 * width    0.0 - 100.0
 * room     0.0 - 1.0
 * lvl      0.0 - 1.0
 * damp     0.0 - 1.0
 */
void cSynth::setReverb()
{
    if(this->reverb.active == 1)
    {
        fluid_synth_set_reverb_on(this->FsSynth, 1);
    }
    else
    {
        fluid_synth_set_reverb_on(this->FsSynth, 0);
    }

    fluid_synth_set_reverb(this->FsSynth, this->reverb.room, this->reverb.damp, this->reverb.width, this->reverb.lvl);
}

/*
 * Turns reverb on or off
 * Sets reverb values
 * nr       0 - 99
 * lvl      0.0 - 10.0
 * speed    0.1 - 5.0 Hz
 * depth    0.0 - 21.0
 * type     FLUID_CHORUS_MOD_SINE, FLUID_CHORUS_MOD_TRIANGLE
 */
void cSynth::setChorus()
{
    if(this->chorus.active == 1)
    {
        //this->chorus.active=1;
        fluid_synth_set_chorus_on(this->FsSynth, 1);
    }
    else
    {
        //this->chorus.active=0;
        fluid_synth_set_chorus_on(this->FsSynth, 0);
    }

    fluid_synth_set_chorus(this->FsSynth, this->chorus.nr, this->chorus.lvl, this->chorus.speed, this->chorus.depth, this->chorus.waveType);
}

/*
 * Sets synth gain
 * range 0.0 - 10.0
 */
void cSynth::setGain(float gain)
{
    this->gain = gain;
    fluid_synth_set_gain(this->FsSynth, this->gain);
}

/*
 * Sets synth gain
 * range 0.0 - 10.0
 * MIDI channel = -1  -> ALL CHANNELS
 */
void cSynth::setPitch()
{
    fluid_synth_pitch_bend(this->FsSynth, -1, this->pitchBend);
}

/*
 * Changes synth oscillator (soundFont)
 * reloads a soundFont loaded at synth initialization
 */
void cSynth::setOscillator()
{   
    switch(this->oscillator)
    {
        case COSMIC:
            //this->oscillator = SINE;
            fluid_synth_sfload(this->FsSynth, this->sFonts[0].fileName, 1);
            this->setGain(0.8);
            break;

        case AMBIANCE:
            //this->oscillator = TRIANGLE;
            fluid_synth_sfload(this->FsSynth, this->sFonts[1].fileName, 1);
            this->setGain(0.8);
            break;

        case ANALOG:
            //this->oscillator = SAW;
            fluid_synth_sfload(this->FsSynth, this->sFonts[2].fileName, 1);
            this->setGain(0.6);
            break;
    }
}

cSynth::~cSynth()
{
    /* Remove Audio Driver */
    delete_fluid_audio_driver(this->FsAudioDriver);

    /* Remove MIDI Driver */
    delete_fluid_midi_driver(this->FsMidiDriver);

    /* Remove synth settings */
    delete_fluid_settings(this->FsSettings);

    /* Delete synth instance */
    delete_fluid_synth(this->FsSynth);
}
