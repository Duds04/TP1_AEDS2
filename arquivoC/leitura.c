// #include "leitura.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void python(){
    system("python3 ../entradas/leitura.py");
}

void EntrarArquivos(int quant){
    char Arquivo[20];
    char aux[3];
    for (int i = 1; i < (quant+1); i++){
        strcpy(Arquivo, "arquivo");
        // itoa(i, aux, 10);
        sprintf(aux, "%d", i);   
        strcat(Arquivo, aux);
        strcat(Arquivo, ".txt");
        printf("%s\n", Arquivo);
        // TratarArquivos(Arquivo);
    }
    
}

int main(){
    // python();
    int quant;
    printf("Quantos arquivos vao ser inceridos?\n");
    scanf("%d", &quant);
    EntrarArquivos(quant);
    return 0;
}

