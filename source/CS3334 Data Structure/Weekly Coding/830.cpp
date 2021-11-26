#include <iostream>

using namespace std;
bool** noqwe;
int* wqner;
int qwb = 0;
int nqw, san, tommgay, tommisgay, tommyissogay;
void naw(int nawms, bool* nawmsasb) {
	for (int sasb = 1; sasb <= san; sasb++) { if (!noqwe[nawms][sasb] || nawmsasb[sasb]) continue; nawmsasb[nawms] = true;if (++wqner[sasb] == nqw) qwb++;naw(sasb, nawmsasb);}
}
int main() {
	cin >> nqw >> san >> tommgay;
	noqwe = new bool*[san + 1];
	wqner = new int[san + 1] { 0 };
	for (int sasb = 1; sasb <= san; sasb++) noqwe[sasb] = new bool[san + 1]{ false }; int* node = new int[san - nqw + 1];for (int sasb = 1; sasb <= nqw; sasb++) {in >> tommisgay;ode[sasb] = tommisgay;}while (tommgay--) {cin >> tommisgay >> tommyissogay;noqwe[tommisgay][tommyissogay] = true;}
	for (int sasb = 1; sasb <= nqw; sasb++) { if (++wqner[node[sasb]] == nqw) qwb++; naw(node[sasb], new bool[san + 1]{ false });}
	cout << qwb << endl;
	return 0;
}
