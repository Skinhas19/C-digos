/*1. Crie uma pilha que execute as seguintes instruções:
1. Empilhe
2. Desempilhe
3. Imprima
1. Toda a pilha
2. Valor - topo
*/




#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
	int valor;
	struct no *prox;
}nodo;
void imprimir();
void push(int);
void pop();
nodo *top=NULL;
int main(void)
{
	int n,opcao;
	do
	{
		printf("\n1.Empilhar \n2.Desempilhar\n3.Imprimir\n0.Sair");
		printf("\nEscolha uma opcao 0-3?");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				printf("\n Entre com um valor para ser empilhado:");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				imprimir();
				break;
				
		}
	}while(opcao!=0);
}



void push(int item)
{
	nodo *novo=malloc(sizeof(nodo));
	novo->valor=item;
	novo->prox=top;
	top=novo;
}

void pop()
{
	if(top==NULL)
	{
		printf("\nA lista esta vazia");
	}
	else 
	{
		nodo *temp;
		temp=top;
		top=top->prox;
		free(temp);
	}
}
void imprimir()
{
	nodo *temp;
	temp=top;
	printf("Valor do topo=%d",temp->valor);
	temp=temp->prox;
	while(temp!=NULL)
{
	printf("\n%d",temp->valor);
	temp=temp->prox;
}
}





