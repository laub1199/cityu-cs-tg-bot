#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	char input[1002];

	while (cin.getline(input, 1001)) {
		stack<int> container;
		int result;
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] != ' ') {
				if (input[i] >= '0' && input[i] <= '9') {
					int temp = (int)input[i] - 48;
					while (input[i + 1] != ' ' && input[i + 1] != '\0') {
						i++;
						temp *= 10;
						temp += (int)input[i] - 48;
					}
					container.push(temp);
				}
				else {
					
					int temp = container.top();
					container.pop();
						result = container.top();
						container.pop();

					switch (input[i])
					{
					case '+':
						result += temp;
						break;
					case '-':
						result -= temp;
						break;
					case '*':
						result *= temp;
						break;
					case '/':
						result /= temp;
						break;
					default:
						break;
					}
					container.push(result);
				}
			}
			
		}
		cout << result << endl;
	}
	return 0;
}
