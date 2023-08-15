#include <iostream>
#include <string>

void error(std::string);
double primary();
double term();
double expression();

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
          return Token(ch);
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

int main() {
  try {
    while (std::cin)
      std::cout << expression() << std::endl;
    throw 20;
  }
  catch(int e) {
    std::cerr << e << '\n';
    return 1;
  }
  catch(...) {
    std::cerr << "exception" << std::endl;
    return 2;
  }
}

void error(std::string s) {
  std::cerr << s << std::endl;
}

double expression() {
  double left = term();
  Token t = get_token();
  while (true) {
    switch(t.kind) {
      case '+':
        return left += term();
      case '-':
        return left -= term();
      default:
        return term();
    } 
  }
  return left;
}

double term() {
  double left = primary();
  Token t = get_token();
  while (true) {
    switch(t.kind) {
      case '*':
        {
          left *= primary();
          t = get_token();
          break;
        }
      case '/':
        {
          double d = primary();
          if (d == 0) error("Cannot divide by 0");
          left /= primary();
          t = get_token();
          break;
        }
      default:
        return left;
    }
  }
  return left;
}

double primary() {
  Token t = get_token();
  switch(t.kind) {
    case '(':
    {
      double d = expression();
      t = get_token();
      if (t.kind != ')') error("Expected ')'");
      return d;
    }
    case '8':
      return t.value;
    defaut:
      error("Primary expected");
  }
}
