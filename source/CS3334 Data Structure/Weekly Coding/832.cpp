#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int maxN = 1010; // [2, 1000]
int ds[maxN], enemy[maxN];

int find(int x)
{
    if(ds[x] < 0) return x;
    else return ds[x] = find(ds[x]);
}

void us(int s1, int s2) // s2->s1
{
    ds[s1] += ds[s2];
    ds[s2] = s1;
}

void u(int a, int b)
{
    int ra=find(a), rb=find(b);
    if(ra != rb) // important
    {
        if(ds[ra] < ds[rb]) us(ra, rb);
        else us(rb, ra);
    }
}

void e(int a, int b)
{
    int ea=enemy[a], eb=enemy[b];
    if(ea == 0) enemy[a] = b;
    else u(ea, b);
    if(eb == 0) enemy[b] = a;
    else u(eb, a);
}

int getNum(int n)
{
    int res=0;
    for(int i=1; i<=n; i++)
    {
        if(ds[i] < 0) res++;
    }
    return res;
}

int main()
{
    // TODO: input num of elements and num of facts
    int N, F;
    cin>>N>>F;
    // TODO: initialize disjoint set and enemy set
    memset(ds, -1, sizeof(ds));
    memset(enemy, 0, sizeof(enemy));
    // TODO: input facts
    char r;
    int e1, e2;
    while(F--)
    {
        cin>>r>>e1>>e2;
        switch(r)
        {
            case 'E':
            e(e1, e2); break;
            case 'F':
            u(e1, e2); break;
        }
    }
    // TODO: get solution
    int ans = getNum(N);
    cout<<ans<<endl;
    return 0;
}