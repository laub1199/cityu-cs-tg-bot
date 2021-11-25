#include <iostream>

using namespace std;

struct TreeNode {
	int cost;
	TreeNode *left, *right, *parent;

	TreeNode() : left(nullptr), right(nullptr), parent(nullptr) {}
};

long long int sumValue(TreeNode* curNode, TreeNode* prev, int dist) {
	long long int sum = 0;

	if (curNode->left && curNode->left != prev)
		sum += sumValue(curNode->left, curNode, dist + 1);
	if (curNode->right && curNode->right != prev)
		sum += sumValue(curNode->right, curNode, dist + 1);
	if (curNode->parent && curNode->parent != prev)
		sum += sumValue(curNode->parent, curNode, dist + 1);

	return sum + (long long int)dist * curNode->cost;
}

int main() {
	int num, cost, cA, cB;
	cin >> num;
	TreeNode*nodes = new TreeNode[num + 1];

	for (int i = 1; i <= num; i++) {
		cin >> cost >> cA >> cB;
		nodes[i].cost = cost;
		if (cA) {
			nodes[i].left = &nodes[cA];
			nodes[cA].parent = &nodes[i];
		}
		if (cB) {
			nodes[i].right = &nodes[cB];
			nodes[cB].parent = &nodes[i];
		}
	}

	long long int result = sumValue(&nodes[1], &nodes[0], 0);

	for (int i = 2; i <= num; i++) {
		long long int temp = sumValue(&nodes[i], &nodes[i], 0);
		if (temp < result)
			result = temp;
	}

	cout << result << endl;

	return 0;
}
