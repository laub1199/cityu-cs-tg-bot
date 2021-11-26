#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int tommy(string, int, int);
int main() {
	string jeng;
	while (cin >> jeng) {
		int rubbish = jeng.length() - 1;
		queue<int> copy;
		for (int i = 0; i < jeng.length(); i++) {
			if (jeng.at(i) == '(') {
				rubbish = tommy(jeng, i, jeng.length() - 1);
				int ilovepython = 0;
				for (int j = i; j < rubbish; j++) {
					if (jeng.at(j) == '(') {
						ilovepython++;
					}
				}
				copy.push(ilovepython);
			}
		}
		int hkhkhk;
		if (!copy.empty()) {
			hkhkhk = copy.front();
			copy.pop();
		}
		while (!copy.empty()) {
			hkhkhk = hkhkhk ^ copy.front();
			copy.pop();
		}
		cout << hkhkhk << endl;
	}
	return 0;
}

int tommy(string str, int stay, int sex) {
	if (stay > sex) {return -1;}
	stack<char> keep;
	for (int i = stay; i <= sex; i++) {
		if (str[i] == '(') {keep.push(str[i]);}
		else {
			keep.pop();
			if (keep.empty()) {return i;}
		}
	}
	return -1;
}



































// dont submit directly ok?
