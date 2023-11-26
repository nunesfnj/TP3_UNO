#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

int main() {
    const int numCartas = 10;
    TCarta cartas[numCartas];
    int tipo, tipoOrdenacao;

    printf("Selecione (1) para o modo interativo ou (2) para o modo por Arquivo:");
    scanf("%d", &tipo);
    
    if(tipo == 1){
    MaoInicial(cartas);
    
    // Antes da ordenação
    printf("MAO INICIAL:\n");
    ImprimirMao(cartas, numCartas);
    
    printf("Escolha qual o tipo de ordenacao desejada:\n");
    printf("(1)BubbleSort - (2)SelectSort - (3)InsertSort - (4)ShellSort - (5)QuickSort - (6)HeapSort:");
    scanf("%d",&tipoOrdenacao);
    
    switch(tipoOrdenacao){
        case 1:
            // Aplica Bubble Sort
            BubbleSort(cartas, numCartas);
            printf("\nBubbleSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
        case 2:
            SelectSort(cartas, numCartas);
            printf("\nSelectSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
    }

}

    return 0;
}
