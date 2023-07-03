/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"


    #include "hw3_output.hpp"
    #include <iostream>
    #include <stdlib.h>
    #include "types.hpp"
    #include "symbol_table.hpp"
    #include "bp.hpp"
    #include "code_generator.hpp"

    using namespace output;
    using std::vector;

    extern int yylex();
    extern int yylineno;
    
    int yyerror(const char * message);

    TablesStack* tables_stack = &(TablesStack::getTablesStack());
    CodeBuffer* code_buffer = &(CodeBuffer::instance());
    CodeGenerator* code_generator;

#line 94 "parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_BYTE = 5,                       /* BYTE  */
  YYSYMBOL_B = 6,                          /* B  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_OVERRIDE = 8,                   /* OVERRIDE  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_NUM = 20,                       /* NUM  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_RELOP = 25,                     /* RELOP  */
  YYSYMBOL_BINOP = 26,                     /* BINOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_SC = 30,                        /* SC  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_Funcs = 34,                     /* Funcs  */
  YYSYMBOL_FuncDecl = 35,                  /* FuncDecl  */
  YYSYMBOL_36_1 = 36,                      /* @1  */
  YYSYMBOL_OverRide = 37,                  /* OverRide  */
  YYSYMBOL_RetType = 38,                   /* RetType  */
  YYSYMBOL_Formals = 39,                   /* Formals  */
  YYSYMBOL_FormalsList = 40,               /* FormalsList  */
  YYSYMBOL_FormalDecl = 41,                /* FormalDecl  */
  YYSYMBOL_Statements = 42,                /* Statements  */
  YYSYMBOL_Statement = 43,                 /* Statement  */
  YYSYMBOL_Call = 44,                      /* Call  */
  YYSYMBOL_ExpList = 45,                   /* ExpList  */
  YYSYMBOL_Type = 46,                      /* Type  */
  YYSYMBOL_Exp = 47,                       /* Exp  */
  YYSYMBOL_N = 48,                         /* N  */
  YYSYMBOL_OpenScope = 49,                 /* OpenScope  */
  YYSYMBOL_WhileScope = 50,                /* WhileScope  */
  YYSYMBOL_CloseScope = 51                 /* CloseScope  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    48,    49,    51,    51,    70,    71,    73,
      77,    79,    80,    82,    87,    95,   105,   112,   117,   122,
     133,   156,   173,   178,   186,   195,   205,   216,   226,   234,
     243,   258,   271,   277,   284,   285,   286,   288,   293,   305,
     315,   320,   325,   334,   339,   343,   347,   356,   366,   376,
     388,   400,   405,   406,   407
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "BYTE",
  "B", "BOOL", "OVERRIDE", "TRUE", "FALSE", "RETURN", "IF", "WHILE",
  "BREAK", "CONTINUE", "COMMA", "LBRACE", "RBRACE", "ID", "NUM", "STRING",
  "ASSIGN", "OR", "AND", "RELOP", "BINOP", "NOT", "LPAREN", "RPAREN", "SC",
  "ELSE", "$accept", "Program", "Funcs", "FuncDecl", "@1", "OverRide",
  "RetType", "Formals", "FormalsList", "FormalDecl", "Statements",
  "Statement", "Call", "ExpList", "Type", "Exp", "N", "OpenScope",
  "WhileScope", "CloseScope", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -79,     6,   -79,     7,   186,   -79,   -79,   -79,   -79,
     -79,   -79,   -10,   -79,   -12,   190,   -79,   -79,     5,     8,
       0,   190,   -79,    15,   -79,   -79,   124,    51,    21,    23,
       4,    25,   -79,    20,    92,   -79,    37,    50,   -79,   -79,
      52,    83,   -79,    67,    26,   -79,   -79,   121,    67,    67,
     -79,   -79,   124,    67,    64,   -79,   -79,   -79,    -5,   -79,
     -79,    53,   145,    67,    67,    67,    67,   -79,   152,   159,
     108,   129,   -79,    61,   -13,    67,   -79,    67,   -79,    76,
      38,    72,   -79,   -79,   -79,   -79,   -79,   -79,    67,   137,
     -79,   124,   124,   -79,   -79,   -79,   -79,   -79,    77,   -79,
     -79,   124,   -79,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     8,     0,     2,     7,     0,     1,     4,    10,    34,
      35,    36,     0,     9,     0,    11,     5,    12,    13,     0,
       0,     0,    15,     0,    14,    51,     0,     0,     0,     0,
       0,     0,    52,     0,     0,    16,     0,     0,    44,    45,
      39,    41,    43,     0,     0,    23,    40,     0,     0,     0,
      28,    29,     0,     0,     0,     6,    17,    22,     0,    42,
      46,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    31,     0,    32,     0,    19,     0,    37,    48,
      47,    49,    38,    52,    53,    54,    21,    30,     0,     0,
      50,     0,     0,    18,    33,    20,    54,    54,    25,    27,
      52,     0,    54,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   110,   -79,   -79,   -79,   -79,   -79,    95,   -79,
      65,   -33,   -26,    30,    -1,   -25,   -79,   -78,   -79,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    20,     5,    12,    16,    17,    18,
      34,    35,    46,    73,    37,    74,    26,    52,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    56,    47,    88,    13,    91,     6,    -3,    36,    14,
      63,    64,    65,    66,    19,     1,    15,    75,    60,    62,
      19,    21,   101,    68,    69,    76,    36,    22,    71,    23,
       9,    10,    25,    11,    50,    38,    39,    56,    79,    80,
      81,    82,    53,    61,    36,    40,    41,    42,    54,    48,
      89,    49,    90,    43,    44,    51,    98,    99,    96,    97,
      38,    39,   103,    65,    66,    36,    36,    57,   102,    58,
      40,    41,    42,    38,    39,    36,    38,    39,    43,    44,
      54,    45,    77,    40,    41,    42,    40,    41,    42,    59,
      87,    43,    44,    72,    43,    44,     9,    10,    66,    11,
      64,    65,    66,    27,    28,    29,    30,    31,   100,    32,
      55,    33,     9,    10,     7,    11,    24,    70,    94,    27,
      28,    29,    30,    31,     0,    32,    85,    33,     9,    10,
       0,    11,     0,     0,     0,    27,    28,    29,    30,    31,
       0,    32,     0,    33,    63,    64,    65,    66,     0,     0,
       0,    67,    63,    64,    65,    66,     0,     0,     0,    86,
      63,    64,    65,    66,     0,     0,     0,    95,    63,    64,
      65,    66,     0,     0,    78,    63,    64,    65,    66,     0,
       0,    83,    63,    64,    65,    66,     0,     0,    84,     8,
       9,    10,     0,    11,     9,    10,     0,    11
};

static const yytype_int8 yycheck[] =
{
      26,    34,    27,    16,     5,    83,     0,     0,    34,    19,
      23,    24,    25,    26,    15,     8,    28,    22,    43,    44,
      21,    16,   100,    48,    49,    30,    52,    19,    53,    29,
       4,     5,    17,     7,    30,     9,    10,    70,    63,    64,
      65,    66,    22,    44,    70,    19,    20,    21,    28,    28,
      75,    28,    77,    27,    28,    30,    96,    97,    91,    92,
       9,    10,   102,    25,    26,    91,    92,    30,   101,    19,
      19,    20,    21,     9,    10,   101,     9,    10,    27,    28,
      28,    30,    29,    19,    20,    21,    19,    20,    21,     6,
      29,    27,    28,    29,    27,    28,     4,     5,    26,     7,
      24,    25,    26,    11,    12,    13,    14,    15,    31,    17,
      18,    19,     4,     5,     4,     7,    21,    52,    88,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      -1,    17,    -1,    19,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    23,    24,
      25,    26,    -1,    -1,    29,    23,    24,    25,    26,    -1,
      -1,    29,    23,    24,    25,    26,    -1,    -1,    29,     3,
       4,     5,    -1,     7,     4,     5,    -1,     7
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    33,    34,    35,    37,     0,    34,     3,     4,
       5,     7,    38,    46,    19,    28,    39,    40,    41,    46,
      36,    16,    19,    29,    40,    17,    48,    11,    12,    13,
      14,    15,    17,    19,    42,    43,    44,    46,     9,    10,
      19,    20,    21,    27,    28,    30,    44,    47,    28,    28,
      30,    30,    49,    22,    28,    18,    43,    30,    19,     6,
      47,    46,    47,    23,    24,    25,    26,    30,    47,    47,
      42,    47,    29,    45,    47,    22,    30,    29,    29,    47,
      47,    47,    47,    29,    29,    18,    30,    29,    16,    47,
      47,    49,    50,    51,    45,    30,    43,    43,    51,    51,
      31,    49,    43,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    36,    35,    37,    37,    38,
      38,    39,    39,    40,    40,    41,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    49,    50,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,    11,     0,     1,     1,
       1,     0,     1,     1,     3,     2,     1,     2,     5,     3,
       5,     4,     2,     2,     3,     7,    11,     7,     2,     2,
       4,     3,     1,     3,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     2,     3,     3,     3,
       4,     0,     0,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* Program: Funcs  */
