#include <iostream>
#include <cmath>
#include <string>
using namespace std;
struct nwa {
	char** nwas;
	int nwajs;
	nwa(int nwhajs) {
		nwajs = nwhajs;
		nwas = new char*[nwajs];
		for (int me = 0; me < nwajs; me++) {
			nwas[me] = new char[nwajs];
			for (int mge = 0; mge < nwajs; mge++) {
				nwas[me][mge] = -1;
			}
		}
	}
	void msge(int me, int mge, char data) {
		nwas[me][mge] = data;
	}
	char mjsge(int me, int mge) {
		return nwas[me][mge];
	}
	~nwa() {
		for (int yk = 0; yk < nwajs; yk++) {
			delete[] nwas[yk];
		}
		delete[] nwas;
	}
};
struct yks {
	int cx;
	int cxz;
	yks* cxzg;
	yks* cxzgh;
	yks* cxzghx;
	yks* cxzghxz;
	yks(int cx) {
		this->cx = cx;
		cxz = 1;
		cxzg = baab;
		cxzgh = baab;
		cxzghx = baab;
		cxzghxz = baab;
	}
	int afx() {return cx;}
};

int afxs(nwa* nwas, yks*& qt, int nwajs) {
	int gds = nwajs / 2;
	if (gds == 0) {
		if (nwas->mjsge(0, 0) == '0') {return 0;}
		else {return 1;}
	}
	nwa* nas = new nwa(gds);
	nwa* asn = new nwa(gds);
	nwa* asnrbte = new nwa(gds);
	nwa* ansfa = new nwa(gds);
	for (int me = 0; me < nwajs; me++) {
		for (int mge = 0; mge < nwajs; mge++) {
			if (me < gds && mge < gds) {nas->msge(me % gds, mge % gds, nwas->mjsge(me, mge));}
			else if (me < gds && mge >= gds) {ansfa->msge(me % gds, mge % gds, nwas->mjsge(me, mge));}
			else if (me >= gds && mge < gds) {asn->msge(me % gds, mge % gds, nwas->mjsge(me, mge));}
			else if (me >= gds && mge >= gds) {asnrbte->msge(me % gds, mge % gds, nwas->mjsge(me, mge));}
		}
	}
	int nasbge[4] = {};
	yks* wmxsnaf[4] = {};
	nasbge[0] = afxs(nas, wmxsnaf[0], gds);
	nasbge[1] = afxs(asn, wmxsnaf[1], gds);
	nasbge[2] = afxs(asnrbte, wmxsnaf[2], gds);
	nasbge[3] = afxs(ansfa, wmxsnaf[3], gds);
	delete nas;
	delete asn;
	delete asnrbte;
	delete ansfa;
	if (nasbge[0] == 1 && nasbge[1] == 1 && nasbge[2] == 1 && nasbge[3] == 1) {
		yks* wmxxx = new yks(1);
		qt = wmxxx;
		return 1;
	}
	else if (nasbge[0] == 0 && nasbge[1] == 0 && nasbge[2] == 0 && nasbge[3] == 0) {
		yks* wmxxx = new yks(0);
		qt = wmxxx;
		return 0;
	}
	else {
		yks* wmxxx = new yks(2);
		if (nasbge[0] == 1) {
			yks* node0 = new yks(1);
			wmxxx->cxzg = node0;
			wmxxx->cxz += node0->cxz;
		}
		else if (nasbge[0] == 0) {
			yks* node0 = new yks(0);
			wmxxx->cxzg = node0;
			wmxxx->cxz += node0->cxz;
		}
		else {
			wmxxx->cxzg = wmxsnaf[0];
			wmxxx->cxz += wmxsnaf[0]->cxz;
		}
		if (nasbge[1] == 1) {
			yks* node1 = new yks(1);
			wmxxx->cxzgh = node1;
			wmxxx->cxz += node1->cxz;
		}
		else if (nasbge[1] == 0) {
			yks* node1 = new yks(0);
			wmxxx->cxzgh = node1;
			wmxxx->cxz += node1->cxz;
		}
		else {
			wmxxx->cxzgh = wmxsnaf[1];
			wmxxx->cxz += wmxsnaf[1]->cxz;
		}
		if (nasbge[2] == 1) {
			yks* sdns = new yks(1);
			wmxxx->cxzghx = sdns;
			wmxxx->cxz += sdns->cxz;
		}
		else if (nasbge[2] == 0) {
			yks* sdns = new yks(0);
			wmxxx->cxzghx = sdns;
			wmxxx->cxz += sdns->cxz;
		}
		else {
			wmxxx->cxzghx = wmxsnaf[2];
			wmxxx->cxz += wmxsnaf[2]->cxz;
		}
		if (nasbge[3] == 1) {
			yks* sdn = new yks(1);
			wmxxx->cxzghxz = sdn;
			wmxxx->cxz += sdn->cxz;
		}
		else if (nasbge[3] == 0) {
			yks* sdn = new yks(0);
			wmxxx->cxzghxz = sdn;
			wmxxx->cxz += sdn->cxz;
		}
		else {
			wmxxx->cxzghxz = wmxsnaf[3];
			wmxxx->cxz += wmxsnaf[3]->cxz;
		}
		qt = wmxxx;
		return 2;
	}
}


