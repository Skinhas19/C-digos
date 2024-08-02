#include <stdio.h>
int main(void)
{
	int a;
	int *b;	
	printf("a=");
	scanf("%d",&a);
	b=&a;
	printf("%d",b);
	
	printf ("\nsaida = %d", *(b+1));
	
}
func(1) = 1

func(n) = (n - 1) * func(n - 1)
func(4)=(4-1)*func(3);func(4)=3*2;func(4)=6;
func(3)=(3-1)*func(2);func(3)=2*1;func(3)=2;
func(2)=(2-1)*func(1);
func(2)=1*1;func(2)=1;
func(5)=5-1*func(4);func(5)=4*6;func(5)=24;
