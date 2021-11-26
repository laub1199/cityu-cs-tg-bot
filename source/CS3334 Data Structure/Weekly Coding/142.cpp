#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
#define N 100000
static int p[N];
static int r[N];
static int e[N];
int m;
void f1(int n){
    for(int i = 0; i < n; ++i){
        p[i]  = i;
        r[i] = 0;
        e[i] = 1;
    }
}
int f2(int x){
    if( x != p[x] )
        p[x] = f2( p[x] );
    return p[x];
}
bool f3(int x, int y){
    return f2(x) == f2(y);
}
void f4(int x, int y) {
    if( !f3(x, y)) {
        if(r[x] > r[y]) {
            p[y] = x;
            e[x] += e[y];
            m = ( m < e[x] ) ? e[x] : m;
        } else {
            p[x] = y;
            e[y] += e[x];
            m = ( m < e[y] ) ? e[y] : m;
            if(r[x] == r[y]) r[y] = r[y] + 1;
        }

    }
}
void U(int x, int y){
    f4( f2(x), f2(y) );
}
int main(){
    int c, a, f1, f2, k;
    cin>>k;
    for(int i = 0; i<k;i++){
        cin>>c>>a;
        f1(c);
        m = 1;
        for(int j = 0; j<a;j++){
            cin>>f1>>f2;
            --f1;
            --f2;
            U(f1, f2);
        }
        cout<<m<<endl;
    }
    return 0;
}




































// dont submit directly ok?
