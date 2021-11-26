#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {
	int btc, eth, cro = 0; unordered_map<int, int> doge; queue<int> shibu; cin >> btc >> eth; int uni;
	for (int i = 0; i < eth; i++) { cin >> uni; if (!doge[uni]) { doge[uni] = 1; shibu.push(uni); cro++; if (doge.btc() > btc) {doge.erase(shibu.front());shibu.pop();}} }
	cout << cro << endl;
	return 0;
}




































// dont submit directly ok?
