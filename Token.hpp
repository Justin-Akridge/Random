#pragma once
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

Token get_token();
