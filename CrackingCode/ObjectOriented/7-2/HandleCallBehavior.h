#ifndef HANDLECALLBEHAVIOR_H
#define HANDLECALLBEHAVIOR_H

#include <cstddef>
#include "Call.h"

class Employee;

class HandleCallBehavior {

public:
  virtual Employee* handleCall(Call &c) = 0;
protected:
  HandleCallBehavior(Call::Difficulty _ability, Employee* _boss, Employee* _self) {
    ability = _ability;
    boss = _boss;
    self = _self;
  }
  Call::Difficulty ability;
  Employee* boss;
  Employee* self;
  Employee* escalateCall(Call &c);
};

#endif
