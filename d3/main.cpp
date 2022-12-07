#include <string>
#include <fstream>
#include <iostream>
#include <map>

using std::string;
int translatePoints(char);
int main() {
		std::ifstream file("data.txt");
		int sum = 0;
		string line;
	
		while(getline(file, line)) {
				string l2 = line.substr(line.length() / 2);
				line = line.substr(0, line.length() / 2);
				for(size_t i = 0; i < line.length(); i++) {
						for(size_t j = 0; j < l2.length(); j++) {
								if(line[i] == l2[j]) {
										sum += translatePoints(line[i]);
										goto loop;
								}
						}
				}

loop:
				std::cout << "";
		}

		std::cout << sum << std::endl;

		file.clear();
		file.seekg(0);
		std::map<char, int> charCount;
		sum = 0;
		while(file.peek() != EOF) {
				charCount.clear();
				for(int i = 0; i < 3; i++) {
						getline(file, line);
						for(char c : line) {
								if(charCount[c] == i) {
									charCount[c]++;
								}
						}
				}

				for(std::pair<char, int> p : charCount) {
						if(p.second == 3) {
							sum += translatePoints(p.first);
							break;
						}
				}
		}

		std::cout << sum << std::endl;
}

int translatePoints(char c) {
		int val = c - (c < 91 ? 'A' - 27 : 'a' - 1);

		return val;
}
