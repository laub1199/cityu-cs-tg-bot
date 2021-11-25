#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, numOfCards;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> numOfCards;
		vector <int> allPiles;
		for (int j = 0; j < numOfCards; j++) {
			int input;
			cin >> input;
			allPiles.push_back(input);
		}

		int numOfOp;
		cin >> numOfOp;

		for (int j = 0; j < numOfOp; j++) {
			char inputChar;
			cin >> inputChar;

			if (inputChar == 'm') {
				cout << *max_element(allPiles.begin(), allPiles.end()) << endl;
			}

			if (inputChar == 'r') {
				allPiles.pop_back();

			}

			if (inputChar == 'a') {
				int value;
				cin >> value;

				allPiles.push_back(value);
			}
		}
		allPiles.clear();
	}

	return 0;

}


