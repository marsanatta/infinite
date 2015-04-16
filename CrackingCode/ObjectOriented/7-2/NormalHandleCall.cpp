#include "NormalHandleCall.h"
#include "Employee.h"
#include <iostream>

using std::cout;
using std::endl;

Employee* NormalHandleCall::handleCall(Call &c){
    //cout << "this addr: " << this << endl;
    //cout << "self is:" << self << endl;
    if (c.getDifficulty() > ability || !self->getIsFree()) {
      cout << self->getName() << " escalate the call to " << boss->getName() << endl;
      return HandleCallBehavior::escalateCall(c);
    }
    cout << self->getName() << " handle the call" << endl;
    return self;
}

