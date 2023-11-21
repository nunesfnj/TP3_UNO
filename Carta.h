#ifndef TP3_CARTA_H
#define TP3_CARTA_H

typedef struct{
    char cor;
    int valor;
} TCarta;

void MaoInicial(TCarta* pCarta);
void DefineOrdem(TCarta* pCarta);
void Destroca(TCarta* pCarta);


#endif //TP3_CARTA_H
