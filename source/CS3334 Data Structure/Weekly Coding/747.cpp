#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

queue< pair<int, int> > s;
queue< pair<int, int> > tmp;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n, k; // index start from 1
        scanf("%d%d", &n, &k);
        // initialize s
        for(int i=1; i<=n; i++){
            int val; scanf("%d", &val);
            s.push({val, i});
        }
        // boring job
        bool isFirst = true;
        while(!s.empty()){
            // pop
            int Vmax = -INF, idx = -1;
            if(s.size() >= k){
                for(int i=0; i<k; i++){
                    auto p = s.front(); s.pop();
                    tmp.push(p);
                    if(p.first > Vmax){
                        Vmax = p.first;
                        idx = p.second;
                    }
                }
            }else{
                while(!s.empty()){
                    auto p = s.front(); s.pop();
                    tmp.push(p);
                    if(p.first > Vmax){
                        Vmax = p.first;
                        idx = p.second;
                    }
                }
            }
            // append
            while(!tmp.empty()){
                auto p = tmp.front(); tmp.pop();
                if(p.second == idx){
                    if(isFirst){
                        printf("%d", p.second);
                        isFirst = false;
                    }else{
                        printf(" %d", p.second);
                    }
                }else{
                    p.first--;
                    s.push(p);
                }
            }
        }printf("\n");
    }
    return 0;
}