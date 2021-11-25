#include <iostream>
using namespace std;

void add(int*, int, int);
void pop(int*, int);
void prompt(int*, int);

int main() {
	int numOfOp;
	while (cin >> numOfOp) {
		int index = 0;
		int *arr = new int[numOfOp + 1];

		for (int i = 0; i < numOfOp; i++) {
			char op;
			cin >> op;
			switch (op) {
			case 'a':
				index++;
				int num;
				cin >> num;
				add(arr, index, num);
				break;
			case 'r':
				prompt(arr, index);
				break;
			case 'p':
				pop(arr, index);
				index--;
				break;

			}
		}
		delete[] arr;
	}
	return 0;
}

void add(int* a, int b, int num) {
	int curr = b;
	a[curr] = num;
	int parent;

	if (curr > 1) {
		parent = curr / 2;
		while (a[curr] > a[parent] && parent != 0) {
			int temp = a[curr];
			a[curr] = a[parent];
			a[parent] = temp;
			curr = curr / 2;
			parent = curr / 2;
		}
	}
}

void pop(int*a, int index) {
	int pos = 1;
	a[pos] = a[index];
	a[index] = 0;

	while ((pos * 2 <= (index - 1)) && (a[pos * 2] > a[pos] || a[((pos * 2) + 1)] > a[pos])) {
		if (a[pos * 2] > a[pos] && a[((pos * 2) + 1)] > a[pos]) {
			if (a[pos * 2] > a[((pos * 2) + 1)]) {
				int temp = a[pos * 2];
				a[pos * 2] = a[pos];
				a[pos] = temp;
				pos = pos * 2;
			}
			else {
				int temp = a[((pos * 2) + 1)];
				a[((pos * 2) + 1)] = a[pos];
				a[pos] = temp;
				pos = (pos * 2) + 1;
			}
		}
		else if (a[pos * 2] > a[pos]) {
			int temp = a[pos * 2];
			a[pos * 2] = a[pos];
			a[pos] = temp;
			pos = pos * 2;
		}
		else if (a[((pos * 2) + 1)] > a[pos]) {
			int temp = a[((pos * 2) + 1)];
			a[((pos * 2) + 1)] = a[pos];
			a[pos] = temp;
			pos = (pos * 2) + 1;
		}
	}
}

void prompt(int* a, int index) {
	int ans = 0;

	for (int i = 1; i <= index; i++) {
		ans += a[i];
	}

	cout << ans << endl;
}