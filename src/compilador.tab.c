/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compilador.y" /* yacc.c:339  */

#include "linguagemUtils.h"
#include "validacoes.h"

extern void yyerror();
extern int yylex();
extern char *yytext;
extern int yylineno;

extern char TiposDeDados[100];

extern void listarIdentificadores();
extern void limparTiposDeDados();
extern void salvarTipoDeDados(const char *);
extern char *obterTiposDeDados();
extern char *obterTipoDeDados(char *);
extern bool existeId(char *);
extern char *obterIdentificador(char []);
extern void salvarIdentificador(char *, char *);
extern void salvarIdentificadorEValor(char *, char *, char *);
extern void atualizarValor(char *, char *);
extern char *obterValor(char *);
extern void erroAtribuicao(char *, char *);
extern void erroIdentificadorInexistente(char *);
extern void erroIdentificadorDuplicado(char *);
bool atribucaoValida(char *);

char *floatToAscii(float);

int noDeIdentificadoresDeVetor=0;
char identificadorExtraido[100][100];

#line 99 "compilador.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VIRGULA = 258,
    APOSTROFE = 259,
    PONTO_VIRGULA = 260,
    IGUAL = 261,
    SOMA = 262,
    SUBTRACAO = 263,
    DIVISAO = 264,
    MULTIPLICACAO = 265,
    INC_DEC = 266,
    IGUAL_IGUAL = 267,
    DIFERENTE = 268,
    NEGACAO = 269,
    MENOR = 270,
    MAIOR = 271,
    MENOR_IGUAL = 272,
    MAIOR_IGUAL = 273,
    AND = 274,
    OR = 275,
    ABRE_PARENTESES = 276,
    FECHA_PARENTESES = 277,
    ABRE_CHAVE = 278,
    FECHA_CHAVE = 279,
    ABRE_COLCHETE = 280,
    FECHA_COLCHETE = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    FOR = 285,
    PRINT = 286,
    SAIR = 287,
    VALOR_NUMERICO = 288,
    VALOR_TEXTUAL = 289,
    TIPO_DE_DADOS = 290,
    ID = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "compilador.y" /* yacc.c:355  */

	float numVal;
	char *tipoDeDados;
	char *txtVal;

