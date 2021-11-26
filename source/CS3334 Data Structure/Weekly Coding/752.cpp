#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
class mtchan {
private:
	int cwk;
	int jackie;
	int tony;
	int ben;
	int ken;
public:
	mtchan() = default;
	mtchan(int, int, int, int);
	int f1();
	int f2();
	int f3();
	int liza();
	int lisa();
	void ccp(int);
	void hk(int);
	void no(int);
	void it(int);
	void so9sad(int);
};
int main() {
	int meow;
	while (cin >> meow) {
		int city, hku, ust, cu = 0;
		queue<mtchan> poly;
		queue<mtchan> treeu;
		mtchan* lingu = new mtchan[meow];
		for (int fucku = 0; fucku < meow; fucku++) {
			cin >> city >> hku >> ust;
			lingu[fucku].ccp(fucku);
			lingu[fucku].hk(city);
			lingu[fucku].no(hku);
			lingu[fucku].it(ust);
		}
		bool mu = false;
		for (int xijinpin = 0; xijinpin < 6000; xijinpin++) {
			for (int fucku = 0; fucku < meow; fucku++) {
				if (lingu[fucku].f2() == xijinpin) {
					if (lingu[fucku].liza() == 0) {poly.push(lingu[fucku]);}
					else {treeu.push(lingu[fucku]);}
				}
				else {continue;}
			}
			if (cu == xijinpin) {mu = false;}
			if (!mu) {
				if (!poly.empty()) {
					mtchan temp = poly.front();
					for (int fucku = 0; fucku < meow; fucku++) {
						if (temp.f1() == fucku) {
							lingu[fucku].so9sad(xijinpin);
							cu = lingu[fucku].lisa();
							poly.pop();
							mu = true;
							break;
						}
					}
				}
				else if (!treeu.empty()) {
					mtchan temp = treeu.front();
					for (int fucku = 0; fucku < meow; fucku++) {
						if (temp.f1() == fucku) {
							lingu[fucku].so9sad(xijinpin);
							cu = lingu[fucku].lisa();
							treeu.pop();
							mu = true;
							break;
						}
					}
				}
			}
		}
		for (int fucku = 0; fucku < meow - 1; fucku++) {cout << lingu[fucku].lisa() << " ";}
		cout << lingu[meow - 1].lisa();
		cout << endl;
		delete[] lingu;
	}
	return 0;
}
mtchan::mtchan(int inID, int aT, int pT, int pri) {
	cwk = inID;
	jackie = aT;
	tony = pT;
	ben = pri;
}
int mtchan::f1() { return cwk; }
int mtchan::f2() { return jackie; }
int mtchan::f3() { return tony; }
int mtchan::liza() { return ben; }
int mtchan::lisa() { return ken; }
void mtchan::ccp(int inID) { cwk = inID; }
void mtchan::hk(int aT) { jackie = aT; }
void mtchan::no(int pT) { tony = pT; }
void mtchan::it(int pri) { ben = pri; }
void mtchan::so9sad(int dT) { ken = dT + tony; }




































// dont submit directly ok?
