#include "../headers/patricia.h"

TipoDib Bit(TipoIndexAmp i, char k[50]){
// Retorna o i-ésimo bit da chave k a partir da esquerda
    return k[i];
}
short EExterno (TipoArvore p){
    // verifica se p é nó externo
    return (p->nt == Externo);
}

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

TipoArvore CriaNoExt(char k[50], int IdDoc){
    TipoArvore p;
    TPalavra palavra;
    Inicializa_Palavra(&palavra);
    Preenche_Palavra(&palavra, k);
    p = (TipoArvore)malloc(sizeof(TipoPatNo));

    p->nt = Externo;
    p->NO.tpalavra = palavra;

    return p;

}

void Pesquisa (char k[50], TipoArvore t){
    if(EExterno(t)){
        if(!(strcmp(k, t->NO.tpalavra.Palavra))){
        printf("Elemento encontrado\n");
        printf("%s, %d\n", t->NO.tpalavra.Palavra, t->NO.tpalavra.ocorrencias.pPrimeiro);
        }
        else{
            printf("Elemento não encontrado\n");
        }
        return;
    }
    if(Bit(t->NO.NoInterno.Index, k) > t->NO.NoInterno.letra){
        Pesquisa(k, t->NO.NoInterno.Dir);
    }else{
        Pesquisa(k, t->NO.NoInterno.Esq);
    }
}

TipoArvore InsereEntre(char k[50], TipoArvore* t, int i, int IdDoc){
    TipoArvore p;
    if (EExterno(*t) || i < (*t)->NO.NoInterno.Index){
        //Cria novo nó externo
        p = CriaNoExt(k, IdDoc);
        if(Bit(i, k) > (*t)->NO.NoInterno.letra){
            return CriaNoInt(i, t, &p, Bit(i, k));
        }else{
            return CriaNoInt(i, &p, t, Bit(i, k));
        }
    }else{
        if(Bit((*t)->NO.NoInterno.Index, k) > (*t)->NO.NoInterno.letra){
            (*t)->NO.NoInterno.Dir = InsereEntre(k, &(*t)->NO.NoInterno.Dir, i, IdDoc);
        }else{
            (*t)->NO.NoInterno.Esq = InsereEntre(k, &(*t)->NO.NoInterno.Esq, i, IdDoc);
        }
        return (*t);
    }
}

TipoArvore Insere(char k[50], TipoArvore* t, int IdDoc){
    TipoArvore p;
    int i;
    if(*t == NULL){
        return CriaNoExt(k, IdDoc);
    }
    else{
        p = *t;
        while(!EExterno(p)){
            if(Bit(p->NO.NoInterno.Index, k) > p->NO.NoInterno.letra){
                p = p->NO.NoInterno.Dir;
            }
            else{
                p = p->NO.NoInterno.Esq;
            }
        }
        // Encontra o primeiro bit diferente
        i = 0;
        while ((i<strlen(k))& (Bit((int)i, k) == Bit((int)i, p->NO.tpalavra.Palavra))){
            i++;
        }
        if (!(strcmp(k, p->NO.tpalavra.Palavra))){
            // se tiver palavra, então adicionar ocorrencia
            Insere_Ocorrencia_Palavra(&(p->NO.tpalavra), IdDoc);
            return *t;
        }
        else{
            return (InsereEntre(k, t, i, IdDoc));
        }
    }
}

void MostraArvore(TipoArvore t){
    if(EExterno(t)){
        printf("%s, %d\n", t->NO.tpalavra.Palavra, t->NO.tpalavra.ocorrencias.pPrimeiro);
        return;
    }
    MostraArvore(t->NO.NoInterno.Esq);
    MostraArvore(t->NO.NoInterno.Dir);
}
