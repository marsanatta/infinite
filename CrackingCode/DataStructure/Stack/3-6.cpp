#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Stack {

  vector<int*> buffer;

  void push(int value) {
    buffer.push_back(new int(value));
  }

  int* pop() {
    if (buffer.size() == 0) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    int* ret = buffer.back();
    buffer.pop_back();
    return ret;
  }

  void print() {
    cout << "print stack:" << endl;
    for (int i = buffer.size() - 1; i >= 0; i--) {
      cout << *buffer[i] << endl;
    }
    cout << endl;
  }


  bool isEmpty(){
    return buffer.size() == 0 ? true : false;
  }
};

void stackSort1(vector<int>& seq) {
  
  Stack in;
  for (int i = 0; i < seq.size(); i++) {
    in.push(seq[i]);
  }
  seq.clear();
  while(!in.isEmpty()) {
    //pop all find minimum
    int *min = new int(INT_MAX);
    vector<int*> buf;
    while(!in.isEmpty()){
      int* temp = in.pop();
      if (*temp < *min) {
        min = temp;
      }
      buf.push_back(temp);
    }
    //push min to seq and rest to in
    for (int i = 0; i < buf.size(); i++) {
      if (buf[i] == min) {
        seq.push_back(*buf[i]);
      }
      else {
        in.push(*buf[i]);
      }
    }
  }
}

void stackSort2(vector<int> &seq) {
  Stack in;
  for (int i = 0; i < seq.size(); i++) {
    in.push(seq[i]);
  }
  seq.clear();

  while(!in.isEmpty()) {
    int* temp = in.pop();
    while(seq.size() >= 0 && seq.back() > *temp) {
      int p = seq.back();
      seq.pop_back();
      in.push(p);
    }
    seq.push_back(*temp);
  }
}

int main() {

  int n;
  vector<int> input;
  //get size of input array
  cin >> n;
  //generating input
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    input.push_back(1+rand()%100);
  }
  //print input
  cout << "input: " << endl;
  for (int i = 0; i < n; i++) {
    cout << input[i] << endl;
  }
  cout << endl;
  //sort input
  stackSort2(input);
  cout << "sorted: " << endl;
  for (int i = 0; i < n; i++) {
    cout << input[i] << endl;
  }
  cout << endl;
 


  return 0;
}
