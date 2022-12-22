#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <stack>

using std::string;


int main() {
		std::ifstream file("data2.txt");
		std::deque<char> stacks[9];

		string line;
		for(int i = 0; i < 8; i++) {
				getline(file, line);
				int index = -1;
				for(int j = 1; j < line.length(); j += 4) {
						index++;
						if(line[j] == ' ') continue;
						stacks[index].push_back(line[j]);
				}
		}

		getline(file, line);
		getline(file, line);

		while(file.peek() != EOF) {
				getline(file, line);
				std::stringstream ss(line.substr(5));
				int amount;
				ss >> amount;
				ss >> line;
				int from;
				ss >> from;
				from--;
				ss >> line;
				int to;
				ss >> to;
				to--;

				std::stack<char> move;
				for(int i = 0; i < amount; i++) {
						move.push(stacks[from].front());
						stacks[from].pop_front();
				}

				while(!move.empty()) {
						stacks[to].push_front(move.top());
						move.pop();
				}
				//for(int i = 0; i < amount; i++) {
				//		stacks[to].push_front(stacks[from].front());
				//		stacks[from].pop_front();
				//}
		}

		for(int i = 0; i < 9; i++) {
				if(!stacks[i].empty()) std::cout << stacks[i].front();
		}
}
