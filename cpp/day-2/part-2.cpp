#include <stdlib.h>

#include <map>
#include <regex>
#include <string>

#include "findall.hpp"
#include "iostream"
#include "read.hpp"

using namespace std;

static int find_most(const vector<string>& matches, map<char, int>& most) {
  auto value{0};
  char color;

  for (const string& match : matches) {
    value = stoi(match.substr(0, match.find(' ')));
    color = match.back();
    most[color] = most[color] < value ? value : most[color];
  }

  return most['g'] * most['b'] * most['r'];
}

auto main() -> int {
  auto lines = read("./input/day-2.txt"s);
  regex pattern("(?:\\d{1,2}) (?:r|g|b)");
  map<char, int> most{{'r', 0}, {'g', 0}, {'b', 0}};
  vector<string> matches{};
  auto sum{0};

  for (auto& line : lines) {
    matches = findall(line, pattern);
    sum += find_most(matches, most);
    most['g'] = 0;
    most['r'] = 0;
    most['b'] = 0;
  }
  cout << sum << endl;

  return EXIT_SUCCESS;
}