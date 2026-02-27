//
// Created by c4ner on 10/29/2025.
//
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


//Пояснення. У нас є char str[3][..] - це теж саме що у мене є 3 пісні. КОНКРЕТНО ПІСНІ.
//тоді char *arr[3] - це з * це покажчик. ТОБТО ПЛЕЙЛИСТ де ці 3 пісні вже є.
void sort (char **mass, int num) {
    int i,j;
    for(i=0;i<num-1;i++)
        for(j=i+1;j<num;j++)
            if ( strcmp(mass[i],mass[j]) >0 )
            {
                char *tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
}


int random(int range_min, int range_max ) {
    return (range_min + rand() % (range_max - range_min + 1)); //NOLINT
}
int main() {
    int scan_result = 0;
   int nums=2,numc=5;
    printf("Ця програма впорядковує масиви рядків. Натисніть Enter щоб продовжити.");
    getch();

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

   do {
       printf("\nВведіть кількість рядків від 2 до 50 -> ");
       scan_result = scanf_s("%d", &nums);
       fflush(stdin);
       if (scan_result != 1 || nums < 2 || nums > 50) {
           printf("Помилка. Ви вводите некорректні дані. Спробуйте ще раз.\n");
       }
   } while (scan_result != 1 || nums < 2 || nums > 50);


    do {
        printf("Введіть кількість символів в рядку від 2 до 100-> ");
        scan_result = scanf_s("%d", &numc);
        fflush(stdin);
        if (scan_result != 1 || numc < 2 || numc > 100 ) {
            printf("Помилка. Ви вводите некорректні дані. Спробуйте ще раз.\n");
        }
    } while (scan_result != 1 || numc < 2 || numc > 100);

    short variant = 0;
    do {
        printf("\nОберіть спосіб заповнення масиву\n");
        printf("1-Випадково, 2-Вручну\n");
        printf("Ваш вибір -> ");
        scan_result = scanf_s("%hd", &variant);
        fflush(stdin);
        if (scan_result != 1 || variant < 1 || variant > 2 ) {
            printf("Помилка. Некорректний ввод. Спробуйте ще раз.\n");
        }
    } while (scan_result != 1 || variant < 1 || variant > 2 );

    char str[nums][numc+1];

    int a = 0;

    if (variant == 1) {
        int b = 0;
        int ch = 0;
        srand((unsigned int)time(NULL)); //NOLINT
        for(a=0;a<nums;a++)
        {b=0;
            do
            { ch=random(65,122);
                if ( /*(ch>= 'A' && ch<='Z')*/ (ch>='a' && ch<='z') )
                { str[a][b]= (char)ch; //явне приведення типу.
                    b++;
                }
            } while (b<numc);
            str[a][b]= '\0'; // вставка символу кінця рядку
        }
    }
    else {
        printf("Ви обрали ввод вручну.\n");
        char format_string[32];
        sprintf_s(format_string, 32, "%%%d[^\n]", numc);
        setColor(12);
        printf("Попередження! Ввід, довший за %d символів буде автоматично обрізано.\n", numc);
        setColor(7);
        for (a =0;a<nums;a++) {
            printf("Введіть рядок %d -> ", a+1);
            scanf_s(format_string, str[a], (unsigned int)numc + 1);
            fflush(stdin);
        }
    }
    printf("Рядки до сортування:\n");
        for (a=0;a<nums;a++) printf("%d-> %s\n",a+1,str[a]); //намс - колво в масиві

        char *addr [nums]; //маленький блокнот для сховища стр.
        for (a=0 ;a<nums;a++) {
            addr[a]=str[a];
        }
        sort (addr, nums);

        printf("\n\nРядки після сортування:\n");
        for (a=0;a<nums;a++) {
            printf("%d-> %s\n",a+1,addr[a]);
        }
       printf("Програма завершила свою роботу. Enter.");
        getch();
        return(0);
}