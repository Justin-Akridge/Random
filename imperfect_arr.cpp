#include <iostream>

bool isNotSquare(int n);

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int arr[n];
    int i = 0;
    while (i < n) {
      std::cin >> arr[i];
      i++;
    }
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (i != j) {
          int tmp = arr[i] * arr[j];
          if (isNotSquare(tmp)) {
            std::cout << "YES" << std::endl; 
            flag= true;
            break;
          }
        }
      }
      if (flag)
        break;
    }
    if (!flag) {
      std::cout << "NO" << std::endl;
    }
  }
}

bool isNotSquare(int n) {
  for (int i = 1; i * i <= n; i++) {
    if ((n % 1 == 0) && (n / i == i)) {
      return false;
    }
  }
  return true;
}
