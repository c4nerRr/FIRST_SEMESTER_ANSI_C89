

/*int main() {
   //попробуем самостоятельно
    printf("How many students: ");
    int count = 0;
    scanf_s("%d", &count);
    int *students = calloc(count, sizeof(int));

    if (students == NULL) {
        printf("Memory allocation error");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        students[i] = i*10;
    }

    printf("Student get: %d points", students[count-1]);
    free(students);
    return 0;

  }*/

//Вся суть данного задания заключатся в том, чтобы комп выделил мне память
//размер которой я ИЗНАЧАЛЬНО НЕ знаю.
//но узнала во время работы программы


/*void useless_raise(int money) {
    money = 10000; //Меняется только локальная копия мани
    printf("YAMI, i`m rich bitch \n", money);
}

void real_raise (int *ptr_money) {
    *ptr_money = 100000; //Мы пошли по адресу и перезаписали значение той самой ячейки
}
int main() {
    int my_salary = 500;
    //Попытка 1(фигня)
    useless_raise(my_salary);
    printf("Your salary is 1: %d\n", my_salary);

    getchar();
    //Попытка 2(Указатели спасают жизнь)
    real_raise(&my_salary);//Отправляем адрес (&) переменной
    printf("Your salary is 2: %d\n", my_salary);
    return 0;
}*/



#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void panic_mode (int *task) {
    *task = 100;
}

int main () {
    printf("Сколько задач вы хотите добавить?");
    int n_zadach = 0;
    scanf_s("%d", &n_zadach);
    int *chto_to_adekvatnoe = (int *)calloc(n_zadach, sizeof(int));
    int counter = 0;
    /*for (int i = 0; i < n_zadach; i++) {
        printf("Введите приоритет %d задачи: ", i + 1);
        scanf_s("%d", &chto_to_adekvatnoe[i]);
    }
 for (int i = 0; i < n_zadach; i++) {
     if (chto_to_adekvatnoe[i] > 5) {
         printf("%d ", chto_to_adekvatnoe[i]);
         counter++;
     }
 }*/
    panic_mode(&n_zadach);
    printf("Приоритеты поменялись! Теперь нужно сделать ВСЕ. Приоритеты задач = %d\n", n_zadach);
    printf("Осталось задач: %d \n", counter);
    getch();
    free(chto_to_adekvatnoe);
    return 0;
}