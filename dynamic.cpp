#include <iostream>

class foo {
public:
  ~foo();
  void set_foo(int &);
  void fill(int);
  int* get_foo() const;
  void print(int);
private:
  int *p;
};

foo::~foo() {
  delete [] p;
}

void foo::print(int length) {
  for (int i = 0; i < length; i++) {
    std::cout <<  p[i] << '\n';  
  }
}

void foo::fill(int length) {
  for (int i = 0; i < length; i++) {
    p[i] = i;
  }
}

void foo::set_foo(int &x) {
  p = &x; 
}

int* foo::get_foo() const {
  return p;
}

int main() {
  foo f;
  int *ptr;
  ptr = new int [10];
  f.set_foo(*ptr);
  f.fill(10);
  f.print(10);
}
