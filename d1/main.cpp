#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <vector>
using std::string;

int main() {
		std::ifstream file("data.txt");
		int max = 0;
		string line;
		std::vector<int> nums;

		while(file.peek() != EOF) {
				int sum = 0;
				while(getline(file, line)) {
						if(line.empty() || line[0] == '\n' || line[0] == ' ') {
							if(max < sum) {
								nums.push_back(sum);
								max = sum;
							}
							break;
						}
						sum += std::stoi(line);
				}
		}

		file.close();
		std::cout << "Max was " << max << std::endl;
		for(int i : nums) std::cout << i << std::endl;
		int total = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
		std::cout << "Total max was " << total << std::endl;
}
