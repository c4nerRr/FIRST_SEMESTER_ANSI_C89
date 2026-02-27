#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

int main()
{
    printf("Ця програма рахує площу, периметр, медіани, бісектриси та висоти для ваших сторін трикутника А, Б, С. Щоб почати користуватись нажміть Enter.\n");
    getch();
    double a=0, b=0, c=0; //числа користувача.
    bool correct = false; //перевірка чи корректний ввод число/не число. 1/0.
    int m = 0; //
    while(true)
        {
            printf("Введіть сторону трикутника а від 1 до 1000: ");
            correct = scanf("%lf", &a); //lf це для double якщо число то в бул йде 1 якщо щось інше то в 0.
        if(correct == true) //сканф повертає 1 якщо очікуване 1 число справдилось - True. Повертає 0 якщо False до прикладу не число а літери.
            {
            break;
            }
        else
            {
            printf("Помилка. Введіть корректне число знову.\n");

            while ((m = getchar()) != '\n' && m != EOF) {} //еоф - енд оф файл. константа зі студіо. читає символи поки не буде кінець вводу. якщо цього не буде програма ламається
            }
        }


    //while ((a = getchar()) != '\n' && a != EOF) {} //при вводі НЕ числа сканф не спіткається о наступний. flush scan.
    while (true)
        {
            printf("Введіть сторону трикутника b від 1 до 1000:  ");
            correct = scanf("%lf", &b);
        if(correct == true)
            {
            break;
            }
        else
            {
            printf("Помилка. Введіть корректне число знову.\n");

            while ((m = getchar()) != '\n' && m != EOF) {}
            }
        }
   while (true)
    {
            printf("Введіть сторону трикутника с від 1 до 1000:\n\n  ");
            correct = scanf("%lf", &c);
      if(correct == true)
        {
        break;
        }
      else
        {
        printf("Помилка. Введіть корректне число знову.\n");
        while ((m = getchar()) != '\n' && m != EOF) {}
        }
    }

    //початок розрахунків:
  if (a>0 && b>0 && c>0 && a <=1000 && b<=1000 && c<=1000)
      {
      if (a+b>c && a+c>b && b+c>a)
          {
          //в іф треба буде записати сюди самі формули та розрахунки.
          double p = (a+b+c)/2.0;
          double S = 0;
            S=sqrt(p*(p-a)*(p-b)*(p-c));
          double Pa = 0;
            Pa = a+b+c;
          double h_a = 0;
          double h_b = 0;
          double h_c = 0;
              h_a = ((2.0*(sqrt(p*(p-a)*(p-b)*(p-c))))/a);   //в цілому можна просто написати (2*S)/а.
              h_b = ((2.0*(sqrt(p*(p-a)*(p-b)*(p-c))))/b);
              h_c = ((2.0*(sqrt(p*(p-a)*(p-b)*(p-c))))/c);
          double m_a = 0;
          double m_b = 0;
          double m_c = 0;
              m_a = 0.5*sqrt((2.0*pow(b,2.0))+(2.0*pow(c,2.0))-(pow(a,2.0)));
              m_b = 0.5*sqrt((2.0*pow(a,2.0))+(2.0*pow(c,2.0))-(pow(b,2.0)));
              m_c = 0.5*sqrt((2.0*pow(a,2.0))+(2.0*pow(b,2.0))-(pow(c,2.0)));
          double b_a = 0;
          double b_b = 0;
          double b_c = 0;
              b_a = (2.0/(b+c)*(sqrt(b*c*p*(p-a))));
              b_b = (2.0/(a+c)*(sqrt(a*c*p*(p-b))));
              b_c = (2.0/(a+b)*(sqrt(a*b*p*(p-c))));
          printf("Периметр:  %.12f\n\n", Pa);
          printf("Площа: %.12f\n\n", S);

          printf("Висота проведена до сторони а: %.12f\n", h_a);
          printf("Висота проведена до сторони b: %.12f\n", h_b);
          printf("Висота проведена до сторони c: %.12f\n\n", h_c);

          printf("Медіана проведена до сторони а: %.12f\n", m_a);
          printf("Медіана проведена до сторони b: %.12f\n", m_b);
          printf("Медіана проведена до сторони c: %.12f\n\n", m_c);

          printf("Бісектриса проведена до сторони а: %.12f\n", b_a);
          printf("Бісектриса проведена до сторони b: %.12f\n", b_b);
          printf("Бісектриса проведена до сторони c: %.12f\n\n", b_c);

          getch();
          }
      else
          {
          printf("Це не трикутник. Спробуйте ще раз.\n");
          getch();
          return 0;
          }
      }
  else
      {
      printf("Будь ласка спробуйте знову  та введіть число від 1 до 1000.");
      getch();
      }
    return 0;
}