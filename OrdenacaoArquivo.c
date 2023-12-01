#include "OrdenacaoArquivo.h"
#include <time.h>
#include <stdio.h>

int comparacoes = 0;
int movimentacoes = 0;
clock_t start_time, end_time;
double cpu_time_used;

void MaoInicialCopiaArquivo(TCarta pCartaOriginal[][10], TCarta pCartaCopia[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            pCartaCopia[i][j].cor = pCartaOriginal[i][j].cor;
            pCartaCopia[i][j].tipo = pCartaOriginal[i][j].tipo;
            pCartaCopia[i][j].valor = pCartaOriginal[i][j].valor;
        }
    }
}



void BubbleSortArquivo(TCarta (*pCarta)[10], int N) {
    int i, j;
    TCarta aux;

    start_time = clock();

    for (int k = 0; k < N; k++) {
        for (i = 0; i < 10 - 1; i++) {
            for (j = 1; j < 10 - i; j++) {
                comparacoes++;
                if ((pCarta[k][j].cor < pCarta[k][j - 1].cor) || (pCarta[k][j].cor == pCarta[k][j - 1].cor && pCarta[k][j].valor < pCarta[k][j - 1].valor)) {
                    aux = pCarta[k][j];
                    pCarta[k][j] = pCarta[k][j - 1];
                    pCarta[k][j - 1] = aux;
                    movimentacoes += 3;
                }
            }
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

void SelectionSortArquivo(TCarta (*pCarta)[10], int N) {
    int i, j, Min;
    TCarta aux;

    start_time = clock();

    for (int k = 0; k < N; k++) {
        for (i = 0; i < 10 - 1; i++) {
            Min = i;

            for (j = i + 1; j < 10; j++) {
                comparacoes++;
                if (pCarta[k][j].cor < pCarta[k][Min].cor) {
                    Min = j;
                } else if (pCarta[k][j].cor == pCarta[k][Min].cor && pCarta[k][j].valor < pCarta[k][Min].valor) {
                    Min = j;
                }
            }

            if (Min != i) {
                aux = pCarta[k][Min];
                pCarta[k][Min] = pCarta[k][i];
                pCarta[k][i] = aux;
                movimentacoes += 3;
            }
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

void InsertionSortArquivo(TCarta (*pCarta)[10], int N) {
    int i, j;
    TCarta aux;

    for (int k = 0; k < N; k++) {
        for (i = 1; i < 10; i++) {
            comparacoes++;
            aux = pCarta[k][i];
            j = i - 1;

            while ((j >= 0) && ((aux.cor == pCarta[k][j].cor && aux.valor < pCarta[k][j].valor) || (aux.cor < pCarta[k][j].cor))) {
                pCarta[k][j + 1] = pCarta[k][j];
                j--;
                movimentacoes++;
            }

            pCarta[k][j + 1] = aux;
        }
    }
}

void ShellSortArquivo(TCarta (*pCarta)[10], int N) {
    int i, j;
    int h = 1;
    TCarta aux;

    start_time = clock();

    do {
        h = h * 3 + 1;
    } while (h < 10);

    do {
        h = h / 3;
        for (int k = 0; k < N; k++) {
            for (i = h; i < 10; i++) {
                aux = pCarta[k][i];
                j = i;

                comparacoes++;
                while (pCarta[k][j - h].cor > aux.cor || (pCarta[k][j - h].cor == aux.cor && pCarta[k][j - h].valor > aux.valor)) {
                    pCarta[k][j] = pCarta[k][j - h];
                    movimentacoes++;
                    j -= h;
                    if (j < h)
                        break;
                }

                pCarta[k][j] = aux;
            }
        }
    } while (h != 1);

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}
void Particao(int Esq, int Dir, int *i, int *j, TCarta (*pCarta)[10]) {
    TCarta pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = pCarta[(*i + *j) / 2][0]; /* Obtem o pivo x */
    do {
        while ((pCarta[0][*i].cor < pivo.cor) || (pCarta[0][*i].cor == pivo.cor && pCarta[0][*i].valor < pivo.valor))
            (*i)++;
        while ((pCarta[0][*j].cor > pivo.cor) || (pCarta[0][*j].cor == pivo.cor && pCarta[0][*j].valor > pivo.valor))
            (*j)--;
        if (*i <= *j) {
            aux = pCarta[0][*i];
            pCarta[0][*i] = pCarta[0][*j];
            pCarta[0][*j] = aux;
            (*i)++;
            (*j)--;
            movimentacoes += 3;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, TCarta (*pCarta)[10]) {
    int i, j;
    comparacoes++;
    Particao(Esq, Dir, &i, &j, pCarta);
    if (Esq < j)
        Ordena(Esq, j, pCarta);

    if (i < Dir)
        Ordena(i, Dir, pCarta);
}

void QuickSortArquivo(TCarta (*pCarta)[10], int N) {
    for (int k = 0; k < N; k++) {
        Ordena(0, 10 - 1, pCarta[k]);
    }
}


void Refaz(int i, int tamanho, TCarta (*pCarta)[10]) {
    int j = i * 2 + 1;
    TCarta aux = pCarta[0][i];

    while (j < tamanho) {
        comparacoes++;
        if (j + 1 < tamanho &&
            (pCarta[0][j].cor < pCarta[0][j + 1].cor ||
             (pCarta[0][j].cor == pCarta[0][j + 1].cor && pCarta[0][j].valor < pCarta[0][j + 1].valor)))
            j++;
        if (aux.cor > pCarta[0][j].cor ||
            (aux.cor == pCarta[0][j].cor && aux.valor >= pCarta[0][j].valor))
            break;
        pCarta[0][i] = pCarta[0][j];
        i = j;
        j = i * 2 + 1;
    }
    pCarta[0][i] = aux;
}

void Constroi(TCarta (*pCarta)[10], int tamanho) {
    int i = tamanho / 2;
    while (i > 0) {
        i--;
        Refaz(i, tamanho, pCarta);
        movimentacoes++;
    }
}


void HeapSortArquivo(TCarta (*pCarta)[10], int N) {
    TCarta aux;

    start_time = clock();

    for (int k = 0; k < N; k++) {
        Constroi(pCarta[k], 10);
        while (N > 1) {
            N--;
            aux = pCarta[k][0];
            pCarta[k][0] = pCarta[k][10];
            pCarta[k][10] = aux;
            Refaz(0, 10, pCarta[k]);
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}
