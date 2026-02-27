//
// Created by c4ner on 11/30/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void insertion_sort(int **A, int n) {
    int i, j, key;
    //перший ел матриці вже відсортований
    for (int i = 1; i < n; i++) {
        key = A[i][n-1-i];
        j = i-1;
        while (j >= 0 && A[j][n-1-j] > key) {
            //більший елемент пхаємо на крок вниз-вліво
            A[j + 1][n - 1 - (j + 1)] = A[j][n - 1 - j];
            j = j - 1;
        }
        //на звільнене місце ставимо змінну кей
        A[j + 1][n - 1 - (j + 1)] = key;
    }
}

int random(int range_min, int range_max ) {
    return (range_min + rand() % (range_max - range_min + 1)); //NOLINT
}

int main() {
    int a = 0;
    int scan_re = 0;
    do {
        printf("Введіть розмір матриці n x n -> ");
        scan_re = scanf_s("%d",&a);
        fflush(stdin);
        if (scan_re != 1) {
            printf("Помилка. Спробуйте ще раз\n");
        }
    }while (scan_re != 1);

    int **A = (int**)calloc(a, sizeof(int*));
    for (int i = 0; i < a; i++) {
        A[i] = (int*)calloc(a, sizeof(int));
    }

    srand((unsigned int)time(NULL)); //NOLINT
    printf("Сгенерована матриця -> \n ");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            A[i][j] = rand()%100; //від 0 до 99
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    insertion_sort(A, a);
    printf("Відсортована матриця:\n");
    printf("-----------------------\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (j == a-1-i) {
                printf("[%2d] ", A[i][j]);
            }
            else {
                printf("%4d ", A[i][j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < a; i++) {
        free(A[i]);
    }
    free(A);
}