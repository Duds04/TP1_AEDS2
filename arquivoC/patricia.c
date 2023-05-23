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


