#include <stdio.h>
#include <stdlib.h>
typedef struct No
{
	int valor;
	struct No *proximo;  
	
}No;
typedef struct{
	No *inicio;
	int tam;
}Lista;
void inserirInicio(Lista *lista,int valor)
{
	No *novo=(No*)malloc(sizeof(No));
	novo->valor=valor;
	novo->proximo=lista->inicio;
	lista->inicio=novo;
	lista->tam++;
	
}
void inserirFim(Lista *lista,int valor)
{
	No *no,*novo=(No*)malloc(sizeof(No));
	novo->valor=valor;
	novo->proximo=NULL;
	if(lista->inicio==NULL)
	{
		lista->inicio=novo;
		
	}
	else{
		no=lista->inicio;
		while(no->proximo!=NULL)
		{
			no=no->proximo;
			no->proximo=novo;
			
		}
	}
	lista->tam++;
}
void imprimir(Lista *lista)
{
	No *inicio=lista->inicio;
	printf("\ntamanho da lista %d",lista->tam);
	while(inicio!=NULL)
	{
		printf("\n%d",inicio->valor);
		inicio=inicio->proximo;	
	}
	printf("\n\n");
}

int main(void)
{
	Lista lista;
	int opcao,valor;
	lista.inicio=NULL;
	lista.tam=0;
	do
	{
		printf("1-Inserir no inicio\n2-imprimir\n3-inserir no final\n5-sair\n");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				printf("digite um valor a ser inserido:");
				scanf("%d",&valor);
				
				inserirInicio(&lista,valor);
				break;
			case 2:
				imprimir(&lista);
				break;
			case 3:
				printf("digite um valor a ser inserido:");
				scanf("%d",&valor);
				inserirFim(&lista,valor);
				break;
			case 5:
				printf("finalizando");
				break;
			default:
				printf("opcao invalida");
			
		}
		
	}while(opcao!=5);
	
	
	
	
}
