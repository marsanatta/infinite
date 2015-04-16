#include <vector>
#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Employee.h"
#include "Call.h"
#include "NormalHandleCall.h"
#include "InterruptHandleCall.h"
#include "Fresher.h"
#include "ProjectManager.h"
#include "TechLeader.h"

using namespace std;

vector<Fresher> freshers;

Employee* getCallHandler(Call &c) {
  for (vector<Fresher>::iterator it = freshers.begin(); it != freshers.end(); it++) {
    if ((*it).getIsFree()) {
      return (*it).getHandleCall()->handleCall(c);
    }
  }
  cout << "all freshers are busy" << endl;
  return TechLeader::getInstance()->getHandleCall()->handleCall(c);
}

int main() {

  //Employee fresher("Freddy");
  //Employee tl("Tom");
  //Employee pm("Parker");
  //fresher.setHandleCall(new NormalHandleCall(Call::EASY, &tl, &fresher));
  //tl.setHandleCall(new NormalHandleCall(Call::NORMAL, &pm, &tl));
  //pm.setHandleCall(new InterruptHandleCall(Call::HARD, NULL, &pm));
  int n;
  cout << "Enter number of freshers:" << endl;
  cin >> n;
  srand(time(NULL));
  for (int i = 1; i <= n; i++) {
    stringstream ss;
    ss << i;
    string newName = "Fresher" + ss.str();
    Fresher *newFresher = new Fresher(newName, ProjectManager::getInstance(), TechLeader::getInstance());
    newFresher->setIsFree((bool)(rand()%2));
    freshers.push_back(*newFresher);
  }
  /*for (int i = 0; i < freshers.size(); i++) {
    cout << "fresher addr: " << &freshers.at(i) << endl;
  }*/
  
  TechLeader::getInstance()->setPM(ProjectManager::getInstance());
  Call call(Call::EASY);

  //TechLeader::getInstance()->setIsFree(false);
  //pm.setIsFree(false);
  
  getCallHandler(call);
  //fresher.getHandleCall()->handleCall(normalCall);

  return 0;
}
