#include "iostream"
#include "ranges"
#include "read.hpp"


auto main(int argc, char* argv[]) -> int {
  std::string filename = "./input/day-1.txt";
  std::vector<std::string> lines = read(filename);
  constexpr char ALPHA_CHAR = 0x41;
  unsigned int sum = 0;

  for (std::string& line : lines) {
    auto view =
        line | std::views::filter([](char c) { return c < ALPHA_CHAR; });
    sum += ((view.front() - '0') * 10) + (view.back() - '0');
  }

  std::cout << sum << std::endl;
  return 0;
}