#include <stdio.h>
#include <stdlib.h>

// Implementar uma Lista

typedef struct no
{
    int info;
    struct no *prox;
}nodo;

int menu();
void imprime (nodo *prim);
void insere_fim (int val, nodo **prim, nodo *p);
void insere_inicio(int val, nodo **prim, nodo *p);
int main()
{
   int opcao, valor;
   nodo *inicio, *lista;
   inicio = NULL;
   opcao = menu();
   
   while (opcao != 4)
   {
      switch (opcao)
      {
          
          case 1: lista = (nodo *) malloc (sizeof(nodo));
                  if (lista == NULL)
                {
                    printf ("\n Falta espaço de memoria");
                }
                else
                {
                    printf ("\n Informe o valor ");
                    scanf ("%d", &valor);
                    insere_inicio (valor, &inicio, lista);
                }    
                break;
          case 2:
                lista = (nodo *) malloc (sizeof(nodo));
                if (lista == NULL)
                {
                    printf ("\n Falta espaço de memoria");
                }
                else
                {
                    printf ("\n Informe o valor ");
                    scanf ("%d", &valor);
                    insere_fim (valor, &inicio, lista);
                }    
                break;
          case 3: imprime (inicio);
                  break;
        }
                  opcao = menu();
    }
}
void imprime (nodo *prim)
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
             printf ("\n endereço:%d,elemento da lista = %d,proximo:%d",paux,paux->info,paux->prox);
             paux = paux->prox;
        }     
    }
}
int menu()
{
    int op;
    printf ("\n1 - Insere no inicio");
    printf ("\n2 - Insere no fim");
    printf ("\n3 - Imprime lista");
    printf ("\n4- Fim ");
    printf ("\n Informe a opção desejada ");
    scanf ("%d", &op);
    
    while (op <= 0 || op > 4)
    {
        printf ("\nInforme a opcao do menu ");
        scanf ("%d", &op);
    }
    
    return op;
 }


void insere_inicio(int val, nodo **prim, nodo *p)
    {
        p->prox = *prim;
        p->info = val;
        *prim = p;
        
    }

 void insere_fim(int val, nodo **prim, nodo *p)
    {
        nodo *paux;
        p->info = val;
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