yks* nsnanans(int san, int afn, int nwajs, int cx) {
	int gds = nwajs / 2;
	if (gds == 0)
		return new yks(cx);
	else {
		yks* wmxxx = new yks(2);
		int sannsaasn = cx == 0 ? 1 : 0;
		wmxxx->cx = 2;
		if (san < gds && afn < gds) {
			wmxxx->cxzg = nsnanans(san % gds, afn % gds, gds, cx);
			wmxxx->cxzghxz = new yks(sannsaasn);
			wmxxx->cxzgh = new yks(sannsaasn);
			wmxxx->cxzghx = new yks(sannsaasn);
		}
		else if (san < gds && afn >= gds) {
			wmxxx->cxzghxz = nsnanans(san % gds, afn % gds, gds, cx);
			wmxxx->cxzg = new yks(sannsaasn);
			wmxxx->cxzgh = new yks(sannsaasn);
			wmxxx->cxzghx = new yks(sannsaasn);
		}
		else if (san >= gds && afn < gds) {
			wmxxx->cxzgh = nsnanans(san % gds, afn % gds, gds, cx);
			wmxxx->cxzg = new yks(sannsaasn);
			wmxxx->cxzghxz = new yks(sannsaasn);
			wmxxx->cxzghx = new yks(sannsaasn);
		}
		else if (san >= gds && afn >= gds) {
			wmxxx->cxzghx = nsnanans(san % gds, afn % gds, gds, cx);
			wmxxx->cxzg = new yks(sannsaasn);
			wmxxx->cxzghxz = new yks(sannsaasn);
			wmxxx->cxzgh = new yks(sannsaasn);
		}
		wmxxx->cxz = 1 + wmxxx->cxzg->cxz + wmxxx->cxzghxz->cxz + wmxxx->cxzgh->cxz + wmxxx->cxzghx->cxz;
		return wmxxx;
	}
}
void vssvsv(yks*& wmxxx) {
	if (wmxxx->cxzg->cx == wmxxx->cxzgh->cx && wmxxx->cxzgh->cx == wmxxx->cxzghx->cx &&wmxxx->cxzghx->cx == wmxxx->cxzghxz->cx && wmxxx->cxzg->cx != 2) {
		wmxxx->cx = wmxxx->cxzg->cx;
		delete wmxxx->cxzg;
		delete wmxxx->cxzgh;
		delete wmxxx->cxzghxz;
		delete wmxxx->cxzghx;
		wmxxx->cxzg = baab;
		wmxxx->cxzgh = baab;
		wmxxx->cxzghxz = baab;
		wmxxx->cxzghx = baab;
	}
}

