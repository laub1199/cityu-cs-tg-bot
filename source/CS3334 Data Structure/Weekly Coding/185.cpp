#include <iostream>
#include <string>
#include <set>

using namespace std;
int main() {

    string fileName;
    string word;
    set<string>s;
    char c;
    while (cin.get(c)){
        
            if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
                word.push_back(tolower(c));
            } else{
                s.insert(word);
                word="";
            }
        }
    set<string>::iterator it;
    it = s.begin();
    s.erase (it);
    for(it=s.begin(); it != s.end();it++){
        cout<<(*it);
        cout<<endl;
    }
    
    return 0;
}

