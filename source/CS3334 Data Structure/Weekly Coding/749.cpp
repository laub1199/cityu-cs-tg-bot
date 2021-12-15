#include <bits/stdc++.h>
#define maxn 105
using namespace std;

// preOrder array, inOrder array
int preOrder[maxn], inOrder[maxn], postOrder[maxn];
// idx for preOrder array
int idx;
// cnt for postOrder array
int cnt;

void solve(int left, int right){
    // base case ?
    if(left > right){
        idx--;
        return;
    }
    // find idx of root
    int root = preOrder[idx];

    int i;
    for(i=left; i<=right; i++){
        if(inOrder[i] == root){
            break;
        }
    }
    // divide and conquer
    idx++; solve(left, i-1);
    idx++; solve(i+1, right);
    postOrder[cnt++] = root;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N; scanf("%d",&N);
        // input preOrder
        for(int i=0; i<N; i++){
            scanf("%d",&preOrder[i]);
        }
        // input inOrder
        for(int i=0; i<N; i++){
            scanf("%d",&inOrder[i]);
        }
        // solve
        idx = cnt = 0;
        solve(0, N-1);
        // output result
        for(int i=0; i<cnt; i++){
            if(i == 0){
                printf("%d",postOrder[i]);
            }else{
                printf(" %d",postOrder[i]);
            }
        }
        printf("\n");
    }
    return 0;
}