from os import system
import re
import string


def TratarArquivos():
    txt = open("./entradas/listagemArquivos.txt", "r")
    N = txt.readline()
        
    for i in range(int(N)):

        Arquivo = txt.readline().replace("\n", "")
        
        nome = "./entradas/" + Arquivo 
        arquivo = open(nome, "r") 
        Larquivo = arquivo.read().replace("\n", " ")
        Larquivo = re.sub(r'\s+', " ", Larquivo).replace(" ", "\n").lower()
        arquivo.close()

        Larquivo = Larquivo.translate(dict.fromkeys(map(ord, string.punctuation)))

        arquivo = open(f"./entradas/{Arquivo}", "w")
        arquivo.writelines(Larquivo)
        arquivo.close()

    txt.close()


TratarArquivos()