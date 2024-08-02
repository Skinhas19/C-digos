//Nome:Lucas Santos Monteiro.

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
void removermeio(nodo **prim,int cont);
void tornarcircular(nodo **prim,nodo *p);
void insere_ordenado(int val,nodo **prim,nodo *p);

int main()
{
int opcao, valor,k,cont=0;//Contador para fazer a funçao inserir no meio.
nodo *inicio, *lista;
inicio = NULL;

while (opcao !=	11)
{
opcao = menu();//chama a funçao menu ate q a opçao seja igual a 11
switch (opcao)
{
case 1:
lista = (nodo *)malloc(sizeof(nodo));//caso n aloque na memoria
if (lista == NULL)
{
printf("\n Falta espaço de memoria");
}
else
{
printf("\n Informe o valor ");
scanf("%d", &valor);
insere_inicio(valor, &inicio, lista);
cont++;//sempre q adiciona um elemento na lista,adiciona mais um no contador
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
cont++;
}
break;
case 3:
if (inicio == NULL)//caso n tenha lista
{
printf("\n N tem lista");
}
else
{
cont--;//sempre q remove, o contador subtrai 1
removefim(&inicio);
}


break;
case 4:
if (inicio == NULL)
{
printf("\n N tem lista");
}	

else
{
cont--;
removeinicio(&inicio);
}

break;

case 5:
if (inicio == NULL)//caso n tenha lista
{
printf("\n N tem lista");
}
else
{
imprime(inicio);
}
break;

case 6:
if (inicio == NULL)//caso n tenha lista
{
printf("\n N tem lista");
}
else
{
buscarValor(inicio);
}
break;

case 7:
lista = (nodo *)malloc(sizeof(nodo));
if (inicio == NULL)
{
printf("\n N tem lista");
}
else
{
printf("\n Informe o K ");
scanf("%d",&k);
insere_antes_do_k(k, &inicio, lista);

}
break;
case 8:
if (inicio == NULL)
{
printf("\n N tem lista");
}
else
	{
	removermeio(&inicio,cont);
	cont--;
	}

	break;
	
	case 9:
if (inicio == NULL)//caso n tenha lista
{
printf("\n N tem lista");
}
else
{
tornarcircular(&inicio,lista);
}
break;
	
	case 10:
	lista = (nodo *)malloc(sizeof(nodo));
	printf("\n Informe o valor ");
	scanf("%d", &valor);
	insere_ordenado(valor,&inicio,lista);
	break;
	
	case 11:
	printf("F");
	break;
	default:
	printf("Digite uma opção valida!");
	break;
}
}
}
void imprime(nodo *prim)
{
nodo *paux;
paux = prim;


while (paux != NULL)//enquanto paux n for nulo,vai imprimindo a lista.
{
printf("\n endereço:%d,elemento da lista = %d,proximo:%d", paux, paux->info, paux->prox);
paux = paux->prox;
}
}
int menu()//menu com as opçoes
{
int op;
printf("\n--------------- Menu ---------------");
printf("\n1 - Insere no inicio");
printf("\n2 - Insere no fim");
printf("\n3 - Remove no fim");
printf("\n4 - Remove no inicio");
printf("\n5 - Imprime lista");
printf("\n6 - Busque um valor");
printf("\n7-  Insere antes do K");
printf("\n8-  Remove meio");
printf("\n9-  Tornar circular");
printf("\n10- Inserir ordenado");
printf("\n11 - Fim ");
printf("\nInforme a opção desejada: ");
scanf("%d", &op);

return op;
}
void tornarcircular(nodo **prim,nodo *p)//faz apontar o fim pro inicio
{
	nodo *paux;
	paux=*prim;
	nodo *inicio;
	inicio=*prim;
	while(paux->prox!=NULL)//faz com q chegue no ultimo elemento da lista
	{
		paux=paux->prox;
	}
	paux->prox=inicio;//ultimo elemento aponta pro inicio
	paux=*prim;//volta pro inicio para fazer a impressao
	while(paux->prox!=inicio)//faz a impressao ate o penultimo elemento da lista
	{
		printf("\nEndereco: %d\tValor: %d\tProximo: %d", paux, paux->info, paux->prox);
		paux = paux->prox;
	}
	printf("\nEndereco: %d\tValor: %d\tProximo: %d", paux, paux->info, paux->prox);//faz a impressao do ultimo elemento
	while(paux->prox!=inicio)//faz a lista voltar a ser oq era antes
	{
		paux = paux->prox;
	}
	paux->prox=NULL;
	

}
void insere_ordenado(int val,nodo **prim, nodo *p)//faz os maiores valores ficarem por ultimo

