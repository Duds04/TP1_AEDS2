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