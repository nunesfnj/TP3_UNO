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
void NovaCarta(TCarta *pcarta, Cor cor, Tipo tipo, int valor);
void LerCarta(FILE *arq, TCarta *cartas, int indice);
void MaoInicialCopia(TCarta* pCarta, TCarta *pCartaCopia);
void MaoInicialArquivo(FILE *arq, TCarta *pCarta, int N);
void ImprimirMao(TCarta cartas[], int tamanho);
