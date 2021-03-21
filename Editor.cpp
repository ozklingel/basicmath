#include "Editor.h"
Editor::~Editor(){
delete Doc;
}
void Editor::loop(){

    regex a("a");

    regex i("i");

    regex c("c");

    regex d("d");

    regex src(R"(/\w+/)");

    regex swc(R"(s/\w+/\w+/?)");

    regex Q("q");
    regex p("p");

    regex n("n");

    regex prAll("%p");

    regex changeLine(R"(\d)");
     regex forward2(R"(\+\d)");
     regex back1(R"(-\d)");
         regex j("j");
          regex w(R"(w\s.*)");

 regex lest(R"(\$)");
    while(true){
        string work;
        getline(cin,work);
        if(regex_match(work, swc)){
            //cout<<"swc"<<endl;
                    string first=work.substr(2);
            int find1 =first.find("/");
            string one= first.substr(0,find1);
            int find2=first.rfind("/");
            string two;
            if(find2==find1) {
                two= first.substr(find1+1);
                //cout<<"in4"<<endl;
            }else{
                //cout<<first<<endl;
                two= first.substr((find1+1),find2-find1-1);
            }
            Doc->s(one,two);
          //  Doc->Q();
        }
        else if(regex_match(work, p)){
           // cout<<"p"<<endl;
          //  Doc->Q();
          Doc->p();
        }
         else if(regex_match(work, n)){
           // cout<<"n"<<endl;
          //  Doc->Q();
          Doc->n();
        }
         else if(regex_match(work, prAll)){
          //  cout<<"prAll"<<endl;
          //  Doc->Q();
          Doc->pAll();
        }
         else if(regex_match(work, changeLine)){
           // cout<<"changeLine"<<endl;
          //  Doc->Q();
          Doc->changeLine(stoi(work));//stoi string to int
        }
         else if(regex_match(work, a)){
          //  cout<<"a"<<endl;
         //   Doc->Q();
         Doc->a();
        }
         else if(regex_match(work, i)){
           // cout<<"i"<<endl;
          //  Doc->Q();
          Doc->i();
        }
         else if(regex_match(work, c)){
           // cout<<"c"<<endl;
          //  Doc->Q();
          Doc->c();
        }
         else if(regex_match(work, d)){
         //  cout<<"d"<<endl;
         //   Doc->Q();
         Doc->d();
        }
         else if(regex_match(work, src)){

          
         //   Doc->Q();
         string src=work.substr(1);
         src=src.substr(0,src.size()-1);
        // cout<<src<<endl;
         Doc->search(src);
        }
         else if(regex_match(work,Q)){
         //   cout<<"Q"<<endl;
            Doc->Q();
        }
         else if(regex_match(work, forward2)){
            //cout<<"changeLine"<<endl;
            //Doc->Q();
         Doc->back1(-(stoi(work.substr(1))))
          ;//stoi string to int
        }
             else if(regex_match(work, back1)){
           // cout<<"changeLine"<<endl;
          //  Doc->Q();
          //char c=work[1];
          //char* ch2=&c;
         //  cout<<work[1]<<endl;
          Doc->back1(stoi(work.substr(1)));//stoi string to int
        }
           else if(regex_match(work, j)){
          //  cout<<"a"<<endl;
         //   Doc->Q();
         Doc->j();
        }
         else if(regex_match(work, w)){
           // cout<<"p"<<endl;
          //  Doc->Q();
          string src=work.substr(1);
           // cout<<src<<endl;
          Doc->w(src);
        }
        else if(regex_match(work, lest)){
           // cout<<"p"<<endl;
          //  Doc->Q();

           // cout<<src<<endl;
          Doc->end();
        }
    }
}
