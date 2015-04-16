#include "HandleCallBehavior.h"
#include "Employee.h"
#include "Call.h"

Employee* HandleCallBehavior::escalateCall(Call &c) {
  
  if (boss != NULL) {
    return boss->getHandleCall()->handleCall(c);
  }
  return NULL;
}


