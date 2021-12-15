#include <bits/stdc++.h>
#define maxN 10005
using namespace std;

struct node{
    int idx;
    bool flag;
    vector<int> ch;
    map<int,int> mm;
}tree[maxN];

int cnt; // #node in tree

// initialization
void init(){
    for(int i=0; i<maxN; i++){
        tree[i].idx = 0;
        tree[i].flag = true;
        tree[i].mm.clear();
        tree[i].ch.clear();
    }
}

// add child
int addch(node &parent, int i){
    // if exists i-th child
    if(parent.mm[i]){
        return parent.mm[i]; // return postion in tree
    }
    // child not exists
    tree[++cnt].idx = i; // add one node in the tree
    parent.mm[i] = cnt; // remember child
    parent.ch.push_back(cnt); // add link
    return cnt; // return pos of child in the tree
}

int mark(node& parent, int i){
    // if exists i-th child
    if(parent.mm[i]){
        parent.flag = false;
        return parent.mm[i];
    }
    // child not exists
    tree[++cnt].idx = i;
    parent.flag = false;
    tree[cnt].flag = false;
    parent.ch.push_back(cnt);
    return cnt;
}

int bfs(int root){
    int ans = 0;
    for(int i=0; i<tree[root].ch.size(); i++){
        if(tree[tree[root].ch[i]].flag){
            ans++;
        }else{
            ans += bfs(tree[root].ch[i]);
        }
    }
    return ans;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d%d",&n,&m);
        init(); // initialization
        int n1, n2;
        // build tree
        for(int i=0; i<n; i++){
            n1 = 0;
            while(scanf("%d",&n2)==1 && n2!=-1){
                n1 = addch(tree[n1], n2);
            }
        }
        // mark node
        for(int i=0; i<m; i++){
            n1 = 0;
            while(scanf("%d",&n2)==1 && n2!=-1){
                n1 = mark(tree[n1], n2);
            }
        }
        // output result
        printf("%d\n", bfs(0));
    }
}