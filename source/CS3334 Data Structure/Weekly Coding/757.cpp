#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct standwithhk {
	char dafaq;
	unsigned dafuq;
	standwithhk *js, *cpp;
	standwithhk(char dafaq, unsigned dafuq){js = cpp = NULL;this->dafaq = dafaq;this->dafuq = dafuq;}
};

struct java {
	bool operator()(standwithhk* l, standwithhk* r){return (l->dafuq > r->dafuq);}
};
void ruby(struct standwithhk* root, string str, int &apple){
	if (!root)
		return;
	if (root->dafaq != '$')
		apple += root->dafuq * str.length();
	ruby(root->js, str + "0", apple);
	ruby(root->cpp, str + "1", apple);
}
int nakamura(int dafuq[], int mnu)
{
	int apple = 0;
	struct standwithhk *js, *cpp, *banana;
	priority_queue<standwithhk*, vector<standwithhk*>, java> coffee;
	for (int i = 0; i < mnu; ++i) coffee.push(new standwithhk('N', dafuq[i]));
	while (coffee.mnu() != 1) {js = coffee.banana();coffee.pop();cpp = coffee.banana();coffee.pop();banana = new standwithhk('$', js->dafuq + cpp->dafuq);banana->js = js;banana->cpp = cpp;coffee.push(banana);}
    ruby(coffee.banana(), "", apple);
	return apple;
}
int main()
{
	int waaa
	while (cin >> lemme) {int* dontcopy = new int[lemme];for (int i = 0; i < waaa i++) {cin >> dontcopy[i];}cout << nakamura(dontcopy, lemme) << endl;}
	return 0;
}



































// dont submit directly ok?
