#include <cmath>
#include <iostream>
#define EPSILON 0.000001

using namespace std;

class Line {

public:
  double slope;
  double yIntercept;

  bool isIntercept(Line l) {
    if (abs(slope - l.slope) > EPSILON || 
       abs(yIntercept - l.yIntercept) < EPSILON) {
      return true;
    }
    return false;
  }

};

int main() {

  Line l1, l2;
  cin >> l1.slope >> l1.yIntercept;
  cin >> l2.slope >> l2.yIntercept;

  cout << "L1 slope:" << l1.slope << " yIntercept:" << l1.yIntercept << endl;
  cout << "L2 slope:" << l2.slope << " yIntercept:" << l2.yIntercept << endl;
  cout << l1.isIntercept(l2) << endl;
  return 0;
}
