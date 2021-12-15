#include <bits/stdc++.h>
#define maxn 3001
using namespace std;

queue<int> b;
stack<int> s;
int a[maxn];

void init()
{
    while(!b.empty()){
        b.pop();
    }
    while(!s.empty()){
        s.pop();
    }
}

int main()
{
    int T; scanf("%d", &T);
    while(T--){
        // previous stack
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        // shuffling
        int m; scanf("%d", &m);
        for(int i=0; i<m; i++){
            // initialzation
            init();
            // input shuffling
            for(int i=0; i<n; i++){ 
                int num; scanf("%d", &num);
                b.push(num);
            }
            // simulation
            int ix = n-1;
            while(ix >= 0){
                int aa = a[ix], bb = b.front();
                if(aa == bb){
                    b.pop(); ix--;
                }else if(!s.empty() && s.top()==bb){
                    b.pop(); s.pop();
                }else{ 
                    s.push(aa); ix--;
                }
            }
            while(!b.empty() && !s.empty() && b.front()==s.top()){
                b.pop(); s.pop();
            }
            // output
            (b.empty()&&s.empty()) ? printf("Aye\n") : printf("Impossible\n");
        }
    }
    return 0;
}