#include "../headers/busca.h"


//Função que calcula a relevancia dos documentos, parametros: arvore, vetor de termos, numero de termos, Id do documento, numero de documentos
void Busca_textos(TipoArvore t, char termos[250], int N_Doc, Doc RelDocs[N_Doc]){
    
    int i;
    double peso = 0;

    //Cria e inicializa vetor com o numero de palavras por documento
    int pal_por_doc[N_Doc];
    for(int i = 0; i < N_Doc; i++){
        pal_por_doc[i] = 0;
    }
    //Calcula o numero de palavras por documento e preenche o vetor
    Pal_por_Doc(t, pal_por_doc);

    int n_palavras;
    char **palavras = separa_frase(termos, &n_palavras);
    for(i = 0; i < N_Doc; i++){
    printf("//////////////////////////////////////////////////////////////////\n");
        RelDocs[i].relevancia = Relevancia(t, palavras, n_palavras, i, N_Doc, pal_por_doc[i]);
        printf("abom\n");
        RelDocs[i].IDDoc = i;
        printf("ID documento: %d\n", RelDocs[i].IDDoc);
    }

    return;

}

//Função que calcula a relevancia de um documento, parametros: arvore, vetor de termos, numero de termos, Id do documento, numero de documentos, numero de palavras no documento
double Relevancia(TipoArvore t, char **palavras, int n_termos, int IDdoc, int N_Doc, int N_Palavras_doc){
    printf("%d\n", n_termos);
    int i;
    double relevancia = 0;
    TipoArvore aux;
    for(i = 0; i < n_termos; i++){
        printf("%s\n", palavras[i]);
        aux = Pesquisa(palavras[i], t);
        relevancia += Peso_termo(aux, IDdoc, N_Doc);
        printf("%f", Peso_termo(aux, IDdoc, N_Doc));
        printf("que merda\n");
        printf("N_Palavras_doc: %d\n", N_Palavras_doc);
        printf("relevancia antes: %f\n", relevancia);

        printf("1/N_Palavras_doc: %f\n", (1/N_Palavras_doc));
        printf("relevancia depois: %f\n", (relevancia/N_Palavras_doc));
        relevancia = relevancia/N_Palavras_doc;
        printf("%f\n", relevancia);
    }
    printf("opadois\n");
    return relevancia;

}

//Função que calcula o peso de um termo em um documento, parametros: Nó da arvore que contém o termo, Id do documento, numero de documentos
double Peso_termo(TipoArvore t, int IDdoc, int N_Doc){

    double peso;

    peso = Ocorrencias_Palavra(&t->NO.tpalavra, IDdoc) * log10(N_Doc/Qtde_Docs_Palavra(&t->NO.tpalavra));
    return peso;

}

//Função que separa e conta as palavras de uma frase, parametros: frase, ponteiro para o numero de palavras
char** separa_frase(char *frase, int* n_palavras){

    char *palavra = strtok(frase, " ");
    char **palavras = malloc(sizeof(char*));
    int i = 0;
    *n_palavras = 0;
    while(palavra != NULL){

        palavras[i] = malloc(sizeof(char)*strlen(palavra));
        strcpy(palavras[i], palavra);
        palavra = strtok(NULL, " ");
        i++;
        (*n_palavras)++;
        palavras = realloc(palavras, sizeof(char*)*(i+1));
    }

    return palavras;
}
