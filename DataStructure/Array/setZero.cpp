#include <iostream>
#include <ctime>
#include <cstdlib>

void printMatrix(int **a, int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void setZero(int **a, int m, int n) {
    bool *row = new bool[m];
    bool *col = new bool[n];
    for (int i = 0; i < m; i++) {
       row[i] = false;
    }
    for (int i = 0; i < n; i++) {
       col[i] = false; 
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                row[i] = true;
                col[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j])
                a[i][j] = 0;
        }
    }
    free(row);
    free(col);
}
int main(int argc, const char *argv[])
{
    int m, n;
    int **a;
    std::cin >> m;
    std::cin >> n;
    a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    srand(time(NULL));
    for (int i = 0; i <m; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 100 <= 15)
                a[i][j] = 0;
            else
                a[i][j] = rand() % 100 + 10;
        }
    }
    printMatrix(a, m, n);
    setZero(a, m, n);
    std::cout << "after set zero" << std::endl;
    printMatrix(a, m, n);
    for (int i = 0; i < m; i++) {
       free(a[i]); 
    }
    free(a);
    return 0;
}
