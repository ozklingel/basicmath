#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
pid_t pid = fork();
 if (pid==0){
	chdir("/");

setsid();
 
printf("stert deamon");
close(stdout);
close(stdin);
close(stderr);

openlog("mydamon",LOG_PID,LOG_DAEMON);
syslog(LOG_NOTICE,"daemon st");
usleep(300000);
syslog(LOG_NOTICE,"daemon work");
usleep(300000);
syslog(LOG_NOTICE,"daemon finition");
}
else{
printf("demon PID %d",pid);
}
return 0;
}


