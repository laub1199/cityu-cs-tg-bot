#include <bits/stdc++.h>
using namespace std;
// [32, 126]
// () 40 41 
// {} 123 125
// [] 91 93

stack<char> stk;

bool match(char c)
{
    if(stk.empty()){
        return false;
    }
    switch(c){
        case '}':
            return stk.top() == '{';
        case ')':
            return stk.top() == '(';
        case ']':
            return stk.top() == '[';
    }
    return false;
}

int main()
{
    string str;
    while(getline(cin, str)){
        // clear
        while(!stk.empty()) stk.pop();
        // stack
        int first;
        bool done = false;
        for(int i=0; i<str.size(); i++){
            if(done) break;
            char c = str[i];
            switch(c){
                case '{': case '(': case '[':
                    if(stk.empty()){
                        first = i;
                    }
                    stk.push(c); break;
                case '}': case ')': case']':
                    if(match(c)){
                        stk.pop();
                    }
                    else{
                        printf("%d\n", i+1);
                        done = true;
                    }break;
                default: break;
            }
        }
        if(!done){
            stk.empty() ? printf("Success\n") : printf("%d\n", first+1);  
        }
    }
    return 0;
}