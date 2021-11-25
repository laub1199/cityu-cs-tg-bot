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

			currNode->next = NULL;

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

		}
		else if (operation == 2) {
			int position;
			node* currNode = ref;
			node* targetNode = ref;

			cin >> position;
			
			if (position == 1) {
				ref = ref->next;
			}
			else {
				for (int i = 0; i < position - 2; i++) {
					currNode = currNode->next;
					targetNode = targetNode->next;
				}
				targetNode = targetNode->next;

				currNode->next = targetNode->next;
				currNode = currNode->next;
			}
		}
		else if (operation == 3) {
			int start;
			int end;
			node* newStart = ref;
			node* continueNode = ref;

			cin >> start >> end;

			for (int i = 0; i < end - 1; i++) {
				newStart = newStart->next;
				continueNode = continueNode->next;
			}
			continueNode = continueNode->next;

			for (int i = 0; i < end - start; i++) {
				node* currNode = ref;
				node* tempNode = newStart;

				for (int j = 0; j < end - 2 - i; j++) {
					currNode = currNode->next;
				}

				for (int j = 0; j < i; j++) {
					tempNode = tempNode->next;
				}

				tempNode->next = currNode;
	
			}

			node* tempNode = ref;

			for (int i = 0; i < start - 2; i++) {
				tempNode = tempNode->next;
			}

			tempNode->next = newStart;

			for (int i = 0; i < end - start + 1; i++) {
				tempNode = tempNode->next;
			}

			tempNode->next = continueNode;


		}
		else if (operation == 4) {
			int position;
			node* currNode = ref;

			cin >> position;

			for (int i = 0; i < position - 1; i++) {
				currNode = currNode->next;
			}

			cout << currNode->data << endl;
		}
	}
}