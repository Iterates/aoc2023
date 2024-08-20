#include <fstream>

#include "string"
#include "vector"

auto read(const std::string &filename) -> std::vector<std::string> {
  std::ifstream file(filename);
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  return lines;
}