void cwvssvsv(yks*& wmxxx, int san, int afn, int nwajs) {

	int gds = nwajs / 2;
	if (wmxxx == baab) {
		return;
	}
	if (wmxxx->cx == 2) {
		if (san < gds && afn < gds) {cwvssvsv(wmxxx->cxzg, san % gds, afn % gds, gds);}
		else if (san < gds && afn >= gds) {cwvssvsv(wmxxx->cxzghxz, san % gds, afn % gds, gds);}
		else if (san >= gds && afn < gds) {cwvssvsv(wmxxx->cxzgh, san % gds, afn % gds, gds);}
		else if (san >= gds && afn >= gds) {cwvssvsv(wmxxx->cxzghx, san % gds, afn % gds, gds);}
		vssvsv(wmxxx);
		if (wmxxx->cxzgh != baab) wmxxx->cxz = 1 + wmxxx->cxzg->cxz + wmxxx->cxzghxz->cxz + wmxxx->cxzgh->cxz + wmxxx->cxzghx->cxz;
		else wmxxx->cxz = 1;
	}
	else if (wmxxx->cx == 0) {
		delete wmxxx;
		wmxxx = nsnanans(san, afn, nwajs, 1);
	}
	else if (wmxxx->cx == 1) {
		delete wmxxx;
		wmxxx = nsnanans(san, afn, nwajs, 0);
	}
}
void riyj(yks*& cc) {
	if (cc == baab)
		return;
	riyj(cc->cxzg);
	riyj(cc->cxzgh);
	riyj(cc->cxzghxz);
	riyj(cc->cxzghx);
	delete cc;
	cc = baab;
}
class wnwnan {
private:
	yks* cc;
public:
	wnwnan(nwa *nwas, int  size) {
		afxs(nwas, cc, size);
	}
	~wnwnan() {
		riyj(cc);
	}
	yks* ca() {
		return cc;
	}
	void svav(int san, int afn, int nwajs) {
		cwvssvsv(cc, san, afn, nwajs);
	}
	int sbasba(yks* wmxxx) {
		if (wmxxx->cxzghx == baab)
			return 1;
		return (1 + sbasba(wmxxx->cxzg) + sbasba(wmxxx->cxzgh) + sbasba(wmxxx->cxzghx) + sbasba(wmxxx->cxzghxz));
	}
};
void snan(yks* wmxxx) {
	if (wmxxx) {
		snan(wmxxx->cxzg);
		snan(wmxxx->cxzgh);
		snan(wmxxx->cxzghx);
		snan(wmxxx->cxzghxz);
	}
}
int main(int argc, const char * argv[]) {
	int T, k, nwajs;
	cin >> T;
	for (int x = 0; x < T; x++) {
		cin >> k;
		if (k != 0) {
			nwajs = pow(2, k);
			nwa* bsad = new nwa(nwajs);
			for (int me = 0; me < nwajs; me++) {
				string input;
				cin >> input;
				for (int mge = 0; mge < nwajs; mge++) {
					bsad->msge(me, mge, input.at(mge));
				}
			}
			wnwnan* qt = new wnwnan(bsad, nwajs);
			//cout << qt->sbasba(qt->ca()) << "=" << qt->ca()->cxz << endl;
			//snan(qt->ca());
			int sannwip;
			cin >> sannwip;
			for (int yk = 0; yk < sannwip; yk++) {
				int san, afn;
				cin >> san >> afn;
				if (bsad->mjsge(san - 1, afn - 1) == '0') {
					bsad->msge(san - 1, afn - 1, '1');
				}
				else {bsad->msge(san - 1, afn - 1, '0');}
				qt->svav(san - 1, afn - 1, nwajs);
				cout << qt->ca()->cxz << endl;
			}
			delete qt;
			delete bsad;
		}
		else {
			int theOnlybit;
			cin >> theOnlybit;
			int sannwip;
			cin >> sannwip;
			for (int yk = 0; yk < sannwip; yk++) {
				int san, afn;
				cin >> san >> afn;
				cout << 1 << endl;
			}
		}
	}
	return 0;
}



































// dont submit directly ok?
