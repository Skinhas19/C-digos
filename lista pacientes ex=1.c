//Suponha que em um laboratório, cada paciente quando chega escolhe uma senha para atendimento. Essa senha pode ser para realizar exames de sangue ou exames de imagem. 
//Quando um paciente é chamado pelo atendente ele deve informar o número da senha, seu nome, o plano de saúde(Unimed/Ipê) e o tipo de exame a fazer(sangue/imagem). Ao término do dia, 
//cada atendente gera a listagem dos pacientes que ele atendeu. Apresente:

//A listagem dos pacientes atendidos
//A quantidade de pacientes atendidos que possuem Unimed.
//A quantidade de pacientes atendidos para realizar exames de Sangue.

//OBS: Apresente os dados com a seguinte construção (endereço do nó, valores do nó, valor do próximo). 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct no
{
int sen,exa,pla;
char name[20];
struct no *prox;
}nodo;
void insere_fim(char nome[],int senha,int exame,int plano, nodo **prim, nodo *p);
void imprime (nodo *prim);

int main(void)
{
	
	nodo *inicio, *lista;
	inicio = NULL;
	char nome[20];
	int senha,exame,plano,opcao;

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
		fflush(stdin);
		printf("Nome:");
		scanf("%[^\n]s",&nome);
	
		printf("Senha:");
		scanf("\n%d",&senha);
		
		while(senha<=0)
		{
		printf("Senha:");
		scanf("%d",&senha);
		}
	
		printf("Exame:\n1-Sangue 2-Imagem");
		scanf("%d",&exame);
		while(exame<1||exame>2)
		{
		printf("Exame:\n1-Sangue 2-Imagem");
		scanf("%d",&exame);
		}
		printf("Plano de saude:\n1-Unimed 2-Ipe");
		scanf("%d",&plano);
		while(plano<1||plano>2)
		{
		printf("plano de saude Unimed=1 OU plano de saude Ipe=2");
		scanf("%d",&plano);
		}
		insere_fim(nome,senha,exame,plano,&inicio,lista);
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
void insere_fim(char nome[],int senha,int exame,int plano, nodo **prim, nodo *p)
{
nodo *paux;
strcpy(p->name,nome);
p->exa=exame;
p->pla=plano;
p->sen=senha;
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
void imprime (nodo *prim)
{
nodo *paux;
paux = prim;
int qtd=0,count=0;
if (prim == NULL)
{
printf ("\nlista vazia");
}
else
{
while (paux != NULL)
{
printf ("\n endereço:%d,nome=%s,senha=%d,proximo:%d",paux,paux->name,paux->sen,paux->prox);
if(paux->exa==1)
{
	qtd++;
}
if(paux->pla==1)
{
	count++;
}
paux = paux->prox;
}
printf("\nnumero de pacientes com unimed=%d",count);
printf("\nnumero de pacientes para exame de sangue=%d",qtd);
}
}

