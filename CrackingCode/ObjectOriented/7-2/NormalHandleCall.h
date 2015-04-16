#include "HandleCallBehavior.h"
#include "Call.h"

class NormalHandleCall : public HandleCallBehavior {

public:
  Employee* handleCall(Call &c);
  NormalHandleCall(Call::Difficulty _ability, Employee* _boss, Employee* _self)
  :HandleCallBehavior(_ability, _boss, _self){
  }

};
