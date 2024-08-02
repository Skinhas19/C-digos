//Elabore um programa que leia um número e depois escreva uma função que receba este valor inteiro lido como referência e retorne o resto da divisão deste número por 10. Altere também o valor da variável 
//passada por referência, dividindo-a por 10.
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