#line 182 "compilador.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "compilador.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    37,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    79,    80,    81,    82,    84,    85,    86,    87,
      88,    89,    90,    92,   100,   110,   120,   130,   141,   142,
     144,   156,   168,   180,   196,   197,   198,   199,   200,   202,
     204,   205,   206,   207,   209,   210,   211,   212,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   225,   226,
     227,   228,   230,   235,   241,   242,   243,   244,   245,   247,
     255,   256
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VIRGULA", "APOSTROFE", "PONTO_VIRGULA",
  "IGUAL", "SOMA", "SUBTRACAO", "DIVISAO", "MULTIPLICACAO", "INC_DEC",
  "IGUAL_IGUAL", "DIFERENTE", "NEGACAO", "MENOR", "MAIOR", "MENOR_IGUAL",
  "MAIOR_IGUAL", "AND", "OR", "ABRE_PARENTESES", "FECHA_PARENTESES",
  "ABRE_CHAVE", "FECHA_CHAVE", "ABRE_COLCHETE", "FECHA_COLCHETE", "IF",
  "ELSE", "WHILE", "FOR", "PRINT", "SAIR", "VALOR_NUMERICO",
  "VALOR_TEXTUAL", "TIPO_DE_DADOS", "ID", "'>'", "$accept", "LINHA",
  "FUNCAO_PRINT", "DECLARACAO", "EXPRESSAO", "ATRIBUICAO",
  "FUNCOES_RESERVADAS", "CLAUSULA_IF", "LISTA_VARS", "TOKENS", "OP_LOGICA",
  "EXPRESSAO_NUMERICA", "VALOR", "LISTA_DE_PARAMETROS",
  "FUNCAO_DECLARACAO", "LISTA_DE_TIPOS_DE_DADOS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    62
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -25,     2,    29,    35,    62,    14,   -21,    61,    73,
     -76,    17,    66,    71,   -76,    55,    81,    74,   -12,   -12,
      19,   209,   107,   129,   131,   -76,    30,    99,   -76,   109,
     139,   -76,    33,   -76,   111,    86,   147,   149,   -76,   146,
     -76,    43,   -76,   -12,   110,   -76,   -76,    98,   137,   -76,
     148,   160,   167,   -76,    72,   -76,   151,   164,   178,   182,
     -76,   -76,   -76,   155,   165,   110,   -76,   -76,   -76,    74,
     -76,   -76,   -76,   -76,   -76,     9,   126,   -76,   161,   169,
     169,   169,   169,   169,   169,   187,   197,   215,    19,   -12,
     -76,   -76,   -76,   -76,   110,   -76,   -76,   -76,   -76,    10,
     185,   -76,   -76,   -76,   217,     3,   136,    18,   -76,   -76,
     -76,   -76,   -76,   -76,   126,   126,   167,   -76,   219,   190,
     -76,   -76,   142,   142,   -76,   -76,   205,   206,   207,   208,
     150,   163,   194,   -76,   -76,   -76,   -12,   -12,   -12,   -12,
     -76,   -76,   220,   210,   211,   212,   213,   214,   -76,   -76,
     -76,   -76,   216,   126,   177,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     5,    34,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     6,    23,     0,     1,     0,
       0,     8,     0,     9,     0,     0,     0,     0,    16,     0,
      17,     0,    18,     0,    45,    47,    44,     0,     0,    46,
       0,     0,    40,    41,     0,    14,     0,     0,     0,     0,
      15,    12,    13,     0,     0,    30,    31,    33,    32,    22,
      10,    29,    19,    20,    21,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
      58,    59,    60,    61,    24,    26,    27,    25,    70,     0,
       0,    62,    63,    64,    65,     0,     0,     0,    48,    49,
      51,    50,    53,    52,     0,     0,    42,    43,     0,     0,
      69,    68,     0,     0,    28,    36,     0,     0,     0,     0,
       0,     0,     0,    71,    67,    66,     0,     0,     0,     0,
      39,    38,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,     0,     0,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -75,    -9,    -7,    -6,    -4,    -5,   196,   -76,    59,
      -8,    -2,   -16,   -76,    -3,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,    54,    47,
      48,    49,   104,   105,    16,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   106,    32,    24,    33,    35,   123,    36,    37,    43,
     100,    50,    17,   119,    52,    26,    53,    -3,    34,    25,
      34,    44,    45,    18,    46,    68,    35,   124,    36,    37,
     126,   127,   120,    -7,    34,    78,    63,   128,   129,   130,
     131,    -3,   101,   102,    -3,   103,    -3,    -3,    -3,    -3,
      19,    64,     7,     8,    51,     8,    20,    -7,    -2,     1,
      -7,    97,    -7,    -7,    -7,    -7,    76,    27,     7,     8,
       2,    38,    39,    28,    29,    88,    40,    89,   154,   -29,
     -29,   118,   116,    41,   117,     2,    42,     3,     4,     5,
       6,    72,    39,     7,     8,    21,    22,    31,    23,    32,
       2,    33,     3,     4,     5,    30,   134,   135,     7,     8,
      79,    80,    60,    81,    82,    83,    84,    56,    57,    58,
      59,    31,    31,    32,    32,    33,    33,     1,   143,   144,
     145,   146,    65,    66,    61,    67,    62,    29,   108,   109,
     110,   111,   112,   113,    70,    31,    69,    32,    71,    33,
      -2,    29,    73,     2,    74,     3,     4,     5,     6,    85,
     125,     7,     8,     2,    29,     3,     4,     5,    30,    75,
      86,     7,     8,    39,   140,   101,   102,     2,    29,     3,
       4,     5,    30,   107,    90,     7,     8,   141,    94,    95,
       2,    96,     3,     4,     5,    30,    87,    91,     7,     8,
      98,   155,    44,    45,     2,    46,     3,     4,     5,    30,
     114,    92,     7,     8,    55,    93,    56,    57,    58,    59,
     115,    63,   121,   122,   132,   133,   136,   137,   138,   139,
     142,   147,   148,   149,   150,   151,   152,    77,     0,   153
};

