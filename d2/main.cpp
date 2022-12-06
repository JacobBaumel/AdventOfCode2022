#include <fstream>
#include <string>
#include <iostream>

using std::string;

int getMatchPoints(char, char);
int getMatchPoints2(char, char);

int main() {
		std::ifstream file("data.txt");
		string line;
		int points = 0;

		while(getline(file, line)) {
				int dpoints = getMatchPoints2(line[0], line[2]);
				points += dpoints;
		}

		std::cout << "Total points: " << points << std::endl;
}

int getMatchPoints(char e, char p) {
		int matchPoints = p - 'W';
		if(p == e + 23) matchPoints+= 3;
		else if(p == 'Z' && e == 'A') {}
		else if(p > e + 23 || (p == 'X' && e == 'C')) matchPoints += 6;

		return matchPoints;
}

int getMatchPoints2(char e, char p) {
		if(p == 'Y') p = e + 23;
		else if(p == 'X') {
				p = e + 22;
				if(p == 'W') p = 'Z';
		}
		else {
				p = e + 24;
				if(p == 'Z' + 1) p = 'X';
		}

		return getMatchPoints(e, p);
}
