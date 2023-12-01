#include <stdio.h>

typedef enum{
    VERDE,
    AMARELO, 
    VERMELHO, 
    AZUL,
    PRETO, 
} Cor;

typedef enum{
    NUMERO,
    PULAR,
    VOLTAR,
    MAIS_DOIS, 
    MAIS_QUATRO,
    CORINGA,
} Tipo;

typedef struct{
    Cor cor;
    Tipo tipo;
    int valor;
} TCarta;

void MaoInicial(TCarta* pCarta);

void MaoInicialCopia(TCarta* pCarta, TCarta *pCartaCopia);
void MaoInicialArquivo(FILE* arq, TCarta (*pCarta)[10], int N);
void ImprimirMao(TCarta cartas[], int tamanho);
void ImprimirCartas(TCarta cartas[][10], int N);