static const yytype_int16 yycheck[] =
{
       9,    76,     9,     5,     9,    11,     3,    11,    11,    21,
       1,    19,    37,     3,    20,    36,    20,     0,     1,     5,
       1,    33,    34,    21,    36,    27,    32,    24,    32,    32,
      12,    13,    22,     0,     1,    43,     6,    19,    20,   114,
     115,    24,    33,    34,    27,    36,    29,    30,    31,    32,
      21,    21,    35,    36,    35,    36,    21,    24,     0,     1,
      27,    63,    29,    30,    31,    32,    23,     6,    35,    36,
      27,     5,     6,     0,     1,     3,     5,     5,   153,     5,
       6,    89,    88,    28,    88,    27,     5,    29,    30,    31,
      32,     5,     6,    35,    36,    33,    34,   106,    36,   106,
      27,   106,    29,    30,    31,    32,   122,   123,    35,    36,
      12,    13,     5,    15,    16,    17,    18,     7,     8,     9,
      10,   130,   131,   130,   131,   130,   131,     1,   136,   137,
     138,   139,    33,    34,     5,    36,     5,     1,    79,    80,
      81,    82,    83,    84,     5,   154,    37,   154,    37,   154,
      24,     1,     5,    27,     5,    29,    30,    31,    32,    22,
      24,    35,    36,    27,     1,    29,    30,    31,    32,    23,
      22,    35,    36,     6,    24,    33,    34,    27,     1,    29,
      30,    31,    32,    22,    33,    35,    36,    24,    33,    34,
      27,    36,    29,    30,    31,    32,    36,    33,    35,    36,
      35,    24,    33,    34,    27,    36,    29,    30,    31,    32,
      23,    33,    35,    36,     5,    33,     7,     8,     9,    10,
      23,     6,    37,     6,     5,    35,    21,    21,    21,    21,
      36,    11,    22,    22,    22,    22,    22,    41,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    29,    30,    31,    32,    35,    36,    39,
      40,    41,    42,    43,    44,    45,    52,    37,    21,    21,
      21,    33,    34,    36,    49,     5,    36,     6,     0,     1,
      32,    40,    41,    44,     1,    42,    43,    52,     5,     6,
       5,    28,     5,    21,    33,    34,    36,    47,    48,    49,
      48,    35,    42,    43,    46,     5,     7,     8,     9,    10,
       5,     5,     5,     6,    21,    33,    34,    36,    49,    37,
       5,    37,     5,     5,     5,    23,    23,    45,    48,    12,
      13,    15,    16,    17,    18,    22,    22,    36,     3,     5,
      33,    33,    33,    33,    33,    34,    36,    49,    35,    53,
       1,    33,    34,    36,    50,    51,    39,    22,    47,    47,
      47,    47,    47,    47,    23,    23,    42,    43,    48,     3,
      22,    37,     6,     3,    24,    24,    12,    13,    19,    20,
      39,    39,     5,    35,    50,    50,    21,    21,    21,    21,
      24,    24,    36,    48,    48,    48,    48,    11,    22,    22,
      22,    22,    22,    23,    39,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    40,    40,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    42,    42,    42,    42,    42,
      43,    43,    43,    43,    44,    44,    44,    44,    44,    45,
      46,    46,    46,    46,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    51,    51,    51,    51,    52,
      53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     2,     2,     2,     2,
       3,     2,     3,     3,     3,     3,     2,     2,     2,     3,
       3,     3,     2,     2,     4,     4,     4,     4,     5,     2,
       3,     3,     3,     3,     1,     3,     5,    12,     7,     7,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     7,     7,     7,     7,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     2,     5,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 68 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1628 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 6:
#line 72 "compilador.y" /* yacc.c:1648  */
    { exit(EXIT_SUCCESS); }
#line 1634 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 10:
#line 76 "compilador.y" /* yacc.c:1648  */
    { exit(EXIT_SUCCESS); }
#line 1640 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 11:
#line 77 "compilador.y" /* yacc.c:1648  */
    {}
#line 1646 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 12:
#line 79 "compilador.y" /* yacc.c:1648  */
    { printf("%s \n", obterValor((yyvsp[-1].txtVal))); }
#line 1652 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 13:
#line 80 "compilador.y" /* yacc.c:1648  */
    { printf("%s \n", floatToAscii((yyvsp[-1].numVal))); }
#line 1658 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 14:
#line 81 "compilador.y" /* yacc.c:1648  */
    { printf("%s \n", floatToAscii((yyvsp[-1].numVal))); }
#line 1664 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 15:
#line 82 "compilador.y" /* yacc.c:1648  */
    { printf("%s \n", (yyvsp[-1].txtVal)); }
#line 1670 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 16:
#line 84 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1676 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 17:
#line 85 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1682 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 18:
#line 86 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1688 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 19:
#line 87 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1694 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 20:
#line 88 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1700 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 21:
#line 89 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1706 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 22:
#line 90 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1712 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 23:
#line 92 "compilador.y" /* yacc.c:1648  */
    {
	if (!existeId((yyvsp[0].txtVal))) {
    	salvarIdentificador((yyvsp[0].txtVal), (yyvsp[-1].tipoDeDados));
        salvarTipoDeDados((yyvsp[-1].tipoDeDados));
    } else {
        erroIdentificadorDuplicado((yyvsp[0].txtVal));
    }
}
#line 1725 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 24:
#line 100 "compilador.y" /* yacc.c:1648  */
    {
	if(existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorDuplicado((yyvsp[-2].txtVal));
	} else if (strcmp((yyvsp[-3].tipoDeDados), "number") != 0) {
		erroAtribuicao((yyvsp[-3].tipoDeDados), "number");
	} else {
        salvarIdentificadorEValor((yyvsp[-2].txtVal), (yyvsp[-3].tipoDeDados), floatToAscii((yyvsp[0].numVal)));
    //    salvarTipoDeDados($1);
    }
}
#line 1740 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 25:
#line 110 "compilador.y" /* yacc.c:1648  */
    {
	if(existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorDuplicado((yyvsp[-2].txtVal));
	} else if (strcmp((yyvsp[-3].tipoDeDados), "number") != 0) {
		erroAtribuicao((yyvsp[-3].tipoDeDados), "number");
	} else {
        salvarIdentificadorEValor((yyvsp[-2].txtVal), (yyvsp[-3].tipoDeDados), floatToAscii((yyvsp[0].numVal)));
    //    salvarTipoDeDados($1);
    }
}
#line 1755 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 26:
#line 120 "compilador.y" /* yacc.c:1648  */
    {
	if(existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorDuplicado((yyvsp[-2].txtVal));
	} else if (strcmp((yyvsp[-3].tipoDeDados), "text") != 0) {
		erroAtribuicao((yyvsp[-3].tipoDeDados), "text");
	} else {
        salvarIdentificadorEValor((yyvsp[-2].txtVal), (yyvsp[-3].tipoDeDados), (yyvsp[0].txtVal));
    //    salvarTipoDeDados($1);
    }
}
#line 1770 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 27:
#line 130 "compilador.y" /* yacc.c:1648  */
    {
	char *tipoFornecido = obterTipoDeDados((yyvsp[0].txtVal)); 
	if(existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorDuplicado((yyvsp[-2].txtVal));
	} else if(strcmp((yyvsp[-3].tipoDeDados), obterTipoDeDados((yyvsp[0].txtVal))) != 0) {
		erroAtribuicao((yyvsp[-3].tipoDeDados), tipoFornecido);
	} else {
        salvarIdentificadorEValor((yyvsp[-2].txtVal), (yyvsp[-3].tipoDeDados), obterValor((yyvsp[0].txtVal)));
    //    salvarTipoDeDados($1);
    }
}
#line 1786 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 29:
#line 142 "compilador.y" /* yacc.c:1648  */
    {;}
#line 1792 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 30:
#line 144 "compilador.y" /* yacc.c:1648  */
    {
	if (!existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorInexistente((yyvsp[-2].txtVal));
	} else {
		char *tipoEsperado = obterTipoDeDados((yyvsp[-2].txtVal));
		if(strcmp(tipoEsperado, "number") != 0) {
			erroAtribuicao(tipoEsperado, "number");
		} else {
    		atualizarValor((yyvsp[-2].txtVal), floatToAscii((yyvsp[0].numVal))); 
		}
	}
}
#line 1809 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 31:
#line 156 "compilador.y" /* yacc.c:1648  */
    {
	if (!existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorInexistente((yyvsp[-2].txtVal));
	} else {
		char *tipoEsperado = obterTipoDeDados((yyvsp[-2].txtVal));
		if (strcmp(tipoEsperado, "text") != 0) {
			erroAtribuicao(tipoEsperado, "text");
		} else {
    		atualizarValor((yyvsp[-2].txtVal), (yyvsp[0].txtVal));
		}
	}
}
#line 1826 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 32:
#line 168 "compilador.y" /* yacc.c:1648  */
    {
	if (!existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorInexistente((yyvsp[-2].txtVal));
	} else {
		char *tipoEsperado = obterTipoDeDados((yyvsp[-2].txtVal));
		if (strcmp(tipoEsperado, "number") != 0) {
			erroAtribuicao(tipoEsperado, "number");
		} else {
    		atualizarValor((yyvsp[-2].txtVal), floatToAscii((yyvsp[0].numVal)));
		} 
	}
}
#line 1843 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 33:
#line 180 "compilador.y" /* yacc.c:1648  */
    {
	if (!existeId((yyvsp[-2].txtVal))) {
		erroIdentificadorInexistente((yyvsp[-2].txtVal));
	} else if (!existeId((yyvsp[0].txtVal))) {
		erroIdentificadorInexistente((yyvsp[0].txtVal));
	} else { 
		char *tipoEsperado = obterTipoDeDados((yyvsp[-2].txtVal)); 
		char *tipoFornecido = obterTipoDeDados((yyvsp[0].txtVal)); 
		if (strcmp(tipoEsperado, tipoFornecido) != 0) {
			erroAtribuicao(tipoEsperado, tipoFornecido);
		} else {
    		atualizarValor((yyvsp[-2].txtVal), obterValor((yyvsp[0].txtVal)));
		}
	}
}
#line 1863 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 44:
#line 209 "compilador.y" /* yacc.c:1648  */
    { (yyval.txtVal) = obterValor((yyvsp[0].txtVal)); }
#line 1869 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 45:
#line 210 "compilador.y" /* yacc.c:1648  */
    { (yyval.txtVal) = floatToAscii((yyvsp[0].numVal)); }
#line 1875 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 46:
#line 211 "compilador.y" /* yacc.c:1648  */
    { (yyval.txtVal) = floatToAscii((yyvsp[0].numVal)); }
#line 1881 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 47:
#line 212 "compilador.y" /* yacc.c:1648  */
    { (yyval.txtVal) = (yyvsp[0].txtVal); }
#line 1887 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 58:
#line 225 "compilador.y" /* yacc.c:1648  */
    { (yyval.numVal) = (yyvsp[-2].numVal) + (yyvsp[0].numVal); }
#line 1893 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 59:
#line 226 "compilador.y" /* yacc.c:1648  */
    { (yyval.numVal) = (yyvsp[-2].numVal) - (yyvsp[0].numVal); }
#line 1899 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 60:
#line 227 "compilador.y" /* yacc.c:1648  */
    { (yyval.numVal) = (yyvsp[-2].numVal) / (yyvsp[0].numVal); }
#line 1905 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 61:
#line 228 "compilador.y" /* yacc.c:1648  */
    { (yyval.numVal) = (yyvsp[-2].numVal) * (yyvsp[0].numVal); }
#line 1911 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 62:
#line 230 "compilador.y" /* yacc.c:1648  */
    {
    if(!atribucaoValida("number")) {
        erroAtribuicao("number", floatToAscii((yyvsp[0].numVal)));
    }
}
#line 1921 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 63:
#line 235 "compilador.y" /* yacc.c:1648  */
    {
    if(!atribucaoValida("text")) {
        erroAtribuicao("text", (yyvsp[0].txtVal));
    }
}
#line 1931 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 67:
#line 244 "compilador.y" /* yacc.c:1648  */
    { yyerror("Erro: atribuindo um valor a outro"); }
#line 1937 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 68:
#line 245 "compilador.y" /* yacc.c:1648  */
    {}
#line 1943 "compilador.tab.c" /* yacc.c:1648  */
    break;

  case 69:
#line 247 "compilador.y" /* yacc.c:1648  */
    {
    if(!existeId((yyvsp[-3].txtVal))) {
		salvarIdentificador((yyvsp[-3].txtVal), obterTiposDeDados());
    } else {
		erroIdentificadorDuplicado((yyvsp[-3].txtVal));
    }
}
#line 1955 "compilador.tab.c" /* yacc.c:1648  */
    break;


#line 1959 "compilador.tab.c" /* yacc.c:1648  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 258 "compilador.y" /* yacc.c:1907  */


int main() {
    yyparse();
    printf("Sem erros!!\n");
    return 0;
}
