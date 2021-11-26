#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
char* a(string input);

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string x;
		cin >> x;
		cout << a(x) << endl;
	}
}

char* a(string x) {
	int l = x.length();
	char* c = new char [l + 1];
	x.copy(c, l + 1);
	c[l] = '\0';
	char z = c[0];
	int p = 0;
	for (int i=0; i<length; i++) {
		if (c[i] > z) {
			z = c[i];
			p = i;
		}
	}
	bool e = true;
	int b = 0;
	char* r = new char[length + 1];
	r[b++] = z;
	z = c[++position];
	while (e && l - p > 0) {
		for (int i = p + 1; i < l; i++) {
			if (c[i] > z) {
				z = c[i];
				p = i;
			}
		}
		r[b++] = z;
		z = c[++p];
		if (p == l - 1) e = false;
	}
	if (p <= l - 1) r[b++] = c[l - 1];
	r[b] = '\0';
	return r;
}




































// dont submit directly ok?
