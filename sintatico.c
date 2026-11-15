/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

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
int contalocal = 0;

void declara_variavel(void)
{
    strcpy(elemtab.nome, atomo);
    elemtab.tipo = tipo;
    if(dentro_funcao){
        elemtab.cat = 'L';
        elemtab.end = contalocal++;
    } else {
        elemtab.cat = 'V';
        elemtab.end = contavar++;
    }
    inseresimbolo(elemtab);
}

#define DEBUG(x)


#line 114 "sintatico.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintatico.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROG = 3,                     /* T_PROG  */
  YYSYMBOL_T_INICIO = 4,                   /* T_INICIO  */
  YYSYMBOL_T_FIM = 5,                      /* T_FIM  */
  YYSYMBOL_T_IDENTIF = 6,                  /* T_IDENTIF  */
  YYSYMBOL_T_LEIA = 7,                     /* T_LEIA  */
  YYSYMBOL_T_ESCREVA = 8,                  /* T_ESCREVA  */
  YYSYMBOL_T_ENQTO = 9,                    /* T_ENQTO  */
  YYSYMBOL_T_FACA = 10,                    /* T_FACA  */
  YYSYMBOL_T_FIMENQTO = 11,                /* T_FIMENQTO  */
  YYSYMBOL_T_SE = 12,                      /* T_SE  */
  YYSYMBOL_T_ENTAO = 13,                   /* T_ENTAO  */
  YYSYMBOL_T_SENAO = 14,                   /* T_SENAO  */
  YYSYMBOL_T_FIMSE = 15,                   /* T_FIMSE  */
  YYSYMBOL_T_ATRIB = 16,                   /* T_ATRIB  */
  YYSYMBOL_T_VEZES = 17,                   /* T_VEZES  */
  YYSYMBOL_T_DIV = 18,                     /* T_DIV  */
  YYSYMBOL_T_MAIS = 19,                    /* T_MAIS  */
  YYSYMBOL_T_MENOS = 20,                   /* T_MENOS  */
  YYSYMBOL_T_MAIOR = 21,                   /* T_MAIOR  */
  YYSYMBOL_T_MENOR = 22,                   /* T_MENOR  */
  YYSYMBOL_T_IGUAL = 23,                   /* T_IGUAL  */
  YYSYMBOL_T_E = 24,                       /* T_E  */
  YYSYMBOL_T_OU = 25,                      /* T_OU  */
  YYSYMBOL_T_V = 26,                       /* T_V  */
  YYSYMBOL_T_F = 27,                       /* T_F  */
  YYSYMBOL_T_NUMERO = 28,                  /* T_NUMERO  */
  YYSYMBOL_T_NAO = 29,                     /* T_NAO  */
  YYSYMBOL_T_ABRE = 30,                    /* T_ABRE  */
  YYSYMBOL_T_FECHA = 31,                   /* T_FECHA  */
  YYSYMBOL_T_LOGICO = 32,                  /* T_LOGICO  */
  YYSYMBOL_T_INTEIRO = 33,                 /* T_INTEIRO  */
  YYSYMBOL_T_RETORNE = 34,                 /* T_RETORNE  */
  YYSYMBOL_T_FN = 35,                      /* T_FN  */
  YYSYMBOL_T_FIMFN = 36,                   /* T_FIMFN  */
  YYSYMBOL_T_FUNC = 37,                    /* T_FUNC  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_cabecalho = 42,                 /* cabecalho  */
  YYSYMBOL_variaveis = 43,                 /* variaveis  */
  YYSYMBOL_rotinas = 44,                   /* rotinas  */
  YYSYMBOL_lista_funcoes = 45,             /* lista_funcoes  */
  YYSYMBOL_funcao = 46,                    /* funcao  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_49_5 = 49,                      /* $@5  */
  YYSYMBOL_lista_parametros = 50,          /* lista_parametros  */
  YYSYMBOL_parametros = 51,                /* parametros  */
  YYSYMBOL_parametro = 52,                 /* parametro  */
  YYSYMBOL_declaracao_variaveis = 53,      /* declaracao_variaveis  */
  YYSYMBOL_tipo = 54,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 55,           /* lista_variaveis  */
  YYSYMBOL_lista_comandos = 56,            /* lista_comandos  */
  YYSYMBOL_comando = 57,                   /* comando  */
  YYSYMBOL_leitura = 58,                   /* leitura  */
  YYSYMBOL_escrita = 59,                   /* escrita  */
  YYSYMBOL_repeticao = 60,                 /* repeticao  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_selecao = 63,                   /* selecao  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_atribuicao = 66,                /* atribuicao  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_retorne = 68,                   /* retorne  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_expressao = 70,                 /* expressao  */
  YYSYMBOL_termo = 71,                     /* termo  */
  YYSYMBOL_72_12 = 72,                     /* $@12  */
  YYSYMBOL_lista_argumentos = 73,          /* lista_argumentos  */
  YYSYMBOL_argumentos = 74,                /* argumentos  */
  YYSYMBOL_argumento = 75                  /* argumento  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    93,    90,   111,   115,   116,   120,   121,
     126,   127,   132,   153,   162,   131,   177,   178,   182,   183,
     187,   202,   203,   207,   209,   214,   216,   221,   222,   226,
     227,   228,   229,   230,   231,   235,   244,   253,   259,   252,
     278,   287,   277,   302,   301,   318,   317,   336,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   358,   364,   369,
     374,   379,   388,   387,   406,   410,   411,   415,   416,   420
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "T_PROG", "T_INICIO", "T_FIM",
  "T_IDENTIF", "T_LEIA", "T_ESCREVA", "T_ENQTO", "T_FACA", "T_FIMENQTO",
  "T_SE", "T_ENTAO", "T_SENAO", "T_FIMSE", "T_ATRIB", "T_VEZES", "T_DIV",
  "T_MAIS", "T_MENOS", "T_MAIOR", "T_MENOR", "T_IGUAL", "T_E", "T_OU",
  "T_V", "T_F", "T_NUMERO", "T_NAO", "T_ABRE", "T_FECHA", "T_LOGICO",
  "T_INTEIRO", "T_RETORNE", "T_FN", "T_FIMFN", "T_FUNC", "$accept",
  "programa", "$@1", "$@2", "cabecalho", "variaveis", "rotinas",
  "lista_funcoes", "funcao", "$@3", "$@4", "$@5", "lista_parametros",
  "parametros", "parametro", "declaracao_variaveis", "tipo",
  "lista_variaveis", "lista_comandos", "comando", "leitura", "escrita",
  "repeticao", "$@6", "$@7", "selecao", "$@8", "$@9", "atribuicao", "$@10",
  "retorne", "$@11", "expressao", "termo", "$@12", "lista_argumentos",
  "argumentos", "argumento", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    -4,    15,   -33,   -33,   -33,   -20,   -33,   -33,   -33,
     -33,    22,     1,   -33,     8,   -20,    33,     1,   -33,   -33,
     -33,    28,    -2,   -33,   -33,   -33,    32,    -3,   -33,    -3,
     -33,    54,    -2,   -33,   -33,   -33,   -33,   -33,   -33,    37,
      52,   -33,   -33,   -33,   -33,   -33,    -3,    -3,   -33,    95,
     -33,    -3,    86,    -3,   -33,   -33,   -20,    -3,   -33,    71,
      39,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      62,   -33,    95,    40,   -20,   -33,    64,    95,   -33,    -3,
     -33,   -33,    13,    13,    44,    44,    35,    -1,    -1,   -33,
      -2,   -33,   -33,   -33,    95,    42,    -3,   -33,    -2,    60,
     -20,   -33,   -33,    65,   -33,   -33,   -33,    -2,    73,    82,
      -2,   -33,    85,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     5,     1,     6,    23,    24,     3,
       7,     0,     8,    26,    22,     0,     0,     9,    11,    25,
      21,     0,    27,    10,    12,    43,     0,     0,    37,     0,
      45,     0,    27,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    57,    59,    60,    58,     0,     0,    62,    36,
      56,     0,     0,     0,     4,    28,    16,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,    46,     0,    17,    19,     0,    44,    64,    65,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    38,
      27,    13,    18,    20,    69,     0,    66,    68,    27,     0,
       6,    63,    67,     0,    41,    14,    39,    27,     0,     0,
      27,    42,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,    81,   -33,
     -33,   -33,   -33,   -33,    27,   108,   -14,   -33,   -32,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -18,    77,   -33,   -33,   -33,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    12,     3,     9,    16,    17,    18,    39,
     100,   108,    73,    74,    75,    10,    11,    14,    31,    32,
      33,    34,    35,    51,    98,    36,    90,   107,    37,    40,
      38,    53,    94,    50,    60,    95,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    21,     4,    42,    25,    26,    27,    28,     1,    49,
      29,    52,     7,     8,    19,     5,    61,    62,    63,    64,
      65,    66,    67,    43,    44,    45,    46,    47,    13,    59,
      61,    62,    30,    70,    48,    72,    15,    22,    41,    77,
       7,     8,    76,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    61,    62,    63,    64,    65,    66,    99,    54,
      76,    61,    62,    63,    64,    24,   103,    56,    57,    79,
      93,    91,    89,   101,   104,   109,   106,   110,   112,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   111,    23,    71,
     105,    92,    78,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    61,    62,    63,    64,    65,    66,    67,    68,
      69,   113,    20,    58,     0,   102
};

static const yytype_int8 yycheck[] =
{
      32,    15,     6,     6,     6,     7,     8,     9,     3,    27,
      12,    29,    32,    33,     6,     0,    17,    18,    19,    20,
      21,    22,    23,    26,    27,    28,    29,    30,     6,    47,
      17,    18,    34,    51,    37,    53,    35,     4,     6,    57,
      32,    33,    56,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    17,    18,    19,    20,    21,    22,    90,     5,
      74,    17,    18,    19,    20,    37,    98,    30,    16,    30,
       6,    31,    10,    31,    14,   107,    11,     4,   110,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    15,    17,    13,
     100,    74,    31,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    36,    14,    46,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    39,    42,     6,     0,    40,    32,    33,    43,
      53,    54,    41,     6,    55,    35,    44,    45,    46,     6,
      53,    54,     4,    46,    37,     6,     7,     8,     9,    12,
      34,    56,    57,    58,    59,    60,    63,    66,    68,    47,
      67,     6,     6,    26,    27,    28,    29,    30,    37,    70,
      71,    61,    70,    69,     5,    56,    30,    16,    71,    70,
      72,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      70,    13,    70,    50,    51,    52,    54,    70,    31,    30,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    10,
      64,    31,    52,     6,    70,    73,    74,    75,    62,    56,
      48,    31,    75,    56,    14,    43,    11,    65,    49,    56,
       4,    15,    56,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    40,    41,    39,    42,    43,    43,    44,    44,
      45,    45,    47,    48,    49,    46,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    59,    61,    62,    60,
      64,    65,    63,    67,    66,    69,    68,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    72,    71,    71,    73,    73,    74,    74,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     2,     0,     1,     0,     1,
       2,     1,     0,     0,     0,    13,     0,     1,     2,     1,
       2,     3,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     0,     7,
       0,     0,     9,     0,     4,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     0,     1,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}



/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 91 "sintatico.y"
        { fprintf(yyout, "\tINPP\n"); }
#line 1317 "sintatico.c"
    break;

  case 3: /* $@2: %empty  */
