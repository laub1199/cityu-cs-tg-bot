#include<bits/stdc++.h>
#define maxN 100010
using namespace std;
typedef long long ll;

stack<ll> stk;
ll arr[maxN];

int main()
{
    ll T, N;
    scanf("%lld", &T);
    while(T--)
    {
        // handle the input
        scanf("%lld", &N);
        ll i;
        for(i=0; i<N; i++)
        {
            scanf("%lld", &arr[i]);
        }arr[i] = 0;
        // ascending stack
        ll res = 0;
        while(!stk.empty()) stk.pop(); // initialization
        for(ll i=0; i<=N; i++)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])
            {
                ll val = stk.top(); stk.pop();
                res = max(res, arr[val]*(stk.empty() ? i : (i-stk.top()-1)));
            }
            stk.push(i);
        }
        printf("%lld\n", res);
    }
    return 0;
}