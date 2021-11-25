#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int findItsBracket(string, int, int);

int main() {

	string input;

	while (cin >> input) {
		int index = input.length() - 1;
		queue<int> q;
		for (int i = 0; i < input.length(); i++) {
			if (input.at(i) == '(') {
				index = findItsBracket(input, i, input.length() - 1);
				int weight = 0;
				for (int j = i; j < index; j++) {
					if (input.at(j) == '(') {
						weight++;
					}
				}
				q.push(weight);
			}
		}
		int ans;
		if (!q.empty()) {
			ans = q.front();
			q.pop();
		}
		while (!q.empty()) {
			ans = ans ^ q.front();
			q.pop();
		}
		cout << ans << endl;
	}



	return 0;
}

int findItsBracket(string str, int s, int e) {
	if (s > e) {
		return -1;
	}

	stack<char> sChar;

	for (int i = s; i <= e; i++) {
		if (str[i] == '(') {
			sChar.push(str[i]);
		}
		else {
			sChar.pop();
			if (sChar.empty()) {
				return i;
			}
		}
	}

	return -1;
}