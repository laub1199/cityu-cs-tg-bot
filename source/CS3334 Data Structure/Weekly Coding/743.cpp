#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int main() {
	char wqb[100001];
	char nqw[100001];
	while (cin.getline(wqb, 100001)) {
		stack<char> nqws;
		stack<int> sasdnaw;
		bool qew = true;
		for (int qewx = 0; wqb[qewx] !='\0'; qewx++) {
			if (wqb[qewx] == '[' || wqb[qewx] == '{' || wqb[qewx] == '(') {
				nqws.push(wqb[qewx]);
				sasdnaw.push(qewx);
			}
			else if (wqb[qewx] == ']' || wqb[qewx] == '}' || wqb[qewx] == ')') {
				if(nqws.empty()){
					qew = false;
					cout << qewx + 1 << endl;
					break;
				}
				else if ((wqb[qewx] == ']' && nqws.top() == '[') || (wqb[qewx] == ')' && nqws.top() == '(') || (wqb[qewx] == '}' && nqws.top() == '{')) {
					nqws.pop();
					sasdnaw.pop();
				}
				else {
					qew = false;
					cout << qewx + 1 << endl;
					break;
				}
			}
		}
		if (!nqws.empty() && qew) {
			qew = false;
			int temp;
			while (!sasdnaw.empty()) {
				temp = sasdnaw.top();
				sasdnaw.pop();
			}
			cout << temp + 1 << endl;
		}
		if (qew) {
			cout << "Success" << endl;
		}
	}
	return 0;
}




































// dont submit directly ok?
