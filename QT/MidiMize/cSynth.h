#ifndef CSYNTH_H
#define CSYNTH_H

#include <pthread.h>
#include <fluidsynth.h>
#include <string>

using namespace std;

/* SYNTH INIT SETTINGS */
#define FS_SAMPLE_RATE 44100.0
#define FS_CPU_CORES 4
#define FS_BUFFER_SIZE 128
#define FS_N_BUFFERS 8
#define FS_AUDIO_DRIVER "alsa"
#define FS_MIDI_DRIVER "alsa_seq"

/* SOUNDFONTS */

#define SF_COSMIC_PATH "/etc/MIDImize/soundFonts/cosmic.sf2"
#define SF_AMBIANCE_PATH "/etc/MIDImize/soundFonts/ambiance.sf2"
#define SF_ANALOG_PATH "/etc/MIDImize/soundFonts/analog.sf2"

/* TEST SOUNDFONTS

#define SF_TEST1_PATH "/etc/MIDImize/soundFonts/test/AcidSQNeutral.sf2"
#define SF_TEST2_PATH "/etc/MIDImize/soundFonts/test/AnalogSaw.sf2"
#define SF_TEST3_PATH "/etc/MIDImize/soundFonts/test/Beeper.sf2"
#define SF_TEST4_PATH "/etc/MIDImize/soundFonts/test/CandyBee.sf2"
#define SF_TEST5_PATH "/etc/MIDImize/soundFonts/test/DanceTrance.sf2"
#define SF_TEST6_PATH "/etc/MIDImize/soundFonts/test/DirtySub.sf2"
#define SF_TEST7_PATH "/etc/MIDImize/soundFonts/test/FM_Modulator.sf2"
#define SF_TEST8_PATH "/etc/MIDImize/soundFonts/test/HappyMellow.sf2"
#define SF_TEST9_PATH "/etc/MIDImize/soundFonts/test/HyperSaw.sf2"
#define SF_TEST10_PATH "/etc/MIDImize/soundFonts/test/JR_Bignoise.sf2"
#define SF_TEST11_PATH "/etc/MIDImize/soundFonts/test/JR_Cosmic.SF2"
#define SF_TEST12_PATH "/etc/MIDImize/soundFonts/test/JR_Ethnic_trumpets.SF2"
#define SF_TEST13_PATH "/etc/MIDImize/soundFonts/test/JR_Ethnic_voice.SF2"
#define SF_TEST14_PATH "/etc/MIDImize/soundFonts/test/JR_PADstring.SF2"
#define SF_TEST15_PATH "/etc/MIDImize/soundFonts/test/JR_String2.sf2"
#define SF_TEST16_PATH "/etc/MIDImize/soundFonts/test/JR_SynthString1.SF2"
#define SF_TEST17_PATH "/etc/MIDImize/soundFonts/test/JR_SynthString2.SF2"
#define SF_TEST18_PATH "/etc/MIDImize/soundFonts/test/JR__pad.SF2"
#define SF_TEST19_PATH "/etc/MIDImize/soundFonts/test/JR_ambiance1.SF2"
#define SF_TEST20_PATH "/etc/MIDImize/soundFonts/test/JR_analog.sf2"
#define SF_TEST21_PATH "/etc/MIDImize/soundFonts/test/JR_backgr.sf2"
#define SF_TEST22_PATH "/etc/MIDImize/soundFonts/test/JR_bells.SF2"
#define SF_TEST23_PATH "/etc/MIDImize/soundFonts/test/JR_bulles2.SF2"
#define SF_TEST24_PATH "/etc/MIDImize/soundFonts/test/JR_church.SF2"
#define SF_TEST25_PATH "/etc/MIDImize/soundFonts/test/JR_effect2k.SF2"
#define SF_TEST26_PATH "/etc/MIDImize/soundFonts/test/JR_effects2.SF2"
#define SF_TEST27_PATH "/etc/MIDImize/soundFonts/test/JR_elepiano.sf2"
#define SF_TEST28_PATH "/etc/MIDImize/soundFonts/test/JR_flute_electronique.SF2"
#define SF_TEST29_PATH "/etc/MIDImize/soundFonts/test/JR_galboro.SF2"
#define SF_TEST30_PATH "/etc/MIDImize/soundFonts/test/JR_ligeti.SF2"
#define SF_TEST31_PATH "/etc/MIDImize/soundFonts/test/JR_loops2k.SF2"
#define SF_TEST32_PATH "/etc/MIDImize/soundFonts/test/JR_male.sf2"
#define SF_TEST33_PATH "/etc/MIDImize/soundFonts/test/JR_mood.sf2"
#define SF_TEST34_PATH "/etc/MIDImize/soundFonts/test/JR_noises2.SF2"
#define SF_TEST35_PATH "/etc/MIDImize/soundFonts/test/JR_organ.sf2"
#define SF_TEST36_PATH "/etc/MIDImize/soundFonts/test/JR_pad_cloches.SF2"
#define SF_TEST37_PATH "/etc/MIDImize/soundFonts/test/JR_pad_voice.SF2"
#define SF_TEST38_PATH "/etc/MIDImize/soundFonts/test/JR_popol.SF2"
#define SF_TEST39_PATH "/etc/MIDImize/soundFonts/test/JR_sax.sf2"
#define SF_TEST40_PATH "/etc/MIDImize/soundFonts/test/JR_vibra.sf2"
#define SF_TEST41_PATH "/etc/MIDImize/soundFonts/test/JR_voice2.sf2"
#define SF_TEST42_PATH "/etc/MIDImize/soundFonts/test/KaputtSine.sf2"
#define SF_TEST43_PATH "/etc/MIDImize/soundFonts/test/PerfectSine.sf2"
#define SF_TEST44_PATH "/etc/MIDImize/soundFonts/test/PlasticStrings.sf2"
#define SF_TEST45_PATH "/etc/MIDImize/soundFonts/test/PolySpecialMono.sf2"
#define SF_TEST46_PATH "/etc/MIDImize/soundFonts/test/PulseWobbler.sf2"
#define SF_TEST47_PATH "/etc/MIDImize/soundFonts/test/Sine_Wave.sf2"
#define SF_TEST48_PATH "/etc/MIDImize/soundFonts/test/SolarWind.sf2"
#define SF_TEST49_PATH "/etc/MIDImize/soundFonts/test/SuperSaw1.sf2"
#define SF_TEST50_PATH "/etc/MIDImize/soundFonts/test/SuperSaw2.sf2"
#define SF_TEST51_PATH "/etc/MIDImize/soundFonts/test/SuperSaw3.sf2"
#define SF_TEST52_PATH "/etc/MIDImize/soundFonts/test/SynthE.sf2"
*/

enum oscillator_t
{
    COSMIC,
    AMBIANCE,
    ANALOG,
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
        fluid_midi_router_t* FsMidiRouter;
        fluid_settings_t* FsSettings;
        fluid_synth_t* FsSynth;
        sound_font_t sFonts[3];

        float gain;
        bool midi_on;

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
        void init_values();
        void delete_synth();
        void init_synth();
        void init_midi();
        void stop_midi();

        //int synthID;
        chorus_settings_t chorus;
        reverb_settings_t reverb;
        oscillator_t oscillator;
        int pitchBend;
        int current_note;
        bool synthOn;
};

#endif // CSYNTH_H
