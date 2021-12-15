#include <bits/stdc++.h>
#define maxn 100
#define maxm 10
using namespace std;

char t1[maxn][maxm], t2[maxn][maxm];
int r, c, r1[maxn], r2[maxn];

inline void reset()
{
    for(int i=0; i<r; i++){
        r2[i] = r1[i];
        for(int j=0; j<c; j++){
            t2[i][j] = t1[i][j];
        }
    }
}

inline void display()
{
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<t2[i][j];
        }cout<<endl;
    }
}

inline void flip_column(int idx)
{
    for(int i=0; i<r; i++){
        if(t2[i][idx] == '1'){
            t2[i][idx] = '0';
            r2[i]--;
        }else{
            t2[i][idx] = '1';
            r2[i]++;
        }
    }
}

int main()
{
    while(scanf("%d%d", &r, &c) == 2){
        // initialize rowSum
        memset(r1, 0, sizeof(r1));
        memset(r2, 0, sizeof(r2));
        // input table
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>t1[i][j]; 
                r1[i] += (t1[i][j] - '0');
            }
        }
        // enumerate 2^c cases
        int ans = 0;
        for(int i=0; i<pow(2, c); i++){
            // reset tmp table
            reset();
            // for one case
            int tmp = i;
            for(int j=0; j<c; j++){
                if(tmp & 1){ 
                    flip_column(j); // flip column j
                }
                tmp >>= 1;
            }
            // count result
            int ret = 0;
            for(int i=0; i<r; i++){
                ret += max(r2[i], c-r2[i]);
            }ans = max(ans, ret);
        }
        // output answer
        printf("%d\n", ans);
    }
    return 0;
}