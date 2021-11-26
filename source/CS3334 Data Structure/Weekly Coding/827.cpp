#include <iostream>
#include <queue>
using namespace std;
void damn(int * damum, int dadad, int dasister, int dabrother) {
	unsigned justax = dabrother;
	for (int justani = 1; justani <= dadad; justani++) { justax ^= justax << 13; justax ^= justax >> 17; justax ^= justax << 5; damum[justani] = justax % dasister + 1; }
}

int main() {
	int dadad, dasister, dabrother; cin >> dadad >> dasister >> dabrother; int* damum = new int[dadad + 1] { 0 }; priority_queue<int, vector<int>, greater<int>> justq; damn(damum, dadad, dasister, dabrother);
	for (int justani = 1; justani <= dadad; justani++) justq.push(damum[justani]);
	while (justq.size() != 1) {int justv = justq.top();justq.pop();justq.pop();justq.push(justv * 2);}
	cout << justq.top() << endl;
	delete[] damum;
	return 0;
}



































// dont submit directly ok?
