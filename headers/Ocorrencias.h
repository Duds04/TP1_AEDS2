#include "include.h"

typedef struct Ocorrencia* POcorrencia;
typedef struct Ocorrencia { 
    
    char documento[50];
    int posicao;
    int ocorrencias;
    POcorrencia pProx;

}TipoOcorrencia;

typedef struct {
    
    POcorrencia pPrimeiro;
    POcorrencia pUltimo;
    
}LOcorrencias;

void FLOcorrencias_Vazia(LOcorrencias* pLista);
void Insere_Ocorrencia(LOcorrencias* pLista, int posicao);
void Imprimir_Ocorrencia(LOcorrencias* pLista);
int Verifica_Ocorrencia(LOcorrencias* pLista, int posicao);