#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

int binary_search(int start, int end) {
	if (start > end)
		return start;
	else if (end < start)
		return end;

	int mid = (start + end) / 2;

	if (list[mid] == mid)
		return binary_search(mid + 1, end);
	else
		return binary_search(start, mid - 1);
}

int main() {
	int num, value;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> value;
		list.push_back(value);
	}

	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());

	cout << binary_search(0, list.size() - 1) << endl;

	return 0;
}
