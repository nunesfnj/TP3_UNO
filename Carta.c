#include "Carta.h" 
#include <stdio.h>
#include <stdlib.h>

void MaoInicial(TCarta *pCarta) {
    for (int i = 0; i < 10; i++) {
        int cor, tipo;
        
        printf("Cor carta %d (0-VERDE, 1-AMARELO, 2-VERMELHO, 3-AZUL, 4-PRETO): ", i + 1);
        scanf("%d", &cor);
        pCarta[i].cor = (Cor)cor; //converte um valor inteiro para o tipo de enumeração Cor

        printf("Tipo carta %d (0-NUMERO, 1-PULAR, 2-VOLTAR, 3-MAIS_DOIS, 4-MAIS_QUATRO, 5-CORINGA): ", i + 1);
        scanf("%d", &tipo);
        pCarta[i].tipo = (Tipo)tipo; //converte um valor inteiro para o tipo de enumeração Tipo
        
        if(tipo == 0){
            printf("Valor carta %d: ", i + 1);
            scanf("%d", &pCarta[i].valor);
        }
        
        else if(tipo == 1){
            pCarta[i].valor = 10;
        }

        else if(tipo == 2){
            pCarta[i].valor = 11;
        }

        else if(tipo == 3){
            pCarta[i].valor = 12;
        }

        else if(tipo == 4){
            pCarta[i].valor = 13;
        }

        else if(tipo == 5){
            pCarta[i].valor = 14;
        }

        else{
            printf("insira um valor correto");
        }
        
    }
}

void ImprimirMao(TCarta cartas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d]: ", i + 1);
        switch (cartas[i].tipo) {
            case NUMERO:
                printf("%s %d\n", cartas[i].cor == VERDE ? VERDE_P"Verde"NORMAL_P :
                                       cartas[i].cor == AMARELO ? AMARELO_P"Amarelo"NORMAL_P :
                                       cartas[i].cor == VERMELHO ? VERMELHO_P"Vermelho"NORMAL_P : AZUL_P"Azul"NORMAL_P,
                       cartas[i].valor);
                break;
            case PULAR:
                printf("%s Pular%s\n", cartas[i].cor == VERDE ? VERDE_P : 
                                       cartas[i].cor == AMARELO ? AMARELO_P : 
                                       cartas[i].cor == VERMELHO ? VERMELHO_P : AZUL_P,
                                       NORMAL_P);
                break;
            case VOLTAR:
                printf("%s Voltar%s\n", cartas[i].cor == VERDE ? VERDE_P : 
                                        cartas[i].cor == AMARELO ? AMARELO_P : 
                                        cartas[i].cor == VERMELHO ? VERMELHO_P : AZUL_P,
                                        NORMAL_P);
                break;
            case MAIS_DOIS:
                printf("%s +2%s\n", cartas[i].cor == VERDE ? VERDE_P : 
                                   cartas[i].cor == AMARELO ? AMARELO_P : 
                                   cartas[i].cor == VERMELHO ? VERMELHO_P : AZUL_P,
                                   NORMAL_P);
                break;
            case MAIS_QUATRO:
                printf("%sPreto +4%s\n", VERDE_P, NORMAL_P);
                break;
            case CORINGA:
                printf("%sPreto Coringa%s\n", VERDE_P, NORMAL_P);
                break;
        }
    }
}
