#include <iostream>
using namespace std;

int search(int arr[], int x, int n){
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printResult(int inorderTree[], int preorderTree[], int node, int &count, int &num)
{
    int root = search(inorderTree, preorderTree[0], node);
    if (root != 0)
        printResult(inorderTree, preorderTree + 1, root, count, num);
    if (root != node - 1)
        printResult(inorderTree + root + 1, preorderTree + root + 1, node - root - 1, count, num);
    count++;
    if (num== count)
        cout << preorderTree[0] << endl;
    else
        cout << preorderTree[0] << " ";
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int noOfNodes;
        int count = 0;
        cin >> noOfNodes;
        int num = noOfNodes;
        int *preorder = new int[noOfNodes];
        int *inorder = new int[noOfNodes];
        
        for (int j = 0; j < noOfNodes; j++)
            cin >> preorder[j];
        
        for (int k = 0; k < noOfNodes; k++)
            cin >> inorder[k];
        
        printResult(inorder, preorder, noOfNodes, count, num);
        delete[] preorder,inorder;
    }
    
    
    return 0;
}
