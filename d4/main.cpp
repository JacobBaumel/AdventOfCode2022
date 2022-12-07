#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;

bool overlaps(int a, int min, int max) {
		return a >= min && a <= max;
}

int main() {
		std::ifstream file("data.txt");
		int count = 0;
		int partial = 0;
		string line;
	
		while(getline(file, line)) {
				int nums[4];
				std::stringstream s(line);

				getline(s, line, '-');
				nums[0] = std::stoi(line);

				getline(s, line, ',');
				nums[1] = std::stoi(line);

				getline(s, line, '-');
				nums[2] = std::stoi(line);

				getline(s, line);
				nums[3] = std::stoi(line);

				if((nums[0] <= nums[2] && nums[1] >= nums[3]) || (nums[2] <= nums[0] && nums[3] >= nums[1])) {
					count++;
				}

				if(overlaps(nums[0], nums[2], nums[3]) || overlaps(nums[1], nums[2], nums[3]) || overlaps(nums[2], nums[0], nums[1]) || overlaps(nums[3], nums[0], nums[1]))
						partial++;
		}

		std::cout << count << std::endl;
		std::cout << partial << std::endl;
}
