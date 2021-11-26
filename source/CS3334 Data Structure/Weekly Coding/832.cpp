#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int money;
struct moneyy {
	int *moneyyy, *moneyyyy, *moneyyyyy;
	moneyy(int moneyyyyyy) : moneyyy(new int[moneyyyyyy + 1]), moneyyyy(new int[moneyyyyyy + 1]), moneyyyyy(new int[moneyyyyyy + 1] ) {
		for (int moneyyyyyyyyyyyyy = 1; moneyyyyyyyyyyyyy <= moneyyyyyy; moneyyyyyyyyyyyyy++) {moneyyyy[moneyyyyyyyyyyyyy] = moneyyyyyyyyyyyyy;moneyyyyy[moneyyyyyyyyyyyyy] = moneyyyyyyyyyyyyy;}
	}
	int moneyyyyyyy(int moneyyyyyyyy) { if (moneyyyy[moneyyyyyyyy] != moneyyyyyyyy) moneyyyy[moneyyyyyyyy] = moneyyyyyyy(moneyyyy[moneyyyyyyyy]); return moneyyyy[moneyyyyyyyy];}
	int moneyyyyyyyyy(int moneyyyyyyyy) { if (moneyyyyy[moneyyyyyyyy] != moneyyyyyyyy) moneyyyyy[moneyyyyyyyy] = moneyyyyyyy(moneyyyyy[moneyyyyyyyy]); return moneyyyyy[moneyyyyyyyy];}
	void moneyyyyyyyyyy(int moneyyyyyyyy, int moneyyyyyyyyyyyyyy) {
		int moneyyyyyyyyyyy = moneyyyyyyy(moneyyyyyyyy);
		int moneyyyyyyyyyyyy = moneyyyyyyy(moneyyyyyyyyyyyyyy);
		if (moneyyyyyyyyyyy == moneyyyyyyyyyyyy) return;
		if (moneyyy[moneyyyyyyyyyyy] < moneyyy[moneyyyyyyyyyyyy]) moneyyyy[moneyyyyyyyyyyy] = moneyyyyyyyyyyyy;
		else if (moneyyy[moneyyyyyyyyyyy] > moneyyy[moneyyyyyyyyyyyy]) moneyyyy[moneyyyyyyyyyyyy] = moneyyyyyyyyyyy;
		else {moneyyyy[moneyyyyyyyyyyyy] = moneyyyyyyyyyyy;moneyyy[moneyyyyyyyyyyy] += 1;}
		money--;
	}
};

int main() {
	int moneyyyyyy, moneyyyyyyyyyyyyyyy;
	cin >> moneyyyyyy >> moneyyyyyyyyyyyyyyy; money = moneyyyyyy; moneyy set(moneyyyyyy);
	char moneyyyyyyyyyyyyyyyy;
	int moneyyyyyyyyyyyyyyyyy, moneyyyyyyyyyyyyyyyyyy;
	while (moneyyyyyyyyyyyyyyy--) {
		cin >> moneyyyyyyyyyyyyyyyy >> moneyyyyyyyyyyyyyyyyy >> moneyyyyyyyyyyyyyyyyyy;
		if (moneyyyyyyyyyyyyyyyy == 'F') set.moneyyyyyyyyyy(moneyyyyyyyyyyyyyyyyy, moneyyyyyyyyyyyyyyyyyy);
		else {
			int moneyyyyyyyyyyyyyyyyyyy = set.moneyyyyyyyyy(moneyyyyyyyyyyyyyyyyy);
			if (moneyyyyyyyyyyyyyyyyyyy != moneyyyyyyyyyyyyyyyyy) set.moneyyyyyyyyyy(moneyyyyyyyyyyyyyyyyyyy, moneyyyyyyyyyyyyyyyyyy);
			else {int moneyyyyyyyyyyyyyyyyyyyy = set.moneyyyyyyyyy(moneyyyyyyyyyyyyyyyyyy);if (moneyyyyyyyyyyyyyyyyyyyy != moneyyyyyyyyyyyyyyyyyy) set.moneyyyyyyyyyy(moneyyyyyyyyyyyyyyyyy, moneyyyyyyyyyyyyyyyyyyyy);}
			set.moneyyyyy[moneyyyyyyyyyyyyyyyyy] = moneyyyyyyyyyyyyyyyyyy; set.moneyyyyy[moneyyyyyyyyyyyyyyyyyy] = moneyyyyyyyyyyyyyyyyy;
		}
	}
	cout << money << endl;
	return 0;
}



































// dont submit directly ok?
