#include <stdio.h>
#include<conio.h>
#include<math.h>
//------------------------------------------------------------------
double polovina(double(*f)(double, double), double a, double eps, double b, double y)
{
    double x = 0;
    while (fabs(b-a)>eps) {
        x = (a+b)/2;
        if (f(a,y) * f(x,y) > 0) {
            a = x;
        }
        else {
            b = x;
        }
    }
    return x;
}

//----------------------------------------------------------------------

double uravnenie1(double x, double y)
   {
     return (cos(y/x)-2*sin(1.0/x)+1.0/x);
   }

double uravnenie2(double x, double y)
   {
     return (sin(log(x))-cos(log(x))+y*log(x));
   }

//----------------------------------------------------------------------

double newton(double(*f)(double, double), double x, double eps, double y) {
    double delta_x = 0.00001;
    double deriv = 0;
    double next_x = 0;
    double diff = 0;
    do {
        //похідна в точці х
        deriv = (f(x+delta_x,y)-f(x,y))/(delta_x);
        //Формула Ньютона
        next_x = x - (f(x,y)/deriv);
        //чи дуже змінився х
        diff = fabs(next_x - x);
        x = next_x;

    }while (diff>eps);
    return x;
}
//---------------------------------------------------------------------


int main () {
    printf("Ця програма обчислює корені нелінійних рівнянь на заданому проміжку. ENTER.\n\n");
    printf("\n1) cos(y/х) - 2sin(1/х)+(1/х) = 0      x є [a,b]\n");
    printf("\n2) sin(lnx) - cos(lnx) + ylnx = 0      x є [a,b]\n");
    getch();
    double a = 0;
    int scanf_result = 0;
    do {
        printf("Введіть а (від 1 до 2 включно):\n");
        printf("ПОПЕРЕДЖЕННЯ: Программа не зчитає більше 15 знаків після коми.\n");
        scanf_result = scanf_s("%15lf", &a);
        fflush(stdin);
        if (scanf_result != 1 || a > 2 || a < 1 ) {
            printf("Некорректний ввід. Спробуйте ще раз. \n");
        }
    }while (scanf_result != 1  || a > 2 || a < 1);

    double b = 0;
    do {
        printf("Введіть b (від 1 до 2 включно):\n");
        printf("ПОПЕРЕДЖЕННЯ: Программа не зчитає більше 15 знаків після коми.\n");
        scanf_result = scanf_s("%15lf", &b);
        fflush(stdin);
        if (scanf_result != 1 || b > 2 || b < 1) {
            printf("Некорректний ввід. Спробуйте ще раз. \n");
        }
    }while (scanf_result != 1 || b > 2 || b < 1);

    double y = 0;
    do {
        printf("Введіть y (від 1 до 2 включно):\n");
        printf("ПОПЕРЕДЖЕННЯ: Программа не зчитає більше 15 знаків після коми.\n");
        scanf_result = scanf_s("%15lf", &y);
        fflush(stdin);
        if (scanf_result != 1 || y > 2 || y < 1) {
            printf("Некорректний ввід. Спробуйте ще раз. \n");
        }
    }while (scanf_result != 1 || y > 2 || y < 1);

    double eps = 0;
    do {
        printf("Введіть епсілон (від 1e-15 до 0.1:\n)");
        scanf_result = scanf_s("%lf", &eps);
        fflush(stdin);
        if (scanf_result != 1 || eps > 0.1 || eps < 1e-15) {
            printf("Ви виходите за межі. Будь ласка спробуйте ще раз.\n");
        }
    }while (scanf_result != 1 || eps > 0.1 || eps < 1e-15);



    double (*selected_f)(double,double) = NULL;
    printf("Оберіть рівняння яке хочете вирішити (1) або (2):\n");

    char variant_1 = 0;
    do {
        variant_1 = _getche(); //в експлорер буде зручно бачити що ти ввів. з _getch ти не бачиш шо вводиш. NOLINT
        if (variant_1 == 13 || variant_1 == 32) continue; //13 Enter, 32 Space
        if (variant_1 != 49 && variant_1 != 50) {
            printf("\nПОМИЛКА. Ви вводите некорректні дані\n");
        }
    }while (variant_1 != 49 && variant_1 != 50); //49 - '1'; 50 - '2'

 switch (variant_1) {
     case '1':
         selected_f = &uravnenie1;

         if (selected_f(a,y) * selected_f(b,y) > 0) { //перевірка чи існує на проміжку
             printf("\nУВАГА! На проміжку [%.2lf, %.2lf] коренів немає (функція не перетинає нуль).\n", a, b);
             printf("Метод може не спрацювати. Натисніть Enter для виходу.\n");
             getch();
             return 1; // Аварійне завершення
         }

         printf("\n\n Яким методом вирішити рівняння?\n");
         printf("1-Половинне ділення\n");
         printf("2-Ньютон\n");
         do {
             variant_1 = _getche(); //NOLINT
             if (variant_1 == 13 || variant_1 == 32) continue; //13 Enter, 32 Space
             if (variant_1 != 49 && variant_1 != 50) {
                 printf("\nПОМИЛКА. Ви вводите некорректні дані\n");
             }
         }while (variant_1 != 49 && variant_1 != 50); //49 - '1'; 50 - '2'

         double result = 0;

         switch (variant_1)
             {
             case '1':
                 result = polovina(selected_f, a, eps, b,y);
                 printf("\n\n Результат обчислень за половинним діленням: %.15lf\n", result);
                 printf("Программа завершила свою роботу. ENTER.\n");
                 getch();
                 break;

             case '2':
                 result = newton(selected_f, b, eps,y);
                 printf("\n\n Результат обчислень за Ньютоном: %.15lf\n", result);
                 printf("Программа завершила свою роботу.\n");
                 getch();
                 break;

                 default:
                 break;
             }
         break;


     case '2':
         selected_f = &uravnenie2;

         if (selected_f(a,y) * selected_f(b,y) > 0) { //перевірка чи існує на проміжку
             printf("\nУВАГА! На проміжку [%.2lf, %.2lf] коренів немає (функція не перетинає нуль).\n", a, b);
             printf("Метод може не спрацювати. Натисніть Enter для виходу.\n");
             getch();
             return 1; // Аварійне завершення
         }

         printf("\n\n Яким методом вирішити рівняння?\n");
         printf("1-Половинне ділення\n");
         printf("2-Ньютон\n");
         do {
             variant_1 = _getche(); //в експлорер буде зручно бачити що ти ввів. з _getch ти не бачиш шо вводиш. NOLINT
             if (variant_1 == 13 || variant_1 == 32) continue; //13 Enter, 32 Space
             if (variant_1 != 49 && variant_1 != 50) {
                 printf("\nПОМИЛКА. Ви вводите некорректні дані\n");
             }
         }while (variant_1 != 49 && variant_1 != 50); //49 - '1'; 50 - '2'

         double resul = 0;
         switch (variant_1) {
             case '1':
                 resul = polovina(selected_f, a, eps, b,y);
                 printf("\n\n Результат обчислень за половинним діленням: %.15lf\n", resul);
                 printf("Программа завершила свою робооту. \n");
                 getch();
                 break;
                 case '2':
                 resul = newton(selected_f, b, eps,y);
                 printf("\n\n Результвт обчислень за Ньютоном: %.15lf\n", resul);
                 printf("Программа завершила свою роботу.\n");
                 getch();
                 break;
                 default:
                 break;
         }
         break;

        default:
         break;
 }
    return 0;
}
