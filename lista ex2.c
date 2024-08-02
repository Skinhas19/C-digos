
//Faça um código em C que permite ao usuário criar uma lista com os seguintes dados: CPF usuário, Nome do curso, ano de início. Realize as seguintes operações utilizando funções:
//Inserir nó na lista – final 
//Imprimir a lista 

//OBS: Apresente os dados com a seguinte construção (endereço do nó, valores do nó, valor do próximo). 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{

char curso[30],cpf[11];
int ano;
struct no *prox;
}nodo;
void insere_fim(char spf[],char ccurso[],int aano,nodo **prim, nodo *p);
void imprime(nodo *prim);

int main(void)
{
	
	nodo *inicio, *lista;
	inicio = NULL;
	int soma,result1,num2,cont,valido=0;
	char dig10,dig11,spf[11];
	char ccurso[30];
	int aano;
	
	int opcao;

	while(opcao!=2)
	{
	printf("opcao:");
	scanf("%d",&opcao);
	switch(opcao)
	{
	case 1:
		
		lista = (nodo *) malloc (sizeof(nodo));
		if (lista == NULL)
{
printf ("\n Falta espaço de memoria");
}
else
{		
		
		while(valido==0)
		{
		
		fflush(stdin);
		printf("cpf:");
		scanf("%s",spf);
		
		soma=0;
		
		for(cont=0;cont<9;cont++)
		{
			num2=spf[cont]-48;
			soma=soma+(num2*(10-cont));
		}
		
		result1=11-(soma%11);
		
		if((result1==10)||(result1==11))
		
		dig10='0';
		
	    else
	    dig10=result1+48;
			
			soma=0;
			
			for(cont=0;cont<10;cont++)
			{
				num2=spf[cont]-48;
				soma=soma+(num2*(11-cont));
			}
		
		result1=11-(soma%11);
		
		if((result1==10)||(result1==11))
		dig11='0';
		
		else
		dig11=result1+48;
		
		if((dig10==spf[9])&&(dig11==spf[10]))
		{
		printf("valido");
		valido=1;
		}
		else
		{
		printf("invalido");
		valido=0;
		}
		}
		valido=0;
		fflush(stdin);
		printf("curso:");
		scanf("%[^\n]s",&ccurso);
		fflush(stdin);
		printf("ano:");
		scanf("%d",&aano);
		
		
		insere_fim(spf,ccurso,aano,&inicio,lista);
	break;
	case 2:
		imprime(inicio);
		break;
	default:
		printf("po\n");
		
	}
	}
}
}
void insere_fim(char spf[],char ccurso[],int aano,nodo **prim, nodo *p)
{
nodo *paux;
strcpy(p->cpf,spf);
strcpy(p->curso,ccurso);
p->ano=aano;
p->prox = NULL;
if (*prim == NULL)
*prim = p;
else
{
paux = *prim;
while (paux->prox != NULL)
{
paux = paux->prox;
}
paux->prox = p;
}
printf ("\nfim funcao insere fim\n");
}
void imprime(nodo *prim)
{
nodo *paux;
paux = prim;

if (prim == NULL)
{
printf ("\nlista vazia");
}
else
{
while (paux != NULL)
{
printf ("\n endereço:%d,cpf:%s,curso:%s,ano:%d,proximo:%d",paux,paux->cpf,paux->curso,paux->ano,paux->prox);
paux = paux->prox;
}
}
}
