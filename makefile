all:
	meson setup build
	clear
	cd build; \
	meson compile
	cd build; \
	./demo

code: 
	clear
	gcc ./headers/include.h	 ./headers/ocorrencias.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/ocorrencias.c	 ./arquivoC/patricia.c ./arquivoC/palavra.c ./headers/palavra.h	./arquivoC/leitura.c   main.c	 -o	 exec
	./exec

build:
	meson setup build

clean:
	rm -rf *.o ./exec
	clear
