#include <stdio.h>

#include <string.h>

int main(void)

{

	char nome[30];

	char sobrenome[30];

	int recebe=0;

	int tam,i,numcarecteres=0;

	printf("informe o nome:");

	scanf("%[^\n]s",nome);

	

	tam=strlen(nome);

	for(i=0;i<tam;i++)

	{

	if(nome[i]==' ')

	{

		recebe=i;

	}

	}

	recebe=recebe+1;

	

	for(i=0;i<tam;i++)

	{

	    sobrenome[i]=nome[recebe];

	    recebe++;

	}

    while(sobrenome[numcarecteres]!='\0')

	{

		numcarecteres++;

	}

    

	printf("\nsobrenome=%s",sobrenome);

	printf("\nnumero de caracteres=%d",numcarecteres);

}
