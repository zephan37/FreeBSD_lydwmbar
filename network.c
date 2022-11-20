#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//int main()
int get_net_status(char *str)
{
    FILE * fp;
    char buffer1[20]; 
    char buffer2[20];
    memset(buffer1, 0, 20);
    memset(buffer2, 0, 20);

    //this cmd get date
    //char* cmd = "echo $(date -R | sed \"s/ +0800//g\")";
    char *cmd1 = "echo $(ifconfig | grep \"status:\" | sed \"s/status: //g\" | sed -n \"1p\")";
    char *cmd2 = "echo $(ifconfig | grep \"status:\" | sed \"s/status: //g\" | sed -n \"2p\")";
    
    fp = popen(cmd1, "r");
    signal(SIGCHLD, SIG_IGN);
    fgets(buffer1, sizeof(buffer1), fp);
    for(int i = 0; i < sizeof(buffer1); i++)
    {
	if(buffer1[i] == '\n')
	{
		buffer1[i]=0;
	}
    }

    fp = popen(cmd2, "r");
    signal(SIGCHLD, SIG_IGN);
    fgets(buffer2, sizeof(buffer2), fp);
    for(int i = 0; i < sizeof(buffer2); i++)
    {
	if(buffer2[i] == '\n')
	{
		buffer2[i]=0;
	}
    }

   if(strcmp(buffer1, "associated") == 0)
   {
	sprintf(str, "%s", "online"); 
   }
   else if(strcmp(buffer2, "associated") == 0)
   {
	sprintf(str, "%s", "online");
   }
   else
	sprintf(str, "%s", "offline");

    pclose(fp);
}

