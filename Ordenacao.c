#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

// Variáveis globais para rastrear a complexidade
int comparacoes = 0;
int movimentacoes = 0;
clock_t start_time, end_time;
double cpu_time_used;

void ImprimirComplexidade() {
    printf("Comparacoes: %d, Movimentacoes: %d, Tempo: %f segundos\n", comparacoes, movimentacoes, cpu_time_used);
}

void BubbleSort(TCarta* pCarta, int tamanho) {
    int i, j;
    TCarta aux;

    // Início da contagem de tempo
    start_time = clock();

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 1; j < tamanho - i; j++) {
            // Compara primeiro as cores
            comparacoes++;
            if ((pCarta[j].cor < pCarta[j - 1].cor) || (pCarta[j].cor == pCarta[j - 1].cor && pCarta[j].valor < pCarta[j - 1].valor)) {
                aux = pCarta[j];
                pCarta[j] = pCarta[j - 1];
                pCarta[j - 1] = aux;
                movimentacoes++;
            }
        }
    }

    // Fim da contagem de tempo
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

void SelectionSort(TCarta* pCarta, int tamanho) {
    int i, j, Min;
    TCarta aux;
    
    // Início da contagem de tempo
    start_time = clock();
    
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
    

void insertion(TCarta* pCarta, int n){
    int i, j;
    TCarta aux;
    for(i = 1; i < tamanho - 1; i++) {
comparações++; 
    if (pCarta.cor == pCarta[i-1].cor){
     aux = pCarta[i];
     j = i-1;
        

    while( (j >= 0 ) &&(aux.valor < pCarta.valor) {
      pCarta[j+1] = pCarta[j];
      j--;
movimentações++;
          }
          pCarta[j+1] = aux;


    }
Else if (pCarta.cor < pCarta[i-1].cor) {
    aux = pCarta[i];
    j = i-1;
comparações++;

    while((j >= 0) && (aux.cor < pCarta.cor)) {
    pCarta[j+1] = pCarta[j];
    j--;
movimentações;
    }

}
}
}


    // Fim da contagem de tempo
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

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

    // Início da contagem de tempo
    start_time = clock();
    
    Constroi(pCarta, tamanho); /* constroi o heap */
    
    Dir = *tamanho;
    
    while (Dir > 1) { /* ordena o vetor */
        aux = pCarta[1];
        pCarta[1] = pCarta[Dir];
        pCarta[Dir] = aux;
        Dir--;
        Refaz(1, Dir, pCarta);  // Ajuste aqui para usar Esq = 1
    }
    // Fim da contagem de tempo
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

