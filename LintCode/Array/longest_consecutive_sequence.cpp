#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int> &input) {
    for(auto i : input)
        std::cout << i << std::endl;
}

int ans(std::vector<int> &input) {
    std::sort(input.begin(), input.end());

    int len = 1;
    int max = 1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] - 1 == input[i - 1]) {
            len++;
        }
        else if (input[i] == input[i - 1]) {
            continue;
        }
        else {
            if ( len > max ) {
                max = len;
                len = 1;
            }
        }
    }
    return max;
}

int main(int argc, const char *argv[])
{
    int arr[] = { 100, 4, 200, 1, 5, 3, 2 };
    std::vector<int> input(arr, arr + 7);

    std::cout << ans(input) << std::endl;

    return 0;
}
