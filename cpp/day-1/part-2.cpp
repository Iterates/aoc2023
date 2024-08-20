#include "findall.hpp"
#include "iostream"
#include "map"
#include "read.hpp"
#include "regex"

using namespace std;

auto main(int argc, char* argv[]) -> int {
  auto filename = "./input/day-1.txt";
  auto lines = read(filename);
  auto sum{0};
  regex regex("one|two|three|four|five|six|seven|eight|nine|1|2|3|4|5|6|7|8|9");
  map<string, int> digits{{"one", 1},  {"two", 2}, {"three", 3}, {"four", 4},
                          {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8},
                          {"nine", 9}, {"1", 1},   {"2", 2},     {"3", 3},
                          {"4", 4},    {"5", 5},   {"6", 6},     {"7", 7},
                          {"8", 8},    {"9", 9}};
  size_t length;
  vector<string> matches;

  for (const string& line : lines) {
    matches = findall(line, regex);
    length = matches.capacity();
    if (length) {
      sum += digits[matches.front()] * 10 + digits[matches.back()];
    }
  }

  cout << sum << endl;

  return 0;
}