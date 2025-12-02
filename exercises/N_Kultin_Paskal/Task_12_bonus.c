/*Игра в пьяницу
В игре участвует 10 "карт", имеющих значения: 0 1 2 3 4 5 6 7 8 9, большая "карта" побеждает меньшую, 0 побеждает 9
Программа получает на вход 2 строки с 5 значениями, разделенные пробелами. "Карты" перечислены сверху вниз.
Игрок, который забирает себе выигранные карты, сначала кладет вниз колоды карту Игрока-1, затем карту Игрока-2.
Программа должна определить, кто выигрывает при данной раздаче и вывести "1st" или "2nd", а также количество ходов, сделанных до выигрыша.
Если на протяжении 10^6 ходов игра не заканчивается - вывести слово "botva" */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct
{
    int *data;
    int idx_in;
    int idx_out;
    int count;
    int size;
} ring_buffer_t;

int has_duplicates(int data[], int size);
void generate_cards(int cards[]);
void dealing(int player1_cards[], int player2_cards[], int cards[]);

void ring_buffer_init(ring_buffer_t *rb, int *data, int count, int size);
int ring_buffer_pop(ring_buffer_t *rb);
void ring_buffer_push(ring_buffer_t *rb, int item);

int main()
{
    int cards[SIZE];
    int cards_p1[SIZE];
    int cards_p2[SIZE];
    int steps = 0;
    ring_buffer_t player1;
    ring_buffer_t player2;

    generate_cards(cards);
    dealing(cards_p1, cards_p2, cards);
    ring_buffer_init(&player1, cards_p1, SIZE/2, SIZE);
    ring_buffer_init(&player2, cards_p2, SIZE/2, SIZE);

    printf("Player 1 cards: ");
    for (int i = 0; i < SIZE/2; i++)
    {
        printf("%d ", player1.data[i]);
    }
    printf("\nPlayer 2 cards: ");
    for (int i = 0; i < SIZE/2; i++)
    {
        printf("%d ", player2.data[i]);
    }
    printf("\n");

    while (player1.count > 0 && player2.count > 0 && steps < 1000 * 1000)
    {
        int current_card_p1 = ring_buffer_pop(&player1);
        int current_card_p2 = ring_buffer_pop(&player2);

        if (current_card_p1 > current_card_p2 || (current_card_p1 == 0 && current_card_p2 == 9))
        {
            ring_buffer_push(&player1, current_card_p1);
            ring_buffer_push(&player1, current_card_p2);
        }
        
        if (current_card_p2 > current_card_p1 || (current_card_p2 == 0 && current_card_p1 == 9))
        {
            ring_buffer_push(&player2, current_card_p2);
            ring_buffer_push(&player2, current_card_p1);
        }

        steps++;
    }
    
    if (steps > 1000 * 1000)
    {
        printf("Botva!\n");
    }
    else if (player1.count == SIZE)
    {
        printf("1st wins! by %d steps\n", steps);
    }
    else
    {
        printf("2nd wins! by %d steps\n", steps);
    } 
    
    return 0;
}

int has_duplicates(int data[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (data[i] == data[j])
            {
                return j;
            }
        }
    }
    return -1;
}

void generate_cards(int cards[])
{
    int duplicate_idx;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        cards[i] = rand() % SIZE;
    }

    do
    {
        duplicate_idx = has_duplicates(cards, SIZE);
        if (duplicate_idx >= 0)
        {
            cards[duplicate_idx] = rand() % SIZE;
        }    
    } while (duplicate_idx != -1);
}

void dealing(int player1_cards[], int player2_cards[], int cards[])
{
    int player1_idx = 0;
    int player2_idx = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            player1_cards[player1_idx] = cards[i];
            player1_idx++;
        }
        else
        {
            player2_cards[player2_idx] = cards[i];
            player2_idx++;
        }
    }
}

void ring_buffer_init(ring_buffer_t *rb, int *data, int count, int size)
{
    if (rb != NULL && data != NULL && size > 0)
    {
        rb->data = data;
        rb->size = size;
        rb->idx_in = count;
        rb->idx_out = 0;
        rb->count = count;
    }
}

int ring_buffer_pop(ring_buffer_t *rb)
{
    int current_card;

    if (rb != NULL, rb->count > 0)
    {
        current_card = rb->data[rb->idx_out];
        rb->idx_out = (rb->idx_out + 1) % SIZE;
        rb->count--;
    }
    
    return current_card;
}

void ring_buffer_push(ring_buffer_t *rb, int item)
{
    if (rb != NULL && rb->count < rb->size)
    {
        rb->data[rb->idx_in] = item;
        rb->idx_in = (rb->idx_in + 1) % SIZE;
        rb->count++;
    }
}