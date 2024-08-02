#include <stdio.h>

int qtd_coelhos(int meses);

int main() 

{

  int meses;

  

  printf("Digite o numero meses: ");

  scanf("%d", &meses);

  

  while(meses<= 0) 

  {

    printf("Digite o numero de meses: ");

    scanf("%d", &meses);

  }

  printf("\nquantidade de coelhos igual=%d",qtd_coelhos(meses));

}

int qtd_coelhos(int meses) 

{

  int qtd;

  

  if (meses==1||meses==2) 

  {

    return 1;

  }

  qtd=qtd_coelhos(meses-1)+qtd_coelhos(meses-2);

  return qtd;

}
