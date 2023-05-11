all: 
	clear
	gcc ./headers/include.h	 ./headers/a.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/a.c	 Linhas.c	 Palavra.c	 ListaPalavras.c   Ordenacoes.c	 Dicionario.c   main.c	 -o	 exec
	./exec 
clean:
	rm -rf *.o ./exec
	clear
