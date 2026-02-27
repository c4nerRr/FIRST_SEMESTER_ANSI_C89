#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sort (int *mass, int num) {
    int i,j, tmp;

    for(i=0;i<num-1;i++) {
        if (abs(mass[i]<10 || abs(mass[i]) > 99)) {
        continue; //скіп числа, зібльшує лічильник
        }
        for(j=i+1;j<num;j++) {

            if (abs(mass[j]<10 || abs(mass[j]) > 99)) {
                continue;
            }

            if (mass[j] > mass[i])
            {
                tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
        }
    }
}

int main() {
    short kolvo = 0;
    int scan_result = 0;
    do {
        printf("Введіть кількість символів в масиві -> ");
        scan_result = scanf_s("%hd",&kolvo);
        fflush(stdin);
        if (scan_result != 1) {
            printf("Помилка, спробуйте ще раз.\n");
        }
    } while (scan_result != 1);

    int *mass = (int*)calloc(kolvo, sizeof(int));
    if (mass == NULL) {
    printf("ERROR");
    exit(1);
}
    for (int i=0;i<kolvo;i++) {
        printf("Введіть %d елемент -> ",i+1);
        scanf_s("%d",&mass[i]);
        fflush(stdin);
    }

    sort(mass,kolvo);
    printf("Відсортовані числа: ");
    for (int i=0;i<kolvo;i++) {
        printf("%d ",mass[i]);
    }
    getchar();
    free(mass);
    return 0;
}