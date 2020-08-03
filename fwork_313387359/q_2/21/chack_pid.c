#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

int check_pid(const int pid){

int rc;
rc = kill(pid, 0);


if (rc != 0)
{
    switch(errno)
    {


        case EPERM:
            printf("‫‪Process‬‬ ‫>‪%d‫​‬ ‫‪exists‬‬ ‫‪but‬‬ ‫‪we‬‬ ‫‪have‬‬ ‫‪no‬‬ ‫‪permission.‬‬\n",pid);
            break;

        case ESRCH:
            printf("‫‪Process‬‬ ‫>‪%d ‫‪does‬‬ ‫‪not‬‬ ‫‪exist.‬‬\n",pid);
            break;
    }

}
     else{      printf("‫‪Process‬‬ ‫%d‬‬ ‫‪exists\n‬‬",pid);}
}

main(int argc, char *argv[]) { 
 int arg1 = atoi(argv[1]);
check_pid(arg1);
 }