#line 38 "parser.ypp"
                      { 
                    if (!tables_stack->mainExists()) {
                        errorMainMissing();
                        exit(1);
                    }
                    tables_stack->closeScope();
                    code_generator->getCodeBuffer()->printGlobalBuffer();
                    code_generator->getCodeBuffer()->printCodeBuffer();
                    exit(0);
                }
#line 1231 "parser.tab.cpp"
    break;

  case 3: /* Funcs: %empty  */
#line 48 "parser.ypp"
                    { }
#line 1237 "parser.tab.cpp"
    break;

  case 4: /* Funcs: FuncDecl Funcs  */
#line 49 "parser.ypp"
                               { }
#line 1243 "parser.tab.cpp"
    break;

  case 5: /* @1: %empty  */
#line 51 "parser.ypp"
                                                   {
                    OverrideNode* override = (OverrideNode*)yyvsp[-4];
                    RetTypeNode* returnType = (RetTypeNode*)yyvsp[-3];
                    IdNode* id = (IdNode*)yyvsp[-2];
                    id->type = returnType->type;
                    FormalsNode* formals = (FormalsNode*)yyvsp[0];
                    int counter = 0;
                    int res = tables_stack->declFunc(id->name, returnType->type, formals, override->isOverride, yylineno, &counter);
                    if(res == -1) {
                        exit(1);
                    }

                    yyval = new FuncDeclNode(returnType->type, id->name, counter, formals->declarations);
                    code_generator->startFunc((FuncDeclNode*)yyval, counter);
                }
