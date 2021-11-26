#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class wdqs {
public:
	int d;
	wdqs* ascx;
};
int main() {
	int wcacv;
	int saveads;
	cin >> wcacv;
	wdqs* ascwgw = NULL;
	for (int i = 0; i < wcacv; i++) {
		wdqs* fuyk = new wdqs;
		int grsebt;
		cin >> grsebt;
		fuyk->d = grsebt;
		if (!ascwgw) {
			fuyk->ascx = ascwgw;
			ascwgw = fuyk;
		}
		else {
			wdqs* amy = ascwgw;
			while (amy->ascx) {
				amy = amy->ascx;
			}
			amy->ascx = fuyk;
			amy = fuyk;
			if (i == wcacv - 1) {
				amy->ascx = ascwgw;
			}
			else {
				amy->ascx = NULL;
			}
		}
	}
	int amerys;
	while (cin >> amerys) {
		if (amerys == 1) {
			int vfads, nwe;
			wdqs* fuyk = new wdqs;
			wdqs* amy = ascwgw;
			cin >> vfads >> nwe;
			fuyk->d = nwe;
			for (int i = 0; i < vfads - 1; i++) {
				amy = amy->ascx;
			}
			fuyk->ascx = amy->ascx;
			amy->ascx = fuyk;
			for (int i = 0; i < vfads; i++) {
				ascwgw = ascwgw->ascx;
			}
		}
		else if (amerys == 2) {
			int vfads;
			wdqs* amy = ascwgw;
			wdqs* wnesqn = ascwgw;
			cin >> vfads;
			for (int i = 0; i < vfads - 2; i++) {
				amy = amy->ascx;
				wnesqn = wnesqn->ascx;
			}
			wnesqn = wnesqn->ascx;
			amy->ascx = wnesqn->ascx;
			amy = amy->ascx;
			ascwgw = amy;
		}
		else if (amerys == 3) {
			int vfads;
			cin >> vfads;
			for (int i = 0; i < vfads - 1; i++) {
				ascwgw = ascwgw->ascx;
			}
			cout << ascwgw->d << endl;
		}
	}
}



































// dont submit directly ok?
