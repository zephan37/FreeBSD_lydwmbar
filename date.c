#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//int main()
int get_date(char *str)
{
    FILE * fp;
    char buffer[40];
    memset(buffer, 0, 40);

    //this cmd get date
    char* cmd = "echo $(date -R | sed \"s/ +0800//g\")";

    fp = popen(cmd, "r");
    signal(SIGCHLD, SIG_IGN); 

    fgets(buffer,sizeof(buffer),fp);

    for(int i = 0; i < sizeof(buffer); i++)
    {
	if(buffer[i] == '\n')
	{
		buffer[i]=0;
	}
	
	if(buffer[i] == ',')
	{
		buffer[i]=' ';
	}
    }

    //printf("%s\n", buffer);
    sprintf(str, "%s", buffer); 
    pclose(fp);
}

