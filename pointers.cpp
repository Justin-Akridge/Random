#include <iostream>


int add(int *p, int list[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += list[i];
  } 
  return sum;
}

void multiply(int* &p, int* &x) {
  std::cout << *&p << '\n' << &p << std::endl;
}

int main() {
  int **board;
  *board = new int [10];
  std::cout << &board << '\n';
  for (int i = 0; i < 10; i++) {
    board[i] = new int [10];
    for (int j = 0; j < 10; j++) {
      board[i][j] = j;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}
