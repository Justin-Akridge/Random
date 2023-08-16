#include <iostream>
#include <string>

  double primary();
  double term();
  double expression();
  void error(std::string s);

  class Token {
  public:
    char kind;
    double value;
    Token(char ch)
      :kind(ch), value(0) { }
    Token(char ch, int val)
      :kind(ch), value(val) { }
  };

  class Token_stream {
  public: 
    Token_stream();
    Token get();
    void putback(Token t);
  private:
    bool full;
    Token buffer;
  };

Token_stream::Token_stream()
  :full(false), buffer(0) { }

  Token Token_stream::get() {
    if (full) {
      full = false;
      return buffer;
    }

    char ch;
    std::cin >> ch;
    switch(ch) {
      case ',':
      case 'q':
      case '(': case ')': case '-': case '*': case '/': case '%':
        return Token(ch);
      case '.':
      case '0': case '1': case '2': case '3': case '4': 
      case '5': case '6': case '7': case '8': case '9':
      {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token('8', val);
      }
      default:
        error("bad token");
    }
  }

  void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
  }

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

  int main() {
    try {
      while (std::cin)
        std::cout << expression() << std::endl;
    }
    catch(std::exception &e) {
      std::cerr << e.what() << '\n';
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
    Token_stream ts;
    Token t = ts.get();
    while (true) {
      switch(t.kind) {
        case '+':
          left += term();
          t = ts.get();
        case '-':
          left -= term();
          t = ts.get();
        default:
          ts.putback(t);
          return left; 
      } 
    }
    return left;
  }

  double term() {
    double left = primary();
    Token_stream ts;
    Token t = ts.get();
    while (true) {
      switch(t.kind) {
        case '*':
        {
          left *= primary();
          t = ts.get();
          break;
        }
        case '/':
        {
          double d = primary();
          if (d == 0) error("Cannot divide by 0");
          left /= d;
          t = ts.get();
          break;
        }
        default:
          ts.putback(t);
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
