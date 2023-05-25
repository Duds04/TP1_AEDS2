#include "../headers/ocorrencias.h"

void FLOcorrencias_Vazia(LOcorrencias* pLista){

	//Aloca espaço para a primeira celula da lista(celula cabeça) e define os Apontadores primeiro e ultimo

	pLista->pPrimeiro = (POcorrencia) malloc(sizeof(TipoOcorrencia));  
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;

}

void Insere_Ocorrencia(LOcorrencias* pLista, int IdDoc){
    //Verifica se a palavra ja apareceu antes nesse documento, se sim, incrementa a quantidade de ocorrencias

    if (Verifica_Ocorrencia(pLista, IdDoc) != 0){
        Verifica_Ocorrencia(pLista, IdDoc)->qtde++;
        return;
    }

	//Aloca espaço para para uma nova celula e preenche o campo IdDoc com o valor recebido como paramatro

    pLista->pUltimo->pProx = (POcorrencia)malloc(sizeof(TipoOcorrencia));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->qtde = 1;
    pLista->pUltimo->IdDOc = IdDoc;
    pLista->pUltimo->pProx = NULL;
    
}

void Imprimir_Ocorrencia(LOcorrencias* pLista){

	//Apontador para celula utilizado para percorrer a lista de posições
	POcorrencia pAux;
	//Começa apontando para a primeira celula após a celula cabeça
    pAux = pLista->pPrimeiro->pProx;
    printf("Ocorrencias: ");
	
    while(pAux != NULL) {
		
		//Imprime cada posição e avança para a proxima celula até chegar ao final da lista
        printf("<%d, %d> ", pAux->qtde, pAux->IdDOc );
        pAux = pAux->pProx;

    }
    printf("\n--------------------\n");
    printf("\n");

}

POcorrencia Verifica_Ocorrencia(LOcorrencias* pLista, int IdDoc){
	//Apontador para celula para percorrer a lista
	POcorrencia pAux;
	//Começa apontando para a primeira celula após a celula cabeça
	pAux = pLista->pPrimeiro->pProx;
	while(pAux != NULL){
		
		//Percorre toda a lista comparando os valores 

		if (pAux->IdDOc == IdDoc){
			
			//retorna o endereço da celula caso encontre o valor
			return pAux;
			
		}
		
		pAux = pAux->pProx;
		
	}
	
	return 0;
	
}

int Tamanho_LOcorrencia(LOcorrencias* pLista){
	
	//Apontador para celula para percorrer a lista
	POcorrencia pAux;
	//Começa apontando para a primeira celula após a celula cabeça
	pAux = pLista->pPrimeiro->pProx;
	int tamanho = 0;
	while(pAux != NULL){
		
		//Percorre toda a lista comparando os valores 
		tamanho++;
		pAux = pAux->pProx;
		
	}
	
	return tamanho;
	
}

