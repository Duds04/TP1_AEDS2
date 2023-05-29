#include "./headers/leitura.h"


GtkBuilder *builder;
GtkWidget *window;
GtkStack *stack;
GtkListStore *armazenameto;
TipoArvore Pat;
int QuantAquivo = 0;


// // typedef struct Dados* PDados;
// // typedef struct Dados{
// //   char palavra[50];
// //   char index[85];
// //   PDados Prox;
// // }TDados;


// PDados PalAtual;
// PDados PalProxima;

// // typedef struct Documento* PDocumento;
// // typedef struct Documento{
// //   int ID;
// //   char nome[14];
// //   PDocumento Prox;
// // }TDocumento;

// PDados DocAtual;
// PDados DocProxima;




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

void exibir_palavra(const char* palavra) {
    GtkLabel* label = GTK_LABEL(gtk_builder_get_object(builder, "label_tree"));
    gtk_label_set_text(label, palavra);
}

void on_botao_printar_arvore_clicked(GtkWidget *widget, gpointer data){

  MostraArvore(Pat);
  gtk_stack_set_visible_child_name(stack, "view_tree");
}

void Imprime_Relevancia(Doc RelDocs[], int N_Doc){
  int i;
  GtkTreeIter iter;
  gtk_list_store_clear(armazenameto);
  char aux[15];

    for(i = 0; i < QuantAquivo; i++){
        if(RelDocs[i].relevancia != 0){

          sprintf(aux, "arquivo%d.txt", RelDocs[i].IDDoc);
          // aux "(arquivo";
          // strcat(aux, RelDocs[i].IDDoc + '0');
          // strcat(aux, ".txt");

          gtk_list_store_append(armazenameto, &iter);
          gtk_list_store_set(armazenameto, &iter,
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

    // DocAtual = (PDocumento) malloc(sizeof(TDocumento));

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
    armazenameto = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_relevancia"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}


// #include "./headers/leitura.h"

// int main()
// {
//     char caminho[20] = "./entradas/";
//     char arquivo[30];
//     int N = 14;
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
//     leituraArquivo(caminho, &Pat, N);
//     MostraArvore(Pat);
//     ////////////////////////////////////////////////////////////

//     //TESTE BUSCA

//     char termos[250];
//     // printf("Digite os termos de busca: \n");
//     // scanf(" %[^\n]s", termos);
//     strcpy(termos, "the travelling problems technologies include nanomagnetic and quantum");
//     Doc reldoc[14];

//     Busca_textos(Pat, termos, N, reldoc);
//     printf("\nLista de Documentos:\n");
//     for(int i = 0; i < N; i++){
//         printf("\nID: %d, Relevancia: %.10lf\n", reldoc[i].IDDoc, reldoc[i].relevancia);
//     }
    
// }