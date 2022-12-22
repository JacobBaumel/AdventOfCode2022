#include <fstream>
#include <iostream>
#include <string>

#define LENGTH 99

using std::string;

int main() {
  std::ifstream file("data.txt");
  int vals[LENGTH][LENGTH];
  bool used[LENGTH][LENGTH];
  string line;
  for (int i = 0; i < LENGTH; i++) {
    for (int j = 0; j < LENGTH; j++) {
      used[i][j] = false;
    }
  }

  int pos = 0;
  while (getline(file, line)) {
    for (int i = 0; i < line.length(); i++) {
      vals[pos][i] = std::stoi(line.substr(i, 1));
    }
    pos++;
  }

  int trees = 0;
  for (int i = 0; i < LENGTH; i++) {
    int left = -1;
    int down = -1;
    int right = -1;
    int up = -1;
    for (int j = 0; j < LENGTH; j++) {
      if (vals[i][j] > left) {
        left = vals[i][j];
        if (!used[i][j]) {
          trees++;
          used[i][j] = true;
        }
      }

      if (vals[j][i] > down) {
        down = vals[j][i];
        if (!used[j][i]) {
          trees++;
          used[j][i] = true;
        }
      }

      if (vals[LENGTH - 1 - i][LENGTH - j - 1] > right) {
        right = vals[LENGTH - 1 - i][LENGTH - j - 1];
        if (!used[LENGTH - 1 - i][LENGTH - 1 - j]) {
          trees++;
          used[LENGTH - 1 - i][LENGTH - 1 - j] = true;
        }
      }

      if (vals[LENGTH - 1 - j][LENGTH - 1 - i] > up) {
        up = vals[LENGTH - 1 - j][LENGTH - 1 - i];
        if (!used[LENGTH - 1 - j][LENGTH - 1 - i]) {
          trees++;
          used[LENGTH - 1 - j][LENGTH - 1 - i] = true;
        }
      }
    }
  }

  std::cout << "Visible trees: " << trees << std::endl;

  int maxDistance = 0;

  for (int i = 1; i < LENGTH - 1; i++) {
    for (int j = 1; j < LENGTH - 1; j++) {
      int currsize = vals[i][j];
      int left = 0;
      int right = 0;
      int up = 0;
      int down = 0;

      for (int k = j - 1; k >= 0; k--) {
        left++;
        if (vals[i][k] >= currsize)
          break;
      }

      for (int k = j + 1; k < LENGTH; k++) {
        right++;
        if (vals[i][k] >= currsize)
          break;
      }

      for (int k = i - 1; k >= 0; k--) {
        up++;
        if (vals[k][j] >= currsize)
          break;
      }

      for (int k = i + 1; k < LENGTH; k++) {
        down++;
        if (vals[k][j] >= currsize)
          break;
      }

      int multiplier = down * up * left * right;
      if (multiplier > maxDistance)
        maxDistance = multiplier;
    }
  }

  std::cout << maxDistance << std::endl;
}