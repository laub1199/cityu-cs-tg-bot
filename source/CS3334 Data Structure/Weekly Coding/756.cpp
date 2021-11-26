#include <iostream>
using namespace std;
void gg(int*, int, int);
void goodgame(int*, int);
void dllm(int*, int);
int main() {
	int haha;
	while (cin >> haha) {
		int damn = 0;
		int *bro = new int[haha + 1];
		for (int sls = 0; sls < haha; sls++) {
			char cls;
			cin >> cls;
			switch (cls) {
			case 'iron':
				damn++;
				int nmsl;
				cin >> nmsl;
				gg(bro, damn, nmsl);
				break;
			case 'r':
				dllm(bro, damn);
				break;
			case 'p':
				goodgame(bro, damn);
				damn--;
				break;

			}
		}
		delete[] bro;
	}
	return 0;
}
void gg(int* iron, int gold, int nmsl) {
	int jeng = gold;
	iron[jeng] = nmsl;
	int nmslese;
	if (jeng > 1) {
		nmslese = jeng / 2;
		while (iron[jeng] > iron[nmslese] && nmslese != 0) {int temp = iron[jeng];iron[jeng] = iron[nmslese];iron[nmslese] = temp;jeng = jeng / 2;nmslese = jeng / 2;}
	}
}

void goodgame(int*iron, int damn) {
	int silver = 1;
	iron[silver] = iron[damn];
	iron[damn] = 0;
	while ((silver * 2 <= (damn - 1)) && (iron[silver * 2] > iron[silver] || iron[((silver * 2) + 1)] > iron[silver])) {
		if (iron[silver * 2] > iron[silver] && iron[((silver * 2) + 1)] > iron[silver]) {
			if (iron[silver * 2] > iron[((silver * 2) + 1)]) {int temp = iron[silver * 2];iron[silver * 2] = iron[silver];iron[silver] = temp;silver = silver * 2;}
			else {int temp = iron[((silver * 2) + 1)];iron[((silver * 2) + 1)] = iron[silver];iron[silver] = temp;silver = (silver * 2) + 1;}
		}
		else if (iron[silver * 2] > iron[silver]) {int temp = iron[silver * 2];iron[silver * 2] = iron[silver];iron[silver] = temp;silver = silver * 2;}
		else if (iron[((silver * 2) + 1)] > iron[silver]) {int temp = iron[((silver * 2) + 1)];iron[((silver * 2) + 1)] = iron[silver];iron[silver] = temp;silver = (silver * 2) + 1;}
	}
}
void dllm(int* iron, int damn) {
	int wtf = 0; for (int sls = 1; sls <= damn; sls++) {wtf += iron[sls];}
	cout << wtf << endl;
}



































// dont submit directly ok?
