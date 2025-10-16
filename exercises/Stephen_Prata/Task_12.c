/*Следующая задача:
Разработать структура по имени Car, которая будет хранить следующую информацию об автомобиле:
название производителя (строка в символьном массиве), а также год выпуска автомобиля в виде целого числа.
Написать программу, которая запросит у пользователя количество автомобилей, которые нужно внести в каталог. 
Затем программа должна применить new для создания динамического массива структур Car указанного пользователем размера. 
Далее она должна пригласить пользователя ввести название производителя и год выпуска для наполнения данными каждой структуры в массиве. 
И, наконец, программа должна отобразить содержимое каждой структуры.
Пример запуска:
Сколько автомобилей внести в каталог? 2
Автомобиль №1:
Введите производителя: Hudson Hornet
Укажите год выпуска: 1952
Автомобиль №2:
Введите производителя: Kaiser
Укажите год выпуска: 1951
Вот ваша коллекция:
1952 Hudson Hornet
1951 Kaiser */

#include <stdio.h>
#include <stdlib.h>

struct car {
    char brand[50];
    int year;
};

int main(){

    int count = 0;
    printf("Enter the number of cars: ");
    scanf("%d", &count);

    struct car *cars = (struct car*)malloc(count * sizeof(struct car));
    if (cars == NULL){
        printf("Memory error\n");
        return 1;
    }

    for(int i = 0; i < count; i++){
        printf("===The car number %d===\n", i+1);
        printf("Enter the brand: ");
        scanf("%49s", cars[i].brand);
        printf("Enter the year: ");
        scanf("%d", &cars[i].year);
    }

    printf("Here is your collection:\n");
    for(int i = 0; i < count; i++){
        printf("%d %s\n", cars[i].year, cars[i].brand);
    }

    free (cars);

    return 0;
}

