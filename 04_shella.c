#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int Shella(int *arr, int arr_len)
{
    int step, tmp, j;
    int k = 0;
    for (step = arr_len / 2; step > 0; step /= 2)
        for (int i = step; i < arr_len; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                k++;
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
            k++;
        }
    return k;
}
int main()
{
    int i, j, y,count,count_1,str;
    float t, sr, tim;
    int array_size[15] = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500};
    const int line = 1000;
    int *arr;
 for (i=0; i < 15; i++)
    {
        t = clock();
        count = 0;
        count_1 = 0;
        for (j=0; j < line; j++ )
        {
            arr = (int*)malloc(array_size[i] * sizeof(int));
            for (y = 0; y < array_size[i]; y++)
            {
                arr[y] = rand();
            }
            count = Shella(arr, array_size[i]);
            count_1+=count;
            free(arr);
        }
        t=(clock()-t)/ CLOCKS_PER_SEC;
        printf("Array length (Shella): ");
        printf("%d", array_size[i]);
        printf("\n");
        printf("All operations: ");
        printf("%d", count_1);
        printf("\n");
        printf("time: ");
        printf("%f", t);
        printf("\n");
        sr = count_1*0.001;
        printf("Average number of operations: ");
        printf("%f", sr);
        printf("\n");
        tim = t;
        printf("Average number of time: ");
        printf("%f", tim);
        printf("\n");
        printf("\n");
    }
}
