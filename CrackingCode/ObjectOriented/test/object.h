class Foo {

public:
  Foo() {
    bar = 10;
  }
  
  void setBar(int _bar) const{
    bar = _bar;
    bar2 = _bar;
  }

private:
  mutable int bar;
  int bar2;
};
