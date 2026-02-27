#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

//допоміжна функція для обміну двох чисел місцями
void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; //останній елемент як опорний
    int i = low - 1; //індекс меншого елемента
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; //зсув межі менших елементів
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//основна ф-ія сортування
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main () {
    printf("Enter the number of terms you want to enter: ");
    int n;
    scanf_s("%d", &n);
    int **matrix = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }

    int *mass = (int *)calloc(n * n, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the mass for term %d %d: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mass[k] = matrix[i][j];
            k++;
        }
    }
    quick_sort(mass, 0, n*n - 1);
    //засипать назад по стовпцям:
    k = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            matrix[i][j] = mass[k];
            k++;
        }
    }

    printf("\nSorted Matrix (by columns):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    getch();
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
    free(mass);
    return 0;

}