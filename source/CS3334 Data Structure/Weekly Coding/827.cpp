#include <iostream>
#include <queue>

using namespace std;

void generateArray(int * arr, int n, int m, int seed) {
	unsigned x = seed;
	for (int i = 1; i <= n; i++) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		arr[i] = x % m + 1;
	}
}

int main() {
	int n, m, seed;
	cin >> n >> m >> seed;
	int* arr = new int[n + 1] { 0 };
	priority_queue<int, vector<int>, greater<int>> queue;

	generateArray(arr, n, m, seed);
	for (int i = 1; i <= n; i++)
		queue.push(arr[i]);

	while (queue.size() != 1) {
		int value = queue.top();
		queue.pop();
		queue.pop();
		queue.push(value * 2);
	}

	cout << queue.top() << endl;

	delete[] arr;
	return 0;
}
