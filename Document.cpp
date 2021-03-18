#include "Document.h"

#include <fstream>
 void Documents::end(){
       
        currentLine=(full.size()-1);
       // cout<<full.at(currentLine<<endl;
    }
  void Documents::w(string src){
  	
           //need lines and with empty lines;
               
    std::ofstream out(src);
    
    for(string st: full){
            out<<st<<endl;
        }

    out.close();
    }
 void Documents::j(){
        string work1=full.at(currentLine-1);
        string work2=full.at(currentLine);
        currentLine++;
        d();
        d();

        string temp=work1+work2;
        std::vector<string>::iterator it;
        it=full.begin()+(currentLine);
        full.insert(it,temp);
        currentLine++;
    }

   void Documents::forward2(){
        if(2+currentLine>full.size()){
            cout<<"?"<<endl;
            Q();
        }
       currentLine=(2+currentLine);

    }
    // -1 makes line #1 the current line
    void Documents::back1(int line){
        if(currentLine-line<1){
            cout<<"?"<<endl;
            Q();
        }
        currentLine=(currentLine-line);
        cout<<currentLine<<endl;
   }
// p prints the current line (ed maintains a current line)
    void Documents::p(){
        cout<<full.at(currentLine-1)<<endl;
    }
// n prints line number of current line followed by TAB followed by current line
    void Documents::n(){
        cout<<(currentLine+1)<<"\t"<<full.at(currentLine)<<endl;
    }
// %p prints all lines
    void Documents::pAll(){

        for(string st: full){
            cout<<st<<endl;
        }

    }

// 7 makes line #7 the current line
    void Documents::changeLine(int line){
    if(line==1&&full.size()==0){
            return;
        } 
        if(line>full.size()||line<=0){
            cout<<"?"<<endl;
            Q();
        } 
        currentLine=(line);
       // cout<<full.at(currentLine<<endl;
    }
// a appends new text after the current line
    void Documents::a(){
       if(currentLine==0){
           string temp;
           //need lines and with empty lines;
           getline(cin,temp);
           if(temp.compare(".")){
               full.push_back(temp);
               currentLine=1;
           }
       }
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it,temp);
            currentLine++;
          //  pAll();
        }
        
    }
// i inserts new text before the current line
    void Documents::i(){
        if(currentLine==0){
           string temp;
           //need lines and with empty lines;
           getline(cin,temp);
           if(temp.compare(".")){
               full.push_back(temp);
               currentLine++;
           }
       }
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine-1);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it++,temp);
            currentLine++;
        }
    }
// c changes the current line for text that follows
    void Documents::c(){
        d();
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it,temp);
            currentLine++;
        }

    }
// d deletes the current line
    void Documents::d(){
        //cout<<full.at(currentLine)<<" del"<<endl;
        full.erase((full.begin()+(currentLine-1)));
        if (currentLine!=0){
        currentLine--;}  
    }
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    void Documents::search(string find){

        for(int i =currentLine; i<full.size() ; i++)
        {
            if(full.at(i).find(find)!=string::npos){
                currentLine=i+1;
                                cout<<i<<endl;
                                break;
            }
        }
          for(int i =0; i<currentLine ; i++)
        {
            if(full.at(i).find(find)!=string::npos){
                currentLine=i+1;
                cout<<i+1<<endl;
            }
        }
        //cout<<full.at(currentLine)<<endl;
        
    }
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    void Documents::s(string s_old, string s_new){
        int check= full.at(currentLine-1).find(s_old);
        if(check!=-1){
            full.at(currentLine-1).replace(check,s_old.size(),s_new);
        }
        else{
            cout<<full.at(currentLine)<<endl;
            cout<<s_old<<endl;
            Q();
        }
    }
// Q
// Quits the editor without saving
    void Documents::Q(){
        exit(0);
    }
    

