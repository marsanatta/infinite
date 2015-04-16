#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>



bool checkNonDecr(int *seq, int len){
  int i;
  for(i = 0; i < len; i++){
    if(i == len-1)
      return true;
    else if(seq[i] > seq[i+1])
      return false;
  }
}

int findLastMax(int *seq, int len){
  int max = INT_MIN;
  int maxIdx;
  int i;
  //find max value of sequence
  for(i = 0; i < len; i++){
    if(seq[i] >  max){
      max = seq[i];
      maxIdx = i;
    }
  }
  //find the last maximum value (circular)
  for(i = maxIdx; ;i++){
    int maxNext;
    if(maxIdx+1 >= len)
      maxNext = 0;
    else
      maxNext = maxIdx+1;
    if(seq[maxNext] == max)
      maxIdx = maxNext;
    else
      break;
  }
  return maxIdx;
}

int main() {
  int seqLen;
  int *seq, *newSeq;
  int i, j;
  int step;
  int maxIdx;
  //read input sequence
  scanf("%d", &seqLen);
  seq = (int*)malloc(seqLen * sizeof(int));
  newSeq = (int*)malloc(seqLen * sizeof(int));
  for(i = 0; i < seqLen; i++){
    scanf("%d", &seq[i]);
  }

  //first check
  if(checkNonDecr(seq, seqLen)){
    printf("0");
    return 0;
  }
  //find max
  maxIdx = findLastMax(seq, seqLen);
  for(i = 0; i < seqLen - (maxIdx+1); i++){
    newSeq[i] = seq[i + maxIdx + 1];
  }
  if((maxIdx+1) == seqLen)
    i = 0;
  for(j = 0; j < maxIdx+1; i++, j++){
    newSeq[i] = seq[j];
  }

  if(!checkNonDecr(newSeq, seqLen)){
    printf("-1");
  }
  else{
    printf("%d", seqLen - (maxIdx+1));
  }
  return 0;
}
