#include <bits/stdc++.h>
using namespace std;

set<string> ss;

int main()
{
    string str;
    // input
    while(cin >> str){
        string ret;
        for(char ch : str)
        {
            if('a'<=ch && ch<='z'){
                ret += ch;
            }else if('A'<=ch && ch<='Z'){
                ch += 32;
                ret += ch;
            }else if(ret.size() > 0){
                ss.insert(ret);
                ret = "";
            }
        }
        if(ret.size() > 0){
            ss.insert(ret);
        }
    }
    // output
    for(auto it=ss.begin(); it!=ss.end(); ++it){
        cout<<*it<<endl;
    }
    return 0;
}