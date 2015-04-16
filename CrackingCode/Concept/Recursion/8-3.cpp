#include <iostream>
#include <set>
#include <vector>

using namespace std;


vector<set<int>> getAllSubSets(vector<int> const &parent, int len) {

  vector<set<int> > subsets;
  if (len == 1) {
    set<int> newSet;
    newSet.insert(parent.front());
    subsets.push_back(newSet);
    return subsets;
  }
  subsets = getAllSubSets(parent, len - 1);

  int numSubSets = subsets.size();
  for (int i = 0; i < numSubSets; i++) {
    set<int> subset = subsets.at(i);
    subset.insert(subset.end(), parent.at(len - 1));
    subsets.push_back(subset);
  }
  
  set<int> newSet;
  newSet.insert(parent.at(len-1));
  subsets.push_back(newSet);

  return subsets;
}

int main() {

  int n;
  cin >> n;
  vector<int> parent;
  for (int i = 0; i < n; i++) {
    parent.push_back(i+1);
  }
  vector<set<int> > subsets = getAllSubSets(parent, n);

  for (auto subset : subsets) {
    cout << "( ";
    for (auto i : subset) {
      cout << i << " ";
    }
    cout << ")" << endl;
  }


  return 0;
}
