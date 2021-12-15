#include <bits/stdc++.h>
#define maxn 30005
using namespace std;

int read(){
    int ret = 0;
    char ch = getchar();
    while(ch<'0' || ch>'9'){
        ch = getchar();
    }
    while('0'<=ch && ch<='9'){
        ret = ret*10 + ch - '0';
        ch = getchar();
    }
    return ret;
}

int ret;
int arr[maxn];

void init(){
    ret = 0;
    memset(arr, -1, sizeof(arr));
}

int find(int x){
    return arr[x]<0 ? x : arr[x]=find(arr[x]);
}

void UNION_SET(int s1, int s2){
    arr[s1] += arr[s2];
    if(arr[s1]+ret < 0){
        ret = -arr[s1];
    }
    arr[s2] = s1; 
}

void UNION(int a, int b){
    int ra=find(a), rb=find(b);
    if(ra != rb){
        if(ra < rb){
            UNION_SET(ra, rb);
        }else{
            UNION_SET(rb, ra);
        }
    }
}

int main(){
    int T = read();
    while(T--){
        int N = read();
        int M = read();
        init();
        for(int i=0; i<M; i++){
            int a = read();
            int b = read();
            UNION(a, b);
        }
        printf("%d\n",ret);
    }
    return 0;
}