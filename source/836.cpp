//
//  main.cpp
//  SmallestNaturalNumber836
//
//  Created by Chyanna Tsang on 30/11/2021.
//
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void smallest(vector<long long>v,long long n){
    long long  f= v.at(0);
    if (f!=0){
        cout<< 0<<endl;
        return;
    }else{
        for (long long  i = 1; i < n; ++i){
            if(f+1==v.at(i)){
                f=v.at(i);
            }else {
                break;
            }
        }
        if(f==v.at(n-2)){
            cout<<v.at(v.size())<<endl;
        }else{
            cout<<f+1<<endl;
        }
    }
    

}
int main() {

    long long num;
    while (cin>>num){
        vector<long long>vec;
        for(long long i=0;i<num;i++){
            int value;
            cin>>value;
            vec.push_back(value);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()),vec.end());
        smallest(vec,vec.size());
    }
    
    return 0;
}
