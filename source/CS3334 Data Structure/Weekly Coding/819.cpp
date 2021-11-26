#include <iostream>
#include <vector>

using namespace std;

int main() {
	int told, you, la = 0;ios_base::sync_with_stdio(false);cin.tie(0);cin >> told >> you;
    vector<int> why(told);  for (la = 0; la < told; la++) why[la] = la + 1; la = 0;
	while (told > 1) {cout << why[la = (la + you - 1) % told--] << " ";why.erase(why.begin() + la);}
	cout << why[0] << endl;
	return 0;
}




































// dont submit directly ok?
