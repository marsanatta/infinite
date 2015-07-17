#include <vector>
#include <iostream>

using namespace std;

void swap(int i, int j, vector<int> &nums) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int quickSelect(vector<int> nums, int l, int r, int k) {
    if (r - l + 1 < k)
        return -1;
    int mid = l + (r - l) / 2;
    int pivot = nums[mid];
    swap(mid, r, nums);
    int chg = l;
    for (int i = l; i <= r - 1; i++) {
        if (pivot > nums[i]) {
            swap(i, chg, nums);
            chg++;
        }
    }
    swap(chg, r, nums);
    if (chg - l + 1 == k) return nums[chg]; //Notice that l will not always be 0, so you cannot just use chg + 1 to check it
    else if (chg - l + 1 > k) return quickSelect(nums, l, chg - 1, k);
    else return quickSelect(nums, chg + 1, r, k - (chg - l + 1));
}

int main(int argc, const char *argv[])
{
    vector<int> in{3, 2, -32, 1442, 203, 37, 874, 2, 193, 34};
    std::cout << quickSelect(in, 0, in.size() - 1, 1) << std::endl;
    std::cout << quickSelect(in, 0, in.size() - 1, 2) << std::endl;
    std::cout << quickSelect(in, 0, in.size() - 1, 3) << std::endl;
    std::cout << quickSelect(in, 0, in.size() - 1, 5) << std::endl;
    std::cout << quickSelect(in, 0, in.size() - 1, 4) << std::endl;
    return 0;
}
