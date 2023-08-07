#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
// 124
int convert(int val, std::string unit) {
  if (unit == "cm")
    return val /= 100;
  else if (unit == "m") 
    return val;  
  else if (unit == "in") 
    return val /= 39.37008; 
  else if (unit == "ft") 
    return val /= 0.3048;
  return 0;
}

int main() {
  double smaller = std::numeric_limits<double>::max(); 
  double greatest = std::numeric_limits<double>::min(); 
  double val1;
  std::string unit;
  int i = 0;
  while (true) {
    if (i==0) {
      std::cout << "Enter value followed by unit: ";
    } else {
      std::cout << "Enter another value followed by unit: ";
    }
    if (std::cin >> val1 >> unit) {
      if (val1 == '|' || unit == "|") {
        break;
      }

      if (unit == "cm") {
        val1 *= 100;
      } else if (unit == "m") {
        ;
      } else if (unit == "in") {
        val1 *= 39.37008; 
      } else if (unit == "ft") {
        val1 *= 0.3048;
      } else {
        std::cout << "Invalid input\n";
        continue;
      }

      if (i==0) {
        smaller = val1;
        greatest= val1;
        std::cout << val1 << unit << " is smallest and the greatest so far!\n";
        i++;
      } else if (i != 0) {
        if (val1 > greatest) {
          greatest = val1;
          std::cout << convert(val1, unit) << unit << " is greatest so far!\n";
        } else if (val1 == greatest) {
          std::cout << convert(val1, unit) << unit << " is equal to the greatest!\n";
        } else if (val1 < smaller) {
          smaller = val1;
          std::cout << convert(val1, unit) << unit << " is smallest so far!\n";
        } else if (val1 == smaller) {
          std::cout << convert(val1, unit) << unit << " is equal to the smallest!\n";
        } else {
          std::cout << "YOU SUCK\n";
        }
      }
    } else {
      std::cin.ignore();
      std::cout << "Invalid Input\n";
      std::cout << "Val1 = " << val1 << "unit = " << unit << std::endl;
    }
  }
}
