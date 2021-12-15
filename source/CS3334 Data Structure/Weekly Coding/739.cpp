#include <bits/stdc++.h>
using namespace std;

// insert, remove, query

class node
{
    public:
    int tag;
    node* nxt;
}*ptr;

void init(int n)
{
    node *newNode, *preNode; 
    // head
    int t;
    scanf("%d", &t);
    ptr = new node;
    ptr->tag = t;
    preNode = ptr;
    // new node
    for(int i=0; i<n-1; i++)
    {
        scanf("%d", &t);
        newNode = new node;
        newNode->tag = t;
        preNode->nxt = newNode;
        preNode = newNode;
    }preNode->nxt = ptr;
}

void Insert(int idx, int t)
{
    node *preNode, *postNode, *newNode; 
    preNode = ptr;
    for(int i=0; i<idx-1; i++)
    {
        preNode = preNode->nxt;
    }postNode = preNode->nxt;
    newNode = new node;
    newNode->tag = t;
    newNode->nxt = postNode;
    preNode->nxt = newNode;
    ptr = newNode;
}

void Remove(int idx)
{
    node *cur, *pre, *post;
    cur = ptr;
    for(int i=0; i<idx-2; i++)
    {
        cur = cur->nxt;
    }pre=cur, cur=cur->nxt;
    post = cur->nxt;
    pre->nxt = post;
    ptr = post;
}

void Query(int idx)
{
    for(int i=0; i<idx-1; i++)
    {
        ptr = ptr->nxt;
    }printf("%d\n", ptr->tag);
}

int main()
{
    int N, Q;
    while(scanf("%d", &N) == 1)
    {
        init(N); // initialize list
        scanf("%d", &Q);
        int opt, idx, t;
        for(int i=0; i<Q; i++)
        {
            scanf("%d%d", &opt, &idx);
            switch(opt)
            {
                case 1:
                    scanf("%d", &t); 
                    Insert(idx, t);
                    break;
                case 2:
                    Remove(idx);
                    break;
                case 3: 
                    Query(idx);
                    break;
            }
        }
    }
    return 0;
}