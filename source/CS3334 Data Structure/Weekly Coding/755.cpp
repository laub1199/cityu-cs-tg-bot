#include <iostream>
#include <stack>
using namespace std;
long long int cs3334(long long int cs4486[], long long int cs3440) {
	stack <int> cs2456;
	long long int ugh = 0, somafan, malunfan, jm9;
	jm9 = 0;
	while (jm9 < cs3440) {
		if (cs2456.empty() || cs4486[cs2456.top()] <= cs4486[jm9]) cs2456.push(jm9++);
		else {
			somafan = cs2456.top();
			cs2456.pop();
			if (cs2456.empty()) malunfan = cs4486[somafan] * jm9;
			else malunfan = cs4486[somafan] * (jm9 - cs2456.top() - 1);
			if (ugh < malunfan) ugh = malunfan;
		}
	}
	while (!cs2456.empty()) {
		somafan = cs2456.top();
		cs2456.pop();
		if (cs2456.empty()) malunfan = cs4486[somafan] * jm9;
		else malunfan = cs4486[somafan] * (jm9 - cs2456.top() - 1);
		if (ugh < malunfan) ugh = malunfan;
	}
	return ugh;
}
int main() {
	long long int longlongdick;
	cin >> longlongdick;
	for (long long int jm9 = 0; jm9 < longlongdick; jm9++) {
		long long int wet;
		cin >> wet;
		long long int *length = new long long int[wet];
		for (long long int jm9 = 0; jm9 < wet; jm9++)
			cin >> length[jm9];
		cout << cs3334(length, wet) << endl;
		delete[] length;
	}
	return 0;
}



































// dont submit directly ok?
