#include "Ordenacao.h"
//#include "OrdenacaoArquivo.h"
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


    InsertionSort(copia3, numCartas); //SE DER TEMPO, voltar numCartas constante
    printf("\nInsertionSort:\n");
    ImprimirMao(copia3, numCartas);
    ImprimirComplexidade(); 


    ShellSort(copia4, numCartas);
    printf("\nShellSort:\n");
    ImprimirMao(copia4, numCartas);
    ImprimirComplexidade(); 


    QuickSort(copia5, numCartas);
    printf("\nQuickSort:\n");
    ImprimirMao(copia5, numCartas);
    ImprimirComplexidade(); 


    HeapSort(copia6, numCartas);
    printf("\nHeapSort:\n");
    ImprimirMao(copia6, numCartas);
    ImprimirComplexidade(); 
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

    TCarta vetor[N][10];
    MaoInicialArquivo(arq, vetor, N);
    printf("MAO INICIAL\n");
    ImprimirCartas(vetor, N);

    /*for (int i = 0; i < N; i++) {
       TCarta copia1[N][10];
    MaoInicialCopiaArquivo(vetor, copia1, N);  

    TCarta copia2[N][10];
    MaoInicialCopiaArquivo(vetor, copia2, N);  

    TCarta copia3[N][10];
    MaoInicialCopiaArquivo(vetor, copia3, N);  

    TCarta copia4[N][10];
    MaoInicialCopiaArquivo(vetor, copia4, N);  

    TCarta copia5[N][10];
    MaoInicialCopiaArquivo(vetor, copia5, N); 

    TCarta copia6[N][10];
    MaoInicialCopiaArquivo(vetor, copia6, N);

        BubbleSortArquivo(copia1, 10);  // Alterei para 1 porque BubbleSortArquivo já opera em 10 cartas
        printf("\nBubbleSort:\n");
        ImprimirCartas(copia1, 1);
        ImprimirComplexidade();

        SelectionSortArquivo(copia2, 10);
        printf("\nSelectionSort:\n");
        ImprimirCartas(copia2, 1);
        ImprimirComplexidade();

        InsertionSortArquivo(copia3, 10);  // Alterei para 1 por motivo semelhante ao BubbleSort
        printf("\nInsertionSort:\n");
        ImprimirCartas(copia3, 1);
        ImprimirComplexidade();

        ShellSortArquivo(copia4, 10);
        printf("\nShellSort:\n");
        ImprimirCartas(copia4, 1);
        ImprimirComplexidade();

        QuickSortArquivo(copia5, 10);
        printf("\nQuickSort:\n");
        ImprimirCartas(copia5, 1);
        ImprimirComplexidade();

        HeapSortArquivo(copia6, 10);
        printf("\nHeapSort:\n");
        ImprimirCartas(copia6, 1);
        ImprimirComplexidade();
    }
*/
    fclose(arq);
    }   
    return 0;
}
