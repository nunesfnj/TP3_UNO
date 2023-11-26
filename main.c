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
            BubbleSort(cartas, numCartas);
            printf("\nBubbleSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;

        case 2:
            SelectSort(cartas, numCartas);
            printf("\nSelectSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;
        
        case 3:
            //InsertSort aqui
            printf("\nInsertSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;
        
        case 4:
            ShellSort(cartas, numCartas);
            printf("\nShellSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;

        case 5:
            //QuickSort aqui
            printf("\nQuickSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;

        case 6:
            HeapSort(cartas, &numCartas);
            printf("\nHeapSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
            break;
        
        default:
            printf("\nEscolha Invalida\n");
            break;
    }
}
    else if(tipo ==2){
        char nArquivo[20];
        int N;
        FILE *arq;
        
        printf("\ndigite o caminho para o arquivo a ser lido: ");
        scanf("%s", nArquivo);

        arq = fopen(nArquivo, "r");
        if (arq == NULL){
            printf("Falha no arquivo");
            return 1;
        }
        else{
            printf("Arquivo Encontrado\n\n");
        }

        fscanf(arq, "%d", &N);
        for(int i=0; i < N; i++){    
            TCarta cartas[10];
            for(int j=0; j <10; j++){
            fscanf(arq, "(%d %d) ", (int*)&cartas[j].cor, &cartas[j].valor);
            }
            printf("Conjunto %d antes da ordenacao:\n", i + 1);
            ImprimirMao(cartas, 10); 
            printf("\n");

            BubbleSort(cartas, numCartas);
            printf("\nBubbleSort:\n");
            ImprimirMao(cartas, numCartas);
            ImprimirComplexidade();
        }

        fclose(arq);
    }

    return 0;
}
