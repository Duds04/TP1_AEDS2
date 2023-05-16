#include "./headers/include.h"
#include "./headers/patricia.h"

int main(){

     while (1)
    {   
        int entrada = -1;
        char letra;
        char palavra[100];
        TPalavra Palavra;
        TListaDePalavras* pLista;
        char arquivo[30];
        char caminho[20] = "./entradas/";

        system("cls");

        // Menu dá acessoa a funcionalidades que não são usadas dentro das funções
        printf("\n\nMENU\nOBS: Digite os valores numeros das respectivas operacoe\n");
        printf("Escreva a operacao que deseja realizar:\n");
        printf("1 - Escrever o nome do arquivo de entrada\n");
        printf("2 - Sair do programa\n");
        printf("\n");
        fflush(stdin);
        scanf(" %d", &entrada);
        printf("\n");

        switch (entrada)
        {
        case 1:
            // arquivo de entrada tem que estar na pasta entradas do programa
            printf("Digite o nome do arquivo (com sua extensao .txt): \n");
            scanf(" %s", arquivo);
            strcat(caminho, arquivo);
            ConstroiDicionario(ptrDicionario, caminho);
            break;

        case 2:
            return 0;
            break;

        default:
            printf("Entrada invalida! \n");
            break;
        }

        system("pause");
    }

    // TipoArvore Pat = NULL;
    // char a[50] = "passaro", b[50] = "passaram", c[50] = "passar", d[50] = "doug", e[50] = "vasilha", f[50] = "lembrar", g[50] ="jogo", h[50] ="agora", i[50] ="mesmo", j[50] ="porque", k[50] ="eu", l[50] ="mandei";

    
    // Pat = Insere(c, &Pat, 1);
    // Pat = Insere(a, &Pat, 1);
    // Pat = Insere(a, &Pat, 1);
    // Pat = Insere(b, &Pat, 1);
    // Pat = Insere(f, &Pat, 1);
    // Pat = Insere(j, &Pat, 1);
    // Pat = Insere(b, &Pat, 1);
    // Pat = Insere(c, &Pat, 1);
    // Pat = Insere(d, &Pat, 1);
    // Pat = Insere(d, &Pat, 2);
    // Pat = Insere(b, &Pat, 2);
    // Pat = Insere(g, &Pat, 2);
    // Pat = Insere(l, &Pat, 2);
    // Pat = Insere(j, &Pat, 2);
    // Pat = Insere(e, &Pat, 3);
    // Pat = Insere(j, &Pat, 3);
    // Pat = Insere(i, &Pat, 3);
    // Pat = Insere(h, &Pat, 4);
    // Pat = Insere(k, &Pat, 4);
    // Pat = Insere(j, &Pat, 4);
    MostraArvore(Pat);
}
