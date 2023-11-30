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

void NovaCarta(TCarta *pcarta, Cor cor, Tipo tipo, int valor) {
    pcarta->cor = cor;
    pcarta->tipo = tipo;

    if (pcarta->tipo != NUMERO) {
        pcarta->valor = valor;
    }
}

void MaoInicialCopia(TCarta *pCartaOriginal, TCarta *pCartaCopia) {
    for (int i = 0; i < 10; i++) {
        pCartaCopia[i].cor = pCartaOriginal[i].cor;
        pCartaCopia[i].tipo = pCartaOriginal[i].tipo;
        pCartaCopia[i].valor = pCartaOriginal[i].valor;
    }
}

Cor cor(FILE* arq, TCarta* pcarta) {
    char CorAux[20];  // Ajuste no tipo da variável para armazenar a string
    fscanf(arq, " %s", CorAux);  // Corrigir para ler a string do arquivo

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
Tipo tipo(FILE* arq, TCarta* pcarta) {
    char TipoAux[10];  // Ajuste no tipo da variável para armazenar a string
    fscanf(arq, " %s", TipoAux);  // Corrigir para ler a string do arquivo

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
    } else {
        return NUMERO;
    }
}


/*void LerCarta(FILE *arq, TCarta *cartas, int indice) {
    char corStr[20];
    char tipoStr[20];
    fscanf(arq, "(%s %d) ", corStr, &cartas[indice].valor);
    cartas[indice].cor = LerCor(arq, corStr);
    cartas[indice].tipo = LerTipo(arq, tipoStr);
}
*/

void MaoInicialArquivo(FILE* arq, TCarta* pCarta, int N) {
    char CorAux[20];  // Declare CorAux aqui
    for (int i = 0; i < N; i++) {
        TCarta v;
        fscanf(arq, "(%s %d) ", CorAux, &v.valor);
        v.cor = cor(arq, &v);  // Não é necessário passar &v para cor
        v.tipo = tipo(arq, &v);  // Não é necessário passar &v para tipo
        pCarta[i] = v;
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
