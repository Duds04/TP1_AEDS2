#include "../headers/palavra.h"

//inicializa a lista de ocorrencias
void Inicializa_Palavra(TPalavra* pPalavra){

    FLOcorrencias_Vazia(&pPalavra->ocorrencias);

}

//Preenche o campo Palavra da estrutura TPalavra com o conteudo da string
void Preenche_Palavra(TPalavra* pPalavra, char *ppalavra){


	strcpy(pPalavra->Palavra, ppalavra);

}

//Retorna o conteúdo do campo Palavra
char* Retorna_Palavra(TPalavra* pPalavra){
	

	return pPalavra->Palavra;
	
}

void Imprime_Palavra(TPalavra* pPalavra){

	printf("---------------------\n");
	//Entra na estrutura e imprime o conteudo do campo Palavra
    printf("Palavra: %s\n", pPalavra->Palavra);

}

//Imprime a estrutura TPalavra chamando os subprogramas para imprimir cada campo
void Imprime_TPalavra(TPalavra* pPalavra){


	Imprime_Palavra(pPalavra);
	Imprimir_Ocorrencia(&(pPalavra->ocorrencias));

}

//Chama o subprograma Insere_Ocorrencia da estrutura LOcorrencias para inserir uma nova ocorrencia
void Insere_Ocorrencia_Palavra(TPalavra* pPalavra, int IdDoc){


    Insere_Ocorrencia(&pPalavra->ocorrencias, IdDoc);

}

//Retorna a quantidade de ocorrencias da palavra em um determinado documento
float Ocorrencias_Palavra(TPalavra* pPalavra, int IdDoc){
    if(Verifica_Ocorrencia(&pPalavra->ocorrencias, IdDoc) != 0){
        return Verifica_Ocorrencia(&pPalavra->ocorrencias, IdDoc)->qtde;
    }
    else{
        return 0;
    }
}
//Retorna a quantidade de documentos em que a palavra ocorre
float Qtde_Docs_Palavra(TPalavra* pPalavra){

    
	return Tamanho_LOcorrencia(&pPalavra->ocorrencias);
}

//Função para calcular quantas vezes a palavra aparece em cada documento
void Oc_Palavras_Docs(TPalavra* pPalavra, int *Documentos){
        
    //Apontador para celula para percorrer a lista
    POcorrencia pAux;
    //Começa apontando para a primeira celula após a celula cabeça
    pAux = pPalavra->ocorrencias.pPrimeiro->pProx;
    while(pAux != NULL){

        Documentos[pAux->IdDOc - 1] += pAux->qtde;
        pAux = pAux->pProx;

    }
}