#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
	int valor;
	struct no *proximo;
}no;

typedef struct
{
	no *inicio;
	int tam;
}lista;
inserirnoinicio(lista *Lista,int valor)
{
	no *novo=(no*)malloc(sizeof(no));
	novo->valor=valor;
	novo->proximo=Lista->inicio;
	Lista->inicio=novo;
	Lista->tam++;
	
	
}
void imprimir(lista *Lista)
{
	no *imprimir=Lista->inicio;
	while(imprimir!=NULL)
	{
		printf("%d",imprimir->valor);
		imprimir=imprimir->proximo;
	}	
	
}
int main()
{
	lista Lista;
	Lista.inicio=NULL;
	Lista.tam=0;
	int opcao,valor;
	
	do
	{
		printf("opcao:");
		scanf("%d",&opcao);
		switch(opcao)
		{
		
			case 1:
				printf("valor=");
				scanf("%d",&valor);
				inserirnoinicio(&Lista,valor);
				break;
			case 2:
				imprimir(&Lista);
			break;
			case 3:
				printf("acabo");
				break;
			default:
				printf("opcao inexistente");
			} 
				
	}while(opcao!=3);
}
