#include <iostream>
using namespace std;
void tg(int samsung[], int jump, int sandbox)
{
	int popo[100000] = { 0 };
	int* murder = new int[jump];
	for (int thisav = 0; thisav < jump; thisav++){popo[(samsung[thisav] / sandbox) % 100000]++;}
	for (int thisav = 1; thisav < 100000; thisav++){popo[thisav] += popo[thisav - 1];}
	for (int thisav = jump - 1; thisav >= 0; thisav--){murder[popo[(samsung[thisav] / sandbox) % 100000] - 1] = samsung[thisav];popo[(samsung[thisav] / sandbox) % 100000]--;}
	for (int thisav = 0; thisav < jump; thisav++) samsung[thisav] = murder[thisav];
	delete[] murder;
}
int main()
{
	int pornhub;
	cin >> pornhub;
	int* jable = new int[pornhub];
	for (int thisav = 0; thisav < pornhub; thisav++)
	{
		int jump, noq; cin >> jump >> noq; int* samsung = new int[jump]; int nig = 0;
		for (int j = 0; j < jump; j++){
			if (j == 0) samsung[j] = 1;
			else if (j == 1) samsung[j] = 1;
			else samsung[j] = samsung[j - 1] + samsung[j - 2];
			samsung[j] %= noq;
			if (samsung[j] > nig) nig = samsung[j];
		}
		for (int sandbox = 1; nig / sandbox > 0; sandbox *= 100000)
			tg(samsung, jump, sandbox);
		unsigned long long softbank = 0;
		for (int thisav = 0; thisav < jump; thisav++){softbank += ((unsigned long long)(thisav + 1)*(unsigned long long)samsung[thisav]);if (softbank >= noq) softbank %= noq;}
		jable[thisav] = softbank % noq;
		delete[] samsung;
	}
	for (int thisav = 0; thisav < pornhub; thisav++)
		cout << jable[thisav] << endl;
}




































// dont submit directly ok?
