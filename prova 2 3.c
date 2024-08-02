#include <string.h>

#include <stdio.h>

#include <stdlib.h>

typedef struct paciente



{



  char nome[30];



  int idade;



   int peso;



}cadpaciente;

void funcao_dados(cadpaciente *v,int num,int i);

void bolha_rec(int n, cadpaciente v[]);

void impressao(int i,cadpaciente *v,int num);

int main(void)

{

	cadpaciente *v;

	int num,i=0;

	

	printf("informe a quantidade de pacientes q vc quer cadastrar:");

	scanf("%d",&num);

	

	v=(cadpaciente*)(malloc(num*sizeof(cadpaciente)));

	

	funcao_dados(v,num,i);

	bolha_rec(num,v);

	impressao(i,v,num);

}

void funcao_dados(cadpaciente *v,int num,int i)

{

	for(i=0;i<num;i++)

	{

		fflush(stdin);

		printf("Nome:");

		scanf("%[^\n]s",&v[i].nome);

		printf("informe a idade:");

		scanf("%d",&v[i].idade);

		while(v[i].idade<0)

		{

		printf("informe a idade:");

		scanf("%d",&v[i].idade);

		}

		printf("informe peso:");

		scanf("%d",&v[i].peso);

		while(v[i].peso<=0)

		{

		printf("informe peso:");

		scanf("%d",&v[i].peso);

		}

	}

}



void bolha_rec(int n, cadpaciente v[])

{

int j;

int troca;

char temp_nome[30];

	for (j=0;j<n-1;j++)

	if (v[j].peso>v[j+1].peso) 

{

	int temp = v[j].peso; // troca

	v[j].peso = v[j+1].peso;

	v[j+1].peso = temp;

	temp = v[j].idade; // troca

	v[j].idade = v[j+1].idade;

	v[j+1].idade = temp;

	strcpy(temp_nome,v[j].nome);

	strcpy(v[j].nome,v[j+1].nome);

	strcpy(v[j+1].nome,temp_nome);

	troca = 1;

}

	if (troca !=0) // houve a troca

	bolha_rec(n-1,v);

}



void impressao(int i,cadpaciente *v,int num)

{

	for(i=0;i<num;i++)

	{

		printf("\nnome=%s",v[i].nome);

		printf("\nidade=%d",v[i].idade);

		printf("\npeso=%d",v[i].peso);

	

		

	

	}

}
