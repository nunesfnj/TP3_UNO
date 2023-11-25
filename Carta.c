#include "Carta.h" 
#include <stdio.h>
#include <stdlib.h>


void MaoInicial(TCarta* pCarta){
    for (int i = 0; i < 10; i++){
        printf("Cor carta %s: ", i+1);
        scanf(" %c", & pCarta[i].cor);
        printf("Valor carta %d: ", i+1);
        scanf("%d", & pCarta[i].valor);
        }
    }


void ImprimeMao(TCarta *pCarta){
    //falta implementar imprime
    for (int i = 0; i < 10; i++){
        printf("\nCarta [%d]: %d", i+1, pCarta[i]); //nao sei imprimir a carta //usar typedef enum
    } //conferir depois tamanho da mao inicial

}
