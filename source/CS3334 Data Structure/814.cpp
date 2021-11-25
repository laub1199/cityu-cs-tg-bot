#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned short n, m, q;
	unsigned int input;
	unsigned short r1, r2, c1, c2, h, w;
	unsigned short rows, cols;
	unsigned short tr1, tr2;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m >> q) {
		vector<vector<unsigned int>> board;

		// Initialize vector
		for (rows = 0; rows < n; rows++) {
			vector<unsigned int> temp;
			for (cols = 0; cols < m; cols++) {
				cin >> input;
				temp.push_back(input);
			}

			board.push_back(temp);
		}

		// Swap element
		for (input = 0; input < q; input++) {
			cin >> r1 >> c1 >> r2 >> c2 >> h >> w;
			r1--; c1--; r2--; c2--;

			for (rows = r1; rows < r1 + h; rows++) {
				tr1 = rows % m;
				tr2 = (r2 + (rows - r1)) % m;

				swap_ranges(board[tr1].begin() + c1, board[tr1].begin() + c1 + w , board[tr2].begin() + c2);
			}
		}

		string result = "";

		// Print result
		for (rows = 0; rows < n; rows++) {
			for (cols = 0; cols < m; cols++)
				cout << board[rows][cols] << " ";
			cout << "\n";
		}
	}

	return 0;
}
