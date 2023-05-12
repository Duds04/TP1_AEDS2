all: 
	clear
	gcc ./headers/include.h	 ./headers/ocorrencias.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/ocorrencias.c	 ./arquivoC/patricia.c ./arquivoC/palavra.c ./headers/palavra.h	./arquivoC/leitura.c   main.c	 -o	 exec
	./exec 
	
clean:
	rm -rf *.o ./exec
	clear
