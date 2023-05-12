#include "palavra.h"

typedef enum{
    Interno, Externo
} TipoNo;
typedef int TipoIndexAmp;
typedef char TipoDib;
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo{
    TipoNo nt;
    union{                          // Separa espaço para a maior estruturaem seu interior, variável ou é um ou outro
        struct{                     // mas com o mesmo espaço do maior entre eles 
            char letra;
            TipoIndexAmp Index;
            TipoArvore Esq, Dir;
        }NoInterno;

        TPalavra tpalavra;
    }NO;
}TipoPatNo;

TipoDib Bit(TipoIndexAmp i, TPalavra k);
TipoArvore CriaNoInt(int i, TipoArvore* Esq, TipoArvore* Dir, char letra);
TipoArvore CriaNoExt(TPalavra k, int IdDoc);
void Pesquisa (TPalavra k, TipoArvore t);
TipoArvore InsereEntre(TPalavra k, TipoArvore* t, int i, int IdDoc);
TipoArvore Insere(TPalavra k, TipoArvore* t, int IdDoc);
short EExterno (TipoArvore p);
void MostraArvore(TipoArvore t);