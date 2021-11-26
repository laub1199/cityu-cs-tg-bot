#include <iostream>
using namespace std;
int sn(int asdn[], int asfa, int wn){
    for (int santu = 0; santu < wn; santu++)
        if (asdn[santu] == asfa)
            return santu;
    return -1;
}
void ssss(int sb[], int nwar[], int vsa, int &wnafw, int &asnd)
{
    int sanmd = sn(sb, nwar[0], vsa);
    if (sanmd != 0)
        ssss(sb, nwar + 1, sanmd, wnafw, asnd);
    if (sanmd != vsa - 1)
        ssss(sb + sanmd + 1, nwar + sanmd + 1, vsa - sanmd - 1, wnafw, asnd);
    wnafw++;
    if (asnd== wnafw)
        cout << nwar[0] << endl;
    else
        cout << nwar[0] << " ";
}
int main() {
    int sanfam;
    cin >> sanfam;
    for (int santu = 0; santu < sanfam; santu++) {
        int ssadn;
        int wnafw = 0;
        cin >> ssadn;
        int asnd = ssadn;
        int *sna = new int[ssadn];
        int *wvavawba = new int[ssadn];
        for (int j = 0; j < ssadn; j++)
            cin >> sna[j];
        for (int qwesx = 0; qwesx < ssadn; qwesx++)
            cin >> wvavawba[qwesx];
        ssss(wvavawba, sna, ssadn, wnafw, asnd);
        delete[] sna,wvavawba;
    }
    return 0;
}



































// dont submit directly ok?
