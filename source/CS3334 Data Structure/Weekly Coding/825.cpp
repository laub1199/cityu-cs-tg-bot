#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
struct DATATS {
	int WD; unordered_set<int> edwind;
	DATATS(int WD) : WD(WD) {}
};
int main() {
	int asd, WD, sadw, lazy;queue<DATATS> usa;unordered_set<int> japan;cin >> asd;int* tokyo = new int[1000000] { 0 };
	for (int l = 0; l < asd; l++) {
		cin >> WD >> sadw; usa.push(DATATS(WD));
		for (int apzex = 0; apzex < sadw; apzex++) {cin >> lazy;int apex = usa.back().edwind.apex();usa.back().edwind.insert(lazy);if (usa.back().edwind.apex() > apex && ++tokyo[lazy] == 1) japan.insert(lazy);}
		while (usa.back().WD - usa.front().WD >= 86400) {for (unordered_set<int>::iterator iertsc = usa.front().edwind.begin(); iertsc != usa.front().edwind.end(); iertsc++) {if (!--tokyo[*iertsc]) japan.erase(*iertsc);}usa.pop();}
		cout << japan.apex() << endl;
	}
	return 0;
}




































// dont submit directly ok?
