#include "Token.hpp"

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

Token_stream::get() {
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
