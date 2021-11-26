#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int zxc, zxcs;
	cin >> zxc;
	for (int i = 0; i < zxc; i++) {
		cin >> zxcs;
		vector <int> zxchs;
		for (int zxvhchs = 0; zxvhchs < zxcs; zxvhchs++) {
			int zxhchs;
			cin >> zxhchs;
			zxchs.push_back(zxhchs);
		}
		int zxnvhchs;
		cin >> zxnvhchs;
		for (int zxvhchs = 0; zxvhchs < zxnvhchs; zxvhchs++) {
			char zxnvzchs;
			cin >> zxnvzchs;
			if (zxnvzchs == 'm') {cout << *max_element(zxchs.begin(), zxchs.end()) << endl;}
			if (zxnvzchs == 'r') {zxchs.pop_back();}
			if (zxnvzchs == 'a') {
				int zxnnvzchs;
				cin >> zxnnvzchs;
				zxchs.push_back(zxnnvzchs);
			}
		}
		zxchs.clear();
	}
	return 0;
}




































// dont submit directly ok?

