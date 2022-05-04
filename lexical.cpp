#include <iostream>
#include <string.h> 
#include <string>

using namespace std;

int main()
{
    string bemenet= "";
    string kimenet="";

    std::cout << "\nKérem adja meg a bemeneti szöveget(például: ldsp{}()*:=<>p$): \n";

    getline(cin, bemenet);
    int length =bemenet.length();

   for (int i=0; i < length; ++i) {
      
       if (isdigit(bemenet[i])) {
           while (isdigit(bemenet[i])) {
               ++i;
           }
           kimenet += "<számjegy>";
       }
       if (isalpha(bemenet[i])) {
           while (isalpha(bemenet[i]) || isdigit(bemenet[i])) {
               ++i;
           }
           kimenet += "<betű>";
       }
       if (bemenet[i]==':' && bemenet[i+1] == '=') {
           i=i+2;
           kimenet += "<értékadás>";
       }
       if (bemenet[i] == '{') {
           for (int j=i; j < length; ++j) {
               if (bemenet[j] == '}') {
                   i = j;
                   kimenet += "<{}komment>";
                   break;
               }
           }
       }
       if (bemenet[i] == '(' && bemenet[i+1]=='*') {
           for (int j = i+2; j < length; ++j) {
               if (bemenet[j] == '*' && bemenet[j+1]==')') {
                   i = j+1;
                   kimenet += "<(**)komment>";
                   break;
               }
           }
        }
       if (bemenet[i] == '<' && bemenet[i + 1] == '>') {
           kimenet += "<nemegyenlõ>";
       }
       if (bemenet[i] == '<' && bemenet[i + 1] == '=') {
           kimenet += "<kisebbegyenlõ>";
       }
       if (bemenet[i] == '>' && bemenet[i + 1] == '=') {
           kimenet += "<nagyobbegyenlõ>";
       }
       if (bemenet[i] == '$') {
           kimenet += "<Vége>";
           break; 
       }
   }
   cout <<"Kimenet:\n"<< kimenet << "\n";
}
