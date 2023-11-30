#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
            HeapSort(cartas, numCartas);
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

    TCarta vetor[N];
    MaoInicialArquivo(arq, vetor, N);

    // Agora você tem as cartas no vetor e pode fazer o que quiser com elas

    // Exemplo de impressão das cartas
    for (int i = 0; i < N; i++) {
        printf("Carta %d: Cor = %d, Tipo = %d, Valor = %d\n", i + 1, vetor[i].cor, vetor[i].tipo, vetor[i].valor);
    }

    fclose(arq);  // Não se esqueça de fechar o arquivo
    }return 0;
}
            /*while(j < 6){
            MaoInicialArquivo(arq, cartas[i]);
            if(j == 0){
                printf("\nBubbleSort\n");
                BubbleSort(cartas[i], numCartas);
                ImprimirComplexidade();
                j++;
                break;
            }
            if(j == 1){
                printf("\nSelectSort\n");
                SelectSort(cartas[i], numCartas);
                ImprimirComplexidade();
                j++;
                break;
            }
            if(j == 2){
                printf("\nInsertSort\n");
                //InsertSort aqui
                ImprimirComplexidade();
                j++;
                break;
            }
            if(j ==3){
                printf("\nShellSort\n");
                ShellSort(cartas[i], numCartas);
                ImprimirComplexidade();
                j++;
                break;
            }
            if(j ==4){
                printf("\nQuickSort\n");
                //QuickSort aqui
                ImprimirComplexidade();
                j++;
                break;
            }
            if(j == 5){
                printf("\nHeapSort\n");
                HeapSort(cartas[i], numCartas);
                ImprimirComplexidade();
                j++;
                break;
            }
            }
        }
        fclose(arq);
    }

    return 0;
}
*/
