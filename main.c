#include "Ordenacao.h"
#include <stdio.h>
#include <time.h>

int main(){

    TCarta mao1;
    MaoInicial(&mao1);
    ContabilizaCores(&mao1);
    clock_t inicio = clock(); //Inicia o registro de tempo
    BubbleSort(&mao1, 10);
    BubbleSortValor(&mao1, 10);
    ImprimeMaoOrdenada(&mao1);
    clock_t fim = clock(); //Termina o registro de tempo
    double tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return 0;
}
