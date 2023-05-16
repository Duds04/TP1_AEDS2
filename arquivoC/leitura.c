#include "../headers/leitura.h"

int leituraArquivo
{
    FILE *arquivo;
    int idDoc = 1;
    int x = 1;
    char guardaPalavra[200]; // vetor auxiliar para guardar palavra

    TipoArvore Pat = NULL;

    pCelulaDicionario pAux;
    pAux = pDicionario->pPrimeiro->pProx;

    if ((arquivo = fopen(pTexto, "r")) != NULL)
    {
        while (fscanf(arquivo, "%s%c", guardaPalavra, &c) != EOF)
        {
            Pat = Insere(guardaPalavra, &Pat, idDoc);
            if (c == '\n')
            {
                x++;
            }
        }
        else
        {
            fprintf(stderr, "Erro ao abrir o arquivo");
            return 0;
        }

        fclose(arquivo);
    }