#include <iostream>
#include <cstdlib>
#include <ctime>
void printMatrix(int **arr, int side) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void randGenerateMatrix(int **arr, int side) {
    srand(time(NULL));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
           arr[i][j] = rand() % 10 + 1; 
        }
    }
}

void rotate(int** arr, int side) {
    for (int cycle = 0; cycle < side/2; cycle++) {
        for (int i = cycle; i < side - cycle - 1; i++) {
            int top = arr[cycle][i];
            //std::cout << "top is " << top << std::endl;            
            arr[cycle][i] = arr[side - i - 1][cycle];
            //std::cout << "left is " << arr[side - i - 1][cycle] << std::endl;
            arr[side - i - 1][cycle] = arr[side - cycle - 1][side - i - 1];
            //std::cout << "bot is " << arr[side - cycle - 1][side - i - 1] << std::endl;
            arr[side - cycle - 1][side -i - 1] = arr[i][side - cycle - 1];
            //std::cout << "right is " << arr[i][side - cycle - 1] << std::endl;
            arr[i][side - cycle - 1] = top;
            //std::cout << "================================" << std::endl;
            //std::cout << "now the matrix looks like.." << std::endl;
            //printMatrix(arr, side);
            //std::cout << "================================" << std::endl;
        }
    }

}
int main(int argc, const char *argv[])
{
    int side;
    int **arr;
    std::cin >> side;
    arr = (int**)malloc(sizeof(int*) * side);
    for (int i = 0; i < side; i++) {
        arr[i] = (int*)malloc(sizeof(int)*side);
    }
    randGenerateMatrix(arr, side);
    printMatrix(arr, side);
    rotate(arr, side);
    std::cout << "after rotate 90" << std::endl;
    printMatrix(arr, side); 

    return 0;
}
