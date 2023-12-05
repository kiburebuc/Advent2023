#include <iostream>
#include <cassert>
#include <fstream>

int main(int argc, char* argv[]) {
  assert((argc > 1) && "No Input File Given, Please Provide One");
  std::ifstream input(argv[1]);
  assert((input.good()) && "Unable to Open Input File. Does it Exist?");

  std::string get;
  int sum = 0;

  while(input >> get) {
    auto bit = get.begin();
    while(!isdigit(*bit))
      ++bit;

    auto eit = get.rbegin();
    while(!isdigit(*eit))
      ++eit;

    sum += (*bit - '0') * 10;
    sum += (*eit - '0');

    std::cout << sum << '\n';
  }
}