#line 93 "sintatico.y"
        { 
            DEBUG(mostratabela();)
            empilha(contavar, 'c');
            if(contavar > 0){
                 fprintf(yyout, "\tAMEM\t%d\n", contavar);
            }
        }
#line 1329 "sintatico.c"
    break;

  case 4: /* programa: cabecalho $@1 variaveis $@2 rotinas T_INICIO lista_comandos T_FIM  */
#line 102 "sintatico.y"
        { 
            int conta = desempilha('c');
            if(conta > 0)
                fprintf(yyout, "\tDMEM\t%d\n", conta);
            fprintf(yyout, "\tFIMP\n"); 
        }
#line 1340 "sintatico.c"
    break;

  case 9: /* rotinas: lista_funcoes  */
#line 122 "sintatico.y"
        { fprintf(yyout, "L%d\tNADA\n", rotulo_main); }
#line 1346 "sintatico.c"
    break;

  case 12: /* $@3: %empty  */
#line 132 "sintatico.y"
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
            inseresimbolo(elemtab);          
            pos_funcao = topotab;
            base_escopo = topotab + 1;      
            nparam = 0;
            tem_retorno = 0;
            dentro_funcao = 1;
        }
#line 1371 "sintatico.c"
    break;

  case 13: /* $@4: %empty  */
