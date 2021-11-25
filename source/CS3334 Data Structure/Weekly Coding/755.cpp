#include <iostream>
#include <stack>
using namespace std;


long long int calMaxArea(long long int arr[], long long int s) {
	stack <int> prices;
	long long int maxArea = 0, topEdge, topArea, i;
	i = 0;

	while (i < s) {
		if (prices.empty() || arr[prices.top()] <= arr[i]) prices.push(i++);
		else {
			topEdge = prices.top();
			prices.pop();
			if (prices.empty()) topArea = arr[topEdge] * i;
			else topArea = arr[topEdge] * (i - prices.top() - 1);
			if (maxArea < topArea) maxArea = topArea;
		}
	}

	while (!prices.empty()) {
		topEdge = prices.top();
		prices.pop();
		if (prices.empty()) topArea = arr[topEdge] * i;
		else topArea = arr[topEdge] * (i - prices.top() - 1);
		if (maxArea < topArea) maxArea = topArea;
	}
	return maxArea;
}


int main() {
	long long int cases;
	cin >> cases;
	for (long long int i = 0; i < cases; i++) {
		long long int noOfDays;
		cin >> noOfDays;
		long long int *dayLength = new long long int[noOfDays];
		for (long long int i = 0; i < noOfDays; i++)
			cin >> dayLength[i];
		cout << calMaxArea(dayLength, noOfDays) << endl;
		delete[] dayLength;
	}
	return 0;
}