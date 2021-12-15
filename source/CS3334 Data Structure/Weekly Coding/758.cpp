#include <iostream>
using namespace std;

void countsort(int arr[], int n, int exp)
{
	int count[100000] = { 0 };
	int* result = new int[n];
	for (int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 100000]++;
	}

	for (int i = 1; i < 100000; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		result[count[(arr[i] / exp) % 100000] - 1] = arr[i];
		count[(arr[i] / exp) % 100000]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = result[i];

	delete[] result;
}

int main()
{
	int t;
	cin >> t;
	int* ans = new int[t];
	for (int i = 0; i < t; i++)
	{
		int n, q;
		cin >> n >> q;
		int* arr = new int[n];
		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				arr[j] = 1;
			else if (j == 1)
				arr[j] = 1;
			else
				arr[j] = arr[j - 1] + arr[j - 2];
			arr[j] %= q;
			if (arr[j] > mx)
				mx = arr[j];
		}
		for (int exp = 1; mx / exp > 0; exp *= 100000)
			countsort(arr, n, exp);
		unsigned long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += ((unsigned long long)(i + 1)*(unsigned long long)arr[i]);
			if (sum >= q)
				sum %= q;
		}
		ans[i] = sum % q;
		delete[] arr;
	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << endl;
}