//Elabore um programa, que deve utilizar fun��o recursiva, para resolver a multiplica��o de dois n�meros naturais, atrav�s de somas sucessivas. 

//Por exemplo: 6 * 4 = 4 + 4 + 4 + 4 + 4 + 4).

//Implementa��es que n�o utilizarem recursividade ser�o desconsideradas.

//Realize as consist�ncias de dados necess�rias.Lembrando, um n�mero natural � um inteiro positivo.
#include <stdio.h>

int funcao(int num1,int num2);
int main(void)
{
	int num1,num2;
	
	printf("informe o numero 1:");//valor que conta quantas vezes multiplica
	scanf("%d",&num1);
	while(num1<0)
	{
		printf("informe o numero 1:");
	scanf("%d",&num1);
	}
	printf("informe o numero 2:");//valor que sofre a soma
	scanf("%d",&num2);
	while(num2<0)
	{
	printf("informe o numero 2:");
	scanf("%d",&num2);
	}
	
	printf("resultado=%d",funcao(num1,num2));
}
int funcao(int num1,int num2)
{
	if(num1==0||num2==0)
		return 0;
	if(num1==1)
		return num2;
    else
        return num2 + funcao(num1-1,num2);

}
