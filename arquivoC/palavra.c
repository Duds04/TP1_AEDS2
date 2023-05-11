#include"../headers/palavra.h"


void Inicializa_Palavra(TPalavra* pPalavra){

	//inicializa a lista de ocorrencias
    FLOcorrencias_Vazia(&pPalavra->ocorrencias);

}

void Preenche_Palavra(TPalavra* pPalavra, char *ppalavra){

	//Preenche o campo Palavra da estrutura TPalavra com o conteudo da string

	strcpy(pPalavra->Palavra, ppalavra);

}

char* Retorna_Palavra(TPalavra* pPalavra){
	
	//Retorna o conteúdo do campo Palavra

	return pPalavra->Palavra;
	
}

void Imprime_Palavra(TPalavra* pPalavra){

	printf("---------------------\n");
	//Entra na estrutura e imprime o conteudo do campo Palavra
    printf("Palavra: %s\n", pPalavra->Palavra);

}

void Imprime_TPalavra(TPalavra* pPalavra){

	//Imprime a estrutura TPalavra chamando os subprogramas para imprimir cada campo

	Imprime_Palavra(pPalavra);
	Imprimir_Ocorrencia(&pPalavra->ocorrencias);

}

void Insere_Ocorrencia_Palavra(TPalavra* pPalavra, int IdDoc){

    //Chama o subprograma Insere_Ocorrencia da estrutura LOcorrencias para inserir uma nova ocorrencia

    Insere_Ocorrencia(&pPalavra->ocorrencias, IdDoc);

}