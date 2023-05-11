#include "../headers/ocorrencias.h"

void FLOcorrencias_Vazia(LOcorrencias* pLista){

	//Aloca espaço para a primeira celula da lista(celula cabeça) e define os Apontadores primeiro e ultimo

	pLista->pPrimeiro = (POcorrencia) malloc(sizeof(TipoOcorrencia));  
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;

}

void Insere_Ocorrencia(LOcorrencias* pLista, int IdDoc){

	//Aloca espaço para para uma nova celula e preenche o campo posição com o valor recebido como paramatro

    pLista->pUltimo->pProx = (POcorrencia)malloc(sizeof(TipoOcorrencia));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->IdDOc = IdDoc;
    pLista->pUltimo->pProx = NULL;
    
}

void Imprimir_Posicao(LOcorrencias* pLista){

	//Apontador para celula utilizado para percorrer a lista de posições
	POcorrencia pAux;
	//Começa apontando para a primeira celula após a celula cabeça
    pAux = pLista->pPrimeiro->pProx;
    printf("Linhas: ");
	
    while(pAux != NULL) {
		
		//Imprime cada posição e avança para a proxima celula até chegar ao final da lista
        printf("[%d] ", pAux->posicao);
        pAux = pAux->pProx;

    }
    printf("\n--------------------\n");
    printf("\n");

}

int Verifica_Posicao(LOcorrencias* pLista, int IdDoc){
	
	//Apontador para celula para percorrer a lista
	POcorrencia pAux;
	//Começa apontando para a primeira celula após a celula cabeça
	pAux = pLista->pPrimeiro->pProx;
	while(pAux != NULL){
		
		//Percorre toda a lista comparando os valores 

		if (pAux->IdDOc == IdDoc){
			
			//retorna 1 caso a palavra ja tenha aparecido nesse documento
			return 1;
			
		}
		
		pAux = pAux->pProx;
		
	}
	
	return 0;
	
}