#line 1263 "parser.tab.cpp"
    break;

  case 6: /* FuncDecl: OverRide RetType ID LPAREN Formals @1 RPAREN LBRACE N Statements RBRACE  */
#line 65 "parser.ypp"
                                                    {
                    tables_stack->curr_func_type = NULL_TYPE;
                    code_generator->endFunc((RetTypeNode*)yyvsp[-9], (StatementsNode*)yyvsp[-1], (MarkerNode*)yyvsp[-2]); // check if statements is $10 or $9
                    tables_stack->closeScope();   
                }
#line 1273 "parser.tab.cpp"
    break;

  case 7: /* OverRide: %empty  */
#line 70 "parser.ypp"
                    { yyval = new OverrideNode(); }
#line 1279 "parser.tab.cpp"
    break;

  case 8: /* OverRide: OVERRIDE  */
#line 71 "parser.ypp"
                         { yyval = new OverrideNode(true); }
#line 1285 "parser.tab.cpp"
    break;

  case 9: /* RetType: Type  */
#line 73 "parser.ypp"
                     { 
                    TypeNode* type = (TypeNode*)yyvsp[0];
                    yyval = new RetTypeNode(type->type);
                }
#line 1294 "parser.tab.cpp"
    break;

  case 10: /* RetType: VOID  */
