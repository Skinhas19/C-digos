#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 100

typedef struct Carro {
    char placa[8];
} Carro;

typedef struct Estacionamento {
    Carro carros[MAX_CARROS];
    int topo;
} Estacionamento;

void inicializarEstacionamento(Estacionamento *estacionamento) {
    estacionamento->topo = -1;
}

int estaCheio(Estacionamento *estacionamento) {
    return estacionamento->topo == MAX_CARROS - 1;
}

int estaVazio(Estacionamento *estacionamento) {
    return estacionamento->topo == -1;
}

void chegada(Estacionamento *estacionamento, char *placa) {
    if (!estaCheio(estacionamento)) {
        strcpy(estacionamento->carros[++estacionamento->topo].placa, placa);
        printf("Chegou: %s (Vaga dispon�vel)\n", placa);
    } else {
        printf("Chegou: %s (Estacionamento lotado, n�o foi poss�vel entrar)\n", placa);
    }
}

void saida(Estacionamento *estacionamento, char *placa) {
    int manobras = 0;
    int encontrado = 0;

    for (int i = estacionamento->topo; i >= 0; i--) {
        if (strcmp(estacionamento->carros[i].placa, placa) == 0) {
            encontrado = 1;
            manobras = estacionamento->topo - i;

            for (int j = i; j < estacionamento->topo; j++) {
                strcpy(estacionamento->carros[j].placa, estacionamento->carros[j + 1].placa);
            }

            estacionamento->topo--;
            break;
        }
    }

    if (encontrado) {
        printf("Saiu: %s (Manobras necess�rias: %d)\n", placa, manobras);
    } else {
        printf("Saiu: %s (Carro n�o encontrado no estacionamento)\n", placa);
    }
}

int main() {
    Estacionamento estacionamento;
    inicializarEstacionamento(&estacionamento);

    char opcao;
    char placa[8];

    while (1) {
        printf("Digite E para entrada, S para sa�da, ou 0 para encerrar: ");
        scanf(" %c", &opcao);

        if (opcao == '0') {
            break;
        }

        printf("Digite a placa do carro: ");
        scanf("%s", placa);

        if (opcao == 'E') {
            chegada(&estacionamento, placa);
        } else if (opcao == 'S') {
            saida(&estacionamento, placa);
        }
    }

    return 0;
}

