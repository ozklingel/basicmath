#define _GNU_SOURCE  
#include <linux/sched.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

char childstack[10000+1];




void print(char* text){
int i;
for (i=0;i<1000;i++){
	printf("hello from%s\n",text);
	usleep(1000000);
}
}


int child(void* param){
print("child");

}


int main(){
//int =clone(child,childstack+1000,0,0);
//CLONE_PARENT
int resulte1=clone(child,childstack+10000,CLONE_PARENT,0);
int resulte2=clone(child,childstack+10000,CLONE_PARENT,0);

printf("clone result %d\n",resulte1);
printf("clone result %d\n",resulte2);
print("parent");
return 0;
}
