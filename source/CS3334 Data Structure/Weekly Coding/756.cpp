#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
// {0, ... , n-1}

int sz, sum, arr[maxn];

void init()
{
    sz = sum = 0;
    memset(arr, 0, sizeof(arr));
}

void ins(int val)
{
    int tmp = sz;
    arr[sz] = val;
    while(arr[tmp]>arr[(tmp-1)/2] && tmp>0){
        swap(arr[tmp], arr[(tmp-1)/2]);
        tmp = (tmp-1)/2;
    }
    sz++; sum+=val;
}

void del()
{
    int tmp = 0;
    sum -= arr[0];
    arr[0] = arr[sz-1];
    arr[sz-1] = 0;
    sz--;
    while(arr[tmp]<max(arr[2*tmp+1],arr[2*tmp+2]) && tmp<sz){
        if(arr[2*tmp+1] > arr[2*tmp+2]){
            swap(arr[tmp], arr[2*tmp+1]);
            tmp = 2*tmp+1;
        }else{
            swap(arr[tmp], arr[2*tmp+2]);
            tmp = 2*tmp+2;
        }
    }
}

int main()
{
    int m;
    while(scanf("%d", &m) == 1){
        init();
        for(int i=0; i<m; i++){
            char opt; cin>>opt;
            switch(opt){
                case 'a':
                    int num; scanf("%d", &num);
                    ins(num);
                    break;
                case 'p':
                    del();
                    break;
                case 'r':
                    printf("%d\n", sum);
                    break;
            }
        }
    }
    return 0;
}