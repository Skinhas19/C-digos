//matriz dinamica
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *matriz_dinamica;
	int i,j,num_linhas,num_colunas;
	printf("informe o numero de linhas");
	scanf("%d",&i);
	printf("informe o numero de colunas");
	scanf("%d",&j);
	matriz_dinamica=fopen("matriz.txt","wt");
	fprintf(matriz_dinamica,"%d\n",i);
	fprintf(matriz_dinamica,"%d\n",j);
	fclose(matriz_dinamica);
	matriz_dinamica=fopen("matriz.txt","r");
	fscanf(matriz_dinamica,"%d",num_linhas);
	fscanf(matriz_dinamica,"\n%d",num_colunas);
	fclose(matriz_dinamica);
	printf("%d %d",num_linhas,num_colunas);
	
}