#line 153 "sintatico.y"
        {
            for(int i = 0; i < nparam; i++)
                tabsimb[pos_funcao + 1 + i].end = i - nparam - 2;
            tabsimb[pos_funcao].npar = nparam;
            end_retorno = -(nparam + 3);
            contalocal = 0;
            fprintf(yyout, "L%d\tENSP\n", tabsimb[pos_funcao].rotulo);
        }
#line 1384 "sintatico.c"
    break;

  case 14: /* $@5: %empty  */
#line 162 "sintatico.y"
        {
            if(contalocal > 0)
                fprintf(yyout, "\tAMEM\t%d\n", contalocal);
        }
#line 1393 "sintatico.c"
    break;

  case 15: /* funcao: T_FN tipo T_FUNC $@3 T_ABRE lista_parametros T_FECHA $@4 variaveis $@5 T_INICIO lista_comandos T_FIMFN  */
#line 167 "sintatico.y"
        {
            if(!tem_retorno)
                yyerror("Função sem comando RETORNE");
            topotab = pos_funcao;           
            base_escopo = 0;
            dentro_funcao = 0;
        }
#line 1405 "sintatico.c"
    break;

  case 20: /* parametro: tipo T_IDENTIF  */
#line 188 "sintatico.y"
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
#line 1421 "sintatico.c"
    break;

  case 23: /* tipo: T_LOGICO  */
