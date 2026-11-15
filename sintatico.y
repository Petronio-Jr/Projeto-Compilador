%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.c"
#include "utils.c"

extern FILE *yyin, *yyout;
extern int nlinha;
int contavar = 0;
int rotulo = 0;
int tipo;

int rotulo_main = 0;
int tem_funcoes = 0; 
int nparam = 0;
int pos_funcao = 0;
int tem_retorno = 0;

int dentro_funcao = 0;
int tipo_retorno_funcao = 0;
int end_retorno = 0;
int rotulo_fim_funcao = 0;

#define DEBUG(x)

%}

%token T_PROG
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE 
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E 
%token T_OU
%token T_V 
%token T_F 
%token T_NUMERO
%token T_NAO 
%token T_ABRE
%token T_FECHA
%token T_LOGICO
%token T_INTEIRO
%token T_RETORNE
%token T_FN
%token T_FIMFN
%token T_FUNC

%define parse.error custom

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV

%%
programa
    : cabecalho 
        { fprintf(yyout, "\tINPP\n"); }
      variaveis 
        { 
            DEBUG(mostratabela();)
            empilha(contavar, 'c');
            if(contavar > 0){
                 fprintf(yyout, "\tAMEM\t%d\n", contavar);
            }
        }
      rotinas
      T_INICIO lista_comandos T_FIM
        { 
            int conta = desempilha('c');
            if(conta > 0)
                fprintf(yyout, "\tDMEM\t%d\n", conta);
            fprintf(yyout, "\tFIMP\n"); 
        }
    ;

cabecalho
    : T_PROG T_IDENTIF
    ;

variaveis
    : /* vazio */
    | declaracao_variaveis
    ;

rotinas
    : /* vazio */
    | lista_funcoes
        { fprintf(yyout, "L%d\tNADA\n", rotulo_main); }
    ;

lista_funcoes
    : lista_funcoes funcao
    | funcao
    ;

funcao
    : T_FN tipo T_FUNC
        {
            /* desvia do código das funções ao programa principal (1ª função) */
           if(!tem_funcoes){
                tem_funcoes = 1;
                fprintf(yyout, "\tDSVS\tL%d\n", rotulo_main);
            }
            tipo_retorno_funcao = tipo;
            strcpy(elemtab.nome, atomo);
            elemtab.tipo = tipo;
            elemtab.cat = 'F';
            elemtab.end = 0;
            elemtab.rotulo = ++rotulo;
            elemtab.npar = 0;
            inseresimbolo(elemtab);          /* escopo global */
            pos_funcao = topotab;
            base_escopo = topotab + 1;       /* parâmetros: escopo da função */
            nparam = 0;
            tem_retorno = 0;
            dentro_funcao = 1;
        }
      T_ABRE lista_parametros T_FECHA
        {
            for(int i = 0; i < nparam; i++)
                tabsimb[pos_funcao + 1 + i].end = i - nparam - 2;
            tabsimb[pos_funcao].npar = nparam;
            end_retorno = -(nparam + 3);
            fprintf(yyout, "L%d\tENSP\n", tabsimb[pos_funcao].rotulo);
        }
      T_INICIO lista_comandos T_FIMFN
        {
            if(!tem_retorno)
                yyerror("Função sem comando RETORNE");
            topotab = pos_funcao;            /* descarta os parâmetros */
            base_escopo = 0;
            dentro_funcao = 0;
        }
    ;

lista_parametros
    : /*vazio*/
    | parametros
    ;

parametros
    : parametros parametro
    | parametro
    ;

parametro
    : tipo T_IDENTIF
        {
            if(nparam >= MAXPAR)
                yyerror("Número máximo de parâmetros excedido");
            strcpy(elemtab.nome, atomo);
            elemtab.tipo = tipo;
            elemtab.cat = 'P';
            elemtab.end = nparam;           
            inseresimbolo(elemtab);
            tabsimb[pos_funcao].tpar[nparam] = tipo;
            nparam++;
        }
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;

tipo
    : T_LOGICO
        { tipo = LOG; }
    | T_INTEIRO
        { tipo = INT; }
    ;

lista_variaveis
    : lista_variaveis T_IDENTIF
      { 
        strcpy(elemtab.nome,atomo);
        elemtab.tipo = tipo;
        elemtab.cat = 'V';
        elemtab.end = contavar;
        inseresimbolo(elemtab);
        contavar++; 
      }
    | T_IDENTIF
      { 
        strcpy(elemtab.nome,atomo);
        elemtab.tipo = tipo;
        elemtab.cat = 'V';
        elemtab.end = contavar;
        inseresimbolo(elemtab);
        contavar++; 
      }
    ;

lista_comandos
    : /* vazio */
    | comando lista_comandos
    ;

comando
    : leitura
    | escrita
    | repeticao
    | selecao
    | atribuicao
    | retorne
    ;

leitura
    : T_LEIA T_IDENTIF
        { 
            int pos = buscasimbolo(atomo);
            fprintf(yyout, "\tLEIA\n"); 
            armazena(pos);
        }
    ;

