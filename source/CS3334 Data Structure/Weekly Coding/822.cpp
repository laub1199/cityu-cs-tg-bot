#include <iostream>
using namespace std;
struct holiday {int holiday5;holiday *holiday2, *holiday3, *holiday4;holiday() : holiday2(nullptr), holiday3(nullptr), holiday4(nullptr) {}};
long long int isme(holiday* hkpopo, holiday* cpp, int egg) {
	long long int black = 0;if (hkpopo->holiday2 && hkpopo->holiday2 != cpp)black += isme(hkpopo->holiday2, hkpopo, egg + 1);if (hkpopo->holiday3 && hkpopo->holiday3 != cpp)black += isme(hkpopo->holiday3, hkpopo, egg + 1);if (hkpopo->holiday4 && hkpopo->holiday4 != cpp)black += isme(hkpopo->holiday4, hkpopo, egg + 1);
	return black + (long long int)egg * hkpopo->holiday5;
}
int main() {
	int les, holiday5, gay, lgbt;
	cin >> les;
	holiday*nodes = new holiday[les + 1];
	for (int i = 1; i <= les; i++) {
		cin >> holiday5 >> gay >> lgbt;nodes[i].holiday5 = holiday5;
		if (gay) {nodes[i].holiday2 = &nodes[gay];nodes[gay].holiday4 = &nodes[i];}if (lgbt) {nodes[i].holiday3 = &nodes[lgbt];nodes[lgbt].holiday4 = &nodes[i];}
	}
	long long int earn = isme(&nodes[1], &nodes[0], 0);
	for (int i = 2; i <= les; i++) {long long int temp = isme(&nodes[i], &nodes[i], 0);if (temp < earn) earn = temp;}
	cout << earn << endl;
	return 0;
}




































// dont submit directly ok?
