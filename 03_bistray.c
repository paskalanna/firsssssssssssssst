#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int bistray(int *arr, int start_arr, int arr_len, int k)
{
    int i = start_arr;
    int j = arr_len;
    int tmp, temp;
    if ((start_arr+arr_len)%2==1)
        temp = arr[(start_arr+arr_len-1)/2];
    else
        temp = arr[(start_arr+arr_len)/2];
    do
    {
        k++;
        while(arr[i]<temp)
        {
            i++;
            k++;
        }
        while(arr[j]>temp)
        {
            j--;
            k++;
        }
        k++;
        if (i <= j)
        {
            k++;
            if(i<j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                k++;
            }
            i++;
            j--;
        }
    }
    while (i<=j);
    k++;
    if (i < arr_len)
        bistray(arr, i, arr_len, k);
    k++;
    if (start_arr < j)
        bistray(arr, start_arr, j, k);
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
            count = bistray(arr,0, array_size[i]-1,0);
            count_1+=count;
            free(arr);
        }
        t=(clock()-t)/ CLOCKS_PER_SEC;
        printf("Array length (bistray): ");
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
