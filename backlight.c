#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//int main()
int get_backlight(char *str)
{
    FILE * fp;
    char buffer[10];
    memset(buffer, 0, 10);

    //this cmd get date
    char *cmd = "echo $(intel_backlight | sed \"s/Current backlight value: //g\")";

    fp = popen(cmd, "r");
    signal(SIGCHLD, SIG_IGN);
    fgets(buffer,sizeof(buffer),fp);

    for(int i = 0; i < sizeof(buffer); i++)
    {
	if(buffer[i] == '\n')
	{
		buffer[i]=0;
	}
	
	if(buffer[i] == ' ')
	{
		buffer[i]=0;
	}
    }

    //printf("%s\n", buffer);
    sprintf(str, "%s", buffer); 
    pclose(fp);
}