#line 77 "parser.ypp"
                     { yyval = new RetTypeNode(TYPE_VOID); }
#line 1300 "parser.tab.cpp"
    break;

  case 11: /* Formals: %empty  */
#line 79 "parser.ypp"
                    { yyval = new FormalsNode(); }
#line 1306 "parser.tab.cpp"
    break;

  case 12: /* Formals: FormalsList  */
#line 80 "parser.ypp"
                            { yyval = new FormalsNode(((FormalsListNode*)yyvsp[0])->declarations); }
#line 1312 "parser.tab.cpp"
    break;

  case 13: /* FormalsList: FormalDecl  */
#line 82 "parser.ypp"
                           { 
                    vector<FormalDeclNode*> vec;
                    vec.insert(vec.begin(), (FormalDeclNode*)yyvsp[0]);
                    yyval = new FormalsListNode(vec);
                }
#line 1322 "parser.tab.cpp"
    break;

  case 14: /* FormalsList: FormalDecl COMMA FormalsList  */
#line 87 "parser.ypp"
                                             { 
                    FormalDeclNode* formal_dec = (FormalDeclNode*)yyvsp[-2];
                    FormalsListNode* formal_list = (FormalsListNode*)yyvsp[0];
                    formal_list->declarations.insert(formal_list->declarations.begin(), formal_dec);

                    yyval = new FormalsListNode(formal_list->declarations);
                }
#line 1334 "parser.tab.cpp"
    break;

  case 15: /* FormalDecl: Type ID  */
#line 95 "parser.ypp"
                        { 
                    TypeNode* type = (TypeNode*)yyvsp[-1];
                    IdNode* id = (IdNode*)yyvsp[0];
                    if (tables_stack->isInCurrScope(id->name)) {
                        errorDef(yylineno, id->name);
                        exit(1);
                    }
                    id->var = code_generator->freshVar();
                    yyval = new FormalDeclNode(type->type, id->name, id->var);
                }
#line 1349 "parser.tab.cpp"
    break;

  case 16: /* Statements: Statement  */
#line 105 "parser.ypp"
                          { 
                    StatementNode* s = (StatementNode*)yyvsp[0];
                    vector<StatementNode*> s_list;
                    s_list.push_back(s);
                    yyval = new StatementsNode(s_list);
                    code_generator->processFirstStatement((StatementsNode*)yyval, s);
                }
#line 1361 "parser.tab.cpp"
    break;

  case 17: /* Statements: Statements Statement  */
#line 112 "parser.ypp"
                                     { 
                    yyval = (StatementsNode*)yyvsp[-1];
                    code_generator->processStatements((StatementsNode*)yyval, (StatementNode*)yyvsp[0]);
                }
#line 1370 "parser.tab.cpp"
    break;

  case 18: /* Statement: LBRACE OpenScope Statements RBRACE CloseScope  */
#line 117 "parser.ypp"
                                                              { 
                    StatementsNode* statements = (StatementsNode*)yyvsp[-2];
                    yyval = new StatementNode();
                    code_generator->processEndStatement((StatementNode*)(yyval), statements);
                }
#line 1380 "parser.tab.cpp"
    break;

  case 19: /* Statement: Type ID SC  */
