#include <stdio.h>

//definindo as cores para printar as cartas bonitinhas
#define VERMELHO_P "\033[31m"
#define VERDE_P "\033[32m"
#define AMARELO_P "\033[33m"
#define AZUL_P "\033[34m"
#define NORMAL_P "\033[0m"

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
void ImprimirMao(TCarta cartas[], int tamanho);
