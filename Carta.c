#include "Carta.h" 
#include <stdio.h>
#include <stdlib.h>


void MaoInicial(TCarta* pCarta){
    for (int i = 0; i < 3; i++){
        printf("Cor carta % d: (0 para VERDE, 1 para AMARELO, 2 para VERMELHO, 3 para AZUL", i+1);
        scanf(" %d", & pCarta[i].cor);
        printf("Tipo carta % d: (0 para NUMERO, 1 para PULAR, 2 para VOLTAR, 3 para MAIS_DOIS, 4 para MAIS_QUATRO, 5 para CORINGA)", i+1);
        scanf(" %d", & pCarta[i].tipo);
        printf("Valor carta %d: ", i);
        scanf("%d", & pCarta[i].valor);
    }
}

void ImprimeMao(TCarta *pCarta){
    //falta implementar imprime
    for (int i = 0; i < 10; i++){
        printf("\nCarta [%d]: %d", i, pCarta[i]); //nao sei imprimir a carta //usar typedef enum
    } //conferir depois tamanho da mao inicial

}
