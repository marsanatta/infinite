#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
  
  char *args[] = {NULL};
  cout << "i'm calling other process right now!!! :)" << endl;
  execv("hello", args);
  cout << "still here?" << endl;
}
