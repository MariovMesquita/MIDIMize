#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BLK _IOW('a', 'b', int32_t*)
#define PWR _IOW('a', 'p', int32_t*)

int main(int argc, char* argv[])
{
    char myCmd[32];
    char led[3];
    char cmd[3];
    char note[3];
    size_t bufsize = 32;
    int osc1, osc2, pwr;
    int32_t freq, ctrl;
    int aux;

    // char* ms=argv[1];
    // printf("\n");
    // printf("%s", argv[1]);

    // printf("\n\nInserting Device Drivers...\n");
    // system("insmod osc2_led_rpi4.ko");
    // system("insmod osc1_led_rpi4.ko");
    // system("insmod pwr_led_rpi4.ko");

    // sleep(2);

    // fprintf(stdout, "\nNo. of clock ticks per sec : %ld\n", sysconf(_SC_CLK_TCK));

    // sleep(2);

    //osc1 = open("/dev/osc1_led", O_WRONLY);
    //osc2 = open("/dev/osc2_led", O_WRONLY);
    //pwr = open("/dev/pwr_led", O_WRONLY);

    // if(osc1 < 0 | osc2 < 0 | pwr < 0)
    // {
    //     printf("Cannot open device file\n");
    //     return 0;
    // }


    printf("Enter led command: ");
    getline(&myCmd, &bufsize, stdin);

    printf("\nCOMMAND:\n-> '%s' ", myCmd);

    strncpy(&led, &myCmd, 3);
    myCmd[3] = '\0';

    printf("\n%s\n", led);
getchar();
    aux = strncmp(myCmd+3, " ", 1);

    if(aux == 0)
    {
        printf("\n All good!\n");

        strncpy(cmd, myCmd+4, 3);
        printf("\n%s\n", cmd);  
    }
    else
    {
        printf("\nError\n");
        exit(-1);
    }


    // //while(1)
    // //{
    //     printf("Enter osc1 value to blink: ");
    //     scanf("%d", &freq);
    //     printf("Writing frequency to driver\n");
    //     ioctl(osc1, BLK, (int32_t*) &freq);

    //     printf("Enter osc2 value to blink: ");
    //     scanf("%d", &freq);
    //     printf("Writing frequency to driver\n");
    //     ioctl(osc2, BLK, (int32_t*) &freq);

    //     printf("Pwr Led control \n-OFF- 0\n-ON 1\n");
    //     scanf("%d", &ctrl);
    //     printf("Sending power control to driver\n");
    //     //ioctl(fd0, PWR, (int32_t*) &ctrl);
    //     if(ctrl == 0)
    //     {
    //         system("echo 0 > /dev/pwr_led");
    //     }
    //     else
    //     {
    //         system("echo 1 > /dev/pwr_led");
    //     }
    //     sleep(1);

    //     printf("osc 1 Led control \n-OFF- 0\n-ON 1\n");
    //     scanf("%d", &ctrl);
    //     printf("Sending power control to driver\n");
    //     ioctl(osc1, PWR, (int32_t*) &ctrl);
    //     sleep(1);

    //     printf("osc 2 Led control \n-OFF- 0\n-ON 1\n");
    //     scanf("%d", &ctrl);
    //     printf("Sending power control to driver\n");
    //     ioctl(osc2, PWR, (int32_t*) &ctrl);
    //     sleep(1);
    // //}

    // printf("\nLED's OFF in 10s\n");
    // sleep(10);
    // printf("Closing Device Driver.\n");
    // close(osc1);
    // close(osc2);
    // close(pwr);
    // putchar('\n');
    // printf("Removing Device Driver.\n");
    // system("rmmod osc2_led_rpi4");
    // system("rmmod osc1_led_rpi4");
    // system("rmmod pwr_led_rpi4");

    return 0;

}