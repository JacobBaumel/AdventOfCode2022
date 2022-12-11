#include <fstream>
#include <string>
#include <iostream>

using std::string;

bool allUnique(const string& s) {
		for(size_t i = 0; i < 14; i++) {
				for(size_t j = i + 1; j < 14; j++) {
						if(s[i] == s[j]) return false;
				}
		}

		return true;
}

int main() {
		std::fstream file("data.txt");
		string data = "";
		string line;

		while(getline(file, line)) data += line;

		size_t i = 14;
		for(; !allUnique(data.substr(i - 14, i)); i++) {}
		std::cout << i;
}
