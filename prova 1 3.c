#include <stdio.h>

int recebe(int vetorpar1[12],int vetorimpar2[12]);

int main(void)

{

	int vetordigitado1[12],vetordigitado2[12],i;

	

	for(i=0;i<12;i++)

	{

		printf("informe o vetor 1 [%d]=",i+1);

		scanf("%d",&vetordigitado1[i]);

		while(vetordigitado1[i]<0)

		{

		printf("informe o vetor 1 dnv [%d]=",i+1);

		scanf("%d",&vetordigitado1[i]);

		}

	}

	for(i=0;i<12;i++)

	{

		printf("informe o vetor 2 [%d]=",i+1);

		scanf("%d",&vetordigitado2[i]);

		while(vetordigitado2[i]<0)

		{

		printf("informe o vetor 2 dnv [%d]=",i+1);

		scanf("%d",&vetordigitado2[i]);

		}

	}

	recebe(vetordigitado1,vetordigitado2);

	

	for(i=0;i<12;i++)

	{

		printf("\nvetor 1[%d]=%d",i+1,vetordigitado1[i]);

	}

	

	for(i=0;i<12;i++)

	{

		printf("\nvetor 2[%d]=%d",i+1,vetordigitado2[i]);

	}

}



int recebe(int vetordigitado1[12],int vetordigitado2[12])

{

	int i,tampar=0,tamimpar=0;

	int vetorimpar[12],vetorpar[12];

	

	for(i=0;i<12;i++)

	{

	vetorimpar[i]=vetordigitado1[i];	

	}

	

	for(i=0;i<12;i++)

	{

	vetorpar[i]=vetordigitado2[i];

	}

	

	for(i=0;i<12;i++)

	{

	if (vetorpar[i] % 2 == 0) 

	{

     if(tampar>12)

    {

    	printf("limite de pares acabo");

	}

	else

	{

	vetordigitado2[tampar]=vetorpar[i];

    tampar++;

	}

    }

    else 

	{

    if(tamimpar>12)

    {

	printf("limite de impares acabo");

	}

	else

	{

	vetordigitado1[tamimpar]=vetorpar[i];

    tamimpar++;

	}

    }

	}

	

	for(i=0;i<12;i++)

	{

	if (vetorimpar[i] % 2 == 1) 

	{

    if(tamimpar>12)

    {

	printf("limite de impares acabo");

	}

	else

	{

	vetordigitado1[tamimpar] = vetorimpar[i];

    tamimpar++;

	}

    }

	

	else 

	{

    if(tampar>12)

    {

		printf("limite de pares acabo");

	}

	else

	{

	vetordigitado2[tampar]=vetorimpar[i];

    tampar++;

	}

    }

	}	

}
