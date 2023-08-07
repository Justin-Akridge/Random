#include <iostream>
#include <string>
#include <cctype>

int main() {
  while (true) {
    std::cout << "Enter a operand: ";
    char oper;
    std::cin >> oper;
    if (oper == '+' || oper == '-'|| oper == '*' || oper == '/') {
      int val1, val2;
      std::cout << "Enter the two integers: ";
      std::cin >> val1 >> val2;
      switch(oper) {
        case '+':
          std::cout << val1 + val2 << std::endl;
          break;
        case '-':
          std::cout << val1 - val2 << std::endl;
          break;
        case '*':
          std::cout << val1 * val2 << std::endl;
          break;
        case '/':
          std::cout << val1 / val2 << std::endl;
          break;
      }
      break;
    } else {
      std::cout << "Invalid, Enter proper operand.\n";
    }
  }
}
