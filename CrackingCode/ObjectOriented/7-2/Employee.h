#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "HandleCallBehavior.h"

using std::string;

class Employee {

public:
  Employee(string n) {
    isFree = true;
    handleCall = NULL;
    name = string(n);
  }
  string getName() { return name; }
  bool getIsFree() { return isFree; }
  void setIsFree(bool _isFree) { isFree = _isFree; }
  void setHandleCall(HandleCallBehavior *_handleCall) {
    handleCall = _handleCall;
  }
  HandleCallBehavior* getHandleCall() {
    return handleCall;
  }
protected:
  bool isFree;
  HandleCallBehavior *handleCall;
  string name;
};

#endif