escrita
    : T_ESCREVA expressao
        { 
            int t = desempilha('t');
            fprintf(yyout, "\tESCR\n"); 
        }
    ;

repeticao
    : T_ENQTO 
        { 
            fprintf(yyout,"L%d\tNADA\n", ++rotulo);
            empilha(rotulo, 'r');
        }
      expressao 
      T_FACA
        {  
            int t = desempilha('t');
            if(t != LOG)
                yyerror("Incompatibilidade de tipo na condição do enquanto");
            fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
            empilha(rotulo,'r');
        } 
      lista_comandos 
      T_FIMENQTO
        { 
            int y = desempilha('r');
            int x = desempilha('r');
            fprintf(yyout,"\tDSVS\tL%d\n", x); 
            fprintf(yyout,"L%d\tNADA\n", y); 
        } 
    ;

selecao
    : T_SE expressao T_ENTAO
        { 
            int t = desempilha('t');
            if(t != LOG)
                yyerror("Incompatibilidade de tipo na condição da seleção");
            fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
            empilha(rotulo,'r');

        }  
      lista_comandos T_SENAO 
        {
            int x = desempilha('r');
            fprintf(yyout,"\tDSVS\tL%d\n", ++rotulo);
            fprintf(yyout,"L%d\tNADA\n", x);
            empilha(rotulo,'r'); 
        }  
      lista_comandos T_FIMSE
            { 
                int y = desempilha('r');
                fprintf(yyout,"L%d\tNADA\n", y);
            }  
    ;

atribuicao
    : T_IDENTIF 
        {
            int pos = buscasimbolo(atomo);
            empilha(pos, 'p');
        }
      T_ATRIB expressao
        { 
            int t = desempilha('t');
            int pos = desempilha('p');
            if(t != tabsimb[pos].tipo)
                yyerror("Incompatibilidade de tipos na atribuição");
            armazena(pos);
        }  
    ;

retorne
    : T_RETORNE
        {
            if(!dentro_funcao)
                yyerror("Comando RETORNE fora de função");
        }
        expressao
        {
            int t = desempilha('t');
            tem_retorno = 1;
            if(t != tipo_retorno_funcao)
                yyerror("Incompatibilidade de tipos no retorno da função");
            fprintf(yyout,"\tARZL\t%d\n", end_retorno);
            fprintf(yyout,"\tRTSP\t%d\n", tabsimb[pos_funcao].npar);
        }
    ;

expressao
    : expressao T_VEZES expressao
        { testatipo (INT, INT, INT); fprintf(yyout,"\tMULT\n"); }  
    | expressao T_DIV expressao
        { testatipo (INT, INT, INT); fprintf(yyout,"\tDIVI\n"); }  
    | expressao T_MAIS expressao
        { testatipo (INT, INT, INT); fprintf(yyout,"\tSOMA\n"); }  
    | expressao T_MENOS expressao
        { testatipo (INT, INT, INT); fprintf(yyout,"\tSUBT\n"); } 
    | expressao T_MAIOR expressao
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMMA\n"); } 
    | expressao T_MENOR expressao
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMME\n"); } 
    | expressao T_IGUAL expressao
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMIG\n"); } 
    | expressao T_E expressao
        { testatipo (LOG, LOG, LOG); fprintf(yyout,"\tCONJ\n"); } 
    | expressao T_OU expressao
        { testatipo (LOG, LOG, LOG); fprintf(yyout,"\tDISJ\n"); } 
    | termo
    ;

termo
    : T_IDENTIF
        { 
            int pos = buscasimbolo(atomo);
            carrega(pos);
            empilha(tabsimb[pos].tipo, 't');
        } 
    | T_NUMERO
        { 
            fprintf(yyout,"\tCRCT\t%s\n", atomo);
            empilha(INT, 't'); 
        } 
    | T_V
        { 
            fprintf(yyout,"\tCRCT\t1\n");
            empilha(LOG,'t');
        } 
    | T_F
        { 
            fprintf(yyout,"\tCRCT\t0\n");
            empilha(LOG, 't'); 
        } 
    | T_NAO termo
        { 
            int t = desempilha('t');
            if(t != LOG)
                yyerror("O operando do NAO tem que ser logico");
            empilha(LOG, 't');
            fprintf(yyout,"\tNEGA\n"); 
        } 
    | T_FUNC
        {
            int pos = buscasimbolo(atomo);
            if(tabsimb[pos].cat != 'F')
                yyerror("Identificador não é uma função");
            empilha(pos, 'f');               /* função sendo chamada */
            empilha(0, 'n');                 /* argumentos já processados */
            fprintf(yyout, "\tAMEM\t1\n");     /* espaço para o resultado */
        }
      T_ABRE lista_argumentos T_FECHA
        {
            int n = desempilha('n');
            int pos = desempilha('f');
            if(n != tabsimb[pos].npar)
                yyerror("Número de argumentos diferente do número de parâmetros");
            fprintf(yyout, "\tSVCP\n");
            fprintf(yyout, "\tDSVS\tL%d\n", tabsimb[pos].rotulo);
            empilha(tabsimb[pos].tipo, 't'); /* o resultado fica no topo da MVS */
        }
    | T_ABRE expressao T_FECHA
    ; 

