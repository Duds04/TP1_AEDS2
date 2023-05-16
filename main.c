#include "./headers/include.h"
#include "./headers/leitura.h"
// #include "./headers/patricia.h"

int main()
{
    char caminho[20] = "./entradas/";
    char arquivo[30];

    // printf("Digite o nome do arquivo (com sua extensao .txt): \n");
    // scanf(" %s", arquivo);
    strcpy(arquivo, "listagemArquivos.txt");
    strcat(caminho, arquivo);
    leituraArquivo(caminho);
}
