#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_REGION_LEN 39
#define MAGIC_NUMBER 0xDEADBEEF

// з вказівником
typedef struct {
    char *region;
    float square;
    float population;
} Record;

// фіксований розмір
typedef struct {
    char region_data[MAX_REGION_LEN + 1];
    float square;
    float population;
} DiskRecord;

int is_file_opened = 0;
char current_file_name[50] = "";

// Прототипи
void print_menu(void);
void create_file(void);
void open_file(void);
void add_record(int sort_needed);
void delete_record(void);
void delete_file(void);
void edit_record(void);
void sort_file(void);
void view_records(void);
void safe_input_string(char *buffer, int size);

// Допоміжна функція: конвертує DiskRecord у Record
Record disk_to_mem(DiskRecord dr) {
    Record r;
    r.square = dr.square;
    r.population = dr.population;
    // Виділяємо пам'ять під рядок
    r.region = (char*)malloc(strlen(dr.region_data) + 1);
    if (r.region) strcpy(r.region, dr.region_data);
    return r;
}

// Допоміжна функція: конвертує Record у DiskRecord
DiskRecord mem_to_disk(Record r) {
    DiskRecord dr;
    dr.square = r.square;
    dr.population = r.population;
    // обрізаючи зайве
    strncpy(dr.region_data, r.region, MAX_REGION_LEN);
    dr.region_data[MAX_REGION_LEN] = '\0';
    return dr;
}

void print_menu(){
    system("cls");
    printf("=== Файл-менеджер ===\n");
    if (is_file_opened) {
        printf(" [ВІДКРИТО ФАЙЛ]: %s\n", current_file_name);
    } else {
        printf(" [NO FILE] - Відкрийте або створіть новий.\n");
    }
    printf("----------------------------------------\n");
    printf(" 0 - Створити новий файл\n");
    printf(" 1 - Відкрити існуючий файл\n");
    printf(" 2 - Додати запис\n");
    printf(" 3 - Видалити запис за ідентифікатором\n");
    printf(" 4 - Видалити весь файл\n");
    printf(" 5 - Редагувати запис\n");
    printf(" 6 - Сортувати файл (бульбашкове сортування через ОП)\n");
    printf(" 7 - Вставити запис\n");
    printf(" 8 - Переглянути всі записи\n");
    printf(" 9 - Вихід\n");
    printf("----------------------------------------\n");
}

