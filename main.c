#include "./headers/include.h"
#include "./headers/leitura.h"



int main()
{
    char caminho[20] = "./entradas/";
    char arquivo[30];
    /*
    //teste função separa palavras
    char frase[100] = {"o rato roeu a roupa do rei de roma"};
    int n;
    char **palavras = separa_frase(frase, &n);
    for(int i = 0; i < 9; i++){
        printf("%s\n", palavras[i]);
    }
    ////////////////////////////////////////////////////////////
    */
    //TESTEPATRICIA
    // printf("Digite o nome do arquivo (com sua extensao .txt): \n");
    // scanf(" %s", arquivo);
    TipoArvore Pat = NULL;

    strcpy(arquivo, "listagemArquivos.txt");
    strcat(caminho, arquivo);
    leituraArquivo(caminho, &Pat);
    MostraArvore(Pat);
    ////////////////////////////////////////////////////////////

    //TESTE BUSCA

    char termos[250];
    // printf("Digite os termos de busca: \n");
    // scanf(" %[^\n]s", termos);
    strcpy(termos, "arthur e joao");
    Doc reldoc[14];

    Busca_textos(Pat, termos, 14, reldoc);
    printf("\nLista de Documentos:\n");
    for(int i = 0; i < 14; i++){
        printf("\nID: %d, Relevancia: %lf\n", reldoc[i].IDDoc, reldoc[i].relevancia);
    }
    
}
