#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> maxSubArray(const vector<int> &nums) {
    const int len = nums.size();
    int f[len];
    f[0] = nums[0];
    int maxSum = nums[0];
    vector<int> out;
    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < len; i++) {
        f[i] = max(f[i - 1] + nums[i], nums[i]);
        if (f[i - 1] + nums[i] < nums[i]) {
            f[i] = nums[i];
            temp.clear();
            temp.push_back(nums[i]);
        }
        else {
            f[i] = nums[i] + f[i - 1];
            temp.push_back(nums[i]);
        }
        if (f[i] > maxSum) {
            maxSum = f[i];
            out.clear();
            out = temp;
        }
    }
    return out;
}

int main(int argc, const char *argv[])
{
    vector<int> in{-2,2,-3,4,-1,2,1,-5,3};
    vector<int> out = maxSubArray(in);
    //std::cout << maxSubArray(in) << std::endl;
    std::cout << "maximum subarray is:" << std::endl;
    for (auto &n : out) {
        std::cout << n << std::endl;
    }
    return 0;
}

