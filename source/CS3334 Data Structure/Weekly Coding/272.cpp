#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;

struct node{
    ll x, y;
    node(){}
    node(ll a, ll b):x(a),y(b){}
    
    node operator-(node n){
        return {x-n.x, y-n.y};
    }
}nodes[maxn],stk[maxn];

int top;

bool cmp(node a, node b){
    return a.x<b.x || a.x==b.x&&a.y<b.y;
}

ll det(node a, node b, node c){
    return (b-a).x*(c-b).y - (b-a).y*(c-b).x;
}

void andrew(int n){
    top = 0;

    for(int i=0; i<n; i++){

        while(top>=2 && det(stk[top-2],stk[top-1],nodes[i])<0){
            top--; // pop
        }
        stk[top++] = nodes[i]; // push
    }

    int tmp = top;
    for(int i=n-2; i>=0; i--){
        while(top>tmp && det(stk[top-2],stk[top-1],nodes[i])<0){
            top--;
        }
        stk[top++] = nodes[i];
    }
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        // handle the node set
        int n; scanf("%d",&n);
        for(int i=0; i<n; i++){
            ll x, y; scanf("%lld%lld",&x,&y);
            nodes[i] = node(x, y);
        }
        // sorting
        sort(nodes, nodes+n, cmp);
        // andrew
        andrew(n);
        // output
        printf("%d\n", --top);
        for(int i=0; i<top; i++){
            printf("%lld %lld\n",stk[i].x,stk[i].y);
        }
    }
    return 0;
}