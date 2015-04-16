#include <iostream>
#include <thread>

using namespace std;

void func() {
  double dSum = 0;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 10000; j++) {
      dSum += i*j;
    }
  }
  cout << "Thread: " << dSum << endl;
}

int main() {

  thread mThread(func);
  cout << "main thread" << endl;
  
  mThread.join();

  return 0;
}
