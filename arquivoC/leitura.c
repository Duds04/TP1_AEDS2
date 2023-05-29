#include "../headers/leitura.h"


int leituraArquivo(char *pArquivo, TipoArvore* Pat)
{
    FILE *arquivo, *arquivoInterno;
    int idDoc = 0;
    char guardaArquivo[50], guardaPalavra[200]; // vetor auxiliar para guardar palavra
    char c;
    char caminho[70] = "./entradas/";

    if ((arquivo = fopen(pArquivo, "r")) != NULL)
    {   
        while (fscanf(arquivo, "%s", guardaArquivo) != EOF)
        {   
            
            if (idDoc != 0)
            {
                strcpy(caminho, "./entradas/");
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
                    fprintf(stderr, "Erro ao abrir o arquivo");
                    return 0;
                }

            }

            idDoc++;
        }
    }
    else
    {
        fprintf(stderr, "Erro ao abrir o arquivo");
        return 0;
    }

    fclose(arquivo);
    return 1;
}