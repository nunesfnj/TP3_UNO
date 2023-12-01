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
                movimentacoes += 3;
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
            movimentacoes += 3;
        }
    }

    // Fim da contagem de tempo
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

void InsertionSort(TCarta* pCarta, int tamanho) {
    int i, j;
    TCarta aux;

    for (i = 1; i < tamanho; i++) {
        comparacoes ++;
        aux = pCarta[i];
        j = i - 1;

        while ((j >= 0) && ((aux.cor == pCarta[j].cor && aux.valor < pCarta[j].valor) || (aux.cor < pCarta[j].cor))) {
            pCarta[j + 1] = pCarta[j];
            j--;
            movimentacoes ++;
        }

        pCarta[j + 1] = aux;
    }
}

void ShellSort(TCarta* pCarta, int tamanho) {
    int i, j;
    int h = 1;
    TCarta aux;

    do {
        h = h * 3 + 1;
    } while (h < tamanho);

    do {
        h = h / 3;
        for (i = h; i < tamanho; i++) {
            aux = pCarta[i];
            j = i;
            
            comparacoes ++;
            // Comparação considerando cor e valor
            while (pCarta[j - h].cor > aux.cor || (pCarta[j - h].cor == aux.cor && pCarta[j - h].valor > aux.valor)) {
                pCarta[j] = pCarta[j - h];
                movimentacoes++;
                j -= h;
                if (j < h) break;
            }
            
            pCarta[j] = aux;
        }
    } while (h != 1);
}




void Particao(int Esq, int Dir, int *i, int *j, TCarta* pCarta) {
    TCarta pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = pCarta[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while ((pCarta[*i].cor < pivo.cor) || (pCarta[*i].cor == pivo.cor && pCarta[*i].valor < pivo.valor))
            (*i)++;
        while ((pCarta[*j].cor > pivo.cor) || (pCarta[*j].cor == pivo.cor && pCarta[*j].valor > pivo.valor))
            (*j)--;
        if (*i <= *j) {
            aux = pCarta[*i];
            pCarta[*i] = pCarta[*j];
            pCarta[*j] = aux;
            (*i)++;
            (*j)--;
            movimentacoes += 3;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, TCarta* pCarta) {
    int i, j;
    comparacoes ++;
    Particao(Esq, Dir, &i, &j, pCarta);
    if (Esq < j)
        Ordena(Esq, j, pCarta);

    if (i < Dir)
        Ordena(i, Dir, pCarta);
    
}

void QuickSort(TCarta* pCarta, int tamanho){
    Ordena(0, tamanho-1, pCarta);
}


void Refaz(int i, int tamanho, TCarta* pCarta) {
    int j = i * 2 + 1;
    TCarta aux = pCarta[i];
    
    while (j < tamanho) {
        comparacoes ++;
        if (j + 1 < tamanho && 
            (pCarta[j].cor < pCarta[j + 1].cor || 
            (pCarta[j].cor == pCarta[j + 1].cor && pCarta[j].valor < pCarta[j + 1].valor)))
            j++;
        if (aux.cor > pCarta[j].cor || 
            (aux.cor == pCarta[j].cor && aux.valor >= pCarta[j].valor))
            break;
        pCarta[i] = pCarta[j];
        i = j;
        j = i * 2 + 1;
    }
    pCarta[i] = aux;
}

void Constroi(TCarta* pCarta, int tamanho) {
    int i = tamanho / 2;
    while (i > 0) {
        i--;
        Refaz(i, tamanho, pCarta);
        movimentacoes ++;
    }
}

void HeapSort(TCarta *pCarta, int tamanho) {
    TCarta aux;
    start_time = clock();
    Constroi(pCarta, tamanho);
    while (tamanho > 1) {
        tamanho--;
        aux = pCarta[0];
        pCarta[0] = pCarta[tamanho];
        pCarta[tamanho] = aux;
        Refaz(0, tamanho, pCarta);
    }
    // Fim da contagem de tempo
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}




