#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string s = ' ';
  for (int i = 0; i < s.size(); i++) {
    if (isspace(s[i])) {
      std::cout << "It is a space" << std::endl;
    }
  }
}
