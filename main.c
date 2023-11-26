#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

int main() {
    const int numCartas = 10;
    TCarta cartas[numCartas]; // aqui nao deveria ser ponteiro ?
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
            BubbleSort(cartas, numCartas); //aqui nao deveria ser &cartas?
            printf("\nBubbleSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;
        case 2:
            SelectionSort(cartas, numCartas);
            printf("\nSelectSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;
        case 6:
            HeapSort(cartas, &numCartas);
            printf("\nHeapSort:\n");
            ImprimirMao(cartas, numCartas);
            //falta fazer complexidade
            break;
    }

}

    return 0;
}
