#include "Carta.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void MaoInicialCopia(TCarta *pCartaOriginal, TCarta *pCartaCopia) {
    for (int i = 0; i < 10; i++) {
        pCartaCopia[i].cor = pCartaOriginal[i].cor;
        pCartaCopia[i].tipo = pCartaOriginal[i].tipo;
        pCartaCopia[i].valor = pCartaOriginal[i].valor;
    }
}

Cor LerCor(FILE* arq, char* CorAux) {
    //char CorAux[20];  // Ajuste no tipo da variável para armazenar a string
    //fscanf(arq, "%s", CorAux);   Corrigir para ler a string do arquivo

    if (strcmp(CorAux, "Verde") == 0) {
        return VERDE;
    } else if (strcmp(CorAux, "Amarelo") == 0) {
        return AMARELO;
    } else if (strcmp(CorAux, "Vermelho") == 0) {
        return VERMELHO;
    } else if (strcmp(CorAux, "Azul") == 0) {
        return AZUL;
    } else if (strcmp(CorAux, "Preto") == 0) {
        return PRETO;
    } else {
        printf("Erro ao ler a cor da carta\n");
        fclose(arq);
        exit(1);  // Terminar o programa em caso de erro
    }
}



// Função para converter uma string para Tipo
Tipo LerTipo(FILE* arq, char* TipoAux, TCarta *pcarta) {
    //char TipoAux[20];  // Ajuste no tipo da variável para armazenar a string
    //fscanf(arq, " %s", TipoAux);   Corrigir para ler a string do arquivo

    if (strcmp(TipoAux, "Pular") == 0) {
        return PULAR;
    } else if (strcmp(TipoAux, "Voltar") == 0) {
        return VOLTAR;
    } else if (strcmp(TipoAux, "+2") == 0) {
        return MAIS_DOIS;
    } else if (strcmp(TipoAux, "+4") == 0) {
        return MAIS_QUATRO;
    } else if (strcmp(TipoAux, "Coringa") == 0) {
        return CORINGA;
    } else if (strcmp(TipoAux, "0") == 0){
        pcarta->valor = 0;
        return NUMERO;
    }else if (strcmp(TipoAux, "1") == 0){
        pcarta->valor = 1;
        return NUMERO;
    }else if (strcmp(TipoAux, "2") == 0){
        pcarta->valor = 2;
        return NUMERO;
    }else if (strcmp(TipoAux, "3") == 0){
        pcarta->valor = 3;
        return NUMERO;
    }else if (strcmp(TipoAux, "4") == 0){
        pcarta->valor = 4;
        return NUMERO;
    }else if (strcmp(TipoAux, "5") == 0){
        pcarta->valor = 5;
        return NUMERO;
    }else if (strcmp(TipoAux, "6") == 0){
        pcarta->valor = 6;
        return NUMERO;
    }else if (strcmp(TipoAux, "7") == 0){
        pcarta->valor = 7;
        return NUMERO;
    }else if (strcmp(TipoAux, "8") == 0){
        pcarta->valor = 8;
        return NUMERO;
    }else if (strcmp(TipoAux, "9") == 0){
        pcarta->valor = 9;
        return NUMERO;
    }else if (strcmp(TipoAux, "10") == 0){
        pcarta->valor = 10;
        return NUMERO;
    }
}

void MaoInicialArquivo(FILE* arq, TCarta (*pCarta)[10], int N) {
    char CorAux[20];  // Declare CorAux aqui
    char TipoAux[20];
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(arq, " (%[^( ] %[^)])", CorAux, TipoAux);
            pCarta[i][j].cor = LerCor(arq, CorAux);  
            pCarta[i][j].tipo = LerTipo(arq, TipoAux, &pCarta[i][j]);
        }
    }
}

void ImprimirMao(TCarta cartas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d]: ", i + 1);
        switch (cartas[i].tipo) {
            case NUMERO:
                printf("%s %d\n", cartas[i].cor == VERDE ? "Verde" :
                                       cartas[i].cor == AMARELO ? "Amarelo" :
                                       cartas[i].cor == VERMELHO ? "Vermelho" : "Azul",
                       cartas[i].valor);
                break;
            case PULAR:
                printf("%s Pular\n", cartas[i].cor == VERDE ? "Verde" :
                                       cartas[i].cor == AMARELO ? "Amarelo" :
                                       cartas[i].cor == VERMELHO ? "Vermelho" : "Azul");
                break;
            case VOLTAR:
                printf("%s Voltar\n", cartas[i].cor == VERDE ? "Verde" :
                                       cartas[i].cor == AMARELO ? "Amarelo" :
                                       cartas[i].cor == VERMELHO ? "Vermelho" : "Azul");
                break;
            case MAIS_DOIS:
                printf("%s +2\n", cartas[i].cor == VERDE ? "Verde" :
                                   cartas[i].cor == AMARELO ? "Amarelo" :
                                   cartas[i].cor == VERMELHO ? "Vermelho" : "Azul");
                break;
            case MAIS_QUATRO:
                printf("Preto +4\n");
                break;
            case CORINGA:
                printf("Preto Coringa\n");
                break;
        }
    }
    }

// usado para imprimir a mao no arquivo
void ImprimirCartas(TCarta cartas[][10], int N) {
    for (int i = 0; i < N; i++) {
        printf("Conjunto %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("[%d]: ", j + 1);
            switch (cartas[i][j].tipo) {
                case NUMERO:
                    printf("%s %d\n", cartas[i][j].cor == VERDE ? "Verde" :
                                           cartas[i][j].cor == AMARELO ? "Amarelo" :
                                           cartas[i][j].cor == VERMELHO ? "Vermelho" : "Azul",
                           cartas[i][j].valor);
                    break;
                case PULAR:
                    printf("%s Pular\n", cartas[i][j].cor == VERDE ? "Verde" :
                                           cartas[i][j].cor == AMARELO ? "Amarelo" :
                                           cartas[i][j].cor == VERMELHO ? "Vermelho" : "Azul");
                    break;
                case VOLTAR:
                    printf("%s Voltar\n", cartas[i][j].cor == VERDE ? "Verde" :
                                           cartas[i][j].cor == AMARELO ? "Amarelo" :
                                           cartas[i][j].cor == VERMELHO ? "Vermelho" : "Azul");
                    break;
                case MAIS_DOIS:
                    printf("%s +2\n", cartas[i][j].cor == VERDE ? "Verde" :
                                       cartas[i][j].cor == AMARELO ? "Amarelo" :
                                       cartas[i][j].cor == VERMELHO ? "Vermelho" : "Azul");
                    break;
                case MAIS_QUATRO:
                    printf("Preto +4\n");
                    break;
                case CORINGA:
                    printf("Preto Coringa\n");
                    break;
            }
        }
        printf("\n");
    }
}
