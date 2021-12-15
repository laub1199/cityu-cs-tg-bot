#include <bits/stdc++.h>
#define mod 10
#define maxn 1005
using namespace std;

int f[maxn];

int fib(int n)
{
    if(f[n]){
        return f[n];
    }else if(n<=1){
        return f[n]=n;
    }else{
        return f[n]=(fib(n-1)+fib(n-2))%mod;
    }
}

int main()
{
    int n;
    memset(f, 0, sizeof(f));
    while(scanf("%d", &n) == 1){
        printf("%d\n", fib(n));
    }
    return 0;
}