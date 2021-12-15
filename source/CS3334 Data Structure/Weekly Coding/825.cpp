#include <bits/stdc++.h>
#define maxn 100005
#define day 86400
using namespace std;

int ret;
int myHash[maxn];

int read(){
    int ret = 0;
    char ch = getchar();
    while(ch<'0' || ch>'9'){
        ch = getchar();
    }
    while('0'<=ch && ch<='9'){
        ret = ret*10 + ch - '0';
        ch = getchar();
    }
    return ret;
}

int main(){
    int n = read();
    queue<int> q;
    ret = 0;
    for(int i=0; i<n; i++){
        int t = read();
        int k = read();
        while(!q.empty() && t - q.front()>=86400){
            int a = q.front(); q.pop();
            int b = q.front(); q.pop();
            for(int j=0; j<b; j++){
                int c = q.front();
                myHash[c]--; 
                if(!myHash[c]){
                    ret--;
                }
                q.pop();
            }
        }
        q.push(t);
        q.push(k);
        for(int j=0; j<k; j++){
            int x = read();
            if(!myHash[x]){
                ret++;
            }
            myHash[x]++;
            q.push(x);
        }
        // output
        printf("%d\n",ret);
    }
    return 0;
}