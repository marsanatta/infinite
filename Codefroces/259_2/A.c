#include <stdio.h>

int main(int argc, char *argv[]){
  int i, a, b, c;
  char crystalSizeStr[128];
  unsigned int crystalSize;
  //int crystalChange = 2;
  int numOtherCell;
  int numCrystalCell;
  //read input
  fgets(crystalSizeStr, 4, stdin);
  crystalSize = (unsigned int)atoi(crystalSizeStr);
  //print crystal
  for(i = 1; i <= crystalSize; i++){
    //calculate cell number
    if(i <= (crystalSize+1)/2){
      numCrystalCell = 2*i - 1;
    }
    else{
      int reverseI = crystalSize - i + 1;
      numCrystalCell = 2*reverseI - 1;
    }
    numOtherCell = crystalSize - numCrystalCell;
    //print a line
    for(a = 0; a < numOtherCell/2; a++)
      printf("*");
    for(b = 0; b < numCrystalCell; b++)
      printf("D");
    for(c = 0; c < numOtherCell/2; c++)
      printf("*");
    printf("\n");
  }


  return 0;
}
