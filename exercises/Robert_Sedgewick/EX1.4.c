/*Упражнение 1.4. Приведите содержимое массива id после выполнения каждой операции union
при использовании алгоритма быстрого поиска (программа 1.1) для решения задачи связности
для последовательности 0-2, 1-4, 2-5, 3-6, 0-4, 6-0 и 1-3.
Укажите также количество обращений программы к массиву id для каждой вводимой пары. 
Упражнение 1.5. То же задание, только с алгоритмом быстрого объединения. 
Упражнение 1.6. То же задание, только с алгоритмом взвешенного объединения. */

#include <stdio.h>

#define N 10
#define QUICK_FIND   1
#define QUICK_UNION  2
#define WEIGHTED_UNION  3
#define WEIGHTED_UNION_PATH_COMPRESSION 4
#define CURRENT_ALG WEIGHTED_UNION_PATH_COMPRESSION

void call_alg(int alg_type);

int main()
{
    int i, p, q, t, count, id[N];
    for (i = 0; i < N; i++)
    {
        id[i] = i;
    }

#if CURRENT_ALG != QUICK_FIND
    int j;
#endif

#if (CURRENT_ALG == WEIGHTED_UNION || CURRENT_ALG == WEIGHTED_UNION_PATH_COMPRESSION)
    int sz[N];
    for (i = 0; i < N; i++)
    {
        sz[i] = 1;
    }   
#endif

    count = 0;
    while (scanf("%d %d", &p, &q) == 2)
    {
#if CURRENT_ALG == QUICK_FIND
        if (id[p] == id[q])
        {
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
            count += 2;
            continue;
        }

        t = id[p];
        count += (N+1);
        for (i = 0; i < N; i++)
        {
            if (id[i] == t)
            {
                id[i] = id[q];
                printf("\t");
                for (i = 0; i < N; i++)
                {
                    printf(" %d", id[i]);
                }
                count += 2;
                printf("\n");
            }
        }

#elif CURRENT_ALG == QUICK_UNION
        int j;
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        
        if (i == j)
        {
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
            count += 4;
            continue;
        }
        id[i] = j;
        printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
        count += 5;

#elif CURRENT_ALG == WEIGHTED_UNION
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        count += 4;
        
        if (i == j)
        {
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
            continue;
        }
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
            count ++;
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
            count ++;
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
        }
#elif CURRENT_ALG == WEIGHTED_UNION_PATH_COMPRESSION
        for (i = p; i != id[i]; i = id[i])
        {
            id[i] = id[id[i]];
        }
        for (j = q; j != id[j]; j = id[j])
        {
            id[j] = id[id[j]];
        }
        count += 10;

        if (i == j)
        {
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
            continue;
        }
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
            count ++;
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
            count ++;
            printf("\t");
            for (i = 0; i < N; i++)
            {
                printf(" %d", id[i]);
            }
            printf("\n");
        }
#endif
    }
    printf("\nNumber of array accesses: %d\n", count);

    return 0;
}