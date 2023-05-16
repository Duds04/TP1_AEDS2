#include "./headers/include.h"
#include "./headers/leitura.h"



int main()
{
    char caminho[20] = "./entradas/";
    char arquivo[30];

    // printf("Digite o nome do arquivo (com sua extensao .txt): \n");
    // scanf(" %s", arquivo);
    TipoArvore Pat = NULL;


    strcpy(arquivo, "listagemArquivos.txt");
    strcat(caminho, arquivo);
    leituraArquivo(caminho, &Pat);

    MostraArvore(Pat);

}
