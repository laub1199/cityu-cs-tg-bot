#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool isFeasible(int[], int, int, int);
int largestMinDist(int[], int, int);

int main() {
	ios::sync_with_stdio(false);
	int numOfCase;
	cin >> numOfCase;

	for (int i = 0; i < numOfCase; i++) {
		int numOfRoom, numOfCustomer;
		cin >> numOfRoom >> numOfCustomer;
		int* allRooms;
		allRooms = new int[numOfRoom];
		for (int i = 0; i < numOfRoom; i++) {
			cin >> allRooms[i];
		}
		sort(allRooms, allRooms + numOfRoom);
		cout << largestMinDist(allRooms, numOfRoom, numOfCustomer) << endl;
		delete allRooms;
	}
	return 0;
}

bool isFeasible(int arr[], int mid, int n, int c) {
	int count = 0;
	int curr = arr[0];
	for (int i = 1; i < n; i++) {
		if (mid <= arr[i] - curr) {
			curr = arr[i];
			count++;
		}
		if (c == count + 1)
			return true;
	}
	return false;
}

int largestMinDist(int arr[], int n, int c) {
	int left = arr[0];
	int right = arr[n - 1];
	int ans = 0;
	while (left < right) {
		int mid = (left + right) / 2;
		if (isFeasible(arr, mid, n, c)) {
			if (ans < mid) {
				ans = mid;
				left = mid + 1;
			}
			else left = mid + 1;
		}
		else right = mid;
	}
	return ans;
}