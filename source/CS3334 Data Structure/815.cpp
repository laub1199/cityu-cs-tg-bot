//#include <iostream>
//#include <set>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int num, value;
//	cin >> num;
//
//	set<int> arr;
//	set<int>::iterator iter;
//	arr.insert(0);
//	arr.insert(num + 1);
//
//	for (int idx = 0; idx < num; idx++) {
//		cin >> value;
//		iter = arr.insert(arr.begin(), value);
//		cout << *prev(iter) << " " << *next(iter) << '\n';
//	}
//
//	return 0;
//}