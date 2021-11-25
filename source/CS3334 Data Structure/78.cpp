#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

char* getSubsequences(string input);

int main() {

	int count;

	cin >> count;

	for (int i = 0; i < count; i++) {

		string input;

		cin >> input;

		cout << getSubsequences(input) << endl;

	}

	system("Pause");
}

char* getSubsequences(string input) {
	
	int length = input.length();
	char* strToChar = new char [length + 1];

	input.copy(strToChar, length + 1);
	strToChar[length] = '\0';

	char largestChar = strToChar[0];
	int position = 0;

	for (int i = 0; i < length; i++) {
		if (strToChar[i] > largestChar) {
			largestChar = strToChar[i];
			position = i;
		}
	}

	bool notEnd = true;
	int begin = 0;
	char* result = new char[length + 1];

	result[begin++] = largestChar;
	largestChar = strToChar[++position];

	while (notEnd && length - position > 0) {
		for (int i = position + 1; i < length; i++)
		{
			if (strToChar[i] > largestChar) {
				largestChar = strToChar[i];
				position = i;
			}
		}

		result[begin++] = largestChar;
		largestChar = strToChar[++position];

		if (position == length - 1) {
			notEnd = false;
		}

	}

	if (position <= length - 1) {
		result[begin++] = strToChar[length - 1];
	}
	
	result[begin] = '\0';

	return result;
}

 