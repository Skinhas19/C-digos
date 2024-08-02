//Implemente um programa que receba um nome completo (nome e sobrenome) e imprima  somente o sobrenome e a quantidade de letras que possui o sobrenome informado.

//Exemplo: José Antonio Olivera       saída: Oliveira  Quantidade de letras: 8

//Considere que o nome completo possa ter 30 letras no total.
#include <stdio.h>
#include <string.h>
int main(void)

{

	char nome[30];
	int recebe=0;
	int tam,i,numcarecteres=0;
	printf("informe o nome:");
	scanf("%[^\n]s",nome);
	tam=strlen(nome);

	for(i=0;i<tam;i++)

	{
	if(nome[i]==' ')

	{
		recebe=i;
	}
	}

	recebe=recebe+1;
	
	for(i=0;i<tam;i++)
	{
	    nome[i]=nome[recebe];
	    recebe++;
	}

    while(nome[numcarecteres]!='\0')
	{
		numcarecteres++;
	}
	printf("\nsobrenome=%s",nome);
	printf("\nnumero de caracteres=%d",numcarecteres);

}
