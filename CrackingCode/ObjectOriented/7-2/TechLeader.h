#ifndef TECHLEADER_H_
#define TECHLEADER_H_

#include <string>
#include <new>
#include "Employee.h"
#include "Call.h"
#define TECH_LEADER_NAME "Tom"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class TechLeader : public Employee{

public:

  void setPM(ProjectManager* _pm) {
    pm = _pm;
    handleCall = new NormalHandleCall(Call::NORMAL, pm, this);
  };

static TechLeader* getInstance() {
  static TechLeader *instance;
  if(instance == NULL) {
    cout << "initiating TechLeader..." << endl;
    instance = new TechLeader(TECH_LEADER_NAME);
  }
  return instance;
}

protected:
  TechLeader(string _name)
  : Employee(_name){
    pm = NULL;
  }
private:
  ProjectManager *pm;
};

#endif
