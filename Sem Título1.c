//Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses caracteres na string.
#include <stdio.h>
#include <string.h>
void funcao(char letra,char string[]);
int main(void)
{
	char string[30],letra;
	fflush(stdin);
	printf("letra=");
	scanf("%c",&letra);
	fflush(stdin);
	printf("string=");
	scanf("%[^\n]s",string);
	
	
	funcao(letra,string);	
}
void funcao(char letra,char string[])
{
	int tam,i;
	tam=strlen(string);
	for(i=0;i<tam;i++)
	{
	if(string[i]==letra);
	{
		string[i]=' ';
	}
	}
	printf("string=%s",string);
}
