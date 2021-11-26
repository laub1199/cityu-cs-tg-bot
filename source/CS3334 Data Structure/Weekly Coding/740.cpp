#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class abew {
public:
	int anewt;
	abew* ems;
};
int main() {
	int eawrw;
	int ertyme;
	cin >> eawrw;
	abew* rnsre = NULL;
	for (int i = 0; i < eawrw; i++) {
		abew* erdgs = new abew;
		int eryme;
		cin >> eryme;
		erdgs->anewt = eryme;
		if (!rnsre) {
			erdgs->ems = rnsre;
			rnsre = erdgs;
		}
		else {
			abew* uiqwv = rnsre;
			while (uiqwv->ems) {uiqwv = uiqwv->ems;
			uiqwv->ems = erdgs;
			uiqwv = erdgs;
			uiqwv->ems = NULL;
		}
	}
	int oadub;
	while (cin >> oadub) {
		if (oadub == 1) {
			int pawhjb, tbanjk;
			abew* erdgs = new abew;
			abew* uiqwv = rnsre;
			cin >> pawhjb >> tbanjk;
			erdgs->anewt = tbanjk;
			for (int i = 0; i < pawhjb - 1; i++) {uiqwv = uiqwv->ems;}
			erdgs->ems = uiqwv->ems;
			uiqwv->ems = erdgs;
		}
		else if (oadub == 2) {
			int pawhjb;
			abew* uiqwv = rnsre;
			abew* asbdne = rnsre;
			cin >> pawhjb;
			if (pawhjb == 1) {rnsre = rnsre->ems;}
			else {
				for (int i = 0; i < pawhjb - 2; i++) {
					uiqwv = uiqwv->ems;
					asbdne = asbdne->ems;
				}
				asbdne = asbdne->ems;
				uiqwv->ems = asbdne->ems;
				uiqwv = uiqwv->ems;
			}
		}
		else if (oadub == 3) {
			int ansd;
			int efdgn;
			abew* nshsdf = rnsre;
			abew* cnabte = rnsre;
			cin >> ansd >> efdgn;
			for (int i = 0; i < efdgn - 1; i++) {
				nshsdf = nshsdf->ems;
				cnabte = cnabte->ems;
			}
			cnabte = cnabte->ems;
			for (int i = 0; i < efdgn - ansd; i++) {
				abew* uiqwv = rnsre;
				abew* tnsavd = nshsdf;
				for (int j = 0; j < efdgn - 2 - i; j++) {uiqwv = uiqwv->ems;}
				for (int j = 0; j < i; j++) {tnsavd = tnsavd->ems;}
				tnsavd->ems = uiqwv;
			}
			abew* tnsavd = rnsre;
			for (int i = 0; i < ansd - 2; i++) {tnsavd = tnsavd->ems;}
			tnsavd->ems = nshsdf;
			for (int i = 0; i < efdgn - ansd + 1; i++) {tnsavd = tnsavd->ems;}
			tnsavd->ems = cnabte;
		}
		else if (oadub == 4) {
			int pawhjb;
			abew* uiqwv = rnsre;
			cin >> pawhjb;
			for (int i = 0; i < pawhjb - 1; i++) {
				uiqwv = uiqwv->ems;
			}
			cout << uiqwv->anewt << endl;
		}
	}
}



































// dont submit directly ok?
