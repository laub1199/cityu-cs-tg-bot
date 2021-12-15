#include <bits/stdc++.h>
using namespace std;
// '(' -> -1  
stack<int> s;
queue<int> q;

int main()
{
    string str;
    while(cin>>str){
        int len = str.size();
        for(int i=0; i<len; i++){
            if(str[i] == '('){
                s.push(-1);
            }else{
                int newNode = 1;
                while(s.top() != -1){
                    int sub = s.top(); s.pop();
                    newNode += sub;
                }s.pop();
                q.push(newNode);
                s.push(newNode);
            }
        }
        int ans = q.front(); q.pop();
        while(!q.empty()){
            int ele = q.front(); q.pop();
            ans ^= ele;
        }printf("%d\n", ans);
    }
    return 0;
}