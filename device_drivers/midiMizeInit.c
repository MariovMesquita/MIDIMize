#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    system("/etc/MIDImize/MidiMize -platform linuxfb");

    return 0;
}