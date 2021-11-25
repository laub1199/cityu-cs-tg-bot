#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class node {
public:
	int data;
	node* next;
};

int main() {

	int numOfStudent;
	int tagT;

	cin >> numOfStudent;


	node* ref = NULL;

	for (int i = 0; i < numOfStudent; i++) {
		node* newNode = new node;
		int temp;
		
		cin >> temp;
		newNode->data = temp;

		if (!ref) {
			newNode->next = ref;
			ref = newNode;
		}
		else {
			node* currNode = ref;
			while (currNode->next) {
				currNode = currNode->next;
			}
			currNode->next = newNode;
			currNode = newNode;
			if (i == numOfStudent - 1) {
				currNode->next = ref;
			}
			else {
				currNode->next = NULL;
			}
		}

	}


	int operation;

	while (cin >> operation) {
		if (operation == 1) {
			int position, tag;
			node* newNode = new node;
			node* currNode = ref;

			cin >> position >> tag;

			newNode->data = tag;

			for (int i = 0; i < position - 1; i++) {
				currNode = currNode->next;
			}

			newNode->next = currNode->next;
			currNode->next = newNode;

			for (int i = 0; i < position; i++) {
				ref = ref->next;
			}
		}
		else if (operation == 2) {
			int position;
			node* currNode = ref;
			node* targetNode = ref;

			cin >> position;

			for (int i = 0; i < position - 2; i++) {
				currNode = currNode->next;
				targetNode = targetNode->next;
			}
			targetNode = targetNode->next;

			currNode->next = targetNode->next;
			currNode = currNode->next;

			ref = currNode;
		}
		else if (operation == 3) {
			int position;

			cin >> position;

			for (int i = 0; i < position - 1; i++) {
				ref = ref->next;
			}

			cout << ref->data << endl;
		}
	}
	system("Pause");
}
