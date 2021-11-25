#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> MinQueue;
typedef priority_queue<int> MaxQueue;

int push(int value, MinQueue& minQueue, MaxQueue& maxQueue) {
	int median = 0;
	if (minQueue.size() > 0)
		median = minQueue.size() >= maxQueue.size() ? minQueue.top() : maxQueue.top();

	if (value > median)
		minQueue.push(value);
	else
		maxQueue.push(value);

	if ((int)minQueue.size() - (int)maxQueue.size() > 1) {
		maxQueue.push(minQueue.top());
		minQueue.pop();
	}
	else if ((int)maxQueue.size() - (int)minQueue.size() > 1) {
		minQueue.push(maxQueue.top());
		maxQueue.pop();
	}

	if (((int)maxQueue.size() + (int)minQueue.size()) % 2 != 0)
		return maxQueue.size() > minQueue.size() ? maxQueue.top() : minQueue.top();
	return 0;
}

int main() {
	MinQueue minQueue;
	MaxQueue maxQueue;

	int n, value;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> value;
		int median = push(value, minQueue, maxQueue);
		if (median)
			cout << median << endl;
	}

	return 0;
}
