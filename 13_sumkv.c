#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
int n = 0,min = 0,a=0,b=2;
printf("Введите количество элементов: ");
scanf("%d",&n);
unsigned long long x[n],sum=0;
for (int i=0;i<n;i++)
{
	x[i]=0+rand()%2147;
	printf("%lld\n", x[i]);
	a=x[i];
	x[i]=pow(a,b);
	printf("%lld\n", x[i]);
}
for (int i=0;i<n;i++)
{
	sum=sum+x[i];
}
printf("%lld",sum);
} 
