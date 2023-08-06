#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<std::string> v;
  std::cout << "Enter 3 strings:\n";
  std::string s;
  for (int i = 0; i < 3; i++) {
    std::cin >> s;
    v.push_back(s); 
  }
  std::sort(v.begin(), v.end());
  for (auto &i : v) {
    std::cout << i << std::endl;
  }
}
