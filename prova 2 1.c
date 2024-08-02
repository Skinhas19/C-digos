#include <stdio.h>

#include <stdlib.h>

typedef struct no

{

    int qtd,cod;

}nodo;

void opcao1(nodo **lista);

void opcao2(nodo **lista);

void opcao3(nodo **lista);

void opcao4(nodo **lista);

void menu()

{

	printf("\nMenu:");

	printf("\n1-Cadastrar cliente");

	printf("\n2-Insere situação (disponível ou em falta)");

	printf("\n3-Valor do item ");

	printf("\n4-Imprime a lista de compras");

	printf("\n5-Fim\n");

}





int main(void)

{

	

	nodo *lista=NULL;

	int opcao=6,qtd=0;

do

{	

	switch(opcao)

	{

		case 1:

		opcao1(&lista);	

		qtd++;

		opcao=6;

		break;

		

		case 6:

		menu();

        fflush(stdin);

		scanf("\n%d",&opcao);

        break;

		

		default:

		opcao=6;

		break;

	}

}

while(opcao!=5);

}

void opcao1(nodo **lista)

{

	FILE *ptrarq;

	int codigo,quantidade;

	ptrarq = fopen("supermercado.txt", "a");

	printf("informe o codigo do alimento:");

	scanf("%d",&codigo);

	printf("informe a quantidade desse alimento:");

	scanf("%d",&quantidade);

	fprintf(ptrarq,"%d\n",codigo);

	fprintf(ptrarq,"%d\n",quantidade);

}
