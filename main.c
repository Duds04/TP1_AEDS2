#include "./headers/include.h"
#include "./headers/patricia.h"

int main(){
    TipoArvore Pat = NULL;
    char a[50] = "passaro", b[50] = "passaram", c[50] = "passar", d[50] = "doug", e[50] = "vasilha", f[50] = "lembrar", g[50] ="jogo", h[50] ="agora", i[50] ="mesmo", j[50] ="porque", k[50] ="eu", l[50] ="mandei";

    
    Pat = Insere(c, &Pat, 1);
    Pat = Insere(a, &Pat, 1);
    Pat = Insere(a, &Pat, 1);
    Pat = Insere(b, &Pat, 1);
    Pat = Insere(f, &Pat, 1);
    Pat = Insere(j, &Pat, 1);
    Pat = Insere(b, &Pat, 1);
    Pat = Insere(c, &Pat, 1);
    Pat = Insere(d, &Pat, 1);
    Pat = Insere(d, &Pat, 2);
    Pat = Insere(b, &Pat, 2);
    Pat = Insere(g, &Pat, 2);
    Pat = Insere(l, &Pat, 2);
    Pat = Insere(j, &Pat, 2);
    Pat = Insere(e, &Pat, 3);
    Pat = Insere(j, &Pat, 3);
    Pat = Insere(i, &Pat, 3);
    Pat = Insere(h, &Pat, 4);
    Pat = Insere(k, &Pat, 4);
    Pat = Insere(j, &Pat, 4);
    MostraArvore(Pat);
}
