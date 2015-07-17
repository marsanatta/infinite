#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void swap(int l, int r, vector<int> &nums) {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}

void quickSort(vector<int> &nums, int start, int end) {
    if (end - start + 1 <= 1)
        return;
    int mid = start + (end - start)/2;
    int pivot = nums[mid];
    swap(mid, end, nums);
    int i, chg;
    for (i = start, chg = start; i <= end; i++) {
        if (nums[i] < pivot) {
            swap(i, chg, nums);
            chg++;
        }
    }
    //chg's left elements must < pivot
    //chg itself must >= pivot
    swap(chg, end, nums);
    // now chg is pivot, and it's at its place
    quickSort(nums, start, chg - 1);
    quickSort(nums, chg + 1, end);
}

void merge(vector<int> &nums, int lstart, int lend, int rstart, int rend) {
    int l = lstart;
    int r = rstart;
    vector<int> temp;
    while( l <= lend && r <= rend ) {
        if ( nums[l] < nums[r] ) {
            temp.push_back(nums[l]);
            l++;
        }
        else {
            temp.push_back(nums[r]);
            r++;
        }
    }
    if ( l <= lend ) {
        for (; l <= lend; l++)
            temp.push_back(nums[l]);
    }
    else if ( r <= rend ) {
        for (; r <= rend; r++ )
            temp.push_back(nums[r]);
    }
    //copy temp to nums
    for (int i = lstart, j = 0; i <= rend; i++, j++) {
        nums[i] = temp[j];
    }

}

void mergeSort(vector<int> &nums, int start, int end) {
    if (end - start + 1 <= 1)
        return;
    int mid = start + (end - start)/2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, mid + 1, end);
}


void selectionSort(vector<int> &nums) {
    for (int i = nums.size() - 1; i >= 0; i-- ) {
        int maxIdx = 0;
        for (int j = 1; j <= i; j++) {
            if (nums[j] > nums[maxIdx])
                maxIdx = j;
        }
        if (maxIdx != i)
            swap(i, maxIdx, nums);
    }
}

void bubbleSort(vector<int> &nums) {
    for (int i = nums.size() - 1; i >= 1; i-- ) {
        for (int j = 0; j <= i - 1; j++ ) {
            if (nums[j] > nums[j + 1])
                swap(j , j + 1, nums);
        }
    }
}

void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int temp = nums[i];
        int j;
        for (j = i - 1; j >= 0 && temp < nums[j]; j--) {
            nums[j+1] = nums[j];
        }
        nums[j+1] = temp;
    }
}

class Node {
    public:
        int val;
        Node* next;
        Node(int val) : next(nullptr), val(val){}

        void insert(int val) {
            Node* cur = this;
            while(cur->next)
                cur = cur->next;
            cur->next = new Node(val);
        }

        void del() {
            if (this->next != nullptr) {
                this->next->del();
                delete this;
            }
            else {
                delete this;
            }
        }
};

int getDigit(int n, int digit) {
    n /= pow(10, digit);
    return n % 10;
}

void radixSort(vector<int> &nums, int digits) {
    Node* buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i] = nullptr;
    }   
    int digit = 0;
    while (digit < digits) {
        for (auto &n : nums) {
            int d = getDigit(n, digit);
            if (!buckets[d])
                buckets[d] = new Node(n);
            else
                buckets[d]->insert(n);
        }
        nums.clear();
        for (int i = 0; i < 10; i++) {
            Node* cur = buckets[i];
            while(cur) {
                nums.push_back(cur->val);
                cur = cur->next;
            }
        }
        //clear buckets
        for (int i = 0; i < 10; i++) {
            if (buckets[i]) 
                buckets[i]->del();
            buckets[i] = nullptr;
        }
        digit++;
    }
}

int main(int argc, const char *argv[])
{
    //int input[] = {8, 2, 5, 4, 7, 8};
    //int input[] = {8, 2, 5};
    int input[] = {73, 22, 93, 43, 55, 14, 28, 22, 65, 39, 81};
    vector<int> nums(begin(input), end(input));
    for ( auto &n : nums ) {
        std::cout << n << std::endl;
    }
    quickSort(nums, 0, nums.size() - 1);
    //mergeSort(nums, 0, nums.size() - 1);
    //radixSort(nums, 2);
    //bubbleSort(nums);
    //selectionSort(nums);
    //insertionSort(nums);
    std::cout << "after sort:" << std::endl;
    for ( auto &n : nums ) {
        std::cout << n << std::endl;
    }
    return 0;
}
