/*Uma string � considerada pal�ndroma se ela pode ser lida da esquerda para a direita
ou da direita para a esquerda com o mesmo significado. Neste caso, n�o podemos
considerar as acentua��es, as letras mai�sculas ou min�sculas, os espa�os e os
caracteres especiais. A seguir, est�o alguns exemplos:
Ex1.: subi no onibus
Ex2.: radar
? Escreva um programa que determine se uma express�o � pal�ndroma ou n�o*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no
{
    char letra;
    struct no *prox;
} nodo;

void push(char);
char pop();
nodo *top = NULL;

int main(void)
{
    char string[40] = "\0";

    printf("Digite uma string: ");
    gets(string); // Use fgets para ler uma linha

    int i = 0;
    int j = 0;

    // Remova espa�os da string e converta para min�sculas
    while (string[i] != '\0')
    {
        if (string[i] != ' ')
        {
            string[j] = tolower(string[i]); // Converta para min�sculas e coloque em string
            j++;
        }
        i++;
    }
    string[j] = '\0'; // Adicione o caractere nulo de t�rmino de string

    i = 0;
    while (string[i] != '\0')
    {
        push(string[i]);
        i++;
    }

    char stringReversa[40] = "\0"; // Nova vari�vel para a vers�o invertida da string original
    i = 0;
    while (top != NULL)
    {
        stringReversa[i] =top->letra;
        pop();
        i++;
    }
    stringReversa[i] = '\0'; // Adicione o caractere nulo de t�rmino de string em stringReversa

    printf("String sem espa�os e em min�sculas: %s\n", string); // Use a string modificada
    printf("String invertida: %s\n", stringReversa);

    int resultado = strcmp(string, stringReversa); // Compare a string modificada com a vers�o invertida de string original

    if (resultado == 0)
    {
        printf("� um pal�ndromo\n");
    }
    else
    {
        printf("N�o � um pal�ndromo\n");
    }

    
}

void push(char item)
{
    nodo *novo = malloc(sizeof(nodo));
    novo->letra = item;
    novo->prox = top;
    top = novo;
}

char pop()
{
    if (top == NULL)
    {
        return 0;// Retorna um caractere nulo se a pilha estiver vazia
    }
    else
    {
        char letra = top->letra;
        nodo *temp;
        temp = top;
        top = top->prox;
        free(temp);
        
    }
}

