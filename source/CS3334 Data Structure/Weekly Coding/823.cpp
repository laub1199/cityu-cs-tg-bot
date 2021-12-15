#include <bits/stdc++.h>
#define INF 0x7fffffff
#define maxm 100005
using namespace std;

map<string, int> myHash;
int arr[maxm], appear[maxm];

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF){
        // hash
        myHash.clear();
        for(int i=1; i<=n; i++){
            string str; cin>>str;
            myHash[str] = i;
        }
        // get type
        int types = 0; // #types
        memset(appear, 0, sizeof(appear)); // #appear times
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            string str; cin>>str;
            int hashValue = myHash[str];
            arr[i] = hashValue; // get hashValue
            if(hashValue){ // if hashValue>0
                if(!appear[hashValue]){ // if no appearance
                    types++;
                }
                appear[hashValue]++;
            }
        }
        // get len
        int len = INF;
        if(types == 0){
            len = 0;
        }else{
            int left = 0, right = m-1; 
            while(true){
                int hashValue = arr[right];
                if(!hashValue){
                    right--; continue;
                }else if(appear[hashValue]==1){
                    break;
                }else{
                    appear[hashValue]--;
                    right--;
                }
            }
            while(true){
                int hashValue = arr[left];
                if(!hashValue){
                    left++; continue;
                }else if(appear[hashValue]==1){
                    break;
                }else{
                    appear[hashValue]--;
                    left++;
                }
            }
            len = min(len, right-left+1);
            //printf("left:%d right:%d len:%d\n", left, right, len);
            while(right < m){
                right++; if(right>=m) break;
                int rightHashValue = arr[right];
                if(rightHashValue){
                    appear[rightHashValue]++;
                }
                while(true){
                    int leftHashValue = arr[left];
                    if(!leftHashValue){
                        left++; continue;
                    }else if(appear[leftHashValue]==1){
                        break;
                    }else{
                        appear[leftHashValue]--;
                        left++;
                    }
                }
                len = min(len, right-left+1);
            }
        }
        printf("%d\n%d\n", types, len);
    }
    return 0;
}