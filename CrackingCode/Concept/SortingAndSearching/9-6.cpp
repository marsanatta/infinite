#include <iostream>
#include <cstdlib>
#include <new>
#define RANGE 1000000
#define M 5
#define N 5

using namespace std;

struct Point {
  int x;
  int y;
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};

void printMatrix(int **mat) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int** generateMatrix() {
  int** mat = new int*[M];
  for (int i = 0; i < M; i++) {
    mat[i] = new int[N];
  }
  int r;
  srand(time(NULL));
  mat[0][0] = 1;
  for (int i = 1; i < N; i++) {
    r = rand() % RANGE;
    while (r <= mat[0][i-1]) {
      r = rand() % RANGE;
    }
    mat[0][i] = r;
  }
  for (int i = 1; i < M; i++) {
    r = rand() % RANGE;
    while (r <= mat[i-1][0]) {
      r = rand() % RANGE;
    }
    mat[i][0] = r;
  }

  for (int i = 1; i < M; i++) {
    for (int j = 1; j < N; j++) {
      r = rand() % RANGE;
      while (r <= mat[i][j-1] || r <= mat[i-1][j]) {
        r = rand() % RANGE;
      }
      mat[i][j] = r;
    }
  }

  return mat;
}

Point* search(int **mat, int const &find) {
  int i = 0;
  int j = N - 1;
  while (i < M && j >= 0) {
    if (mat[i][j] == find) {
      return new Point(j, i);
    }
    else if (mat[i][j] > find) {
      j--;
    }
    else {
      i++;
    }
    cout << "i:" << i << " j:" << j << endl;
  }
  return NULL;
}


int main() {

  int **mat = generateMatrix();
  printMatrix(mat);

  int find;
  cout << "Enter the number you want to search:";
  while (true) {
    cin >> find;
    Point *fp = search(mat, find);
    if (fp != NULL) {
      cout << "col:" << fp->x << " row:" << fp->y << endl;
    }
    else 
      cout << "Not found" << endl;
  }
  
  return 0;
}