#line 122 "parser.ypp"
                           { 
                    TypeNode* type = (TypeNode*)yyvsp[-2];
                    IdNode* id = (IdNode*)yyvsp[-1];
                    if (tables_stack->symbDeclared(id->name)) {
                        errorDef(yylineno, id->name);
                        exit(1);
                    }
                    yyval = new StatementNode();
                    code_generator->initVar(id, (StatementNode*)yyval, type->type, tables_stack->offset_stack.top());
                    tables_stack->declVar(id->name, type->type, id->var);
                 }
#line 1396 "parser.tab.cpp"
    break;

  case 20: /* Statement: Type ID ASSIGN Exp SC  */
#line 133 "parser.ypp"
                                      { 
                    TypeNode* type = (TypeNode*)yyvsp[-4];
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if (tables_stack->symbDeclared(id->name)) {
                        errorDef(yylineno, id->name);
                        exit(1);
                    }
                    else {
                        if (AssignLegality(type->type, exp->type)) {
                            id->var = exp->var;
                            id->type = type->type;
                            exp->value = id->name;
                            tables_stack->declVar(id->name, type->type, id->var);
                        }
                        else {
                            errorMismatch(yylineno);
                            exit(1);
                        }
                    }
                    yyval = new StatementNode();
                    code_generator->storeVar(exp, (StatementNode*)yyval, tables_stack->offset_stack.top());
                }
#line 1424 "parser.tab.cpp"
    break;

  case 21: /* Statement: ID ASSIGN Exp SC  */
#line 156 "parser.ypp"
                                 { 
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if (!tables_stack->symbDeclared(id->name)) {
                        errorUndef(yylineno, id->name);
                        exit(1);
                    }
                    TypesEnum type = tables_stack->getIdType(id->name);
                    if (!AssignLegality(type, exp->type)) {
                            errorMismatch(yylineno);
                            exit(1);
                    }
                    exp->value = id->name;
                    int offset = tables_stack->getIdOffset(id->name);
                    yyval = new StatementNode();
                    code_generator->storeVar(exp, (StatementNode*)yyval, offset);    
                }
#line 1446 "parser.tab.cpp"
    break;

  case 22: /* Statement: Call SC  */
#line 173 "parser.ypp"
                        { 
                    CallNode* call = (CallNode*)yyvsp[-1];
                    yyval = new StatementNode();
                    code_generator->processStatementCall((StatementNode*)yyval, call);
                }
#line 1456 "parser.tab.cpp"
    break;

  case 23: /* Statement: RETURN SC  */
#line 178 "parser.ypp"
                          { 
                    if(tables_stack->curr_func_type != TYPE_VOID) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new StatementNode();
                    code_generator->processReturn((StatementNode*)yyval);
                }
#line 1469 "parser.tab.cpp"
    break;

  case 24: /* Statement: RETURN Exp SC  */
#line 186 "parser.ypp"
                              { 
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if(!AssignLegality(tables_stack->curr_func_type, exp->type)) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new StatementNode();
                    code_generator->processReturn((StatementNode*)yyval, exp);
                }
#line 1483 "parser.tab.cpp"
    break;

  case 25: /* Statement: IF LPAREN Exp RPAREN OpenScope Statement CloseScope  */
