/*1)Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
Cada pessoa deve ser representada por uma struct dentro de um vetor. 
O nome, a data de nascimento e a altura de cada pessoa devem ser informados pelo teclado.
Posteriormente imprima os nomes das pessoas que possuem altura superior a 1,78.*/
#include <stdio.h>
typedef struct no
{
	char nome[30];
	int dia,mes,ano;
	float altura;
}
aluno;


int main(void)
{
	aluno vetor[10];
	int continua,i=0;
	while(continua==0)
	{
			fflush(stdin);
			printf("informe o nome do aluno:");
			scanf("%[^\n]s",&vetor[i].nome);
			printf("informe a altura do aluno:");
			scanf("%f",&vetor[i].altura);
			printf("informe o dia de nascimento do aluno:");
			scanf("%d",&vetor[i].dia);
			printf("informe o mes de nascimento do aluno:");
			scanf("%d",&vetor[i].mes);
			printf("informe o ano de nascimento do aluno:");
			scanf("%d",&vetor[i].ano);
		
		if(i<10)
		{
		printf("deseja continuar?");
		scanf("%d",&continua);
		i++;
		}
		else
		{
			continua=1;
		}
	}	
	for(i=0;i<10;i++)
	{
		if(vetor[i].altura>1.78)
		{
			printf("\naluno q tem mais de 1.78:%s",vetor[i].nome);
		}
	}
	
	
	
	

}


