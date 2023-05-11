from os import system
import re
import platform
import string

def TratarArquivo(Arquivo):
    nome = "./entradas/" + Arquivo

    arquivo = open(nome, "r") 
    Larquivo = arquivo.read().replace("\n", " ")
    Larquivo = re.sub(r'\s+', " ", Larquivo).replace(" ", "\n")
    arquivo.close()

    Larquivo = Larquivo.translate(dict.fromkeys(map(ord, string.punctuation)))

    arquivo = open(nome, "w")
    arquivo.writelines(Larquivo)
    arquivo.close()

TratarArquivo("oi.txt")