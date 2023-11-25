#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

int main() {
    const int numCartas = 10;
    TCarta cartas[numCartas];

    MaoInicial(cartas);

    // Antes da ordenação
    printf("MAO INICIAL:\nMao de cartas:\n");
    ImprimirMao(cartas, numCartas);

    // Aplica Bubble Sort
    BubbleSort(cartas, numCartas);

    // Depois da ordenação
    printf("\nMao de cartas:\n");
    ImprimirMao(cartas, numCartas);

    return 0;
}
