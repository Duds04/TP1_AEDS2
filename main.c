#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "./headers/leitura.h"



typedef struct Dados{
    TipoArvore Pat;
    char palavra[];


}TDados;



typedef struct Janelas{
    GtkBuilder *builder;
    GtkWidget *window;
    GtkStack *stack;
    TDados* interno;

}TJanelas;


void on_main_window_destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void mensagem(char text[100], char secondary_text[200], char icon_name[100]){

    GtkMessageDialog *mensagem_dialogo = gtk_builder_get_object(builder, "mensagem");

    g_object_set(mensagem_dialogo, "text", text, NULL);
    g_object_set(mensagem_dialogo, "secondary_text", secondary_text, NULL);
    g_object_set(mensagem_dialogo, "icon_name", icon_name, NULL);

    gtk_widget_show_all(mensagem_dialogo);
    gtk_dialog_run     (mensagem_dialogo);
    gtk_widget_hide    (mensagem_dialogo);
}

void on_botao_inicio_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_opcao");
}

void on_botao_sair_inicio_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}
void on_botao_sair_opcao_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_ajuda");
}
void on_botao_voltar_pesquisa_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_opcao");
}
void on_botao_voltar_printar_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_opcao");
}
void on_botao_voltar_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_opcao");
}

void on_botao_voltar_ajuda_ajuda1_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_ajuda");
}
void on_botao_voltar_ajuda_ajuda2_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_ajuda");
}
void on_botao_voltar_ajuda_ajuda3_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_ajuda");
}
void on_botao_voltar_ajuda_ajuda4_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_ajuda");
}

void on_botao_arquivos_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "ajuda_arquivos");
}
void on_botao_indice_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "ajuda_index");
}
void on_botao_pesquisa_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "ajuda_pesquisa");
}
void on_botao_printar_arvore_ajuda_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "ajuda_printar");
}




void on_butao_arquivos_clicked(GtkWidget *widget, gpointer data, TipoArvore Pat){
    char caminho[20] = "./entradas/";
    char arquivo[30];
    

    strcpy(arquivo, "listagemArquivos.txt");
    strcat(caminho, arquivo);

    leituraArquivo(caminho, &Pat);

    mensagem("Operacao concluida!!", "Os arquivos foram inceridos com sucesso! ", "emblem-default");
}

void on_botao_indice_clicked(GtkWidget *widget, gpointer data){
  //Constroi os indices invertidos. O que é?
    mensagem("Operacao concluida!!", "A construçao do indice invertida foi feita! ", "emblem-default");
}

void on_botao_printar_arvore_clicked(GtkWidget *widget, gpointer data){

    gtk_stack_set_visible_child_name(stack, "view_printar");
    MostraArvore(Pat);
}

void on_botao_pesquisa_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_pesquisa");
}






