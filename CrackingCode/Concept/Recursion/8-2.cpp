#include <iostream>
#include <cstdlib>
#define N 5

using namespace std;

struct Point{
  int x;
  int y;
};

bool canGoMap[N][N];
Point path[N-1 + N-1];

void printPath(Point current, int pathLen) {

  if (current.x >= N || current.y >= N) {
    return;
  }
  if (!canGoMap[current.y][current.x]) {
    return;
  }
  if (current.x == N - 1 && current.y == N - 1) {
    for (int i = 0; i < pathLen; i++) {
      cout << "(" << path[i].x << "," << path[i].y << ") ";
    }
    cout << "(" << N-1 << "," << N-1 << ")" << endl;
  }
  else {
    path[pathLen] = current;
    Point right; right.x = current.x + 1; right.y = current.y;
    printPath(right, pathLen+1);
    Point bot; bot.x = current.x; bot.y = current.y + 1;
    printPath(bot, pathLen+1);
  }
}

int main() {

  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bool canGo = (bool)(rand() % 2);
      canGoMap[i][j] = canGo;
   }
  }
  canGoMap[0][0] = true;
  canGoMap[N-1][N-1] = true;

  cout << "canGoMap:" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << canGoMap[i][j] << " ";
    }
    cout << endl;
  }

  Point start; start.x = 0; start.y = 0;
  printPath(start, 0);

  return 0;
}
