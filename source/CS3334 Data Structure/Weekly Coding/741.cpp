#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <chrono> 

using namespace std;


int main() {
	char coin[100][10];
	char temp[100][10];
	bool state[10];
	int row, col;
	int tmp = 1;
	while (cin >> row >> col) {
		for (int i = 0; i < row; i++) {
			string input;
			cin >> input;
			for (int j = 0; j < col; j++) {
				coin[i][j] = input.at(j);
			}
		}
		for (int i = 0; i < col; i++) {
			state[i] = false;
		}


		int max = 0;
		int power = (int)pow(2, col);
		for (int x = 0; x < power; x++) {

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					temp[i][j] = coin[i][j];
				}
			}
			for (int j = 0; j < col; j++) {
				if (state[j] == true)
					for (int i = 0; i < row; i++) {
						if (temp[i][j] == '1') {
							temp[i][j] = '0';
						}
						else {
							temp[i][j] = '1';
						}
					}
			}
			int countNum1 = 0;
			for (int i = 0; i < row; i++) {
				int count = 0;
				for (int j = 0; j < col; j++) {
					if (temp[i][j] == '0')
						count++;
				}
				if (count > col / 2) {
					countNum1 += count;
				}
				else {
					countNum1 += col - count;
				}
			}
			for (int i = 0; i < col; i++) {
				if (state[i] == true) {
					state[i] = false;
				}
				else if (state[i] == false) {
					state[i] = true;
					break;
				}
			}
			if (countNum1 > max) {
				max = countNum1;
			}
		}



		cout << max << endl;
	}

	system("pause");
	return 0;
}