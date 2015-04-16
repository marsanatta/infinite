#ifndef FRESHER_H_
#define FRESHER_H_

#include <string>
#include "Employee.h"
#include "Call.h"
#include "ProjectManager.h"
#include "TechLeader.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Fresher : public Employee{

public:
  Fresher(string _name, ProjectManager *_pm, TechLeader *_tl)
  : Employee(_name){
    handleCall = new NormalHandleCall(Call::EASY, (Employee*)_tl, (Employee*)this);
    
    pm = _pm;
    tl = _tl;
  }
private:
  ProjectManager *pm;
  TechLeader *tl;
};

#endif
