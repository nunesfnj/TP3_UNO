#include "Ordenacao.h"

void BubbleSort (TCarta* v, int n ){
    int i, j;
    TCarta aux;
    for( i = 0 ; i < n-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j].cor < v[j-1].cor){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            } // if
        }
    }
}    

void SelectionSort (TCarta* v, int n){
    int i, j, Min;
    TCarta aux;
    for (i = 0; i < n - 1; i++){
        Min = i;
        for (j = i + 1 ; j < n; j++){
            if ( v[j].cor < v[Min].cor){
            Min = j;
            aux = v[Min];
            v[Min] = v[i];
            v[i] = aux;
            }
        }
    }
}

void InsertionSort(TCarta* pCarta, int n){ 
    int i,j;
    TCarta aux;
    for (i = 1; i < n; i++){
        aux = n[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux.cor < n[j].cor ) ){ //nao tenho ctz se n eh o vetor
            n[j + 1] = n[j];
            j--;
}
    n[j + 1] = aux;
}
}

void ShellSort(TCarta* pCarta, int n){

}

void QuickSort(TCarta* pCarta, int n){
    /* Entra aqui o procedimento Particao */
void Ordena(int Esq, int Dir, TCarta* pCarta){
    int i,j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
        if (i < Dir) Ordena(i, Dir, A);
}

Ordena(0, n-1, A);

void Particao(int Esq, int Dir,
    int *i, int *j, TCarta* pCarta){
    TCarta pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do{
    while (pivo.Chave > A[*i].Chave) (*i)++;
        while (pivo.Chave < A[*j].Chave) (*j)--;
            if (*i <= *j){
                aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
                (*i)++; (*j)--;
            }
        } while (*i <= *j);
}
}




















