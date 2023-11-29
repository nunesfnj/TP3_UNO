#include "Carta.h"

void BubbleSort(TCarta cartas[], int tamanho);
void SelectionSort(TCarta* pCarta, int tamanho);
void ShellSort(TCarta* pCarta, int tamanho);
void InsertionSort(TCarta* pCarta, int tamanho);

void Refaz(int Esq, int Dir, TCarta* pCarta);
void Constroi(TCarta* pCarta, int tamanho);
void HeapSort(TCarta* pCarta, int tamanho);

void ImprimirComplexidade();
