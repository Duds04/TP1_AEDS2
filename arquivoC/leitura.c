#include "../headers/leitura.h"

void python(){
    system("python3   ../entradas/leitura.py");
}

void EntrarArquivos(int quant){
    python();
    char Arquivo[20];
    char aux[3];
    for (int i = 1; i < (quant+1); i++){
        strcpy(Arquivo, "arquivo");
        // itoa(i, aux, 10);
        sprintf(aux, "%d", i);   
        strcat(Arquivo, aux);
        strcat(Arquivo, ".txt");
        printf("%s\n", Arquivo);

        TratarArquivos("arquivo1.txt");
    }
    
}



