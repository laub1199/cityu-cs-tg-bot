//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main() {
//	int time, cut, ncut, node;
//
//	cin >> time;
//	for (int t = 0; t < time; t++) {
//		int n, m;
//		int count = 0, actionCount = 0;
//		map<string, int> action;
//		string key;
//
//		cin >> n >> m;
//
//		for (cut = 0; cut < n; cut++) {
//			key = "";
//
//			do {
//				cin >> node;
//				if (node >= 0)
//					key += node;
//			} while (node >= 0);
//
//			action[key.substr(0, key.size() - 1)] += 1;
//		}
//
//		for (ncut = 0; ncut < m; ncut++) {
//			key = "";
//
//			do {
//				cin >> node;
//				if (node >= 0)
//					key += node;
//			} while (node >= 0);
//
//			key = key.substr(0, key.size() - 1);
//			actionCount = action[key];
//			if (actionCount > 0) {
//				count += actionCount;
//				action.erase(key);
//			}
//		}
//
//		cout << (actionCount + action.size()) << endl;
//	}
//
//	return 0;
//}