class MyClass {
private:
  int val;
public:
  MyClass (int _val) {
    val = _val;
  }
};

int main() {

  int v = 1;
  MyClass mc = v;

  return 0;
}
