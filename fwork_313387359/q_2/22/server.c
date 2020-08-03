#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdlib.h>
void  SIGINT_handler(int);   
void  SIGUSR1_handler(int); 
int count=0;
int   ShmID;      
pid_t *ShmPTR;    

void main(void)
{
     int   i;
     pid_t pid = getpid();
     key_t MyKey;

     if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("SIGINT install error\n");
          exit(1);
     }
	else{count++;}
     if (signal(SIGUSR1,SIGUSR1_handler) == SIG_ERR) {
          printf("SIGUSR1 install error\n");
          exit(2);
     }

     MyKey   = ftok(".", 's');    
     ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     *ShmPTR = pid;               

     for (i = 0; ; i++) {        

          sleep(10);
     }
}
void  counter()
{
count++;}

void  SIGINT_handler(int sig)
{



    counter();
}

void SIGUSR1_handler(int sig)
{

     printf("%d\n", count);
     shmdt(ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);


}
