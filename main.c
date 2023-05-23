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
    strcpy(termos, "case the problems single consists");
    Doc reldoc[14];
    printf("opa\n");
    Busca_textos(Pat, termos, 14, reldoc);
    printf("opa3\n");
    for(int i = 0; i < 14; i++){
        printf("relevancia doc %d: %.10f\n", reldoc[i].IDDoc + 1, reldoc[i].relevancia);
    }

}
