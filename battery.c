#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int get_bat_status(char *str)
{
    FILE * fp;
    char buffer[10];
    memset(buffer, 0, 10);

    //this cmd get sound
    char* cmd = "echo $(apm | grep \"AC Line status: \" | sed \"s/AC Line status: //g\")";
	
    fp = popen(cmd, "r");
    signal(SIGCHLD, SIG_IGN);

    fgets(buffer,sizeof(buffer),fp);

    for(int i = 0; i < sizeof(buffer); i++)
    {
	if(buffer[i] == '\n')
	{
		buffer[i]=0;
	}
    }

    //printf("%s", buffer);
    sprintf(str, "%s", buffer); 
    pclose(fp);
}

int get_bat_life(char *str)
{
    FILE * fp;
    char buffer[5];
    memset(buffer, 0, 5);

    //this cmd get sound
    char* cmd = "echo $(apm | grep \"Remaining battery life: \" | sed \"s/Remaining battery life: //g\" | head -n 1)";

    fp = popen(cmd, "r");
    signal(SIGCHLD, SIG_IGN);

    fgets(buffer,sizeof(buffer),fp);
	
    for(int i = 0; i < sizeof(buffer); i++)
    {
	if(buffer[i] == '\n')
	{
		buffer[i]=0;
	}
    }
    
    //printf("%s", buffer);
    sprintf(str, "%s", buffer); 
    pclose(fp);
}

int get_bat(char *bat)
{
    char status[10];
    char life[5];
    memset(status, 0, 10);
    memset(life, 0, 5);
    
    get_bat_status(status);
    get_bat_life(life);
    sprintf(bat, "%s-%s", status, life);

    return 0;    
}
