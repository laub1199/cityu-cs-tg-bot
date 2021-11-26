#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	long long int me, no;
	while (cin >> me >> no) {
		long long int yes, you = 0;unordered_map<long long int, long long int> him;unordered_map<long long int, long long int> her;
		for (int i = 0; i < me; i++) {cin >> yes;him[yes]++;her[yes] = yes - no;} for (unordered_map<long long int, long long int>::iterator iter = her.begin(); iter != her.end(); iter++) you += him[iter->first] * him[iter->second];
		cout << you << endl;
	}
	return 0;
}




































// dont submit directly ok?