#line 208 "sintatico.y"
        { tipo = LOG; }
#line 1427 "sintatico.c"
    break;

  case 24: /* tipo: T_INTEIRO  */
#line 210 "sintatico.y"
        { tipo = INT; }
#line 1433 "sintatico.c"
    break;

  case 25: /* lista_variaveis: lista_variaveis T_IDENTIF  */
#line 215 "sintatico.y"
      { declara_variavel(); }
#line 1439 "sintatico.c"
    break;

  case 26: /* lista_variaveis: T_IDENTIF  */
#line 217 "sintatico.y"
      { declara_variavel(); }
#line 1445 "sintatico.c"
    break;

  case 35: /* leitura: T_LEIA T_IDENTIF  */
#line 236 "sintatico.y"
        { 
            int pos = buscasimbolo(atomo);
            fprintf(yyout, "\tLEIA\n"); 
            armazena(pos);
        }
#line 1455 "sintatico.c"
    break;

  case 36: /* escrita: T_ESCREVA expressao  */
#line 245 "sintatico.y"
        { 
            int t = desempilha('t');
            fprintf(yyout, "\tESCR\n"); 
        }
#line 1464 "sintatico.c"
    break;

  case 37: /* $@6: %empty  */
#line 253 "sintatico.y"
        { 
            fprintf(yyout,"L%d\tNADA\n", ++rotulo);
            empilha(rotulo, 'r');
        }
#line 1473 "sintatico.c"
    break;

  case 38: /* $@7: %empty  */
