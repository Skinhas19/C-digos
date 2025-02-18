//Nome: Luiz Eduardo Colombo Teixeira Soares
/*
Exerc�cio . Considere que um estacionamento da Rua Direita, em Porto alegre,
que � composto por uma �nica alameda que v�rios carros.
Existe apenas uma entrada/sa�da no estacionamento,
e esta extremidade da alameda d� acesso justamente � Rua Direita.
Se chegar um cliente para retirar um carro que n�o seja o mais pr�ximo da sa�da,
todos os carros bloqueando seu caminho sair�o do estacionamento.
O carro do cliente ser� manobrado para fora do estacionamento,
e os outros carros voltar�o a ocupar a mesma sequ�ncia inicial.
Escreva um programa que processe um grupo de linhas de entrada.
Cada linha de entrada cont�m um �E� ou 1, de entrada, ou um �S� ou 2 de sa�da,e o n�mero da placa do carro.
Presume-se que os carros cheguem e partam na mesma ordem que entraram no estacionamento.
O programa deve imprimir uma mensagem sempre que um carro  chegar ou sair.
Quando um carro chegar, a mensagem deve especificar se existe ou n�o vaga para o carro no estacionamento.
Se n�o houver vaga, o carro partir� sem entrar no estacionamento. Quando um carro sair do estacionamento,
a mensagem dever� incluir o n�mero de vezes em que o carro foi manobrado para fora do estacionamento
para permitir que os outros carros sa�ssem.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo
{
int dado;
struct nodo* prox;
} nodo;

void insere_no_inicio(nodo** inicio, int valor);
void insere_no_fim(nodo** inicio, int valor);
void insere_antes_de_k(nodo** inicio, int valor,int k);
void exclui_no_inicio(nodo** inicio);
void exclui_no_fim(nodo** inicio);
void exclui_k(nodo** inicio,int k);
void insere_ordenada(nodo** ordenada, int valor);
void imprime_lista(nodo* inicio);
void imprime_primeiro(nodo* inicio);
void tornar_ciclica(nodo* inicio);
void empilha(nodo** inicio, int valor);
void desempilha(nodo** inicio1, nodo** inicio2);
nodo* localiza_k(nodo* lista, int k,int log);

int main()
{
nodo* pilha1 = NULL;
nodo* pilha2 = NULL;

int op=1, valor, k;

while (op != 0)
{
	printf("\nMenu:");
	printf("\n1 - Empilha");
	printf("\n2 - Desempilha");
	printf("\n3 - Imprimir pilha");
	printf("\n4 - Imprimir desempilhados");
	printf("\n5 - Imprimir primeiro valor da pilha");
	printf("\n0 - Sair");
	printf("\nEscolha uma opcao: ");
	
	scanf("%d", &op);
	
		switch (op)
		{
			case 1:
			printf("\nDigite o valor a ser empilhado: ");
			scanf("%d", &valor);
			empilha(&pilha1,valor);
			break;
			
			case 2:
			desempilha(&pilha1, &pilha2);
			break;
			
			case 3:
			imprime_lista(pilha1);
			break;
			
			case 4:
			imprime_lista(pilha2);
			break;
			
			case 5:
			imprime_primeiro(pilha1);
			break;
			
			case 0:
			printf("\nSaindo...");
			break;
			
			default:
			printf("\n Entrada invalida.\n");
		}
} 
}

//=================================
//=================================
//=================================
//=================================

void imprime_lista(nodo* inicio)
{
	nodo* p = inicio;
	
	if(p == NULL)
	{
		printf("\nLista vazia");
		return;
	}//se a lista estiver vazia, avisa e retorna
	
	printf("Lista: \n");
	while (p != NULL)
	{
		printf("DADO: %d, MEM: %p,", p->dado, p);
            if (p->prox != NULL) {
                printf(" PROX: %p\n", p->prox);
            } else {
                printf(" FIM DA LISTA\n");
            }
		p = p->prox;
	}//enquanto p n�o for nulo, percorre a lista imprimindo as informa��es da lista
	//printf("\n");
}

void insere_no_inicio(nodo** inicio, int valor)
	{
	nodo* p = (nodo*)malloc(sizeof(nodo));
	nodo* aux = *inicio;
	
	if (p == NULL)
	{
		printf("\nErro ao alocar memoria.");
	}
	
	p->dado = valor;
	p->prox = NULL;
	
	if (*inicio==NULL)
	{
		*inicio = p;
		return;
	}//se a lista estiver vazia o n� se torna a nova lista
	else
	{
        p->prox = *inicio;
        *inicio = p;
        return;
    }//encadeia o novo nodo com o inicio e transforma o novo nodo no inicio
	}

void insere_no_fim(nodo** inicio, int valor)
{
	nodo* p = (nodo*)malloc(sizeof(nodo));
	
	if (p == NULL)
	{
		printf("\nErro ao alocar memoria.");
	}
	
	p->dado = valor;
	p->prox = NULL;
	
	if (*inicio == NULL)
	{
		*inicio = p;
		return;
	}//se a lista estiver vazia o n� se torna a nova lista
	nodo* aux = *inicio;
	while (aux->prox != NULL)
	{
		aux = aux->prox;
	}//percorre a lista at� chegar no �ltimo nodo
	
	aux->prox = p;//faz o pr�ximo do �ltimo nodo apontar pro novo fim
}

void insere_antes_de_k(nodo** inicio, int valor, int k)
{
	nodo* p = (nodo*)malloc(sizeof(nodo));
	nodo* aux = *inicio;
	
	if (p == NULL)
	{
		printf("\nErro ao alocar memoria.");
	}
	
	if (aux==NULL)
	{
		printf("\nLista vazia.");
		return;
	}//se a lista estiver vazia, avisa e retorna
	
	p->dado = valor;
	
    if (aux->dado == k)
	{
        p->prox = *inicio;
        *inicio = p;
        return;
    }//se o primeiro termo for k, insere no inicio

    while (aux->prox != NULL)
	{
        if (aux->prox->dado == k)
		{
            p->prox = aux->prox;
            aux->prox = p;
            return;
        }//se encontrar k, insere o valor antes
        aux = aux->prox;
    }//percorre a lista
	printf("\nk nao encontrado.");
	return;
}

void insere_ordenada(nodo** inicio, int valor)
{
    nodo* p = (nodo*)malloc(sizeof(nodo));
    p->dado = valor;
    p->prox = NULL;

    if (*inicio == NULL || (*inicio)->dado >= valor)
	{
        p->prox = *inicio;
        *inicio = p;
    }//se o inicio for nulo ou se o primeiro nodo for maior que o valor inserido, e transforma o novo nodo no inicio.
	else
	{
        nodo* aux = *inicio;
        while (aux->prox != NULL && aux->prox->dado < valor)
		{
            aux = aux->prox;
        }//percorre a lista at� que o valor do pr�ximo nodo seja maior que o valor inserido.
        p->prox = aux->prox;
        aux->prox = p;
    }
}

void exclui_no_inicio(nodo** inicio)
{
    if (*inicio == NULL)
	{
        printf("\nLista vazia.");
        return;
    }//se a lista estiver vazia, avisa e retorna

    nodo* aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
    //transforma o inicio no segundo nodo (ou em nulo se for uma lista de um nodo) e exclui o primeiro nodo
}

void exclui_no_fim(nodo** inicio)
	{
    if (*inicio == NULL)
	{
		printf("\nLista vazia");
        return;
    }//se a lista estiver vazia, avisa e retorna

    if ((*inicio)->prox == NULL)
	{
        free(*inicio);
        *inicio = NULL;
        return;
    }//se a lista possuir um unico nodo, exclui a lista

    nodo* aux = *inicio;
    while (aux->prox->prox != NULL)
	{
        aux = aux->prox;
    }//percorre a lista parando no penultimo nodo

    free(aux->prox);
    aux->prox = NULL;
    //limpa o ultimo nodo e transforma o penultimo no fim da lista
}

void exclui_k(nodo** inicio, int k)
	{
    if (*inicio == NULL)
	{
        printf("\nLista vazia");
        return;
    }//se a lista estiver vazia, avisa e retorna

    if ((*inicio)->dado == k)
	{
        nodo* temp = *inicio;
        *inicio = (*inicio)->prox;
        free(temp);
        return;
    }//se o primeiro nodo for k, exclui o primeiro nodo e transforma o segundo nodo no inicio.

    nodo* aux = *inicio;
    while (aux->prox != NULL && aux->prox->dado != k)
	{
        aux = aux->prox;
    }//percorre a lista at� chegar no fim ou em k

    if (aux->prox == NULL)
	{
        printf("\nA lista nao possui nenhum elemento k=%d.", k);
        return;
    }//se n�o achar k, retorna e avisa

    nodo* temp = aux->prox;
    aux->prox = aux->prox->prox;
    free(temp);//se chegar aqui significa que estamos k, excluindo o nodo anterior e encadeando a lista.
}

nodo* localiza_k(nodo* lista, int k,int log)
{
    nodo* aux = lista;
    if (aux == NULL)
	{
        printf("\nLista vazia.");
        return NULL;
    }//se a lista estiver vazia, avisa e retorna
    
    while (aux != NULL)
	{
    	
	    if (aux->dado == k)
			{
				if(log==1)
				{
					
				 	printf("Valor de k: %d\n", aux->dado);
			        //printf("k encontrado no endereco: %p\n", aux);
			        printf("DADO: %d, MEM: %p,", aux->dado, aux);
			        if (aux->prox != NULL)
					{
			            printf(" PROX: %p\n", aux->prox);
			        }
					else
					{
			            printf(" FIM DA LISTA\n");
			        }
		    	}
		        return aux;
	       	}//se o dado do nodo for igual a k, printa (caso log seja 1) e retorna o nodo com k
       		
        aux = aux->prox;
    }//percorre a lista
	 printf("\nA lista nao possui nenhum elemento k=%d.", k);
	 return NULL;//se a lista n�o possuir k, avisa e retorna
}

void tornar_ciclica(nodo* inicio)
{
	nodo* p = inicio;
	
	if(p == NULL)
	{
		printf("\nLista vazia");
		return;
	}
		
	printf("Lista: \n");
	while (p != NULL)
	{
		printf("DADO: %d, MEM: %p,", p->dado, p);
            if (p->prox != NULL) {
                printf(" PROX: %p\n", p->prox);
            } else {
            	p->prox=inicio;
            	printf(" PROX: %p\n", p->prox);
            	return;
            }
		p = p->prox;
	}//imprime a lista, quando chega no ultimo, encadeia o mesmo com o primeiro nodo (se tentar imprimir com a fun��o normal depois, quebra o programa)
	//printf("\n");
}
void imprime_primeiro(nodo* inicio)
{
	nodo* p = inicio;
	
	if(p == NULL)
	{
		printf("\nLista vazia");
		return;
	}//se a lista estiver vazia, avisa e retorna
	else
	{
	printf("Lista: \n");
	printf("DADO: %d, MEM: %p,", p->dado, p);
        if (p->prox != NULL)
		{
            printf(" PROX: %p\n", p->prox);
        }
		else
		{
            printf(" FIM DA LISTA\n");
        }
	}
	return;
}
void empilha(nodo** inicio, int valor)
{
	insere_no_inicio(inicio, valor);
}

void desempilha(nodo** inicio1, nodo** inicio2)
{
	insere_no_inicio(inicio2, (*inicio1)->dado);
	exclui_no_inicio(inicio1);
};//fun��o desempilha da pilha 1 e empilha na pilha 2.

