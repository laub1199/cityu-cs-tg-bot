#include<iostream>
#include<stack>
using namespace std;

bool isDigit(char c);

int main()
{
    string input;
    while(getline(cin, input))
    {
        //cout<<input<<endl;
        stack<int> stk;
        for(char c : input)
        {
            //if(c == ' ') continue;
            if(isDigit(c)) stk.push(c-48);
            if(c=='+' || c=='-' || c=='*')
            {
                int opd2 = stk.top();
                stk.pop();
                int opd1 = stk.top();
                stk.pop();
                switch(c)
                {
                    case '+': stk.push(opd1+opd2); break;
                    case '-': stk.push(opd1-opd2); break;
                    case '*': stk.push(opd1*opd2); break;
                }
            }
            //cout<<stk.top()<<endl;
        }
        cout<<stk.top()<<endl;
    }
    return 0;
}

//
bool isDigit(char c)
{
    return (48<=c && c<=57);
}