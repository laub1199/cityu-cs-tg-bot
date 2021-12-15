#include <bits/stdc++.h>
#define SIZE 10000005
using namespace std;

int myHash[SIZE];

int read(){
    int ret = 0 ;
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
    int ans = 0;
    memset(myHash, 0, sizeof(myHash));
    for(int i=0; i<n; i++){
        int x = read();
        if(x < SIZE) myHash[x]++;
        
        if(x == ans){
            while(myHash[ans]){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}