#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long fTable[100010];
int cnt[100010];
int n;

void countA(int *a){
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
}


long long f(int pick){
  if(pick == 0){
    return 0;
  }
  if(pick == 1){
    return cnt[1];
  }
  if(fTable[pick] != -1){
    return fTable[pick];
  }
  long long way1 = (long long)pick * (long long)cnt[pick] + f(pick-2);
  long long way2 = f(pick-1);

  if(way1 > way2)
  {
    fTable[pick] = way1;
    return way1;
  }
  else if(way2 > way1){
    fTable[pick] = way2;
    return way2;
  }
  else{
    fTable[pick] = way1;
    return way1;
  }
  //return max(pick * cnt[pick] + f(a, pick-2), f(a, pick-1));

}

typedef struct comp{

  bool operator()(int a, int b){
    return (a > b);
  }
}Comp;

int main() {


  //init
  memset(cnt, 0, 100010*sizeof(int));
  memset(fTable, -1, 100010*sizeof(long long));
  //read input
  cin >> n;
  int *a;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  
  //sort
  //sort(a, a+n);
  cout << f(100000);

  return 0;
}
