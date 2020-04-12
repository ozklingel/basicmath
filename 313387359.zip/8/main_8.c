#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#define _GNU_SOURCE  
#include <linux/sched.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

char childstack1[10000+1];
char childstack2[10000+1];
char childstack3[10000+1];
int main1() 
{ 
        //A null terminated array of character  
        //pointers 
        char *args[]={"./aa.out",NULL}; 
        execvp(args[0],args); 
      
    return 0; 
}
int main2() 
{ 
       char *args1[]={"./a1.out",NULL}; 
        execvp(args1[0],args1); 
      
    return 0; 
}
       
int main3() 
{ 
       char *args1[]={"./aaa.out",NULL}; 
        execvp(args1[0],args1); 
      
    return 0; 
}


int main()
{ 
int resulte1=clone(main2,childstack1+10000,CLONE_PARENT,0);
int resulte2=clone(main1,childstack2+10000,CLONE_PARENT,0);
int resulte3=clone(main3,childstack3+10000,CLONE_PARENT,0);
        printf("Ending-----"); 
      
    return 0; 
} 
