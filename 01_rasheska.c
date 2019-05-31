#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int racheska(int *arr, int arr_len)
{
    int j = arr_len;
    bool step = true;
    int tmp;
    int k = 0;
    while (j > 1 || step == true)
    {
        if (j > 1)
            j /= 1.247f;
        step = false;
        for (int i = 0; i + j < arr_len; ++i)
        {
            k++;
            if (arr[i + j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + j];
                arr[i + j] = tmp;
                step = 1;
                k++;
            }
        }
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
    /// sorting 1000 massiv 1
    for (i=0; i < 15; i++)
    {
        t = clock();
        count = 0 ;
        count_1 = 0;
        for (j=0; j < line; j++ )
        {
            arr = (int*)malloc(array_size[i] * sizeof(int));
            for (y = 0; y < array_size[i]; y++)
            {
                arr[y] = rand();
            }
            count = racheska(arr, array_size[i]);
            count_1+=count;
            free(arr);
        }
        t=(clock()-t)/ CLOCKS_PER_SEC;
        printf("Array length (rasheska): ");
        printf("%d", array_size[i]);
        printf("\n");
        printf("All operations: ");
        printf("%d", count_1);
        printf("\n");
        printf("All time: ");
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
