//ARTHUR ATAIDE DE MELO SARAIVA - 5070
//MARIA EDUARDA DE PINHO BRAGA - 5099 
//JOÃO GABRIEL ANGELO BRADACHI - 5078
//ESDRAS ARAUJO FERREIRA - 5102

#include "include.h"

typedef struct Ocorrencia* POcorrencia;
typedef struct Ocorrencia { 
    
    int IdDOc;
    int qtde;
    POcorrencia pProx;

}TipoOcorrencia;

typedef struct {
    
    POcorrencia pPrimeiro;
    POcorrencia pUltimo;
    
}LOcorrencias;

void FLOcorrencias_Vazia(LOcorrencias* pLista);
void Insere_Ocorrencia(LOcorrencias* pLista, int IdDOc);
void Imprimir_Ocorrencia(LOcorrencias* pLista);
POcorrencia Verifica_Ocorrencia(LOcorrencias* pLista, int IdDoc);
int Tamanho_LOcorrencia(LOcorrencias* pLista);