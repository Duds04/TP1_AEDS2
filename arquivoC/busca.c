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
    char palavras[50][50];
    separa_frase2(termos, &n_palavras, palavras);
    for(i = 0; i < N_Doc; i++){
        RelDocs[i].relevancia = Relevancia(t, palavras, n_palavras, i + 1, N_Doc, pal_por_doc[i]);
        RelDocs[i].IDDoc = i + 1;
    }
    return;

}

//Função que calcula a relevancia de um documento, parametros: arvore, vetor de termos, numero de termos, Id do documento, numero de documentos, numero de palavras no documento
double Relevancia(TipoArvore t, char palavras[50][50], int n_termos, int IDdoc, int N_Doc, int N_Palavras_doc){
    int i;
    double relevancia = 0;
    TipoArvore aux;
    for(i = 0; i < n_termos; i++){
        aux = Pesquisa(palavras[i], t);
        relevancia += Peso_termo(aux, IDdoc, N_Doc);
        relevancia = relevancia/N_Palavras_doc;
    }
    return relevancia;

}

//Função que calcula o peso de um termo em um documento, parametros: Nó da arvore que contém o termo, Id do documento, numero de documentos
double Peso_termo(TipoArvore t, int IDdoc, int N_Doc){

    double peso;

    peso = Ocorrencias_Palavra(&t->NO.tpalavra, IDdoc) * log10(N_Doc/Qtde_Docs_Palavra(&t->NO.tpalavra));
    return peso;

}

//Função que separa e conta as palavras de uma frase, parametros: frase, ponteiro para o numero de palavras
void separa_frase(char *frase, int* n_palavras, char **palavras){

    //Não funciona
    char *palavra = malloc(sizeof(char)*50);
    strcpy(palavra, strtok(frase, " "));
    int i = 0;
    *n_palavras = 0;
    while(palavra != NULL){

        strcpy(palavras[i], palavra);
        palavra = strtok(NULL, " ");
        i++;
        (*n_palavras)++;
        palavras = realloc(palavras, sizeof(char*)*(i+1));
    }
    free(palavra);
    for(i = 0; i < *n_palavras; i++){
        printf("sim%s\n", palavras[i]);
    printf("durante\n");
    }

    return;
}

//função para separar frase sem usar alocação dinamica feita pelo chat gpt
void separa_frase2(char* frase, int* n_palavras, char palavras[50][50]) {
    int i = 0;  // Índice da palavra atual
    int j = 0;  // Índice da letra atual na palavra
    *n_palavras = 0;  // Inicializa o contador de palavras

    // Percorre a frase caractere por caractere
    for (int k = 0; frase[k] != '\0'; k++) {
        if (frase[k] == ' ') {
            // Se encontrou um espaço em branco, finaliza a palavra atual
            palavras[i][j] = '\0';
            i++;  // Avança para a próxima palavra
            j = 0;  // Reinicia o índice da letra

            if (i >= 50) {
                // Limite máximo de palavras atingido, interrompe o loop
                break;
            }
        } else {
            // Adiciona o caractere à palavra atual
            palavras[i][j] = frase[k];
            j++;  // Avança para a próxima letra

            if (j >= 50) {
                // Limite máximo de caracteres por palavra atingido, interrompe o loop
                break;
            }
        }
    }

    // Finaliza a última palavra
    palavras[i][j] = '\0';
    *n_palavras = i + 1;  // Atualiza o número de palavras encontradas
}
