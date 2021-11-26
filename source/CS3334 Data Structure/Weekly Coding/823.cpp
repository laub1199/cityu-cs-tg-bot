#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
	int amd, nvidia;
	string intel;
	while (cin >> amd) {
		int RTX3080 = 0, RTX3090 = INT32_MAX, RTX3090Ti = -1, RTX3070Ti = 0;set<string> crazy;map<string, int> taiwan; for (int HKDI2 = 0; HKDI2 < amd; HKDI2++) {cin >> intel;crazy.insert(intel);} cin >> nvidia;
		for (int HKDI2 = 0; HKDI2 < nvidia; HKDI2++) {
		    cin >> intel;if (crazy.find(intel) == crazy.end()) continue;bool itz = taiwan.find(intel) == taiwan.end();
			if (itz) RTX3080++;
			RTX3090Ti = taiwan[intel]; taiwan[intel] = HKDI2;
			if (RTX3090Ti == RTX3070Ti || !RTX3090Ti) {RTX3070Ti = INT32_MAX; for (map<string, int>::iterator iter = taiwan.begin(); iter != taiwan.end(); iter++) {if (iter->second < RTX3070Ti) RTX3070Ti = iter->second;}}
			int HKDI = HKDI2 - RTX3070Ti + 1;
			if (itz || HKDI < RTX3090) RTX3090 = HKDI;
		}
		if (!RTX3080) RTX3090 = 0;
		cout << RTX3080 << "\n" << RTX3090 << endl;
	}
	return 0;
}




































// dont submit directly ok?
