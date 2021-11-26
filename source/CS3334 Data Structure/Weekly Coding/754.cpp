#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool dick(int[], int, int, int);
int penis(int[], int, int);
int main() {
	ios::sync_with_stdio(false);
	int pussy;
	cin >> pussy;
	for (int i = 0; i < pussy; i++) {
		int dog, cat;
		cin >> dog >> cat;
		int* monkey;
		monkey = new int[dog];
		for (int i = 0; i < dog; i++) {
			cin >> monkey[i];
		}
		sort(monkey, monkey + dog);
		cout << penis(monkey, dog, cat) << endl;
		delete monkey;
	}
	return 0;
}
bool dick(int a[], int fb, int google, int amazon) {
	int want = 0;
	int boob = a[0];
	for (int i = 1; i < google; i++) {
		if (fb <= a[i] - boob) {boob = a[i];want++;}
		if (amazon == want + 1)return true;
	}
	return false;
}
int penis(int a[], int google, int amazon) {
	int jor = a[0];
	int diu = a[google - 1];
	int ans = 0;
	while (jor < diu) {
		int fb = (jor + diu) / 2;
		if (dick(a, fb, google, amazon)) {if (ans < fb) {ans = fb;jor = fb + 1;}else jor = fb + 1;}
		else diu = fb;
	}
	return ans;
}



































// dont submit directly ok?
