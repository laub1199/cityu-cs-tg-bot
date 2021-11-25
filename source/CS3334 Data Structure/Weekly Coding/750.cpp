#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Tree {
private:
	int key;
	vector<Tree*> childList;

public:
	Tree(int);
	void addChild(Tree*);
	Tree* findChild(int);
	void findCCA(int, int, int&);
	int getKey();
};

int main() {
	int numOfCase;

	cin >> numOfCase;

	for (int i = 0; i < numOfCase; i++) {
		int rootNum, numOfOp;
		cin >> rootNum >> numOfOp;

		Tree* root = new Tree(rootNum);

		for (int j = 0; j < numOfOp - 1; j++) {
			int key, parant;
			cin >> key >> parant;

			Tree* temp = root->findChild(parant);
			temp->addChild(new Tree(key));
		}

		int num1, num2;
		int result;
		cin >> num1 >> num2;
		root->findCCA(num1, num2, result);

		cout << result << endl;
	}

	return 0;
}

Tree::Tree(int num) {
	key = num;
}

void Tree::addChild(Tree* child) {
	childList.push_back(child);
}

Tree* Tree::findChild(int n) {
	if (key == n)
		return this;
	else {
		for (unsigned i = 0; i < childList.size(); i++) {
			Tree* temp = childList.at(i);
			if (temp->findChild(n)) {
				return temp->findChild(n);
			}
		}
		return NULL;
	}
}

void Tree::findCCA(int num1, int num2, int& result) {
	bool num1Found = false;
	bool num2Found = false;

	if (this->findChild(num1)) {
		num1Found = true;
	}
	if (this->findChild(num2)) {
		num2Found = true;
	}

	if (num1Found && num2Found) {
		result = this->key;
		for (unsigned i = 0; i < childList.size(); i++)
			childList.at(i)->findCCA(num1, num2, result);
	}
}

int Tree::getKey() {
	return key;
}