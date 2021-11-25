#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


int main(){
	string input;
	vector <string> data;
	vector <string> words;
	vector <int> count;

	while (cin >> input) {
		if (input.compare("0") == 0) { break;}
		data.push_back(input);
	}
	words.push_back(data[0]);
	count.push_back(0);

	for (size_t positionOfData = 0; positionOfData < data.size(); positionOfData++) {
		bool newWord = true;
		
		for (size_t positionOfWords = 0; positionOfWords < words.size(); positionOfWords++) {
			if (data[positionOfData].compare(words[positionOfWords]) == 0) {
				count[positionOfWords]++;
				newWord = false;
				break;
			}
		}
		
		if (newWord) {
			if (words.size() == 1) {
				if (data[positionOfData].compare(words[0]) > 0) {
					words.push_back(data[positionOfData]);
					count.push_back(1);
				}
				else {
					words.insert(words.begin(), data[positionOfData]);
					count.insert(count.begin(), 1);
				}
			}
			else if (words.size() == 2){
				if (data[positionOfData].compare(words[0]) < 0) {
					words.insert(words.begin(), data[positionOfData]);
					count.insert(count.begin(), 1);
				}
				else if (data[positionOfData].compare(words[0]) > 0 && data[positionOfData].compare(words[1]) < 0) {
					words.insert(words.begin() + 1, data[positionOfData]);
					count.insert(count.begin() + 1, 1);
				}
				else {
					words.push_back(data[positionOfData]);
					count.push_back(1);
				};
			}
			else {
				for (size_t positionOfWords = 0; positionOfWords < words.size(); positionOfWords++) {
					if (data[positionOfData].compare(words[positionOfWords]) < 0) {
						words.insert(words.begin() + positionOfWords, data[positionOfData]);
						count.insert(count.begin() + positionOfWords, 1);
						break;
					}
					else if (data[positionOfData].compare(words[positionOfWords]) > 0 && positionOfWords == words.size() - 1) {
						words.push_back(data[positionOfData]);
						count.push_back(1);
					}
				}
			}
		}
	}

	for (size_t positionOfWords = 0; positionOfWords < words.size(); positionOfWords++) {
		cout << words[positionOfWords] << " " << count[positionOfWords] << endl;
	}

	system("Pause");

}