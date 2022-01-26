#include "cSynth.h"

using namespace std;

cSynth::cSynth()
{
    /* Create settings object and pass init values */
    this->FsSettings = new_fluid_settings();
    fluid_settings_setnum(FsSettings, "synth.sample-rate", initSettings.fs_sampleRate);
    fluid_settings_setint(FsSettings, "synth.cpu-cores", initSettings.fs_cpuCores);
    fluid_settings_setstr(FsSettings, "audio.driver", initSettings.fs_audioDriver.c_str());
    fluid_settings_setstr(FsSettings, "midi.driver", initSettings.fs_midiDriver.c_str());

    /* Create synth instance */
    this->FsSynth = new_fluid_synth(this->FsSettings);

    /* Load soundfonts */

    /* Create AudioDriver */
    this->FsAudioDriver = new_fluid_audio_driver(this->FsSettings, this->FsSynth);

    /* Create MidiDriver */
    this->FsMidiDriver = new_fluid_midi_driver(this->FsSettings, handle_midi_event, NULL);

}

void cSynth::chorusOnOff(bool onOff)
{
    if(onOff == 1)
        fluid_synth_set_chorus_on(this->FsSynth, 1);

    else
        fluid_synth_set_chorus_on(this->FsSynth, 0);
}

void cSynth::chorusSet()
{
    fluid_synth_set_chorus(this->FsSynth, this->synthChorus.Nr, this->synthChorus.Lvl, this->synthChorus.Speed, this->synthChorus.Depth, this->synthChorus.WaveType);
}

void cSynth::reverbOnOff(bool onOff)
{
    if(onOff == 1)
        fluid_synth_set_reverb_on(this->FsSynth, 1);

    else
        fluid_synth_set_reverb_on(this->FsSynth, 0);
}

void cSynth::reverbSet()
{
    fluid_synth_set_reverb(this->FsSynth, this->synthReverb.RoomSize, this->synthReverb.Damp, this->synthReverb.Width, this->synthReverb.Lvl);
}
