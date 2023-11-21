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
/*Essa funcao tranforma a cor em inteiros para que fique mais 
facil de ordena-lo*/
void DefineOrdem(TCarta* pCarta){
    for (int i = 0; i < 10; i++){
        if(pCarta[i].cor == "Verde"){
            pCarta[i].cor = 1;
        }
        else if(pCarta[i].cor == "Amarelo"){
            pCarta[i].cor = 2;
        }
        else if(pCarta[i].cor == "Vermelho"){
            pCarta[i].cor = 3;
        }
        else {
            pCarta[i].cor = 4;
        }
    }
}
void Destroca(TCarta* pCarta){
    for (int i = 0; i < 10; i++){
        if(pCarta[i].cor == 1){
            pCarta[i].cor = "Verde";
        }
        else if(pCarta[i].cor == 2){
            pCarta[i].cor = "Amarelo";
        }
        else if(pCarta[i].cor == 3){
            pCarta[i].cor = "Vermelho";
        }
        else {
            pCarta[i].cor = "Azul";
        }
    }
}
