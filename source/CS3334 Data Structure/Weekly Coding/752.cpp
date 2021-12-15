#include <bits/stdc++.h>
#define maxn 105
using namespace std;

struct Node{
    int arv_tim, proc_tim, priority, idx;
    Node(){}
    Node(int a, int w, int p, int i):arv_tim(a), proc_tim(w), priority(p), idx(i){}
};

struct myQueue{
    int front, rear;
    Node arr[maxn];
    myQueue(){
        front = 0; rear = 0;
    }
    bool empty(){
        return front == rear;
    }
    int size(){
        return rear-front;
    }
    Node top(){
        if(!empty()){
            return arr[front];
        }
        printf("The queue is empty! ERROR!");
        return Node(0, 0, 0, 0);
    }
    void push(Node n){
        arr[rear++] = n;
    }
    Node pop(){
        if(!empty()){
            return arr[front++];
        }
        printf("The queue is empty! ERROR!");
        return Node(0, 0, 0, 0);
    }
    void clear(){
        front = 0; rear = 0;
    }
}buf, high, low;

int ret[maxn];

void init(){
    buf.clear();
    low.clear();
    high.clear();
    memset(ret, 0, sizeof(ret));
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        init();
        // initialize buffer
        for(int i=0; i<n; i++){
            int a, w, p;
            scanf("%d%d%d", &a, &w, &p);
            buf.push(Node(a, w, p, i));
        }
        int t = 0;
        Node bufTop, lowTop, highTop;
        while(!buf.empty() || !high.empty() || !low.empty()){
            if(high.empty() && low.empty()){
                bufTop = buf.top();
                if(bufTop.arv_tim > t){
                    t = bufTop.arv_tim;
                }else{
                    while(!buf.empty()){
                        bufTop = buf.top();
                        if(bufTop.arv_tim <= t){
                            if(bufTop.priority){
                                low.push(buf.pop());
                            }else{
                                high.push(buf.pop());
                            }       
                        }else{
                            break;
                        }
                    }
                }
            }
            // if high is not empty
            if(!high.empty()){
                highTop = high.top();
                t += highTop.proc_tim;
                ret[highTop.idx] = t; 
                high.pop();
                // enqueue
                while(!buf.empty()){
                    bufTop = buf.top();
                    if(bufTop.arv_tim <= t){
                        if(bufTop.priority){
                            low.push(buf.pop());
                        }else{
                            high.push(buf.pop());
                        }
                    }else{
                        break;
                    }
                }
            }else if(!low.empty()){
                lowTop = low.top();
                t += lowTop.proc_tim;
                ret[lowTop.idx] = t; 
                low.pop();
                // enqueue
                while(!buf.empty()){
                    bufTop = buf.top();
                    if(bufTop.arv_tim <= t){
                        if(bufTop.priority){
                            low.push(buf.pop());
                        }else{
                            high.push(buf.pop());
                        }
                    }else{
                        break;
                    }
                }
            }
            
        }
        for(int i=0; i<n; i++){
            if(i == 0){
                printf("%d", ret[i]);
            }else{
                printf(" %d", ret[i]);
            }            
        }printf("\n");
    }
    return 0;
}