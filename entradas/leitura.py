from os import system
import re
import platform

def TratarArquivo(Arquivo):
    arquivo = open(Arquivo, "r") 
    arquivo = arquivo.readlines()

    arquivo.close()

    arquivo = open(Arquivo, 'w')
    arquivo.writelines(saidas)
    arquivo.close()
    return arquivo