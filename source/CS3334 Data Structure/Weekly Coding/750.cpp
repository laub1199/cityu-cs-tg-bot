#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class wsx {
private:
	int wsxa;
	vector<wsx*> wsxag;
public:
	wsx(int);
	void wsxsag(wsx*);
	wsx* wsxsazg(int);
	void pazg(int, int, int&);
	int pazgx();
};
int main() {
	int pazgxg;
	cin >> pazgxg;
	for (int pgxg = 0; pgxg < pazgxg; pgxg++) {
		int pgzxg, pgzxqg;
		cin >> pgzxg >> pgzxqg;
		wsx* pgzvdqg = new wsx(pgzxg);
		for (int j = 0; j < pgzxqg - 1; j++) {
			int wsxa, parant;
			cin >> wsxa >> parant;
			wsx* jtg = pgzvdqg->wsxsazg(parant);
			jtg->wsxsag(new wsx(wsxa));
		}
		int jrtg, jrstg;
		int jrstgq;
		cin >> jrtg >> jrstg;
		pgzvdqg->pazg(jrtg, jrstg, jrstgq);
		cout << jrstgq << endl;
	}
	return 0;
}
wsx::wsx(int sb) {
	wsxa = sb;
}
void wsx::wsxsag(wsx* child) {
	wsxag.push_back(child);
}
wsx* wsx::wsxsazg(int n) {
	if (wsxa == n)
		return this;
	else {
		for (unsigned pgxg = 0; pgxg < wsxag.size(); pgxg++) {
			wsx* jtg = wsxag.at(pgxg);
			if (jtg->wsxsazg(n)) {
				return jtg->wsxsazg(n);
			}
		}
		return NULL;
	}
}
void wsx::pazg(int jrtg, int jrstg, int& jrstgq) {
	bool gsne = false;
	bool sae = false;
	if (this->wsxsazg(jrtg)) {
		gsne = true;
	}
	if (this->wsxsazg(jrstg)) {
		sae = true;
	}
	if (gsne && sae) {
		jrstgq = this->wsxa;
		for (unsigned pgxg = 0; pgxg < wsxag.size(); pgxg++)
			wsxag.at(pgxg)->pazg(jrtg, jrstg, jrstgq);
	}
}
int wsx::pazgx() {
	return wsxa;
}



































// dont submit directly ok?
