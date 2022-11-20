#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include "config.h"

static Display *dpy;

void setstatus(char *str)
{
	XStoreName(dpy, DefaultRootWindow(dpy), str);
	XSync(dpy, False);
}

int main()
{
    //char *resource; 
    char *battery; 
    char *date;    
    char *backlight; 
    char *sound;
    char *network;
    char *status;

    //resource = (char *)malloc(sizeof(char) * 50);
    battery = (char *)malloc(sizeof(char) * 20);
    date = (char *)malloc(sizeof(char) * 40);
    backlight = (char *)malloc(sizeof(char) * 10);
    sound = (char *)malloc(sizeof(char) * 5);
    network = (char *)malloc(sizeof(char) * 10);
    status = (char *)malloc(sizeof(char) * 90);

    if(!(dpy = XOpenDisplay(NULL))) {
		fprintf(stderr, "dwmstatus: cannot open display.\n");
		return 1;
	}

    while(1)
    {
        //memset(resource, 0, 50);
	memset(battery, 0, 20);
	memset(date, 0, 40);
	memset(backlight, 0, 10);
	memset(sound, 0, 5);
	memset(network, 0, 10);
	memset(status, 0, 90);

        //getResource(resource);
        get_bat(battery);
        get_date(date);
        get_backlight(backlight);
        get_sound(sound);
        get_net_status(network);

        sprintf(status, "[My Cute FreeBSD] [Bat: %s%] [Backlight: %s%] [Sound: %s%] [Net: %s%] [%s]", battery, backlight, sound, network, date);
        //printf("%s\n", status);
        setstatus(status);

        sleep(1);
    }
    
    XCloseDisplay(dpy);
    //free(resource);
    free(battery);
    free(date);
    free(backlight);
    free(sound);
    free(network);
    free(status);

    return 0;
}
