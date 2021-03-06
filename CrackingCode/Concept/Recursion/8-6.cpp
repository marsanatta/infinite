#include <iostream>
#include <cstring>
#define SCREEN_SIZE 10


using namespace std;



void paintFill(int paintColor, int (&screen)[SCREEN_SIZE][SCREEN_SIZE], int x, int y) {
  if (x < 0 || x >= SCREEN_SIZE ||
      y < 0 || y >= SCREEN_SIZE) {
    return;
  }
  if (screen[y][x] == -1) {
    return;
  }
  if (screen[y][x] != paintColor) {
    screen[y][x] = paintColor;
    paintFill(paintColor, screen, x+1, y);
    paintFill(paintColor, screen, x-1, y);
    paintFill(paintColor, screen, x, y+1);
    paintFill(paintColor, screen, x, y-1);
  }
}

void printScreen(int (&screen)[SCREEN_SIZE][SCREEN_SIZE]) {
  for (int i = 0; i < SCREEN_SIZE; i++) {

    for (int j = 0; j < SCREEN_SIZE; j++) {
      cout << screen[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {

  int screen[SCREEN_SIZE][SCREEN_SIZE];
  memset(screen, 0, sizeof(int) * SCREEN_SIZE * SCREEN_SIZE);
  for (int i = 0; i < SCREEN_SIZE; i++) {
    //screen[0][i] = -1;
    //screen[SCREEN_SIZE - 1][i] = -1;
    //screen[i][0] = -1;
    //screen[i][SCREEN_SIZE - 1] = -1;
    screen[i][SCREEN_SIZE/2] = -1;
    screen[SCREEN_SIZE/2][i] = -1;
  }
  printScreen(screen);

  int color;
  int x;
  int y;
  cin >> color >> x >> y;
  paintFill(color, screen, x, y);
  printScreen(screen);


  return 0;
}
