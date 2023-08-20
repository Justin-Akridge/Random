#include <iostream>

class clockType {
public:
  void get_time(int& hour, int& min, int& sec) const;
  void set_time();
  void print_time();
  void increment_sec();
  void decrement_sec();
  bool equal_time(const clockType&) const;
private:
  int hour;
  int min;
  int sec;
};

int main() {
  clockType my_clock;
  clockType your_clock;
  int hour;
  int min;
  int sec;
  my_clock.set_time(3, 45, 23);
  std::cout << "My_clock: "; 
  myClock.printTime();


}

clockType::print_time() {
  std::cout << hour << ":" << min << ":" << sec << std::endl;
}

clockType::get_time() {
  std::cout << "Enter the hour: ";
  std::cin >> hour;
  std::cout << "Enter the min: ";
  std::cin >> min;
  std::cout << "Enter the sec: ";
  std::cin >> sec;
}


