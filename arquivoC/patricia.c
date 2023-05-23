#include "../headers/patricia.h"

TipoDib Bit(TipoIndexAmp i, char k[50]){
// Retorna o i-ésimo bit da chave k a partir da esquerda
    return k[i];
}
short EExterno (TipoArvore p){
    // verifica se p é nó externo
    return (p->nt == Externo);
}

/*Função que cria nó interno, parametros: posição do vetor em que há a diferença, arvore que ficará à esquerda, 
arvore que ficará à direita, letra que se difere da palavra que está na arvore*/
TipoArvore CriaNoInt(int i, TipoArvore* Esq, TipoArvore* Dir, char letra){
    TipoArvore p;

    p = (TipoArvore) malloc(sizeof(TipoPatNo));

    p->nt = Interno;
    p->NO.NoInterno.Esq = *Esq;
    p->NO.NoInterno.Dir = *Dir;
    p->NO.NoInterno.Index = i;
    p->NO.NoInterno.letra = letra;

    return p;
}
// Função que cria nó externo, parametros: palavra_a_ser_inserida, Id do documento.
TipoArvore CriaNoExt(char k[50], int IdDoc){
    TipoArvore p;
    TPalavra palavra;

    //Prepara o tad palavra
    Inicializa_Palavra(&palavra);
    Preenche_Palavra(&palavra, k);

    p = (TipoArvore)malloc(sizeof(TipoPatNo));

    p->nt = Externo;
    p->NO.tpalavra = palavra;

    // Insere a primeira ocorrencia
    Insere_Ocorrencia_Palavra(&(p->NO.tpalavra), IdDoc);

    return p;

}

TipoArvore Pesquisa (char k[50], TipoArvore t){
    if(EExterno(t)){
        if(!(strcmp(k, t->NO.tpalavra.Palavra))){
            return t;
        }
        else{
            printf("Elemento não encontrado\n");
        }
        return NULL;
    }
    if(Bit(t->NO.NoInterno.Index, k) > t->NO.NoInterno.letra){
        Pesquisa(k, t->NO.NoInterno.Dir);
    }else{
        Pesquisa(k, t->NO.NoInterno.Esq);
    }
}

// Função que insere entre os nós, parametros: palavra a ser inserida, arvore, posição do vetor em que há a diferença, Id do documento, letra que se difere da palavra que está na arvore
TipoArvore InsereEntre(char k[50], TipoArvore* t, int i, int IdDoc, char LetraDif){
    TipoArvore p;

    // Se a arvore for um nó externo (primeiro nó), ou se o i for menor que o index do nó interno da arvore;
    if (EExterno(*t) || i < (*t)->NO.NoInterno.Index){

        //Cria novo nó externo
        p = CriaNoExt(k, IdDoc);

        // Se a posião i da palavra for maior
        if(Bit(i, k) > LetraDif){

            /* Se o caractere i da palavra inserida for maior: cria nó interno que guarda i, 
            LetraDif (menor letra entre as posiçoes das palavras comparadas), 
            palavra inserida na direita, arvore restante para esquerda (menor ou igual para a esquerda)*/
            return CriaNoInt(i, t, &p, LetraDif);
        }else{

            /* Se o caractere i da palavra inserida for menor: cria nó interno que guarda i, 
            o caractere i pa palavra (menor letra entre as posiçoes das palavras comparadas), 
            palavra inserida na esquerda, arvore restante para direita (menor ou igual para a esquerda)*/
            return CriaNoInt(i, &p, t, Bit(i, k));
        }
    }else{
        // Procura o lugar para criar o nó
        if(Bit((*t)->NO.NoInterno.Index, k) > (*t)->NO.NoInterno.letra){
            (*t)->NO.NoInterno.Dir = InsereEntre(k, &(*t)->NO.NoInterno.Dir, i, IdDoc, LetraDif);
        }else{
            (*t)->NO.NoInterno.Esq = InsereEntre(k, &(*t)->NO.NoInterno.Esq, i, IdDoc, LetraDif);
        }
        return (*t);
    }
}

// Função para inserir palavras em uma arvore já preenchida com nós ou com NULL, parametros: palavra a ser inserida, arvore, Id do documento.
TipoArvore Insere(char k[50], TipoArvore* t, int IdDoc){
    TipoArvore p;
    int i;
    // Verifica se a arvore é nula
    if(*t == NULL){
        // se for: cria nó externo
        return CriaNoExt(k, IdDoc);
    }
    else{
        // Se não for: procura pelo nó externo semelhante
        p = *t;
        while(!EExterno(p)){
            if(p->NO.NoInterno.Index < strlen(k)){
                // Caso o tamanho da palavra seja maior ou igual, percorre normalmente
                if(Bit(p->NO.NoInterno.Index, k) > p->NO.NoInterno.letra){
                    p = p->NO.NoInterno.Dir;
                }
                else{
                    p = p->NO.NoInterno.Esq;
                }
            }
            else{
                // Caso o tamanho da palavra seja menor, pegar o mais a esquerda
                p = p->NO.NoInterno.Esq;
            }
        }
        // Encontra o primeiro bit diferente
        i = 0;
        while ((i<=strlen(k))& (Bit((int)i, k) == Bit((int)i, p->NO.tpalavra.Palavra))){
            i++;
        }
        // Se palavra existir, então adiciona ocorrencia da mesma de acordo com o IdDoc
        if (!(strcmp(k, p->NO.tpalavra.Palavra))){
            Insere_Ocorrencia_Palavra(&(p->NO.tpalavra), IdDoc);
            return *t;
        }
        // Se a palavra não existir terá que ser inserida entre nós
        else{
            return (InsereEntre(k, t, i, IdDoc, p->NO.tpalavra.Palavra[i]));
        }
    }
}

void MostraArvore(TipoArvore t){
    if(t == NULL){
        return;
    }
    else if(EExterno(t)){
        Imprime_TPalavra(&(t->NO.tpalavra));
        return;
    }
    else{
    MostraArvore(t->NO.NoInterno.Esq);
    MostraArvore(t->NO.NoInterno.Dir);
    return;
    }
}

//EM DESENVOLVIMENTO

//calcula o numero de palavras por documento
void Pal_por_Doc(TipoArvore t, int* Documentos){

    if(t == NULL){
        return;
    }
    else if(EExterno(t)){
        Oc_Palavras_Docs(&t->NO.tpalavra, Documentos);
        return;
    }
    else{
        Pal_por_Doc(t->NO.NoInterno.Esq, Documentos);
        Pal_por_Doc(t->NO.NoInterno.Dir, Documentos);
    }
    return;
}


//Função que calcula a relevancia dos documentos, parametros: arvore, vetor de termos, numero de termos, Id do documento, numero de documentos
void Busca_textos(TipoArvore t, char termos[250], int N_Doc, int* vetor_de_relevancia){
    
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
    int doc = 0;
    for(i = 0; i < (10*2); i = i + 2){
    printf("//////////////////////////////////////////////////////////////////\n");
        doc++;
        vetor_de_relevancia[i] = Relevancia(t, palavras, n_palavras, doc, N_Doc, pal_por_doc[doc-1]);
        printf("abom\n");
        vetor_de_relevancia[i+1] = doc;
        printf("%d\n", vetor_de_relevancia[i+1]);
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
