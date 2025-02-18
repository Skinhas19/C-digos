#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
	int valor;
	struct no *proximo;
	
}No;
void inserir_ordenado(No **lista,int num)

{

	No *aux,*novo;

	novo=(No*)malloc(sizeof(No));

	if(novo)

	{

	novo->valor=num;



	if(*lista==NULL)

	{

		novo->proximo=NULL;

		*lista=novo;

	}

	else if(novo->valor <(*lista)->valor)

	{

		novo->proximo=*lista;

		*lista=novo;

	}

	else{

		aux=*lista;

		while(aux->proximo && novo->valor > aux->proximo->valor)

		aux=aux->proximo;

		novo->proximo=aux->proximo;

		aux->proximo=novo;

	}

	}

	else

	printf("erro ao alocar na memoria");

}
void inserir_decrescente(No **lista,int num)

{

	No *aux,*novo;

	novo=(No*)malloc(sizeof(No));

	if(novo)

	{

	novo->valor=num;



	if(*lista==NULL)

	{

		novo->proximo=NULL;

		*lista=novo;

	}

	else if(novo->valor >(*lista)->valor)

	{

		novo->proximo=*lista;

		*lista=novo;

	}

	else{

		aux=*lista;

		while(aux->proximo && novo->valor < aux->proximo->valor)

		aux=aux->proximo;

		novo->proximo=aux->proximo;

		aux->proximo=novo;

	}

	}

	else

	printf("erro ao alocar na memoria");

}
void inserir_no_inicio(No **lista,int num)
{
	No *novo =(No*) malloc(sizeof(No));
	if(novo)
	{
		novo->valor=num;
		novo->proximo=*lista;
		*lista=novo;
	}
	else
	printf("erro ao alocar memoria!\n");
}
void inserir_no_fim(No **lista,int num)
{
	No *aux,*novo=(No*)malloc(sizeof(No));
	if(novo)
	{
		novo->valor=num;
		novo->proximo=NULL;
		if(*lista==NULL)
		*lista=novo;
		else{
			aux=*lista;
			while(aux->proximo)
			aux=aux->proximo;
			aux->proximo=novo;
		}
	}
	else
	printf("erro ao alocar memoria");
}
void inserir_no_meio(No **lista,int num,int ant)
{
	No *aux,*novo=(No*)malloc(sizeof(No));
	if(novo)
	{
		novo->valor=num;
		if(*lista==NULL)
		{
			novo->proximo=NULL;
			*lista=novo;
		}
		else
		{
			aux=*lista;
			while(aux->valor!=ant && aux->proximo)
			aux=aux->proximo;
			novo->proximo=aux->proximo;
			aux->proximo=novo;
		}
	}
	else
	printf("erro ao alocar memoria!\n");
}
No *remover(No **lista,int num)
{
	No *aux,*remover=NULL;
	if(*lista)
	{
		if((*lista)->valor==num)
		{
			remover=*lista;
			*lista=remover->proximo;
			
		}
		else{
			aux=*lista;
			while(aux->proximo && aux->proximo->valor != num)
			aux=aux->proximo;
			if(aux->proximo)
			{
				remover=aux->proximo;
				aux->proximo=remover->proximo;
			}
		}
	}
	return remover;
}
void imprimir(No *no)
{
	printf("\n\tlista: ");
	while(no)
	{
		printf("%d",no->valor);
		no=no->proximo;
	}
	printf("\n\n");
}
int main(void)
{
	int opcao,valor,anterior;
	No *removido,*lista=NULL;
	do
	{
		printf("\n\t0-Sair\n\t1-inserirI\n\t2-inserirF\n\t3-InserirM\n\t4-remover\n\t5-InserirO\n\t6-InserirD\n\t7-Imprimir\n");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				printf("digite um valor:");
				scanf("%d",&valor);
				inserir_no_inicio(&lista,valor);
				break;
			case 2:
				printf("digite um valor:");
				scanf("%d",&valor);
				inserir_no_fim(&lista,valor);
				break;
			case 3:
				printf("digite um valor e o valor de referencia:");
				scanf("%d%d",&valor,&anterior);
				inserir_no_meio(&lista,valor,anterior);
				break;
			case 4:
				printf("digite um valor a ser removido:\n");
				scanf("%d",&valor);
				removido=remover(&lista,valor);
				if(removido)
				{
					printf("elemento a ser removido: %d\n",removido->valor);
					free(removido);
				}
				break;
			case 5:
				printf("digite um valor a ser adicionado em ordem:\n");
				scanf("%d",&valor);
				inserir_ordenado(&lista,valor);
				break;
			case 6:
				printf("digite um valor a ser adicionado em ordem decrescente:\n");
				scanf("%d",&valor);
				inserir_decrescente(&lista,valor);
				break;
			case 7:
				imprimir(lista);
				break;
			
			default:
				if(opcao!=0)
				printf("opcao invalida!\n");
		}
	}while(opcao!=0);	
	return 0;
}
