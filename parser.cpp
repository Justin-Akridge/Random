#include <iostream>
#include <string>
using namespace std;


void error(string &s) {
  std::cerr << s << std::endl;
}

int main() {
    cout << "Please enter expression: ";
    int lval = 0;
    int rval;
    int res;
    cin >> lval 
    if (!cin) error ("no first operand");
    for (char op; cin >> op) {
    if (op != 'x') cin >> rval;
    if (!cin) error ("no second operand");
    switch(op) {
      case '+':
        lval += rval;
        break;
      case '-':
        lval -= rval;
        break;
      case '*':
        lval *= rval;
        break;
      case '/':
        lval /= rval;
        break;
      default:
        cout << "RESULT = "
    }

    cout << "RESULT: " << res << '\n';
    return 0;
}
