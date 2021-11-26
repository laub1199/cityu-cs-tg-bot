#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
int qarne(int, int, int, int, char**);
int main() {
	int aewn;
	while (cin >> aewn) {
		int neawbt = (int)pow(2, aewn);
		char** qwertyu = new char*[neawbt + 1];
		for (int i = 1; i <= neawbt; i++) {qwertyu[i] = new char[neawbt + 1];}
		for (int rwoaniue = 1; rwoaniue <= neawbt; rwoaniue++) {
			string ivaweb;
			cin >> ivaweb;
			for (int asd = 1; asd <= neawbt; asd++) {qwertyu[rwoaniue][asd] = ivaweb.at(asd - 1);}
		}
		cout << qarne(1, 1, neawbt, neawbt, qwertyu) << endl;
	}
	return 0;
}
int qarne(int qwe, int qwer, int qwert, int qwerty, char** qwertyu) {
	char temp = (char)qwertyu[qwe][qwer];
	if (qwe == qwert) {
		return 1;
	}
	for (int rwoaniue = qwe; rwoaniue <= qwert; rwoaniue++) {
		for (int asd = qwer; asd <= qwerty; asd++) {
			if (qwertyu[rwoaniue][asd] != temp && qwert > qwe && qwerty > qwer) {
				int qwa[4] = { qwe, qwer, (qwert - qwe) / 2 + qwe, (qwerty - qwer) / 2 + qwer };
				int qwas[4] = { qwe, (qwerty - qwer) / 2 + qwer + 1, (qwert - qwe) / 2 + qwe, qwerty };
				int qwasf[4] = { (qwert - qwe) / 2 + qwe + 1, qwer, qwert, (qwerty - qwer) / 2 + qwer };
				int qwasfx[4] = { (qwert - qwe) / 2 + qwe + 1,(qwerty - qwer) / 2 + qwer + 1, qwert, qwerty };
				return  1 + (qarne(qwa[0], qwa[1], qwa[2], qwa[3], qwertyu) + qarne(qwas[0], qwas[1], qwas[2], qwas[3], qwertyu) + qarne(qwasf[0], qwasf[1], qwasf[2], qwasf[3], qwertyu) + qarne(qwasfx[0], qwasfx[1], qwasfx[2], qwasfx[3], qwertyu));
				break;
			}
		}
	}
	return 1;
}




































// dont submit directly ok?
