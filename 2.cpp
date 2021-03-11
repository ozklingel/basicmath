#include "Editor.h"
#include<stdlib.h>
#include "iostream"
int main(int argc,char** ardv) 
{
    switch(argc){
    case 1:
    	 Editor editor;
    	editor.loop();
    	break;
    }
    
    return 0;
}
