#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int salario,codigo;
	struct no *proximo;
	
}No;

void inserir_ordenado(No **lista,int valor,int cod)
{
	No *aux,*novo;
	novo=(No*)malloc(sizeof(No));
	if(novo)
	{
	novo->salario=valor;
	novo->codigo=cod;
	if(*lista==NULL)
	{
		novo->proximo=NULL;
		*lista=novo;
	}
	else if(novo->salario <(*lista)->salario)
	{
		novo->proximo=*lista;
		*lista=novo;
	}
	else{
		aux=*lista;
		while(aux->proximo && novo->salario > aux->proximo->salario)
		aux=aux->proximo;
		novo->proximo=aux->proximo;
		aux->proximo=novo;
	}
	}
	else
	printf("erro ao alocar na memoria");
}
void imprimir (No *No)
{
	printf("\n\tlista: ");
	while(No)
	{
		printf("%d %d ",No->salario,No->codigo);
		No=No->proximo;
	}
	printf("\n\n");
}
int main(void)
{
	int valor,cod,continua=0;
 	
 	
   No *lista = NULL;
   while(continua==0)
   {
   
            printf ("informe um salario ");
            scanf ("%d", &valor);
            while(valor<=0)
            {
            printf ("informe um salario ");
            scanf ("%d", &valor);
			}
            printf("informe um codigo");
            scanf("%d",&cod);
            while(cod>1000||cod<100)
            {
            printf("informe um codigo");
            scanf("%d",&cod);
			}
            inserir_ordenado(&lista,valor,cod);
    printf ("\n deseja continuar inserindo na lista ");
    scanf ("%d", &continua);
	}
        
        
   
   
   imprimir(lista);
   
}
