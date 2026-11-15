#include <stdio.h>

void yyerror(const char *);
extern int nlinha;

enum {
    INT = 10,
    LOG = 20
};

#define TAMPILHA 100
struct {
    int valor;
    char tipo;
} Pilha[TAMPILHA];

int topo = -1;

void empilha(int valor, char tipo){
    if(topo >= TAMPILHA - 1)
        yyerror("Pilha Cheia");
    topo++;
    Pilha[topo].valor = valor;
    Pilha[topo].tipo = tipo;
}

int desempilha(char tipo) {
    if (topo == -1)
        yyerror("Pilha Vazia");
    if (Pilha[topo].tipo != tipo)
        yyerror("Tipo diferente no desempilha");
    return Pilha[topo--].valor;
}

int consulta(char tp){
    if (topo == -1)
        yyerror("Pilha Vazia");
    if(Pilha[topo].tipo != tp)
        yyerror("Tipo diferente na consulta da pilha");
    return Pilha[topo].valor;    
}


void testatipo(int tipo1, int tipo2, int ret){
    int t2 = desempilha('t'); 
    int t1 = desempilha('t');
    
    if(t1 != tipo1 || t2 != tipo2)
        yyerror("Incompatibilidade de tipo!");
    
    empilha(ret, 't');
}

void mostrapilha(){
    printf("Pilha = [");
    for(int i = topo; i >= 0; i--){
        printf("(%d,%c) ", Pilha[i].valor, Pilha[i].tipo);
        printf("]\n");
    }
}

#define TAMTAB 100
#define MAXPAR 10

typedef struct {
    char nome[30];
    int tipo;
    int end;
    char cat;
    int rotulo;
    int npar;
    int tpar[MAXPAR];
} tiptab;

tiptab elemtab, tabsimb[TAMTAB];
int topotab = -1;
int base_escopo = 0;

void inseresimbolo(tiptab elem){
    int i;
    for(i = topotab; i >= base_escopo && strcmp(elem.nome, tabsimb[i].nome) != 0 ; i--)
        ;
    if(i >= base_escopo){
        yyerror("Identificador duplicado");
    }
    tabsimb[++topotab] = elem;
}

int buscasimbolo(char *nome){
    int i;
    for(i = topotab; i >= 0 && strcmp(nome, tabsimb[i].nome) != 0; i--)
        ;
    if(i == -1){
        yyerror("Identificador não encontrado");
    }
    return i;
}

void carrega(int pos){
    if(tabsimb[pos].cat == 'F')
        yyerror("Função usada como variável");
    if(tabsimb[pos].cat == 'P')
        fprintf(yyout, "\tCRVL\t%d\n", tabsimb[pos].end);
    else
        fprintf(yyout, "\tCRVG\t%d\n", tabsimb[pos].end);
}

void armazena(int pos){
    if(tabsimb[pos].cat == 'F')
        yyerror("Função não pode receber atribuição ou leitura");
    if(tabsimb[pos].cat == 'P')
        fprintf(yyout, "\tARZL\t%d\n", tabsimb[pos].end);
    else
        fprintf(yyout, "\tARZG\t%d\n", tabsimb[pos].end);
}

void mostratabela(){
    printf("%10s %3s %3s\n", "Nome", "Tipo", "End");
    for(int i = 0; i <= topotab; i++){
        printf("%10s %3d %3d\n", tabsimb[i].nome, tabsimb[i].tipo, tabsimb[i].end);
    }
}