#line 259 "sintatico.y"
        {  
            int t = desempilha('t');
            if(t != LOG)
                yyerror("Incompatibilidade de tipo na condição do enquanto");
            fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
            empilha(rotulo,'r');
        }
#line 1485 "sintatico.c"
    break;

  case 39: /* repeticao: T_ENQTO $@6 expressao T_FACA $@7 lista_comandos T_FIMENQTO  */
#line 268 "sintatico.y"
        { 
            int y = desempilha('r');
            int x = desempilha('r');
            fprintf(yyout,"\tDSVS\tL%d\n", x); 
            fprintf(yyout,"L%d\tNADA\n", y); 
        }
#line 1496 "sintatico.c"
    break;

  case 40: /* $@8: %empty  */
#line 278 "sintatico.y"
        { 
            int t = desempilha('t');
            if(t != LOG)
                yyerror("Incompatibilidade de tipo na condição da seleção");
            fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
            empilha(rotulo,'r');

        }
#line 1509 "sintatico.c"
    break;

  case 41: /* $@9: %empty  */
#line 287 "sintatico.y"
        {
            int x = desempilha('r');
            fprintf(yyout,"\tDSVS\tL%d\n", ++rotulo);
            fprintf(yyout,"L%d\tNADA\n", x);
            empilha(rotulo,'r'); 
        }
#line 1520 "sintatico.c"
    break;

  case 42: /* selecao: T_SE expressao T_ENTAO $@8 lista_comandos T_SENAO $@9 lista_comandos T_FIMSE  */
#line 294 "sintatico.y"
            { 
                int y = desempilha('r');
                fprintf(yyout,"L%d\tNADA\n", y);
            }
#line 1529 "sintatico.c"
    break;

  case 43: /* $@10: %empty  */
#line 302 "sintatico.y"
        {
            int pos = buscasimbolo(atomo);
            empilha(pos, 'p');
        }
#line 1538 "sintatico.c"
    break;

  case 44: /* atribuicao: T_IDENTIF $@10 T_ATRIB expressao  */
#line 307 "sintatico.y"
        { 
            int t = desempilha('t');
            int pos = desempilha('p');
            if(t != tabsimb[pos].tipo)
                yyerror("Incompatibilidade de tipos na atribuição");
            armazena(pos);
        }
#line 1550 "sintatico.c"
    break;

  case 45: /* $@11: %empty  */
#line 318 "sintatico.y"
        {
            if(!dentro_funcao)
                yyerror("Comando RETORNE fora de função");
        }
#line 1559 "sintatico.c"
    break;

  case 46: /* retorne: T_RETORNE $@11 expressao  */
#line 323 "sintatico.y"
        {
            int t = desempilha('t');
            tem_retorno = 1;
            if(t != tipo_retorno_funcao)
                yyerror("Incompatibilidade de tipos no retorno da função");
            fprintf(yyout, "\tARZL\t%d\n", end_retorno);
            if(contalocal > 0)
                fprintf(yyout, "\tDMEM\t%d\n", contalocal);
            fprintf(yyout, "\tRTSP\t%d\n", tabsimb[pos_funcao].npar);
        }
#line 1574 "sintatico.c"
    break;

  case 47: /* expressao: expressao T_VEZES expressao  */
#line 337 "sintatico.y"
        { testatipo (INT, INT, INT); fprintf(yyout,"\tMULT\n"); }
#line 1580 "sintatico.c"
    break;

  case 48: /* expressao: expressao T_DIV expressao  */
#line 339 "sintatico.y"
        { testatipo (INT, INT, INT); fprintf(yyout,"\tDIVI\n"); }
#line 1586 "sintatico.c"
    break;

  case 49: /* expressao: expressao T_MAIS expressao  */
#line 341 "sintatico.y"
        { testatipo (INT, INT, INT); fprintf(yyout,"\tSOMA\n"); }
#line 1592 "sintatico.c"
    break;

  case 50: /* expressao: expressao T_MENOS expressao  */
