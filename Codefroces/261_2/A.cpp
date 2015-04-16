#include <iostream>
#include <cmath>

using namespace std;

typedef struct tree{
  int x;
  int y;
}Tree;

bool findTree(Tree* trees){
  Tree t1 = trees[0];
  Tree t2 = trees[1];
  
  if(t1.x != t2.x && t1.y != t2.y){
  
    if(abs(t1.x - t2.x) != abs(t1.y - t2.y))
      return false;
    trees[3].x = t2.x;
    trees[3].y = t1.y;
    trees[4].x = t1.x;
    trees[4].y = t2.y;
    return true;
  }

  else if(t1.x == t2.x && t1.y != t2.y){
    int sideLen = abs(t1.y - t2.y);
    if(t1.x + sideLen <= 1000){
      trees[3].x = t1.x + sideLen;
      trees[3].y = t1.y;
      trees[4].x = t1.x + sideLen;
      trees[4].y = t2.y;
      return true;
    }
    else if(t1.x - sideLen >= -1000){
      trees[3].x = t1.x - sideLen;
      trees[3].y = t1.y;
      trees[4].x = t1.x - sideLen;
      trees[4].y = t2.y;
      return false;
    }
    else{
      return false;
    }
  }

  else if (t1.x != t2.x && t1.y == t2.y) {
    int sideLen = abs(t1.x - t2.x);
    if(t1.y + sideLen <= 1000){
      trees[3].x = t1.x;
      trees[3].y = t1.y + sideLen;
      trees[4].x = t2.x;
      trees[4].y = t1.y + sideLen;
      return true;
    }
    else if(t1.y - sideLen >= -1000){
      trees[3].x = t1.x;
      trees[3].y = t1.y - sideLen;
      trees[4].x = t2.x;
      trees[4].y = t1.y - sideLen;
      return true;
    }
    else{
      return false;
    }
  }
  return false;

}

int main() {

  Tree trees[4];
  for (int i = 0; i < 2; i++) {
    cin >> trees[i].x;
    cin >> trees[i].y;
  }
  if(findTree(trees)) {
    cout << trees[3].x << " " << trees[3].y << " " << trees[4].x << " " << trees[4].y;
  }
  else{
    cout << -1;
  }
  

  return 0;
}
