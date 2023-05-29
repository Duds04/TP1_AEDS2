#include"patricia.h"

typedef struct documento{

    int IDDoc;
    double relevancia;

}Doc;

void Busca_textos(TipoArvore t, char termos[250], int N_Doc, Doc RelDocs[N_Doc]);
double Relevancia(TipoArvore t, char palavras[50][50], int n_termos, int IDdoc, int N_Doc, int N_Palavras_doc);
double Peso_termo(TipoArvore t, int IDdoc, int N_Doc);
void Pal_por_Doc(TipoArvore t, int* Documentos);
void separa_frase(char *frase, int *n_termos, char **palavras);
void separa_frase2(char* frase, int* n_palavras, char palavras[50][50]);
void ordenar_docs(Doc *RelDocs, int tamanho);
void Imprime_RolDocs(Doc RelDocs[], int N_Doc);
