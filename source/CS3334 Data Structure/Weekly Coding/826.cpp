#include <iostream>
#include<unordered_map>
#include<queue>

using namespace std;

int main() {
	int size, wordNum, count = 0;
	unordered_map<int, int> dict;
	queue<int> key;
	cin >> size >> wordNum;

	int word;
	for (int i = 0; i < wordNum; i++) {
		cin >> word;

		if (!dict[word]) {
			dict[word] = 1;
			key.push(word);
			count++;

			if (dict.size() > size) {
				dict.erase(key.front());
				key.pop();
			}
		}
	}

	cout << count << endl;

	return 0;
}
