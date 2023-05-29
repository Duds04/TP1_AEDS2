#include "./headers/leitura.h"


GtkBuilder *builder;
GtkWidget *window;
GtkStack *stack;
GtkListStore *armazenameto_relevancia;
GtkListStore *armazenamento_todos;
TipoArvore Pat;
int QuantAquivo = 0;


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



void on_botao_sair_inicio_clicked(GtkWidget *widget, gpointer data){
  gtk_main_quit();
}
void on_botao_sair_opcao_clicked(GtkWidget *widget, gpointer data){
  gtk_main_quit();
}

void on_botao_inicio_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_opcao");
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
void on_botao_voltar_mandar_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_opcao");
}
void on_botao_voltar_relevancia_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_opcao");
}

void on_botao_ajuda_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_ajuda");
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
void on_botao_pesquisa_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_pesquisa");
}
void on_butao_arquivos_clicked(GtkWidget *widget, gpointer data){
  gtk_stack_set_visible_child_name(stack, "view_arquivo");
}

void on_botao_mandar_clicked(GtkWidget *widget, gpointer data){
  char* aux = gtk_entry_get_text(gtk_builder_get_object(builder, "Quantidade"));    
  QuantAquivo = atoi(aux);

  if (QuantAquivo >= 1 && QuantAquivo <= 14)
    mensagem("Operacao concluida!!", "Recebemos os Arquivos", "emblem-default");
  else 
    mensagem("Operacao falhou", "Os arquivos nao foram recebidos ", "emblem-default");
}

void on_botao_indice_clicked(GtkWidget *widget, gpointer data){
  int erro;
  char caminho[20] = "../entradas/";
  char arquivo[30];
  Pat = NULL;

  strcpy(arquivo, "listagemArquivos.txt");
  strcat(caminho, arquivo);

  erro = leituraArquivo(caminho,&Pat, QuantAquivo);
  if (erro)
    mensagem("Operacao concluida!!", "A construçao do indice invertida foi feita! ", "emblem-default");
  else
    mensagem("Operacao falhou", "Nao foi possivel fazer o indice invertido ", "emblem-default");
}

void Imprimir_OcorrenciaGTK(LOcorrencias* pLista, GtkTreeIter iter, char* palavra){
	POcorrencia pAux;
  char index[140] = "";

  pAux = pLista->pPrimeiro->pProx;
	
  while(pAux != NULL) {

      sprintf(index, "%s<%d, %d> ", index, pAux->qtde, pAux->IdDOc );
      pAux = pAux->pProx;
      
  }

  gtk_list_store_append(armazenamento_todos, &iter);
  gtk_list_store_set(armazenamento_todos, &iter,
  0, palavra,
  1, index,
  -1);
}

void MostraArvoreGTK(TipoArvore t){
    GtkTreeIter iter;
    if(t == NULL){
        return;
    }
    else if(EExterno(t)){
        char *palavra = t->NO.tpalavra.Palavra;
        Imprimir_OcorrenciaGTK(&(t->NO.tpalavra.ocorrencias), iter, palavra);
        return;
    }
    else{
    MostraArvoreGTK(t->NO.NoInterno.Esq);
    MostraArvoreGTK(t->NO.NoInterno.Dir);
    return;
    }
}

void on_botao_printar_arvore_clicked(GtkWidget *widget, gpointer data){

  MostraArvoreGTK(Pat);
  
  gtk_stack_set_visible_child_name(stack, "view_tree");
}



void Imprime_Relevancia(Doc RelDocs[], int N_Doc){
  int i;
  GtkTreeIter iter;
  gtk_list_store_clear(armazenameto_relevancia);
  char aux[15];

    for(i = 0; i < QuantAquivo; i++){
        if(RelDocs[i].relevancia != 0){

          sprintf(aux, "arquivo%d.txt", RelDocs[i].IDDoc);
          // aux "(arquivo";
          // strcat(aux, RelDocs[i].IDDoc + '0');
          // strcat(aux, ".txt");

          gtk_list_store_append(armazenameto_relevancia, &iter);
          gtk_list_store_set(armazenameto_relevancia, &iter,
          0, RelDocs[i].IDDoc,
          1, aux,
          -1);
          // g_printf("Documento %d (arquivo%d.txt)\n", RelDocs[i].IDDoc, RelDocs[i].IDDoc);
        }
    }
    //use problems
}

void BuscaGTK(char termos[250]){
  Doc reldoc[14];
  Busca_textos(Pat, termos, QuantAquivo, reldoc);
  Imprime_Relevancia(reldoc, QuantAquivo);
  
}

void on_botao_mandar_pesquisa_clicked(GtkWidget *widget, gpointer data){
  const char* termos = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "cad_pesquisa")));
  BuscaGTK(termos);

  gtk_stack_set_visible_child_name(stack, "view_relevancia");
}


int main (int argc, char **argv){


    gtk_init(&argc, &argv);
    

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
        "on_botao_voltar_relevancia_clicked",             G_CALLBACK(on_botao_voltar_relevancia_clicked),
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
        "on_botao_mandar_pesquisa_clicked",               G_CALLBACK(on_botao_mandar_pesquisa_clicked),
        "on_botao_mandar_clicked",                        G_CALLBACK(on_botao_mandar_clicked),
        "on_botao_voltar_mandar_clicked",                 G_CALLBACK(on_botao_voltar_mandar_clicked),
        

    NULL);


    gtk_builder_connect_signals(builder,NULL);


    stack =     GTK_WIDGET(gtk_builder_get_object(builder, "stack"));
    window =    GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    armazenameto_relevancia = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_relevancia"));
    armazenamento_todos = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_todos"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}