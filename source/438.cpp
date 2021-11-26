#include<iostream>
using namespace std;
int main(){
        int k;
        cin>>k;
        while(k--){
                int n;
                cin>>n;
                if(n<=2){
                        cout<<"0"<<endl;
                }
                else{
                        cout<<n-2<<endl;
                }
        }
}
