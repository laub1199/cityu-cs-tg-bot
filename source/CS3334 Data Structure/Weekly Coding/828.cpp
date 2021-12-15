#include <bits/stdc++.h>
#define maxN 10000005
using namespace std;
typedef long long ll;

int top,n,m,seed,a1[maxN],a2[maxN];
queue<ll> q;

void init(){
    top = 0;
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    while(!q.empty()) q.pop();
}

void generate_array(int* a, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 1; i <= n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

void bucketSort(){
    // count {a[1], a[2], ... , a[n]}
    for(int i=1; i<=n; i++){
        a2[a1[i]]++;
    }
    // sort [1, m]
    int idx = 0;
    for(int i=1; i<=m; i++){
        while(a2[i]--){
            a1[idx++] = i; 
        }
    }
}

inline ll pop(){
    ll ret;
    if(q.empty()){
        return a1[top++];
    }
    ll x = q.front();
    if(top==n || x<a1[top]){
        q.pop();
        return x;
    }
    return a1[top++];
}

int main(){
    while(scanf("%d%d%d",&n,&m,&seed)==3){
        // initialization
        init();
        // generate array
        generate_array(a1, n, m, seed);
        // bucketSort
        bucketSort();
        // simulation
        ll x, y;
        for(int i=1; i<n; i++){
            x = pop(); 
            y = pop();
            q.push(max(x<<1,y));
        }printf("%lld\n", q.front());
    }
    return 0;
}