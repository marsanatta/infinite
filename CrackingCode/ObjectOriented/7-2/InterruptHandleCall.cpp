#include <iostream>
#include "InterruptHandleCall.h"
#include "Employee.h"

using std::cout;
using std::endl;

Employee* InterruptHandleCall::handleCall(Call &c) {
  if (c.getDifficulty() > ability) {
    cout << self->getName() << " escalate the call to " << boss->getName() << endl;
    return HandleCallBehavior::escalateCall(c);
  }
  cout << self->getName() << " handle the call" << endl;
  return self;
}
