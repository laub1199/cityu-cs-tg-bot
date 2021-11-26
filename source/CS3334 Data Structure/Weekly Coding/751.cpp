#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	char bs[1002];
	while (cin.getline(bs, 1001)) {
		stack<int> bsz;
		int bsza;
		for (int i = 0; bs[i] != '\0'; i++) {
			if (bs[i] != ' ') {
				if (bs[i] >= '0' && bs[i] <= '9') {
					int zsa = (int)bs[i] - 48;
					while (bs[i + 1] != ' ' && bs[i + 1] != '\0') {
						i++;
						zsa *= 10;
						zsa += (int)bs[i] - 48;
					}
					bsz.push(zsa);
				}
				else {
					int zsa = bsz.top();
					bsz.pop();
						bsza = bsz.top();
						bsz.pop();
					switch (bs[i])
					{
					case '+':
						bsza += zsa;
						break;
					case '-':
						bsza -= zsa;
						break;
					case '*':
						bsza *= zsa;
						break;
					case '/':
						bsza /= zsa;
						break;
					default:
						break;
					}
					bsz.push(bsza);
				}
			}
		}
		cout << bsza << endl;
	}
	return 0;
}




































// dont submit directly ok?
