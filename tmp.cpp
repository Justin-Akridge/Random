#include <iostream>

int main() {
  char curr = 'A';
  char end = 'Z';
  for (char i = curr; i <= end; i++)  
    std::cout << i << " " << static_cast<int>(i) << std::endl;
  curr = 'a';
  end = 'z';
  for (char i = curr; i <= end; i++)  
    std::cout << i << " " << static_cast<int>(i) << std::endl;
}
