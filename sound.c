#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//int main()
void get_sound(char *str)
{
    FILE * fp;
    char buffer[5];
    
    //this cmd get sound
    char* cmd = "echo $(pamixer --get-volume)";

    fp = popen(cmd, "r");
    signal(SIGCHLD, SIG_IGN);
    fgets(buffer, sizeof(buffer), fp);
   
    for(int i = 0; i < sizeof(buffer); i++)
    {
        if(buffer[i] == '\n')
        {
                buffer[i]=0;
        }
    }

    //printf("%s%%%", buffer);
    sprintf(str, "%s%%%", buffer); 
    pclose(fp);
}
