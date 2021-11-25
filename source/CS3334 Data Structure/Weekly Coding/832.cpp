#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int group;

struct DisjointSet {
	int *rank, *parent, *eParent;

	DisjointSet(int n) : rank(new int[n + 1]), parent(new int[n + 1]), eParent(new int[n + 1] ) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			eParent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x)
			parent[x] = find(parent[x]);

		return parent[x];
	}

	int findE(int x) {
		if (eParent[x] != x)
			eParent[x] = find(eParent[x]);

		return eParent[x];
	}

	void Union(int x, int y) {
		int left = find(x);
		int right = find(y);

		if (left == right) return;

		if (rank[left] < rank[right])
			parent[left] = right;
		else if (rank[left] > rank[right])
			parent[right] = left;
		else {
			parent[right] = left;
			rank[left] += 1;
		}
		group--;
	}
};

int main() {
	int n, line;
	cin >> n >> line;
	group = n;
	DisjointSet set(n);

	char op;
	int vLeft, vRight;
	while (line--) {
		cin >> op >> vLeft >> vRight;

		if (op == 'F')
			set.Union(vLeft, vRight);
		else {
			int eLeft = set.findE(vLeft);
			if (eLeft != vLeft)
				set.Union(eLeft, vRight);
			else {
				int eRight = set.findE(vRight);
				if (eRight != vRight)
					set.Union(vLeft, eRight);
			}

			set.eParent[vLeft] = vRight;
			set.eParent[vRight] = vLeft;
		}
	}

	cout << group << endl;

	return 0;
}
