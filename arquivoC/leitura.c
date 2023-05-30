//ARTHUR ATAIDE DE MELO SARAIVA - 5070
//MARIA EDUARDA DE PINHO BRAGA - 5099 
//JOÃO GABRIEL ANGELO BRADACHI - 5078
//ESDRAS ARAUJO FERREIRA - 5102

#include "../headers/leitura.h"


int leituraArquivo(char *pArquivo, TipoArvore* Pat, int quant)
{
    FILE *arquivo, *arquivoInterno;
    int idDoc = 0;
    char guardaArquivo[50], guardaPalavra[200]; // vetor auxiliar para guardar palavra
    char c;
    char caminho[70] = "../entradas/";
    int i = 0;

    if ((arquivo = fopen(pArquivo, "r")) != NULL)
    { 
        while (fscanf(arquivo, "%s", guardaArquivo) != EOF )
        {
            if (idDoc != 0 && idDoc < quant+1)
            {
                strcpy(caminho, "../entradas/");
                strcat(caminho, guardaArquivo);
                if ((arquivoInterno = fopen(caminho, "r")) != NULL)
                {
                    while (fscanf(arquivoInterno, "%s", guardaPalavra) != EOF)
                    {
                        (*Pat) = Insere(guardaPalavra, Pat, idDoc);
                    }
                }
                else
                {   
                    return 0; //"Erro ao abrir o arquivo"
                }

            }

            idDoc++;
        }
        
    }
    else
    {
        return 0; //"Erro ao abrir o arquivo"
    }

    fclose(arquivo);
    return 1;
}
