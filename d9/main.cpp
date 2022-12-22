#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

struct knot {
  int x;
  int y;

  knot() {
    x = 0;
    y = 0;
  }

  knot(int x, int y) : x(x), y(y){};

  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }

  bool operator<<(const knot &other) {
    return abs(other.x - x) >= 2 || abs(other.y - y) >= 2;
  }

  void operator>>(const knot &other) {
    if (abs(other.x - x) >= 2) {
      if (other.x > x)
        x++;
      else
        x--;

      if (abs(other.y - y) >= 1) {
        if (other.y > y)
          y++;
        else
          y--;
      }
    }

    if (abs(other.y - y) >= 2) {
      if (other.y > y)
        y++;
      else
        y--;

      if (abs(other.x - x) >= 1) {
        if (other.x > x)
          x++;
        else
          x--;
      }
    }
  }
};

int main() {
  std::unordered_map<int, std::unordered_map<int, bool>> places;
  std::ifstream file("data.txt");
  string line;

  knot head{0, 0};
  knot tail{0, 0};
  places[0][0] = true;

  std::unordered_map<int, std::unordered_map<int, bool>> places2;
  places2[0][0] = true;
  knot knots[10];

  while (getline(file, line)) {
    int dx;
    int dy;
    int count = std::stoi(line.substr(2, line.length()));

    switch (line[0]) {
    case 'R':
      dx = 1;
      dy = 0;
      break;

    case 'L':
      dx = -1;
      dy = 0;
      break;

    case 'U':
      dx = 0;
      dy = -1;
      break;

    case 'D':
      dx = 0;
      dy = 1;
      break;

    default:
      std::cout << "UAWTFBHIEGYU" << std::endl;
    }

    for (int i = 0; i < count; i++) {
      head.move(dx, dy);
      if (head << tail) {
        tail >> head;
        places[tail.x][tail.y] = true;
      }

      knots[0].move(dx, dy);
      for (int i = 1; i < 10; i++) {
        if (knots[i] << knots[i - 1]) {
          knots[i] >> knots[i - 1];
        }
      }

      places2[knots[9].x][knots[9].y] = true;
    }
  }

  int total = 0;

  for (std::pair<const int, std::unordered_map<int, bool>> &i : places) {
    for (auto &j : i.second) {
      total++;
    }
  }

  int total2 = 0;
  for (std::pair<const int, std::unordered_map<int, bool>> &i : places2) {
    for (auto &j : i.second) {
      total2++;
    }
  }

  std::cout << "Length 2: " << total << std::endl
            << "Length 10: " << total2 << std::endl;
}