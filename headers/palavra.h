#include "ocorrencias.h"

typedef struct{

    char Palavra[50];
    LOcorrencias ocorrencias;

}TPalavra;

void Insere_Palavra(TPalavra* pPalavra, char *palavra, int IdDoc); //Preenche a palavra dentro da estrutura TPalavra
void Imprime_Palavra(TPalavra* pPalavra);                             //Imprime a palavra presente na estrutura
void Imprime_TPalavra(TPalavra* pPalavra);                            //Imprime a estrutura TPalavra ou seja imprime uma palavra e a lista de posicoes

