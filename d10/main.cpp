#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using std::string;

int main() {
  std::ifstream file("data.txt");
  std::unordered_set<int> cycles;
  cycles.insert(20);
  cycles.insert(60);
  cycles.insert(100);
  cycles.insert(140);
  cycles.insert(180);
  cycles.insert(220);

  bool pixels[6][40];

  string line;
  int cycle = 0; // Set to 1 for part 1, 0 for part 2 no idea why
  int strengths = 0;
  int x = 1;

  auto cycler = [&]() {
    cycle++;
    std::cout << cycle / 40 << " " << cycle % 40 << std::endl;
    if(cycle < 240) pixels[cycle / 40][cycle % 40] = abs(x - (cycle % 40)) <= 1;
    if (cycles.count(cycle) != 0) {
      std::cout << "Cycle: " << cycle << ", X: " << x << std::endl;
      strengths += cycle * x;
    }
  };

  while (getline(file, line)) {
    if (line.substr(0, 4) == "addx") {
      cycler();
      int val = std::stoi(line.substr(5, line.length()));
      x += val;
    }
    cycler();
  }

  std::cout << strengths << std::endl << std::endl << std::endl << std::endl;

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 40; j++) {
      if (j % 5 == 0 && j != 0)
        std::cout << "  ";
      std::cout << (pixels[i][j] ? '#' : '.');
    }

    std::cout << std::endl;
  }
}
