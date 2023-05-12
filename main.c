#include "./headers/include.h"
#include "./headers/patricia.h"

int main(){
    TipoArvore Pat = NULL;
    char a[50] = "passaro", b[50] = "passaram", c[50] = "passar";

    Pat = Insere(a, &Pat, 1);
    Pat = Insere(a, &Pat, 1);
    Pat = Insere(b, &Pat, 1);
    Pat = Insere(b, &Pat, 1);
    Pat = Insere(b, &Pat, 1);
    Pat = Insere(c, &Pat, 1);

    MostraArvore(Pat);
}
