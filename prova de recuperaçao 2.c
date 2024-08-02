//Fa�a um programa que crie uma fila encadeada para armazenar as horas de inspe��o de uma m�quina e a quantidade de itens produzidos a cada hora. Posteriormente imprima a quantidade de itens produzidos da primeira hora armazenada. 
//Observe que a hora e a quantidade de itens produzidos s�o solicitados via teclado e armazenados na fila (voc� escolhe se � no final ou no in�cio).

//O programa ir� parar de ler os dados quando a hora 24 for informada. O funcion�rio sabe que deve informar 24 para finalizar. Independente disso, voc� deve consistir os dados de entrada, as horas v�lidas s�o de 0 at� 23. 
//As  horas de inspe��o s�o sempre inteiras. A quantidade de itens produzidos n�o pode ser zero e nem negativo.

//Use fun��es para a inclus�o e para a impress�o.


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
