#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int val;
    node* nxt;
    node() { nxt = NULL; }
    node(int a) { val = a, nxt = NULL; }
}*head, *preNode, *newNode, *pre, *cur;

node* init(int n)
{
    int idx = 1;
    head = new node;
    head->val = idx++;
    preNode = head; n--;
    while(n--)
    {
        newNode = new node;
        newNode->val = idx++;
        preNode->nxt = newNode;
        preNode = newNode;
    }preNode->nxt = head;
    return head;
}

void solve(int n, int m)
{
    int idx = 1;
    bool first = true;
    cur = init(n), pre = new node;
    while(cur && cur->nxt)
    {
        if(idx == m) // execution
        {
            first ? printf("%d", cur->val), first=false : printf(" %d", cur->val);
            if(m == 1)
            {
                pre = cur->nxt;
                cur->nxt = NULL;
                cur = pre;
            }
            else
            {
                pre->nxt = cur->nxt;
                cur->nxt = NULL;
                cur = pre->nxt;
            }
            idx = 1;
        }
        else // survive
        {
            pre = cur;
            cur = cur->nxt;
            idx++;
        }
    }printf("\n");
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
    {
        solve(n, m);
    }
    return 0;
}