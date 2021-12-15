#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        if(N==1 || N==2) printf("0\n");
        else printf("%d\n", N-2);
    }
    return 0;
}