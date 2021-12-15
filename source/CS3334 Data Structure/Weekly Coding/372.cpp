#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, pre, cur;
    scanf("%d", &T);
    for(int cas=1; cas<=T; cas++)
    {
        int high=0, low=0;
        scanf("%d%d", &N, &pre);
        for(int i=0; i<N-1; i++)
        {
            scanf("%d", &cur);
            if(cur > pre) high++;
            if(cur < pre) low++;
            pre = cur;
        }
        printf("Case %d: %d %d\n", cas, high, low);
    }
    return 0;
}