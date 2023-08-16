
class Token_stream {
public: 
  Token_stream();
  Token get();
  void putback(Token t);
private:
  bool full;
  Token buffer
};

Token_stream::Token_stream()
  :full(false), buffer(0) { }

Token_stream::get();
