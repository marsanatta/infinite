#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

int M, N;

void setRow(int** m, int idx, int value){
  for (int i = 0; i < N; i++) {
    m[idx][i] = value;
  }
}

void setCol(int** m, int idx, int value) {
  for (int i = 0; i < M; i++) {
    m[i][idx] = value;
  }
}
void printMatrix(int** m){
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

//O(M*N*(M+N))
int** setZero1(int** m){
  //create temp
  int **temp = new int*[M];
  for (int i = 0; i < M; i++) {
    temp[i] = new int[N];
  }
  //copy m to temp
  for (int i = 0; i < M; i++) {
    memcpy(temp[i], m[i], sizeof(int)*N);
  }

  //scan and set zero
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if(m[i][j] == 0){
        setRow(temp, i, 0);
        setCol(temp, j, 0);
      }
    }
  }
  return temp;
}

bool *isZeroRow;
bool *isZeroCol;
int** setZero2(int** m) {
  
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (m[i][j] == 0){
        isZeroRow[i] = true;
        isZeroCol[j] = true;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (isZeroRow[i] || isZeroCol[j])
        m[i][j] = 0;
    }
  }
  return m;
}

void genMatrixWithZero(int** m, int numZero) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      
      if (rand()%2 == 1 && numZero > 0){
        m[i][j] = 0;
        numZero--;
      }
      else
        m[i][j] = rand()%32 + 1;
    }
  }
}


int main() {

  cin >> M;
  cin >> N;
    
  //create temp
  int** m = new int*[M];
  for (int i = 0; i < M; i++) {
    m[i] = new int[N];
  }
  isZeroRow = new bool[M];
  isZeroCol = new bool[N];

  srand(time(NULL));
  int numZero = rand() % M + 1;
  genMatrixWithZero(m, numZero);
  cout << "orignal matrix: " << endl;
  printMatrix(m);
  m = setZero2(m);
  cout << endl;
  cout << "after setZero: " << endl;
  printMatrix(m);

  return 0;
}
