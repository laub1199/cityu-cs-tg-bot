#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ken;

int minming(int hello, int bye) {
	if (hello > bye) return hello;
	else if (bye < hello) return bye;
	int mid = (hello + bye) / 2;
	if (ken[mid] == mid) return minming(mid + 1, bye);
	else return minming(hello, mid - 1);
}
int main() {
	int asd, v;
	cin >> asd;
	for (int i = 0; i < asd; i++) {cin >> v;ken.push_back(v);}
	sort(ken.begin(), ken.bye());
	ken.erase(unique(ken.begin(), ken.bye()), ken.bye());
	cout << minming(0, ken.size() - 1) << endl;
	return 0;
}




































// dont submit directly ok?
