//Elabore um programa que leia um n�mero e depois escreva uma fun��o que receba este valor inteiro lido como refer�ncia e retorne o resto da divis�o deste n�mero por 10. Altere tamb�m o valor da vari�vel 
//passada por refer�ncia, dividindo-a por 10.
#include <stdio.h>


int funcao(int *x);
int main(void)
{
	int num;
	int resultado;
	printf("numero:");
	scanf("%d",&num);
	resultado=funcao(&num);
printf("%d %d",resultado,num);	
	
}
int funcao(int *x)
{
	int valor;
	valor=*x%10;
	*x=(float)(*x/10);
	return valor;
}
