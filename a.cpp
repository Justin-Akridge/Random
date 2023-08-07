#include <iostream>
#include <cctype>

int main() {
  const double cm_per_inch = 2.54;
  int length = 1;
  char unit;
  std::cin >> length >> unit;
  switch(unit) {
    case 'i':
      std::cout << length << "in == " << cm_per_inch * length << "cm\n";
      break;
    case 'c':
      std::cout << length << "em == " << length / cm_per_inch << "in\n";
      break;
    default:
      std::cout << "Invalid Input" << std::endl;
      break;
  } 
}
