#ifndef TLED_H
#define TLED_H

#include <pthread.h>
#include "cprotectedbuffer.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLK _IOW('a', 'b', int32_t*)
#define PWR _IOW('a', 'p', int32_t*)

/* f = 440 . 2 ^ (n-69)/12 - Tuning based on A4 = 440Hz */
static const float noteFreqs[128] = {8.18, 8.66, 9.18, 9.72, 10.30, 10.91, 11.56, 12.25, 12.98, 13.75, 14.57,
                                    15.43, 16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96,
                                    27.50, 29.14, 30.87, 32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91,
                                    55.00, 58.27, 61.74, 65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83,
                                    110.00, 116.54, 123.47, 130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65,
                                    220.00, 233.08, 246.94, 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30,
                                    440.00, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61,
                                    880.00, 932.33, 987.77, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22,
                                    1760.00, 1864.66, 1975.53, 2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44,
                                    3520.00, 3729.31, 3951.07, 4186.01, 4434.92, 4698.64, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88,
                                    7040.00, 7458.62, 7902.13, 8372.02, 8869.84, 9397.27, 9956.06, 10548.08, 11175.30, 11839.82, 12543.85};

enum lCmd { OSC_1_ON, OSC_1_OFF, OSC_1_BLK, OSC_2_ON, OSC_2_OFF, OSC_2_BLK, PWR_ON, PWR_OFF };


//enum noteNames { A0=21, Bb0, B0, Db1, D1, Eb1, E1, F1, Gb1, G1, Ab1,
//                A1, Bb1, B1, C2, Db2, D2, Eb2, E2, F2, Gb2, G2, Ab2,
//                A2, Bb2, B2, C3, Db3, D3, Eb3, E3, F3, Gb3, G3, Ab3,
//                A3, Bb3, B3, C4, Db4, D4, Eb4, E4, F4, Gb4, G4, Ab4,
//                A4, Bb4, B4, C5, Db5, D5, Eb5, E5, F5, Gb5, G5, Ab5,
//                A5, Bb5, B5, C6, Db6, D6, Eb6, E6, F6, Gb6, G6, Ab6,
//                A6, Bb6, B6, C7, Db7, D7, Eb7, E7, F7, Gb7, G7, Ab7,
//                A7, Bb7, B7, C8, Db8, D8, Eb8, E8, F8, Gb8, G8, Ab8,
//                A8, Bb8, B8, C9, Db9, D9, Eb9, E9, F9, Gb9, G9,
//                } notes;

struct ledCommand_t
{
    int note;
    lCmd led_cmd;
};

class TLed
{
    private:
        CProtectedBuffer<ledCommand_t>* cmdBuffer;
        pthread_t threadId;
        pthread_attr_t threadAttr;
        void*(*job)(void*);
    public:
        TLed(CProtectedBuffer<ledCommand_t>* led_cmds, void*(*job) (void*));
        int create();
        int join();
        int exit();
};

void* tLed_job(void* opaque);
float note_to_freq(int note);

#endif // TLED_H
