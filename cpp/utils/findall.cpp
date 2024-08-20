#include "algorithm"
#include "regex"
#include "string"
#include "vector"

using namespace std;

auto findall(const string& str, const regex& regex) -> vector<string> {
  auto words_begin = sregex_iterator(str.begin(), str.end(), regex);
  auto words_end = sregex_iterator();
  vector<string> matches{};

  for_each(words_begin, words_end,
           [&matches](const auto& match) { matches.push_back(match.str()); });

  return matches;
}
