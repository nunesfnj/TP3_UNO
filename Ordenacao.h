#include "Carta.h"

void BubbleSort(TCarta cartas[], int tamanho);

void SelectionSort(TCarta* pCarta, int tamanho);

void InsertionSort();

void ShellSort();

void QuickSort(); 

void Refaz(int Esq, int Dir, TCarta* pCarta);
void Constroi(TCarta* pCarta, const int* tamanho);
void HeapSort(TCarta* pCarta, const int* tamanho);

void ImprimirComplexidade();
