//ARTHUR ATAIDE DE MELO SARAIVA - 5070
//MARIA EDUARDA DE PINHO BRAGA - 5099 
//JOÃO GABRIEL ANGELO BRADACHI - 5078
//ESDRAS ARAUJO FERREIRA - 5102

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <glib.h>


#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_input() fflush(stdin)
#define limpar_tela() system("cls")
#define pausar_tela() system("pause")
#else
#include <stdio_ext.h>
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")
#define pausar_tela() printf("\nPress any key to continue..."); limpar_input(); getchar();
#endif
