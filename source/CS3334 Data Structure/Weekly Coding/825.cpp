#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct Day {
	int day;
	unordered_set<int> passenger;

	Day(int day) : day(day) {}
};

int main() {
	int line, day, num, value;
	queue<Day> time;
	unordered_set<int> dict;
	cin >> line;
	int* list = new int[1000000] { 0 };

	for (int l = 0; l < line; l++) {
		cin >> day >> num;
		time.push(Day(day));

		for (int record = 0; record < num; record++) {
			cin >> value;

			int size = time.back().passenger.size();
			time.back().passenger.insert(value);
			if (time.back().passenger.size() > size && ++list[value] == 1)
				dict.insert(value);
		}

		while (time.back().day - time.front().day >= 86400) {
			for (unordered_set<int>::iterator iter = time.front().passenger.begin(); iter != time.front().passenger.end(); iter++) {
				if (!--list[*iter])
					dict.erase(*iter);
			}

			time.pop();
		}

		cout << dict.size() << endl;
	}

	return 0;
}
