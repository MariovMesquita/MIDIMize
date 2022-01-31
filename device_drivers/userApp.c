#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BLK _IOW('a', 'b', int32_t*)
#define PWR _IOW('a', 'p', int32_t*)

int main(int argc, char* argv[])
{
    int fd0;
    int32_t freq, ctrl;

    char* ms=argv[1];
    printf("\n");
    printf("%s", argv[1]);

    printf("\n\nInserting Device Driver...\n");
    system("insmod osc2_led_rpi4.ko");

    fprintf(stdout, "No. of clock ticks per sec : %ld\n", sysconf(_SC_CLK_TCK));


    fd0 = open("/dev/osc2_led", O_WRONLY);
    if(fd0 < 0)
    {
        printf("Cannot open device file\n");
        return 0;
    }

    while(1)
    {
        printf("Enter value to blink: ");
        scanf("%d", &freq);
        printf("Writing frequency to driver\n");
        ioctl(fd0, BLK, (int32_t*) &freq);

        printf("Led control \n-OFF- 0\n-ON 1\n");
        scanf("%d", &ctrl);
        printf("Sending power control to driver\n");
        ioctl(fd0, PWR, (int32_t*) &ctrl);
        sleep(1);
    }
    printf("Closing Device Driver.\n");
    close(fd0);
    putchar('\n');
    printf("Removing Device Driver.\n");
    system("rmmod osc2_led_rpi4");

    return 0;

}