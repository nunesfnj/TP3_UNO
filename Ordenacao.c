#include "Ordenacao.h"
#include <stdio.h>

// Variáveis globais para rastrear a complexidade
int comparacoes = 0;
int movimentacoes = 0;

void ImprimirComplexidade() {
    printf("Comparacoes: %d, Movimentacoes: %d", comparacoes, movimentacoes);
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

void ShellSort(TCarta* pCarta, int tamanho) {
    int i, j;
    int h = 1;
    TCarta aux;

    do h = h * 3 + 1; while (h < tamanho);
    
    do {
        h = h / 3;
        for (i = h; i < tamanho; i++) {
            aux = pCarta[i];
            j = i;

            while (j >= h && (pCarta[j - h].cor > aux.cor || (pCarta[j - h].cor == aux.cor && pCarta[j - h].valor > aux.valor))) {
                pCarta[j] = pCarta[j - h];
                j -= h;
            }

            pCarta[j] = aux;
        }
    } while (h != 1);
}

//Todas as funcoes seguintes sao usadas para o funcionamento correto do HeapSort
void Refaz(int Esq, int Dir, TCarta* pCarta){
    int j = Esq * 2;
    TCarta aux = pCarta[Esq];
    
    while (j <= Dir){
        if ((j < Dir) && (
            pCarta[j].cor < pCarta[j+1].cor ||
            (pCarta[j].cor == pCarta[j+1].cor && pCarta[j].valor < pCarta[j+1].valor)
        )) {
            j++;
        }
        
        if (aux.cor > pCarta[j].cor || (aux.cor == pCarta[j].cor && aux.valor > pCarta[j].valor)) {  // Ajuste aqui para corrigir a condição
            break;
        }
        
        pCarta[Esq] = pCarta[j];
        Esq = j;
        j = Esq * 2;
    }
    
    pCarta[Esq] = aux;
}


void Constroi(TCarta* pCarta, const int* tamanho){
    int Esq;
    Esq = *tamanho / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *tamanho, pCarta);
    }
}

void HeapSort(TCarta* pCarta, const int* tamanho){
    int Esq, Dir;
    TCarta aux;
    Constroi(pCarta, tamanho); /* constroi o heap */
    
    Dir = *tamanho;
    
    while (Dir > 1) { /* ordena o vetor */
        aux = pCarta[1];
        pCarta[1] = pCarta[Dir];
        pCarta[Dir] = aux;
        Dir--;
        Refaz(1, Dir, pCarta);  // Ajuste aqui para usar Esq = 1
    }
}
