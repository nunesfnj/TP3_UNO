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

void Selectsort (TCarta* v, int n){
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
