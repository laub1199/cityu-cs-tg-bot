#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

#define N 100000


static int parent[N];
static int ranking[N];
static int element[N];


int maxi;

void formSet(int n){
    for(int i = 0; i < n; ++i){
        parent[i]  = i;
        ranking[i] = 0;
        element[i] = 1;
    }
}


int findSet(int x){
    if( x != parent[x] )
        parent[x] = findSet( parent[x] );
    return parent[x];
}


bool sameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void link(int x, int y){
    
    if( !sameSet(x, y) ){
        
        if( ranking[x] > ranking[y] ){
            parent[y] = x;
            element[x] += element[y];
            maxi = ( maxi < element[x] ) ? element[x] : maxi;
        }
        else{
            parent[x] = y;
            element[y] += element[x];
            maxi = ( maxi < element[y] ) ? element[y] : maxi;
            
            if(ranking[x] == ranking[y])
                ranking[y] = ranking[y] + 1;
        }
        
    }
}


void Union(int x, int y){
    link( findSet(x), findSet(y) );
}



int main(){
    int citizen, pair;
    int f1, f2;
    
    
    int cases;
    cin>>cases;
    
    
    for(int i = 0; i<cases;i++){
        
        cin>>citizen>>pair;
        
        formSet(citizen);
        
        maxi = 1;
        
        for(int j = 0; j<pair;j++){
            cin>>f1>>f2;
            --f1;
            --f2;
            Union(f1, f2);
        }
        
        cout<<maxi<<endl;
        
    }
    
    
    return 0;
}
