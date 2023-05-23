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

TipoDib Bit(TipoIndexAmp i, char k[50]);
TipoArvore CriaNoInt(int i, TipoArvore* Esq, TipoArvore* Dir, char letra);
TipoArvore CriaNoExt(char k[50], int IdDoc);
TipoArvore Pesquisa (char k[50], TipoArvore t);
TipoArvore InsereEntre(char k[50], TipoArvore* t, int i, int IdDoc, char LetraDif);
TipoArvore Insere(char k[50], TipoArvore* t, int IdDoc);
short EExterno (TipoArvore p);
void MostraArvore(TipoArvore t);
void Busca_textos(TipoArvore t, char termos[250], int N_Doc, int* vetor_de_relevancia);
double Relevancia(TipoArvore t, char **palavras, int n_termos, int IDdoc, int N_Doc, int N_Palavras_doc);
double Peso_termo(TipoArvore t, int IDdoc, int N_Doc);
void Pal_por_Doc(TipoArvore t, int* Documentos);
char** separa_frase(char *frase, int *n_termos);