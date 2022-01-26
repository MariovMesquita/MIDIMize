#ifndef CSYNTH_H
#define CSYNTH_H

#include <pthread.h>
#include <fluidsynth.h>
#include <string>

using namespace std;

enum oscillator
{
    SINE,
    SAW,
    TRIANGLE,
};

struct init_settings
{
    float fs_sampleRate = 44100.0;
    float fs_cpuCores = 2;
    string fs_audioDriver = "alsa";
    string fs_midiDriver = "alsa_seq";
    string fs_soundFonts[3] = {"/etc/MIDImize/soundFonts/sine.sf2" , "/etc/MIDImize/soundFonts/saw.sf2" , "/etc/MIDImize/soundFonts/triangle.sf2"};
};

struct chorus_settings
{
    float chorusSpeed;
    int chorusNr;
    float chorusLvl;
    float chorusDepth;
    float chorusActive;
    float chorusWave;
};

struct reverb_settings
{
    bool reverbActive;
    float reverbWidth;
    float reverbRoom;
    float reverbLvl;
    float reverbDamp;
};

class cSynth
{
    private:
        init_settings initSettings;
        fluid_settings_t* FsSettings;
        fluid_synth_t* FsSynth;
        float synthGain;
        chorus_settings synthChorus;
        reverb_settings synthReverb;
        oscillator synthOscillator;
        bool synthOn;
        int synthID;

    public:
        cSynth();
        ~cSynth();

};

#endif // CSYNTH_H
