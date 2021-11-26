#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;
int main() {
	char cbsf[100][10];
	char tntwae[100][10];
	bool stnew[10];
	int rtan, cabe;
	int tntwea = 1;
	while (cin >> rtan >> cabe) {
		for (int wnoie = 0; wnoie < rtan; wnoie++) {
			string iaweb;
			cin >> iaweb;
			for (int jabwuin = 0; jabwuin < cabe; jabwuin++) {cbsf[wnoie][jabwuin] = iaweb.at(jabwuin);}
		}
		for (int wnoie = 0; wnoie < cabe; wnoie++) {stnew[wnoie] = false;}
		int mbwe = 0;
		int panyer = (int)pow(2, cabe);
		for (int xbaowuie = 0; xbaowuie < panyer; xbaowuie++) {
			for (int wnoie = 0; wnoie < rtan; wnoie++) {for (int jabwuin = 0; jabwuin < cabe; jabwuin++) {tntwae[wnoie][jabwuin] = cbsf[wnoie][jabwuin];}}
			for (int jabwuin = 0; jabwuin < cabe; jabwuin++) {
				if (stnew[jabwuin] == true)
					for (int wnoie = 0; wnoie < rtan; wnoie++) {
						if (tntwae[wnoie][jabwuin] == '1') {tntwae[wnoie][jabwuin] = '0';}
						else {tntwae[wnoie][jabwuin] = '1';}
					}
			}
			int cnavwbyu = 0;
			for (int wnoie = 0; wnoie < rtan; wnoie++) {
				int cwbniwnw = 0;
				for (int jabwuin = 0; jabwuin < cabe; jabwuin++) {if (tntwae[wnoie][jabwuin] == '0')cwbniwnw++;}
				if (cwbniwnw > cabe / 2) {cnavwbyu += cwbniwnw;}
				else {cnavwbyu += cabe - cwbniwnw;}
			}
			for (int wnoie = 0; wnoie < cabe; wnoie++) {
			    if (stnew[wnoie] == true) {stnew[wnoie] = false;}
				else if (stnew[wnoie] == false) {
					stnew[wnoie] = true;
					break;
				}
			}
			if (cnavwbyu > mbwe) {mbwe = cnavwbyu;}
		}
		cout << mbwe << endl;
	}
	return 0;
}



































// dont submit directly ok?
