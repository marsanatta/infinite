#include <iostream>

using namespace std;

int treeHeightAtCycle[60];
int maxCycle;

int grow(int numCycle){

  if (treeHeightAtCycle[numCycle] != -1) {
    return treeHeightAtCycle[numCycle];
  }
  else{
    int treeHeight = treeHeightAtCycle[maxCycle];
    bool isDoubleGrow;
    if(maxCycle %2 == 1)
      isDoubleGrow = false;
    else
      isDoubleGrow = true;
    for(int i = maxCycle+1; i <= numCycle; i++){
      if(isDoubleGrow){
        treeHeight *= 2;
      }
      else{
        treeHeight++;
      }
      treeHeightAtCycle[i] = treeHeight;
      isDoubleGrow = !isDoubleGrow;
      //cout << "treeHeight:" << treeHeight << "at cycle:" << i << "\n";
    }
    maxCycle = numCycle;
    return treeHeight;
  }

}



int main() {

  int numTest;
  int numCycle[10];
  
  //init
  treeHeightAtCycle[0] = 1;
  for (int i = 1 ; i <= 60; i++) {
    treeHeightAtCycle[i] = -1;
  }
  maxCycle = 0;

  //read input
  cin >> numTest;
  for (int i  = 0; i < numTest; i++) {
    cin >> numCycle[i];
  }
  
  for(int i = 0; i < numTest; i++){
    cout << grow(numCycle[i]) << "\n";
  }

  return 0;
}
