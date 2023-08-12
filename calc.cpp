#include <iostream>

class Token {
public:
  char kind;
  double value;
  Token(char ch)
    :kind(ch), value(0) {}
  Token(char ch, double val)
    :kind(ch), value(val) {}
};

void error(std::string s) {
  std::cerr << s << std::endl;
}

double expression() {
  double left = expression();
  Token t = get_token();
  while (t.kind == '+' || t.kind == '-') {
    if (t.kind == '+') {
      left += term();
    } else {
        left -= term();
      t = get_token();
    }
  }
  return left;
}

double primary() {
  Token t = get_token();
  switch(t.kind) {
    case '(':
      double d = expression();
      t = get_token();
      if (t.kind != ')') error("Epected ')'");
      return d;
    case '8':
      return t.value;
    defaut:
      error("Primary expected");
  }
}

double term() {
  double left = primary();
  Token t = get_token();
  while (true) {
    switch(t.kind) {
      case '*':
        left *= primary();
        t = get_token();
        break;
      case '/':
        double d = primary();
        if (d == 0) error("This is an invalid response");
        left /= primary();
        t = get_token();
        break;
      default:
        return left;
    }
  }
  return left;
}

int main() {
  try {
    while (cin)
      std::cout << expression() << std::endl;
  }
  catch(exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch(...) {
    std::cerr << "exception" << std::endl;
    return 2;
  }
}
