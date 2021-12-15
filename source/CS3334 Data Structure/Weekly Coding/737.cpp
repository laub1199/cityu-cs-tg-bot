#include <bits/stdc++.h>
using namespace std;

set<string> strs;
map<string, int> mm;

int main()
{
    string str;
    while(cin>>str)
    {
        mm[str]++;
        strs.insert(str);
    }
    set<string>::iterator it;
    for(it=strs.begin(); it!=strs.end(); it++)
    {
        cout<<*it<<' '<<mm[*it]<<endl;
    }
}