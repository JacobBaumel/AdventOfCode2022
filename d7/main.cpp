#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>

using std::string;

int pathTotal(const string& path, std::map<string, int>& files, std::map<string, std::vector<string>>& paths) {
		int total = files[path];

		for(string& s : paths[path]) total += pathTotal(s, files, paths);

		return total;
}

int main() {
	std::ifstream file("data.txt");
	std::map<string, int> files;
	std::map<string, std::vector<string>> paths;
	string line;
	string path;
	getline(file, line);

	while(getline(file, line)) {
			if(line[0] == '$') {
					if(line[2] == 'c') {
							if(line[5] == '.') path = path.substr(0, path.find_last_of('/'));
							else path += '/' + line.substr(5);
					}
			}

			else if(line[0] == 'd') {
					paths[path].push_back(path + "/" + line.substr(4));
			}

			else files[path] += std::stoi(line.substr(0, line.find_first_of(' ')));
	}

	int neededSize = 30000000 - (70000000 - pathTotal("", files, paths));

	unsigned int smallest = 0xffffffff;

	int total = 0;
	for(auto& [key, value] : files) {
			int n = pathTotal(key, files, paths);
			if(n <= 100000) total += n; 
			if(n < smallest && n >= neededSize) smallest = n;
	}

	std::cout << total << std::endl << smallest << std::endl;
	
	
}
