#include <bits/stdc++.h>
#define maxn 105
using namespace std;

struct edge{
    int nxt, dest;
}edges[maxn<<1];

int cnt, head[maxn];

void init_tree(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v){
    edges[cnt].dest = v;
    edges[cnt].nxt = head[u];
    head[u] = cnt++;
}

int lg[maxn];
void generate_log(){
    for(int i=1; i<maxn; i++){
        lg[i] = lg[i-1] + (1<<lg[i-1] == i);
    }
}

int dep[maxn], fa[maxn][30];
void dfs(int cur, int f){
    fa[cur][0] = f; dep[cur] = dep[f]+1;
    // update fa
    for(int i=1; i<=lg[dep[cur]]; i++){
        fa[cur][i] = fa[fa[cur][i-1]][i-1];
    }
    // bfs
    for(int i=head[cur]; ~i; i=edges[i].nxt){
        if(edges[i].dest != f){
            dfs(edges[i].dest, cur);
        }
    }
}
// lca
int lca(int x, int y){
    // 保证 dep[x]>dep[y]
    if(dep[x] < dep[y]){
        swap(x, y);
    }
    
    while(dep[x] > dep[y]){
        x = fa[x][lg[dep[x]-dep[y]]-1]; // -1?
    }
    
    if(x == y){
        return x;
    }
    // find ancestor
    for(int i=lg[dep[x]]-1; i>=0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i]; y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    generate_log();
    int T; scanf("%d",&T);
    while(T--){
        // idx of root, #node
        int root, n;
        scanf("%d%d",&root,&n);
        init_tree();
        for(int i=0; i<n-1; i++){
            int a, b; scanf("%d%d",&a,&b);
            add(a, b); add(b, a);
        }
        dfs(root, 0);
        int a, b, ret; 
        scanf("%d%d",&a,&b);
        ret = lca(a, b);
        printf("%d\n",ret);
    }
    return 0;
}