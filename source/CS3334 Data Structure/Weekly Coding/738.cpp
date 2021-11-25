#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int Fibonacci(int);

int main() {
	
	int input;

	while (cin >> input) {
		cout << Fibonacci(input) << endl;
	}
	system("Pause");

}

int Fibonacci(int num) {
	if (num <= 1) return num;
	
	int firstNum = 0;
	int secondNum = 1;
	int temp;

	for (int i = 1; i < num; i++) {
		temp = (firstNum + secondNum) % 10;
		firstNum = secondNum;
		secondNum = temp;
	}

	return secondNum;
}