{
    	nodo *aux;
   
        p->info=val;
        if (*prim == NULL)//vai inserir no primeiro elemento da lista, ja q n tem nada na lista
        {
            p->prox = NULL;
            *prim = p;
        }

        else if (p->info < (*prim)->info)//coloca o elemento novo como primeiro na lista,ja q ele é menor q o primeiro.
        {
            p->prox = *prim;
            *prim = p;
        }
        else
        {
            	aux = *prim;
            	while (aux->prox && p->info > aux->prox->info)//verifica se o aux nao é o ultimo elemento da lista e verifica se o valor a ser inserido	é maior do que o valor do proximo no na lista.
                aux = aux->prox;
            	p->prox = aux->prox;//faz com que o novo elemento da lista aponte para o mesmo q a variavel auxiliar,assim mantendo a lista.
            	aux->prox = p;//coloca o novo elemento na lista
        }
}



void removermeio(nodo **prim,int cont)
{
	
	nodo *paux;
	paux=*prim;
	nodo *ppaux;//pega o elemento dps do removido
	nodo *pant;//pega o elemento anterior do removido
	
if(paux->prox == NULL)
{
printf("\nApenas um item");
free(paux);
*prim = NULL;
}
else
{
		cont=cont/2;//divide o contador por dois,sendo ele inteiro ficaria cont=3/2->cont=1.
		printf("cont=%d",cont);
		//exemplo com 3 elementos
		while(cont!=0)
		{
			cont--;//decresce apenas uma vez
			pant=paux;//pega o inicio 
			paux=paux->prox;//pega o segundo elemento
			ppaux=paux->prox;//aponta pro terceiro elemento
		}
		pant->prox=ppaux;//o inicio aponta pro terceiro
	   	free(paux);//exclui o segundo
}
}




void insere_antes_do_k(int k,nodo **prim,nodo *p)
{
int val = NULL;
nodo *paux;
paux = *prim;
int nacho = 1;

printf("\nDigite o valor desejado: ");
scanf("%d", &val);
if(paux->info==k)//caso o primeiro valor seja igual a k
{
nacho=1;
p->prox = *prim;
p->info = val;
*prim = p;
}
else
{
while ((paux->prox->info != k) && !nacho)//busca o valor k na lista
{
if ((paux->prox->prox == NULL) && (paux->prox->info != k))//verifica se nao achou o valor k
{
nacho = 0;
}
else
paux = paux->prox;
}
if (nacho)
printf("\nValor nao encontrado!");
else//caso ache faz com o q o novo elemento aponte para o proximo elemento da lista(no caso k) e receba o valor.
{
p->prox = paux->prox;
p->info = val;
paux->prox=p;//insere o novo elemento na lista
}
}
}


void insere_inicio(int val, nodo **prim, nodo *p)
{//o novo elemento da lista(p) recebe o endereço do primeiro,recebe o valor e se torna o primeiro elemento da lista.
p->prox = *prim;
p->info = val;
*prim = p;
}

void insere_fim(int val, nodo **prim, nodo *p)
{
nodo *paux;
p->info = val;//novo elemento recebe valor e aponta pra null ja q vai se tornar o fim da lista
p->prox = NULL;
if (*prim == NULL)//coloca em primeiro caso nao tenha nada na lista
*prim = p;
else
{
paux = *prim;
while (paux->prox != NULL)//vai achar o ultimo elemento da lista
{
paux = paux->prox;
}
paux->prox = p;//ultimo elemento se torna o novo elemento
}
}


void removeinicio(nodo **prim)
{
nodo *paux;
// nodo *pprox;
paux = *prim;
*prim = paux->prox;//primeiro se torna o segundo elemento da lista
free(paux);//exclui o primeiro
}


void removefim(nodo **prim)
{
nodo *paux;
nodo *ant;
int fim = 1;

paux = *prim;

if(paux->prox == NULL)//remove o primeiro elemento da lista,ja q so tem um
{
printf("\nApenas um item");
free(paux);
*prim = NULL;
}
else
while (fim)//looping ate mudar o fim
{
ant = paux;//recebe um elemento antes do fim.
paux = paux->prox;//paux vai receber o fim
if (paux->prox == NULL)
{
free(paux);
ant->prox = NULL;//o ultimo elemento se torna o anterior do excluido e com isso precisa apontar para null
fim = 0;

}
}
}

void buscarValor(nodo *prim)
{
int val;
nodo *paux;
paux = prim;
int nacho = 0;

printf("\nDigite o valor desejado: ");
scanf("%d", &val);

while (paux != NULL)//vai percorrer a lista ate q o paux aponte pra null,ou seja,ultimo elemento da lista
{

if (paux->info == val)//verifica se o valor é igual
{
printf("\nEndereco: %d\tValor: %d\tProximo: %d", paux, paux->info, paux->prox);
nacho = 1;//nacho vira true
}
paux = paux->prox;
}
if (!nacho)//caso nao ache o valor,nacho é false
printf("\nValor nao encontrado!");
}


