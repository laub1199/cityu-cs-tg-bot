#include <bits/stdc++.h>
#define MAX 5000000
#define SIZE 1030
using namespace std;

struct node{
    int val;
    node(){}
    node(int a){
        val = a;
    }
}tree[MAX];

bool M[SIZE][SIZE];

int leaf[SIZE][SIZE];

inline bool isValid(int r, int c){
    bool x = M[r][c];
    return x==M[r+1][c]&&x==M[r][c+1]&&x==M[r+1][c+1];
} 

inline bool isPure(int i){
    int nw, ne, sw, se;
    nw = tree[4*i+1].val;
    ne = tree[4*i+2].val;
    sw = tree[4*i+3].val;
    se = tree[4*i+4].val;
    return nw!=-1&&ne==nw&&sw==nw&&se==nw;
}

int solve(int r, int c, int size, int &cnt, int idx){
    if(size == 1){
        leaf[r][c] = idx;
        tree[idx] = node(M[r][c]);
        return M[r][c];
    }
    // divide and conquer
    int nw, ne, sw, se;
    nw = solve(r, c, size/2, cnt, 4*idx+1);
    ne = solve(r, c+size/2, size/2, cnt, 4*idx+2);
    sw = solve(r+size/2, c, size/2, cnt, 4*idx+3);
    se = solve(r+size/2, c+size/2, size/2, cnt, 4*idx+4);
    if(nw!=-1 & ne==nw & sw==nw && se==nw){ // is valid
        tree[idx] = node(nw);
        return nw;
    }else{
        cnt += 4;
        tree[idx] = node(-1);
        return -1;
    }
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int k; scanf("%d", &k);
        // input matrix
        k = 1<<k; 
        for(int i=0; i<k; i++){
            string str; cin>>str;
            for(int j=0; j<k; j++){
                M[i][j] = (str[j]=='1');
            }
        }
        if(!k){
            int m; cin>>m;
            for(int i=0; i<m; i++){
                printf("1\n");
            }
        }else{
            // build quadtree
            int cnt = 1;
            solve(0, 0, k, cnt, 0); 
            // operation
            int m; cin>>m;
            for(int i=0; i<m; i++){
                int r, c; scanf("%d%d", &r, &c);
                int iidx = leaf[r-1][c-1];
                tree[iidx].val ^= 1;
                if(tree[(iidx-1)/4].val == -1){ // not valid
                    while(iidx>0 && isPure((iidx-1)/4)){
                        tree[(iidx-1)/4].val = tree[iidx].val;
                        cnt -= 4;
                        iidx = (iidx-1)/4; 
                    }
                }else{ // valid
                    while(iidx>0 && tree[(iidx-1)/4].val!=-1 && !isPure((iidx-1)/4)){
                        tree[(iidx-1)/4].val = -1;
                        cnt += 4;
                        iidx = (iidx-1)/4; 
                    }
                }printf("%d\n", cnt);
            }
        }
    }
    return 0;
}