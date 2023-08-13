#include <iostream>
#include <string>

void error(std::string s);
double primary();
double term();
double expression();

class Token {
public:
  char kind;
  double value;
  Token(char ch)
    :kind(ch), value(0) { }
  Token(char ch, double val)
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
    case '5': case '6': case '7': case '8': case '9': {
      std::cin.putback(ch);
      double val;
      std::cin >> val;
      return Token('8', val);
    }
    default:
      error("Bad token");
  }
}

void error(std::string s) {
  std::cerr << s << std::endl;
}

double primary() {
  Token t = get_token();
  switch (t.kind) {
  case '(': {
    double d = expression();
    t = get_token();
    if (t.kind != ')') error("')' expected");
    return d;
  }
  case '8':
    return t.value;
  default:
    error("primary expected");
  }
}

double term() {
  double left = primary();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/': {
      double d = primary();
      if (d == 0) error("divide by zero");
      left /= d;
      t = ts.get();
      break;
    }
    default:
      ts.put_back(t);
      return left;
    }
  }
}

double expression() {
  double left = term();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '+':
      left += term();
      t = ts.get();
      break;
    case '-':
      left -= term();
      t = ts.get();
      break;
    default:
      ts.put_back(t);
      return left;
    }
  }
}

int main() {
  try {
    while (std::cin)
      std::cout << expression() << '\n';
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
      return 1;
  }
  catch (...) {
    std::cerr << "exception \n";
      return 2;
  }
}
