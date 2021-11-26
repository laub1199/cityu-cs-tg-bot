#include <iostream>
#include <queue>
using namespace std;
int main() {
	int za, zae, zfae, zfaes, zfhaes;
	while (cin >> za) {
		queue<int> zfhkaes;
		cin >> zae;
		cin >> zfae;
		cin >> zfaes;
		zfhkaes.push(zae + zfae);
		if (za == 1) {
			cout << zae << endl;
		}
		else {
			for (int i = 1; i < za - 1; i++) {
				cin >> zae;
				cin >> zfae;
				cin >> zfaes;
				while (!zfhkaes.empty() && zfhkaes.front() <= zae)
					zfhkaes.pop();
				if (zfaes >= zfhkaes.size()) {
					if (zae > zfhkaes.back())
						zfhaes = zae + zfae;
					else
						zfhaes = zfhkaes.back() + zfae;
					zfhkaes.push(zfhaes);
				}
			}
			cin >> zae >> zfae >> zfaes;
			while (!zfhkaes.empty() && zfhkaes.front() <= zae)
				zfhkaes.pop();
			if (zfhkaes.size() <= zfaes) {
				if (zae > zfhkaes.back())
					cout << zae << endl;
				else
					cout << zfhkaes.back() << endl;
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}



































// dont submit directly ok?
