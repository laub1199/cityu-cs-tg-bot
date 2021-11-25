#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


int main() {
	char input[100001];
	char in[100001];
	while (cin.getline(input, 100001)) {
		stack<char> container;
		stack<int> intContainer;
		bool success = true;

		for (int i = 0; input[i] !='\0'; i++) {
			if (input[i] == '[' || input[i] == '{' || input[i] == '(') {
				container.push(input[i]);
				intContainer.push(i);
			}
			else if (input[i] == ']' || input[i] == '}' || input[i] == ')') {
				if(container.empty()){
					success = false;
					cout << i + 1 << endl;
					break;
				}
				else if ((input[i] == ']' && container.top() == '[') || (input[i] == ')' && container.top() == '(') || (input[i] == '}' && container.top() == '{')) {
					container.pop();
					intContainer.pop();
				}
				else {
					success = false;
					cout << i + 1 << endl;
					break;
				}
			}
		}
		if (!container.empty() && success) {
			success = false;
			int temp;
			while (!intContainer.empty()) {
				temp = intContainer.top();
				intContainer.pop();
			}
			cout << temp + 1 << endl;
		}
		if (success) {
			cout << "Success" << endl;
		}
	}

	return 0;
}