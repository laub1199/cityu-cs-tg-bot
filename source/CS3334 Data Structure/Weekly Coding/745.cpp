#include <bits/stdc++.h>
#define maxn 20005
using namespace std;

int dp[maxn];

int main()
{
    int T; scanf("%d", &T);
    while(T--){
        // initialization
        memset(dp, 0, sizeof(dp));
        // input initial pile
        int mmax = 0;
        int n; scanf("%d", &n);
        for(int i=1; i<=n; i++){
            int num; scanf("%d", &num);
            if(num > mmax){
                mmax = num;
            }dp[i] = mmax;
        }
        // operation
        int m; cin>>m;
        for(int i=0; i<m; i++){
            char opt; cin>>opt;
            switch(opt){
                case 'm':
                    printf("%d\n", dp[n]);
                    break;
                case 'r':
                    n--;
                    break;
                case 'a':
                    int val; scanf("%d", &val);
                    mmax = dp[n];
                    dp[++n] = max(val, mmax);
                    break;
            }
        }
    }
    return 0;
}