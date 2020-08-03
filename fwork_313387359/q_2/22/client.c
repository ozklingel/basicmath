

    #include  <stdio.h>
    #include  <sys/types.h>
    #include  <signal.h>
    #include  <sys/ipc.h>
    #include  <sys/shm.h>

main(int argc, char *argv[]) { 

    
 int argv1 = atoi(argv[2]);
 int argv2 = atoi(argv[3]);

         int   pid=atoi(argv[1]);

         key_t MyKey;
         int   ShmID;
         pid_t *ShmPTR;
         char  line[100], c;
         int   i;

         MyKey   = ftok(".", 's');        
         ShmID   = shmget(MyKey, sizeof(pid_t), 0666);
         ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
         pid     = *ShmPTR;                
         shmdt(ShmPTR);                    

                              
            
              if (argv1==2) {  
  for (i = 0;i<argv2 ; i++) {  
                   kill(pid,SIGINT);
                   printf("Sent a SIGINT signal\n");
              }}
              else if (argv1==10) {
  for (i = 0;i<argv2 ; i++) {  
                   printf("About to send USER signal\n");
                   kill(pid,SIGUSR1);     


}
              }
          
    }


