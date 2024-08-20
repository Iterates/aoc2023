#include <regex>

#include "findall.hpp"
#include "iostream"
#include "read.hpp"

using namespace std;

auto main() -> int {
  auto filename = "./input/day-2.txt";
  auto lines = read(filename);
  regex pattern(
      "(?:1[3-9]|[2-9]\\d) r|(?:1[4-9]|[2-9]\\d) g|(?:1[5-9]|[2-9]\\d) b");
  int sum{0};

  for (unsigned short i = 1; const auto line : lines) {
    auto matches = findall(line, pattern);
    sum = !matches.size() ? sum + i : sum;
    i++;
  };

  cout << sum << endl;

  return 0;
}