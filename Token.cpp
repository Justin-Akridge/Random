#include <iostream>

class Token {
public:
  char kind;
  double value;
  Token(char ch)
    :kind(ch), value(0) {}
  Token(char ch, int val)
    :kind(ch), value(val) {}
  Token get_token() {
    return Token;
  }
};

int main() {
  Token t1;
  t1.kind = '8';
  t1.value = 55;
  std::cout << typeid(t1.kind).name() << " " << t1.value << std::endl;
}
