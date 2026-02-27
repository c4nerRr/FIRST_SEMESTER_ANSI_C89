
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    printf("Вітаю. Программа обчислює кубічне рівняння x^3 + ax^2 + bx + c = 0, дe а, b, c - задані коефіцієнти рівняння.\n");
    getchar();
    fflush(stdin);
    setColor(12);
    printf("[ПОПЕРЕДЖЕННЯ: Програма враховує приблизно 15–16 значущих цифр (не лише після коми, а загалом).]\n");
    printf("Задля корректних розрахунків рекомендується вводити числа більше 1е15/1е-15.\n");
    getchar();
    fflush(stdin);


  double a,b,c;
    int mami = 0;
    int dota2 = 0;

    setColor(7);
  printf("Введіть коефіцієнти a:");
    mami = scanf_s("%lf",&a);
    while (mami != 1)
    {
        setColor(12);
        printf("Це не число, спробуйте ввести коефіцієнти а ще раз:\n");
        fflush(stdin);
        mami = scanf_s("%lf",&a);
        while ((dota2 = getchar()) != '\n' && dota2 != EOF);
    }
    setColor(7);
  printf("Введіть коєфіцієнти b:");
    mami = scanf_s("%lf",&b);
    while (mami != 1)
    {
        setColor(12);
        printf("Це не число, спробуйте ввести коефіцієнти b ще раз:\n");
        fflush(stdin);
        mami = scanf_s("%lf",&b);
        while ((dota2 = getchar()) != '\n' && dota2 != EOF);
    }
    setColor(7);
  printf("Введіть коєфіцієнти c:");
    mami = scanf_s("%lf",&c);
    while (mami != 1)
    {
        setColor(12);
        printf("Це не число, спробуйте ввести коефіцієнти c ще раз:\n");
        fflush(stdin);
        mami = scanf_s("%lf",&c);
        while ((dota2 = getchar()) != '\n' && dota2 != EOF);
    }

         if (a == 0.0 && b == 0.0 && c == 0.0)
             {
                printf("Ви ввели коефіцієнти 0. Відповідь буде 0.\n");
                getch();
                return 0;
             }
        double p = b - (pow(a,2.0)/3.0);
        double q = (2.0*pow(a,3.0)/27.0)-((a*b)/3.0)+c;

        double D = (pow(p,3.0)/27.0) + (pow(q,2.0)/4.0);

        // - - - - - - - - - - - - - - - -  - -   - - - -  - - - - - -
        const double eps = 1e-15;
        if (D>eps)
        {
            double y_u = -q/2.0 + sqrt(D);
            double y_uu = -q/2.0 - sqrt(D);

            double u = (y_u > 0) ? pow(y_u, 1.0/3.0) : (pow(fabs(y_u), 1.0/3.0) * -1.0);
            double uu = (y_uu > 0) ? pow(y_uu, 1.0/3.0) : (pow(fabs(y_uu), 1.0/3.0) * -1.0);

            double y1 = u + uu;

            double y2_fr = -(u+uu)/2.0;
            double y3_fr = y2_fr;

            double y23_im =  fabs(u - uu) * sqrt(3.0) / 2.0; //комплексна частина 2 з формули

            // - - - - - - -  - - - - - - - - - -
            double x1_1 = y1 - a/3.0;
            double x2_1 = y2_fr - a/3.0;
            double x3_1 = y3_fr - a/3.0;
            setColor(10);
            printf("x1 = %.6f\n",x1_1);
            printf("x2 = %.6f + %.6f*i\n",x2_1, y23_im);
            printf("x3 = %.6f - %.6f*i\n",x3_1, fabs(y23_im));
            setColor(7);
            printf("Програма завершила свою роботу, натисніть Enter для завершення.\n\n");
            getch();
            return 0;
        }
        else if (D<eps)
        {
            double r = sqrt(-pow(p,3.0)/27.0);
            double fi = acos((-q/2.0)/r);

            double y1_2 = 2.0*cbrt(r)*cos(fi/3.0);
            double y2_2 = 2.0*cbrt(r)*cos((fi+2.0*M_PI)/3.0);
            double y2_3 = 2.0*cbrt(r)*cos((fi+4.0*M_PI)/3.0);
            // - - - - - - - - - - - - - - - - - - - - -
            double x2_1 = y1_2 - a/3.0;
            double x2_2 = y2_2 - a/3.0;
            double x2_3 = y2_3 - a/3.0;
            printf("x1 = %.6f\n", x2_1);
            printf("x2 = %.6f\n", x2_2);
            printf("x3 = %.6f\n", x2_3);
            setColor(7);
            printf("Програма завершила свою роботу, натисніть Enter для завершення.\n\n");
            getch();
            return 0;
        }
        else //дискрім = 0
        {
            double y1_3 = 3.0*q/p;
            double y2_3 = -3.0*q/(2.0*p);
            double y3_3 = y2_3;
            // - - - - - - - - - - -
            double x3_1 = y1_3 - a/3.0;
            double x3_2 = y2_3 - a/3.0;
            double x3_3 = y3_3 - a/3.0;
            printf("x1 = %.6f\n",x3_1);
            printf("x2 = %.6f\n",x3_2);
            printf("x3 = %.6f\n",x3_3);
            setColor(7);
            printf("Програма завершила свою роботу, натисніть Enter для завершення.\n\n");
            getch();
            return 0;
        }

}