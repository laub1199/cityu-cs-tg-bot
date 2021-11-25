#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateArray(int* arr, int n, int m, int seed) {
	unsigned x = seed;
	for (int i = 1; i <= n; i++) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		arr[i] = x % m + 1;
	}
}

int log10(int value) {
	if (value < 10)  return 0;
	else if (value < 100) return 1;
	else if (value < 1000) return 2;
	else if (value < 10000) return 3;
	else if (value < 100000) return 4;
	else if (value < 1000000) return 5;
	else if (value < 10000000) return 6;
	else return 7;
}

int main() {
	int n, m, seed, counter = 0, curIdx = -1, ans = 0;
	cin >> n >> m >> seed;
	int* arr = new int[n + 1]{ 0 };
	vector<vector<long long int>> list(9);

	generateArray(arr, n, m, seed);
	for (int i = 1; i <= n; i++)
		list[log10(arr[i])].push_back(arr[i]);

	for (int i = 0; i <= n; i++) {
		if (list[counter].empty()) counter++;
		else if (n == m) {
			sort(list[i].begin(), list[i].end());

		}
	}

	while (counter < list.size()) {
		int value;

		if (curIdx + 2 < list[counter].size()) {
			sort(list[counter].begin(), list[counter].end());
			value = list[counter][(++curIdx)++] * 2;
			list[log10(value)].push_back(value);
		}
		else {
			if (curIdx + 1 < list[counter].size()) {
				value = list[counter][++curIdx] * 2;

				while (++counter < list.size() && list[counter].empty()) {};
				if (counter == list.size()) continue;

				curIdx = 0;
				sort(list[counter].begin(), list[counter].end());
			}
			else {
				while (++counter < list.size() && list[counter].empty()) {};
				if (counter == list.size()) continue;

				sort(list[counter].begin(), list[counter].end());
				value = list[counter][(curIdx = 0)++] * 2;
			}

			list[log10(value)].push_back(value);
		}

		ans = value;
		cout << ans << endl;
	}

	cout << ans << endl;

	return 0;
}
