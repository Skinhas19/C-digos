/*Uma string é considerada palíndroma se ela pode ser lida da esquerda para a direita
ou da direita para a esquerda com o mesmo significado. Neste caso, não podemos
considerar as acentuações, as letras maiúsculas ou minúsculas, os espaços e os
caracteres especiais. A seguir, estão alguns exemplos:
Ex1.: subi no onibus
Ex2.: radar
? Escreva um programa que determine se uma expressão é palíndroma ou não*/

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

    // Remova espaços da string e converta para minúsculas
    while (string[i] != '\0')
    {
        if (string[i] != ' ')
        {
            string[j] = tolower(string[i]); // Converta para minúsculas e coloque em string
            j++;
        }
        i++;
    }
    string[j] = '\0'; // Adicione o caractere nulo de término de string

    i = 0;
    while (string[i] != '\0')
    {
        push(string[i]);
        i++;
    }

    char stringReversa[40] = "\0"; // Nova variável para a versão invertida da string original
    i = 0;
    while (top != NULL)
    {
        stringReversa[i] =top->letra;
        pop();
        i++;
    }
    stringReversa[i] = '\0'; // Adicione o caractere nulo de término de string em stringReversa

    printf("String sem espaços e em minúsculas: %s\n", string); // Use a string modificada
    printf("String invertida: %s\n", stringReversa);

    int resultado = strcmp(string, stringReversa); // Compare a string modificada com a versão invertida de string original

    if (resultado == 0)
    {
        printf("É um palíndromo\n");
    }
    else
    {
        printf("Não é um palíndromo\n");
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

