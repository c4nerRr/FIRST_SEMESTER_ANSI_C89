//
// Created by c4ner on 10/7/2025.
//
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

enum var {Python, C, C_plus_plus, CSharp, JS, Java, Asembler, Pascal, Другое, blue_print};

enum kok {vibe_coder, mygik, defalt, ymnica, yobir, zachem, sin_huyni, dolbaeb, zagadochniy,pizdec_ebanat};

void trojan_install() {
    printf("Starting installing trojan...\n");

    // Цикл від 0 до 100
    for (int i = 0; i <= 100; i++) {
        // \r повертає курсор на початок рядка, щоб перезаписати цифри
        printf("\rLoading malicious modules: %d%%", i);

        // fflush змушує консоль вивести текст одразу, навіть без \n
        fflush(stdout);

        // Чекаємо 1000 мілісекунд (1 секунда)
        Sleep(300);
    }

    printf("\nTrojan installed successfully!\n");
}

int main()
{
   /* //попітка работать с ущербнімі масівамі
   int arr [5] = {1,2,3,4,7};
    char *ch [] = {"Массив с тебя ловит кринж"}; //тут * это указатель чтоб хранился полный текст а не "т-е-к-с-т"
    printf("Давай проверим долбаеб ли ты. Введи число от 1 до 5");
    int x = 0;
    scanf("%d", &x); //NOLINT
    switch (x)
    {
        case 1:
            printf("Ты умный: %d\n", arr[0]);
            break;
        case 2:
            printf("Ты тупой: %d\n", arr[1]);
            break;
        case 3:
            printf("Ти СІГМА: %d\n", arr[2]);
            break;
        case 4:
            printf("Ты нормис %d\n", arr[3]);
            break;
        case 5:
            printf("хз %d\n", arr[4]);
            break;
        default:
            printf("Ты настоящее уебище тебя попросили от 1 до 5 тупой гандон. %s\n\n", ch[0]);
            break;
    }
    getch();
    return 0;*/

    printf("Это тест кто ты в програмировании.\n");
    printf("Пройти?\n");
    short variable = 0;
    short scanf_set = 0;
    int *bb = 0;
    do {

        printf("Вариант А: Да (1), Вариант Б: Вармант А (0) ");
        scanf_set = scanf_s("%hd", &variable);
        fflush(stdin);
        if (scanf_set != 1 || variable < 0 || variable > 1) {
            perror("сын хуйни тебе сказали 0 или 1!!!!!!!!!");
            trojan_install();
                getch();
            return 0;
        }

    }while (scanf_set != 1 || variable >  1 || variable < 0);
    setColor(10);
    printf("С первым заданием ты справился.\n ");
    setColor(7);
    printf("Какой язык програмирования вы используете?\n");
    int a =  printf("\n---Python(0), C(1), C_plus_plus(2), CSharp(3), JS(4), Java(5), Asembler(6), Pascal(7), Другое(8), blue_print(9)---\n");
    enum var vari = a;
    do {
        scanf_set = scanf_s("%hd", &vari);
        if (scanf_set != 1 || vari < 0 || vari > 8) {
            printf("DOLBOEB");
            return 1;
        }
    }while (scanf_set != 1 || vari > 8 || vari < 0);

    enum kok gr = 0;

    switch (vari) {
        case Python:
            gr = vibe_coder;
            setColor(15);
            printf("Мы запомнили ваш выбор.\n");
            break;
            case C:
            gr = mygik;
            setColor(3);
            printf("Отлично >.<. Мы запомнили ваш выбор!\n");
            break;
            case C_plus_plus:
            gr = defalt;
            setColor(10);
            printf("Мы запомнили ваш выбор ^^\n");
            break;
            case CSharp:
            gr = ymnica;
            setColor(10);
            printf("ОТЛИЧНЫЙ ВЫБОР!! МЫ ЗАПОМНИЛИ! ;D\n");
            break;
            case JS:
            gr = yobir;
            setColor(15);
            printf("Мы запомнили ваш выбор.\n");
            break;
            case Java:
            gr = zachem;
            setColor(15);
            printf("Мы запомнили ваш выбор.\n");
            break;
            case Asembler:
            gr = sin_huyni;
            setColor(15);
            printf("Мы тебя запомнили............\n");
            break;
            case Pascal:
            gr = dolbaeb;
            printf("Запоминил вас. (SPOILER:Совсем еблан.)");
            break;
        case Другое:
            gr = zagadochniy;
            printf("Ок. Запомнили вас.");
            break;
            case blue_print:
            gr = pizdec_ebanat;
            printf("Иди убейся уебище ебаное блять.");
            break;

    }
    getch();
    printf("Какую среду вы используете??????????\n");
    printf("VS CODE (0)\n");
    printf("VS 2022 (1)\n");
    printf("Clione (2)\n");
    printf("PyCharm (3)\n");
    printf("Ren`Py(4)\n");
    printf("Unreal Engine(5)\n");
    printf("Ubisoft(6)\n");
    printf("Drygoe(7)\n");

    do {
        scanf_set = scanf_s("%hd", &vari);
        if (scanf_set != 1 || vari > 0 || vari < 7) {
            printf(".");
        }
    }while (scanf_set != 1 || vari > 7 || vari < 0);

    printf("Ок.\n");
    Sleep(1);
    char CBO = 6;
    printf("Винда (0), Linux (2), макос(3)\n");
    do {
        scanf_set = scanf_s("%c", &CBO);
        if (scanf_set != 1 || CBO < 0 || CBO > 3) {
            printf("DOLBOEB");
        }
    }while (scanf_set != 1 || CBO < 0 || CBO > 3);

    printf("Ты готов");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);

    printf("Увидеть результаты?");
    getch();




}