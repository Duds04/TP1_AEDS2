from os import system
import re
import string
import nltk
from nltk.corpus import stopwords



def TratarArquivos():
    nltk.download('stopwords')
    nltk.download('punkt')
    
    stop = ['im', 'i', 'me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', 'youre', 'youve', 'youll', 'youd', 'your', 'yours', 'yourself', 'yourselves', 'he', 'him', 'his', 'himself', 'she', 'shes', 'her', 'hers', 'herself', 'it', 'its', 'its', 'itself', 'they', 'them', 'their', 'theirs', 'themselves', 'what', 'which', 'who', 'whom', 'this', 'that', 'thatll', 'these', 'those', 'am', 'is', 'are', 'was', 'were', 'be', 'been', 'being', 'have', 'has', 'had', 'having', 'do', 'does', 'did', 'doing', 'a', 'an', 'the', 'and', 'but', 'if', 'or', 'because', 'as', 'until', 'while', 'of', 'at', 'by', 'for', 'with', 'about', 'against', 'between', 'into', 'through', 'during', 'before', 'after', 'above', 'below', 'to', 'from', 'up', 'down', 'in', 'out', 'on', 'off', 'over', 'under', 'again', 'further', 'then', 'once', 'here', 'there', 'when', 'where', 'why', 'how', 'all', 'any', 'both', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'not', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'dont', 'should', 'shouldve', 'now', 'd', 'll', 'm', 'o', 're', 've', 'y', 'ain', 'aren', 'arent', 'couldn', 'couldnt', 'didn', 'didnt', 'doesn', 'doesnt', 'hadn', 'hadnt', 'hasn', 'hasnt', 'haven', 'havent', 'isn', 'isnt', 'ma', 'mightn', 'mightnt', 'mustn', 'mustnt', 'needn', 'neednt', 'shan', 'shant', 'shouldn', 'shouldnt', 'wasn', 'wasnt', 'weren', 'werent', 'won', 'wont', 'wouldn', 'wouldnt']
    
    txt = open("./entradas/listagemArquivos.txt", "r")
    N = txt.readline()
        
    for i in range(int(N)):

        Arquivo = txt.readline().replace("\n", "")
        
        nome = "./entradas/" + Arquivo 
        arquivo = open(nome, "r") 
        Larquivo = arquivo.read().replace("\n", " ")
        Larquivo = re.sub(r'\s+', " ", Larquivo).lower()
        arquivo.close()
        
        for i in range(10):
            Larquivo = (''.join(Larquivo)).replace(f"{i}", "") 
        Larquivo = (Larquivo.translate(dict.fromkeys(map(ord, string.punctuation))))
        
        Larquivo = nltk.sent_tokenize(Larquivo)
        
        for i in range(len(Larquivo)):
            words = nltk.word_tokenize(Larquivo[i])
            newwords = [word for word in words if word not in stop]
            Larquivo[i] = ' '.join(newwords)
            
        Larquivo = (''.join(Larquivo)).replace(" ", "\n")   
            
        arquivo = open(f"./entradas/{Arquivo}", "w")
        arquivo.writelines(Larquivo)
        arquivo.close()

    txt.close()


TratarArquivos()