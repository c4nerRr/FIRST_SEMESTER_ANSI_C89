#include <stdio.h>
#include <stdlib.h>

void sort (char *mass, int num) {
    int i,j, max_idx; //індекс макс
    char tmp; //свап одної літери
    for(i=0;i<num-1;i++) {
        max_idx = i;
        for(j=i+1;j<num;j++) {
            if ( mass[j] > mass[max_idx])
            {
                max_idx=j;
            }
        }
            if (max_idx != i) {
                tmp=mass[i];
                mass[i]=mass[max_idx];
                mass[max_idx]=tmp;
            }
    }
}

int main() {
    short kolvo = 0;
    int scan_res = 0;
    do {
        printf("Введіть кількість символів в масиві -> ");
        scan_res = scanf_s("%hd",&kolvo);
        fflush(stdin);
        if (scan_res != 1) {
            printf("Некорректні дані. Спробуйте знову. \n");
        }
    }while( scan_res != 1);
    char *mass = (char *)calloc(kolvo, sizeof(char));
    if (mass == NULL) {
        printf("FATAL ERROR, недостатньо пам'яті.");
        return 1;
    }

    printf("Будь ласка, вводьте 1 символ. Якщо буде більше, програма зчитає тільки перший.\n");
    for (int i = 0; i < kolvo; i++)
    {
        printf("Введіть  %d елемент ->", i+1);
        scanf(" %c",&mass[i]);
        fflush(stdin);
    }

    sort(mass,kolvo);
    printf("Відсортовані числа: ");
    for (int i = 0; i < kolvo; i++) {
        printf("%c ",mass[i]);
    }
    getchar();
    free(mass);
    return 0;
}



