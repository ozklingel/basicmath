#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
pid_t pid = fork();
 if (pid==0){
	pid_t pid=fork();
 	if (pid==0){
				print("pros2");
	}
	else{
		print("pros1");
	}
 }
else{
print("perent");
}
return 0;
}



void print(char* text){
int i;
for (i=0;i<20;i++){
	printf("hello from%s\n",text);
	usleep(1000000);
}
}


