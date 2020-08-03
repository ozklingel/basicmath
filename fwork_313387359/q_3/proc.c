#include <stdio.h>
#include <unistd.h>
#include <sched.h>
int
Set_policy(int pra,int pol)
{

  printf("Scheduler Policy for PID: %d  -> ", 0);
int policy;
  policy = sched_getscheduler(0);

  switch(policy) {
    case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
    case SCHED_RR:   printf("SCHED_RR\n"); break;
    case SCHED_FIFO:  printf("SCHED_FIFO\n"); break;
    default:   printf("Unknown...\n");
  }
struct sched_param sp = { .sched_priority = pra };
int ret;

ret = sched_setscheduler(0, SCHED_FIFO, &sp);
if (ret == -1) {
  perror("sched_setscheduler");
  return 1;}
return 0;
}

 int main(int argc, char *argv[]) { 

    
 int argv1 = atoi(argv[1]);
 int argv2 = atoi(argv[2]);
Set_policy(argv1,argv2);
return 1;}
