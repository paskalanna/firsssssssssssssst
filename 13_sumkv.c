#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
int n = 0,min = 0,a=0,b=2;
printf("Введите количество элементов: ");
scanf("%d",&n);
unsigned int x[n],sum=0;
for (int i=0;i<n;i++)
{
	scanf("%d",&x[i]);
	a=x[i];
	x[i]=pow(a,b);
}
for (int i=0;i<n;i++)
{
	sum=sum+x[i];
}
printf("%d",sum);
}
