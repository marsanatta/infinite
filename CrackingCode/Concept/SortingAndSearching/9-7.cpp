#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define MAX_N 100

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::max;

struct Person {
  int w;
  int h;
};

Person randomGeneratePerson() {
  Person newP;
  newP.h = 150 + rand() % 51;
  newP.w = 50 + rand() % 51;
  return newP;
}
int d[MAX_N];
int pos[MAX_N];
Person p[MAX_N];

bool cmp(Person p1, Person p2) {
  if (p1.h == p2.h) {
    return p1.w < p2.w;
  }
  return p1.h < p2.h;
}

int lis(Person p[], int n) {
  int k = 1;
  d[0] = p[0].w;
  for (int i = 1; i < n; i++) {
    if (p[i].w > d[k-1]) { 
      pos[i] = k;
      d[k++] = p[i].w;
    }
    else {
      int j;
      for (j = k - 1; j >= 0 && d[j] >= p[i].w; j--);
      d[j+1] = p[i].w;
      pos[i] = j+1;
    }
  }
  return k;
}

void printPerson(Person p) {
  cout << "weight:" << p.w;
  cout << " height:" << p.h << endl;
  
}

int lisLens[MAX_N];
int prev[MAX_N];
int dplis(Person p[], int n) {
  for (int i = 0; i < n; i++) {
    lisLens[i] = 1;
    prev[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (p[i].w < p[j].w) {
        if (lisLens[j] < lisLens[i] + 1) {
          lisLens[j] = lisLens[i] + 1;
          prev[j] = i;
        }
      }
    }
  }

  int lisLen = 0;
  int lisPos = 0;
  for (int i = 0; i < n; i++) {
    if (lisLens[i] > lisLen) {
      lisLen = lisLens[i];
      lisPos = i;
    }
  }
  cout << "dp result:" << endl;

  int i = lisPos;
  for (; prev[i] != -1; i = prev[i]) {
      printPerson(p[i]);
  }
  printPerson(p[i]);

  return lisLen;
}


void printPersons(int n) {
  for (int i = 0; i < n; i++) {
    cout << "weight:" << p[i].w;
    cout << " height:" << p[i].h << endl;
  }
}

void printLIS(int n, int len) {
  int next = len - 1;
  int i = n - 1;
  while(next >= 0) {
    while(pos[i] != next)
      i--;
    printPerson(p[i]);
    next--;
  }
  
}

int main() {

  //init
  int n;
  cin >> n;
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    p[i] = randomGeneratePerson();
  }
  /*for (int i = 0; i < n; i++) {
    cin >> p[i].h >> p[i].w;
  }*/
  sort(p, p+n, cmp);
  printPersons(n);
  int len = lis(p, n);
  cout << "nlogn method:" << len << endl;
  cout << "dp method: " << dplis(p, n) << endl;
  for (int i = 0; i < n; i++) {
    cout << "pos:" << pos[i] << endl;
  }
  printLIS(n, len);


  return 0;
}
