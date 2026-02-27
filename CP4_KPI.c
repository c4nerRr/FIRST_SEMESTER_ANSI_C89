//
// Created by c4ner on 10/22/2025.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void sort(double *ar, int num) //сортування бульбашкою.
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (ar[j] > ar[j+1])
            {
                double t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
            }
        }
    }
}

int main() {
    printf("Ця програма сортує числа методом бульбашки. Enter.");
    getch();
    int n = 0;
    srand(time(NULL)); //NOLINT
    int scan_result = 0;
    do {
        printf("Введіть кількість елементів в массиві (від 1 до 20): ");
        scan_result = scanf_s("%d", &n);
        fflush(stdin);
        if (scan_result != 1 || n < 1 || n > 20) {
            printf("Це число виходить за діапазон від 1 до 20. Спробуйте ще раз.\n");
        }
    } while (scan_result != 1 || n < 1 || n > 20);


    double arr[n];

      short choise = 0;
    do {
        printf("Бажаєте сортувати вручну чи рандомом? 1 - Рандом, 2 - Вручну. \n");
        scan_result = scanf_s("%hd", &choise);
        fflush(stdin);
        if (scan_result != 1 || (choise != 1 && choise != 2)) {
            printf("Вам треба ввести числа 1 - для вибору Рандом, 2 - для вибору Вручну. Спробуйте ще раз\n");
        }

    } while (scan_result != 1 || (choise != 1 && choise != 2));


       if (choise == 1) {
        for (int i = 0; i < n; i++) {
            arr[i] = (double)(rand() % 100) + ((double)rand() / RAND_MAX); //NOLINT
        }
       }
       else if (choise == 2) {
           printf("Тепер введіть будь ласка %d довільних числа щоб зберегти і відсортувати їх (числа від -1e20 до 1e20):\n", n);

           for (int i = 0; i < n; i++) {
               int false = 0;
               do {
                   printf("Елемент #%d: ", i + 1);
                   scan_result = scanf_s("%lf", &arr[i]);
                   int next_char = getchar();
                   if (scan_result != 1 ||(next_char != '\n' && next_char != EOF) || arr[i] > 1e20 || arr[i] < -1e20) {
                       printf("Ви порушуєте обмеження [-1e20; 1e20]. Спробуйте ще раз:\n");
                       if (next_char != '\n' && next_char != EOF) {
                           while (getchar() != '\n');
                       }
                       false = 0;
                   } else {
                       false = 1;
                   }

               } while (false == 0);
           }
       }
         printf("Дані числа: ");

         for (int i = 0; i < n; i++)
        {
           printf("%.3g ", arr[i]);
        }


           sort(arr, n);
           printf("\n");
           printf("Відсортовані числа: ");

           for (int i = 0; i < n; i++)
           {
               printf("%.3g ", arr[i]);
           }
    printf(" Програма завершила свою роботу. Enter.\n");
    getch();
   return 0;
}