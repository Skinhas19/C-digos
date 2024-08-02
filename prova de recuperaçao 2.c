//Faça um programa que crie uma fila encadeada para armazenar as horas de inspeção de uma máquina e a quantidade de itens produzidos a cada hora. Posteriormente imprima a quantidade de itens produzidos da primeira hora armazenada. 
//Observe que a hora e a quantidade de itens produzidos são solicitados via teclado e armazenados na fila (você escolhe se é no final ou no início).

//O programa irá parar de ler os dados quando a hora 24 for informada. O funcionário sabe que deve informar 24 para finalizar. Independente disso, você deve consistir os dados de entrada, as horas válidas são de 0 até 23. 
//As  horas de inspeção são sempre inteiras. A quantidade de itens produzidos não pode ser zero e nem negativo.

//Use funções para a inclusão e para a impressão.


#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
	int horas,qtd;
	struct no *proximo;
}nodo;
typedef struct
{
	nodo *inicio;
}Lista;
void inserir_inicio(Lista *lista,int horario,int qtd_itens);
void imprimir(Lista *lista);

int main(void)
{
	int horario,qtd_itens,vetor[24],i,valida,cont=0;
	Lista lista;
	
	for(i=0;i<24;i++)//sujeira de memoria no vetor(impossibilitando colocar o horario 1 e 0);
	{
		vetor[i]=-1;
	}	
	while(horario!=24)
	{
	valida=0;

	printf("\ninforme a hora:");
	scanf("%d",&horario);
	while(horario<0)
	{
	printf("\ninforme a hora:");
	scanf("%d",&horario);
	}
	if(horario==24||cont==24)
	{
		printf("acabo");
	}
	else
	{
	for(i=0;i<24;i++)
	{
	if(vetor[i]==horario)
	{
		valida=1;
	}
	}
	if(valida==1)
	{
		printf("horario ja adicionado");
	}
	else
	{
	printf("\ninforme a quantidade de itens produzidos:");
	scanf("%d",&qtd_itens);
	while(qtd_itens<=0)
	{
	printf("\ninforme a quantidade de itens produzidos:");
	scanf("%d",&qtd_itens);
	}
	vetor[cont]=horario;	
	cont++;
	inserir_inicio(&lista,horario,qtd_itens);
	}
	}
	}
	imprimir(&lista);
	
}





void inserir_inicio(Lista *lista,int horario,int qtd_itens)
{
	nodo *novo=(nodo*)malloc(sizeof(nodo));;
	
	novo->horas=horario;
	novo->qtd=qtd_itens;
	novo->proximo=lista->inicio;
	lista->inicio=novo;
}
void imprimir(Lista *lista)
{
	nodo *inicio=lista->inicio;
	
	while(inicio!=NULL)
	{
	printf("\nquantidade de itens produzidos na hora %d=%d",inicio->horas,inicio->qtd);
	inicio=inicio->proximo;
	}
	
}
