#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 100

typedef struct Carro {
    char placa[8];
    struct Carro* prox;
} Carro;

typedef struct Estacionamento {
    Carro* topo;
    int tamanho;
} Estacionamento;

Estacionamento* criarEstacionamento() {
    Estacionamento* estacionamento = (Estacionamento*)malloc(sizeof(Estacionamento));
    estacionamento->topo = NULL;
    estacionamento->tamanho = 0;
    return estacionamento;
}

void chegarEstacionamento(Estacionamento* estacionamento, char* placa) {
    if (estacionamento->tamanho < MAX_CARROS) {
        Carro* novoCarro = (Carro*)malloc(sizeof(Carro));
        strcpy(novoCarro->placa, placa);
        novoCarro->prox = estacionamento->topo;
        estacionamento->topo = novoCarro;
        estacionamento->tamanho++;
        printf("Chegou: %s\n", placa);
    } else {
        printf("Chegou: %s (Estacionamento lotado, não foi possível entrar)\n", placa);
    }
}

int sairEstacionamento(Estacionamento* estacionamento, char* placa) {
    Carro* atual = estacionamento->topo;
    Carro* anterior = NULL;
    int manobras = 0;

    while (atual != NULL && strcmp(atual->placa, placa) != 0) {
        anterior = atual;
        atual = atual->prox;
        manobras++;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            estacionamento->topo = atual->prox;
        }
        free(atual);
        estacionamento->tamanho--;
    }

    return manobras;
}

void liberarEstacionamento(Estacionamento* estacionamento) {
    Carro* atual = estacionamento->topo;
    while (atual != NULL) {
        Carro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(estacionamento);
}

int main() {
    Estacionamento* estacionamento = criarEstacionamento();

    char tipo;
    char placa[8];

    while (1) {
        printf("Digite E para entrada, S para saída, ou 0 para encerrar: ");
        scanf(" %c", &tipo);

        if (tipo == '0') {
            break;
        }

        printf("Digite a placa do carro: ");
        scanf("%s", placa);

        if (tipo == 'E') {
            chegarEstacionamento(estacionamento, placa);
        } else if (tipo == 'S') {
            int manobras = sairEstacionamento(estacionamento, placa);
            if (manobras > 0) {
                printf("Saiu: %s (Manobras necessárias: %d)\n", placa, manobras);
            } else {
                printf("Saiu: %s (Carro não encontrado no estacionamento)\n", placa);
            }
        }
    }

    liberarEstacionamento(estacionamento);
    return 0;
}

