#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


int main() {
	int numOfCases;

	cin >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {
		int numOfData;
		stack<int> tempA;
		stack<int> A;
		stack<int> B;
		stack<int> S;
		
		cin >> numOfData;

		for (int j = 0; j < numOfData; j++) {
			int temp;
			cin >> temp;
			tempA.push(temp);
		}

		int numOfTestCases;

		cin >> numOfTestCases;

		for (int j = 0; j < numOfTestCases; j++) {
			A = tempA;
			int* target = new int[numOfData];
			for (int k = 0; k < numOfData; k++) {
				cin >> target[k];
			}

			int curr = 0;
			while (!A.empty()) {
				if (target[curr] == A.top()) {
					B.push(A.top());
					A.pop();
					curr++;
				}
				else if (target[curr] != A.top() && S.empty())
				{
					S.push(A.top());
					A.pop();
				}
				else if (target[curr] == S.top()) {
					B.push(S.top());
					S.pop();
					curr++;
				}
				else if (target[curr] != A.top() && target[curr] != S.top()) {
					S.push(A.top());
					A.pop(); 
				}
			}
			while (!S.empty()) {
				B.push(S.top());
				S.pop();
			}

			bool aye = true;
			for (int k = numOfData - 1; k >= 0; k--) {
				if (B.empty()) {
					aye = false;
					cout << "Impossible" << endl;
					break;
				}
				else {
					if (target[k] == B.top()) {
						B.pop();
					}
					else {
						aye = false;
						cout << "Impossible" << endl;
						break;
					}
				}
			}

			if (aye) cout << "Aye" << endl;

			while (!B.empty()) {
				B.pop();
			}
		}
		
		

	}

	return 0;
}