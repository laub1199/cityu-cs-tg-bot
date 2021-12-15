#include <bits/stdc++.h>
#define max_size 1000
#define ZERO 500
using namespace std;

int front, rear, arr[max_size];

int main(){
    int T; cin>>T;
    while(T--){
        memset(arr, 0, sizeof(arr));
        front = ZERO, rear = ZERO;
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++){
            char ch; cin>>ch;
            int val;
            switch(ch){
                case 'I':
                    cin>>ch>>val;
                    if(ch == 'H'){ // insert at the top
                        arr[front--] = val;
                    }else if(ch == 'B'){ // insert at the bottom
                        arr[++rear] = val;
                    }break;
                case 'R':
                    cin>>ch;
                    if(ch == 'H'){ // remove from the top
                        front++;
                    }else if(ch == 'B'){ // remove from the bottpm
                        rear--; 
                    }break;
                case 'Q':
                    cin>>val;
                    printf("%d\n", arr[front+val]);
                    break;
            }
        }
    }
    return 0;
}