#line 195 "parser.ypp"
                                                                    { 
                    ExpNode* exp = (ExpNode*)yyvsp[-4];
                    if(exp->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    StatementNode* statement = (StatementNode*)yyvsp[-1];
                    yyval = new StatementNode();
                    code_generator->processIfElse((StatementNode*)yyval, exp, statement);
                }
#line 1498 "parser.tab.cpp"
    break;

  case 26: /* Statement: IF LPAREN Exp RPAREN OpenScope Statement CloseScope ELSE OpenScope Statement CloseScope  */
#line 205 "parser.ypp"
                                                                                                        { 
                    ExpNode* exp = (ExpNode*)yyvsp[-8];
                    if(exp->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    StatementNode* if_statement = (StatementNode*)yyvsp[-5];
                    StatementNode* else_statement = (StatementNode*)yyvsp[-1];
                    yyval = new StatementNode();
                    code_generator->processIfElse((StatementNode*)yyval, exp, if_statement, else_statement);
                }
#line 1514 "parser.tab.cpp"
    break;

  case 27: /* Statement: WHILE LPAREN Exp RPAREN WhileScope Statement CloseScope  */
#line 216 "parser.ypp"
                                                                        {
                    ExpNode* exp = (ExpNode*)yyvsp[-4];
                    if(exp->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    StatementNode* statement = (StatementNode*)yyvsp[-1];
                    yyval = new StatementNode();
                    code_generator->processWhile((StatementNode*)yyval, exp, statement);
                }
#line 1529 "parser.tab.cpp"
    break;

  case 28: /* Statement: BREAK SC  */
#line 226 "parser.ypp"
                         { 
                    if(!tables_stack->isCurrScopeInWhile()) {
                        errorUnexpectedBreak(yylineno);
                        exit(1);
                    }
                    yyval = new StatementNode();
                    code_generator->processBreakContinue((StatementNode*)yyval, true);
                }
#line 1542 "parser.tab.cpp"
    break;

  case 29: /* Statement: CONTINUE SC  */
#line 234 "parser.ypp"
                            {
                    if(!tables_stack->isCurrScopeInWhile()) {
                        errorUnexpectedContinue(yylineno);
                        exit(1);
                    }
                    yyval = new StatementNode();
                    code_generator->processBreakContinue((StatementNode*)yyval);
                }
#line 1555 "parser.tab.cpp"
    break;

  case 30: /* Call: ID LPAREN ExpList RPAREN  */
#line 243 "parser.ypp"
                                         {
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpListNode* expr_list = (ExpListNode*)yyvsp[-1];
                    if(!tables_stack->symbDeclared(id->name, true)) {
                        errorUndefFunc(yylineno, id->name);
                        exit(1);
                    }
                    int res = tables_stack->checkFuncParams(id->name, expr_list->exprs, yylineno);
                    if(res == -1) {
                        exit(1);
                    }
                    int counter = tables_stack->getFuncCounter(id->name, expr_list->exprs);
                    yyval = new CallNode(tables_stack->getFuncType(id->name, expr_list->exprs), id->name, counter);
                    code_generator->processCall((CallNode*)yyval, expr_list->exprs);
                }
#line 1575 "parser.tab.cpp"
    break;

  case 31: /* Call: ID LPAREN RPAREN  */
#line 258 "parser.ypp"
                                 { 
                    IdNode* id = (IdNode*)yyvsp[-2];
                    if(!tables_stack->symbDeclared(id->name, true)){
                        errorUndefFunc(yylineno, id->name);
                        exit(1);
                    }
                    tables_stack->checkFuncParams(id->name, yylineno);
                    vector<ExpNode*> exprs;
                    int counter = tables_stack->getFuncCounter(id->name);
                    yyval = new CallNode(tables_stack->getFuncType(id->name, exprs), id->name, counter);
                    code_generator->processCall((CallNode*)yyval);
                }
#line 1592 "parser.tab.cpp"
    break;

  case 32: /* ExpList: Exp  */
#line 271 "parser.ypp"
                    { 
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    vector<ExpNode*> exps;
                    exps.insert(exps.begin(), exp);
                    yyval = new ExpListNode(exps);
                }
#line 1603 "parser.tab.cpp"
    break;

  case 33: /* ExpList: Exp COMMA ExpList  */
#line 277 "parser.ypp"
                                  { 
                    ExpNode* exp = (ExpNode*)yyvsp[-2];
                    ExpListNode* expr_list = (ExpListNode*)yyvsp[0];
                    expr_list->exprs.insert(expr_list->exprs.begin(), exp);
                    yyval = new ExpListNode(expr_list->exprs);
                }
#line 1614 "parser.tab.cpp"
    break;

  case 34: /* Type: INT  */
#line 284 "parser.ypp"
                    { yyval = new TypeNode(TYPE_INT); }
#line 1620 "parser.tab.cpp"
    break;

  case 35: /* Type: BYTE  */
#line 285 "parser.ypp"
                     { yyval = new TypeNode(TYPE_BYTE); }
#line 1626 "parser.tab.cpp"
    break;

  case 36: /* Type: BOOL  */
#line 286 "parser.ypp"
                     { yyval = new TypeNode(TYPE_BOOL); }
#line 1632 "parser.tab.cpp"
    break;

  case 37: /* Exp: LPAREN Exp RPAREN  */
#line 288 "parser.ypp"
                                  { 
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    yyval = new ExpNode(exp->type); 
                    code_generator->processParentheses((ExpNode*)yyval, exp);
                }
#line 1642 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp BINOP Exp  */
#line 293 "parser.ypp"
                              {
                    ExpNode* first = (ExpNode*)yyvsp[-2];
                    BinopNode* binop = (BinopNode*)yyvsp[-1];
                    ExpNode* second = (ExpNode*)yyvsp[0];
                    TypesEnum type = SumType(first->type, second->type);
                    if (type == NULL_TYPE) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(type);
                    code_generator->processBinop((ExpNode*)yyval, first, second, binop->binop);
                }
#line 1659 "parser.tab.cpp"
    break;

  case 39: /* Exp: ID  */
#line 305 "parser.ypp"
                   { 
                    IdNode* id = (IdNode*)yyvsp[0];
                    if(!tables_stack->symbDeclared(id->name)) {
                            errorUndef(yylineno, id->name);
                            exit(1);
                    }
                    yyval = new ExpNode(tables_stack->getIdType(id->name));
                    int offset = tables_stack->getIdOffset(id->name);
                    code_generator->loadVar((ExpNode*)yyval, offset);
                }
#line 1674 "parser.tab.cpp"
    break;

  case 40: /* Exp: Call  */
#line 315 "parser.ypp"
                     { 
                    CallNode* call = (CallNode*)yyvsp[0];
                    yyval = new ExpNode(call->type); 
                    code_generator->processExpCall((ExpNode*)yyval, call);
                }
#line 1684 "parser.tab.cpp"
    break;

  case 41: /* Exp: NUM  */
#line 320 "parser.ypp"
                    { 
                    NumNode* num = (NumNode*)yyvsp[0];
                    yyval = new ExpNode(TYPE_INT, code_generator->freshVar());
                    code_generator->processExpNum((ExpNode*)yyval, num);
                }
#line 1694 "parser.tab.cpp"
    break;

  case 42: /* Exp: NUM B  */
#line 325 "parser.ypp"
                      { 
                    NumNode* num = (NumNode*)yyvsp[-1];
                    if(std::stoi(num->num_val) > 255) {
                        errorByteTooLarge(yylineno, num->num_val);
                        exit(1);
                    }
                    yyval = new ExpNode(TYPE_BYTE, code_generator->freshVar());
                    code_generator->processExpNum((ExpNode*)yyval, num);
                }
#line 1708 "parser.tab.cpp"
    break;

  case 43: /* Exp: STRING  */
#line 334 "parser.ypp"
                       { 
                    StringNode* str = (StringNode*)yyvsp[0];
                    yyval = new ExpNode(TYPE_STRING); 
                    code_generator->processExpString((ExpNode*)yyval, str);
                }
#line 1718 "parser.tab.cpp"
    break;

  case 44: /* Exp: TRUE  */
#line 339 "parser.ypp"
                     { 
                    yyval = new ExpNode(TYPE_BOOL, code_generator->freshVar());
                    code_generator->processTrueOrFalse((ExpNode*)yyval, true); 
                }
#line 1727 "parser.tab.cpp"
    break;

  case 45: /* Exp: FALSE  */
#line 343 "parser.ypp"
                      { 
                    yyval = new ExpNode(TYPE_BOOL, code_generator->freshVar());
                    code_generator->processTrueOrFalse((ExpNode*)yyval); 
                }
#line 1736 "parser.tab.cpp"
    break;

  case 46: /* Exp: NOT Exp  */
#line 347 "parser.ypp"
                        { 
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    if(exp->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(TYPE_BOOL);
                    code_generator->processNot((ExpNode*)yyval, exp);
                }
#line 1750 "parser.tab.cpp"
    break;

  case 47: /* Exp: Exp AND Exp  */
#line 356 "parser.ypp"
                            { 
                    ExpNode* first = (ExpNode*)yyvsp[-2];
                    ExpNode* second = (ExpNode*)yyvsp[0];
                    if(first->type != TYPE_BOOL || second->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(TYPE_BOOL);
                    code_generator->processAnd((ExpNode*)yyval, first, second);
                }
#line 1765 "parser.tab.cpp"
    break;

  case 48: /* Exp: Exp OR Exp  */
#line 366 "parser.ypp"
                           { 
                    ExpNode* first = (ExpNode*)yyvsp[-2];
                    ExpNode* second = (ExpNode*)yyvsp[0];
                    if(first->type != TYPE_BOOL || second->type != TYPE_BOOL) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(TYPE_BOOL);
                    code_generator->processOr((ExpNode*)yyval, first, second);
                }
#line 1780 "parser.tab.cpp"
    break;

  case 49: /* Exp: Exp RELOP Exp  */
#line 376 "parser.ypp"
                              {
                    ExpNode* first = (ExpNode*)yyvsp[-2];
                    RelopNode* relop = (RelopNode*)yyvsp[-1];
                    ExpNode* second = (ExpNode*)yyvsp[0];
                    TypesEnum type = SumType(first->type, second->type);
                    if (type == NULL_TYPE) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(TYPE_BOOL);
                    code_generator->processRelop((ExpNode*)yyval, first, second, relop->relop);
                }
#line 1797 "parser.tab.cpp"
    break;

  case 50: /* Exp: LPAREN Type RPAREN Exp  */
#line 388 "parser.ypp"
                                       {
                    TypeNode* type = (TypeNode*)yyvsp[-2];
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    if(!ConversionLegality(exp->type , type->type)) {
                        errorMismatch(yylineno);
                        exit(1);
                    }
                    yyval = new ExpNode(type->type, code_generator->freshVar());
                    code_generator->processConvertion((ExpNode*)yyval, exp);
                }
#line 1812 "parser.tab.cpp"
    break;

  case 51: /* N: %empty  */
#line 400 "parser.ypp"
                { 
                    List next_list = code_generator->getCodeBuffer()->makelist(pair<int, BranchLabelIndex>(code_generator->getCodeBuffer()->emit("br label @"), FIRST));
                    yyval = new MarkerNode(next_list);
                }
#line 1821 "parser.tab.cpp"
    break;

  case 52: /* OpenScope: %empty  */
#line 405 "parser.ypp"
                { tables_stack->openScope(); }
#line 1827 "parser.tab.cpp"
    break;

  case 53: /* WhileScope: %empty  */
#line 406 "parser.ypp"
                { tables_stack->openScope(true); }
#line 1833 "parser.tab.cpp"
    break;

  case 54: /* CloseScope: %empty  */
#line 407 "parser.ypp"
                { tables_stack->closeScope(); }
#line 1839 "parser.tab.cpp"
    break;


#line 1843 "parser.tab.cpp"

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
      yyerror (YY_("syntax error"));
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 408 "parser.ypp"


int main()
{
    tables_stack->Init();
    code_generator = new CodeGenerator(code_buffer);
    code_generator->emitPrint();
	yyparse();
}

int yyerror(const char * message)
{
	errorSyn(yylineno);
	exit(1);
}
