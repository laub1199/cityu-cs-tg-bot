#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct MinHeapNode {
	char data;

	unsigned freq;

	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)

	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};
void getResult(struct MinHeapNode* root, string str, int &ans)
{

	if (!root)
		return;

	if (root->data != '$')
		ans += root->freq * str.length();

	getResult(root->left, str + "0", ans);
	getResult(root->right, str + "1", ans);
}

int HuffmanCodes(int freq[], int size)
{
	int ans = 0;
	struct MinHeapNode *left, *right, *top;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode('N', freq[i]));

	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	getResult(minHeap.top(), "", ans);

	return ans;
}

int main()
{
	int index;

	while (cin >> index) {
		int* nums = new int[index];
		for (int i = 0; i < index; i++) {
			cin >> nums[i];
		}
		cout << HuffmanCodes(nums, index) << endl;
	}
	return 0;
}