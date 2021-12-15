#include <bits/stdc++.h>
#define maxN 2005
using namespace std;

bool isStop[maxN];

int n, m, stop[maxN], dep[maxN], ch[maxN][maxN];

int dfs(int x){
    if(dep[x]){
        return dep[x];
    }
    // for real node
    if(x <= n){
        for(int i=1; i<=ch[x][0]; i++){
            dep[x] = max(dep[x], dfs(ch[x][i]));
        }
    }else{
        for(int i=1; i<=ch[x][0]; i++){
            dep[x] = max(dep[x], dfs(ch[x][i])+1);
        }
    }
    return ch[x][0]==0 ? dep[x]=1 : dep[x];
}


int main(){
    /*
    n -> #station
    m -> #modification
    */ 
    while(scanf("%d%d", &n, &m) == 2){
        // create a dummy node for every i
        for(int i=1; i<=m; i++){
            // #stop station
            scanf("%d", &stop[0]);
            // input stop station
            memset(isStop, 0, sizeof(isStop));
            for(int j=1; j<=stop[0]; j++){
                scanf("%d", &stop[j]);
                isStop[stop[j]] = true;
                ch[i+n][++ch[i+n][0]] = stop[j]; // set child
            }
            // traverse
            for(int j=stop[1]; j<=stop[stop[0]]; j++){
                if(!isStop[j]){
                    ch[j][++ch[j][0]] = i+n;
                }
            }
        }
        // dfs
        int ret = 0;
        memset(dep, 0, sizeof(dep));
        for(int i=1; i<=n; i++){
            ret = max(ret, dfs(i));
        }
        printf("%d\n", ret);
    }
    return 0;
}