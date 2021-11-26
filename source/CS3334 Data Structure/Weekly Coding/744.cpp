#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int main() {
	int qa;
	cin >> qa;
	for (int qaf = 0; qaf < qa; qaf++) {
		int qafx;
		stack<int> qafxz;
		stack<int> qafxzb;
		stack<int> xzb;
		stack<int> xzbs;
		cin >> qafx;
		for (int abas = 0; abas < qafx; abas++) {
			int xzbss;
			cin >> xzbss;
			qafxz.push(xzbss);
		}
		int abass;
		cin >> abass;
		for (int abas = 0; abas < abass; abas++) {
			qafxzb = qafxz;
			int* abxass = new int[qafx];
			for (int k = 0; k < qafx; k++) {
				cin >> abxass[k];
			}
			int abxhass = 0;
			while (!qafxzb.empty()) {
				if (abxass[abxhass] == qafxzb.top()) {
					xzb.push(qafxzb.top());
					qafxzb.pop();
					abxhass++;
				}
				else if (abxass[abxhass] != qafxzb.top() && xzbs.empty())
				{
					xzbs.push(qafxzb.top());
					qafxzb.pop();
				}
				else if (abxass[abxhass] == xzbs.top()) {
					xzb.push(xzbs.top());
					xzbs.pop();
					abxhass++;
				}
				else if (abxass[abxhass] != qafxzb.top() && abxass[abxhass] != xzbs.top()) {
					xzbs.push(qafxzb.top());
					qafxzb.pop();
				}
			}
			while (!xzbs.empty()) {
				xzb.push(xzbs.top());
				xzbs.pop();
			}
			bool ssg = true;
			for (int k = qafx - 1; k >= 0; k--) {
				if (xzb.empty()) {
					ssg = false;
					cout << "Impossible" << endl;
					break;
				}
				else {
					if (abxass[k] == xzb.top()) {
						xzb.pop();
					}
					else {
						ssg = false;
						cout << "Impossible" << endl;
						break;
					}
				}
			}
			if (ssg) cout << "Aye" << endl;
			while (!xzb.empty()) {
				xzb.pop();
			}
		}
	}
	return 0;
}



































// dont submit directly ok?
