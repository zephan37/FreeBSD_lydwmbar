# lydwm-bar

- this is my own dwm status bar, use on FreeBSD.Before use it, you must to install pamixer package and lisysinfo first

# how to use
- git clone https://github.com/zephan37/FreeBSD_lydwmbar.git
- cd lydwm-bar
- gcc -o ly-dwm-status ly-dwm-status.c sound.c backlight.c battery.c date.c network.c resource.c config.h -lX11 -lsysinfo
- ly-dwm-status &
