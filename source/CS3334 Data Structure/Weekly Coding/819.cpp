//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	int n, m, idx = 0;
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> m;
//
//	vector<int> arr(n);
//	for (idx = 0; idx < n; idx++)
//		arr[idx] = idx + 1;
//	idx = 0;
//
//	while (n > 1) {
//		cout << arr[idx = (idx + m - 1) % n--] << " ";
//		arr.erase(arr.begin() + idx);
//	}
//	cout << arr[0] << '\n';
//
//	return 0;
//}