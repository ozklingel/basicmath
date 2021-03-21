#include <iostream>
#include <string>
#include <vector>

#include <fstream>

using namespace std;

class Documents {

private:
    vector<string> full;
    int currentLine;




public:

    Documents(): currentLine{0}{
    full.clear();
    };
    Documents(char* a):
     currentLine{0}{
     full.clear();
    std::ifstream in(a);
    std::string str;
// Read the next line from File untill it reaches the end.
while (std::getline(in, str))
{
   
        full.push_back(str);
    
}
    
    };

 
    void changeLine(int line);
void forwardn(int line);
    void back1(int line);
    void j();
     void w(string src);
     void end();
// a appends new text after the current line
    void a();
// i inserts new text before the current line
    void i();
// c changes the current line for text that follows
    void c();
// d deletes the current line
    void d();
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    void search(string find);
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    void s(string sold, string snew);
// Q
// Quits the editor without saving
    void Q();
   void p();

    void n();

    void pAll();

};
