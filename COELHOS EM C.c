//Observe a figura e elabore um programa RECURSIVO para indicar ao criador de coelhos quantos pares de coelhos ele ter� depois de uma quantidade de meses informada por ele na execu��o do programa.
//No primeiro m�s nasce apenas um casal;
//Casais amadurecem e reproduzem-se apenas ap�s o segundo m�s de vida;
//N�o h� problemas gen�ticos no cruzamento consangu�neo;
//Todos os meses, cada casal f�rtil d� � luz um novo casal;
//Os coelhos nunca morrem. 
#include <stdio.h>
int qtd_coelhos(int meses);
int main(void)
{
	int mes;
	printf("informe a quatidade de meses:");
	scanf("%d",&mes);
  while(mes<= 0) 

  {

    printf("Digite o numero de meses: ");
    scanf("%d", &mes);

  }

  printf("\nquantidade de coelhos igual=%d",qtd_coelhos(mes));

}

int qtd_coelhos(int mes) 

{
	int qtd;
	if(mes==1||mes==2)
	{
		return 1;
	}
 	qtd=qtd_coelhos(mes-1)+qtd_coelhos(mes-2);

 	return qtd;
 	 
}
mes=6;
qtd=qtd_coelhos(mes-1)+qtd_coelhos(mes-2);
qtd=qtd_coelhos(5)+qtd_coelhos(4);
qtd(5)=qtd(4)+qtd(3);qtd(3)=2;
qtd(3)=qtd(2)+qtd(1); 
qtd(4)=qtd(3)+qtd(2);qtd(4)=3;
