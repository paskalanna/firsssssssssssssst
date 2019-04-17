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
	scanf("%d",&x[i]);
}
min=x[0];
for (int i=0;i<n;i++)
{
	if (min>x[i])
		min=x[i];
}
printf("%d",min);
}
