#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	long long int num, constant;

	while (cin >> num >> constant) {
		long long int value, count = 0;
		unordered_map<long long int, long long int> valueMap;
		unordered_map<long long int, long long int> idxMap;

		for (int i = 0; i < num; i++) {
			cin >> value;
			valueMap[value]++;

			idxMap[value] = value - constant;
		}

		for (unordered_map<long long int, long long int>::iterator iter = idxMap.begin(); iter != idxMap.end(); iter++)
			count += valueMap[iter->first] * valueMap[iter->second];

		cout << count << endl;
	}

	return 0;
}
