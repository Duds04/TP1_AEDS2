#include "./headers/leitura.h"

void Foi(){
    system("python   entradas/leitura.py");
}

int main(){
    int quant;
    printf("Quantos arquivos vao ser inceridos?\n");
    scanf("%d", &quant);
    Foi();
    return 0;
}
