#include <iostream>
#include <cstring>
#include <new>

#define STACK_SIZE 2
#define MAX_STACKS 3

using namespace std;

struct SetOfStacks{
  
  int** buffers[MAX_STACKS];
  int top[MAX_STACKS];
  int stackNo;

  SetOfStacks() {
    buffers[0] = new int*[STACK_SIZE];
    memset(top, -1, sizeof(int) * MAX_STACKS);
    stackNo = 0;
  }

  void push(int value) {
    if (top[stackNo] + 1 + 1 > STACK_SIZE) {
      if (stackNo+1 == MAX_STACKS) {
        cout << "Stack Overflow" << endl;
        return;
      }
      stackNo++;
      buffers[stackNo] = new int*[STACK_SIZE];
      //top[stackNo] = -1;
    }
    /*if (top[stackNo] == -1) {
      top[stackNo] = 0;
    }else {
      top[stackNo]++;
      }*/
    top[stackNo]++;
    buffers[stackNo][top[stackNo]] = new int(value);
    cout << "push " << value << endl;
    return;
  }

  int* pop() {
    if (top[stackNo] == -1) {
      if (stackNo == 0) {
        cout << "Stack Underflow" << endl;
        return NULL;
      }
      delete buffers[stackNo];
      //find next top;
      do{
        if (stackNo == 0) {
          cout << "Stack Underflow" << endl;
          return NULL;
        }
        stackNo--;
     }
      while(top[stackNo] == -1);
      int* ret = buffers[stackNo][top[stackNo]];
      /*do{
        if (stackNo == 0) {
          return NULL;
        }
        stackNo--;
        if (top[stackNo] == -1) {
          continue;
        }
        ret = buffers[stackNo][top[stackNo]];
      }while(ret == NULL);*/
      top[stackNo]--;
      return ret;
    }
    else {
      int* ret = buffers[stackNo][top[stackNo]];
      buffers[stackNo][top[stackNo]] = NULL;
      top[stackNo]--;
      return ret;
    }
  }

  int* popAt(int no){
    if (stackNo == no) {
      return pop();
    }
    if (top[no] == -1) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    int* ret = buffers[no][top[no]];
    buffers[no][top[no]] = NULL;
    top[no]--;
    return ret;
  }
};

int main() {

  SetOfStacks s;
  for (int i = 0; i < 6; i++) {
    s.push(i);
  }
  //s.popAt(0);
  s.popAt(1);
  s.popAt(1);
  for (int i = 0; i < 6; i++){
    int* ret = s.pop();
    if (ret != NULL) {
      cout << *ret << endl;
    }
  }

  return 0;

}
