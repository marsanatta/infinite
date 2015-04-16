#include <iostream>
#include <cmath>
//#define N 4

using namespace std;

int N;
int solutions = 0;

struct ColForRow {
  int *arr;
};


bool check(int row, ColForRow &colForRow) {
  for (int i = 0; i < row; i++) {
    //cout << "colForRow[" << i << "]" << colForRow.arr[i] << endl;
    //cout << "colForRow[" << row << "]" << colForRow.arr[row] << endl;
    int diff = abs(colForRow.arr[i] - colForRow.arr[row]);
    if (diff == 0 || diff == row - i) {
      //cout << "false" << endl;
      return false;
    }
  }
  //cout << "true" << endl;
  return true;
}

void printBoard(ColForRow &colForRow) {

  for (int i = 0; i < N; i++) {
    if (colForRow.arr[i] == -1) {
      return;
    }
  }

  cout << "board:" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (colForRow.arr[i] == j) {
        cout << "1";
      }
      else {
        cout << "0";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void placeQueen(int row, ColForRow colForRow) {
  if (row == N) {
    printBoard(colForRow);
    solutions++;
    return;
  }
  for (int i = 0; i < N; i++) {
    colForRow.arr[row] = i;
    if (check(row, colForRow)) {
      cout << "put Queen at row:" << row << "col:" << i << endl;
      placeQueen(row+1, colForRow);
    }
  }
}

int main() {

  cin >> N;
  
  ColForRow colForRow;
  colForRow.arr = new int[N];
  for (int i = 0; i < N; i++) {
    colForRow.arr[i] = -1;
  }
  placeQueen(0, colForRow);
  cout << "solutions: " << solutions << endl;
  return 0;
}