#line 343 "sintatico.y"
        { testatipo (INT, INT, INT); fprintf(yyout,"\tSUBT\n"); }
#line 1598 "sintatico.c"
    break;

  case 51: /* expressao: expressao T_MAIOR expressao  */
#line 345 "sintatico.y"
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMMA\n"); }
#line 1604 "sintatico.c"
    break;

  case 52: /* expressao: expressao T_MENOR expressao  */
#line 347 "sintatico.y"
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMME\n"); }
#line 1610 "sintatico.c"
    break;

  case 53: /* expressao: expressao T_IGUAL expressao  */
#line 349 "sintatico.y"
        { testatipo (INT, INT, LOG); fprintf(yyout,"\tCMIG\n"); }
#line 1616 "sintatico.c"
    break;

  case 54: /* expressao: expressao T_E expressao  */
#line 351 "sintatico.y"
        { testatipo (LOG, LOG, LOG); fprintf(yyout,"\tCONJ\n"); }
#line 1622 "sintatico.c"
    break;

  case 55: /* expressao: expressao T_OU expressao  */
#line 353 "sintatico.y"
        { testatipo (LOG, LOG, LOG); fprintf(yyout,"\tDISJ\n"); }
#line 1628 "sintatico.c"
    break;

  case 57: /* termo: T_IDENTIF  */
#line 359 "sintatico.y"
        { 
            int pos = buscasimbolo(atomo);
            carrega(pos);
            empilha(tabsimb[pos].tipo, 't');
        }
#line 1638 "sintatico.c"
    break;

  case 58: /* termo: T_NUMERO  */
#line 365 "sintatico.y"
        { 
            fprintf(yyout,"\tCRCT\t%s\n", atomo);
            empilha(INT, 't'); 
        }
#line 1647 "sintatico.c"
    break;

  case 59: /* termo: T_V  */
#line 370 "sintatico.y"
        { 
            fprintf(yyout,"\tCRCT\t1\n");
            empilha(LOG,'t');
        }
#line 1656 "sintatico.c"
    break;

  case 60: /* termo: T_F  */
#line 375 "sintatico.y"
        { 
            fprintf(yyout,"\tCRCT\t0\n");
            empilha(LOG, 't'); 
        }
#line 1665 "sintatico.c"
    break;

  case 61: /* termo: T_NAO termo  */
#line 380 "sintatico.y"
        { 
            int t = desempilha('t');
            if(t != LOG)
                yyerror("O operando do NAO tem que ser logico");
            empilha(LOG, 't');
            fprintf(yyout,"\tNEGA\n"); 
        }
#line 1677 "sintatico.c"
    break;

  case 62: /* $@12: %empty  */
#line 388 "sintatico.y"
        {
            int pos = buscasimbolo(atomo);
            if(tabsimb[pos].cat != 'F')
                yyerror("Identificador não é uma função");
            empilha(pos, 'f');               /* função sendo chamada */
            empilha(0, 'n');                 /* argumentos já processados */
            fprintf(yyout, "\tAMEM\t1\n");     /* espaço para o resultado */
        }
#line 1690 "sintatico.c"
    break;

  case 63: /* termo: T_FUNC $@12 T_ABRE lista_argumentos T_FECHA  */
#line 397 "sintatico.y"
        {
            int n = desempilha('n');
            int pos = desempilha('f');
            if(n != tabsimb[pos].npar)
                yyerror("Número de argumentos diferente do número de parâmetros");
            fprintf(yyout, "\tSVCP\n");
            fprintf(yyout, "\tDSVS\tL%d\n", tabsimb[pos].rotulo);
            empilha(tabsimb[pos].tipo, 't'); /* o resultado fica no topo da MVS */
        }
#line 1704 "sintatico.c"
    break;

  case 69: /* argumento: expressao  */
#line 421 "sintatico.y"
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
#line 1720 "sintatico.c"
    break;


#line 1724 "sintatico.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        if (yyreport_syntax_error (&yyctx) == 2)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 433 "sintatico.y"


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
