#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "hello_ariel.h"



bool init_library()
{
void * hdl = dlopen("./libHello.so", RTLD_LAZY);
if(hdl==NULL){
printf("f1");
	return false;
}

return true;
}

int main()
{
if (init_library())
  myPrintHelloMake();
else
	printf("faild");
return 0;
}
