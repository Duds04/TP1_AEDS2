//ARTHUR ATAIDE DE MELO SARAIVA - 5070
//MARIA EDUARDA DE PINHO BRAGA - 5099 
//JOÃO GABRIEL ANGELO BRADACHI - 5078
//ESDRAS ARAUJO FERREIRA - 5102

#include "ocorrencias.h"

typedef struct{

    char Palavra[50];
    LOcorrencias ocorrencias;

}TPalavra;

void Inicializa_Palavra(TPalavra* pPalavra);                          //Inicializa a estrutura TPalavra
void Preenche_Palavra(TPalavra* pPalavra, char *palavra);    //Preenche a palavra dentro da estrutura TPalavra
char* Retorna_Palavra(TPalavra* pPalavra);               //Retorna a palavra presente na estrutura
void Imprime_Palavra(TPalavra* pPalavra);                             //Imprime a palavra presente na estrutura
void Imprime_TPalavra(TPalavra* pPalavra);                            //Imprime a estrutura TPalavra ou seja imprime uma palavra e a lista de posicoes
void Insere_Ocorrencia_Palavra(TPalavra* pPalavra, int IdDoc);                 //Insere uma ocorrencia na lista de ocorrencias da palavra
float Ocorrencias_Palavra(TPalavra* pPalavra, int IdDoc);             //Retorna a quantidade de ocorrencias da palavra em um determinado documento
float Qtde_Docs_Palavra(TPalavra* pPalavra);                   //Retorna a quantidade de documentos em que a palavra ocorre
void Oc_Palavras_Docs(TPalavra* pPalavra, int *Documentos);