//
// Created by c4ner on 2/2/2026.
//
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//-------------------------------------------------------------
void sort(int *ar, int num) //сортування бульбашкою.
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (ar[j] > ar[j+1])
            {
                int t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
            }
        }
    }
}
//-------------------------------------------------------------
//Класичний лінійний пошук:
int LinearSearch(const int *a, int N, int key) { //конст тому шо з обичним інт функція пошуку мала право міняти числа, а це не можна
    //а - показник на ел масиву, N - номер в масиві, key - іскуєме
    int i = 0;
    int steps = 0;
    while ((i < N) && (a[i] != key)) {
        i++;
        steps++;
    }
    steps++;//перевірка шо зупинила цикл
    printf_s("\n ЛІНІЙНИЙ: Кількість кроків -> %d\n", steps);
    if (i == N) {
        return -1;
    }
    return i;
}
//--------------------------------------------------------
//Класичний бінарний пошук:
int BinarySearch(const int *a, int N, int key) {
    int b, e, i; //бегін, енд, індекс
    b = 0; e = N-1; // -1 щоб отримати індекс останнього якщо рахуємо з 0
    bool Found = false;
    int steps = 0;
    while ((b <= e) && !Found ) { //більше або = щоб не пропустити останній елемент
        steps++; //рахуємо оберти циклу
        i = (b + e) / 2;
        if (a[i] == key) {
            Found = true;
        }
        else if (a[i] < key) {
            b = i + 1;
        }
        else {
            e = i-1;
        }
    }
    printf_s("\nБІНАРНИЙ: Кількість кроків -> %d\n", steps);
    if (Found == true) {
        return i;
    }
    else
        {
        return -1;
    }
}
//--------------------------------------------------
//Інтерполяційний пошук
int InterpolationSearch(const int *a, int N, int key) {
    int b, e, i;
    b = 0; e = N-1;
    int steps = 0;
    while (b<=e && key >= a[b] && key <= a[e]) {
        steps++;
        i = b + (key - a[b]) * (e - b) / (a[e] - a[b]);
        if (a[i] == key) {
            printf_s("\nІНТЕРПОЛЯЦІЙНИЙ: Кількість кроків -> %d\n", steps);
            return i;
        }
        else if (a[i] < key) {
            b = i + 1;
        }
        else {
            e = i-1;
        }
    }
    printf_s("\nІНТЕРПОЛЯЦІЙНИЙ: Кількість кроків -> %d\n", steps);
    return -1;
}
//----------------------------------------------
//Метод Золотого перерізу
int ZolotyPereriz(const int *a, int N, int key) {
    int b, e, i;
    b = 0; e = N-1;
    const double Phi = (1.0 + sqrt(5.0))/2.0;
    int steps = 0;
    while (b <= e && key >= a[b] && key <= a[e]) {
        steps++;
       if (a[e] - key < key - a[b]) {
           i = b + (e-b) * (Phi - 1);
       }
        else { //NOLINT
            i = e - (e-b) * (Phi - 1);
        }
         if (a[i]==key) {
             printf_s("\nЗОЛОТИЙ ПЕРЕРІЗ: Кількість кроків -> %d\n", steps);
             return i;
         }

        else if (a[i]<key) { //NOLINT
            b = i + 1;
        }
        else { //NOLINT
            e = i-1;
        }
    }
    printf_s("\nЗОЛОТИЙ ПЕРЕРІЗ: Кількість кроків -> %d\n", steps);
    return -1;
}


int main () {
    srand(time(NULL)); //NOLINT
    printf("Ця программа реалізує основні методи пошуку в масиві даних. ENTER");
    _getch();
    short choice = 1;

    while (choice == 1) {
        printf("--MAIN MENU--\n");
        printf("Оберіть метод пошуку:\n");
        printf("1) Лінійний пошук\n");
        printf("2) Бінарний пошук\n");
        printf("3) Інтерполяційний пошук\n");
        printf("4) Пошук методом ""Золотого перерізу""\n");
        printf("-->");

        char choi = 48;
        do {
            scanf_s(" %c", &choi);
            fflush(stdin);
            if (choi < 49 || choi > 52) {
                printf_s("Помилка. Введіть 1, 2, 3 або 4.\n");
            }
        }while (choi < 49 || choi > 52);


        int number = 0;
        do {
            printf("Яке число треба знайти?\n");
            scanf_s("%d", &number);
            fflush(stdin);
            if (number > 1000 || number < -1000) {
                printf("Це завелике число або ви вводите некорректні дані. Спробуйте ще раз.\n");
            }
        }while (number > 1000 || number < -1000);

        const short n = 115; //шоб не писать 115 вручну, поки шо використовуємо тільки 115 місць
        int mass [116] = {0}; // 116 для завдання
        for (int i = 0; i < n; i++) {
            mass[i] = (int)(rand() % 101 - 18); //NOLINT, 101-50 (діапазон - зсув.) щоб були від'ємні.
        }


        int result = -1;
        if (choi == 49) {
         result = LinearSearch(mass,n,number);
        }
        else {
            sort(mass, n);
            switch (choi) {
                case 50:
                    result = BinarySearch(mass, n, number);
                    break;
                    case 51:
                    result = InterpolationSearch(mass, n, number);
                    break;
                    case 52:
                    result = ZolotyPereriz(mass, n, number);
                    break;
                    default:
                    break;
            }
        }
        if (result == -1) {
            for (int i = 0; i < n; i++) {
                printf(" %d ", mass[i]);
            }
            printf_s("\nТакого числа немає!\n");
            printf_s("Вставляю елемент перед останнім від'ємним числом...\n");
            int targee = 0;
            for (int i = n-1; i >= 0; i--) {
                if (mass[i] < 0) {
                    targee = i;
                    break;
                }
            }
            for (int i = n; i > targee; i--) { //справа наліво іду. починаємо з н тому шо у нас 116 елементів і 115 комірок. одна вільна ізначально
                mass[i] = mass[i-1];
            }
            mass[targee] = number;
            for (int i = 0; i < n+1; i++) { //томушо у нас 115 н було, а тепер 116!
                printf_s("%d ", mass[i]);
            }
            printf_s("\n");
        }
        else {
            printf_s("\nЗнайдено число під індексом: %d\n", result);
            for (int i = 0; i < n; i++) {
                printf(" %d", mass[i]);
            }

            printf_s("\nЗмінюю знайдений елемент місцями з максимальним елементом...\n");
            int maxIndex = 0;
            for (int i = 0; i < n; i++) {
                if (mass[i] > mass[maxIndex]) {
                    maxIndex = i;
                }
            }
            printf_s("Готово!\n");

            int te = mass[result];
            mass[result] = mass[maxIndex];
            mass[maxIndex] = te;
            for (int i = 0; i < n; i++) {
                printf_s(" %d ", mass[i]);
            }
        }

        do {
            printf_s("\nЧи бажаєте ви завершити? 0-yes /1 - no\n");
            scanf_s("%d", &choice);
            fflush(stdin);
            if (choice == 0) {
                break;
            }
            if (choice > 1 || choice < 0) {
                printf_s("Помилка. Некорректний ввід. Спробуйте ще раз.");
            }
        }while (choice > 1 || choice < 0);
    }
return 0;

}