lista_argumentos
    : /* vazio */
    | argumentos
    ;

argumentos
    : argumentos argumento
    | argumento
    ;

argumento
    : expressao
        {
            /* passagem por valor: o valor da expressão já está na pilha da MVS */
            int t = desempilha('t');
            int n = desempilha('n');
            int pos = consulta('f');
            if(n >= tabsimb[pos].npar)
                yyerror("Número de argumentos maior que o de parâmetros");
            if(t != tabsimb[pos].tpar[n])
                yyerror("Incompatibilidade de tipo no argumento da chamada");
            empilha(n + 1, 'n');
        }
    ;
%%

void yyerror(const char *mensagem)
{
    fprintf(stderr, "Erro na linha %d\n", nlinha);
    fprintf(stderr, "Erro Interno %s\n", mensagem);
    exit(10);
}

static const char *nome_token(yysymbol_kind_t token)
{
    static const char *nomes[] = {
        [YYSYMBOL_T_PROG]      = "programa",
        [YYSYMBOL_T_INICIO]    = "início",
        [YYSYMBOL_T_FIM]       = "fim",
        [YYSYMBOL_T_IDENTIF]   = "identificador",
        [YYSYMBOL_T_LEIA]      = "leia",
        [YYSYMBOL_T_ESCREVA]   = "escreva",
        [YYSYMBOL_T_ENQTO]     = "enquanto",
        [YYSYMBOL_T_FACA]      = "faça",
        [YYSYMBOL_T_FIMENQTO]  = "fim-enquanto",
        [YYSYMBOL_T_SE]        = "se",
        [YYSYMBOL_T_ENTAO]     = "então",
        [YYSYMBOL_T_SENAO]     = "senão",
        [YYSYMBOL_T_FIMSE]     = "fim-se",
        [YYSYMBOL_T_ATRIB]     = "atribuição",
        [YYSYMBOL_T_VEZES]     = "'*'",
        [YYSYMBOL_T_DIV]       = "'/'",
        [YYSYMBOL_T_MAIS]      = "'+'",
        [YYSYMBOL_T_MENOS]     = "'-'",
        [YYSYMBOL_T_MAIOR]     = "'>'",
        [YYSYMBOL_T_MENOR]     = "'<'",
        [YYSYMBOL_T_IGUAL]     = "'='",
        [YYSYMBOL_T_E]         = "e",
        [YYSYMBOL_T_OU]        = "ou",
        [YYSYMBOL_T_V]         = "verdadeiro",
        [YYSYMBOL_T_F]         = "falso",
        [YYSYMBOL_T_NUMERO]    = "número",
        [YYSYMBOL_T_NAO]       = "não",
        [YYSYMBOL_T_ABRE]      = "'('",
        [YYSYMBOL_T_FECHA]     = "')'",
        [YYSYMBOL_T_LOGICO]    = "lógico",
        [YYSYMBOL_T_INTEIRO]   = "inteiro",
        [YYSYMBOL_T_RETORNE]   = "retorne",
        [YYSYMBOL_T_FN]        = "fn",
        [YYSYMBOL_T_FIMFN]     = "fimfn",
        [YYSYMBOL_T_FUNC]      = "nome de função"
    };

    if (token >= 0 &&
        token < sizeof(nomes) / sizeof(nomes[0]) &&
        nomes[token] != NULL)
        return nomes[token];

    return "símbolo desconhecido";
}

static int yyreport_syntax_error(const yypcontext_t *ctx)
{
    yysymbol_kind_t token;
    yysymbol_kind_t expected[10];

    token = yypcontext_token(ctx);

    fprintf(stderr, "Erro de sintaxe.\n");
    fprintf(stderr, "  Símbolo encontrado: %s\n",
            nome_token(token));

    fprintf(stderr, "  Símbolos esperados: ");

    int n = yypcontext_expected_tokens(ctx, expected, 10);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            fprintf(stderr, ", ");

        fprintf(stderr, "%s", nome_token(expected[i]));
    }
    fprintf(stderr, "\n\n");
    return 0;
}

int main(int argc, char *argv[]) {
    char nameIn[100], nameOut[100], *s;
    if (argc < 2) {
        printf("Uso:\n \t%s <nomeprog[.simples]>\n\n", argv[0]);
        exit(20);
    }
    s = strstr(argv[1],".simples");
    if(s){
        *s = 0;
    }
    strcpy(nameIn, argv[1]);
    strcpy(nameOut, argv[1]);

    strcat(nameIn, ".simples");
    strcat(nameOut, ".mvs");
    yyin = fopen(nameIn, "rt");
    yyout = fopen(nameOut, "wt");
    yyparse();
    fclose(yyin);
    fclose(yyout);
}