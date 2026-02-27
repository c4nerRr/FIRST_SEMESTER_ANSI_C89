#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<conio.h>
//
// Created by c4ner on 11/12/2025.
//
int main () {
    printf("\n---Це программа для розв'язання СЛАР.---\n");
    printf("A11X1 + A12X2 + ... + A1nXn = B1\n");
    printf("A21X1 + A22X2 + ... + A2nXn = B2\n");
    printf("...................................\n");
    printf("An1X1 + An2X2 + ... + AnnXn = Bn\n");
    printf("ENTER.\n");
    getch();
    int n = 0;
    int scan_result = 0;
do {
    printf("Введіть розмір матриці. (від 1 до 5) -> ");
    scan_result = scanf_s ("%d", &n);
    fflush(stdin);
    if (scan_result != 1 || n < 1 || n > 5) {
        printf("Некорректний ввод. Будь ласка вводьте ЧИСЛО в діапазоні від 1 до 5. Спробуйте ще рвз.\n");
    }
}while (n < 1 || n > 5);

    double eps = 0;
    do {
        printf("Введіть епсіон (від 0.1 до 1e-12 )-> ");
        scan_result = scanf_s ("%lf", &eps);
        fflush(stdin);
        if (scan_result != 1 || eps > 0.1|| eps < 1e-12) {
            printf("Некорректний ввод. Будь ласка вводьте ЧИСЛО в діапазоні від 0.1 до 1e-4. Спробуйте ще раз\n");
        }
    }while (eps == 0 || eps > 0.1 || eps < 1e-12);

    double *X = 0;
    X = (double *)calloc(n, sizeof(double)); //неперервна область пам'яті для Х масиву.
    double *XP = 0;
    XP = (double *)calloc(n, sizeof(double));
    double *B = 0;
    B = (double *)calloc(n, sizeof(double));
    double **A = 0;
    A = (double **)calloc(n, sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)calloc(n, sizeof(double));
    }

    int is_diagonally_dominant = 0; //прапор зовн. циклу.
    do {
        is_diagonally_dominant = 1;
        printf("\nВведіть коефіцієнти матриці А[i][j] (від -5 до 5):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    do {
                        printf("A[%d][%d] = ", i+1, j+1);
                        scan_result = scanf_s("%lf", &A[i][j]);
                        fflush(stdin);
                        if (scan_result != 1 || A[i][j] > 5.0 || A[i][j] < -5.0) {
                            printf("ПOМИЛКА! Некорректний ввод.\n");
                        }
                        else if (A[i][j] == 0) {
                            printf("ПОМИЛКА! Діагональний елемент [%d][%d] не може дорівнювати нулю. Спробуйте ще раз.\n", i+1,j+1);
                        }
                    }while (A[i][j] == 0 || scan_result != 1 || A[i][j] > 5.0 || A[i][j] < -5.0 );
                }
                else
                {
                    do{
                        printf("A[%d][%d] = ", i+1, j+1);
                        scan_result = scanf_s("%lf", &A[i][j]);
                        fflush(stdin);
                        if (scan_result != 1 || A[i][j] > 5.0 || A[i][j] < -5.0 ) {
                            printf("Помилка. Некорректний ввод. Спробуйте ще раз.\n");
                        }
                    }while (scan_result != 1 || A[i][j] > 5.0 || A[i][j] < -5.0 );
                }
            }
        }
        //ПЕРЕВІРКА ЗБІЖНОСТІ 2.
        for (int i = 0; i < n; i++) {
            double row_sum = 0;
            //недіаг. елементи:
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    row_sum += fabs(A[i][j]);
                }
            }
            //якщо модуль діаг. ел не більше за суму решти
            if (fabs(A[i][i]) <= row_sum) {
                printf("\n---ПОРУШЕННЯ УМОВИ ЗБІЖНОСТІ (РЯДОК %d) ---\n", i+1);
                printf("Модуль A[%d][%d] (%.2f) повинен бути СТРОГО більшим за суму решти (%.2f).\n", i+1, i+1, fabs(A[i][i]), row_sum);

                is_diagonally_dominant = 0;
                break;
            }
        }
        if (is_diagonally_dominant == 0) {
            printf("\n---МАТРИЦЯ НЕ ЗБІЖНА. БУДЬ ЛАСКА ВВЕДІТЬ КОЕФІЦІЄНТИ ЩЕ РАЗ.\n\n");
        }
    }while (is_diagonally_dominant == 0);

    printf("Введіть вільні члени B[i](Від -5 до 5):\n");
    for (int i = 0; i<n ; i++) {
        do {
            printf("B[%d] -> ", i+1);
            scan_result = scanf_s("%lf", &B[i]);
            fflush(stdin);
            if (scan_result != 1 || B[i] > 5.0 || B[i] < -5.0) {
                printf("Некорректний ввод. Будь ласка вводьте ЧИСЛО в діапазоні від 5 до -5. Спробуйте ще раз:");
            }
        }while (scan_result != 1 || B[i] > 5.0 || B[i] < -5.0);
    }
    for (int i = 0; i < n; i++) {
            XP[i] = B[i]/A[i][i];
    }

    int iter_count = 0;
    double prop = 0;
    do
    {
        prop = 0.0;
        iter_count++;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j]*XP[j];
                }
            }
            X[i] = (B[i] - sum)/A[i][i];
            double delta = fabs(X[i] - XP[i]);
            if (delta > prop) {
                prop = delta;
            }
        }
        for (int i = 0; i < n; i++) {
            XP[i] = X[i];
        }

        printf("Ітерація %d: prop = %.12f\n", iter_count, prop);
    } while (prop>=eps);

    printf("\n---Результат розв'язання (Кількість ітерацій: %d)---\n", iter_count);
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %.12f\n", i+1, X[i]);
    }
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(X);
    free(B);
    free(XP);
    printf("Програма завершила свою роботу. ENTER.\n");
    getch();
    return 0;
}