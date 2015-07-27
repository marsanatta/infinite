#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;
void removeDup(vector<int> &nums) {
    map<int, int> m;
    for (auto &n : nums) {
        auto it = m.find(n);
        if (it == m.end()) {
            m[n] = 1;
        }
    }
    nums.clear();
    for (auto it = m.begin(); it != m.end(); it++) {
       nums.push_back(it->first);
    }
}

void printArr(const vector<int> &nums) {
    for(auto &n : nums) {
        std::cout << n << ", "; 
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[])
{
    vector<int> in{1,5,2,6,8,9,1,1,10,3,2,4,1,3,11,3};
    printArr(in);
    removeDup(in);
    printArr(in);
    return 0;
}
