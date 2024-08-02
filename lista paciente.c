//Suponha que em um laboratório, cada paciente quando chega escolhe uma senha para atendimento. Essa senha pode ser para realizar exames de sangue ou exames de imagem. Quando um paciente é chamado pelo atendente
//ele deve informar o número da senha, seu nome, o plano de saúde(Unimed/Ipê) e o tipo de exame a fazer(sangue/imagem). Ao término do dia, cada atendente gera a listagem dos pacientes que ele atendeu. Apresente:
//A listagem dos pacientes atendidos
//A quantidade de pacientes atendidos que possuem Unimed.
//A quantidade de pacientes atendidos para realizar exames de Sangue.
#include <stdio.h>
int main(void)
{
	int i=0,mais,qtd=1,continua=0,cont=0,certo=0;
	struct paciente
	{
		char nome[20];
		int senha;
		int exame;
		int plano;
	};
	struct paciente a[10];
	
	
	while(continua==0)
	{
	fflush(stdin);
	printf("\nnome:");
	scanf("%[^\n]s",&a[i].nome);
	
printf("\nsenha:");
			scanf("%d",&a[i].senha);
	
		while(a[i].senha<=0||a[i].senha>100)
		{
		printf("\nsenha:");
		scanf("%d",&a[i].senha);
		}
	
	
	printf("\nexame de sangue=1 ou exame de imagem=2:");
	scanf("%d",&a[i].exame);
	while(a[i].exame!=1 && a[i].exame!=2)
	{
	printf("\nexame de sangue=1 ou exame de imagem=2");
	scanf("%d",&a[i].exame);
	}
	
	printf("\nplano de saude Unimed=1 OU plano de saude Ipê=2");
	scanf("%d",&a[i].plano);
	
	while(a[i].plano<1||a[i].plano>2)
	{
	printf("\nplano de saude Unimed=1 OU plano de saude Ipê=2");
	scanf("%d",&a[i].plano);
	}
	printf("\nmais paciente? 1-s ou 2-n");
	scanf("%d",&mais);
	while(mais<1||mais>2)
	{
	printf("\nmais paciente? 1-s ou 2-n");
	scanf("%d",&mais);
	}
	if(mais==2)
	{
		continua=1;
	}
	else
	{
		i++;
		qtd++;
	}
	}
	
	for(i=0;i<qtd;i++)
	{
		printf("\npaciente=%s",a[i].nome);
	}
	for(i=0;i<qtd;i++)
	{
		if(a[i].plano==1)
		{
			cont++;
		}
	}
	printf("\nunimed=%d",cont);
	cont=0;
	for(i=0;i<qtd;i++)
	{
		if(a[i].exame==1)
		{
			cont++;
		}
	}
	printf("\nexames de sangue=%d",cont);
	
	
	
}
