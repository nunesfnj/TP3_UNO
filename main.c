#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

int main() {
    int numCartas = 10;
    TCarta cartas[numCartas]; 
    int tipo;

    printf("Selecione (1) para o modo interativo ou (2) para o modo por Arquivo:");
    scanf("%d", &tipo);
    
    if(tipo == 1){
    MaoInicial(cartas);

    
    //criando as 6 copias de vetores para serem usados nas ordenacoes
   TCarta copia1[numCartas];
    MaoInicialCopia(cartas, copia1);

    TCarta copia2[numCartas];
    MaoInicialCopia(cartas, copia2);

    TCarta copia3[numCartas];
    MaoInicialCopia(cartas, copia3);

    TCarta copia4[numCartas];
    MaoInicialCopia(cartas, copia4);

    TCarta copia5[numCartas];
    MaoInicialCopia(cartas, copia5);

    TCarta copia6[numCartas];
    MaoInicialCopia(cartas, copia6);

    
    // Antes da ordenação
    printf("MAO INICIAL:\n");
    ImprimirMao(cartas, numCartas);
    

    BubbleSort(copia1, numCartas);
    printf("\nBubbleSort:\n");
    ImprimirMao(copia1, numCartas);
    ImprimirComplexidade();


    SelectionSort(copia2, numCartas);
    printf("\nSelectionSort:\n");
    ImprimirMao(copia2, numCartas);
    ImprimirComplexidade();

    HeapSort(copia3, numCartas);
    printf("\nHeapSort:\n");
    ImprimirMao(copia3, numCartas);
    //falta fazer complexidade
    }

    return 0;
}
