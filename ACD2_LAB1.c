#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
//двигун
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i =0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //докидаємо залишки елементів в кінець.
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//управл
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right- left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    else {
        return;
    }

}

int main () {
        int n;
        printf("Enter matrix size (n): ");
        scanf_s("%d", &n);
    //матриця динамічно
        int **matrix = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)calloc(n, sizeof(int));
        }

      //мас для результатів
        int *mass = (int *)calloc(n, sizeof(int));

        printf("\n--- Manual Matrix Entry ---\n");

        for (int i = 0; i < n; i++) {
            int negativesInRow = 0;

            printf("Row %d:\n", i + 1);
            for (int j = 0; j < n; j++) {
                printf("  Enter element [%d][%d]: ", i, j);
                scanf_s("%d", &matrix[i][j]);

                // від'ємне число чи ні
                if (matrix[i][j] < 0) {
                    negativesInRow++;
                }
            }
            mass[i] = negativesInRow;
        }
        printf("\nArray B (negatives count per row - UNSORTED):\n");
        for (int i = 0; i < n; i++) printf("%d ", mass[i]);

        MergeSort(mass, 0, n - 1);

        printf("\n\nArray B (SORTED):\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", mass[i]);
        }
        getch();
        for (int i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
        free(mass);

        return 0;
}