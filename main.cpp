#include "Editor.h"
#include<stdlib.h>

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy
int main(int argc,char* ardv[]) 
{
    switch(argc){
    case 1:
    {
    	 Editor editor;
    	editor.loop();
    	break;
    	}
    case 2:
    {
    	Editor editor2(ardv[1]);
    	editor2.loop();
    	break;
    	}
    }
    
    return 0;
}



