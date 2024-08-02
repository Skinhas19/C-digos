#include <stdio.h>
#include <stdlib.h>// Implementar uma Lista

typedef struct no
{
int info;
struct no *prox;
} nodo;

int menu();
void imprime(nodo *prim);
void insere_fim(int val, nodo **prim, nodo *p);
void insere_inicio(int val, nodo **prim, nodo *p);
void removefim(nodo **prim);
void removeinicio(nodo **prim);
void buscarValor(nodo *prim);
void insere_antes_do_k(int k,nodo **prim, nodo *p);
main()
{
int opcao, valor,k;
nodo *inicio, *lista;
inicio = NULL;

while (opcao != 9)
{
opcao = menu();
switch (opcao)
{
case 1:
lista = (nodo *)malloc(sizeof(nodo));
if (lista == NULL)
{
printf("\n Falta espaço de memoria");
}
else
{
printf("\n Informe o valor ");
scanf("%d", &valor);
insere_inicio(valor, &inicio, lista);
}
break;
case 2:
lista = (nodo *)malloc(sizeof(nodo));
if (lista == NULL)
{
printf("\n Falta espaço de memoria");
}
else
{
printf("\n Informe o valor ");
scanf("%d", &valor);
insere_fim(valor, &inicio, lista);
}
break;
case 3:

removefim(&inicio);
break;
case 4:
removeinicio(&inicio);
break;
case 5:
imprime(inicio);
break;
case 6:
buscarValor(inicio);
break;
case 7:
lista = (nodo *)malloc(sizeof(nodo));
if (lista == NULL)
{
printf("\n Falta espaço de memoria");
}
else
{
printf("\n Informe o K ");
scanf("%d",&k);
insere_antes_do_k(k, &inicio, lista);

}

case 9:
break;
default:
printf("Digite uma opção valida!");
}
}
}
void imprime(nodo *prim)
{
nodo *paux;
paux = prim;

if (prim == NULL)
{
printf("\nlista vazia!");
}
else
{
while (paux != NULL)
{
printf("\n endereço:%d,elemento da lista = %d,proximo:%d", paux, paux->info, paux->prox);
paux = paux->prox;
}
}
}
int menu()
{
int op;
printf("\n--------------- Menu ---------------");
printf("\n1 - Insere no inicio");
printf("\n2 - Insere no fim");
printf("\n3 - Remove no fim");
printf("\n4 - Remove no inicio");
printf("\n5 - Imprime lista");
printf("\n6 - Busque um valor");
printf("\n7- Insere antes do K");
printf("\n8 - Fim ");
printf("\nInforme a opção desejada: ");
scanf("%d", &op);

return op;
}
void insere_antes_do_k(int k,nodo **prim,nodo *p)
{
int val = NULL;
nodo *paux;
paux = *prim;
int nacho = 1;

if (paux== NULL)
{
printf("Lista vazia");
}
else
{
printf("\nDigite o valor desejado: ");
scanf("%d", &val);
if(paux->info==k)
{
nacho=1;
p->prox = *prim;
p->info = val;
*prim = p;
}
else
{
while ((paux->prox->info != k) && !nacho)
{
if ((paux->prox->prox == NULL) && (paux->prox->info != k))
{
nacho = 0;
}
else
paux = paux->prox;

}
if (!nacho)
printf("\nValor nao encontrado!");
else{
p->prox = paux->prox;
p->info = val;
paux->prox=p;
}
}

}
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
}
void removeinicio(nodo **prim)
{
nodo *paux;
// nodo *pprox;

paux = *prim;
if (*prim == NULL)
{
printf("lista vazia");
}
else
{
*prim = paux->prox;
free(paux);
}
}
void removefim(nodo **prim)
{
nodo *paux;
nodo *ant;
int fim = 1;

paux = *prim;
if (*prim == NULL)
{
printf("lista vazia");
}
else if(paux->prox == NULL)
{
printf("\nApenas um item");
free(paux);
*prim = NULL;
}
else
while (fim)
{
ant = paux;
paux = paux->prox;
if (paux->prox == NULL)
{
free(paux);
ant->prox = NULL;
fim = 0;
}
}
}

void buscarValor(nodo *prim)
{
int val = NULL;
nodo *paux;
paux = prim;
int nacho = 0;

printf("\nDigite o valor desejado: ");
scanf("%d", &val);
if (prim == NULL)
{
printf("Lista vazia");
}
else
{
while (paux != NULL)
{

if (paux->info == val)
{
printf("\nEndereco: %d\tValor: %d\tProximo: %d", paux, paux->info, paux->prox);
nacho = 1;
}
paux = paux->prox;
}
if (!nacho)
printf("\nValor nao encontrado!");
}
}


