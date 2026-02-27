#include <stdio.h>
#include<conio.h>
#include<math.h>

typedef struct complex_ {
   double real;
   double imag;
}Complex_x;

Complex_x result(double a, double b, double c, double d) {
  Complex_x temp;
    temp.real =  (a*c+b*d)/(pow(c,2)+pow(d,2));
        temp.imag = (b*c-a*d)/(pow(c,2)+pow(d,2));

    return temp;
    //в даному випадку сума квадратів ніколи не буде нулем.
}

Complex_x res_1(double L, double C, double R, double f) {
   double kyt = 2*M_PI*f;
    double a = L/C;
    double b = -1*(R/(kyt*C));
    double c = R;
    double d = kyt*L-(1/(kyt*C));
    return result(a,b,c,d);
}

Complex_x res_2(double L, double C, double R, double f) {
    double kyt = 2*M_PI*f;
    double a = L/C;
    double b = 1*(R/(kyt*C));
    double c = R;
    double d = kyt*L-(1/(kyt*C));
    return result(a,b,c,d);
}

Complex_x res_3(double L, double C, double R, double R_1, double f) {
    double kyt = 2*M_PI*f;
    double a = R*R_1;
    double b = R*(kyt*L - (1/(kyt*C)));
    double c = R+R_1;
    double d = kyt*L-(1/(kyt*C));
    return result(a,b,c,d);
}

Complex_x res_4(double L, double C, double R, double R_1, double f) {
    double kyt = 2*M_PI*f;
    double a = R*R_1 + L/C;
    double b = (kyt*L*R - (R_1/(kyt*C)));
    double c = R+R_1;
    double d = kyt*L - (1/(kyt*C));
    return result(a,b,c,d);
}

int main () {
    printf("\n---Ця программа обчислює комплексний опір заданого коливального контуру в залежності від частоти струму---\n");
    printf("1) Z = ( (L/C) - i(R/Fi*C))/(R + i(Fi*L - (1/Fi*C)))\n");
    printf("2) Z = ( (L/C) + i(R/Fi*C))/(R + i(Fi*L - (1/Fi*C)))\n");
    printf("3) Z = ( R1*R2 + iR1(Fi*L - (1/Fi*C))/(R1 + R2 + i(Fi*L - (1/Fi*C)))\n");
    printf("4) Z = ( R1*R2 + (L/C) + i(Fi*L*R1 - (R2/Fi*C))/(R1 + R2 + i(Fi*L - (1/Fi*C)))\n");
   printf("Оберіть номер прикладу який бажаєте розв'язати -> ");
    char variant = 0;
    do {
        variant = _getche(); //NOLINT
        fflush(stdin);
        if (variant == 13 || variant == 32) {
            continue;
        }
        if (variant < '1' || variant > '4') {
            printf("\nНекорректні дані. Спробуйте ще раз.\n");
        }
    }while (variant < '1' || variant > '4');


    double fmin = 0;
    double fmax = 0;
    double df = 0;

    printf("---ПОПЕРЕДЖЕННЯ: Программа НЕ зчитає більше 15 знаків після коми.\n---");
    do {
        printf("\nВведіть fmin (від 1 до 900)-> ");
        scanf_s("%15lf", &fmin);
        fflush(stdin);
        if (fmin < 1 || fmin > 900) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
    }while (fmin < 1 || fmin > 900);

    do {
        printf("Введіть fmax(від 3 до 1000)(fmax повинен бути більше за fmin)-> ");
        scanf_s("%15lf", &fmax);
        fflush(stdin);
        if (fmax < 3 || fmax > 1000) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
        else if (fmax < fmin) {
            printf("fmax повинен бути більше fmin. Спробуйте ще раз\n");
        }
    }while (fmin > fmax || fmax < 3 || fmax > 1000);

    do {
        printf("Введіть df(від 1 до 1000) -> ");
        scanf_s("%15lf", &df);
        fflush(stdin);
        if (df<1 || df > 1000) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
        else if (df>fmax-fmin) {
            printf("Крок df повинен бути меншим за різницю fmax - fmin. Спробуйте ще раз.\n");
        }
    }while (df > fmax-fmin || df < 1 || df > 1000);

    double L = 0;
    double C = 0;
    double R = 0;

    do {
        printf("Введіть R1(від 1 до 100 000) -> ");
        scanf_s("%15lf", &R);
        fflush(stdin);
        if (R<1 || R>100000) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
    }while (R<1 || R>100000);

    do {
        printf("Введіть С(мкФ) (від 1 до 10 000) -> ");
        scanf_s("%15lf", &C);
        fflush(stdin);
        if (C<1 || C>10000) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
    }while (C<1 || C>10000);

    do {
        printf("Введіть L(мГн) (від 1 ло 1 000) -> ");
        scanf_s("%15lf", &L);
        fflush(stdin);
        if (L<1 || L>1000) {
            printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
        }
    }while (L<1 || L>1000);

    L *= 0.001;
    C *= 0.000001;

    double R_2 = 0;

    double f_0 = 1/(2*M_PI*sqrt(L*C));
    printf("Ось параметри вашого контуру, резонанс буде на такій-то частоті: %lf\n", f_0);
    double f = 0;
    switch (variant ) {
        //---------------------------------------------------------
        case '1':
            for (f=fmin; f<=fmax; f=f+df) {
                Complex_x Z;
                Z = res_1(L, C, R, f);
                printf("Результат обчислень: %.15lf + i*%.15lf\n", Z.real, Z.imag);
            }

            break;
        //---------------------------------------------------------
            case '2':
            for (f=fmin; f<=fmax; f=f+df) {
                Complex_x Z;
                Z = res_2(L, C, R, f);
                printf("Результат обчислень: %.15lf + i*%.15lf\n", Z.real, Z.imag);
            }
            break;
        //---------------------------------------------------------
            case '3':
            do {
                printf("Введіть R2(Ом) (від 1 до 100 000) -> ");
                scanf_s("%15lf", &R_2);
                fflush(stdin);
                if (R_2<1 || R_2>100000) {
                    printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
                }
            }while (R_2<1 || R_2>100000);
            for (f=fmin; f<=fmax; f=f+df) {
                Complex_x Z;
                Z = res_3(L, C, R, R_2, f);
                printf("Результат обчислень:  %.15lf + i*%.15lf\n", Z.real, Z.imag);
            }

            break;
        //---------------------------------------------------------
            case '4':
            do {
                printf("Введіть R2(Ом) (від 1 до 100 000) -> ");
                scanf_s("%15lf", &R_2);
                fflush(stdin);
                if (R_2<1 || R_2>100000) {
                    printf("ПОМИЛКА. Спробуйте ще раз та введіть корректні значення.\n");
                }
            }while (R_2<1 || R_2>100000);

            for (f=fmin; f<=fmax; f=f+df) {
                Complex_x Z;
                Z = res_4(L, C, R, R_2, f);
                printf("Результат обчислень:  %.15lf + i*%.15lf\n", Z.real, Z.imag);
            }
            break;
        //---------------------------------------------------------
            default:
            break;
    }
    printf("Программа завершила свою роботу. ENTER.\n");
    getch();
    return 0;
}