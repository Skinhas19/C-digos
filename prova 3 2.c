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

	int horario,qtd_itens;

	Lista lista;

	while(horario!=24)

	{

	printf("\ninforme a quantidade de itens produzidos a cada hora:");

	scanf("%d",&qtd_itens);

	while(qtd_itens<=0)

	{

	printf("\ninforme a quantidade de itens produzidos a cada hora:");

	scanf("%d",&qtd_itens);

	}

	printf("\ninforme as horas de inspecao de uma maquina:");

	scanf("%d",&horario);

	while(horario<0)

	{

	printf("\ninforme as horas de inspecao de uma maquina:");

	scanf("%d",&horario);

	}

	if(horario<24)

	{

	inserir_inicio(&lista,horario,qtd_itens);

	imprimir(&lista);

	}

	}

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

	int num_horas,num_qtd,vezes;

	nodo *inicio=lista->inicio;

	num_horas=inicio->horas;

	num_qtd=inicio->qtd;

	

	

	vezes=num_horas*num_qtd;

	printf("\nquantidade de itens produzidos em %d horas:%d",inicio->horas,vezes);

	inicio=inicio->proximo;

	

}