//зхищений ввід рядка бо scanf - зло
void safe_input_string(char *buffer, int size) {
    do {
        fflush(stdin);
        if (fgets(buffer, size, stdin) == NULL) {
            buffer[0] = '\0';
            return;
        }
        char *p = strchr(buffer, '\n');
        if (p != NULL) {
            *p = '\0';
        }
        else {
            int c = 0;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }while (strlen(buffer) == 0); //якщо зчитано тіко ентерь
}

void create_file(){
    char temp_name[50];
    FILE *f;

    printf("\n--- Створення файлу(Для повернення в меню натисніть 0) ---\n");
    printf("Введіть ім'я файлу(не більше 50 симовлів) (e.g., data.bin): ");
    safe_input_string(temp_name, sizeof(temp_name));
    //повернення в меню бо бісить
    if (strcmp(temp_name, "0") == 0) {
        printf("Скасовано. Повертаємось в меню...\n");
        return;
    }


    f = fopen(temp_name, "rb");
    if (f != NULL) {
        fclose(f);
        printf("\nERROR: Файл '%s' вже існує! Спробуйте інше ім'я.\n", temp_name);
        getch();
        return;
    }

    f = fopen(temp_name, "wb");
    if(f == NULL){
        perror("Error! Захист від запису на диск..\n");
        getch();
        return;
    }

    // сігна
    int magic = MAGIC_NUMBER;
    fwrite(&magic, sizeof(int), 1, f);

    fclose(f);
    printf("Файл був успішно створений! Натисніть ENTER.\n");
    strcpy(current_file_name, temp_name);
    is_file_opened = 1;
    getch();
}

void open_file(){
    char temp_name[50];
    FILE *f;
    int magic;

    printf("\n--- Open File(Для повернення в меню натисніть 0) ---\n");
    printf("Введіть ім'я файлу: ");
    safe_input_string(temp_name, 50);

    if (strcmp(temp_name, "0") == 0) {
        return;
    }

    f = fopen(temp_name, "rb");
    if(f == NULL){
        perror("\nERROR: Файл не було знайдено. Натисніть ENTER\n");
        getch();
        return;
    }

    // Перевірка сігни
    if (fread(&magic, sizeof(int), 1, f) != 1 || magic != MAGIC_NUMBER) {
        perror("\nERROR: Підпис недійсний!\n");
        fclose(f);
        getch();
        return;
    }

    fclose(f);
    strcpy(current_file_name, temp_name);
    is_file_opened = 1;
    printf("Файл відкрито. Натисніть ENTER для продовження.\n");
    getch();
}

void add_record(int sort_needed){
    if(!is_file_opened){ perror("No file opened!\n");
        getch();
        return;
    }

    Record rec;
    char buffer[MAX_REGION_LEN + 1];

    printf("\n--- Додати запис ---\n");
    printf("ВВедіть  Region: ");
    safe_input_string(buffer,  sizeof(buffer));

    //пам'ять під вказівник
    rec.region = (char*)malloc(strlen(buffer) + 1);
    strcpy(rec.region, buffer);
    int check;


    do {
        printf("Введіть Square (від 1 до 100 000): ");
        check = scanf_s("%7f", &rec.square); // Зчитуємо саме ПЛОЩУ
        fflush(stdin);

        if (check != 1.0 || rec.square < 1.0 || rec.square > 100000.0) {
            printf("Будь ласка, введіть лише цифри!\n");
            fflush(stdin); // Очистка буфера (працює у Visual Studio)
        }
    } while (check != 1.0 || rec.square < 1.0 || rec.square > 100000.0);


    do {
        printf("Введіть Population від 1 до 2000000: ");
        check = scanf_s("%7f", &rec.population);

        if (check != 1.0 || rec.population < 1.0 || rec.population > 2000000.0) {
            // Ввели букви
            printf("Тільки цифри, будь ласка!\n");
            fflush(stdin);
         }
        } while (check != 1.0 || rec.population < 1.0 || rec.population > 2000000.0);


    FILE *f = fopen(current_file_name, "ab"); // Append binary
    if (!f) {
        free(rec.region);
        return;
    }

    // дисковий формат перед записом
    DiskRecord dr = mem_to_disk(rec);
    fwrite(&dr, sizeof(DiskRecord), 1, f);
    fclose(f);


    free(rec.region);

    if (sort_needed) {
        printf("Вставка передбачає дотримання порядку. Сортування зараз...\n");
        sort_file();
    } else {
        printf("Запис додано.\n");
        getch();
    }

}

void view_records(){
    if(!is_file_opened) {
        perror("Файл не відкрито!\n");
        getch();
        return;
    }

    FILE *f = fopen(current_file_name, "rb");
    if (!f) return;

    // пропускаємо сигнатуру
    fseek(f, sizeof(int), SEEK_SET);

    DiskRecord dr = { 0 };
    int i = 1;

    printf("\n--- Список записів ---\n");
    printf("ID | Region               | Square    | Population\n");
    printf("---|----------------------|-----------|-----------\n");

    size_t result;
    do {
        //читаємо
        result = fread(&dr, sizeof(DiskRecord), 1, f);
        fflush(stdin);

        if (result == 1) {
            Record r = disk_to_mem(dr);
            if (r.region != NULL) {
                printf("%-2d | %-20s | %-9.2f | %-9.2f\n", i++, r.region, r.square, r.population);
                // Звільняємо пам'ять
                free(r.region); //NOLINT
                r.region = NULL;
            }
        }
    } while (result == 1);

    fclose(f);
    printf("--------------------\n");
    getch();
}

void delete_record(){
    if(!is_file_opened) {
        perror("No file opened!\n");
        getch();
        return;
    }


    int id, current = 1, found = 0;

    view_records(); //показ шо видалити
    int scan_res = 0;
    do {
        printf("Введіть ID запису для видалення: ");
        scan_res = scanf_s("%d", &id);
        fflush(stdin);
    }while (scan_res != 1);


    FILE *f = fopen(current_file_name, "rb");
    FILE *temp = fopen("temp.tmp", "wb");
    if (temp == NULL) {
        perror("Помилка створення тимчасового файлу.\n");
        getch();
        fclose(f);
        return;
    }

    // копі сігна
    int magic;
    fread(&magic, sizeof(int), 1, f);
    fwrite(&magic, sizeof(int), 1, temp);

    DiskRecord dr;
    while(fread(&dr, sizeof(DiskRecord), 1, f) == 1){
        if (current != id) {
            fwrite(&dr, sizeof(DiskRecord), 1, temp);
        } else {
            found = 1;
        }
        current++;
    }

    fclose(f);
    fclose(temp);

    remove(current_file_name);
    rename("temp.tmp", current_file_name);

    if(found) {
        printf("Видалення успішне.\n");
    }
    else {
        printf("ID не знайдено.\n");
    }
    getch();
}

void edit_record(){
    if(!is_file_opened) {
        perror("No file opened!\n");
        getch();
        return;
    }

    int id = 0;
    view_records();
    int scan_res = 0;
    do {
        printf("Введіть ID щоб редагувати(натисніть 0 щоб повернутися в меню.): ");
        scan_res = scanf_s("%d", &id);
        if (scan_res != 1) {
            printf("Помилка! Ви вводите некорректні дані. Спробуйте ще раз.\n");
        }
        else if (id == 0) {
            printf("Скасовано, повернення в меню...");
            return;
        }
        fflush(stdin);
    }while (scan_res != 1);

    FILE *f = fopen(current_file_name, "rb+");

    // сігна + (ID-1) * розмір_запису
    long long offset = (long long)sizeof(int) + (id - 1) * (long long)sizeof(DiskRecord);

    if (_fseeki64(f, offset, SEEK_SET) != 0) {
        perror("Seek error.\n");
        fclose(f);
        getch();
        return;
    }

    DiskRecord dr;
    if (fread(&dr, sizeof(DiskRecord), 1, f) != 1) {
        perror("Запис не знайдено.\n");
        fclose(f);
        getch();
        return;
    }

    printf("Редагування: %s\n", dr.region_data);

    // Нові дані
    Record temp_rec;
    char buffer[MAX_REGION_LEN + 1];

    printf("Введіть новий Region: ");
    safe_input_string(buffer, sizeof(buffer));
    temp_rec.region = buffer; // Тимчасово, для конвертації
    int check;
do {
    printf("Введіть новий Squart: ");
    check = scanf_s("%7f", &temp_rec.square);
    fflush(stdin);
    if (check != 1.0 || temp_rec.square < 1.0 || temp_rec.square > 100000.0) {
        printf("Помилка! Ви вводите некорректні дані. Спробуйте ще раз.\n");
    }
}while (check != 1.0 || temp_rec.square < 1.0 || temp_rec.square > 100000.0);

    do {
        printf("Введіть нову Population: ");
        check = scanf_s("%7f", &temp_rec.population);
        fflush(stdin);
        if (check != 1 || temp_rec.population < 1 || temp_rec.population > 2000000.0) {
            printf("Помилка! Ви вводите некорректні дані. Спробуйте ще раз\n");
        }
    }while (check != 1 || temp_rec.population < 1 || temp_rec.population > 2000000.0);

    // Конвертуємо назад в DiskRecord
    dr = mem_to_disk(temp_rec);

    // Повертаємося назад, щоб перезаписати
    _fseeki64(f, offset, SEEK_SET);
    fwrite(&dr, sizeof(DiskRecord), 1, f);

    fclose(f);
    printf("Успішно оновлено.\n");
    getch();
}

void delete_file(){
    if(!is_file_opened) {
        perror("No file opened!\n");
        getch();
        return;
    }
    char c = 0;
    do {
        printf("Ви впевнені? Це назавжди. (y/n): ");
        c = _getche(); //NOLINT
        fflush(stdin);
        if(c == 'y'){
            if(remove(current_file_name) == 0){
                printf("\nФайл видалено.\n");
                is_file_opened = 0;
                current_file_name[0] = '\0';
            } else {
                printf("\nВидалення не було здійснено.\n");
            }
        }
        getch();
    }while (c != 'y' && c != 'n');
}

// функція сортування/ вставки
void sort_file(){
    if(!is_file_opened){
        perror("No file opened!\n");
        getch();
        return;
    }

    //читаємо весь файл в RAM
    FILE *f = fopen(current_file_name, "rb");
    _fseeki64(f, 0, SEEK_END);
    long size = ftell(f) - (long)sizeof(int); // мінус сігна
    int count = (int)size / (long)sizeof(DiskRecord);

    if (count < 2) {
        fclose(f);
        return;
    } //нема шо сортувати

    DiskRecord *arr = (DiskRecord*)calloc(count, sizeof(DiskRecord));
    if (arr == NULL) {
        perror("Не вистачає пам'яті для сортування!");
        getch();
        fclose(f);
        return;
    }
    _fseeki64(f, sizeof(int), SEEK_SET); //пропускаємо сігну
    fread(arr, sizeof(DiskRecord), count, f);
    fclose(f);

    //захардкод вибір як меню
    char field = 0;
    char order = 0;
    do {
        printf("Сортувати за: 1-Регіоном, 2-Площею, 3-Популяцією: ");
        field = _getche(); //NOLINT
        fflush(stdin);
        if (field != '1' && field != '2' && field != '3') {
            printf("ПОМИЛКА. Ви вводите некорректні дані. Спробуйте ще раз\n");
        }
    }while (field != '1' && field != '2' && field != '3');

    do {
        printf("\nOrder: 1-Asc (0->9), 2-Desc (9->0): ");
        order = _getche(); //NOLINT
        fflush(stdin);
        if (order != '1' && order != '2') {
            printf("ПОМИЛКА. Ви вводите некорректні дані. Спробуйте ще раз\n");
        }
    }while (order != '1' && order!= '2');

    // (bubble sort, вибачте)
    DiskRecord temp;
    for(int i=0; i<count-1; i++){
        for(int j=0; j<count-i-1; j++){
            int condition = 0;

            if(field == '1') { // String compare
                int cmp = strcmp(arr[j].region_data, arr[j+1].region_data);
                if (order == '1') condition = (cmp > 0);
                else condition = (cmp < 0);
            } else if (field == '2') { // Float compare
                if (order == '1') condition = (arr[j].square > arr[j+1].square);
                else condition = (arr[j].square < arr[j+1].square);
            } else {
                if (order == '1') condition = (arr[j].population > arr[j+1].population);
                else condition = (arr[j].population < arr[j+1].population);
            }

            if(condition) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // пишемо назад у файл
    f = fopen(current_file_name, "wb");
    int magic = MAGIC_NUMBER;
    fwrite(&magic, sizeof(int), 1, f);
    fwrite(arr, sizeof(DiskRecord), count, f);

    free(arr);
    fclose(f);
    printf("\nУспішно відсортовано.\n");
    getch();
}

int main() {
    char choice;
    do{
        print_menu();
        do {
            printf("Дія > ");
            choice = _getche(); //NOLINT
            printf("\n");
            fflush(stdin);

            if (choice < '0' || choice > '9') {
                while (_kbhit()) {
                    _getch();
                }
                printf(">>Ви виходите за межі або вводите некорректні дані. Спробуйте ще раз.\n");
            }
        }while (choice < '0' || choice > '9');

        switch(choice){
            case '0':
                create_file();
                break;
            case '1':
                open_file();
                break;
            case '2':
                add_record(0);
                break; // Просто додати
            case '3':
                delete_record();
                break;
            case '4':
                delete_file();
                break;
            case '5':
                edit_record();
                break;
            case '6':
                sort_file();
                break;
            case '7':
                add_record(1);
                break; // додати і посортувати
            case '8':
                view_records();
                break;
            case '9':
                printf("\nБувай\n");
                break;
            default:
                printf("\nМісклік?\n");
                getch();
        }
    } while (choice != '9');
    return 0;
}