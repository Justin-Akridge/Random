#include <iostream>


Token get_token();
double expression() {
  double left = expression();
  Token t = get_token();
  switch(t.kind) {
    case '+':
      return left + expression();
    case '-':
      return left - expression();
    default:
      return expression();
  }
}
double term();
double primary();


int main() {
}
