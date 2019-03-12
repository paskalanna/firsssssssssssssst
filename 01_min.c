#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n = 0,min = 0;
printf("Введите количество элементов: ");
scanf("%d",&n);
unsigned int x[n];
for (int i=0;i<n;i++)
{
	x[i]=0+rand()%2147483647;
	printf("%d\n", x[i]);
}
min=x[0];
for (int i=0;i<n;i++)
{
	if (min>x[i])
		min=x[i];
}
printf("%d",min);
}
 
