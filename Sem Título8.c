#include <stdio.h>



#include <string.h>



//No compilador em c online ele buga por causa do scanf do nome,no dev c++ funciona perfeitamente;







typedef struct no



{



	char nome[30];



	int idade;



}pessoa;



void apaga_cadastro_anterior()



{



	FILE *arq1;



char arq[5]={"arq1"};



	



	arq1=fopen("arq1.txt","w");



	fclose (arq1);



}



void menu()



{



	printf("\nMenu:");



	printf("\n1-insere nome e idade");



	printf("\n2-Conta quantidade de vogais armazenadas no arquivo");



	printf("\n3-imprima o nome da pessoa mais velha que esta armazenada no arquivo.");



	printf("\n4-Fim\n");



}

void apaga_cadastro_anterior();



void opcao1(pessoa cadastro);



void opcao2(pessoa cadastro);



void opcao3(pessoa cadastro);



int main(void)



{



	apaga_cadastro_anterior();



	pessoa cadastro;



	int opcao,qtd=0;



	FILE *arq1;



	char arq[5]={"arq1"};



	



	do



{	



	switch(opcao)



	{



		case 1:



		opcao1(cadastro);	



		qtd++;



		opcao=6;



		break;



		



		case 2:



		if(qtd==0)



		{



			printf("cadastre alguem primeiro");



		}



		else



		{



		opcao2(cadastro);



		}



		opcao=6;



		break;



		



		case 3:



		if(qtd==0)



		{



			printf("cadastre alguem primeiro");



		}



		else



		{



		opcao3(cadastro);



		}



		opcao=6;



		break;



		



		



		case 4:



		printf("fim");



		break;



		



		case 6:



		menu();



        fflush(stdin);



		scanf("\n%d",&opcao);



        break;



		



		default:



		opcao=6;



		break;



	}



}



while(opcao!=4);



}



void opcao1(pessoa cadastro)



{







		FILE *arq1;



		char arq[5]={"arq1"};



		fflush(stdin);



		printf("Nome:");



		scanf("%[^\n]s",&cadastro.nome);



		



		printf("idade:");



		scanf("%d",&cadastro.idade);



		while(cadastro.idade<0)



		{



			printf("idade:");



			scanf("%d",&cadastro.idade);



		}



		arq1 =fopen("arq1.txt","a");



		fprintf(arq1,"%s\n",cadastro.nome);



		fprintf(arq1,"%d\n",cadastro.idade);



		fclose (arq1);



}



void opcao2(pessoa cadastro)



{



FILE *arq1;



char arq[5]={"arq1"};



		int i,cont=0,tam;



		arq1 =fopen("arq1.txt","r");



		if(arq1==NULL)



		{



			printf("erro");



		}



		else



		{



			do{



				fscanf(arq1,"%s\n%d\n",&cadastro.nome,&cadastro.idade);



				tam=strlen(cadastro.nome);



				for(i=0;i<tam;i++)



				{



				if(cadastro.nome[i]=='a'||cadastro.nome[i]=='e'||cadastro.nome[i]=='i'||cadastro.nome[i]=='o'||cadastro.nome[i]=='u')



					cont++;



				}



			



			}while(!feof(arq1));



		}



		



		fclose (arq1);



		printf("numero de vogais nos nomes =%d",cont);



}



void opcao3(pessoa cadastro)



{



		FILE *arq1;



		char arq[5]={"arq1"};



		int maior=0;



		char nome[30];



		arq1=fopen("arq1.txt","r");



		if(arq1==NULL)



		{



			printf("erro");



		}



		else



		{



		do



		{



		fscanf(arq1,"%s\n%d\n", &cadastro.nome,&cadastro.idade);



		if(maior<cadastro.idade)



			{



				strcpy(nome,cadastro.nome);



				maior=cadastro.idade;



			}



		}while(!feof(arq1));



		}



		fclose (arq1);	



		printf("nome da pessoa com a idade maior:%s",nome);



}
