#include <stdio.h>

// Fun��o que recebe um par�metro por refer�ncia
void alteraValor(int *x) 
{
    *x = 10;  // Modifica diretamente o valor do par�metro original
}

int main() {
    int valor = 5;
    alteraValor(&valor);
	printf("%d",valor);
}
