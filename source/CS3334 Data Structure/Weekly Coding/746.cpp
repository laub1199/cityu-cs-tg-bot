#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) == 1){
	
        queue<int> q;
        while(!q.empty()) q.pop();
        // input
        for(int i=0; i<n; i++){
            int a, o, l;
            scanf("%d%d%d",&a,&o,&l);
            while(!q.empty() && q.front()<=a){
                q.pop(); // dequeue
            }
            if(i == n-1){
                if(q.size() <= l){
                    int ret = q.empty() ? a : q.back();
                    printf("%d\n",ret);
                }else{
                    printf("-1\n");
                }
            }else{
                if(q.size() <= l){
                    int ret = q.empty() ? a+o : q.back()+o ;
                    q.push(ret);
                }
            }
        }
    }
    return 0;
}