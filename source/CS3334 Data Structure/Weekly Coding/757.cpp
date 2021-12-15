#include<bits/stdc++.h>
#define maxN 100001
using namespace std;
// huffman tree & heap
class MinHeap
{
    private:
    int size;
    int arr[maxN];
    public:
    MinHeap() { size=0; }
    int getSize() { return size; }
    void PUSH(int val);
    int POP();
};

void MinHeap::PUSH(int val)
{
    int tmp = size;
    arr[size] = val;
    // for i>0, child i -> parent (i-1)/2
    // while child is less than parent, keep swaping
    while(arr[tmp]<arr[(tmp-1)/2] && tmp>0)
    {
        swap(arr[tmp], arr[(tmp-1)/2]);
        tmp = (tmp-1)/2;
    }size++;
}

int MinHeap::POP()
{
    int ret, child, ptr, hole;
    ret = arr[0]; // return value
    arr[0] = arr[size-1];
    ptr = arr[0];
    for(hole=0; 2*hole+1<size; hole=child)
    {
        child = 2*hole+1;
        // choose the smaller one 
        if(arr[child+1]<arr[child] && child+1<size) child++;
        // swaping
        if(arr[child] < ptr) arr[hole] = arr[child];
        else break;
    }arr[hole] = ptr;
    size--;
    return ret;
}

int main()
{
    int N;
    while(scanf("%d", &N) == 1)
    {
        MinHeap mh;
        int fre;
        for(int i=0; i<N; i++)
        {
            scanf("%d", &fre);
            mh.PUSH(fre);
        }
        int ans = 0;
        while(mh.getSize() > 1)
        {
            int x, y;
            x = mh.POP();
            y = mh.POP();
            ans += (x+y);
            mh.PUSH(x+y);
        }printf("%d\n", ans);
    }
    return 0;
}