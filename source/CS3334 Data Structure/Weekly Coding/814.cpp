#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

class Node{
    public:
    int val; // instance field
    Node *right, *down;
    
    Node(){ // constructor
        val = 0;
        right = NULL;
        down = NULL;
    }
    Node(int x){
        val = x;
        right = NULL;
        down = NULL;
    }
}matrix[maxn][maxn], *entrance;

void traverse(int n, int m){
    Node *ptr = entrance->down;
    for(int i=1; i<=n; i++){
        Node *tmp = ptr->right;
        for(int j=1; j<=m; j++){
            if(j == 1){
                printf("%d", tmp->val);
            }else{
                printf(" %d", tmp->val);
            }
            if(tmp->right != NULL){
                tmp = tmp->right;
            }
        }printf("\n");
        if(ptr->down != NULL){
            ptr = ptr->down;
        }
    }
}

Node* find(int r, int c){
    Node *ret = entrance;
    for(int i=0; i<r; i++){
        ret = ret->down;
    }
    for(int i=0; i<c; i++){
        ret = ret->right;
    }
    return ret;
}

void check(Node* n){
    printf("%d\n", n->val);
}

int main(){
    int n, m, q;
    entrance = &matrix[0][0];
    while(scanf("%d%d%d", &n, &m, &q) == 3){
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=m+1; j++){
                if(i>=1 && i<=n && j>=1 && j<=n){
                    int v; scanf("%d", &v);
                    matrix[i][j] = Node(v);
                }else{
                    matrix[i][j] = Node();
                }
                if(j >= 1){
                    matrix[i][j-1].right = &matrix[i][j];   
                }
                if(i >= 1){
                    matrix[i-1][j].down = &matrix[i][j];
                }
            }
        }
        for(int i=0; i<q; i++){
            int r1, c1, r2, c2, h, w;
            scanf("%d%d%d%d%d%d", &r1, &c1, &r2, &c2, &h, &w);
            Node *n1, *n2, *tmpr1, *tmpd1, *tmpr2, *tmpd2;
            n1 = find(r1-1, c1-1), n2 = find(r2-1, c2-1);
            tmpr1 = tmpd1 = n1; tmpr2 = tmpd2 = n2;
            // up
            for(int i=0; i<w; i++){
                tmpr1 = tmpr1->right; tmpr2 = tmpr2->right;
                Node *temp = tmpr1->down;
                tmpr1->down = tmpr2->down;
                tmpr2->down = temp;
            }
            // right
            for(int i=0; i<h; i++){
                tmpr1 = tmpr1->down; tmpr2 = tmpr2->down;
                Node *temp = tmpr1->right;
                tmpr1->right = tmpr2->right;
                tmpr2->right = temp;
            }
            // left
            for(int i=0; i<h; i++){
                tmpd1 = tmpd1->down; tmpd2 = tmpd2->down;
                Node *temp = tmpd1->right;
                tmpd1->right = tmpd2->right;
                tmpd2->right = temp;
            }
            // down
            for(int i=0; i<w; i++){
                tmpd1 = tmpd1->right; tmpd2 = tmpd2->right;
                Node *temp = tmpd1->down;
                tmpd1->down = tmpd2->down;
                tmpd2->down = temp;
            }
        }
        traverse(n, m);
    }
    return 0;
}