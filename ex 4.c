#include <stdio.h>

// Função que recebe um parâmetro por referência
void alteraValor(int *x) 
{
    *x = 10;  // Modifica diretamente o valor do parâmetro original
}

int main() {
    int valor = 5;
    alteraValor(&valor);
	printf("%d",valor);
}
