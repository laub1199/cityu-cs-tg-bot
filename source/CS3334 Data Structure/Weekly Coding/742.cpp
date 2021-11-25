#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int quad(int, int, int, int, char**);

int main() {
	int k;

	while (cin >> k) {
		int n = (int)pow(2, k);

		char** image = new char*[n + 1];	
		for (int i = 1; i <= n; i++) {
			image[i] = new char[n + 1];
		}

		for (int row = 1; row <= n; row++) {
			string input;
			cin >> input;
			for (int col = 1; col <= n; col++) {
				image[row][col] = input.at(col - 1);
			}
		}

		cout << quad(1, 1, n, n, image) << endl;

	}


	return 0;
}

int quad(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY, char** image) {
	char temp = (char)image[topLeftX][topLeftY];
	if (topLeftX == bottomRightX) {
		return 1;
	}
	for (int row = topLeftX; row <= bottomRightX; row++) {
		for (int col = topLeftY; col <= bottomRightY; col++) {
			if (image[row][col] != temp && bottomRightX > topLeftX && bottomRightY > topLeftY) {
				int node1[4] = { topLeftX, topLeftY, (bottomRightX - topLeftX) / 2 + topLeftX, (bottomRightY - topLeftY) / 2 + topLeftY };
				int node2[4] = { topLeftX, (bottomRightY - topLeftY) / 2 + topLeftY + 1, (bottomRightX - topLeftX) / 2 + topLeftX, bottomRightY };
				int node3[4] = { (bottomRightX - topLeftX) / 2 + topLeftX + 1, topLeftY, bottomRightX, (bottomRightY - topLeftY) / 2 + topLeftY };
				int node4[4] = { (bottomRightX - topLeftX) / 2 + topLeftX + 1,(bottomRightY - topLeftY) / 2 + topLeftY + 1, bottomRightX, bottomRightY };

				return  1 + (quad(node1[0], node1[1], node1[2], node1[3], image) + quad(node2[0], node2[1], node2[2], node2[3], image) + quad(node3[0], node3[1], node3[2], node3[3], image) + quad(node4[0], node4[1], node4[2], node4[3], image));
				break;
			}
		}
	}

	return 1;
}