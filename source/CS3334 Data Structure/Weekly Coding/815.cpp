#include <iostream>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);int jm9, FBI;cin >> jm9;set<int> code;set<int>::iterator isMe;code.insert(0);code.insert(jm9 + 1);
	for (int netflix = 0; netflix < jm9; netflix++) {cin >> FBI;isMe = code.insert(code.begin(), FBI);cout << *prev(isMe) << " " << *next(isMe) << '\n';}
	return 0;
}




































// dont submit directly ok?