int main (int argc, char **argv){

   
    // fprintf(stderr, caminho);
    
    TJanelas janelas;

    janelas.interno->Pat = NULL;

    gtk_init(&argc, &argv);
    

    janelas.builder = gtk_builder_new_from_file("ui.glade");

    gtk_builder_add_callback_symbols(
        janelas.builder,
        "on_botao_inicio_clicked",                        G_CALLBACK(on_botao_inicio_clicked),
        "on_main_window_destroy",                         G_CALLBACK(on_main_window_destroy),
        "on_botao_sair_inicio_clicked",                   G_CALLBACK(on_botao_sair_inicio_clicked),
        "on_butao_arquivos_clicked",                      G_CALLBACK(on_butao_arquivos_clicked),
        "on_botao_indice_clicked",                        G_CALLBACK(on_botao_indice_clicked),
        "on_botao_printar_arvore_clicked",                G_CALLBACK(on_botao_printar_arvore_clicked),
        "on_botao_pesquisa_clicked",                      G_CALLBACK(on_botao_pesquisa_clicked),
        "on_botao_sair_opcao_clicked",                    G_CALLBACK(on_botao_sair_opcao_clicked),
        "on_botao_voltar_pesquisa_clicked",               G_CALLBACK(on_botao_voltar_pesquisa_clicked),
        "on_botao_voltar_printar_clicked",                G_CALLBACK(on_botao_voltar_printar_clicked),
        "on_botao_voltar_ajuda_clicked",                  G_CALLBACK(on_botao_voltar_ajuda_clicked),
        "on_botao_ajuda_clicked",                         G_CALLBACK(on_botao_ajuda_clicked),
        "on_botao_voltar_ajuda_ajuda1_clicked",           G_CALLBACK(on_botao_voltar_ajuda_ajuda1_clicked),
        "on_botao_voltar_ajuda_ajuda2_clicked",           G_CALLBACK(on_botao_voltar_ajuda_ajuda2_clicked),
        "on_botao_voltar_ajuda_ajuda3_clicked",           G_CALLBACK(on_botao_voltar_ajuda_ajuda3_clicked),
        "on_botao_voltar_ajuda_ajuda4_clicked",           G_CALLBACK(on_botao_voltar_ajuda_ajuda4_clicked),
        "on_botao_ajuda_clicked",                         G_CALLBACK(on_botao_voltar_ajuda_ajuda2_clicked),
        "on_botao_arquivos_ajuda_clicked",                G_CALLBACK(on_botao_arquivos_ajuda_clicked),
        "on_botao_indice_ajuda_clicked",                  G_CALLBACK(on_botao_indice_ajuda_clicked),
        "on_botao_pesquisa_ajuda_clicked",                G_CALLBACK(on_botao_pesquisa_ajuda_clicked),
        "on_botao_printar_arvore_ajuda_clicked",          G_CALLBACK(on_botao_printar_arvore_ajuda_clicked),
        "on_botao_ajuda_clicked",                         G_CALLBACK(on_botao_ajuda_clicked),

    NULL);


    gtk_builder_connect_signals(janelas.builder,NULL);


    janelas.stack =     GTK_WIDGET(gtk_builder_get_object(janelas.builder, "stack"));
    janelas.window =    GTK_WIDGET(gtk_builder_get_object(janelas.builder, "main_window"));

    gtk_widget_show_all(janelas.window);
    gtk_main();
    // TipoArvore Pat = NULL;


    // strcpy(arquivo, "listagemArquivos.txt");
    // strcat(caminho, arquivo);
    // leituraArquivo(caminho, &Pat);

    // MostraArvore(Pat);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


// #include "./headers/leitura.h"
// int main()
// {
//     char caminho[20] = "./entradas/";
//     char arquivo[30];
//     /*
//     //teste função separa palavras
//     char frase[100] = {"o rato roeu a roupa do rei de roma"};
//     int n;
//     char **palavras = separa_frase(frase, &n);
//     for(int i = 0; i < 9; i++){
//         printf("%s\n", palavras[i]);
//     }
//     ////////////////////////////////////////////////////////////
//     */
//     //TESTEPATRICIA
//     // printf("Digite o nome do arquivo (com sua extensao .txt): \n");
//     // scanf(" %s", arquivo);
//     TipoArvore Pat = NULL;

//     strcpy(arquivo, "listagemArquivos.txt");
//     strcat(caminho, arquivo);
//     leituraArquivo(caminho, &Pat);
//     MostraArvore(Pat);
//     ////////////////////////////////////////////////////////////

//     //TESTE BUSCA

//     char termos[250];
//     // printf("Digite os termos de busca: \n");
//     // scanf(" %[^\n]s", termos);
//     strcpy(termos, "the travelling problems technologies include nanomagnetic and quantum");
//     Doc reldoc[14];

//     Busca_textos(Pat, termos, 14, reldoc);

//     for(int i = 0; i < 14; i++){
//         printf("\nID: %d, Relevancia: %lf\n", reldoc[i].IDDoc, reldoc[i].relevancia);
//     }
// }

// gcc ./headers/include.h	 ./headers/ocorrencias.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/ocorrencias.c	 ./arquivoC/patricia.c ./arquivoC/palavra.c ./headers/palavra.h	./arquivoC/leitura.c   main.c	 -o	 exec
// 	./exec