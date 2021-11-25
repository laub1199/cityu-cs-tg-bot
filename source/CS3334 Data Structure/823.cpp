#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
	int wordNum, essayNum;
	string word;

	while (cin >> wordNum) {
		int count = 0, dist = INT32_MAX, tempIdx = -1, minIdx = 0;

		set<string> wordList;
		map<string, int> existList;

		for (int i = 0; i < wordNum; i++) {
			cin >> word;
			wordList.insert(word);
		}

		cin >> essayNum;

		for (int i = 0; i < essayNum; i++) {
			cin >> word;
			if (wordList.find(word) == wordList.end())
				continue;

			bool notFind = existList.find(word) == existList.end();
			if (notFind)
				count++;

			tempIdx = existList[word];
			existList[word] = i;

			if (tempIdx == minIdx || !tempIdx) {
				minIdx = INT32_MAX;

				for (map<string, int>::iterator iter = existList.begin(); iter != existList.end(); iter++) {
					if (iter->second < minIdx)
						minIdx = iter->second;
				}
			}

			int d = i - minIdx + 1;
			if (notFind || d < dist)
				dist = d;
		}

		if (!count)
			dist = 0;

		cout << count << "\n" << dist << endl;
	}

	return 0;
}
