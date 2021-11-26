#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int az(int, int);
int main() {
	int nas, nsas, sm, sma, smsa, smjsa, smkjsa, kjsa;
	pair <int, int>sjksa;
	cin >> nas;
	for (int kjksa = 0; kjksa < nas; kjksa++) {
		cin >> nsas >> sm;
		deque <pair<int, int> >lkjksa;
		deque <pair<int, int> >ljkjksa;
		for (sma = 1; sma <= nsas; sma++) {
			cin >> smjsa;
			lkjksa.push_back(make_pair(smjsa, sma));
		}
		for (sma = 1; sma <= nsas; sma++) {
			int ljkmasjksa = az(sm, lkjksa.size());
			smkjsa = lkjksa.front().first;
			kjsa = lkjksa.front().second;
			for (smsa = 1; smsa <= ljkmasjksa; smsa++) {
				sjksa = lkjksa.front();
				if (smkjsa < sjksa.first)
				{
					smkjsa = sjksa.first;
					kjsa = sjksa.second;
				}
				lkjksa.pop_front();
				ljkjksa.push_back(sjksa);
			}
			ljkmasjksa = ljkjksa.size();
			for (smsa = 1; smsa <= ljkmasjksa; smsa++) {
				sjksa = ljkjksa.front();
				ljkjksa.pop_front();
				if (kjsa != sjksa.second) {
					sjksa.first--;
					lkjksa.push_back(sjksa);
				}
			}
			if (sma != nsas) {
				cout << kjsa;
				cout << " ";
			}
			else {
				cout << kjsa;
			}
		}
		cout << endl;
	}
	return 0;
}
int az(int a, int b) {
	if (a < b)
		return a;
	return b;
}



































// dont submit directly ok?
