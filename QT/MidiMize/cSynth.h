#ifndef CSYNTH_H
#define CSYNTH_H

#include <pthread.h>
#include <fluidsynth.h>
#include <string>

using namespace std;

/* SYNTH INIT SETTINGS */
#define FS_SAMPLE_RATE 44100.0
#define FS_CPU_CORES 2
#define FS_AUDIO_DRIVER "alsa"
#define FS_MIDI_DRIVER "alsa_seq"

/* SOUNDFONTS */
//#define SF_SINE_PATH "/etc/MIDImize/soundFonts/sine.sf2"
//#define SF_TRIANGLE_PATH "/etc/MIDImize/soundFonts/tri.sf2"
//#define SF_SAW_PATH "/etc/MIDImize/soundFonts/saw.sf2"

#define SF_SINE_PATH "/etc/MIDImize/soundFonts/test/JR_Cosmic.SF2"
#define SF_TRIANGLE_PATH "/etc/MIDImize/soundFonts/test/JR_ambiance1.sf2"
#define SF_SAW_PATH "/etc/MIDImize/soundFonts/test/JR_analog.sf2"

//struct init_settings
//{
//    float fs_sampleRate = 44100.0;
//    float fs_cpuCores = 2;
//    string fs_audioDriver = "alsa";
//    string fs_midiDriver = "alsa_seq";
//    string fs_soundFonts[3] = {"/etc/MIDImize/soundFonts/sine.sf2" , "/etc/MIDImize/soundFonts/saw.sf2" , "/etc/MIDImize/soundFonts/triangle.sf2"};
//};

enum oscillator_t
{
    SINE,
    TRIANGLE,
    SAW,
};

struct sound_font_t
{
    string name;
    const char* fileName;
    int id;
};

struct chorus_settings_t
{

    float active;
    float speed;    // 0.0 - 5.0
    int nr;         // 0 - 99
    float lvl;      // 0.0 - 10.0
    float depth;    // 0.0 - 21.0
    float waveType; // FLUID_CHORUS_MOD_SINE, FLUID_CHORUS_MOD_TRIANGLE
};

struct reverb_settings_t
{
    bool active;
    float width; // 0.0 - 100.0
    float room;  // 0.0 - 1.0
    float lvl;   // 0.0 - 1.0
    float damp;  // 0.0 - 1.0
};

class cSynth
{
    private:
        fluid_audio_driver_t* FsAudioDriver;
        fluid_midi_driver_t* FsMidiDriver;
        fluid_settings_t* FsSettings;
        fluid_synth_t* FsSynth;
        sound_font_t sFonts[3];

        float gain;


    public:
        cSynth();
        ~cSynth();

        void noteOn(int chan, int key, int vel);
        void noteOff(int chan, int key);
        void setReverb();
        void setChorus();
        void setOscillator();
        void setGain(float gain);
        void setPitch();
        void init_synth();
        void handle_midi_event();



        //int synthID;
        chorus_settings_t chorus;
        reverb_settings_t reverb;
        oscillator_t oscillator;
        int pitchBend;
        int current_note;
        bool synthOn;
};

#endif // CSYNTH_H
