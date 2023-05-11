all: 
	clear
	gcc ./headers/Linhas.h	 ./headers/Palavra.h	 ./headers/ListaPalavras.h	 ./headers/Dicionario.h	 ./headers/Ordenacoes.h	 Linhas.c	 Palavra.c	 ListaPalavras.c   Ordenacoes.c	 Dicionario.c   main.c	 -o	 exec
	./exec 
clean:
	rm -rf *.o ./exec
	clear
