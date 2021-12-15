#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int n, c, arr[maxn];

bool isValid(int x){
    int checkPoints = 1, pre = arr[0]; // check arr[0]
    for(int i=0; i<n; i++){
        if(arr[i]-pre >= x){
            checkPoints++; pre = arr[i]; // check
        }
    }
    return checkPoints >= c;
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &c);
        // input array and sort
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }sort(arr, arr+n);
        // binary search
        int leftBound, rightBound;
        leftBound = 0;
        rightBound = (arr[n-1]-arr[0])/(c-1) + 1;
        while(leftBound < rightBound-1){
            int mid = (leftBound + rightBound)>>1; 
            if(isValid(mid)){
                leftBound = mid;
            }else{
                rightBound = mid;
            }
        }
        printf("%d\n", leftBound);
    }
    return 0;
}