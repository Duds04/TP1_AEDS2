#include "palavra.h""

typedef enum{
    Interno, Externo
} TipoNo;

typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo{
    TipoNo nt;
    union{                          // Separa espaço para a maior estruturaem seu interior, variável ou é um ou outro
        struct{                     // mas com o mesmo espaço do maior entre eles 
            char letra_no;
            int index;
            TipoArvore Esq, Dir;
        }NoInterno;

        TPalavra tpalavra;
    }NO;
}TipoPatNo;

void InsercaoPat(char* palavra, TipoArvore* t); // função de inserção
TipoArvore CriaNoExt(char* palavra); // inserção auxiliar folha

