#include <iostream>
#include <string>

int main() {
  int num;
  std::cout << "Pick a number 1 - 100: ";
  std::cin >> num;

  int left = 0;
  int right = 100;
  char ans; 
  while (left < right) {
    int curr = (left + right) / 2;
    std::cout << "I choose " << curr << std::endl;
    std::cout << "Is your num greater then or less then this number: l/g: ";
    std::cin >> ans;
    if (ans == 'g') {
      left = curr + 1;
    } else if (ans == 'l') {
      right = curr - 1;
    } else {
      std::cout << curr << " is the correct guess!\n";
      break;
    }
  }
}
