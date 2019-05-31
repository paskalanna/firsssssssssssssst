#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int Heap(int *arr, int root, int base, int k)
{
    int max;
    bool flag = false;
    while ((root * 2 <= base) && (!flag))
    {
        if (root * 2 == base)
            max = root * 2;
        else if (arr[root * 2] > arr[root * 2 + 1])
            max = root * 2;
        else
            max = root * 2 + 1;
        k++;
        if (arr[root] < arr[max])
        {
            int temp = arr[root];
            arr[root] = arr[max];
            arr[max] = temp;
            root = max;
            k++;
        }
        else
            flag = true;
    }
    return k;
}
int piramid(int *arr, int arr_len)
{
    int k = 0;
    int i = (arr_len / 2) - 1;
    int j = arr_len - 1;
    int temp;
    for (i; i >= 0; i--)
    {
        k++;
        k = Heap(arr, i, arr_len - 1, k);
    }
    for (j; j >= 1; j--)
    {
        temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        k++;
        k = Heap(arr, 0, j - 1, k);
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
            count = piramid(arr, array_size[i]);
            count_1+=count;
            free(arr);
        }
        t=(clock()-t)/ CLOCKS_PER_SEC;
        printf("Array length (piramid): ");
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
