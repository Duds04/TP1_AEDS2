#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "./headers/include.h"
#include "./headers/leitura.h"


GtkBuilder *builder;
GtkWidget *window;
GtkStack *stack;

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




void on_butao_arquivos_clicked(GtkWidget *widget, gpointer data){
  //Receber os arquivos
  mensagem("Operacao concluida!!", "Os arquivos foram inceridos com sucesso! ", "emblem-default");
}

void on_botao_indice_clicked(GtkWidget *widget, gpointer data){
  //Constroi os indices invertidos. O que é?
  mensagem("Operacao concluida!!", "A construçao do indice invertida foi feita! ", "emblem-default");
}

void on_botao_printar_arvore_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_printar");
}

void on_botao_pesquisa_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_pesquisa");
}






int main (int argc, char **argv){

    gtk_init(&argc, &argv);
    // char caminho[20] = "./entradas/";
    // char arquivo[30];

    builder = gtk_builder_new_from_file("ui.glade");

    gtk_builder_add_callback_symbols(
        builder,
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


    gtk_builder_connect_signals(builder,NULL);


    stack =     GTK_WIDGET(gtk_builder_get_object(builder, "stack"));
    window =    GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gtk_widget_show_all(window);
    gtk_main();
    // TipoArvore Pat = NULL;


    // strcpy(arquivo, "listagemArquivos.txt");
    // strcat(caminho, arquivo);
    // leituraArquivo(caminho, &Pat);

    // MostraArvore(Pat);

    return 0;
}

// gcc ./headers/include.h	 ./headers/ocorrencias.h	 ./headers/patricia.h	 ./headers/leitura.h	 ./arquivoC/ocorrencias.c	 ./arquivoC/patricia.c ./arquivoC/palavra.c ./headers/palavra.h	./arquivoC/leitura.c   main.c	 -o	 exec
// 	./exec