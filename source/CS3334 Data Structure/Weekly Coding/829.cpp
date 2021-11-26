#include <iostream>
#include <queue>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> qwe;
typedef priority_queue<int> bas;
int push(int asd, qwe& sfana, bas& nas) {
	int wnqrm = 0; if (sfana.size() > 0) wnqrm = sfana.size() >= nas.size() ? sfana.top() : nas.top(); if (asd > wnqrm) sfana.push(asd); else nas.push(asd);
	if ((int)sfana.size() - (int)nas.size() > 1) {nas.push(sfana.top());sfana.pop();}
	else if ((int)nas.size() - (int)sfana.size() > 1) {sfana.push(nas.top());nas.pop();}
	if (((int)nas.size() + (int)sfana.size()) % 2 != 0) return nas.size() > sfana.size() ? nas.top() : sfana.top();
	return 0;
}
int main() {
	qwe sfana; bas nas; int mna, asd; cin >> mna;
	for (int i = 0; i < mna; i++) {cin >> asd; int wnqrm = push(asd, sfana, nas);if (wnqrm) cout << wnqrm << endl;}
	return 0;
}
