#include <stdio.h>
#include<conio.h>

void shellSort(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n = 5;
    int matr[5][5];
    // Твій масив (він поки несортований)
    int mass[25] = {9,8,7,6,5,16,15,14,13,4,21,20,19,12,3,24,23,18,11,2,25,22,17,10,1};

    shellSort(mass, 25);

    int k = 0;

    //цикл по шарах (літерах "г")
    for (int layer = 0; layer < n; layer++) {

        int col = n - 1 - layer;
        int row = layer;

        for (int i = n - 1; i >= row; i--) {
            if (k < 25) {
                matr[i][col] = mass[k];
                k++;
            }
        }

        for (int j = col - 1; j >= 0; j--) {
            if (k < 25) {
                matr[row][j] = mass[k];
                k++;
            }
        }
    }

    printf("Result Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%4d ", matr[i][j]);
        }
        printf("\n");
    }

    _getch();
    return 0;
}