#include <iostream>
#include <vector>
#include <limits>

int main() {
  std::vector<double> v;
  double num;
  while (std::cin >> num) {
    v.push_back(num); 
  }
  double total_distance = 0;
  double smallest_dis = std::numeric_limits<double>::max();
  double greatest_dis = std::numeric_limits<double>::min();
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > greatest_dis) 
      greatest_dis = v[i];
    else if (v[i] < smallest_dis)
      smallest_dis = v[i];
    total_distance += v[i];
  }
  std::cout << "The mean distance is = " << total_distance / v.size() << ".\n";
  std::cout << "The greatest distance is = " << greatest_dis << ".\n";
  std::cout << "The smallest distance is = " << smallest_dis << ".\n";
}
