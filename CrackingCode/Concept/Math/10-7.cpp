#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int findkth(int k) {
  if (k <= 0)
    return -1;
  queue<int> q3;
  queue<int> q5;
  queue<int> q7;
  q3.push(3);
  q5.push(5);
  q7.push(7);

  int minVal = 1;
  for (k-- ; k > 0; k--) {
    minVal = min(q3.front(), min(q5.front(), q7.front()));
      if (minVal == q7.front())
        q7.pop();
      else {
        if (minVal == q3.front()) {
          q3.pop();
          q3.push(minVal * 3);
        }
        else if (minVal == q5.front()) {
          q5.pop();
        }
        q5.push(minVal * 5);
      }
      q7.push(minVal * 7);
  }
  return minVal;
}

int main() {

  int k;
  cin >> k;
  cout << findkth(k) << endl;
  return 0;
}
