#include <iostream>


Token get_token();

double expression() {
  double left = term();
  Token t = get_token();
  while (true) {
    switch(t.kind) {
      case '+':
        left += term();
        t = get_token();
        break;
      case '-':
        left -= term();
        t = get_token();
        break;
      default:
        return left;
  }
  return left;
}

double term() {
  double left = primary();
  Token t = get_token();  
}

double primary();


int main() {
}
