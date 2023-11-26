#include "Ordenacao.h"
#include <stdio.h>

// Variáveis globais para rastrear a complexidade
int comparacoes = 0;
int movimentacoes = 0;

void ImprimirComplexidade() {
    printf("Comparacoes: %d, Movimentacoes: %d\n", comparacoes, movimentacoes);
}

void BubbleSort(TCarta* pCarta, int tamanho) {
    int i, j;
    TCarta aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 1; j < tamanho - i; j++) {
            // Compara primeiro as cores
            comparacoes++;
            if (pCarta[j].cor < pCarta[j - 1].cor) {
                aux = pCarta[j];
                pCarta[j] = pCarta[j - 1];
                pCarta[j - 1] = aux;
                movimentacoes++;
            }
            // Se as cores são iguais, compara pelos valores
            else if (pCarta[j].cor == pCarta[j - 1].cor && pCarta[j].valor < pCarta[j - 1].valor) {
                aux = pCarta[j];
                pCarta[j] = pCarta[j - 1];
                pCarta[j - 1] = aux;
                movimentacoes++;
            }
        }
    }
}
void SelectSort(TCarta* pCarta, int tamanho) {
    int i, j, Min;
    TCarta aux;
    
    for (i = 0; i < tamanho - 1; i++) {
        Min = i;
        
        for (j = i + 1; j < tamanho; j++) {
            comparacoes++;
            if (pCarta[j].cor < pCarta[Min].cor) {
                Min = j;
            }
            else if (pCarta[j].cor == pCarta[Min].cor && pCarta[j].valor < pCarta[Min].valor) {
                Min = j;
            }
        }
        
        // Movimentar a troca para fora do loop interno
        if (Min != i) {
            aux = pCarta[Min];
            pCarta[Min] = pCarta[i];
            pCarta[i] = aux;
            movimentacoes++;
        }
    }
}

