#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int F(int);
int main() {
	int x;
	while (cin >> x) {
		cout << F(x) << endl;
	}
}
int F(int nx) {
	if (nx <= 1) return nx;
	int fn = 0;
	int sn = 1;
	int t;
	for (int i = 1; i < nx; i++) {
		t = (fn + sn) % 10;
		fn = sn;
		sn = t;
	}
	return sn;
}




































// dont submit directly ok?
