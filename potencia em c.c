#include <stdio.h>
int funcao(int num,int exp);
int main(void)
{
	int num,exp;
	printf("informe um numero:");
	scanf("%d",&num);
	printf("informe o expoente:");
	scanf("%d",&exp);
	
	printf("resultado=%d",funcao(num,exp));
}
int funcao(int num,int exp)
{
	if(exp == 0)
        return 1;
    else
        return num * funcao(num, exp-1);

}


