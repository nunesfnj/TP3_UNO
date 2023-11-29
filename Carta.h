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
void MaoInicialAleatoria(TCarta *pCarta);
void ImprimirMao(TCarta cartas[], int tamanho);
