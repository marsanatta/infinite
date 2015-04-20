#include <iostream>

class ArrayList
{
public:
    ArrayList(int init_size):
    max_size(init_size),
    current(0)
    {
       arr = new int[max_size]; 
    }
    void insert(int elem) {
        std::cout << "inserting " << elem << std::endl;
        if (current + 1 < max_size) {
            arr[current] = elem;
            current++;
        }
        else {
            std::cout << "double the size of current array... "; 
            int *newArr = new int[max_size * 2];
            for (int i = 0; i < max_size; i++) {
                newArr[i] = arr[i];    
            }
            max_size *= 2;
            free(arr);
            arr = newArr;
            std::cout << "now the size is " << max_size << std::endl;
        }
    }

private:
    int max_size;
    int current;
    int *arr;
};
int main(int argc, const char *argv[])
{
    ArrayList array_list(2);
    for (int i = 0; i < 10; i++) {
       array_list.insert(i);
    }
    return 0;
}
