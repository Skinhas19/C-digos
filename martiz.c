//matriz dinamica
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *matriz_dinamica;
	int **matriz;
	int i,j,num_linhas,num_colunas;
	printf("informe o numero de linhas");
	scanf("%d",&i);
	printf("informe o numero de colunas");
	scanf("%d",&j);
	matriz_dinamica=fopen("matriz.txt","wt");
	fprintf(matriz_dinamica,"%d %d",i,j);
	fclose(matriz_dinamica);
	matriz_dinamica=fopen("matriz.txt","r");
	fscanf(matriz_dinamica,"%d %d",&num_linhas,&num_colunas);
	fclose(matriz_dinamica);
	matriz = (int **)calloc(num_linhas,sizeof(int *)); 
  	for (i = 0; i < num_linhas; i++)
  	{
  	matriz[i] = (int *)calloc(num_colunas,sizeof(int));
  	}
	for(i=0;i<num_linhas;i++)
	{
		for(j=0;j<num_colunas;j++)
		{
			printf("informe o valor da matriz[%d][%d]=",i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
	for(i=0;i<num_linhas;i++)
	{
		for(j=0;j<num_colunas;j++)
		{
			printf("\ninforme o valor da matriz[%d][%d]=%d",i+1,j+1,matriz[i][j]);
			
		}
	}
}
