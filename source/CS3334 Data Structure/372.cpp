#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	int numOfCase;

	cin >> numOfCase;

	for (int i = 0; i < numOfCase; i++) {

		int numOfData;
		cin >> numOfData;

		int* data = new int[numOfData];

		for (int j = 0; j < numOfData; j++) {
			cin >> data[j];
		}

		int up = 0;
		int down = 0;

		if (numOfData > 1) {
			for (int j = 0; j < numOfData - 1; j++) {
				if (data[j] > data[j + 1]) {
					down++;
				}
				else if (data[j] < data[j + 1]) {
					up++;
				}
			}
		}

		cout << "Case " << i + 1 << ": " << up << " " << down << endl;
	}
	return 0;
}