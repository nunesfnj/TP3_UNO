#include "Carta.h"

void BubbleSort(TCarta cartas[], int tamanho);
void SelectSort(TCarta* pCarta, int tamanho);
void ShellSort(TCarta* pCarta, int tamanho);

void Refaz(int Esq, int Dir, TCarta* pCarta);
void Constroi(TCarta* pCarta, const int* tamanho);
void HeapSort(TCarta* pCarta, const int* tamanho);

void ImprimirComplexidade();
