#include <bits/stdc++.h>
#define SIZE 1030
using namespace std;

bool M[SIZE][SIZE];

inline bool isValid(int r, int c){
    bool x = M[r][c];
    return x==M[r+1][c]&&x==M[r][c+1]&&x==M[r+1][c+1];
} 

int solve(int r, int c, int size, int &cnt){
    if(size == 1){
        return M[r][c];
    }
    if(size == 2){ // leaves
        if(isValid(r, c)){
            return M[r][c]; // return binary value
        }else{
            cnt += 4; 
            return -1; // not valid
        }
    }
    int nw, ne, sw, se;
    nw = solve(r, c, size/2, cnt);
    ne = solve(r, c+size/2, size/2, cnt);
    sw = solve(r+size/2, c, size/2, cnt);
    se = solve(r+size/2, c+size/2, size/2, cnt);
    if(nw!=-1 & ne==nw & sw==nw & se==nw){
        return nw;
    }else{
        cnt += 4;
        return -1;
    }
}

int main(){
    int k;
    while(scanf("%d", &k) == 1){
        // input matrix
        k = 1<<k; 
        for(int i=0; i<k; i++){
            string str; cin>>str;
            for(int j=0; j<k; j++){
                M[i][j] = (str[j]=='1');
            }
        }
        // solve
        int cnt = 1;
        solve(0, 0, k, cnt);
        printf("%d\n", cnt);
    }
    return 0;
}