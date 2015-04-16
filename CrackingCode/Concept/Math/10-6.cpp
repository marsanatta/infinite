#include <iostream>
#include <cmath>
#include <map>
#define EPSILON 0.000001

  using namespace std;

  bool isEqual(double a, double b) {
    //cout << "a:" << a << " b:" << b << " abs(a - b):" << abs(a-b) << endl;
    if(abs(a - b) < EPSILON)
      return true;
    else 
      return false;
  }

  struct Point {
    double x;
    double y;
    
    Point(double _x, double _y) {
      x = _x;
      y = _y;
    }
    Point() {x = 0; y = 0;}
    bool isSame(Point p) {
      if(isEqual(p.x, x) && isEqual(p.y, y))
        return true;
      return false;
    }
  };



  class Line {

  public:
    double slope;
    double yIntercept;
    bool isVertical;

    Line (Point p1, Point p2) {
      if (!p1.isSame(p2)){
        slope = (p2.y - p1.y) / (p2.x - p1.x);
        yIntercept = p2.y - slope * p2.x;
        isVertical = false;
      }
      else {
        cout << "same point" << endl;
        isVertical = true;
        yIntercept = p1.x;
      }
    }

    bool isIntercept(Line l) {
      if (abs(slope - l.slope) > EPSILON || 
         abs(yIntercept - l.yIntercept) < EPSILON) {
        return true;
      }
      return false;
    }
    bool operator<(Line const &other) const{
      return slope < other.slope;
    }
    bool operator>(Line const &other) const{
      return slope > other.slope;
    }

  };

  Line findBestLine(Point points[], int n) {
    map<Line, int> lineCount;
    Line *bestLine = NULL;
    //cout << "d1" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        //cout << "d2" << endl;
        Line *newLine = new Line(points[i], points[j]);
        cout << "p1.x:" << points[i].x << " p1.y" << points[i].y << " p2.x" << points[j].x << " p2.y" << points[j].y << endl;
        cout << "creating new Line slope:" << newLine->slope << " yIntercept:" << newLine->yIntercept << endl;
      //cout << "d3" << endl;
      if (lineCount.count(*newLine) == 0) {
        lineCount.insert(pair<Line, int>(*newLine, 0));
        //cout << "d4" << endl;
      }
      lineCount.at(*newLine)++;
      //cout << "d5" << endl;
      if (bestLine == NULL ||
          lineCount.at(*newLine) > lineCount.at(*bestLine)) {
        bestLine = newLine;
        cout << "new best line count:" << lineCount.at(*newLine) << endl;
      }
      //cout << "d6" << endl;
    }
  }
  for (auto it = lineCount.begin(); it != lineCount.end(); it++) {
    cout << "slope:" << it->first.slope << endl;
    cout << "yIntercept:" << it->first.yIntercept << endl;
  }
  return *bestLine;
}

int main() {
  Point points[4];
  points[0] = *(new Point(1.0, 0.0));
  points[1] = *(new Point(2.0, 1.0));
  points[2] = *(new Point(0.0, -1.0));
  points[3] = *(new Point(0.0, 1.0));
  Line bestLine = findBestLine(points, 4);
  cout << "best line slope:" << bestLine.slope << " intercept:" << bestLine.yIntercept << endl;
  return 0;
}
