#include <iostream>

using namespace std;

bool** map2d;
int* counter;
int ans = 0;
int k, n, m, value1, value2;

void pathTraverse(int idx, bool* visited) {
	for (int i = 1; i <= n; i++) {
		if (!map2d[idx][i] || visited[i]) continue;

		visited[idx] = true;
		if (++counter[i] == k)
			ans++;

		pathTraverse(i, visited);
	}
}

int main() {
	cin >> k >> n >> m;

	map2d = new bool*[n + 1];
	counter = new int[n + 1] { 0 };
	for (int i = 1; i <= n; i++)
		map2d[i] = new bool[n + 1]{ false };

	int* node = new int[n - k + 1];
	for (int i = 1; i <= k; i++) {
		cin >> value1;
		node[i] = value1;
	}

	while (m--) {
		cin >> value1 >> value2;
		map2d[value1][value2] = true;
	}

	for (int i = 1; i <= k; i++) {
		if (++counter[node[i]] == k)
			ans++;

		pathTraverse(node[i], new bool[n + 1]{ false });
	}

	cout << ans << endl;

	return 0;
}
