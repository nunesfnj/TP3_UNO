#include "Ordenacao.h"

//definindo inteiros para contabilizar quantidade de cartas de mesma cor
int countVerde, countAmarelo, countVermelho, countAzul;



//contabiliza a quantidade de cores atraves de um case
void Contabilizacores(TCarta *pCarta){
    void DefineOrdem(TCarta *pCarta);
    for(int i=0; i<10; i++){
        switch (pCarta[i].cor){
        case 1:
        countVerde += 1;
            break;
        case 2:
        countAmarelo += 1;
            break;
        case 3:
        countVermelho += 1;
            break;
        case 4:
        countAzul += 1;
            break;
        }
    }
}
void BubbleSortCor (TCarta* v, int n ){
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
void BubbleSortValor (TCarta* v, int n ){
    int i, j;
    TCarta aux;
    for( i = 0 ; i < countVerde-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j].valor < v[j-1].valor){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            } // if
        }
    }
    for( i += countVerde ; i < countVerde+countAmarelo-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j].valor < v[j-1].valor){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            } // if
        }
    }
    for( i += countVerde+countAmarelo ; i < countVerde+countAmarelo+countVermelho-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j].valor < v[j-1].valor){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            } // if
        }
    }
    for( i += countVerde+countAmarelo+countVermelho ; i < countVerde+countAmarelo+countVermelho+countAzul-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j].valor < v[j-1].valor){
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

void ImprimeMaoOrdenada(TCarta* pCarta){
    void Destroca(TCarta* pCarta);
    for (int i = 0; i < 10; i++){
        printf("Cor carta %s: ", i+1);
        printf("Valor carta %d: ", i+1);
        }
} 
