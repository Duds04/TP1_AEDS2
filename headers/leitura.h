#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void python();
void TratarArquivos(char* Arquivo);
void EntrarArquivos(int quant);
void cleanFiles(){
    system("python3 files/filesManagement.py");
}
