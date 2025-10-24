/*Пусть имеется следующее объявление структуры:
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
Написать функцию, принимающую структуру box по значению и отображающую все её члены.
А затем функцию, принимающую адрес структуры box и устанавливающую значение члена volume равным произведению остальных трёх членов*/

#include <stdio.h>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void box_output(struct box example)
{
    printf("%s made this box: height %.2f, width %.2f, length %.2f, volume %.2f\n", example.maker, example.height, example.width, example.length, example.volume);
}

void volume_calculate(struct box *example)
{
    example->volume = example->height * example->width * example->length;
}

int main(){

    struct box box_1 = {"James", 12.5, 10.5, 25, 0};

    volume_calculate(&box_1);
    box_output(box_1);

    return 0;
}