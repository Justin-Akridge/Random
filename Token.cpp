#include <iostream>
#include "Token.hpp"

class Token {
public:
  char kind;
  double value;
  Token(char ch)
    :kind(ch), value(0) { }
  Token(char ch, int val)
    :kind(ch), value(val) { }
};

Token get_token() {
  char ch;
  std::cin >> ch;
  switch (ch) {
    case '(': case ')': case '+': case '-': case '*': case '/':
    {
      return Token(ch);
    }
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
      std::cin.putback(ch);
      double val; std::cin >> val;
      return Token('8', val);
    }
    default:
      error("bad token");
  }
}

