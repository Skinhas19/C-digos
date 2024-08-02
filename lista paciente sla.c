#include <stdio.h>
int main(void)
{
	int i;
	struct paciente
	{
		char nome[20];
		int senha;
		int exame;
		int plano;
	};
	struct paciente vetor[i];
	
	
	
	printf("nome:");
	scanf("%[^\n]s",&vetor[i].nome);
	
	
	printf("senha:");
	scanf("%d",&vetor[i].senha);
	
	while(vetor[i].senha<=0||vetor[i].senha>100)
	{
	printf("senha:");
	scanf("%d",&vetor[i].senha);
	}
	
	printf("exame de sangue=1 ou exame de imagem=2:");
	scanf("%d",&vetor[i].exame);

	printf("plano de saude Unimed=1 OU plano de saude Ipê=2");
	scanf("%d",&vetor[i].plano);
	
	while(vetor[i].plano<1||vetor[i].plano>2)
	{
	printf("plano de saude Unimed=1 OU plano de saude Ipê=2");
	scanf("%d",&vetor[i].plano);
	}
	
	
}
