all: 
	clear
	gcc ./headers/include.h	 ./headers/a.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/a.c	 ./arquivoC/patricia.c	./arquivoC/leitura.c   main.c	 -o	 exec
	./exec 
	
clean:
	rm -rf *.o ./exec
	clear
