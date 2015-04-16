#include "HandleCallBehavior.h"
#include "Call.h"

class InterruptHandleCall : public HandleCallBehavior {

public:
  Employee* handleCall(Call &c);
  InterruptHandleCall(Call::Difficulty _ability, Employee* _boss, Employee* _self)
  :HandleCallBehavior(_ability, _boss, _self){
  }


};
