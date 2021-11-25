#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int findMin(int, int);

int main() {
	int num, length, k, i, p, temp, vMax, index;
	pair <int, int>newPair;
	cin >> num;
	for (int j = 0; j < num; j++) {
		cin >> length >> k;
		deque <pair<int, int> >firstLine;
		deque <pair<int, int> >secondLine;

		for (i = 1; i <= length; i++) {
			cin >> temp;
			firstLine.push_back(make_pair(temp, i));
		}

		for (i = 1; i <= length; i++) {

			int time = findMin(k, firstLine.size());
			vMax = firstLine.front().first;
			index = firstLine.front().second;

			for (p = 1; p <= time; p++) {
				newPair = firstLine.front();
				if (vMax < newPair.first)
				{
					vMax = newPair.first;
					index = newPair.second;
				}
				firstLine.pop_front();
				secondLine.push_back(newPair);
			}

			time = secondLine.size();
			for (p = 1; p <= time; p++) {
				newPair = secondLine.front();
				secondLine.pop_front();
				if (index != newPair.second) {
					newPair.first--;
					firstLine.push_back(newPair);
				}
			}
			if (i != length) {
				cout << index;
				cout << " ";
			}
			else {
				cout << index;
			}
		}
		cout << endl;
	}
	return 0;
}

int findMin(int a, int b) {
	if (a < b)
		return a;
	return b;
}