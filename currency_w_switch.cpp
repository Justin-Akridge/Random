#include <iostream>

int main() {
  int pennies;
  std::cout << "Enter number of pennies: ";
  std::cin >> pennies;
  int nickels;
  std::cout << "Enter number of nickels: ";
  std::cin >> nickels;
  int dime;
  std::cout << "Enter number of dime: ";
  std::cin >> dime;
  int quarters;
  std::cout << "Enter number of quarters: ";
  std::cin >> quarters;
  int half_dollars;
  std::cout << "Enter number of half_dollars: ";
  std::cin >> half_dollars;
  int dollar_coin;
  std::cout << "Enter number of dollar_coin: ";
  std::cin >> dollar_coin;

  std::cout << "You have " << pennies << " pennies.\n";
  std::cout << "You have " << nickels << " nickels.\n";
  std::cout << "You have " << dime << " dime.\n";
  std::cout << "You have " << quarters << " quarters.\n";
  std::cout << "You have " << half_dollars << " half_dollars.\n";
  std::cout << "You have " << dollar_coin << " dollar_coin.\n";
  //data loss in int
  double total = pennies + (nickels * 5) + (dime * 10) + (quarters * 25) + 
              (half_dollars * 50) + (dollar_coin * 100);

  std::cout << "Total value = " << total << '\n';
  std::cout << "Total value in $" << total/100 << '\n';
}
