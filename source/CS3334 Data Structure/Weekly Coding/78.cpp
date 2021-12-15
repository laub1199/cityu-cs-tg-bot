#include <bits/stdc++.h>
using namespace std;

string str, ans;
int len;

int main(){
    int N; scanf("%d",&N);
    while(N--){
        // input string
        cin>>str;
        len = str.size();
        // brutal force
        ans = "";
        int start = 0; // search start
        for(int i='z'; i>='a'; i--){
            for(int j=start; j<len; j++){
                if(str[j] == i){
                    start = j+1;
                    ans += (char)i;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}