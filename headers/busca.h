#include"patricia.h"

typedef struct documento{

    int IDDoc;
    double relevancia;

}Doc;

void Busca_textos(TipoArvore t, char termos[250], int N_Doc, Doc RelDocs[N_Doc]);
double Relevancia(TipoArvore t, char **palavras, int n_termos, int IDdoc, int N_Doc, int N_Palavras_doc);
double Peso_termo(TipoArvore t, int IDdoc, int N_Doc);
void Pal_por_Doc(TipoArvore t, int* Documentos);
char** separa_frase(char *frase, int *n_termos);