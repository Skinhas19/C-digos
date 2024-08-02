//Crie uma matriz  5 x 5 de inteiros e posteriormente (após o preenchimentos dos elementos via teclado), escreva a localização (linha e a coluna) do maior valor.
#include <stdio.h>

int main(void)
{
	int matriz[2][2],i,j,maior=0,recebelinha,recebecoluna;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("informe a matriz[%d][%d]=",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(maior<matriz[i][j])
			{
				maior=matriz[i][j];
				recebelinha=i;
				recebecoluna=j;
			}
		}
	}
	printf("linha e coluna do maior valor da matriz=%d %d",recebelinha,recebecoluna);
}
