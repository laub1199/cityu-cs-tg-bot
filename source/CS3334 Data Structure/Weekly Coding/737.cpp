#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main(){
	string x;
	vector <string> d;
	vector <string> w;
	vector <int> c;
	while (cin >> x) {
		if (x.compare("0") == 0) break;
		d.push_back(x);
	}
	w.push_back(d[0]);
	c.push_back(0);
	for (size_t pd = 0; pd < d.size(); pd++) {
		bool n = true;
		for (size_t pw = 0; pw < w.size(); pw++) {
			if (d[pd].compare(w[pw]) == 0) {
				c[pw]++;
				n = false;
				break;
			}
		}
		if (n) {
			if (w.size() == 1) {
				if (d[pd].compare(w[0]) > 0) {
					w.push_back(d[pd]);
					c.push_back(1);
				}
				else {
					w.insert(w.begin(), d[pd]);
					c.insert(c.begin(), 1);
				}
			}
			else if (w.size() == 2){
				if (d[pd].compare(w[0]) < 0) {
					w.insert(w.begin(), d[pd]);
					c.insert(c.begin(), 1);
				}
				else if (d[pd].compare(w[0]) > 0 && d[pd].compare(w[1]) < 0) {
					w.insert(w.begin() + 1, d[pd]);
					c.insert(c.begin() + 1, 1);
				}
				else {
					w.push_back(d[pd]);
					c.push_back(1);
				}
			}
			else {
				for (size_t pw = 0; pw < w.size(); pw++) {
					if (d[pd].compare(w[pw]) < 0) {
						w.insert(w.begin() + pw, d[pd]);
						c.insert(c.begin() + pw, 1);
						break;
					}
					else if (d[pd].compare(w[pw]) > 0 && pw == w.size() - 1) {
						w.push_back(d[pd]);
						c.push_back(1);
					}
				}
			}
		}
	}
	for (size_t pw = 0; pw < w.size(); pw++) {
		cout << w[pw] << " " << c[pw] << endl;
	}
}



































// dont submit directly ok?
