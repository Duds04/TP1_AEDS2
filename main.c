#include "./headers/leitura.h"

void Python(){
    system("python   entradas/leitura.py");
}

int main(){
    int quant;
    printf("Quantos arquivos vao ser inceridos?\n");
    scanf("%d", &quant);
    Python();
    return 0;
}
