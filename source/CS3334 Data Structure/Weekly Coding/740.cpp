#include <bits/stdc++.h>
using namespace std;

list<int> ll;

void ins(int idx, int val){
    auto it = ll.begin();
    while(idx--) it++;
    ll.insert(it, val);
}

void del(int idx){
    auto it = ll.begin();
    while(idx--) it++;
    ll.erase(it);
}

void rev(int left, int right){
    auto l=ll.begin(), r=ll.begin();
    while(left--) l++;
    while(right--) r++;
    reverse(l, r);
}

void qry(int idx){
    auto it = ll.begin();
    while(idx--) it++;
    printf("%d\n", *it);
}

int main()
{
    int N;
    while(scanf("%d", &N) == 1){
        // input list
        int num;
        for(int i=0; i<N; i++){
            scanf("%d", &num);
            ll.push_back(num);
        }
        // operation
        int Q, opt, idx;
        scanf("%d", &Q);
        for(int i=0; i<Q; i++){
            scanf("%d%d", &opt, &idx);
            switch(opt){
                case 1: // insert
                    int val; scanf("%d", &val);
                    ins(idx, val);
                    break;
                case 2: // delete
                    del(idx-1);
                    break;
                case 3: // reverse
                    int end;
                    scanf("%d", &end);
                    rev(idx-1, end);
                    break;
                case 4: // query
                    qry(idx-1);
                    break;
            }
        }
    }
    return 0;
}