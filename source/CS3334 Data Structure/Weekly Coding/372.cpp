#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		int* a = new int[d];
		for (int j = 0; j < d; j++) {
			cin >> a[j];
		}
		int u = 0;
		int b = 0;
		if (d > 1) {
			for (int j = 0; j < d - 1; j++) {
				if (a[j] > a[j + 1]) b++;
				else if (a[j] < a[j + 1]) u++;
			}
		}
		cout << "Case " << i + 1 << ": " << u << " " << b << endl;
	}
	return 0;
}



































// dont submit directly ok?
