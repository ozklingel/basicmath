
#include<stdlib.h>              //standard lib
#include<string.h>              //string operation lib
#include<ctype.h>
#include <algorithm>
#include "parser.h"
#include <iostream>
#include <iostream>
#include <vector>
vector<char*> stack;
vector<char*> accepted;
int idt=0;
char buff[30];
void E1();
void E2();
void R();
void T();
void T2();
void S();
void F();
void D();
char lex();
using namespace std;
string unconsumed_input();
    bool error = false;
char next_token = '%';
string lexy = "";
char ch;

void Parser::parse(){
    if(!inputFile.is_open()){                                       //Display error message if file cannot be opened
		cout<<"\nError while opening the file";
		exit(0);
	}
    
    if(!inputFile.eof()){                                        //While End of File is not reached


int j=0;
next_token=inputFile.get();
accepted.push_back("|");
stack.push_back("E1");


for (auto it :accepted) {
        std::cout << it << ' ';
    }
  for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
	E1();
	cout<<next_token<<endl;
	if(next_token != ')')
	{
		printf("success\n");
	}
	else 
	{
		cout<<"syntax error1"<<endl;
	} 
}
}




void Parser::E1()
{
stack.pop_back();
stack.push_back("E2");
stack.push_back("T");//T E2 |

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";

	//printf("E1->T E2\n");
	T();
	E2();
	

}
void Parser::E2()
{
	if(error) return;
	//printf("token %c\n", next_token);
	if(next_token == '+')
	{


stack.pop_back();
stack.push_back("E2");
stack.push_back("T");
stack.push_back("+");//+ T E2 |


for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
	
//	printf("E2 -> + T E2\n");
stack.pop_back();
 accepted.pop_back();
 accepted.push_back("+");// id|...
 accepted.push_back("|");

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
next_token=inputFile.get();
		T();
		E2();
		
	}
	else  
	{
	if(!stack.empty()){
	stack.pop_back();

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
  //    printf("E2->e\n");
    }
    }
    
}



void Parser::T()
{
stack.pop_back();
stack.push_back("T2");
stack.push_back("F");// F T2 E2 |

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
	if (error) return;
//	printf("T -> F T2\n");
	F();
	T2();

}

void Parser::T2()
{
	if (error) return;
	
	stack.pop_back();

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
	if (next_token=='*') 
	{


stack.pop_back();
stack.push_back("T2");
stack.push_back("F");
stack.push_back("*");// F T2 E2 |

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
  //  	printf("T2 -> * F T2\n");
    stack.pop_back();
 accepted.pop_back();
 accepted.push_back("*");// id|...
 accepted.push_back("|");

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
next_token=inputFile.get();
      	F();
       T2();   
   }
if (next_token==' ') {
		cout<<"syntax error"<<endl;
		exit(1);
}
  
  else 
	{


stack.pop_back();

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";

    //  printf("T2 -> e\n");
   	}

}

void Parser::F()
{
	
	if (error) return;
 	if (next_token=='(' )  
	{
stack.pop_back();
stack.push_back(")");
stack.push_back("E1");
stack.push_back("(");// F T2 E2 |

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
      // 	printf("F->( E1 )\n");
 stack.pop_back();
 accepted.pop_back();
 accepted.push_back("(");// (|...
 accepted.push_back("|");
next_token=inputFile.get();

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";
       	E1();
   		if (next_token == ')'  )
		{
accepted.pop_back();
accepted.push_back(")");// )|...
accepted.push_back("|");
next_token=inputFile.get();
        }
		else 
		{  
			error=true; 
            printf("error: unexptected token %c\n", next_token);      
            cout<<"unconsumed_input 1 = "<<unconsumed_input(); 
           	return;
       } 
	}
	else {
	  stack.pop_back();
	stack.push_back("_id");

for (auto it :accepted) {
        std::cout << it << ' ';
    }
 for (auto it = stack.crbegin(); it != stack.crend(); it++) {
        std::cout << *it << ' ';
    }
cout<<"\n ";

  accepted.pop_back();
accepted.push_back("_id");// id|...
accepted.push_back("|");
     // 	printf("F->%s\n", "id");

next_token=inputFile.get();
next_token=inputFile.get();
       return;	
       }
///////////////////////////////////////////////////////////////////////////////////////    
    //else 
	//{
          //error=true; 
         // printf("error: unexptected token %c\n", next_token);
         // cout<<"unconsumed_input 2 = "<<unconsumed_input();   
   // }
}

char Parser::lex()
{
	char ch;
	
		inputFile.get(ch);
		if(ch == ' ' || ch == '\n' || ch == '+' || ch == '*' || ch == '(')
		{
		
			
		}
		next_token = ch;
		return next_token;
	
} 

string Parser::unconsumed_input()
{
	if(!(inputFile.eof()))
	{
		char ch;

    	while(inputFile)
    	{
			inputFile.get(ch);
			if (inputFile.eof())
          	 	 break;
			lexy +=ch;
	
		}
	}
	return lexy;
}



 ///////////////
//int j=0;
//ch = inputFile.get();
//buff[j++] = ch;
  //        while(isalnum(ch)){ 
                                     
    //        buff[j++] = ch;
      //      ch = inputFile.get();
       // }
        //buff[j] = '\0';
        
  /////////////////  
