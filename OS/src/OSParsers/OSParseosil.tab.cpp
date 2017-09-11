/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         osilparse
#define yylex           osillex
#define yyerror         osilerror
#define yydebug         osildebug
#define yynerrs         osilnerrs


/* Copy the first part of user declarations.  */



#include <string>
#include <iostream>
#include <sstream>  
#include <algorithm>
 
#include "OSInstance.h" 
#include "OSGeneral.h" 
#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSiLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "OSConfig.h"

#define OSINSTANCE_AVAILABLE

//#define CHECK_PARSE_TIME

// debugging tools. uncomment as needed 
#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif


#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osil_scan_string (const char *yy_str , void* yyscanner  );
int osillex_init(void** ptr_yy_globals);
int osillex_destroy (void* yyscanner );
void osilset_extra (OSiLParserData* parserData , void* yyscanner );
int osilget_lineno( void* yyscanner);
char *osilget_text (void* yyscanner );
void osilset_lineno (int line_number , void* yyscanner );
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass);
void osil_empty_vectors( OSiLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);

//

double atofmod1(int* osillineno, const char *ch1, const char *ch2 );
int atoimod1(int* osillineno, const char *ch1, const char *ch2);
// we distinguish a newline from other whitespace
// so that we can report proper line numbers in case of error
void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg);
bool isnewline(char c, int* osillineno);
bool parseVariables(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseObjectives(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseObjCoef(const char **pchar, int objcount, OSInstance *osinstance, int* osillineno);
bool parseConstraints(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseLinearConstraintCoefficients(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseStart(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseRowIdx(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseColIdx(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseValue(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseInstanceHeader(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseInstanceData( const char **pchar, OSInstance *osinstance, int* osillineno);
char *parseBase64( const char **p, long int *dataSize, int* osillineno);

#define ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define BURNWHITESPACE( X ) for(; ISWHITESPACE( *X) || isnewline( *X, osillineno); X++ )

#define FINDNEXTTAG( X )         \
    BURNWHITESPACE( X );                                                 \
    while(*X == '<' && *(X+1) == '!' && *(X+2) == '-' && *(X+3) == '-')  \
    {                                                                    \
        X += 4;                                                          \
        while (*X != '-' || *(X+1) != '-' || *(X+2) != '>')              \
            X++;                                                         \
        X += 3;                                                          \
        BURNWHITESPACE( X );                                             \
    }                                                 

#define ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  \
    BURNWHITESPACE( ch ); \
    if( *ch != '=') {  osilerror_wrapper( ch, osillineno, "found an attribute not defined"); return false;}  \
    ch++; \
    BURNWHITESPACE( ch ); \
    if(*ch == '\"'){ \
        ch++; \
        BURNWHITESPACE( ch ); \
        *p = ch; \
        for( ; *ch != '\"'; ch++); \
    }\
    else{\
        if(*ch == '\'') { \
            ch++; \
            BURNWHITESPACE( ch ); \
            *p = ch; \
            for( ; *ch != '\''; ch++); \
        } \
        else {  osilerror_wrapper( ch, osillineno,"missing quote on attribute"); return false;} \
    }\
    numChar = ch - *p; \
    attText = new char[numChar + 1]; \
    for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++); \
    attText[ki] = '\0'; \
    attTextEnd = &attText[ki]; 

    
#define GAIL printf("GAIL ANN HONDA\n")
    
#define ECHOCHECK \
    GAIL; \
    printf("%c", ch[-2]); \
    printf("%c", ch[-1]); \
    printf("%c", ch[0]); \
    printf("%c", ch[1]); \
    printf("%c", ch[2]); \
    printf("%c", ch[3]); \
    printf("%c", ch[4]); \
    printf("%c", ch[5]); \
    printf("%c \n", ch[6]); \
    GAIL;



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
   by #include "OSParseosil.tab.hpp".  */
#ifndef YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED
# define YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int osildebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ATTRIBUTETEXT = 258,
    ELEMENTTEXT = 259,
    ITEMTEXT = 260,
    INTEGER = 261,
    DOUBLE = 262,
    QUOTE = 263,
    TWOQUOTES = 264,
    BOOLEAN = 265,
    ENDOFELEMENT = 266,
    GREATERTHAN = 267,
    EMPTYSEMIDEFINITENESSATT = 268,
    SEMIDEFINITENESSATT = 269,
    NUMBEROFQTERMSATT = 270,
    NUMBEROFCONESATT = 271,
    NUMBEROFSTAGESATT = 272,
    IDXONEATT = 273,
    IDXTWOATT = 274,
    HORIZONATT = 275,
    STARTATT = 276,
    STARTIDXATT = 277,
    MATRIXIDXATT = 278,
    LBMATRIXIDXATT = 279,
    LBCONEIDXATT = 280,
    UBMATRIXIDXATT = 281,
    UBCONEIDXATT = 282,
    TEMPLATEMATRIXIDXATT = 283,
    REFERENCEMATRIXIDXATT = 284,
    VARREFERENCEMATRIXIDXATT = 285,
    OBJREFERENCEMATRIXIDXATT = 286,
    CONREFERENCEMATRIXIDXATT = 287,
    ORDERCONEIDXATT = 288,
    CONSTANTMATRIXIDXATT = 289,
    NORMSCALEFACTORATT = 290,
    DISTORTIONMATRIXIDXATT = 291,
    AXISDIRECTIONATT = 292,
    FIRSTAXISDIRECTIONATT = 293,
    SECONDAXISDIRECTIONATT = 294,
    OSILEND = 295,
    INSTANCEDATAEND = 296,
    INSTANCEDATASTARTEND = 297,
    QUADRATICCOEFFICIENTSSTART = 298,
    QUADRATICCOEFFICIENTSEND = 299,
    QTERMSTART = 300,
    QTERMEND = 301,
    CONESSTART = 302,
    CONESEND = 303,
    NONNEGATIVECONESTART = 304,
    NONNEGATIVECONEEND = 305,
    NONPOSITIVECONESTART = 306,
    NONPOSITIVECONEEND = 307,
    ORTHANTCONESTART = 308,
    ORTHANTCONEEND = 309,
    POLYHEDRALCONESTART = 310,
    POLYHEDRALCONEEND = 311,
    QUADRATICCONESTART = 312,
    QUADRATICCONEEND = 313,
    ROTATEDQUADRATICCONESTART = 314,
    ROTATEDQUADRATICCONEEND = 315,
    SEMIDEFINITECONESTART = 316,
    SEMIDEFINITECONEEND = 317,
    PRODUCTCONESTART = 318,
    PRODUCTCONEEND = 319,
    INTERSECTIONCONESTART = 320,
    INTERSECTIONCONEEND = 321,
    DUALCONESTART = 322,
    DUALCONEEND = 323,
    POLARCONESTART = 324,
    POLARCONEEND = 325,
    DIRECTIONSTART = 326,
    DIRECTIONEND = 327,
    FACTORSSTART = 328,
    FACTORSEND = 329,
    COMPONENTSSTART = 330,
    COMPONENTSEND = 331,
    TIMEDOMAINSTART = 332,
    TIMEDOMAINEND = 333,
    STAGESSTART = 334,
    STAGESEND = 335,
    STAGESTART = 336,
    STAGEEND = 337,
    INTERVALSTART = 338,
    INTERVALEND = 339,
    HEADERSTART = 340,
    HEADEREND = 341,
    FILENAMESTART = 342,
    FILENAMEEND = 343,
    FILENAMEEMPTY = 344,
    FILENAMESTARTANDEND = 345,
    FILESOURCESTART = 346,
    FILESOURCEEND = 347,
    FILESOURCEEMPTY = 348,
    FILESOURCESTARTANDEND = 349,
    FILEDESCRIPTIONSTART = 350,
    FILEDESCRIPTIONEND = 351,
    FILEDESCRIPTIONEMPTY = 352,
    FILEDESCRIPTIONSTARTANDEND = 353,
    FILECREATORSTART = 354,
    FILECREATOREND = 355,
    FILECREATOREMPTY = 356,
    FILECREATORSTARTANDEND = 357,
    FILELICENCESTART = 358,
    FILELICENCEEND = 359,
    FILELICENCEEMPTY = 360,
    FILELICENCESTARTANDEND = 361,
    INDEXESSTART = 362,
    INDEXESEND = 363,
    VALUESSTART = 364,
    VALUESEND = 365,
    NONZEROSSTART = 366,
    NONZEROSEND = 367,
    ELSTART = 368,
    ELEND = 369,
    ENUMERATIONSTART = 370,
    ENUMERATIONEND = 371,
    ITEMEMPTY = 372,
    ITEMSTART = 373,
    ITEMEND = 374,
    ITEMSTARTANDEND = 375,
    BASE64START = 376,
    BASE64END = 377,
    NUMBEROFELATT = 378,
    NUMBEROFENUMERATIONSATT = 379,
    NUMBEROFITEMSATT = 380,
    EMPTYCATEGORYATT = 381,
    CATEGORYATT = 382,
    EMPTYDESCRIPTIONATT = 383,
    DESCRIPTIONATT = 384,
    EMPTYSOLVERATT = 385,
    SOLVERATT = 386,
    EMPTYNAMEATT = 387,
    NAMEATT = 388,
    EMPTYTYPEATT = 389,
    TYPEATT = 390,
    EMPTYENUMTYPEATT = 391,
    ENUMTYPEATT = 392,
    EMPTYSHAPEATT = 393,
    SHAPEATT = 394,
    EMPTYUNITATT = 395,
    UNITATT = 396,
    EMPTYVALUEATT = 397,
    VALUEATT = 398,
    EMPTYVALUETYPEATT = 399,
    VALUETYPEATT = 400,
    EMPTYCONTYPEATT = 401,
    CONTYPEATT = 402,
    EMPTYOBJTYPEATT = 403,
    OBJTYPEATT = 404,
    EMPTYVARTYPEATT = 405,
    VARTYPEATT = 406,
    EMPTYMATRIXCONTYPEATT = 407,
    MATRIXCONTYPEATT = 408,
    EMPTYMATRIXOBJTYPEATT = 409,
    MATRIXOBJTYPEATT = 410,
    EMPTYMATRIXVARTYPEATT = 411,
    MATRIXVARTYPEATT = 412,
    EMPTYMATRIXTYPEATT = 413,
    MATRIXTYPEATT = 414,
    EMPTYSYMMETRYATT = 415,
    SYMMETRYATT = 416,
    EMPTYROWMAJORATT = 417,
    ROWMAJORATT = 418,
    EMPTYBASETRANSPOSEATT = 419,
    BASETRANSPOSEATT = 420,
    NUMBEROFBLOCKSATT = 421,
    NUMBEROFCOLUMNSATT = 422,
    NUMBEROFROWSATT = 423,
    NUMBEROFMATRICESATT = 424,
    NUMBEROFVALUESATT = 425,
    NUMBEROFCONSTRAINTSATT = 426,
    NUMBEROFCONATT = 427,
    NUMBEROFCONIDXATT = 428,
    NUMBEROFOBJECTIVESATT = 429,
    NUMBEROFOBJATT = 430,
    NUMBEROFOBJIDXATT = 431,
    NUMBEROFVARIABLESATT = 432,
    NUMBEROFVARATT = 433,
    NUMBEROFVARIDXATT = 434,
    NUMBEROFMATRIXCONATT = 435,
    NUMBEROFMATRIXOBJATT = 436,
    NUMBEROFMATRIXVARATT = 437,
    BASEMATRIXIDXATT = 438,
    TARGETMATRIXFIRSTROWATT = 439,
    TARGETMATRIXFIRSTCOLATT = 440,
    BASEMATRIXSTARTROWATT = 441,
    BASEMATRIXSTARTCOLATT = 442,
    BASEMATRIXENDROWATT = 443,
    BASEMATRIXENDCOLATT = 444,
    SCALARMULTIPLIERATT = 445,
    BLOCKROWIDXATT = 446,
    BLOCKCOLIDXATT = 447,
    REATT = 448,
    IMATT = 449,
    MATRIXVARIDXATT = 450,
    MATRIXOBJIDXATT = 451,
    MATRIXCONIDXATT = 452,
    IDXATT = 453,
    INCRATT = 454,
    MULTATT = 455,
    SIZEOFATT = 456,
    COEFATT = 457,
    CONSTANTATT = 458,
    MATRICESSTART = 459,
    MATRICESEND = 460,
    MATRIXSTART = 461,
    MATRIXEND = 462,
    BASEMATRIXEND = 463,
    BASEMATRIXSTART = 464,
    BLOCKSSTART = 465,
    BLOCKSEND = 466,
    BLOCKSTART = 467,
    BLOCKEND = 468,
    COLOFFSETSTART = 469,
    COLOFFSETEND = 470,
    ROWOFFSETSTART = 471,
    ROWOFFSETEND = 472,
    ELEMENTSSTART = 473,
    ELEMENTSEND = 474,
    CONSTANTELEMENTSSTART = 475,
    CONSTANTELEMENTSEND = 476,
    COMPLEXELEMENTSSTART = 477,
    COMPLEXELEMENTSEND = 478,
    VARREFERENCEELEMENTSSTART = 479,
    VARREFERENCEELEMENTSEND = 480,
    LINEARELEMENTSSTART = 481,
    LINEARELEMENTSEND = 482,
    CONREFERENCEELEMENTSSTART = 483,
    CONREFERENCEELEMENTSEND = 484,
    OBJREFERENCEELEMENTSSTART = 485,
    OBJREFERENCEELEMENTSEND = 486,
    REALVALUEDEXPRESSIONSSTART = 487,
    REALVALUEDEXPRESSIONSSEND = 488,
    COMPLEXVALUEDEXPRESSIONSSTART = 489,
    COMPLEXVALUEDEXPRESSIONSSEND = 490,
    STRINGVALUEDELEMENTSSTART = 491,
    STRINGVALUEDELEMENTSEND = 492,
    STARTVECTORSTART = 493,
    STARTVECTOREND = 494,
    INDEXSTART = 495,
    INDEXEND = 496,
    VALUESTART = 497,
    VALUEEND = 498,
    VARIDXSTART = 499,
    VARIDXEND = 500,
    TRANSFORMATIONSTART = 501,
    TRANSFORMATIONEND = 502,
    MATRIXPROGRAMMINGSTART = 503,
    MATRIXPROGRAMMINGEND = 504,
    MATRIXVARIABLESSTART = 505,
    MATRIXVARIABLESEND = 506,
    MATRIXVARSTART = 507,
    MATRIXVAREND = 508,
    MATRIXOBJECTIVESSTART = 509,
    MATRIXOBJECTIVESEND = 510,
    MATRIXOBJSTART = 511,
    MATRIXOBJEND = 512,
    MATRIXCONSTRAINTSSTART = 513,
    MATRIXCONSTRAINTSEND = 514,
    MATRIXCONSTART = 515,
    MATRIXCONEND = 516,
    CONSTART = 517,
    CONEND = 518,
    CONSTRAINTSSTART = 519,
    CONSTRAINTSEND = 520,
    OBJSTART = 521,
    OBJEND = 522,
    OBJECTIVESSTART = 523,
    OBJECTIVESEND = 524,
    VARSTART = 525,
    VAREND = 526,
    VARIABLESSTART = 527,
    VARIABLESEND = 528,
    GENERALSTART = 529,
    GENERALEND = 530,
    SYSTEMSTART = 531,
    SYSTEMEND = 532,
    SERVICESTART = 533,
    SERVICEEND = 534,
    JOBSTART = 535,
    JOBEND = 536,
    OPTIMIZATIONSTART = 537,
    OPTIMIZATIONEND = 538,
    ATEQUALITYSTART = 539,
    ATEQUALITYEND = 540,
    ATLOWERSTART = 541,
    ATLOWEREND = 542,
    ATUPPERSTART = 543,
    ATUPPEREND = 544,
    BASICSTART = 545,
    BASICEND = 546,
    ISFREESTART = 547,
    ISFREEEND = 548,
    SUPERBASICSTART = 549,
    SUPERBASICEND = 550,
    UNKNOWNSTART = 551,
    UNKNOWNEND = 552,
    SERVICEURISTART = 553,
    SERVICEURIEND = 554,
    SERVICENAMESTART = 555,
    SERVICENAMEEND = 556,
    INSTANCENAMESTART = 557,
    INSTANCENAMEEND = 558,
    JOBIDSTART = 559,
    JOBIDEND = 560,
    OTHERSTART = 561,
    OTHEREND = 562,
    DUMMY = 563,
    NONLINEAREXPRESSIONSSTART = 564,
    NONLINEAREXPRESSIONSEND = 565,
    NUMBEROFNONLINEAREXPRESSIONS = 566,
    NLSTART = 567,
    NLEND = 568,
    MATRIXEXPRESSIONSSTART = 569,
    MATRIXEXPRESSIONSEND = 570,
    NUMBEROFEXPR = 571,
    EXPRSTART = 572,
    EXPREND = 573,
    NUMBEROFMATRIXTERMSATT = 574,
    MATRIXTERMSTART = 575,
    MATRIXTERMEND = 576,
    POWERSTART = 577,
    POWEREND = 578,
    PLUSSTART = 579,
    PLUSEND = 580,
    MINUSSTART = 581,
    MINUSEND = 582,
    DIVIDESTART = 583,
    DIVIDEEND = 584,
    LNSTART = 585,
    LNEND = 586,
    SQRTSTART = 587,
    SQRTEND = 588,
    SUMSTART = 589,
    SUMEND = 590,
    PRODUCTSTART = 591,
    PRODUCTEND = 592,
    EXPSTART = 593,
    EXPEND = 594,
    NEGATESTART = 595,
    NEGATEEND = 596,
    IFSTART = 597,
    IFEND = 598,
    SQUARESTART = 599,
    SQUAREEND = 600,
    COSSTART = 601,
    COSEND = 602,
    SINSTART = 603,
    SINEND = 604,
    VARIABLESTART = 605,
    VARIABLEEND = 606,
    ABSSTART = 607,
    ABSEND = 608,
    ERFSTART = 609,
    ERFEND = 610,
    MAXSTART = 611,
    MAXEND = 612,
    ALLDIFFSTART = 613,
    ALLDIFFEND = 614,
    MINSTART = 615,
    MINEND = 616,
    ESTART = 617,
    EEND = 618,
    PISTART = 619,
    PIEND = 620,
    TIMESSTART = 621,
    TIMESEND = 622,
    NUMBERSTART = 623,
    NUMBEREND = 624,
    MATRIXDETERMINANTSTART = 625,
    MATRIXDETERMINANTEND = 626,
    MATRIXTRACESTART = 627,
    MATRIXTRACEEND = 628,
    MATRIXTOSCALARSTART = 629,
    MATRIXTOSCALAREND = 630,
    MATRIXDIAGONALSTART = 631,
    MATRIXDIAGONALEND = 632,
    MATRIXDOTTIMESSTART = 633,
    MATRIXDOTTIMESEND = 634,
    MATRIXLOWERTRIANGLESTART = 635,
    MATRIXLOWERTRIANGLEEND = 636,
    MATRIXUPPERTRIANGLESTART = 637,
    MATRIXUPPERTRIANGLEEND = 638,
    MATRIXMERGESTART = 639,
    MATRIXMERGEEND = 640,
    MATRIXMINUSSTART = 641,
    MATRIXMINUSEND = 642,
    MATRIXNEGATESTART = 643,
    MATRIXNEGATEEND = 644,
    MATRIXPLUSSTART = 645,
    MATRIXPLUSEND = 646,
    MATRIXTIMESSTART = 647,
    MATRIXTIMESEND = 648,
    MATRIXPRODUCTSTART = 649,
    MATRIXPRODUCTEND = 650,
    MATRIXSCALARTIMESSTART = 651,
    MATRIXSCALARTIMESEND = 652,
    MATRIXSUBMATRIXATSTART = 653,
    MATRIXSUBMATRIXATEND = 654,
    MATRIXTRANSPOSESTART = 655,
    MATRIXTRANSPOSEEND = 656,
    MATRIXREFERENCESTART = 657,
    MATRIXREFERENCEEND = 658,
    IDENTITYMATRIXSTART = 659,
    IDENTITYMATRIXEND = 660,
    MATRIXINVERSESTART = 661,
    MATRIXINVERSEEND = 662,
    COMPLEXCONJUGATESTART = 663,
    COMPLEXCONJUGATEEND = 664,
    COMPLEXMINUSSTART = 665,
    COMPLEXMINUSEND = 666,
    COMPLEXNEGATESTART = 667,
    COMPLEXNEGATEEND = 668,
    COMPLEXNUMBERSTART = 669,
    COMPLEXNUMBEREND = 670,
    COMPLEXPLUSSTART = 671,
    COMPLEXPLUSEND = 672,
    COMPLEXSQUARESTART = 673,
    COMPLEXSQUAREEND = 674,
    COMPLEXSUMSTART = 675,
    COMPLEXSUMEND = 676,
    COMPLEXTIMESSTART = 677,
    COMPLEXTIMESEND = 678,
    CREATECOMPLEXSTART = 679,
    CREATECOMPLEXEND = 680,
    EMPTYINCLUDEDIAGONALATT = 681,
    INCLUDEDIAGONALATT = 682,
    EMPTYTRANSPOSEATT = 683,
    TRANSPOSEATT = 684,
    EMPTYIDATT = 685,
    IDATT = 686
  };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define ITEMTEXT 260
#define INTEGER 261
#define DOUBLE 262
#define QUOTE 263
#define TWOQUOTES 264
#define BOOLEAN 265
#define ENDOFELEMENT 266
#define GREATERTHAN 267
#define EMPTYSEMIDEFINITENESSATT 268
#define SEMIDEFINITENESSATT 269
#define NUMBEROFQTERMSATT 270
#define NUMBEROFCONESATT 271
#define NUMBEROFSTAGESATT 272
#define IDXONEATT 273
#define IDXTWOATT 274
#define HORIZONATT 275
#define STARTATT 276
#define STARTIDXATT 277
#define MATRIXIDXATT 278
#define LBMATRIXIDXATT 279
#define LBCONEIDXATT 280
#define UBMATRIXIDXATT 281
#define UBCONEIDXATT 282
#define TEMPLATEMATRIXIDXATT 283
#define REFERENCEMATRIXIDXATT 284
#define VARREFERENCEMATRIXIDXATT 285
#define OBJREFERENCEMATRIXIDXATT 286
#define CONREFERENCEMATRIXIDXATT 287
#define ORDERCONEIDXATT 288
#define CONSTANTMATRIXIDXATT 289
#define NORMSCALEFACTORATT 290
#define DISTORTIONMATRIXIDXATT 291
#define AXISDIRECTIONATT 292
#define FIRSTAXISDIRECTIONATT 293
#define SECONDAXISDIRECTIONATT 294
#define OSILEND 295
#define INSTANCEDATAEND 296
#define INSTANCEDATASTARTEND 297
#define QUADRATICCOEFFICIENTSSTART 298
#define QUADRATICCOEFFICIENTSEND 299
#define QTERMSTART 300
#define QTERMEND 301
#define CONESSTART 302
#define CONESEND 303
#define NONNEGATIVECONESTART 304
#define NONNEGATIVECONEEND 305
#define NONPOSITIVECONESTART 306
#define NONPOSITIVECONEEND 307
#define ORTHANTCONESTART 308
#define ORTHANTCONEEND 309
#define POLYHEDRALCONESTART 310
#define POLYHEDRALCONEEND 311
#define QUADRATICCONESTART 312
#define QUADRATICCONEEND 313
#define ROTATEDQUADRATICCONESTART 314
#define ROTATEDQUADRATICCONEEND 315
#define SEMIDEFINITECONESTART 316
#define SEMIDEFINITECONEEND 317
#define PRODUCTCONESTART 318
#define PRODUCTCONEEND 319
#define INTERSECTIONCONESTART 320
#define INTERSECTIONCONEEND 321
#define DUALCONESTART 322
#define DUALCONEEND 323
#define POLARCONESTART 324
#define POLARCONEEND 325
#define DIRECTIONSTART 326
#define DIRECTIONEND 327
#define FACTORSSTART 328
#define FACTORSEND 329
#define COMPONENTSSTART 330
#define COMPONENTSEND 331
#define TIMEDOMAINSTART 332
#define TIMEDOMAINEND 333
#define STAGESSTART 334
#define STAGESEND 335
#define STAGESTART 336
#define STAGEEND 337
#define INTERVALSTART 338
#define INTERVALEND 339
#define HEADERSTART 340
#define HEADEREND 341
#define FILENAMESTART 342
#define FILENAMEEND 343
#define FILENAMEEMPTY 344
#define FILENAMESTARTANDEND 345
#define FILESOURCESTART 346
#define FILESOURCEEND 347
#define FILESOURCEEMPTY 348
#define FILESOURCESTARTANDEND 349
#define FILEDESCRIPTIONSTART 350
#define FILEDESCRIPTIONEND 351
#define FILEDESCRIPTIONEMPTY 352
#define FILEDESCRIPTIONSTARTANDEND 353
#define FILECREATORSTART 354
#define FILECREATOREND 355
#define FILECREATOREMPTY 356
#define FILECREATORSTARTANDEND 357
#define FILELICENCESTART 358
#define FILELICENCEEND 359
#define FILELICENCEEMPTY 360
#define FILELICENCESTARTANDEND 361
#define INDEXESSTART 362
#define INDEXESEND 363
#define VALUESSTART 364
#define VALUESEND 365
#define NONZEROSSTART 366
#define NONZEROSEND 367
#define ELSTART 368
#define ELEND 369
#define ENUMERATIONSTART 370
#define ENUMERATIONEND 371
#define ITEMEMPTY 372
#define ITEMSTART 373
#define ITEMEND 374
#define ITEMSTARTANDEND 375
#define BASE64START 376
#define BASE64END 377
#define NUMBEROFELATT 378
#define NUMBEROFENUMERATIONSATT 379
#define NUMBEROFITEMSATT 380
#define EMPTYCATEGORYATT 381
#define CATEGORYATT 382
#define EMPTYDESCRIPTIONATT 383
#define DESCRIPTIONATT 384
#define EMPTYSOLVERATT 385
#define SOLVERATT 386
#define EMPTYNAMEATT 387
#define NAMEATT 388
#define EMPTYTYPEATT 389
#define TYPEATT 390
#define EMPTYENUMTYPEATT 391
#define ENUMTYPEATT 392
#define EMPTYSHAPEATT 393
#define SHAPEATT 394
#define EMPTYUNITATT 395
#define UNITATT 396
#define EMPTYVALUEATT 397
#define VALUEATT 398
#define EMPTYVALUETYPEATT 399
#define VALUETYPEATT 400
#define EMPTYCONTYPEATT 401
#define CONTYPEATT 402
#define EMPTYOBJTYPEATT 403
#define OBJTYPEATT 404
#define EMPTYVARTYPEATT 405
#define VARTYPEATT 406
#define EMPTYMATRIXCONTYPEATT 407
#define MATRIXCONTYPEATT 408
#define EMPTYMATRIXOBJTYPEATT 409
#define MATRIXOBJTYPEATT 410
#define EMPTYMATRIXVARTYPEATT 411
#define MATRIXVARTYPEATT 412
#define EMPTYMATRIXTYPEATT 413
#define MATRIXTYPEATT 414
#define EMPTYSYMMETRYATT 415
#define SYMMETRYATT 416
#define EMPTYROWMAJORATT 417
#define ROWMAJORATT 418
#define EMPTYBASETRANSPOSEATT 419
#define BASETRANSPOSEATT 420
#define NUMBEROFBLOCKSATT 421
#define NUMBEROFCOLUMNSATT 422
#define NUMBEROFROWSATT 423
#define NUMBEROFMATRICESATT 424
#define NUMBEROFVALUESATT 425
#define NUMBEROFCONSTRAINTSATT 426
#define NUMBEROFCONATT 427
#define NUMBEROFCONIDXATT 428
#define NUMBEROFOBJECTIVESATT 429
#define NUMBEROFOBJATT 430
#define NUMBEROFOBJIDXATT 431
#define NUMBEROFVARIABLESATT 432
#define NUMBEROFVARATT 433
#define NUMBEROFVARIDXATT 434
#define NUMBEROFMATRIXCONATT 435
#define NUMBEROFMATRIXOBJATT 436
#define NUMBEROFMATRIXVARATT 437
#define BASEMATRIXIDXATT 438
#define TARGETMATRIXFIRSTROWATT 439
#define TARGETMATRIXFIRSTCOLATT 440
#define BASEMATRIXSTARTROWATT 441
#define BASEMATRIXSTARTCOLATT 442
#define BASEMATRIXENDROWATT 443
#define BASEMATRIXENDCOLATT 444
#define SCALARMULTIPLIERATT 445
#define BLOCKROWIDXATT 446
#define BLOCKCOLIDXATT 447
#define REATT 448
#define IMATT 449
#define MATRIXVARIDXATT 450
#define MATRIXOBJIDXATT 451
#define MATRIXCONIDXATT 452
#define IDXATT 453
#define INCRATT 454
#define MULTATT 455
#define SIZEOFATT 456
#define COEFATT 457
#define CONSTANTATT 458
#define MATRICESSTART 459
#define MATRICESEND 460
#define MATRIXSTART 461
#define MATRIXEND 462
#define BASEMATRIXEND 463
#define BASEMATRIXSTART 464
#define BLOCKSSTART 465
#define BLOCKSEND 466
#define BLOCKSTART 467
#define BLOCKEND 468
#define COLOFFSETSTART 469
#define COLOFFSETEND 470
#define ROWOFFSETSTART 471
#define ROWOFFSETEND 472
#define ELEMENTSSTART 473
#define ELEMENTSEND 474
#define CONSTANTELEMENTSSTART 475
#define CONSTANTELEMENTSEND 476
#define COMPLEXELEMENTSSTART 477
#define COMPLEXELEMENTSEND 478
#define VARREFERENCEELEMENTSSTART 479
#define VARREFERENCEELEMENTSEND 480
#define LINEARELEMENTSSTART 481
#define LINEARELEMENTSEND 482
#define CONREFERENCEELEMENTSSTART 483
#define CONREFERENCEELEMENTSEND 484
#define OBJREFERENCEELEMENTSSTART 485
#define OBJREFERENCEELEMENTSEND 486
#define REALVALUEDEXPRESSIONSSTART 487
#define REALVALUEDEXPRESSIONSSEND 488
#define COMPLEXVALUEDEXPRESSIONSSTART 489
#define COMPLEXVALUEDEXPRESSIONSSEND 490
#define STRINGVALUEDELEMENTSSTART 491
#define STRINGVALUEDELEMENTSEND 492
#define STARTVECTORSTART 493
#define STARTVECTOREND 494
#define INDEXSTART 495
#define INDEXEND 496
#define VALUESTART 497
#define VALUEEND 498
#define VARIDXSTART 499
#define VARIDXEND 500
#define TRANSFORMATIONSTART 501
#define TRANSFORMATIONEND 502
#define MATRIXPROGRAMMINGSTART 503
#define MATRIXPROGRAMMINGEND 504
#define MATRIXVARIABLESSTART 505
#define MATRIXVARIABLESEND 506
#define MATRIXVARSTART 507
#define MATRIXVAREND 508
#define MATRIXOBJECTIVESSTART 509
#define MATRIXOBJECTIVESEND 510
#define MATRIXOBJSTART 511
#define MATRIXOBJEND 512
#define MATRIXCONSTRAINTSSTART 513
#define MATRIXCONSTRAINTSEND 514
#define MATRIXCONSTART 515
#define MATRIXCONEND 516
#define CONSTART 517
#define CONEND 518
#define CONSTRAINTSSTART 519
#define CONSTRAINTSEND 520
#define OBJSTART 521
#define OBJEND 522
#define OBJECTIVESSTART 523
#define OBJECTIVESEND 524
#define VARSTART 525
#define VAREND 526
#define VARIABLESSTART 527
#define VARIABLESEND 528
#define GENERALSTART 529
#define GENERALEND 530
#define SYSTEMSTART 531
#define SYSTEMEND 532
#define SERVICESTART 533
#define SERVICEEND 534
#define JOBSTART 535
#define JOBEND 536
#define OPTIMIZATIONSTART 537
#define OPTIMIZATIONEND 538
#define ATEQUALITYSTART 539
#define ATEQUALITYEND 540
#define ATLOWERSTART 541
#define ATLOWEREND 542
#define ATUPPERSTART 543
#define ATUPPEREND 544
#define BASICSTART 545
#define BASICEND 546
#define ISFREESTART 547
#define ISFREEEND 548
#define SUPERBASICSTART 549
#define SUPERBASICEND 550
#define UNKNOWNSTART 551
#define UNKNOWNEND 552
#define SERVICEURISTART 553
#define SERVICEURIEND 554
#define SERVICENAMESTART 555
#define SERVICENAMEEND 556
#define INSTANCENAMESTART 557
#define INSTANCENAMEEND 558
#define JOBIDSTART 559
#define JOBIDEND 560
#define OTHERSTART 561
#define OTHEREND 562
#define DUMMY 563
#define NONLINEAREXPRESSIONSSTART 564
#define NONLINEAREXPRESSIONSEND 565
#define NUMBEROFNONLINEAREXPRESSIONS 566
#define NLSTART 567
#define NLEND 568
#define MATRIXEXPRESSIONSSTART 569
#define MATRIXEXPRESSIONSEND 570
#define NUMBEROFEXPR 571
#define EXPRSTART 572
#define EXPREND 573
#define NUMBEROFMATRIXTERMSATT 574
#define MATRIXTERMSTART 575
#define MATRIXTERMEND 576
#define POWERSTART 577
#define POWEREND 578
#define PLUSSTART 579
#define PLUSEND 580
#define MINUSSTART 581
#define MINUSEND 582
#define DIVIDESTART 583
#define DIVIDEEND 584
#define LNSTART 585
#define LNEND 586
#define SQRTSTART 587
#define SQRTEND 588
#define SUMSTART 589
#define SUMEND 590
#define PRODUCTSTART 591
#define PRODUCTEND 592
#define EXPSTART 593
#define EXPEND 594
#define NEGATESTART 595
#define NEGATEEND 596
#define IFSTART 597
#define IFEND 598
#define SQUARESTART 599
#define SQUAREEND 600
#define COSSTART 601
#define COSEND 602
#define SINSTART 603
#define SINEND 604
#define VARIABLESTART 605
#define VARIABLEEND 606
#define ABSSTART 607
#define ABSEND 608
#define ERFSTART 609
#define ERFEND 610
#define MAXSTART 611
#define MAXEND 612
#define ALLDIFFSTART 613
#define ALLDIFFEND 614
#define MINSTART 615
#define MINEND 616
#define ESTART 617
#define EEND 618
#define PISTART 619
#define PIEND 620
#define TIMESSTART 621
#define TIMESEND 622
#define NUMBERSTART 623
#define NUMBEREND 624
#define MATRIXDETERMINANTSTART 625
#define MATRIXDETERMINANTEND 626
#define MATRIXTRACESTART 627
#define MATRIXTRACEEND 628
#define MATRIXTOSCALARSTART 629
#define MATRIXTOSCALAREND 630
#define MATRIXDIAGONALSTART 631
#define MATRIXDIAGONALEND 632
#define MATRIXDOTTIMESSTART 633
#define MATRIXDOTTIMESEND 634
#define MATRIXLOWERTRIANGLESTART 635
#define MATRIXLOWERTRIANGLEEND 636
#define MATRIXUPPERTRIANGLESTART 637
#define MATRIXUPPERTRIANGLEEND 638
#define MATRIXMERGESTART 639
#define MATRIXMERGEEND 640
#define MATRIXMINUSSTART 641
#define MATRIXMINUSEND 642
#define MATRIXNEGATESTART 643
#define MATRIXNEGATEEND 644
#define MATRIXPLUSSTART 645
#define MATRIXPLUSEND 646
#define MATRIXTIMESSTART 647
#define MATRIXTIMESEND 648
#define MATRIXPRODUCTSTART 649
#define MATRIXPRODUCTEND 650
#define MATRIXSCALARTIMESSTART 651
#define MATRIXSCALARTIMESEND 652
#define MATRIXSUBMATRIXATSTART 653
#define MATRIXSUBMATRIXATEND 654
#define MATRIXTRANSPOSESTART 655
#define MATRIXTRANSPOSEEND 656
#define MATRIXREFERENCESTART 657
#define MATRIXREFERENCEEND 658
#define IDENTITYMATRIXSTART 659
#define IDENTITYMATRIXEND 660
#define MATRIXINVERSESTART 661
#define MATRIXINVERSEEND 662
#define COMPLEXCONJUGATESTART 663
#define COMPLEXCONJUGATEEND 664
#define COMPLEXMINUSSTART 665
#define COMPLEXMINUSEND 666
#define COMPLEXNEGATESTART 667
#define COMPLEXNEGATEEND 668
#define COMPLEXNUMBERSTART 669
#define COMPLEXNUMBEREND 670
#define COMPLEXPLUSSTART 671
#define COMPLEXPLUSEND 672
#define COMPLEXSQUARESTART 673
#define COMPLEXSQUAREEND 674
#define COMPLEXSUMSTART 675
#define COMPLEXSUMEND 676
#define COMPLEXTIMESSTART 677
#define COMPLEXTIMESEND 678
#define CREATECOMPLEXSTART 679
#define CREATECOMPLEXEND 680
#define EMPTYINCLUDEDIAGONALATT 681
#define INCLUDEDIAGONALATT 682
#define EMPTYTRANSPOSEATT 683
#define TRANSPOSEATT 684
#define EMPTYIDATT 685
#define IDATT 686

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


    double dval;
    int ival;
    char* sval;
    


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int osilparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);

#endif /* !YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */


int osillex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner );
void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg );
std::string addErrorMsg(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg ) ;
 
#define scanner parserData->scanner



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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  436
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  732
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1091
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1690

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   686

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   433,
     435,     2,     2,   434,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   432,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   450,   450,   453,   454,   456,   465,   466,   469,   470,
     486,   491,   501,   501,   503,   516,   522,   523,   526,   527,
     530,   533,   536,   539,   545,   555,   565,   569,   580,   580,
     588,   594,   606,   606,   608,   610,   617,   617,   620,   620,
     626,   632,   644,   644,   646,   648,   652,   652,   660,   661,
     662,   663,   664,   665,   667,   674,   675,   681,   683,   694,
     707,   707,   710,   716,   722,   727,   727,   730,   732,   741,
     754,   754,   757,   762,   767,   772,   772,   775,   777,   786,
     804,   804,   807,   812,   817,   823,   823,   829,   831,   831,
     833,   835,   842,   881,   882,   884,   884,   886,   886,   888,
     891,   893,   903,   916,   916,   919,   924,   929,   934,   939,
     956,   956,   959,   961,   973,   998,   998,  1001,  1006,  1011,
    1015,  1020,  1025,  1032,  1032,  1035,  1037,  1050,  1089,  1089,
    1092,  1097,  1102,  1107,  1112,  1117,  1122,  1129,  1129,  1133,
    1135,  1146,  1158,  1158,  1161,  1166,  1171,  1175,  1182,  1182,
    1196,  1198,  1207,  1219,  1219,  1222,  1227,  1232,  1237,  1239,
    1241,  1247,  1253,  1253,  1255,  1257,  1259,  1269,  1283,  1286,
    1288,  1297,  1309,  1309,  1312,  1317,  1322,  1327,  1329,  1331,
    1337,  1343,  1343,  1345,  1347,  1349,  1359,  1373,  1384,  1384,
    1386,  1391,  1391,  1393,  1396,  1398,  1398,  1405,  1410,  1420,
    1420,  1422,  1424,  1426,  1428,  1428,  1430,  1435,  1451,  1498,
    1498,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1514,  1515,  1517,  1517,  1523,  1528,  1538,  1538,
    1540,  1542,  1544,  1546,  1546,  1548,  1553,  1566,  1598,  1598,
    1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1611,  1612,
    1615,  1615,  1621,  1626,  1636,  1636,  1638,  1640,  1642,  1644,
    1644,  1646,  1651,  1666,  1704,  1704,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1718,  1719,  1762,  1762,  1764,
    1766,  1766,  1768,  1769,  1772,  1773,  1776,  1827,  1829,  1843,
    1844,  1846,  1846,  1870,  1871,  1874,  1875,  1877,  1879,  1880,
    1884,  1885,  1887,  1888,  1890,  1909,  1920,  1927,  1932,  1933,
    1935,  1936,  1938,  1938,  1941,  1953,  1954,  1956,  1957,  1961,
    1962,  1964,  1965,  1967,  1986,  1997,  2004,  2009,  2010,  2012,
    2013,  2015,  2015,  2018,  2030,  2031,  2033,  2043,  2047,  2048,
    2050,  2051,  2053,  2072,  2079,  2084,  2085,  2087,  2088,  2090,
    2090,  2093,  2105,  2106,  2111,  2111,  2119,  2120,  2122,  2123,
    2125,  2129,  2135,  2146,  2151,  2166,  2177,  2188,  2196,  2204,
    2223,  2234,  2252,  2266,  2279,  2292,  2304,  2322,  2334,  2346,
    2358,  2370,  2382,  2394,  2406,  2418,  2430,  2457,  2458,  2465,
    2467,  2467,  2469,  2470,  2471,  2472,  2635,  2643,  2651,  2653,
    2653,  2655,  2657,  2666,  2668,  2668,  2670,  2670,  2672,  2681,
    2684,  2684,  2686,  2686,  2689,  2720,  2728,  2730,  2730,  2732,
    2734,  2742,  2742,  2744,  2753,  2755,  2755,  2757,  2757,  2759,
    2790,  2800,  2800,  2802,  2804,  2812,  2812,  2814,  3297,  3349,
    3372,  3396,  3396,  3399,  3400,  3401,  3402,  3403,  3603,  3603,
    3605,  3607,  3648,  3650,  3650,  3655,  3673,  3702,  3702,  3705,
    3706,  3707,  3708,  3709,  3710,  3711,  3712,  3713,  3716,  3716,
    3718,  3718,  3723,  3723,  3723,  3724,  3724,  3724,  3725,  3725,
    3725,  3726,  3726,  3728,  3730,  3739,  3745,  3745,  3748,  3752,
    3758,  3760,  3760,  3766,  3776,  3786,  3786,  3788,  3790,  3806,
    3809,  3809,  3823,  3831,  3831,  3833,  3835,  3837,  3843,  3853,
    3861,  3861,  3863,  3865,  3867,  3870,  3872,  3881,  3887,  3887,
    3890,  3894,  3900,  3902,  3904,  3904,  3914,  3922,  3922,  3924,
    3926,  3928,  3931,  3933,  3942,  3948,  3948,  3951,  3955,  3961,
    3963,  3966,  3971,  3982,  3998,  3998,  4000,  4002,  4004,  4006,
    4006,  4008,  4015,  4022,  4041,  4041,  4044,  4045,  4047,  4047,
    4049,  4051,  4053,  4053,  4056,  4058,  4066,  4066,  4071,  4078,
    4080,  4089,  4095,  4095,  4098,  4102,  4109,  4111,  4114,  4118,
    4129,  4145,  4145,  4147,  4149,  4151,  4151,  4153,  4155,  4170,
    4170,  4172,  4174,  4183,  4185,  4194,  4200,  4200,  4203,  4207,
    4214,  4216,  4219,  4223,  4234,  4251,  4251,  4253,  4255,  4257,
    4257,  4259,  4261,  4276,  4276,  4278,  4280,  4290,  4292,  4301,
    4307,  4307,  4310,  4314,  4320,  4322,  4324,  4324,  4334,  4342,
    4342,  4344,  4346,  4348,  4351,  4353,  4362,  4368,  4368,  4371,
    4375,  4381,  4383,  4386,  4390,  4401,  4417,  4417,  4419,  4421,
    4423,  4423,  4425,  4428,  4440,  4440,  4443,  4444,  4445,  4447,
    4480,  4482,  4492,  4498,  4498,  4501,  4505,  4511,  4513,  4516,
    4520,  4531,  4544,  4544,  4546,  4548,  4550,  4550,  4552,  4579,
    4590,  4590,  4593,  4594,  4595,  4597,  4597,  4600,  4602,  4611,
    4617,  4617,  4620,  4624,  4630,  4632,  4634,  4634,  4644,  4652,
    4652,  4654,  4656,  4658,  4661,  4664,  4682,  4682,  4693,  4700,
    4710,  4718,  4724,  4726,  4740,  4752,  4758,  4764,  4764,  4766,
    4768,  4770,  4772,  4782,  4788,  4794,  4794,  4796,  4798,  4800,
    4802,  4802,  4807,  4812,  4824,  4826,  4826,  4829,  4830,  4831,
    4841,  4848,  4848,  4850,  4852,  4870,  4881,  4925,  5035,  5047,
    5069,  5094,  5105,  5118,  5132,  5146,  5158,  5170,  5190,  5210,
    5220,  5260,  5271,  5283,  5297,  5310,  5323,  5333,  5343,  5356,
    5356,  5358,  5368,  5532,  5532,  5534,  5541,  5568,  5568,  5570,
    5579,  5595,  5595,  5597,  5604,  5631,  5631,  5633,  5640,  5649,
    5649,  5651,  5658,  5685,  5685,  5689,  5697,  5706,  5706,  5708,
    5715,  5724,  5724,  5726,  5733,  5773,  5774,  5788,  5794,  5819,
    5820,  5822,  5833,  5852,  5860,  5860,  5863,  5872,  5885,  5886,
    5887,  5888,  5889,  5890,  5891,  5892,  5893,  5894,  5895,  5896,
    5897,  5898,  5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,
    5907,  5908,  5910,  5911,  5912,  5916,  5916,  5919,  5920,  5922,
    5922,  5925,  5926,  5930,  5930,  5935,  5935,  5940,  5940,  5945,
    5945,  5950,  5950,  5955,  5955,  5960,  5960,  5965,  5965,  5970,
    5970,  5975,  5975,  5980,  5980,  5985,  5985,  5990,  5992,  5998,
    6005,  6005,  6011,  6011,  6023,  6023,  6028,  6028,  6033,  6033,
    6043,  6050,  6056,  6057,  6059,  6060,  6063,  6067,  6071,  6075,
    6074,  6095,  6094,  6101,  6102,  6104,  6103,  6110,  6111,  6114,
    6120,  6128,  6135,  6157,  6157,  6168,  6168,  6171,  6171,  6185,
    6186,  6189,  6189,  6202,  6203,  6206,  6206,  6219,  6220,  6223,
    6223,  6233,  6234,  6240,  6241,  6242,  6243,  6244,  6245,  6246,
    6247,  6248,  6249,  6250,  6251,  6252,  6253,  6254,  6255,  6256,
    6257,  6258,  6261,  6272,  6280,  6280,  6283,  6284,  6287,  6288,
    6290,  6302,  6316,  6321,  6328,  6329,  6331,  6338,  6343,  6350,
    6351,  6353,  6360,  6365,  6372,  6373,  6375,  6382,  6384,  6390,
    6392,  6394,  6400,  6402,  6404,  6410,  6412,  6414,  6420,  6422,
    6424,  6430,  6430,  6435,  6437,  6439,  6445,  6445,  6450,  6452,
    6463,  6465,  6470,  6470,  6472,  6474,  6480,  6483,  6485,  6491,
    6494,  6496,  6502,  6505,  6507,  6513,  6517,  6516,  6528,  6528,
    6535,  6537,  6543,  6545,  6547,  6553,  6556,  6558,  6564,  6574,
    6574,  6580,  6588,  6590,  6610,  6610,  6612,  6614,  6616,  6616,
    6618,  6630,  6648,  6654,  6654,  6657,  6665,  6681,  6681,  6685,
    6686,  6687,  6688,  6689,  6690,  6691,  6692,  6693,  6697,  6701,
    6710,  6711,  6713,  6720,  6720,  6723,  6724,  6728,  6730,  6736,
    6739,  6741,  6747,  6750,  6750,  6760,  6761,  6767,  6769,  6775,
    6778,  6780,  6786,  6789,  6791,  6797,  6800,  6802,  6808,  6811,
    6813,  6819
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "BOOLEAN",
  "ENDOFELEMENT", "GREATERTHAN", "EMPTYSEMIDEFINITENESSATT",
  "SEMIDEFINITENESSATT", "NUMBEROFQTERMSATT", "NUMBEROFCONESATT",
  "NUMBEROFSTAGESATT", "IDXONEATT", "IDXTWOATT", "HORIZONATT", "STARTATT",
  "STARTIDXATT", "MATRIXIDXATT", "LBMATRIXIDXATT", "LBCONEIDXATT",
  "UBMATRIXIDXATT", "UBCONEIDXATT", "TEMPLATEMATRIXIDXATT",
  "REFERENCEMATRIXIDXATT", "VARREFERENCEMATRIXIDXATT",
  "OBJREFERENCEMATRIXIDXATT", "CONREFERENCEMATRIXIDXATT",
  "ORDERCONEIDXATT", "CONSTANTMATRIXIDXATT", "NORMSCALEFACTORATT",
  "DISTORTIONMATRIXIDXATT", "AXISDIRECTIONATT", "FIRSTAXISDIRECTIONATT",
  "SECONDAXISDIRECTIONATT", "OSILEND", "INSTANCEDATAEND",
  "INSTANCEDATASTARTEND", "QUADRATICCOEFFICIENTSSTART",
  "QUADRATICCOEFFICIENTSEND", "QTERMSTART", "QTERMEND", "CONESSTART",
  "CONESEND", "NONNEGATIVECONESTART", "NONNEGATIVECONEEND",
  "NONPOSITIVECONESTART", "NONPOSITIVECONEEND", "ORTHANTCONESTART",
  "ORTHANTCONEEND", "POLYHEDRALCONESTART", "POLYHEDRALCONEEND",
  "QUADRATICCONESTART", "QUADRATICCONEEND", "ROTATEDQUADRATICCONESTART",
  "ROTATEDQUADRATICCONEEND", "SEMIDEFINITECONESTART",
  "SEMIDEFINITECONEEND", "PRODUCTCONESTART", "PRODUCTCONEEND",
  "INTERSECTIONCONESTART", "INTERSECTIONCONEEND", "DUALCONESTART",
  "DUALCONEEND", "POLARCONESTART", "POLARCONEEND", "DIRECTIONSTART",
  "DIRECTIONEND", "FACTORSSTART", "FACTORSEND", "COMPONENTSSTART",
  "COMPONENTSEND", "TIMEDOMAINSTART", "TIMEDOMAINEND", "STAGESSTART",
  "STAGESEND", "STAGESTART", "STAGEEND", "INTERVALSTART", "INTERVALEND",
  "HEADERSTART", "HEADEREND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "INDEXESSTART", "INDEXESEND", "VALUESSTART", "VALUESEND",
  "NONZEROSSTART", "NONZEROSEND", "ELSTART", "ELEND", "ENUMERATIONSTART",
  "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "BASE64START", "BASE64END", "NUMBEROFELATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFITEMSATT", "EMPTYCATEGORYATT", "CATEGORYATT",
  "EMPTYDESCRIPTIONATT", "DESCRIPTIONATT", "EMPTYSOLVERATT", "SOLVERATT",
  "EMPTYNAMEATT", "NAMEATT", "EMPTYTYPEATT", "TYPEATT", "EMPTYENUMTYPEATT",
  "ENUMTYPEATT", "EMPTYSHAPEATT", "SHAPEATT", "EMPTYUNITATT", "UNITATT",
  "EMPTYVALUEATT", "VALUEATT", "EMPTYVALUETYPEATT", "VALUETYPEATT",
  "EMPTYCONTYPEATT", "CONTYPEATT", "EMPTYOBJTYPEATT", "OBJTYPEATT",
  "EMPTYVARTYPEATT", "VARTYPEATT", "EMPTYMATRIXCONTYPEATT",
  "MATRIXCONTYPEATT", "EMPTYMATRIXOBJTYPEATT", "MATRIXOBJTYPEATT",
  "EMPTYMATRIXVARTYPEATT", "MATRIXVARTYPEATT", "EMPTYMATRIXTYPEATT",
  "MATRIXTYPEATT", "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "NUMBEROFMATRICESATT", "NUMBEROFVALUESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFCONATT", "NUMBEROFCONIDXATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJIDXATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIDXATT", "NUMBEROFMATRIXCONATT",
  "NUMBEROFMATRIXOBJATT", "NUMBEROFMATRIXVARATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "BLOCKROWIDXATT",
  "BLOCKCOLIDXATT", "REATT", "IMATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT",
  "MATRIXCONIDXATT", "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT",
  "COEFATT", "CONSTANTATT", "MATRICESSTART", "MATRICESEND", "MATRIXSTART",
  "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSSTART",
  "BLOCKSEND", "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART", "COLOFFSETEND",
  "ROWOFFSETSTART", "ROWOFFSETEND", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "COMPLEXELEMENTSSTART",
  "COMPLEXELEMENTSEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "REALVALUEDEXPRESSIONSSTART", "REALVALUEDEXPRESSIONSSEND",
  "COMPLEXVALUEDEXPRESSIONSSTART", "COMPLEXVALUEDEXPRESSIONSSEND",
  "STRINGVALUEDELEMENTSSTART", "STRINGVALUEDELEMENTSEND",
  "STARTVECTORSTART", "STARTVECTOREND", "INDEXSTART", "INDEXEND",
  "VALUESTART", "VALUEEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "MATRIXPROGRAMMINGSTART",
  "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART", "MATRIXVARIABLESEND",
  "MATRIXVARSTART", "MATRIXVAREND", "MATRIXOBJECTIVESSTART",
  "MATRIXOBJECTIVESEND", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "MATRIXCONSTART",
  "MATRIXCONEND", "CONSTART", "CONEND", "CONSTRAINTSSTART",
  "CONSTRAINTSEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART",
  "OBJECTIVESEND", "VARSTART", "VAREND", "VARIABLESSTART", "VARIABLESEND",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "ATEQUALITYSTART", "ATEQUALITYEND", "ATLOWERSTART",
  "ATLOWEREND", "ATUPPERSTART", "ATUPPEREND", "BASICSTART", "BASICEND",
  "ISFREESTART", "ISFREEEND", "SUPERBASICSTART", "SUPERBASICEND",
  "UNKNOWNSTART", "UNKNOWNEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND", "OTHERSTART", "OTHEREND",
  "DUMMY", "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND",
  "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND", "NUMBEROFEXPR",
  "EXPRSTART", "EXPREND", "NUMBEROFMATRIXTERMSATT", "MATRIXTERMSTART",
  "MATRIXTERMEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND",
  "MINUSSTART", "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND",
  "SQRTSTART", "SQRTEND", "SUMSTART", "SUMEND", "PRODUCTSTART",
  "PRODUCTEND", "EXPSTART", "EXPEND", "NEGATESTART", "NEGATEEND",
  "IFSTART", "IFEND", "SQUARESTART", "SQUAREEND", "COSSTART", "COSEND",
  "SINSTART", "SINEND", "VARIABLESTART", "VARIABLEEND", "ABSSTART",
  "ABSEND", "ERFSTART", "ERFEND", "MAXSTART", "MAXEND", "ALLDIFFSTART",
  "ALLDIFFEND", "MINSTART", "MINEND", "ESTART", "EEND", "PISTART", "PIEND",
  "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND", "MATRIXTRACESTART",
  "MATRIXTRACEEND", "MATRIXTOSCALARSTART", "MATRIXTOSCALAREND",
  "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND", "MATRIXDOTTIMESSTART",
  "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
  "MATRIXLOWERTRIANGLEEND", "MATRIXUPPERTRIANGLESTART",
  "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART", "MATRIXMERGEEND",
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXNEGATESTART",
  "MATRIXNEGATEEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
  "MATRIXTIMESSTART", "MATRIXTIMESEND", "MATRIXPRODUCTSTART",
  "MATRIXPRODUCTEND", "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART", "MATRIXREFERENCEEND",
  "IDENTITYMATRIXSTART", "IDENTITYMATRIXEND", "MATRIXINVERSESTART",
  "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART", "COMPLEXCONJUGATEEND",
  "COMPLEXMINUSSTART", "COMPLEXMINUSEND", "COMPLEXNEGATESTART",
  "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART", "COMPLEXNUMBEREND",
  "COMPLEXPLUSSTART", "COMPLEXPLUSEND", "COMPLEXSQUARESTART",
  "COMPLEXSQUAREEND", "COMPLEXSUMSTART", "COMPLEXSUMEND",
  "COMPLEXTIMESSTART", "COMPLEXTIMESEND", "CREATECOMPLEXSTART",
  "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "EMPTYTRANSPOSEATT", "TRANSPOSEATT", "EMPTYIDATT", "IDATT", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osildoc", "theInstanceEnd",
  "osilEnd", "osilEnding", "quadraticCoefficients",
  "quadraticCoefficientsStart", "osilQuadnumberATT", "qTermlist", "qterm",
  "qtermStart", "qtermend", "anotherqTermATT", "qtermatt",
  "osilQtermidxOneATT", "osilQtermidxTwoATT", "osilQtermcoefATT",
  "osilQtermidxATT", "matrices", "matricesStart", "matricesAttributes",
  "matricesContent", "matricesEmpty", "matricesLaden", "matrixList",
  "cones", "conesStart", "conesAttributes", "conesContent", "conesEmpty",
  "conesLaden", "coneList", "cone", "nonnegativeCone",
  "nonnegativeConeStart", "nonnegativeConeAttributes",
  "nonnegativeConeAttList", "nonnegativeConeAtt", "nonnegativeConeEnd",
  "nonpositiveCone", "nonpositiveConeStart", "nonpositiveConeAttributes",
  "nonpositiveConeAttList", "nonpositiveConeAtt", "nonpositiveConeEnd",
  "generalOrthantCone", "generalOrthantConeStart",
  "generalOrthantConeAttributes", "generalOrthantConeAttList",
  "generalOrthantConeAtt", "generalOrthantConeContent",
  "generalOrthantConeDirectionList", "generalOrthantConeDirections",
  "generalOrthantConeDirection", "generalOrthantConeDirectionStart",
  "generalOrthantConeDirectionAttributes",
  "generalOrthantConeDirectionAttributeList",
  "generalOrthantConeDirectionAtt", "generalOrthantConeDirectionEnd",
  "generalOrthantConeEnd", "polyhedralCone", "polyhedralConeStart",
  "polyhedralConeAttributes", "polyhedralConeAttList", "polyhedralConeAtt",
  "referenceMatrixATT", "polyhedralConeEnd", "quadraticCone",
  "quadraticConeStart", "quadraticConeAttributes", "quadraticConeAttList",
  "quadraticConeAtt", "quadraticConeEnd", "rotatedQuadraticCone",
  "rotatedQuadraticConeStart", "rotatedQuadraticConeAttributes",
  "rotatedQuadraticConeAttList", "rotatedQuadraticConeAtt",
  "rotatedQuadraticConeEnd", "semidefiniteCone", "semidefiniteConeStart",
  "semidefiniteConeAttributes", "semidefiniteConeAttList",
  "semidefiniteConeAtt", "semidefiniteConeEnd", "productCone",
  "productConeStart", "productConeAttributes", "productConeAttList",
  "productConeAtt", "productConeContent", "productConeFactors",
  "productConeFactorsStart", "productConeFactorsAttributes",
  "productConeFactorsContent", "productConeFactorsEmpty",
  "productConeFactorsLaden", "productConeFactorList",
  "productConeFactorsEnd", "productConeEnd", "intersectionCone",
  "intersectionConeStart", "intersectionConeAttributes",
  "intersectionConeAttList", "intersectionConeAtt",
  "intersectionConeContent", "intersectionConeComponents",
  "intersectionConeComponentsStart",
  "intersectionConeComponentsAttributes",
  "intersectionConeComponentsContent", "intersectionConeComponentsEmpty",
  "intersectionConeComponentsLaden", "intersectionConeComponentList",
  "intersectionConeComponentsEnd", "intersectionConeEnd",
  "matrixProgramming", "matrixProgrammingStart",
  "matrixProgrammingContent", "matrixProgrammingEmpty",
  "matrixProgrammingLaden", "matrixVariables", "matrixVariablesStart",
  "matrixVariablesAttributes", "matrixVariablesContent",
  "matrixVariablesEmpty", "matrixVariablesLaden", "matrixVariablesEnd",
  "matrixVarList", "matrixVariable", "matrixVariableStart",
  "matrixVariableAttributes", "matrixVariableAttList", "matrixVariableAtt",
  "matrixVariableEnd", "matrixObjectives", "matrixObjectivesStart",
  "matrixObjectivesAttributes", "matrixObjectivesContent",
  "matrixObjectivesEmpty", "matrixObjectivesLaden", "matrixObjectivesEnd",
  "matrixObjList", "matrixObjective", "matrixObjectiveStart",
  "matrixObjectiveAttributes", "matrixObjectiveAttList",
  "matrixObjectiveAtt", "matrixObjectiveEnd", "matrixConstraints",
  "matrixConstraintsStart", "matrixConstraintsAttributes",
  "matrixConstraintsContent", "matrixConstraintsEmpty",
  "matrixConstraintsLaden", "matrixConstraintsEnd", "matrixConList",
  "matrixConstraint", "matrixConstraintStart",
  "matrixConstraintAttributes", "matrixConstraintAttList",
  "matrixConstraintAtt", "matrixConstraintEnd", "timeDomain",
  "timeDomainStart", "timeDomainContent", "timeDomainEmpty",
  "timeDomainLaden", "stages", "stagesstart", "osilNumberofstagesATT",
  "stagelist", "stage", "$@1", "osilStagenameATT", "stageend",
  "stagecontent", "stagevariables", "anotherstagevarATT", "stagevaratt",
  "osilNumberofstagevariablesATT", "osilStagevarstartidxATT",
  "restofstagevariables", "emptyvarlist", "stagevarlist", "stagevar",
  "$@2", "osilStagevaridxATT", "stagevarend", "stageconstraints",
  "anotherstageconATT", "stageconatt", "osilNumberofstageconstraintsATT",
  "osilStageconstartidxATT", "restofstageconstraints", "emptyconlist",
  "stageconlist", "stagecon", "$@3", "osilStageconidxATT", "stageconend",
  "stageobjectives", "anotherstageobjATT", "stageobjatt",
  "osilNumberofstageobjectivesATT", "restofstageobjectives",
  "emptyobjlist", "stageobjlist", "stageobj", "$@4", "osilStageobjidxATT",
  "stageobjend", "interval", "$@5", "intervalend", "anotherIntervalATT",
  "intervalatt", "osilStageobjstartidxATT", "osilIntervalhorizonATT",
  "osilIntervalstartATT", "numberOfMatricesATT", "numberOfConesATT",
  "numberOfMatrixVarATT", "numberOfMatrixObjATT", "numberOfMatrixConATT",
  "normScaleFactorATT", "distortionMatrixIdxATT", "axisDirectionATT",
  "firstAxisDirectionATT", "secondAxisDirectionATT", "semidefinitenessATT",
  "matrixIdxATT", "lbMatrixIdxATT", "ubMatrixIdxATT",
  "constantMatrixIdxATT", "templateMatrixIdxATT",
  "varReferenceMatrixIdxATT", "objReferenceMatrixIdxATT",
  "conReferenceMatrixIdxATT", "lbConeIdxATT", "ubConeIdxATT",
  "orderConeIdxATT", "aNumber", "quote", "xmlWhiteSpace",
  "xmlWhiteSpaceChar", "osglNonNegativeIntArrayData", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "osglIntVectorBase64Content", "osglIntVectorBase64Empty",
  "osglIntVectorBase64Laden", "osglDblArrayData", "osglDblVectorElArray",
  "osglDblVectorEl", "osglDblVectorElStart", "osglDblVectorElAttributes",
  "osglDblVectorElContent", "osglDblVectorBase64",
  "osglDblVectorBase64Content", "osglDblVectorBase64Empty",
  "osglDblVectorBase64Laden", "osglStrArrayData", "osglStrVectorElArray",
  "osglStrVectorEl", "osglStrVectorElStart", "osglStrVectorElAttributes",
  "osglStrVectorElContent", "osglMatrix", "matrixStart",
  "matrixAttributes", "matrixAttributeList", "matrixAttribute",
  "matrixContent", "matrixEmpty", "matrixLaden", "matrixOrBlockBody",
  "baseMatrix", "baseMatrixStart", "baseMatrixAttributes",
  "baseMatrixAttList", "baseMatrixAtt", "baseMatrixEnd",
  "matrixConstructorList", "matrixConstructor", "constantElements",
  "constantElementsStart", "constantElementsAttributes",
  "constantElementsAttList", "constantElementsAtt",
  "constantElementsContent", "constantElementsNonzeros",
  "matrixElementsStartVector", "matrixElementsStartVectorStart",
  "matrixElementsStartVectorContent", "matrixElementsStartVectorEmpty",
  "matrixElementsStartVectorLaden", "matrixElementsStartVectorBody",
  "matrixElementsIndexVector", "matrixElementsIndexStart",
  "matrixElementsIndexContent", "matrixElementsIndexEmpty",
  "matrixElementsIndexLaden", "matrixElementsIndexBody",
  "constantElementsValues", "constantElementsValueStart",
  "constantElementsValueContent", "constantElementsValueEmpty",
  "constantElementsValueLaden", "constantElementsValueBody",
  "varReferenceElements", "varReferenceElementsStart",
  "varReferenceElementsAttributes", "varReferenceElementsAttList",
  "varReferenceElementsAtt", "varReferenceElementsContent",
  "varReferenceElementsNonzeros", "varReferenceElementsValues",
  "varReferenceElementsValuesStart", "varReferenceElementsValuesContent",
  "varReferenceElementsValuesEmpty", "varReferenceElementsValuesLaden",
  "varReferenceElementsValuesBody", "linearElements",
  "linearElementsStart", "linearElementsAttributes",
  "linearElementsAttList", "linearElementsAtt", "linearElementsContent",
  "linearElementsNonzeros", "linearElementsValues",
  "linearElementsValuesStart", "linearElementsValuesContent",
  "linearElementsValuesEmpty", "linearElementsValuesLaden",
  "linearElementsValuesBody", "linearElementsValuesElList",
  "linearElementsValuesEl", "linearElementsValuesElStart",
  "linearElementsValuesElAttributes", "linearElementsValuesElAttList",
  "linearElementsValuesElAtt", "linearElementsValuesElContent",
  "linearElementsValuesElEmpty", "linearElementsValuesElLaden",
  "linearElementsValuesVarIdxList", "linearElementsValuesVarIdx",
  "linearElementsValuesVarIdxStart", "linearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "realValuedExpressions",
  "realValuedExpressionsStart", "realValuedExpressionsAttributes",
  "realValuedExpressionsAttList", "realValuedExpressionsAtt",
  "realValuedExpressionsContent", "realValuedExpressionsNonzeros",
  "realValuedExpressionsValues", "realValuedExpressionsValuesStart",
  "realValuedExpressionsValuesContent", "realValuedExpressionsValuesEmpty",
  "realValuedExpressionsValuesLaden", "realValuedExpressionsElList",
  "realValuedExpressionsEl", "realValuedExpressionsElStart",
  "realValuedExpressionsElContent", "realValuedExpressionsElEmpty",
  "realValuedExpressionsElLaden", "complexValuedExpressions",
  "complexValuedExpressionsStart", "complexValuedExpressionsAttributes",
  "complexValuedExpressionsAttList", "complexValuedExpressionsAtt",
  "complexValuedExpressionsContent", "complexValuedExpressionsNonzeros",
  "complexValuedExpressionsValues", "complexValuedExpressionsValuesStart",
  "complexValuedExpressionsValuesContent",
  "complexValuedExpressionsValuesEmpty",
  "complexValuedExpressionsValuesLaden", "complexValuedExpressionsElList",
  "complexValuedExpressionsEl", "complexValuedExpressionsElStart",
  "complexValuedExpressionsElContent", "complexValuedExpressionsElEmpty",
  "complexValuedExpressionsElLaden", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsAttributes",
  "objReferenceElementsAttList", "objReferenceElementsAtt",
  "objReferenceElementsContent", "objReferenceElementsNonzeros",
  "objReferenceElementsValues", "objReferenceElementsValuesStart",
  "objReferenceElementsValuesContent", "objReferenceElementsValuesEmpty",
  "objReferenceElementsValuesLaden", "objReferenceElementsValuesBody",
  "conReferenceElements", "conReferenceElementsStart",
  "conReferenceElementsAttributes", "conReferenceElementsAttList",
  "conReferenceElementsAtt", "conReferenceElementsContent",
  "conReferenceElementsNonzeros", "conReferenceElementsValues",
  "conReferenceElementsValuesStart", "conReferenceElementsValuesContent",
  "conReferenceElementsValuesEmpty", "conReferenceElementsValuesLaden",
  "conReferenceElementsElList", "conReferenceElementsEl",
  "conReferenceElementsElStart", "conReferenceElementsElAttributeList",
  "conReferenceElementsElAttribute", "conReferenceElementsElContent",
  "complexElements", "complexElementsStart", "complexElementsAttributes",
  "complexElementsAttList", "complexElementsAtt", "complexElementsContent",
  "complexElementsNonzeros", "complexElementsValues",
  "complexElementsValuesStart", "complexElementsValuesContent",
  "complexElementsValuesEmpty", "complexElementsValuesLaden",
  "complexElementsElList", "complexElementsEl", "complexElementsElStart",
  "complexElementsElAttributeList", "complexElementsElAttribute",
  "complexElementsElEnd", "stringValuedElements",
  "stringValuedElementsStart", "stringValuedElementsAttributes",
  "stringValuedElementsAttList", "stringValuedElementsAtt",
  "stringValuedElementsContent", "stringValuedElementsNonzeros",
  "stringValuedElementsValues", "stringValuedElementsValueStart",
  "stringValuedElementsValueContent", "stringValuedElementsValueEmpty",
  "stringValuedElementsValueLaden", "stringValuedElementsValueBody",
  "matrixTransformation", "matrixTransformationStart",
  "matrixTransformationShapeATT", "matrixTransformationEnd",
  "matrixBlocks", "matrixBlocksStart", "matrixBlocksAttributes",
  "matrixBlocksContent", "matrixBlocksEnd", "colOffsets", "colOffsetStart",
  "colOffsetNumberOfElAttribute", "colOffsetContent", "colOffsetEmpty",
  "colOffsetLaden", "colOffsetBody", "rowOffsets", "rowOffsetStart",
  "rowOffsetNumberOfElAttribute", "rowOffsetContent", "rowOffsetEmpty",
  "rowOffsetLaden", "rowOffsetBody", "blockList", "matrixBlock",
  "matrixBlockStart", "matrixBlockAttributes", "matrixBlockAttList",
  "matrixBlockAtt", "matrixBlockContent", "blockEmpty", "blockLaden",
  "osglNumberOfBlocksATT", "osglNumberOfColumnsATT", "osglNumberOfElATT",
  "osglNumberOfRowsATT", "osglNumberOfValuesATT", "osglNumberOfVarIdxATT",
  "osglBase64SizeATT", "osglBaseMatrixIdxATT", "osglBaseMatrixStartRowATT",
  "osglBaseMatrixStartColATT", "osglBaseMatrixEndRowATT",
  "osglBaseMatrixEndColATT", "osglBlockRowIdxATT", "osglBlockColIdxATT",
  "osglIdxATT", "osglIncrATT", "osglMultATT",
  "osglTargetMatrixFirstRowATT", "osglTargetMatrixFirstColATT",
  "osglCoefATT", "osglConstantATT", "osglImagPartATT", "osglRealPartATT",
  "osglScalarMultiplierATT", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent", "osglNameATT",
  "nameAttEmpty", "nameAttContent", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "osglShapeATT", "shapeAttEmpty", "shape",
  "osglSymmetryATT", "symmetryAttEmpty", "symmetryAttContent",
  "osglTypeATT", "typeAttEmpty", "typeAttContent", "osglValueATT",
  "valueAttEmpty", "valueAttContent", "osglValueTypeATT",
  "valueTypeAttEmpty", "valueTypeAttContent", "osglVarTypeATT",
  "varTypeAttEmpty", "varTypeAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "realValuedExpressionTree", "nlstart", "nlAttributes", "nlAttributeList",
  "nlAttribute", "nlnode", "E", "$@7", "eend", "PI", "$@8", "piend",
  "times", "$@9", "plus", "$@10", "minus", "$@11", "negate", "$@12",
  "divide", "$@13", "power", "$@14", "ln", "$@15", "sqrt", "$@16",
  "square", "$@17", "cos", "$@18", "sin", "$@19", "exp", "$@20", "abs",
  "absStart", "absEnd", "erf", "$@21", "if", "$@22", "matrixDeterminant",
  "$@23", "matrixTrace", "$@24", "matrixToScalar", "$@25", "number",
  "numberStart", "numberEnd", "numberAttributeList", "numberAttribute",
  "numberidATT", "$@26", "variable", "$@27", "variableend", "$@28",
  "anotherVariableATT", "variableATT", "variablecoefATT", "variableidxATT",
  "sum", "$@29", "anothersumnlnode", "allDiff", "$@30",
  "anotherallDiffnlnode", "max", "$@31", "anothermaxnlnode", "min", "$@32",
  "anotherminnlnode", "product", "$@33", "anotherproductnlnode",
  "OSnLMNode", "matrixReference", "matrixReferenceStart",
  "matrixRefAttributeList", "matrixRefAttribute", "matrixReferenceEnd",
  "matrixTransposeATT", "matrixVarReference", "matrixVarReferenceStart",
  "matrixVarReferenceEnd", "matrixVarIdxATT", "matrixObjReference",
  "matrixObjReferenceStart", "matrixObjReferenceEnd", "matrixObjIdxATT",
  "matrixConReference", "matrixConReferenceStart", "matrixConReferenceEnd",
  "matrixConIdxATT", "matrixDiagonal", "matrixDiagonalStart",
  "matrixDiagonalContent", "matrixDotTimes", "matrixDotTimesStart",
  "matrixDotTimesContent", "identityMatrix", "identityMatrixStart",
  "identityMatrixContent", "matrixInverse", "matrixInverseStart",
  "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixNegate", "matrixNegateStart",
  "matrixNegateContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@34",
  "anothermatrixproductnode", "matrixScalarTimes",
  "matrixScalarTimesStart", "matrixScalarTimesContent",
  "matrixSubMatrixAt", "matrixSubMatrixAtStart",
  "matrixSubMatrixAtContent", "matrixTranspose", "matrixTransposeStart",
  "matrixTransposeContent", "matrixExpressions", "matrixExpressionsStart",
  "matrixExpressionsAtt", "numberOfExprATT", "matrixExpressionsContent",
  "matrixExpressionsEmpty", "matrixExpressionsLaden", "matrixExprList",
  "matrixExpr", "matrixExprStart", "matrixExprAttributes",
  "matrixExprAttributeList", "exprAttribute", "scalarNode", "OSnLCNode",
  "complexNumber", "complexNumberStart", "complexNumberEnd",
  "complexNumberAttributes", "complexNumberAttList", "complexNumberAtt",
  "createComplex", "createComplexStart", "createComplexContent",
  "complexPlus", "complexPlusStart", "complexPlusContent", "complexSum",
  "$@35", "anothercsumnode", "complexMinus", "complexMinusStart",
  "complexMinusContent", "complexNegate", "complexNegateStart",
  "complexNegateContent", "complexConjugate", "complexConjugateStart",
  "complexConjugateContent", "complexTimes", "complexTimesStart",
  "complexTimesContent", "complexSquare", "complexSquareStart",
  "complexSquareContent", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,    32,     9,    13,    10
};
# endif

#define YYPACT_NINF -1323

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1323)))

#define YYTABLE_NINF -501

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29, -1323,    79,  -224,    80, -1323, -1323,  -105,  -188,   121,
   -1323, -1323,    87,   -30,   145, -1323,   149,    14, -1323,   -88,
     146,   156,   105, -1323,   162,  -220,   164, -1323, -1323, -1323,
   -1323, -1323,    97,   126,   176,   133, -1323,   186, -1323, -1323,
   -1323, -1323, -1323,   191, -1323, -1323, -1323, -1323,   195,    42,
   -1323,   116,   135, -1323,   -38, -1323, -1323, -1323,   211, -1323,
   -1323, -1323, -1323, -1323,   213,   -95,   207,   216,   -56, -1323,
   -1323,   188,   228,   239,   263,   265, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   218, -1323,    88, -1323, -1323, -1323,
   -1323,    21,    95,   271,   430, -1323, -1323, -1323, -1323, -1323,
   -1323,   726, -1323,   280,   277, -1323, -1323, -1323, -1323, -1323,
   -1323,   281,   290,   296, -1323, -1323, -1323, -1323, -1323, -1323,
     226,   289,   230,   227, -1323,    54,   137,   306,   171, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     212,   262, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,     7,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   726, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   314,
     318,   338,   347,   354,   356,    39, -1323,   358, -1323, -1323,
   -1323, -1323,    12,   190,   368,   215, -1323,   376, -1323, -1323,
   -1323, -1323, -1323,   219,   -36,   258,   -36,   282,   -36,   324,
       8,   328,   293,   331,   225,   333,   122,   372,   -36,   374,
     -36, -1323,   179, -1323, -1323, -1323, -1323,   397, -1323,   418,
   -1323,   421,   399,   433, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   726,   726,   726,   726,
     726,   726, -1323, -1323,   726,   726,   726,   726,   726,   726,
   -1323,   726, -1323, -1323, -1323,   339,   341,   726,   -15,   -15,
     -15, -1323,    93,    36, -1323,   443, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   458,   377, -1323,
     387,    82, -1323,   221,   161,   474,   348, -1323,   480, -1323,
   -1323, -1323, -1323, -1323,   482,   147, -1323,   449, -1323, -1323,
   -1323, -1323, -1323, -1323,   442, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   450, -1323,
     500, -1323, -1323, -1323, -1323, -1323, -1323,   467, -1323,   519,
     522,   524, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     476, -1323,   526,   532, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   502, -1323,   539, -1323, -1323, -1323, -1323,
   -1323,   493, -1323, -1323, -1323, -1323, -1323,   495, -1323, -1323,
   -1323, -1323, -1323, -1323,   361, -1323, -1323,   597,   599,   601,
     605,   607,   726,   726,   726,   726,   284,   286,   209,   250,
     278,   309,   726,   276,   287,   274,    44,   272,   556,   593,
     632, -1323,   310, -1323, -1323,   312, -1323,   726, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   304, -1323, -1323,
   -1323,   481, -1323,   485, -1323,   487, -1323,   -15, -1323,   -15,
   -1323,   726, -1323,   -15, -1323,   260, -1323,   260, -1323,   392,
   -1323,   -15, -1323,   -15, -1323,   -15, -1323,   -15, -1323, -1323,
     -15, -1323,   726, -1323,   -15,   316,   320, -1323, -1323, -1323,
     322, -1323,   690,   694, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  -313,  -313,   691, -1323, -1323,   568, -1323,   621,
     695,   701, -1323, -1323, -1323, -1323, -1323,   703,   394, -1323,
     707, -1323, -1323, -1323, -1323, -1323,   709,   154, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   661,   648, -1323,   715,
   -1323, -1323,   740,   741, -1323,   743,   744, -1323,   745, -1323,
     659,   602, -1323,   688,   602, -1323,    52,   404,   248, -1323,
   -1323, -1323,   747,   748,   436,   438,   434,   440, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   726, -1323, -1323, -1323,
   -1323,   673,   757,   759, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   411, -1323, -1323,
      40,   763,   406,   774,   408,   776,   428,   409, -1323,   -15,
   -1323,   383, -1323,   385, -1323,   787,   784, -1323,   786, -1323,
   -1323,   415, -1323,   -15, -1323,   413, -1323,   -15, -1323,   -15,
   -1323,   453, -1323,   726, -1323,   403, -1323, -1323, -1323, -1323,
     798, -1323,   796,   807,   431, -1323, -1323, -1323,   806, -1323,
   -1323, -1323, -1323, -1323,   808,   185, -1323, -1323, -1323, -1323,
   -1323, -1323,   444,   100, -1323, -1323, -1323, -1323, -1323,   810,
     812,   814,   816,   818,   820, -1323, -1323, -1323,   821,   451,
   -1323, -1323, -1323,   454, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   359, -1323,   664, -1323,
     606, -1323, -1323,   828,   824,   825,   826,   827,   829,   830,
     831,   832, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     498, -1323, -1323,   837, -1323, -1323,   -79, -1323,   441,   838,
     839,   833, -1323, -1323, -1323, -1323,   842, -1323,   592, -1323,
     843, -1323,   594, -1323,   844, -1323,   591, -1323, -1323,   475,
   -1323, -1323,   845,   -15,   -15, -1323,   468, -1323,   465,   464,
   -1323, -1323, -1323, -1323, -1323, -1323,   846, -1323, -1323, -1323,
     462, -1323, -1323, -1323, -1323,   848, -1323,   850, -1323, -1323,
     852, -1323,   854, -1323,   856, -1323,   858, -1323,   860,   726,
   -1323, -1323,   866, -1323,   871, -1323,   609, -1323,   877,   879,
     881,  -217, -1323, -1323, -1323, -1323, -1323, -1323,   491,    81,
   -1323,   638, -1323,   885,   887,   889,   891,   893,   895, -1323,
     902,   899, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   614,   -46, -1323, -1323,
   -1323, -1323, -1323, -1323,   903, -1323,   790, -1323, -1323, -1323,
   -1323,   790, -1323, -1323, -1323,   920,   -57,   922,   -57,   924,
     -57,   926,   -57,   928,   -57,   930,   -57,   932,   -57,   934,
     -57,   938,   -57,   957, -1323,   963,   961, -1323, -1323, -1323,
     969,   971,   973,   975,   977,   979,   981, -1323, -1323,   640,
    1000,  1002, -1323, -1323, -1323,   983,  1008,  1010,  1012, -1323,
    1014, -1323,  1018, -1323, -1323, -1323,   651, -1323,   633, -1323,
   -1323, -1323, -1323, -1323, -1323,   619,   439,   726,   453,   453,
     453,   453,   453,   453,   726, -1323, -1323, -1323,   946,   766,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   625,   124, -1323,
     777, -1323,  1028,  1030,  1032, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,  1036,  1038,  1043,  1045,  1047,
    1049,  1051,  1055, -1323,   985, -1323, -1323, -1323, -1323,  1057,
     862,   993, -1323, -1323,   956, -1323,   995, -1323,   835, -1323,
    1072,  1069, -1323, -1323, -1323, -1323, -1323,   835, -1323, -1323,
   -1323,   835, -1323, -1323, -1323,   835, -1323, -1323, -1323,   835,
   -1323, -1323, -1323,   835, -1323, -1323, -1323,   835, -1323, -1323,
   -1323,   835, -1323, -1323, -1323,   835, -1323, -1323, -1323,   -15,
    1073,   867, -1323, -1323,    15,  1075,  1077,  1079,  1083,  1085,
    1087,  1089,  1091, -1323, -1323, -1323,  1093,  1094, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   689, -1323,  1095,  1097,
   -1323, -1323, -1323,   726, -1323,   453, -1323,   453, -1323,   693,
   -1323,   698, -1323,   453, -1323,   692, -1323,   -15,    62, -1323,
   -1323,   840,  1098,   -56, -1323,   851, -1323,  1101, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  1107,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116, -1323,  1117,
   -1323, -1323,  1118,   627, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,  -107,   629,  1119,  1122,   878, -1323,   878,
   -1323,   878, -1323,   878, -1323,   878, -1323,   878, -1323,   878,
   -1323,   878, -1323,   870,  1121, -1323,   914,   602, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   352,
   -1323, -1323, -1323,   706,   716,   724, -1323, -1323,   711, -1323,
     737, -1323,   859,  1129,  1130, -1323, -1323, -1323, -1323, -1323,
      64, -1323, -1323,   -15, -1323, -1323, -1323, -1323,  1133,  1132,
    1134,  1135, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  1138,
   -1323,    37, -1323, -1323, -1323,  1136,   445, -1323,   925,   905,
     635, -1323,   790, -1323, -1323, -1323, -1323,  1137,   907,   916,
     908,   927,   909,   919,   911,   921,   913,   929,   915,   933,
     917,   935,   923,   931, -1323, -1323, -1323, -1323, -1323,   602,
     637, -1323, -1323, -1323,  1153,  1155, -1323, -1323, -1323, -1323,
   -1323, -1323,   894, -1323,   896,  1158,  1163, -1323,   906,  1162,
    1164, -1323, -1323, -1323, -1323, -1323,    69,   855,  1166, -1323,
   -1323, -1323,  1167,  1054, -1323,  1171, -1323,  1170, -1323, -1323,
   -1323, -1323, -1323, -1323,   641, -1323,   790, -1323, -1323, -1323,
   -1323,   940, -1323, -1323, -1323,   643, -1323, -1323, -1323,   645,
   -1323, -1323, -1323,   647, -1323, -1323, -1323,   649, -1323, -1323,
   -1323,   652, -1323, -1323, -1323,   654, -1323, -1323, -1323,   656,
   -1323, -1323, -1323,   658, -1323,   460,   717, -1323, -1323,   790,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   982,  1173,  1174,
   -1323,   918, -1323,   936,  1178,  1179, -1323,   937,  1180,  1181,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  1076,
    1185, -1323,  1065, -1323, -1323, -1323, -1323,   951, -1323, -1323,
     790, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     790, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   790, -1323, -1323, -1323, -1323,
     972,  1186,   719, -1323, -1323, -1323, -1323,   997,  1189,  1191,
   -1323,   939, -1323,   941,  1187,  1194, -1323,  1193,   862, -1323,
    1090, -1323,   959, -1323, -1323,   962,   966,  1099,   -82,   -80,
   -1323,   967,   -78,   -74, -1323,  1100,   968,   721,   267, -1323,
     987, -1323,  1208, -1323,   944, -1323,  1209,   723, -1323, -1323,
   -1323, -1323,  1020,  1211,  1212, -1323,   725, -1323, -1323,  1016,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   727,
   -1323, -1323, -1323,   729, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,  1016, -1323, -1323,   179, -1323,
   -1323, -1323,  1213,  1214, -1323, -1323, -1323, -1323, -1323, -1323,
    1215, -1323,  1218, -1323,   964, -1323,  1217,   731, -1323, -1323,
   -1323,    83, -1323, -1323, -1323,  1216, -1323,   733,  -102, -1323,
     726, -1323, -1323, -1323, -1323,    99, -1323, -1323, -1323,    66,
      59,  1219, -1323,  1013,  1223,  1224, -1323,  1225, -1323,  1226,
   -1323,   970, -1323,  1120, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  1227,  1228, -1323, -1323, -1323,  1124,  1125,  1234,
   -1323,  1231, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
    1127, -1323, -1323, -1323, -1323, -1323,  1239, -1323, -1323,  1236,
    1237, -1323,  1238, -1323, -1323,  1139,   -64,  1241, -1323, -1323,
   -1323,  1140,  1240, -1323,  1141, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  1048,  1243,  1244, -1323, -1323, -1323,  1248,  1245,
   -1323, -1323, -1323, -1323,  1252, -1323,  1251,  1004, -1323, -1323
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   805,     0,     1,   807,    28,     0,     0,
      12,    30,    38,     0,     0,   809,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   806,   812,   810,   814,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   813,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   439,    37,   441,
     808,     0,   783,     0,     0,   816,   817,   781,   782,   815,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   440,   863,   855,   857,   861,   865,   867,   913,   929,
     875,   859,   882,   869,   871,   873,   901,   878,   880,   921,
     917,   925,   845,   849,   853,   891,   884,   886,   888,     0,
     839,   840,   820,   821,   823,   824,   825,   826,   828,   829,
     830,   832,   831,   833,   835,     0,   836,   834,   842,   843,
     844,   818,   894,   819,   822,   841,   837,   838,   827,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,  1029,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   450,   453,   438,   448,   449,   775,     0,   791,     0,
     787,     0,     0,     0,   442,   445,   444,   446,   773,   774,
     443,   785,   786,   447,   789,   790,     0,     0,     0,     0,
       0,     0,   915,   931,     0,     0,     0,     0,     0,     0,
     907,     0,   923,   919,   927,     0,     0,     0,     0,     0,
       0,   811,     0,     0,   784,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1031,     0,     0,     0,     0,   253,     0,   230,
     233,   225,   228,   229,     0,     0,    65,     0,    57,    61,
      63,    62,    64,    75,     0,    67,    71,    73,    72,    74,
      85,    88,    77,    81,    83,    82,    84,   110,     0,   100,
       0,   104,   107,   106,   105,   108,   123,     0,   112,     0,
       0,     0,   116,   121,   120,   122,   118,   117,   119,   137,
       0,   125,     0,     0,   129,   134,   133,   135,   136,   131,
     130,   132,   148,     0,   139,     0,   143,   147,   145,   144,
     146,     0,   150,   154,   156,   155,   157,     0,   169,   173,
     175,   174,   176,   455,     0,   470,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   847,     0,   846,   851,     0,   850,     0,   963,   968,
     973,   978,   981,   990,   995,  1001,  1005,  1008,  1011,  1014,
    1016,  1021,  1024,  1027,   953,   984,   987,     0,   933,   954,
     934,     0,   935,     0,   936,     0,   937,     0,   938,     0,
     951,     0,   939,     0,   940,   991,   941,   996,   942,     0,
     943,     0,   944,     0,   945,     0,   946,     0,   947,   948,
       0,   949,     0,   950,     0,     0,     0,   879,   877,   892,
       0,   795,     0,     0,   896,   897,   793,   794,   890,   895,
     898,   759,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,  1032,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   451,   452,     0,   456,   776,
     792,   788,     0,     0,     0,     0,     0,     0,   866,   868,
     914,   916,   930,   932,   876,   860,     0,   870,   872,   874,
     903,     0,     0,     0,   902,   908,   909,   910,   881,   922,
     924,   918,   920,   926,   928,   848,   852,     0,  1018,   885,
       0,     0,     0,     0,     0,     0,     0,     0,   977,     0,
     980,     0,   983,     0,   986,     0,     0,   992,     0,   997,
    1002,     0,  1000,     0,  1004,     0,  1007,     0,  1010,     0,
    1013,     0,  1020,     0,  1023,     0,  1026,   887,   889,   893,
       0,   899,     0,     0,     0,   357,   390,   390,     0,  1036,
    1038,  1030,  1034,  1035,     0,     0,   368,   232,   236,   231,
     234,   238,     0,   208,    99,    86,    91,    89,    93,     0,
       0,     0,     0,     0,     0,   375,   168,   158,     0,     0,
     161,   187,   177,     0,   180,   710,   484,   661,   516,   533,
     635,   618,   570,   594,   688,   705,   471,   472,   486,   475,
     518,   478,   535,   479,   572,   480,   596,   476,   620,   477,
     637,   473,   663,   474,   690,   481,   706,   482,     0,   469,
       0,   454,   771,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   459,   462,   463,   464,   465,   460,   461,
     467,   466,   769,   770,   746,   748,   864,   856,   858,   862,
       0,   904,   905,     0,   390,   854,     0,   958,     0,     0,
       0,     0,   956,   955,   952,   957,     0,   964,     0,   962,
       0,   969,     0,   967,     0,   974,     0,   972,   979,     0,
     985,   988,     0,     0,     0,  1003,     0,  1009,     0,     0,
    1084,  1078,  1081,  1059,  1071,  1090,     0,  1087,  1068,  1047,
       0,  1048,  1049,  1063,  1050,     0,  1051,     0,  1052,  1053,
       0,  1054,     0,  1055,     0,  1056,     0,  1057,     0,     0,
    1028,   796,     0,   288,     0,   295,   298,   292,     0,     0,
       0,     0,   369,   258,   262,   257,   260,   264,     0,   237,
     222,     0,   206,     0,     0,     0,     0,     0,     0,   803,
       0,     0,   210,   215,   217,   213,   214,   216,   218,   212,
     211,   221,   219,   220,   801,   802,     0,    92,   109,   370,
     371,   372,   373,   374,     0,   164,   399,   159,   162,   163,
     183,   399,   178,   181,   182,     0,   485,     0,   517,     0,
     534,     0,   571,     0,   595,     0,   619,     0,   636,     0,
     662,     0,   689,     0,   707,     0,     0,   711,   468,   390,
       0,     0,     0,     0,     0,     0,     0,   390,   883,     0,
       0,     0,  1017,  1019,   959,     0,     0,     0,     0,   965,
       0,   970,     0,   975,   982,   999,     0,   989,     0,   994,
    1006,  1012,  1015,  1073,  1022,     0,  1062,     0,     0,     0,
       0,     0,     0,     0,     0,   900,   294,   300,     0,   317,
     363,   364,  1033,  1037,  1041,  1039,  1043,     0,   263,   248,
       0,   235,     0,     0,     0,   239,   245,   242,   243,   244,
     241,   240,   247,   246,   223,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,    90,    94,    96,    95,     0,
       0,     0,   166,   396,   397,   398,     0,   185,     0,   779,
       0,     0,   487,   488,   489,   777,   778,     0,   519,   520,
     521,     0,   536,   537,   538,     0,   573,   574,   575,     0,
     597,   598,   599,     0,   621,   622,   623,     0,   638,   639,
     640,     0,   664,   665,   666,     0,   691,   692,   693,     0,
       0,     0,   709,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,   912,   911,     0,     0,   961,   966,
     971,   976,   993,   998,  1075,  1060,     0,  1058,     0,     0,
    1066,  1065,  1064,     0,  1067,     0,  1070,     0,  1077,     0,
    1080,     0,  1083,     0,  1086,     0,  1089,     0,     0,   296,
     319,   336,     0,  1042,   275,     0,   261,     0,   265,   270,
     272,   268,   269,   271,   273,   267,   266,   274,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   804,     0,
      98,   747,     0,     0,   167,   165,   402,   400,   404,   186,
     184,   494,   483,   491,     0,     0,     0,   500,   515,   500,
     532,   500,   569,   500,   593,   500,   617,   500,   634,   500,
     660,   500,   687,     0,     0,   715,     0,     0,   389,   752,
     762,   763,   753,   754,   755,   756,   768,   376,   960,     0,
    1061,   390,   390,     0,     0,     0,  1082,  1085,     0,  1091,
       0,   308,   312,     0,     0,   301,   302,   303,   299,   306,
       0,   338,   297,     0,  1045,  1046,  1044,   276,     0,     0,
       0,     0,   377,   384,   378,   385,   380,   381,   761,     0,
     413,     0,   409,   410,   411,     0,   403,   502,     0,     0,
       0,   497,   399,   493,   495,   496,   780,     0,   524,     0,
     541,     0,   578,     0,   602,     0,   626,     0,   643,     0,
     669,     0,   696,     0,   708,   704,   745,   723,   730,     0,
       0,   716,  1074,  1076,     0,     0,  1069,  1072,  1079,  1088,
    1025,   309,   312,   310,     0,     0,     0,   327,   331,     0,
       0,   320,   321,   322,   318,   325,     0,     0,     0,   382,
     386,   379,     0,     0,   412,     0,   401,     0,   405,   407,
     406,   490,   509,   492,     0,   505,   399,   501,   503,   504,
     499,     0,   749,   526,   523,     0,   522,   543,   540,     0,
     539,   580,   577,     0,   576,   604,   601,     0,   600,   628,
     625,     0,   624,   645,   642,     0,   641,   671,   668,     0,
     667,   698,   695,     0,   694,     0,     0,   724,   719,   399,
     714,   717,   718,   767,   766,   307,   311,     0,     0,     0,
     328,   331,   329,     0,     0,     0,   345,   349,     0,     0,
     339,   340,   337,   343,   341,  1040,   383,   751,   414,     0,
       0,   512,   417,   508,   510,   511,   507,     0,   498,   529,
     399,   525,   527,   528,   546,   549,   542,   544,   545,   583,
     585,   579,   581,   582,   607,   609,   603,   605,   606,   631,
     399,   627,   629,   630,   648,   650,   644,   646,   647,   674,
     676,   670,   672,   673,   701,   431,   697,   699,   700,   713,
     733,   712,   731,   735,   727,   399,   722,   725,   726,   721,
       0,     0,     0,   305,   304,   326,   330,     0,     0,     0,
     346,   349,   347,     0,     0,     0,   408,     0,     0,   514,
     415,   416,     0,   506,   531,     0,     0,   548,     0,     0,
     633,     0,     0,     0,   703,   430,     0,     0,   734,   729,
       0,   720,     0,   315,     0,   313,     0,     0,   324,   323,
     344,   348,     0,     0,     0,   760,     0,   420,   418,   421,
     513,   530,   547,   552,   550,   554,   588,   584,   586,     0,
     612,   608,   610,     0,   632,   653,   649,   651,   654,   679,
     675,   677,   680,   434,   432,   435,   702,   743,   453,   732,
     741,   742,     0,     0,   736,   737,   738,   739,   740,   728,
       0,   316,     0,   334,     0,   332,     0,     0,   362,   342,
     428,     0,   424,   425,   426,     0,   422,     0,   553,   591,
       0,   587,   589,   590,   615,     0,   611,   613,   614,     0,
       0,     0,   436,     0,     0,     0,   314,     0,   335,     0,
     352,     0,   350,     0,   427,   390,   419,   560,   562,   551,
     558,   559,     0,     0,   555,   556,   557,     0,     0,     0,
     799,     0,   655,   652,   658,   657,   656,   797,   798,   686,
       0,   681,   678,   684,   683,   682,     0,   433,   744,     0,
       0,   333,     0,   353,   429,     0,     0,     0,   390,   592,
     616,     0,     0,   685,     0,   757,   758,   351,   423,   561,
     565,   563,   566,     0,     0,   659,   800,   437,     0,     0,
     567,   750,   765,   390,     0,   564,     0,     0,   764,   568
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   942, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   -42, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,  -130, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -219, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,  1009,  1011, -1323, -1323, -1323, -1323,
   -1323,   266,   268, -1323,  -807, -1323, -1323, -1323,   269,   270,
   -1323,  -569, -1323,  -277, -1323,  -882, -1322, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  -289, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -571, -1323,
   -1323, -1323, -1323, -1323,  -665, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -241,  -562,  -240,
    -372, -1323,  -216, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     138,  -326,  -848, -1323, -1323, -1323, -1323,  -325,  -324, -1323,
   -1323, -1323, -1323,  -218, -1323, -1323,  -329, -1323, -1323,  -719,
   -1323, -1323,  -234, -1323, -1323,  -312, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,  -101, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
    -285, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   780,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
    -914,  -317, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   697,   698,   896,   897,  1026,  1025,   695,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   709,   907,   908,   909,  1031,  1165,   707,
     158,   159,   259,   260,   419,   418,   583,   584,   713,   912,
     913,   914,  1036,  1170,   712,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     692,   693,   882,   872,   125,   126,   235,   341,   342,   343,
     689,   557,   690,   691,   868,   869,  1005,  1001,   232,   233,
     336,   553,   554,   555,   865,   685,   866,   867,   997,   998,
    1138,  1136,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   674,   857,   988,   989,  1128,  1225,  1226,
    1227,  1228,  1229,  1302,  1303,  1304,  1472,  1515,  1131,  1230,
    1311,  1312,  1313,  1314,  1315,  1391,  1392,  1393,  1517,  1575,
    1232,  1316,  1400,  1401,  1402,  1403,  1481,  1482,  1483,  1577,
    1612,   122,   123,   542,   331,   543,  1404,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     792,   883,   884,  1006,   885,   886,  1008,  1142,   887,   888,
    1009,   224,  1083,   225,   326,  1032,  1033,  1034,  1167,  1168,
    1255,  1256,  1328,  1326,  1035,  1252,  1253,  1254,  1489,  1490,
    1528,  1529,  1585,  1616,  1491,  1582,  1583,  1584,  1504,  1505,
    1554,  1555,  1601,  1647,    98,    99,   160,   161,   274,   263,
     264,   265,   424,   425,   426,   587,   588,   762,   751,   586,
     726,   727,   728,   915,   916,  1042,  1172,  1258,  1173,  1174,
    1263,  1264,  1265,  1341,  1259,  1260,  1337,  1338,  1339,  1417,
    1333,  1334,  1413,  1414,  1415,  1492,   729,   730,   917,   918,
    1048,  1178,  1269,  1344,  1345,  1421,  1422,  1423,  1495,   731,
     732,   919,   920,  1052,  1180,  1271,  1348,  1349,  1426,  1427,
    1428,  1496,  1497,  1534,  1535,  1587,  1588,  1624,  1619,  1620,
    1621,  1656,  1671,  1672,  1679,  1685,   733,   734,   921,   922,
    1056,  1182,  1273,  1352,  1353,  1431,  1432,  1433,  1498,  1538,
    1539,  1591,  1592,  1593,   735,   736,   923,   924,  1060,  1184,
    1275,  1356,  1357,  1436,  1437,  1438,  1499,  1542,  1543,  1596,
    1597,  1598,   737,   738,   925,   926,  1064,  1186,  1277,  1360,
    1361,  1441,  1442,  1443,  1501,   739,   740,   927,   928,  1068,
    1188,  1279,  1364,  1365,  1446,  1447,  1448,  1502,  1547,  1548,
    1599,  1632,  1633,   741,   742,   929,   930,  1072,  1190,  1281,
    1368,  1369,  1451,  1452,  1453,  1503,  1551,  1552,  1600,  1641,
    1642,   743,   744,   931,   932,  1076,  1192,  1283,  1372,  1373,
    1456,  1457,  1458,  1506,   745,   746,   933,  1285,   747,   748,
     936,  1082,  1461,  1196,  1197,  1290,  1380,  1381,  1382,  1470,
    1288,  1289,  1376,  1466,  1467,  1468,  1510,  1375,  1462,  1463,
    1507,  1508,  1564,  1559,  1560,  1561,   937,   275,   710,   276,
    1043,  1625,  1163,   763,   764,   765,   766,   767,  1565,  1566,
     105,  1329,   891,   768,   769,  1680,  1626,  1110,  1111,   770,
     771,   772,   773,   277,   278,   279,  1044,  1045,  1046,   106,
     107,   108,   280,   281,   282,   283,   284,   285,   525,   526,
     527,  1636,  1637,  1638,   893,   894,   895,     7,     8,    15,
      25,    46,    47,    67,    68,   109,   829,   190,   305,   453,
     191,   306,   456,   192,   307,   193,   287,   194,   288,   195,
     295,   196,   289,   197,   286,   198,   290,   199,   291,   200,
     297,   201,   298,   202,   299,   203,   294,   204,   205,   518,
     206,   301,   207,   296,   208,   308,   209,   309,   210,   310,
     211,   212,   528,   313,   529,   530,   852,   213,   300,   614,
     949,   446,   615,   616,   617,   214,   292,   438,   215,   303,
     449,   216,   302,   448,   217,   304,   450,   218,   293,   439,
     477,   478,   479,   630,   793,   794,   795,   480,   481,   799,
     632,   482,   483,   803,   634,   484,   485,   807,   636,   486,
     487,   638,   488,   489,   640,   490,   491,   642,   492,   493,
     644,   494,   495,   646,   967,   496,   497,   648,   969,   647,
     498,   499,   652,   500,   501,   654,   502,   503,   656,   504,
     505,   658,   506,   507,   660,   508,   628,   786,   509,   510,
     662,   511,   512,   664,   513,   514,   666,   333,   334,   548,
     549,   681,   682,   683,   861,   995,   996,  1132,  1133,  1236,
     830,   831,   832,   833,  1107,   975,   976,  1112,   834,   835,
    1114,   836,   837,  1116,   838,  1104,  1209,   839,   840,  1118,
     841,   842,  1120,   843,   844,  1122,   845,   846,  1124,   847,
     848,  1126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     189,   524,   700,   350,   351,   357,   358,   364,   365,   373,
     374,   386,   387,   399,   400,   408,   409,   414,   415,   420,
     421,  1012,   714,  1198,   515,   516,   352,   934,   359,  1037,
     366,  1536,   375,  1540,   388,  1545,   401,   370,   410,  1549,
     416,  1323,   422,   532,   533,   320,   321,   519,   520,  1027,
    1669,   787,   788,    70,    71,   610,   611,  1469,    27,    28,
      72,    73,  1007,   789,  1115,  1117,  1119,  1121,  1123,  1125,
    1639,  1640,     1,  1221,  1222,  1307,  1308,  1622,  1629,     5,
    1396,  1397,   102,   103,  1223,     6,  1309,  1613,   268,   269,
      44,  1398,    45,   538,   539,     9,   266,   267,   993,    11,
     994,  1623,   540,   541,   312,  1039,  1040,   858,   859,   877,
      96,    97,  1002,  1041,  1003,  1004,    38,    39,  1500,   322,
     323,   324,   325,    14,   873,   874,   875,   876,   877,    16,
     878,   272,   273,  1257,    18,  -500,   405,    53,    54,    21,
     266,   267,   104,  1509,    59,    60,    85,    86,   873,   874,
     875,   876,   877,    24,   881,    26,  1137,    82,    83,  1324,
      31,  1537,    34,  1541,    37,  1546,   118,   119,    43,  1550,
     268,   269,    48,   458,    50,   272,   273,   459,   521,   522,
    1670,   460,   238,   239,    58,   432,   433,   434,   435,   436,
     437,  1141,    64,   440,   441,   442,   443,   444,   445,    66,
     447,  1214,   637,  1215,   639,  1614,   457,    69,   643,  1218,
    1630,  1631,    90,   266,   267,   951,   653,    93,   655,   100,
     657,    95,   659,   261,   262,   661,   339,   340,   101,   665,
     346,   347,   266,   267,   110,  1310,   111,   458,   790,  1224,
      74,   459,   612,  1399,    75,   460,   613,   112,   272,   273,
     879,   880,  1108,  1109,   266,   267,   266,   267,   115,   881,
     379,   380,   715,   392,   393,  1327,   881,   272,   273,   353,
     354,   113,   716,   114,   717,   124,   718,   127,   719,   130,
     720,   881,   721,   219,   722,   220,   723,   221,   724,   272,
     273,   272,   273,   360,   361,  1293,   222,   461,   725,   462,
     881,   463,   223,   464,   226,   465,   227,   466,   229,   467,
     230,   468,   231,   469,   237,   470,   952,   471,   234,   472,
     311,   473,   314,   474,   315,   475,   332,   476,   379,   380,
     381,   594,   595,   596,   597,   367,   368,   601,   603,   376,
     377,   606,   389,   390,   402,   403,   316,   620,   622,   624,
     451,   452,   454,   455,   809,   317,   627,   266,   267,   551,
     552,   461,   318,   462,   319,   463,   327,   464,   816,   465,
     335,   466,   818,   467,   819,   468,   338,   469,  1092,   470,
    1340,   471,   344,   472,   411,   473,   417,   474,   423,   475,
     641,   476,   272,   273,   266,   267,   268,   269,   559,   560,
     427,   268,   269,   650,   651,   679,   680,   430,  1330,   687,
     688,   663,   752,   753,  1235,   749,   750,   797,   798,   801,
     802,   428,   270,   271,   429,   266,   267,   270,   271,   272,
     273,   754,   755,   756,   757,   758,   759,   760,   761,   805,
     806,   431,   855,   856,   863,   864,   517,   322,   323,   324,
     325,   531,   889,   890,  1416,   870,   871,   535,  1562,  1563,
     272,   273,   905,   906,   534,   910,   911,   523,   537,   791,
     546,   322,   323,   324,   325,   892,  1177,   547,   131,   132,
    1179,   133,   550,   134,  1181,   135,   556,   136,  1183,   137,
     558,   138,  1185,   139,   565,   140,  1187,   102,   103,   564,
    1189,   953,   999,  1000,  1191,   780,   568,   820,   569,   821,
     782,   822,  1268,   823,  1270,   824,  1272,   825,  1274,   826,
    1276,   827,  1278,   828,  1280,   570,  1282,   571,   966,   968,
     572,   162,   573,   163,   575,   164,   574,   165,  1494,   166,
     576,   167,   578,   168,   600,   169,  1049,   170,  1053,   171,
    1057,   172,  1061,   173,  1065,   174,  1069,   175,  1073,   176,
    1077,   177,   849,   178,   577,   179,   579,   180,   585,   181,
     582,   182,   162,   183,   163,   184,   164,   185,   165,   186,
     166,   187,   167,   188,   168,  1028,   169,   602,   170,  1050,
     171,  1054,   172,  1058,   173,  1062,   174,  1066,   175,  1070,
     176,  1074,   177,  1078,   178,   589,   179,   590,   180,   591,
     181,   592,   182,   593,   183,   598,   184,   604,   185,   599,
     186,   607,   187,   609,   188,  1023,  1024,   618,  1010,  1011,
    1105,  1106,  1108,  1109,   608,  1291,  1134,  1135,  1250,  1251,
    1261,  1262,  1294,  1295,  1327,   881,  1335,  1336,  1378,  1379,
     605,  1013,  1411,  1412,  1419,  1420,  1424,  1425,  1429,  1430,
    1434,  1435,  1084,  1439,  1440,  1444,  1445,  1449,  1450,  1454,
    1455,  1459,  1460,   625,   162,   629,   163,   626,   164,   631,
     165,  1586,   166,   633,   167,   635,   168,   645,   169,   667,
     170,   669,   171,   670,   172,   668,   173,   671,   174,   672,
     175,   673,   176,   676,   177,   675,   178,  1602,   179,   677,
     180,   678,   181,   684,   182,   694,   183,   686,   184,   696,
     185,   699,   186,   706,   187,   708,   188,  1377,  1464,  1465,
    1513,  1514,  1557,  1558,  1573,  1574,  1580,  1581,  1589,  1590,
    1594,  1595,  1610,  1611,  1617,  1618,   701,   702,   984,   703,
     704,  1635,  1643,   705,   711,   774,   775,  1145,  1146,   776,
     820,   778,   821,   777,   822,   783,   823,   784,   824,   779,
     825,   796,   826,  1292,   827,   162,   828,   163,   785,   164,
    1147,   165,   800,   166,   804,   167,   808,   168,   810,   169,
     812,   170,   811,   171,  1193,   172,   813,   173,   814,   174,
     815,   175,   817,   176,   850,   177,   851,   178,   853,   179,
     854,   180,   860,   181,   938,   182,   862,   183,   898,   184,
     899,   185,   900,   186,   901,   187,   902,   188,   903,   904,
     935,   939,   940,   941,   942,   943,   957,   944,   945,   946,
     947,   948,  1220,   950,   954,   959,   955,   956,   958,   960,
     962,   961,   963,   965,   964,   970,   971,   972,   973,   974,
     977,   820,   978,   821,   979,   822,   980,   823,   981,   824,
     982,   825,   983,   826,   985,   827,  1113,   828,   162,   986,
     163,   987,   164,  1127,   165,   990,   166,   991,   167,   992,
     168,  1014,   169,  1015,   170,  1016,   171,  1017,   172,  1018,
     173,  1019,   174,  1020,   175,  1021,   176,  1022,   177,  1029,
     178,  1030,   179,   619,   180,   162,   181,   163,   182,   164,
     183,   165,   184,   166,   185,   167,   186,   168,   187,   169,
     188,   170,  1038,   171,  1047,   172,  1051,   173,  1055,   174,
    1059,   175,  1063,   176,  1067,   177,  1071,   178,  1317,   179,
    1075,   180,   621,   181,   162,   182,   163,   183,   164,   184,
     165,   185,   166,   186,   167,   187,   168,   188,   169,  1079,
     170,  1080,   171,  1081,   172,  1085,   173,  1086,   174,  1087,
     175,  1088,   176,  1089,   177,  1090,   178,  1091,   179,  1096,
     180,  1093,   181,   623,   182,   162,   183,   163,   184,   164,
     185,   165,   186,   166,   187,   167,   188,   168,  1094,   169,
    1095,   170,  1213,   171,  1097,   172,  1103,   173,  1098,   174,
    1099,   175,  1100,   176,   781,   177,  1101,   178,  1129,   179,
    1130,   180,  1102,   181,  1148,   182,  1149,   183,  1150,   184,
    1151,   185,  1152,   186,  1153,   187,  1655,   188,   162,  1154,
     163,  1155,   164,  1156,   165,  1157,   166,  1160,   167,  1158,
     168,  1159,   169,  1162,   170,  1161,   171,  1164,   172,  1166,
     173,  1169,   174,  1171,   175,  1175,   176,  1176,   177,  1194,
     178,  1195,   179,  1199,   180,  1200,   181,  1201,   182,  1674,
     183,  1202,   184,  1203,   185,  1204,   186,  1205,   187,  1206,
     188,  1207,  1208,  1211,  1210,  1212,  1216,  1217,  1231,  1238,
    1233,  1219,  1237,  1239,  1686,  1240,  1241,  1284,  1257,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,  1249,  1266,  1267,  1286,
    1287,  1296,  1301,  1297,  1299,  1298,  1300,  1305,  1306,  1318,
    1319,  1346,  1320,  1321,  1322,  1342,  1331,  1332,  1325,  1343,
    1347,  1351,  1354,  1355,  1350,  1359,  1358,  1363,  1370,  1367,
    1362,  1383,  1366,  1384,  1388,  1371,  1387,  1385,  1374,  1389,
    1394,  1390,  1395,  1405,  1406,  1407,  1408,  1409,  1410,  1418,
    1471,  1473,  1474,  1475,  1478,  1479,  1488,  1511,  1484,  1485,
    1486,  1487,  1493,  1523,  1512,  1516,  1568,  1518,  1477,  1519,
    1524,  1525,  1530,  1527,  1569,  1531,  1480,  1522,  1520,  1532,
    1544,  1556,  1533,  1553,  1570,  1571,   881,  1572,  1576,  1578,
    1579,  1604,  1605,  1606,  1607,  1609,  1648,  1608,  1615,  1649,
    1650,  1646,  1652,  1651,  1662,  1657,  1658,  1653,  1659,  1660,
    1661,  1663,  1654,  1664,  1665,  1666,  1667,  1673,  1676,  1689,
    1678,  1681,  1682,  1668,  1675,  1677,  1683,  1684,  1687,  1688,
    1386,  1476,  1521,   395,  1139,   396,  1140,  1143,  1144,  1603,
     536,  1234,  1526,  1634,  1567,  1644,  1645,   649,  1628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1627
};

static const yytype_int16 yycheck[] =
{
     101,   313,   571,   244,   244,   246,   246,   248,   248,   250,
     250,   252,   252,   254,   254,   256,   256,   258,   258,   260,
     260,   869,   584,     8,   309,   310,   244,   746,   246,   911,
     248,   113,   250,   113,   252,   113,   254,    29,   256,   113,
     258,     4,   260,   320,   321,     6,     7,    11,    12,   897,
     114,    11,    12,    11,    12,    11,    12,  1379,    44,    45,
      18,    19,   869,    23,   978,   979,   980,   981,   982,   983,
      11,    12,    43,    11,    12,    11,    12,   179,    12,     0,
      11,    12,   138,   139,    22,   309,    22,     4,   134,   135,
     310,    22,   312,    11,    12,    15,   132,   133,   315,   204,
     317,   203,    20,    21,   205,   162,   163,   676,   677,    28,
     205,   206,    31,   170,    33,    34,    11,    12,  1440,   432,
     433,   434,   435,   311,    24,    25,    26,    27,    28,     8,
      30,   167,   168,   240,    47,   242,    14,    11,    12,   169,
     132,   133,   198,  1465,    11,    12,    11,    12,    24,    25,
      26,    27,    28,     8,   200,     6,    32,    41,    42,   122,
     248,   243,    16,   243,     8,   243,    78,    79,     6,   243,
     134,   135,     8,   252,    77,   167,   168,   256,   142,   143,
     244,   260,    11,    12,     8,   286,   287,   288,   289,   290,
     291,   998,     6,   294,   295,   296,   297,   298,   299,     8,
     301,  1115,   487,  1117,   489,   122,   307,    12,   493,  1123,
     144,   145,   250,   132,   133,   784,   501,     6,   503,    12,
     505,     8,   507,    11,    12,   510,    11,    12,    12,   514,
      11,    12,   132,   133,    46,   171,     8,   252,   198,   177,
     198,   256,   198,   174,   202,   260,   202,     8,   167,   168,
     150,   151,   193,   194,   132,   133,   132,   133,    40,   200,
      35,    36,   210,    38,    39,   199,   200,   167,   168,    11,
      12,     8,   220,     8,   222,   254,   224,   182,   226,     8,
     228,   200,   230,     3,   232,     8,   234,     6,   236,   167,
     168,   167,   168,    11,    12,  1209,     6,   376,   246,   378,
     200,   380,     6,   382,    78,   384,    17,   386,    78,   388,
      83,   390,   258,   392,     8,   394,   395,   396,   181,   398,
     313,   400,     8,   402,     6,   404,   314,   406,    35,    36,
      37,   432,   433,   434,   435,    11,    12,   438,   439,    11,
      12,   442,    11,    12,    11,    12,     8,   448,   449,   450,
      11,    12,    11,    12,   639,     8,   457,   132,   133,    11,
      12,   376,     8,   378,     8,   380,     8,   382,   653,   384,
     180,   386,   657,   388,   659,   390,     8,   392,   947,   394,
    1262,   396,     6,   398,    12,   400,    12,   402,   209,   404,
     491,   406,   167,   168,   132,   133,   134,   135,   251,   252,
       3,   134,   135,    11,    12,    11,    12,     8,  1256,   255,
     256,   512,   164,   165,  1133,    11,    12,    11,    12,    11,
      12,     3,   160,   161,     3,   132,   133,   160,   161,   167,
     168,   183,   184,   185,   186,   187,   188,   189,   190,    11,
      12,     8,    11,    12,   259,   260,   353,   432,   433,   434,
     435,     8,   693,   693,  1336,    11,    12,    80,   191,   192,
     167,   168,    11,    12,     6,    11,    12,   431,    81,   429,
     249,   432,   433,   434,   435,   693,  1047,   316,    48,    49,
    1051,    51,     8,    53,  1055,    55,     6,    57,  1059,    59,
       8,    61,  1063,    63,    52,    65,  1067,   138,   139,    50,
    1071,   786,    11,    12,  1075,   606,    56,   408,     8,   410,
     611,   412,  1177,   414,  1179,   416,  1181,   418,  1183,   420,
    1185,   422,  1187,   424,  1189,    58,  1191,     8,   813,   814,
       8,   322,     8,   324,     8,   326,    60,   328,  1420,   330,
       8,   332,     3,   334,   335,   336,   918,   338,   920,   340,
     922,   342,   924,   344,   926,   346,   928,   348,   930,   350,
     932,   352,   663,   354,    62,   356,    73,   358,   207,   360,
      75,   362,   322,   364,   324,   366,   326,   368,   328,   370,
     330,   372,   332,   374,   334,   897,   336,   337,   338,   918,
     340,   920,   342,   922,   344,   924,   346,   926,   348,   928,
     350,   930,   352,   932,   354,     8,   356,     8,   358,     8,
     360,     6,   362,     6,   364,   331,   366,   339,   368,   333,
     370,   345,   372,   349,   374,    11,    12,   355,   869,   869,
      11,    12,   193,   194,   347,  1197,    11,    12,    11,    12,
      11,    12,  1211,  1212,   199,   200,    11,    12,    11,    12,
     341,   869,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,   939,    11,    12,    11,    12,    11,    12,    11,
      12,   211,   212,   363,   322,   371,   324,   365,   326,   198,
     328,  1529,   330,   198,   332,   198,   334,   427,   336,   373,
     338,   369,   340,     3,   342,   375,   344,     3,   346,     8,
     348,   133,   350,     8,   352,    84,   354,  1555,   356,     8,
     358,     8,   360,     6,   362,    54,   364,     8,   366,    71,
     368,     6,   370,    64,   372,   123,   374,  1289,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,     6,     6,   849,     6,
       6,  1599,  1600,     8,    66,     8,     8,   998,   998,   323,
     408,   327,   410,   325,   412,     8,   414,     8,   416,   329,
     418,     8,   420,   421,   422,   322,   424,   324,   367,   326,
     998,   328,     8,   330,     8,   332,   377,   334,   405,   336,
       3,   338,   407,   340,  1079,   342,    12,   344,    12,   346,
     385,   348,   389,   350,   401,   352,     8,   354,    12,   356,
       3,   358,     6,   360,   208,   362,     8,   364,     8,   366,
       8,   368,     8,   370,     8,   372,     8,   374,     8,     8,
     166,     3,     8,     8,     8,     8,     3,     8,     8,     8,
       8,   343,  1127,     6,   403,   253,     8,     8,     6,     6,
       6,   257,   261,     8,   379,   387,   391,   393,    12,   397,
      12,   408,    12,   410,    12,   412,    12,   414,    12,   416,
      12,   418,    12,   420,     8,   422,   977,   424,   322,     8,
     324,   272,   326,   984,   328,     8,   330,     8,   332,     8,
     334,   253,   336,     8,   338,     8,   340,     8,   342,     8,
     344,     8,   346,     8,   348,     3,   350,     8,   352,     6,
     354,   121,   356,   357,   358,   322,   360,   324,   362,   326,
     364,   328,   366,   330,   368,   332,   370,   334,   372,   336,
     374,   338,    12,   340,    12,   342,    12,   344,    12,   346,
      12,   348,    12,   350,    12,   352,    12,   354,  1233,   356,
      12,   358,   359,   360,   322,   362,   324,   364,   326,   366,
     328,   368,   330,   370,   332,   372,   334,   374,   336,    12,
     338,     8,   340,    12,   342,     6,   344,     6,   346,     6,
     348,     6,   350,     6,   352,     6,   354,     6,   356,     6,
     358,   351,   360,   361,   362,   322,   364,   324,   366,   326,
     368,   328,   370,   330,   372,   332,   374,   334,     8,   336,
       8,   338,  1113,   340,     6,   342,   383,   344,     8,   346,
       8,   348,     8,   350,   351,   352,     8,   354,    82,   356,
     264,   358,   381,   360,   257,   362,     8,   364,     8,   366,
       8,   368,     6,   370,     6,   372,  1615,   374,   322,     6,
     324,     6,   326,     6,   328,     6,   330,    72,   332,     8,
     334,     6,   336,   201,   338,     8,   340,    74,   342,   113,
     344,    76,   346,   238,   348,     3,   350,     8,   352,     6,
     354,   214,   356,     8,   358,     8,   360,     8,   362,  1658,
     364,     8,   366,     8,   368,     8,   370,     8,   372,     8,
     374,     8,     8,     8,   415,     8,   413,   409,   268,     8,
      12,   419,   261,     6,  1683,     6,     6,   247,   240,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     6,     8,
     216,   425,   273,   417,   423,   411,   399,     8,     8,     6,
       8,   225,     8,     8,     6,     8,   221,   242,    12,   242,
     242,   242,   233,   242,   227,   242,   235,   242,   223,   242,
     231,     8,   229,     8,     6,   242,   270,   273,   237,     6,
       8,   265,     8,   318,     8,     8,   122,     6,     8,   239,
     198,     8,     8,   265,     6,     6,   121,   215,     8,     8,
     114,     6,   241,     6,     8,   198,  1508,     8,   262,     8,
       6,     8,   243,   113,   217,   243,   269,   266,   269,   243,
     243,   243,   113,   113,     6,   271,   200,     8,   198,     8,
       8,     8,     8,     8,     6,     8,   213,   263,    12,     6,
       6,    12,     6,     8,     3,     8,     8,   267,   114,   114,
       6,   114,   122,     4,     8,     8,     8,     6,     8,   245,
     202,     8,     8,   114,   114,   114,     8,    12,     6,     8,
    1302,  1391,  1481,   254,   998,   254,   998,   998,   998,  1558,
     328,  1133,  1488,  1599,  1508,  1600,  1600,   497,  1595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    43,   437,   441,   442,     0,   309,   973,   974,    15,
     443,   204,   454,   455,   311,   975,     8,   444,    47,   461,
     462,   169,   456,   655,     8,   976,     6,    44,    45,   445,
     446,   248,   551,   552,    16,   463,   656,     8,    11,    12,
     457,   458,   459,     6,   310,   312,   977,   978,     8,   448,
      77,   598,   599,    11,    12,   553,   554,   555,     8,    11,
      12,   464,   465,   466,     6,   460,     8,   979,   980,    12,
      11,    12,    18,    19,   198,   202,   447,   449,   450,   451,
     452,   453,    41,    42,   438,    11,    12,   600,   601,   602,
     250,   556,   557,     6,   467,     8,   205,   206,   710,   711,
      12,    12,   138,   139,   198,   936,   955,   956,   957,   981,
      46,     8,     8,     8,     8,    40,   439,   440,    78,    79,
     603,   604,   647,   648,   254,   570,   571,   182,   558,   657,
       8,    48,    49,    51,    53,    55,    57,    59,    61,    63,
      65,   468,   469,   470,   475,   476,   481,   482,   496,   497,
     503,   504,   509,   510,   515,   516,   521,   522,   536,   537,
     712,   713,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   982,
     983,   986,   989,   991,   993,   995,   997,   999,  1001,  1003,
    1005,  1007,  1009,  1011,  1013,  1014,  1016,  1018,  1020,  1022,
    1024,  1026,  1027,  1033,  1041,  1044,  1047,  1050,  1053,     3,
       8,     6,     6,     6,   677,   679,    78,    17,   605,    78,
      83,   258,   584,   585,   181,   572,   658,     8,    11,    12,
     559,   560,   561,   471,   472,   477,   478,   483,   484,   498,
     499,   505,   506,   511,   512,   517,   518,   523,   524,   538,
     539,    11,    12,   715,   716,   717,   132,   133,   134,   135,
     160,   161,   167,   168,   714,   923,   925,   949,   950,   951,
     958,   959,   960,   961,   962,   963,  1000,   992,   994,   998,
    1002,  1004,  1042,  1054,  1012,   996,  1019,  1006,  1008,  1010,
    1034,  1017,  1048,  1045,  1051,   984,   987,   990,  1021,  1023,
    1025,   313,   982,  1029,     8,     6,     8,     8,     8,     8,
       6,     7,   432,   433,   434,   435,   680,     8,   606,   607,
     608,   650,   314,  1123,  1124,   180,   586,   659,     8,    11,
      12,   573,   574,   575,     6,   563,    11,    12,   474,   473,
     923,   925,   949,    11,    12,   480,   479,   923,   925,   949,
      11,    12,   486,   485,   923,   925,   949,    11,    12,   502,
      29,   500,   501,   923,   925,   949,    11,    12,   508,    35,
      36,    37,   507,   660,   661,   662,   923,   925,   949,    11,
      12,   514,    38,    39,   513,   660,   661,   663,   664,   923,
     925,   949,    11,    12,   520,    14,   519,   665,   923,   925,
     949,    12,   526,   525,   923,   925,   949,    12,   541,   540,
     923,   925,   949,   209,   718,   719,   720,     3,     3,     3,
       8,     8,   982,   982,   982,   982,   982,   982,  1043,  1055,
     982,   982,   982,   982,   982,   982,  1037,   982,  1049,  1046,
    1052,    11,    12,   985,    11,    12,   988,   982,   252,   256,
     260,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,  1056,  1057,  1058,
    1063,  1064,  1067,  1068,  1071,  1072,  1075,  1076,  1078,  1079,
    1081,  1082,  1084,  1085,  1087,  1088,  1091,  1092,  1096,  1097,
    1099,  1100,  1102,  1103,  1105,  1106,  1108,  1109,  1111,  1114,
    1115,  1117,  1118,  1120,  1121,  1056,  1056,   353,  1015,    11,
      12,   142,   143,   431,   961,   964,   965,   966,  1028,  1030,
    1031,     8,   679,   679,     6,    80,   607,    81,    11,    12,
      20,    21,   649,   651,   653,   654,   249,   316,  1125,  1126,
       8,    11,    12,   587,   588,   589,     6,   577,     8,   251,
     252,   562,   564,   565,    50,    52,   487,   488,    56,     8,
      58,     8,     8,     8,    60,     8,     8,    62,     3,    73,
     527,   528,    75,   542,   543,   207,   725,   721,   722,     8,
       8,     8,     6,     6,   982,   982,   982,   982,   331,   333,
     335,   982,   337,   982,   339,   341,   982,   345,   347,   349,
      11,    12,   198,   202,  1035,  1038,  1039,  1040,   355,   357,
     982,   359,   982,   361,   982,   363,   365,   982,  1112,   371,
    1059,   198,  1066,   198,  1070,   198,  1074,  1056,  1077,  1056,
    1080,   982,  1083,  1056,  1086,   427,  1089,  1095,  1093,  1095,
      11,    12,  1098,  1056,  1101,  1056,  1104,  1056,  1107,  1056,
    1110,  1056,  1116,   982,  1119,  1056,  1122,   373,   375,   369,
       3,     3,     8,   133,   609,    84,     8,     8,     8,    11,
      12,  1127,  1128,  1129,     6,   591,     8,   255,   256,   576,
     578,   579,   566,   567,    54,   495,    71,   489,   490,     6,
     677,     6,     6,     6,     6,     8,    64,   535,   123,   529,
     924,    66,   550,   544,   924,   210,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   246,   726,   727,   728,   752,
     753,   765,   766,   792,   793,   810,   811,   828,   829,   841,
     842,   859,   860,   877,   878,   890,   891,   894,   895,    11,
      12,   724,   164,   165,   183,   184,   185,   186,   187,   188,
     189,   190,   723,   929,   930,   931,   932,   933,   939,   940,
     945,   946,   947,   948,     8,     8,   323,   325,   327,   329,
     982,   351,   982,     8,     8,   367,  1113,    11,    12,    23,
     198,   429,   666,  1060,  1061,  1062,     8,    11,    12,  1065,
       8,    11,    12,  1069,     8,    11,    12,  1073,   377,  1056,
     405,   407,     3,    12,    12,   385,  1056,   389,  1056,  1056,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   982,
    1136,  1137,  1138,  1139,  1144,  1145,  1147,  1148,  1150,  1153,
    1154,  1156,  1157,  1159,  1160,  1162,  1163,  1165,  1166,   982,
     401,     8,  1032,    12,     3,    11,    12,   610,   677,   677,
       6,  1130,     8,   259,   260,   590,   592,   593,   580,   581,
      11,    12,   569,    24,    25,    26,    27,    28,    30,   150,
     151,   200,   568,   667,   668,   670,   671,   674,   675,   923,
     925,   938,   949,   970,   971,   972,   491,   492,     8,     8,
       8,     8,     8,     8,     8,    11,    12,   530,   531,   532,
      11,    12,   545,   546,   547,   729,   730,   754,   755,   767,
     768,   794,   795,   812,   813,   830,   831,   843,   844,   861,
     862,   879,   880,   892,   955,   166,   896,   922,   208,     3,
       8,     8,     8,     8,     8,     8,     8,     8,   343,  1036,
       6,   677,   395,  1056,   403,     8,     8,     3,     6,   253,
       6,   257,     6,   261,   379,     8,  1056,  1090,  1056,  1094,
     387,   391,   393,    12,   397,  1141,  1142,    12,    12,    12,
      12,    12,    12,    12,   982,     8,     8,   272,   611,   612,
       8,     8,     8,   315,   317,  1131,  1132,   594,   595,    11,
      12,   583,    31,    33,    34,   582,   669,   670,   672,   676,
     923,   925,   938,   949,   253,     8,     8,     8,     8,     8,
       8,     3,     8,    11,    12,   494,   493,   938,   961,     6,
     121,   533,   681,   682,   683,   690,   548,   681,    12,   162,
     163,   170,   731,   926,   952,   953,   954,    12,   756,   926,
     952,    12,   769,   926,   952,    12,   796,   926,   952,    12,
     814,   926,   952,    12,   832,   926,   952,    12,   845,   926,
     952,    12,   863,   926,   952,    12,   881,   926,   952,    12,
       8,    12,   897,   678,   679,     6,     6,     6,     6,     6,
       6,     6,   677,   351,     8,     8,     6,     6,     8,     8,
       8,     8,   381,   383,  1151,    11,    12,  1140,   193,   194,
     943,   944,  1143,   982,  1146,  1136,  1149,  1136,  1155,  1136,
    1158,  1136,  1161,  1136,  1164,  1136,  1167,   982,   613,    82,
     264,   624,  1133,  1134,    11,    12,   597,    32,   596,   667,
     668,   670,   673,   674,   675,   923,   925,   949,   257,     8,
       8,     8,     6,     6,     6,     6,     6,     6,     8,     6,
      72,     8,   201,   928,    74,   534,   113,   684,   685,    76,
     549,   238,   732,   734,   735,     3,     8,   734,   757,   734,
     770,   734,   797,   734,   815,   734,   833,   734,   846,   734,
     864,   734,   882,  1056,     6,   214,   899,   900,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,  1152,
     415,     8,     8,   982,  1136,  1136,   413,   409,  1136,   419,
    1056,    11,    12,    22,   177,   614,   615,   616,   617,   618,
     625,   268,   636,    12,   936,   955,  1135,   261,     8,     6,
       6,     6,     8,     8,     8,     8,     8,     8,     8,     8,
      11,    12,   691,   692,   693,   686,   687,   240,   733,   740,
     741,    11,    12,   736,   737,   738,     8,     6,   740,   758,
     740,   771,   740,   798,   740,   816,   740,   834,   740,   847,
     740,   865,   740,   883,   247,   893,     8,   216,   906,   907,
     901,   924,   421,  1136,   677,   677,   425,   417,   411,   423,
     399,   273,   619,   620,   621,     8,     8,    11,    12,    22,
     171,   626,   627,   628,   629,   630,   637,  1056,     6,     8,
       8,     8,     6,     4,   122,    12,   689,   199,   688,   937,
     938,   221,   242,   746,   747,    11,    12,   742,   743,   744,
     681,   739,     8,   242,   759,   760,   225,   242,   772,   773,
     227,   242,   799,   800,   233,   242,   817,   818,   235,   242,
     835,   836,   231,   242,   848,   849,   229,   242,   866,   867,
     223,   242,   884,   885,   237,   913,   908,   924,    11,    12,
     902,   903,   904,     8,     8,   273,   620,   270,     6,     6,
     265,   631,   632,   633,     8,     8,    11,    12,    22,   174,
     638,   639,   640,   641,   652,   318,     8,     8,   122,     6,
       8,    11,    12,   748,   749,   750,   681,   745,   239,    11,
      12,   761,   762,   763,    11,    12,   774,   775,   776,    11,
      12,   801,   802,   803,    11,    12,   819,   820,   821,    11,
      12,   837,   838,   839,    11,    12,   850,   851,   852,    11,
      12,   868,   869,   870,    11,    12,   886,   887,   888,   211,
     212,   898,   914,   915,    11,    12,   909,   910,   911,   682,
     905,   198,   622,     8,     8,   265,   632,   262,     6,     6,
     269,   642,   643,   644,     8,     8,   114,     6,   121,   694,
     695,   700,   751,   241,   681,   764,   777,   778,   804,   822,
     682,   840,   853,   871,   704,   705,   889,   916,   917,   682,
     912,   215,     8,    11,    12,   623,   198,   634,     8,     8,
     269,   643,   266,     6,     6,     8,   928,   113,   696,   697,
     243,   243,   243,   113,   779,   780,   113,   243,   805,   806,
     113,   243,   823,   824,   243,   113,   243,   854,   855,   113,
     243,   872,   873,   113,   706,   707,   243,    11,    12,   919,
     920,   921,   191,   192,   918,   934,   935,   958,   961,   217,
       6,   271,     8,    11,    12,   635,   198,   645,     8,     8,
      11,    12,   701,   702,   703,   698,   938,   781,   782,    11,
      12,   807,   808,   809,    11,    12,   825,   826,   827,   856,
     874,   708,   938,   718,     8,     8,     8,     6,   263,     8,
      11,    12,   646,     4,   122,    12,   699,    11,    12,   784,
     785,   786,   179,   203,   783,   927,   942,   982,  1137,    12,
     144,   145,   857,   858,   937,   938,   967,   968,   969,    11,
      12,   875,   876,   938,   943,   944,    12,   709,   213,     6,
       6,     8,     6,   267,   122,   677,   787,     8,     8,   114,
     114,     6,     3,   114,     4,     8,     8,     8,   114,   114,
     244,   788,   789,     6,   677,   114,     8,   114,   202,   790,
     941,     8,     8,     8,    12,   791,   677,     6,     8,   245
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   436,   437,   438,   438,   439,   440,   440,   441,   441,
     442,   443,   444,   444,   445,   446,   447,   447,   448,   448,
     449,   449,   449,   449,   450,   451,   452,   453,   454,   454,
     455,   456,   457,   457,   458,   459,   460,   460,   461,   461,
     462,   463,   464,   464,   465,   466,   467,   467,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   469,   470,   471,
     472,   472,   473,   473,   473,   474,   474,   475,   476,   477,
     478,   478,   479,   479,   479,   480,   480,   481,   482,   483,
     484,   484,   485,   485,   485,   486,   486,   487,   488,   488,
     489,   490,   491,   492,   492,   493,   493,   494,   494,   495,
     496,   497,   498,   499,   499,   500,   500,   500,   500,   501,
     502,   502,   503,   504,   505,   506,   506,   507,   507,   507,
     507,   507,   507,   508,   508,   509,   510,   511,   512,   512,
     513,   513,   513,   513,   513,   513,   513,   514,   514,   515,
     516,   517,   518,   518,   519,   519,   519,   519,   520,   520,
     521,   522,   523,   524,   524,   525,   525,   525,   526,   527,
     528,   529,   530,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   539,   540,   540,   540,   541,   542,   543,
     544,   545,   545,   546,   547,   548,   549,   550,   551,   551,
     552,   553,   553,   554,   555,   556,   556,   557,   558,   559,
     559,   560,   561,   562,   563,   563,   564,   565,   566,   567,
     567,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   569,   569,   570,   570,   571,   572,   573,   573,
     574,   575,   576,   577,   577,   578,   579,   580,   581,   581,
     582,   582,   582,   582,   582,   582,   582,   582,   583,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   590,   591,
     591,   592,   593,   594,   595,   595,   596,   596,   596,   596,
     596,   596,   596,   596,   596,   597,   597,   598,   598,   599,
     600,   600,   601,   601,   602,   602,   603,   604,   605,   606,
     606,   608,   607,   609,   609,   610,   610,   611,   612,   612,
     613,   613,   614,   614,   615,   616,   617,   617,   618,   618,
     619,   619,   621,   620,   622,   623,   623,   624,   624,   625,
     625,   626,   626,   627,   628,   629,   629,   630,   630,   631,
     631,   633,   632,   634,   635,   635,   636,   636,   637,   637,
     638,   638,   639,   640,   640,   641,   641,   642,   642,   644,
     643,   645,   646,   646,   648,   647,   649,   649,   650,   650,
     651,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   677,   678,
     679,   679,   680,   680,   680,   680,   681,   682,   682,   683,
     683,   684,   685,   686,   687,   687,   688,   688,   689,   690,
     691,   691,   692,   692,   693,   694,   694,   695,   695,   696,
     697,   698,   698,   699,   700,   701,   701,   702,   702,   703,
     704,   705,   705,   706,   707,   708,   708,   709,   710,   711,
     712,   713,   713,   714,   714,   714,   714,   714,   715,   715,
     716,   717,   718,   719,   719,   720,   721,   722,   722,   723,
     723,   723,   723,   723,   723,   723,   723,   723,   724,   724,
     725,   725,   726,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   727,   728,   729,   730,   730,   731,   731,
     732,   733,   733,   734,   735,   736,   736,   737,   738,   739,
     740,   740,   741,   742,   742,   743,   744,   745,   746,   747,
     748,   748,   749,   750,   751,   752,   753,   754,   755,   755,
     756,   756,   757,   758,   759,   759,   760,   761,   761,   762,
     763,   764,   765,   766,   767,   768,   768,   769,   769,   770,
     771,   772,   772,   773,   774,   774,   775,   776,   777,   778,
     778,   779,   780,   781,   782,   782,   783,   783,   784,   784,
     785,   786,   787,   787,   788,   789,   790,   790,   791,   792,
     793,   794,   795,   795,   796,   796,   797,   798,   799,   799,
     800,   801,   801,   802,   803,   804,   804,   805,   806,   807,
     807,   808,   809,   810,   811,   812,   813,   813,   814,   814,
     815,   816,   817,   817,   818,   819,   819,   820,   821,   822,
     822,   823,   824,   825,   825,   826,   827,   828,   829,   830,
     831,   831,   832,   832,   833,   834,   835,   835,   836,   837,
     837,   838,   839,   840,   841,   842,   843,   844,   844,   845,
     845,   846,   847,   848,   848,   849,   850,   850,   851,   852,
     853,   853,   854,   855,   856,   856,   857,   857,   857,   858,
     859,   860,   861,   862,   862,   863,   863,   864,   865,   866,
     866,   867,   868,   868,   869,   870,   871,   871,   872,   873,
     874,   874,   875,   875,   875,   876,   876,   877,   878,   879,
     880,   880,   881,   881,   882,   883,   884,   884,   885,   886,
     886,   887,   888,   889,   890,   891,   892,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   902,   903,
     904,   905,   906,   907,   908,   909,   909,   910,   911,   912,
     913,   913,   914,   915,   916,   917,   917,   918,   918,   918,
     918,   919,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     946,   947,   948,   949,   949,   950,   951,   952,   952,   953,
     954,   955,   955,   956,   957,   958,   958,   959,   960,   961,
     961,   962,   963,   964,   964,   965,   966,   967,   967,   968,
     969,   970,   970,   971,   972,   973,   973,   974,   975,   976,
     976,   977,   978,   979,   980,   980,   981,   981,   982,   982,
     982,   982,   982,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   982,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   982,   982,   982,   984,   983,   985,   985,   987,
     986,   988,   988,   990,   989,   992,   991,   994,   993,   996,
     995,   998,   997,  1000,   999,  1002,  1001,  1004,  1003,  1006,
    1005,  1008,  1007,  1010,  1009,  1012,  1011,  1013,  1014,  1015,
    1017,  1016,  1019,  1018,  1021,  1020,  1023,  1022,  1025,  1024,
    1026,  1027,  1028,  1028,  1029,  1029,  1030,  1030,  1030,  1032,
    1031,  1034,  1033,  1035,  1035,  1036,  1035,  1037,  1037,  1038,
    1038,  1039,  1040,  1042,  1041,  1043,  1043,  1045,  1044,  1046,
    1046,  1048,  1047,  1049,  1049,  1051,  1050,  1052,  1052,  1054,
    1053,  1055,  1055,  1056,  1056,  1056,  1056,  1056,  1056,  1056,
    1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1056,
    1056,  1056,  1057,  1058,  1059,  1059,  1060,  1060,  1061,  1061,
     666,  1062,  1063,  1064,  1065,  1065,  1066,  1067,  1068,  1069,
    1069,  1070,  1071,  1072,  1073,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1089,  1090,  1091,  1092,  1093,  1093,  1094,  1095,
    1096,  1097,  1098,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1112,  1111,  1113,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1123,  1124,  1125,  1126,  1127,  1127,  1128,  1129,  1130,  1130,
    1131,  1132,  1133,  1134,  1134,  1135,  1135,  1136,  1136,  1137,
    1137,  1137,  1137,  1137,  1137,  1137,  1137,  1137,  1138,  1139,
    1140,  1140,  1141,  1142,  1142,  1143,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1151,  1150,  1152,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     0,     0,     4,
       1,     5,     0,     2,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     1,     4,     4,     4,     4,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     2,     3,     3,     4,     1,     5,     1,
       2,     0,     4,     0,     3,     1,     3,     3,     0,     3,
       0,     2,     1,     1,     4,     4,     1,     3,     1,     2,
       1,     2,     0,     4,     4,     1,     2,     0,     3,     0,
       2,     1,     1,     4,     4,     1,     3,     1,     2,     1,
       2,     0,     4,     4,     1,     2,     0,     3,     0,     2,
       1,     1,     4,     1,     3,     1,     2,     1,     2,     0,
       4,     4,     1,     2,     0,     4,     1,     2,     0,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     2,     1,     3,     1,     1,     0,     2,     3,
       1,     0,     1,     3,     3,     1,     1,     2,     1,     3,
       1,     0,     2,     3,     1,     0,     1,     3,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     3,     0,     2,     3,     1,     0,     1,     3,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     2,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     5,     1,     0,     1,     1,     3,
       1,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     0,     4,     1,     5,     0,
       2,     5,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     2,     0,
       3,     1,     2,     0,     5,     0,     5,     0,     5,     0,
       4,     0,     5,     0,     5,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     3,     1,     1,
       0,     4,     0,     6,     0,     4,     0,     4,     0,     4,
       3,     1,     1,     2,     0,     2,     1,     1,     1,     0,
       4,     0,     4,     1,     2,     0,     4,     0,     2,     1,
       1,     4,     4,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     2,
       4,     3,     3,     1,     1,     2,     4,     3,     1,     1,
       2,     4,     3,     1,     1,     2,     4,     2,     1,     2,
       2,     1,     3,     2,     1,     2,     2,     1,     2,     4,
       1,     0,     1,     2,     4,     1,     0,     1,     2,     3,
       2,     1,     1,     2,     2,     1,     3,     2,     1,     2,
       2,     1,     3,     2,     1,     3,     0,     4,     0,     2,
       2,     1,     3,     2,     1,     6,     2,     1,     2,     0,
       3,     1,     1,     4,     1,     1,     1,     3,     0,     2,
       5,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     2,     1,     0,     2,     1,     1,     3,     1,     3,
       3,     1,     3,     0,     5,     0,     2,     3,     1,     3,
       3,     1,     2,     3,     1,     2,     3,     1,     3,     3,
       1,     2
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
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, osinstance, parserData, osglData, osnlData); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (osinstance);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , osinstance, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, osinstance, parserData, osglData, osnlData); \
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
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
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osinstance);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
    }

    break;

  case 7:

    { parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unexpected end of file, expecting </osil>");}

    break;

  case 9:

    {
        if (osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms
                                                             > parserData->qtermcount ) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                    "actual number of qterms less than numberOfQuadraticTerms");

        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
        parserData->parser_errors = "";
    }

    break;

  case 10:

    {
    osinstance->instanceData->quadraticCoefficients = new QuadraticCoefficients();
}

    break;

  case 11:

    { 
if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[-2].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[-2].ival) ];
for(int i = 0; i < (yyvsp[-2].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
parserData->qtermcount = 0;
}

    break;

  case 14:

    {
    parserData->qtermcount++; 
    if(!parserData->qtermidxattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idx is required"); 
    if(!parserData->qtermidxOneattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idxOne is required"); 
    if(!parserData->qtermidxTwoattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idxTwo is required"); 
    parserData->qtermidattON = false; 
    parserData->qtermidxattON = false; 
    parserData->qtermidxOneattON = false; 
    parserData->qtermidxTwoattON = false;
    parserData->qtermcoefattON = false;
}

    break;

  case 15:

    {
    if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= parserData->qtermcount )
        throw ErrorClass("encountered more quadratic terms than specified");
}

    break;

  case 20:

    { if(parserData->qtermidxOneattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxOne attributes"); 
            parserData->qtermidxOneattON = true;  }

    break;

  case 21:

    { if(parserData->qtermidxTwoattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxTwo attributes"); 
            parserData->qtermidxTwoattON = true;  }

    break;

  case 22:

    { if(parserData->qtermcoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm coef attributes"); 
            parserData->qtermcoefattON = true;  }

    break;

  case 23:

    { if(parserData->qtermidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idx attributes"); 
            parserData->qtermidxattON = true;  }

    break;

  case 24:

    {  if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ((yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
}

    break;

  case 25:

    { if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ((yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
}

    break;

  case 26:

    {if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = parserData->tempVal;
}

    break;

  case 27:

    {  if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term exceeds number of constraints");
    if ((yyvsp[-1].ival) < -osinstance->instanceData->objectives->numberOfObjectives)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term refers to nonexisting objective");
}

    break;

  case 29:

    {
    if (osglData->matrixCounter < osglData->numberOfMatrices) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
    osinstance->instanceData->matrices->numberOfMatrices = osglData->numberOfMatrices;
    osinstance->instanceData->matrices->matrix = osglData->matrix;
}

    break;

  case 30:

    {
    osinstance->instanceData->matrices = new Matrices();
    osglData->numberOfMatricesPresent = false;
}

    break;

  case 31:

    {
    if (osglData->numberOfMatrices < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
    {
        osglData->matrix = new OSMatrix*[osglData->numberOfMatrices];
        for (int i=0; i < osglData->numberOfMatrices; i++)
            osglData->matrix[i] = NULL;
    }
}

    break;

  case 39:

    {
    if (parserData->coneCounter < parserData->numberOfCones) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer cones than specified");
}

    break;

  case 40:

    {
    osinstance->instanceData->cones = new Cones();
    parserData->coneCounter = 0;
}

    break;

  case 41:

    {
    if (parserData->numberOfCones < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones cannot be negative");
    else
    {
        osinstance->instanceData->cones->cone = new Cone*[parserData->numberOfCones];
        for (int i=0; i < parserData->numberOfCones; i++)
            osinstance->instanceData->cones->cone[i] = NULL;
    }
}

    break;

  case 45:

    {
}

    break;

  case 47:

    {
    parserData->coneCounter++;
    if (parserData->coneCounter > parserData->numberOfCones)
        throw ErrorClass("encountered more cones than specified");
    osinstance->instanceData->cones->numberOfCones = parserData->coneCounter;
}

    break;

  case 58:

    {
std::cout << "Start nonnegative cone" << std::endl;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonnegativeCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_nonnegative;    
}

    break;

  case 59:

    {
std::cout << "Finish attribute list" << std::endl;
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 62:

    {
std::cout << "Number of rows attribute" << std::endl;
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 63:

    {
std::cout << "Number of columns attribute" << std::endl;
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 64:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 68:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonpositiveCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonpositive;    
}

    break;

  case 69:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 72:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 73:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 74:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 78:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new OrthantCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_orthant;
}

    break;

  case 79:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    osglData->numberOfEl = (osglData->numberOfRows)*(osglData->numberOfColumns);
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub 
        = new double[osglData->numberOfEl];  
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb
        = new double[osglData->numberOfEl];   
    osglData->osglCounter = 0;
}

    break;

  case 82:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 83:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 84:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 86:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of directions does not match");
}

    break;

  case 91:

    {
    osglData->typePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
}

    break;

  case 92:

    {
    double ubt;
    double lbt;
    if (osglData->type == "nonnegative")
    {
        ubt = OSDBL_MAX;
        lbt = 0.0;
    }
    else if (osglData->type == "nonpositive")
    {
        ubt = 0.0;
        lbt = -OSDBL_MAX;
    }
    else if (osglData->type == "free")
    {
        ubt =  OSDBL_MAX;
        lbt = -OSDBL_MAX;
    }
    else if (osglData->type == "zero")
    {
        ubt = 0.0;
        lbt = 0.0;
    }
    else
    {
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unrecognized direction type");
    }
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Too many directions given");
    else
        for (int i=0; i < osglData->mult; i++)
        {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub[osglData->osglCounter+i] = ubt;
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb[osglData->osglCounter+i] = lbt;
        }
    osglData->osglCounter += osglData->mult;
}

    break;

  case 101:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new PolyhedralCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_polyhedral;    
}

    break;

  case 102:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 105:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 106:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 107:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->referenceMatrixIdx
                = parserData->referenceMatrixIdx;
        }

    break;

  case 108:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 109:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->referenceMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "polyhedral cone referenceMatrixIdx attribute previously set");
    parserData->referenceMatrixIdxPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index cannot be negative");
    else parserData->referenceMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 113:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->axisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new QuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_quadratic;    
}

    break;

  case 114:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    if (parserData->axisDirectionPresent)
    {
        if (parserData->axisDirection >= 
                ( ((QuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((QuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "axis direction index exceeds number of dimensions");
        if (parserData->axisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "axis direction index cannot be negative");
    }
}

    break;

  case 117:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 118:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 119:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 120:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }

    break;

  case 121:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }

    break;

  case 122:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->axisDirection
                = parserData->axisDirection;
        }

    break;

  case 126:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->firstAxisDirectionPresent = false;
    parserData->secondAxisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new RotatedQuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_rotatedQuadratic;    
}

    break;

  case 127:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    if (parserData->firstAxisDirectionPresent)
    {
        if (parserData->firstAxisDirection >= 
                ( ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "first axis direction index exceeds number of dimensions");
        if (parserData->firstAxisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "first axis direction index cannot be negative");
    }
    if (parserData->secondAxisDirectionPresent)
    {
        if (parserData->secondAxisDirection >= 
                ( ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "second axis direction index exceeds number of dimensions");
        if (parserData->secondAxisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "second axis direction index cannot be negative");
    }
}

    break;

  case 130:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 131:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 132:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name
                = osglData->name;
        }

    break;

  case 133:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }

    break;

  case 134:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }

    break;

  case 135:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->firstAxisDirection
                = parserData->firstAxisDirection;
        }

    break;

  case 136:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->secondAxisDirection
                = parserData->secondAxisDirection;
        }

    break;

  case 140:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->semidefinitenessPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new SemidefiniteCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_semidefinite;    
}

    break;

  case 141:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 144:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 145:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 146:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 147:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->semidefiniteness
                = parserData->semidefiniteness;
        }

    break;

  case 151:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new ProductCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_product;    
}

    break;

  case 152:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 155:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 156:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 157:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 160:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 161:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 166:

    {
    // factors must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "product cone factor has illegal index");
}

    break;

  case 167:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of factors does not match numberOfEl");
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors = new IntVector();
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors->numberOfEl
        = osglData->numberOfEl;
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors ->el 
        = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 170:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new IntersectionCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_intersection;    
}

    break;

  case 171:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
}

    break;

  case 174:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 175:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }

    break;

  case 176:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }

    break;

  case 179:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 180:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 185:

    {
    // components must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "intersection cone component has illegal index");
}

    break;

  case 186:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of components does not match numberOfEl");
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components = new IntVector();
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components->numberOfEl
        = osglData->numberOfEl;
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components ->el 
        = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 190:

    {
    osinstance->instanceData->matrixProgramming = new MatrixProgramming();
}

    break;

  case 196:

    {  
        if (parserData->kounter < parserData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixVar less than number attribute");   
    }

    break;

  case 197:

    {
    osinstance->instanceData->matrixProgramming->matrixVariables = new MatrixVariables(); 
}

    break;

  case 198:

    {
    osinstance->instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar = parserData->numberOfMatrixVar;
    osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar
        = new MatrixVar*[parserData->numberOfMatrixVar];
    for (int i=0; i < parserData->numberOfMatrixVar; i++)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i] = new MatrixVar();
    parserData->kounter = 0;
}

    break;

  case 206:

    {
    parserData->kounter += osglData->mult;
}

    break;

  case 207:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    osglData->varTypePresent = false;
    parserData->templateMatrixIdxPresent = false;
    parserData->varReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
}

    break;

  case 208:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixVar) 
        throw ErrorClass("actual number of matrixVar greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->numberOfColumns
            = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->varReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->varReferenceMatrixIdx
                = parserData->varReferenceMatrixIdx;
        if (parserData->lbMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->lbMatrixIdx
                = parserData->lbMatrixIdx;
        if (parserData->lbConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->lbConeIdx
                = parserData->lbConeIdx;
        if (parserData->ubMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->ubMatrixIdx
                = parserData->ubMatrixIdx;
        if (parserData->ubConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->ubConeIdx
                = parserData->ubConeIdx;
        if (osglData->varTypePresent)
        {
            if (returnVarType(osglData->varType[0]) > 0)  
                osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->varType
                = osglData->varType[0];
            else
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "varType must be one of C, B, I, S, D, J");
        }
    }
}

    break;

  case 225:

    {  
        if (parserData->kounter < parserData->numberOfMatrixObj)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj less than number attribute");
    }

    break;

  case 226:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives = new MatrixObjectives(); 
}

    break;

  case 227:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj = parserData->numberOfMatrixObj;
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj
        = new MatrixObj*[parserData->numberOfMatrixObj];
    for (int i=0; i < parserData->numberOfMatrixObj; i++)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i] = new MatrixObj();
    parserData->kounter = 0;
}

    break;

  case 235:

    {
    parserData->kounter += osglData->mult;
}

    break;

  case 236:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    parserData->templateMatrixIdxPresent = false;
    parserData->objReferenceMatrixIdxPresent = false;
    parserData->orderConeIdxPresent = false;
    parserData->constantMatrixIdxPresent = false;
}

    break;

  case 237:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixObj) 
        throw ErrorClass("actual number of matrixObj greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->numberOfColumns
                = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->objReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->objReferenceMatrixIdx
                = parserData->objReferenceMatrixIdx;
        if (parserData->orderConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->orderConeIdx
                = parserData->orderConeIdx;
        if (parserData->constantMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->constantMatrixIdx
                = parserData->constantMatrixIdx;
    }
}

    break;

  case 251:

    {  
        if (parserData->kounter < parserData->numberOfMatrixCon)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon less than number attribute");   
    }

    break;

  case 252:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints = new MatrixConstraints(); 
}

    break;

  case 253:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon = parserData->numberOfMatrixCon;
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon
        = new MatrixCon*[parserData->numberOfMatrixCon];
    for (int i=0; i < parserData->numberOfMatrixCon; i++)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i] = new MatrixCon();
    parserData->kounter = 0;
}

    break;

  case 261:

    {
    parserData->kounter += osglData->mult;
}

    break;

  case 262:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    parserData->templateMatrixIdxPresent = false;
    parserData->conReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
}

    break;

  case 263:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixCon) 
        throw ErrorClass("actual number of matrixCon greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->numberOfColumns
            = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->conReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->conReferenceMatrixIdx
                = parserData->conReferenceMatrixIdx;
        if (parserData->lbMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->lbMatrixIdx
                = parserData->lbMatrixIdx;
        if (parserData->lbConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->lbConeIdx
                = parserData->lbConeIdx;
        if (parserData->ubMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->ubMatrixIdx
                = parserData->ubMatrixIdx;
        if (parserData->ubConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->ubConeIdx
                = parserData->ubConeIdx;
    }
}

    break;

  case 279:

    {osinstance->instanceData->timeDomain = new TimeDomain();}

    break;

  case 286:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages > parserData->stagecount )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of stages less than numberOfStages");
 /* After stages have been processed, make sure that all variables and constraints have been assigned
  * to a stage (uniquely) and all objectives have been assigned as well (possibly more than once).
  * For future reference also record the stage to which each variable and constraint belongs. 
  */
    parserData->m_miVarStageInfo = new int [ osinstance->instanceData->variables->numberOfVariables ];
    parserData->m_miObjStageInfo = new int [ osinstance->instanceData->objectives->numberOfObjectives ];
    parserData->m_miConStageInfo = new int [ osinstance->instanceData->constraints->numberOfConstraints ];
    parserData->nvarcovered = 0;
    for (int i = 0; i < osinstance->instanceData->variables->numberOfVariables; i++)
         parserData->m_miVarStageInfo[i] = -1;
    for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
         parserData->m_miObjStageInfo[i] = -1;
    for (int i = 0; i < osinstance->instanceData->constraints->numberOfConstraints; i++)
         parserData->m_miConStageInfo[i] = -1;
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        {for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables; i++)
            {            
            if (parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] != -1)
                    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable belongs to two stages");
                parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] = k;
            };
         parserData->nvarcovered += osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables;
        };
    if (parserData->nvarcovered != osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some variables not assigned to any stage");
    parserData->nconcovered = 0;
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        {for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints; i++)
            {if (parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] != -1)
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint belongs to two stages");
                 parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] = k;
            };
         parserData->nconcovered += osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints;
        };
    if (parserData->nconcovered != osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some constraints not assigned to any stage");
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        { for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->objectives->numberOfObjectives; i++)
            { if (parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] == -1)
                    parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] = k;
            };
        };
    for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
        if (parserData->m_miObjStageInfo[i] == -1)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some objectives not assigned to any stage");
}

    break;

  case 287:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}

    break;

  case 288:

    {
    if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-2].ival) < 1) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of stages must be positive");
    osinstance->instanceData->timeDomain->stages->numberOfStages = (yyvsp[-2].ival);
    if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
        osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ (yyvsp[-2].ival) ];
    for(int i = 0; i < (yyvsp[-2].ival); i++) 
    {    osinstance->instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
        osinstance->instanceData->timeDomain->stages->stage[i]->variables   = new TimeDomainStageVariables();
        osinstance->instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        osinstance->instanceData->timeDomain->stages->stage[i]->objectives  = new TimeDomainStageObjectives();
    }
}

    break;

  case 291:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}

    break;

  case 292:

    { /* set defaults for next stage */
    parserData->stagenameON = false;
    parserData->stageVariablesON = false;
    parserData->stageObjectivesON = false;
    parserData->stageConstraintsON = false;
    parserData->stageVariablesOrdered = false;
    parserData->stageObjectivesOrdered = false;
    parserData->stageConstraintsOrdered = false;
    parserData->stageVariableStartIdx = 0;
    parserData->stageObjectiveStartIdx = 0;
    parserData->stageConstraintStartIdx = 0;
    parserData->stagevarcount = 0;
    parserData->stageconcount = 0;
    parserData->stageobjcount = 0;
    parserData->stagecount++;
}

    break;

  case 294:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[-1].sval); free((yyvsp[-1].sval));}

    break;

  case 299:

    {
        parserData->stageVariablesON = true;
        }

    break;

  case 304:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of variables cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfVariables");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var = new TimeDomainStageVar*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
        }
    };
}

    break;

  case 305:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) < 0 && (yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[-1].ival);
}

    break;

  case 306:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }

    break;

  case 307:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }

    break;

  case 312:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}

    break;

  case 314:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[-1].ival);
    parserData->stagevarcount++;
}

    break;

  case 318:

    {
        parserData->stageConstraintsON = true;
    }

    break;

  case 323:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of constraints cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfConstraints");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con = new TimeDomainStageCon*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
        }
    };
}

    break;

  case 324:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) < 0 && (yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[-1].ival);
}

    break;

  case 325:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }

    break;

  case 326:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }

    break;

  case 331:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}

    break;

  case 333:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[-1].ival);
    parserData->stageconcount++;
}

    break;

  case 336:

    { /* By default, an objective belongs to every stage */
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 
                osinstance->instanceData->objectives->numberOfObjectives;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = 
                new TimeDomainStageObj*[ osinstance->instanceData->objectives->numberOfObjectives ];
            for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++) 
            {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
                osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = -(i+1); 
            }
    }

    break;

  case 337:

    {
      parserData->stageObjectivesON = true;
    }

    break;

  case 342:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of objectives cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->objectives->numberOfObjectives)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfObjectives");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = new TimeDomainStageObj*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = 0; 
        }
    };
}

    break;

  case 343:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }

    break;

  case 344:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }

    break;

  case 349:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}

    break;

  case 351:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) >= 0 || (yyvsp[-1].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[-1].ival);
    parserData->stageobjcount++;
}

    break;

  case 354:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }

    break;

  case 355:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}

    break;

  case 360:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }

    break;

  case 361:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }

    break;

  case 362:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) >= 0 && (yyvsp[-1].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[-1].ival);
}

    break;

  case 363:

    {
        if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}

    break;

  case 364:

    {
        if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}

    break;

  case 365:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    osglData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = (yyvsp[-1].ival);
}

    break;

  case 366:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfConesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <cone> elements cannot be negative");
    parserData->numberOfConesPresent = true;
    parserData->numberOfCones = (yyvsp[-1].ival); 
}

    break;

  case 367:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[-1].ival); 
}

    break;

  case 368:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[-1].ival); 
}

    break;

  case 369:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[-1].ival); 
}

    break;

  case 370:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->normScaleFactorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "normScaleFactor attribute previously set");
    if (parserData->tempVal <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "scale factor must be positive");
    parserData->normScaleFactorPresent = true;
    parserData->normScaleFactor = parserData->tempVal; 
}

    break;

  case 371:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->distortionMatrixPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortionMatrixIdx attribute previously set");
    parserData->distortionMatrixPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index cannot be negative");
    else parserData->distortionMatrix = (yyvsp[-1].ival); 
}

    break;

  case 372:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->axisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "axisDirection attribute previously set");
    parserData->axisDirectionPresent = true;
    parserData->axisDirection = (yyvsp[-1].ival);
std::cout << "found axis direction = " << parserData->axisDirection << std::endl;
}

    break;

  case 373:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,     
            "mismatched quotes");
    if (parserData->firstAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "firstAxisDirection attribute previously set");
    parserData->firstAxisDirectionPresent = true;
    parserData->firstAxisDirection = (yyvsp[-1].ival); 
std::cout << "found first axis direction = " << parserData->firstAxisDirection << std::endl;
}

    break;

  case 374:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->secondAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "secondAxisDirection attribute previously set");
    parserData->secondAxisDirectionPresent = true;
    parserData->secondAxisDirection = (yyvsp[-1].ival); 
std::cout << "found second axis direction = " << parserData->secondAxisDirection << std::endl;
}

    break;

  case 375:

    {
    if (parserData->semidefinitenessPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->semidefinitenessPresent = true;
    parserData->semidefiniteness = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
    if (parserData->semidefiniteness != "positive" && parserData->semidefiniteness != "negative")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "semidefiniteness must be either \"positive\" or \"negative\"");
}

    break;

  case 376:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->matrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrixIdx attribute previously set");
    parserData->matrixIdxPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index cannot be negative");
    else parserData->matrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 377:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbMatrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbMatrix attribute");
    parserData->lbMatrixIdxPresent = true;
    parserData->lbMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 378:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubMatrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubMatrix attribute");
    parserData->ubMatrixIdxPresent = true;
    parserData->ubMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 379:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->constantMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one constant matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for constant matrix attribute");
    parserData->constantMatrixIdxPresent = true;
    parserData->constantMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 380:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for template matrix index");
    parserData->templateMatrixIdxPresent = true;
    parserData->templateMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 381:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->varReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one varReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for varReference matrix attribute");
    parserData->varReferenceMatrixIdxPresent = true;
    parserData->varReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 382:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->objReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one objReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for objReference matrix attribute");
    parserData->objReferenceMatrixIdxPresent = true;
    parserData->objReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 383:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->conReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one conReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for conReference matrix attribute");
    parserData->conReferenceMatrixIdxPresent = true;
    parserData->conReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 384:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbCone attribute");
    parserData->lbConeIdxPresent = true;
    parserData->lbConeIdx = (yyvsp[-1].ival);
}

    break;

  case 385:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubCone attribute");
    parserData->ubConeIdxPresent = true;
    parserData->ubConeIdx = (yyvsp[-1].ival);
}

    break;

  case 386:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->orderConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one orderCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for orderCone attribute");
    parserData->orderConeIdxPresent = true;
    parserData->orderConeIdx = (yyvsp[-1].ival);
}

    break;

  case 387:

    {parserData->tempVal = (yyvsp[-1].ival);}

    break;

  case 388:

    {parserData->tempVal = (yyvsp[-1].dval);}

    break;

  case 396:

    {
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
}

    break;

  case 397:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 402:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}

    break;

  case 408:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[-1].ival) + i*osglData->incr;    
}

    break;

  case 414:

    {
    char* b64string = (yyvsp[-1].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[-1].sval));
}

    break;

  case 415:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 420:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 423:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL DblVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}

    break;

  case 429:

    {
    char* b64string = (yyvsp[-1].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[-1].sval));
}

    break;

  case 430:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 434:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 437:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));    
}

    break;

  case 438:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}

    break;

  case 439:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        throw ErrorClass("more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back((OSMatrix*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrix*)osglData->tempC);
}

    break;

  case 440:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryPresent == true)
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}

    break;

  case 451:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 454:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}

    break;

  case 455:

    {
    osglData->tempC = new BaseMatrix();
    osglData->mtxConstructorVec.push_back((BaseMatrix*)osglData->tempC);

    osglData->baseMatrixIdxPresent = false;
    osglData->targetMatrixFirstRowPresent = false;
    osglData->targetMatrixFirstColPresent = false;
    osglData->baseMatrixStartRowPresent = false;
    osglData->baseMatrixStartColPresent = false;
    osglData->baseMatrixEndRowPresent = false;
    osglData->baseMatrixEndColPresent = false;
    osglData->baseTransposePresent = false;
    osglData->scalarMultiplierPresent = false;
    osglData->baseMatrixEndRow = -1;
    osglData->baseMatrixEndCol = -1;
}

    break;

  case 456:

    {
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
    {
        if (osglData->baseMatrixIdx < 0 || osglData->baseMatrixIdx >= osglData->matrixCounter)
            throw ErrorClass("Improper idx value for baseMatrix reference");
        ((BaseMatrix*)osglData->tempC)->baseMatrixIdx = osglData->baseMatrixIdx;
        ((BaseMatrix*)osglData->tempC)->baseMatrix = (OSMatrix*)osglData->matrix[osglData->baseMatrixIdx];
    }
    if (osglData->targetMatrixFirstRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstRow = osglData->targetMatrixFirstRow;
    if (osglData->targetMatrixFirstColPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstCol = osglData->targetMatrixFirstCol;
    if (osglData->baseMatrixStartRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartRow = osglData->baseMatrixStartRow;
    if (osglData->baseMatrixStartColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartCol = osglData->baseMatrixStartCol;
    if (osglData->baseMatrixEndRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndRow = osglData->baseMatrixEndRow;
    if (osglData->baseMatrixEndColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndCol = osglData->baseMatrixEndCol;
    if (osglData->baseTransposePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseTranspose = osglData->baseTranspose;
    if (osglData->scalarMultiplierPresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarMultiplier = osglData->scalarMultiplier;
}

    break;

  case 471:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}

    break;

  case 484:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 485:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}

    break;

  case 488:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 489:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 493:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 494:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 498:

    {
    //verify start vector: first element must be zero, vector must be nondecreasing, 
    //last element must equal numberOfValues; length must equal numberOfRows + 1 or numberOfColumns + 1
    if (osglData->osglIntArray[0] != 0)
        throw ErrorClass("first entry of matrix element start vector is not zero");
    for (int i=1; i < osglData->numberOfEl; i++)
    {
        if (osglData->osglIntArray[i] < osglData->osglIntArray[i-1])
            throw ErrorClass("matrix element start vector must be nondecreasing");
    }
    if (osglData->osglIntArray[osglData->numberOfEl-1] 
        != ((MatrixElements*)osglData->tempC)->numberOfValues)
            throw ErrorClass("last entry of matrix element start vector does not equal numberOfValues");
}

    break;

  case 501:

    {
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    //check whether the values of the index array are legal and satisfy symmetry assertions
    int maxindex;
    //symmetry.substr(0,5) == "upper"/"lower"
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 502:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 508:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 509:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 516:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 517:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 520:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 521:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 525:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 526:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 533:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 534:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}

    break;

  case 537:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 538:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 541:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 542:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }

    break;

  case 543:

    {
    osglData->numberOfValues = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;
    ((LinearMatrixElements*)osglData->tempC)->value = new LinearMatrixValues();
    ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl
        = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;    
    if (osglData->numberOfValues > 0)
        ((LinearMatrixElements*)osglData->tempC)->value->el
        = new LinearMatrixElement*[((LinearMatrixElements*)osglData->tempC)->numberOfValues]; 
    for (int i=0; i < ((LinearMatrixElements*)osglData->tempC)->numberOfValues; i++)
        ((LinearMatrixElements*)osglData->tempC)->value->el[i] = new LinearMatrixElement();
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxPresent = false;
}

    break;

  case 551:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}

    break;

  case 552:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}

    break;

  case 553:

    {
    if (osglData->numberOfVarIdxPresent)
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
            = osglData->numberOfVarIdx;
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
            = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
            = osglData->constant;
    }
    else
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx = 0;
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    }
    osglData->osglCounter = 0;
}

    break;

  case 565:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}

    break;

  case 567:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}

    break;

  case 568:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[-1].ival);
    osglData->osglCounter++;
}

    break;

  case 570:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 571:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 574:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 575:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 578:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 579:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }

    break;

  case 580:

    {
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((RealValuedExpressions*)osglData->tempC)->value->el
        = new RealValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((RealValuedExpressions*)osglData->tempC)->value->el[i] = new RealValuedExpressionTree();
}

    break;

  case 588:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    }

    break;

  case 592:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 594:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 595:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 598:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 599:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 602:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 603:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }

    break;

  case 604:

    {
    osglData->numberOfValues = ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexValuedExpressions*)osglData->tempC)->value = new ComplexValuedExpressionArray();
    ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((ComplexValuedExpressions*)osglData->tempC)->value->el
        = new ComplexValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ComplexValuedExpressions*)osglData->tempC)->value->el[i] = new ComplexValuedExpressionTree();
}

    break;

  case 612:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    }

    break;

  case 616:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 618:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 619:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 622:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 623:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 627:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 628:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 635:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 636:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 639:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 640:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 643:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 644:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }

    break;

  case 645:

    {
    osglData->numberOfValues = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->value = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((ConReferenceMatrixElements*)osglData->tempC)->value->el
        = new ConReferenceMatrixElement*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->value->el[i] = new ConReferenceMatrixElement();
}

    break;

  case 653:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = "";
    }

    break;

  case 659:

    {
    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "invalid valueType attribute in conReferenceElements");
        else
        {
            for (int i=0; i<osglData->mult; i++)
            {
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->conReference
                    = (yyvsp[-1].ival) + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}

    break;

  case 661:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 662:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}

    break;

  case 665:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 666:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 669:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 670:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }

    break;

  case 671:

    {
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues> 0)
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
}

    break;

  case 678:

    {
    if (!osglData->realPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "real part missing");
    if (!osglData->imagPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "imaginary part missing");

    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        for (int i=0; i<osglData->mult; i++)
        {
            ((ComplexMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]
                = std::complex<double>(osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}

    break;

  case 679:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }

    break;

  case 688:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 689:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}

    break;

  case 692:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 693:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 697:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 698:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 705:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back((MatrixTransformation*)osglData->tempC);

    // clear the vectors of pointers
    osnlData->nlNodeVec.clear();
    osnlData->sumVec.clear();
    osnlData->allDiffVec.clear();
    osnlData->maxVec.clear();
    osnlData->minVec.clear();
    osnlData->productVec.clear();
    osnlData->matrixSumVec.clear();
    osnlData->matrixProductVec.clear();

    osglData->shapePresent = false;   
}

    break;

  case 707:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}

    break;

  case 708:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}

    break;

  case 709:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}

    break;

  case 710:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}

    break;

  case 711:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}

    break;

  case 713:

    {
    if ( ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren != 
                           osglData->nBlocksVec.back())
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
}

    break;

  case 714:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 715:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 716:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 722:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 723:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 724:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 731:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}

    break;

  case 732:

    {
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 733:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back((MatrixBlock*)osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}

    break;

  case 739:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        if (osglData->symmetry == "none")
            osglData->symmetry =  "default";
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }

    break;

  case 740:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }

    break;

  case 744:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}

    break;

  case 745:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[-1].ival);
}

    break;

  case 746:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[-1].ival);
}

    break;

  case 747:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[-1].ival);
}

    break;

  case 748:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[-1].ival);
}

    break;

  case 749:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[-1].ival);
}

    break;

  case 750:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[-1].ival);
}

    break;

  case 751:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[-1].ival);
}

    break;

  case 752:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("baseMatrix idx cannot be negative");
    if ((yyvsp[-1].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 753:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[-1].ival); 
}

    break;

  case 754:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[-1].ival); 
}

    break;

  case 755:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[-1].ival); 
}

    break;

  case 756:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[-1].ival); 
}

    break;

  case 757:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = (yyvsp[-1].ival);
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}

    break;

  case 758:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = (yyvsp[-1].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}

    break;

  case 759:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[-1].ival);
}

    break;

  case 760:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[-1].ival);
}

    break;

  case 761:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[-1].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[-1].ival);
}

    break;

  case 762:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[-1].ival); 
}

    break;

  case 763:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[-1].ival); 
}

    break;

  case 764:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
}

    break;

  case 765:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
}

    break;

  case 766:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}

    break;

  case 767:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}

    break;

  case 768:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}

    break;

  case 771:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}

    break;

  case 772:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 775:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}

    break;

  case 776:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 779:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}

    break;

  case 780:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 783:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}

    break;

  case 784:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 787:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}

    break;

  case 788:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 791:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}

    break;

  case 792:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 795:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}

    break;

  case 796:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 799:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}

    break;

  case 800:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 803:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}

    break;

  case 804:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 806:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
 		"actual number of nl terms less than number attribute");   

        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
        parserData->parser_errors = "";
    }

    break;

  case 807:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }

    break;

  case 808:

    { 
        if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "start and end quotes are not the same");
        if ((yyvsp[-2].ival) < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[-2].ival);
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[-2].ival);  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[-2].ival) ];
        for (int i = 0; 
                 i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; 
                 i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[i] = new Nl();
        }
    }

    break;

  case 811:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->nonlinearExpressions
                    ->nl[osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
                ((OSnLNode*)
                    osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }

    break;

  case 812:

    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber)
            throw ErrorClass(  "actual number of nl terms greater than numberOfNonlinearExpressions");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
        osnlData->cSumVec.clear();
    }

    break;

  case 813:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mandatory attribute idx is missing");    
}

    break;

  case 816:

    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
                = new RealValuedExpressionTree();
//        }
    }

    break;

  case 817:

    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            if (returnNlExprShape(osglData->shape) > 0)
                osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->declaredShape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
            else
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "unknown shape specified in real-valued expression");
//        }
    }

    break;

  case 845:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 849:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 853:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 855:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 857:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 859:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 861:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 863:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 865:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 867:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 869:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 871:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 873:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 875:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 878:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 879:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 880:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 881:

    {
}

    break;

  case 882:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 883:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 884:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 886:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 888:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 890:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}

    break;

  case 891:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}

    break;

  case 896:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }

    break;

  case 897:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }

    break;

  case 899:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[0].sval);
    free((yyvsp[0].sval));
}

    break;

  case 901:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}

    break;

  case 902:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}

    break;

  case 905:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }

    break;

  case 909:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }

    break;

  case 910:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }

    break;

  case 911:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}

    break;

  case 912:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index cannot be negative");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[-1].ival);
}

    break;

  case 913:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 914:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}

    break;

  case 916:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }

    break;

  case 917:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 918:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 920:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }

    break;

  case 921:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 922:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 924:

    { osnlData->maxVec.back()->inumberOfChildren++; }

    break;

  case 925:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 926:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 928:

    { osnlData->minVec.back()->inumberOfChildren++; }

    break;

  case 929:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 930:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}

    break;

  case 932:

    { osnlData->productVec.back()->inumberOfChildren++; }

    break;

  case 952:

    {
    osnlData->matrixidxattON = false;
    if (osnlData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory idx attribute missing");
    if (osnlData->transposeAttributePresent == true)
        osnlData->nlMNodeMatrixRef->transpose = osnlData->matrixTransposeAttribute;
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}

    break;

  case 953:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}

    break;

  case 960:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[-1].ival);
    osnlData->idxAttributePresent = true;
}

    break;

  case 961:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
    osnlData->transposeAttributePresent = true;
}

    break;

  case 962:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 963:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}

    break;

  case 966:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[-1].ival);
}

    break;

  case 967:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 968:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}

    break;

  case 971:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[-1].ival);
}

    break;

  case 972:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 973:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}

    break;

  case 976:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[-1].ival);
}

    break;

  case 978:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 981:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 984:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 987:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 990:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 992:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 995:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 997:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 999:

    {
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
}

    break;

  case 1001:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}

    break;

  case 1005:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1008:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1011:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1014:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1016:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1017:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}

    break;

  case 1019:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}

    break;

  case 1021:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1024:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1027:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1030:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }

    break;

  case 1031:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }

    break;

  case 1033:

    {
    #ifdef OSINSTANCE_AVAILABLE
        if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
        if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[-1].ival);
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = (yyvsp[-1].ival);  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr
                = new MatrixExpression*[ (yyvsp[-1].ival) ];
        for (int i = 0; 
                 i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr;
                 i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i]
                = new MatrixExpression();
    #endif
    }

    break;

  case 1040:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->
                    expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
                ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }

    break;

  case 1041:

    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            throw ErrorClass("actual number of matrix expressions greater than numberOfExpr attribute");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    }

    break;

  case 1042:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}

    break;

  case 1045:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }

    break;

  case 1046:

    {
    #ifdef OSINSTANCE_AVAILABLE
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->matrixProgramming->matrixExpressions
                ->expr[ osnlData->tmpnlcount]->declaredShape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix expression");
    #endif
    }

    break;

  case 1058:

    {
}

    break;

  case 1059:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}

    break;

  case 1062:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}

    break;

  case 1068:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1071:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1073:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1074:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}

    break;

  case 1076:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}

    break;

  case 1078:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1081:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1084:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1087:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1090:

    {
    osnlData->nlNodePoint = new OSnLCNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;



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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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
        yyerror (&yylloc, osinstance, parserData, osglData, osnlData, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, osinstance, parserData, osglData, osnlData);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, osinstance, parserData, osglData, osnlData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, osinstance, parserData, osglData, osnlData);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, osinstance, parserData, osglData, osnlData);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}




// user defined functions

void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg )
{
    osil_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osilerror


std::string addErrorMsg(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osilget_lineno( scanner) << ": "; 
    outStr << osilget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg


void  yygetOSInstance( const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw (ErrorClass) {
    try {
        parseInstanceHeader( &osil, osinstance, &parserData->osillineno);
        parseInstanceData( &osil, osinstance, &parserData->osillineno);    
        /** at this point here we have parsed everything through <linearConstraintCoefficients>
         *    we have done so without bison and just moved the pointer on osil to point to what is past
         *    the linear part    
         * call the flex scanner and start scanning the nonlinear part of the problem
         */    
        osil_scan_string( osil, scanner );
        osilset_lineno (parserData->osillineno , scanner );
        //
        // call the Bison parser
        //
        if(  osilparse( osinstance,  parserData, osglData, osnlData) != 0) {
            throw ErrorClass(  "Error parsing the OSiL");
        }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
}//end yygetOSInstance

bool isnewline(char c, int* osillineno){
    if(c != '\n') return false;
    (*osillineno)++;
    return true;
}//end isnewline()

bool parseInstanceHeader( const char **p, OSInstance *osinstance, int* osillineno){
    //
    *osillineno = 1;
    const char *pchar = *p;
    
    //first check of osil start
    const char *startOSiL = "<osil";
    const char *pOSiLStart = strstr(pchar, startOSiL);
    if(pOSiLStart == NULL){
      osilerror_wrapper( pchar,osillineno,"<osil> element missing"); 
      return false;
    }else{
        //look for osil end
            const char *pOSiLEnd = strstr(pOSiLStart, ">");
        if(pOSiLEnd == NULL) {  osilerror_wrapper( pchar,osillineno,"end of <osil> element missing"); return false;
            } else {
            pchar = pOSiLEnd;
            pchar++;
        }
    }
    
    
    // create a char array that holds the instance header information
    const char *startInstanceHeader = "<instanceHeader";
    const char *endInstanceHeader = "instanceHeader"; // "</instanceHeader";
    const char *startName = "ame"; // "<name";
    const char *startSource = "ource"; // "<source";
    const char *startDescription = "escription"; // "<description";
    const char *startFileCreator = "ileCreator"; // "<fileCreator";
    const char *startLicence = "icence"; // "<licence";
    const char *endName = "</name";
    const char *endSource = "</source";
    const char *endDescription = "</description";
    const char *endFileCreator = "</fileCreator";
    const char *endLicence = "</licence";
    const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
    char *pelementText = NULL;
    const char *ptemp = NULL;
    long int elementSize;

    bool namePresent = false;
    bool sourcePresent = false;
    bool descriptionPresent = false;
    bool fileCreatorPresent = false;
    bool licencePresent = false;

    if(pinstanceHeadStart == NULL ) {
        const char *startInstanceData = "<instanceData";
        *p = strstr(pchar, startInstanceData);
        return true;
    }
    // increment the line number counter if there are any newlines between the start of
    // the osil string and pinstanceHeadStart
    long int kount = pinstanceHeadStart - pchar;
    while( kount-- > 0) if(*(pchar++) == '\n') (*osillineno)++;
    // important! pchar now points to the '<' in <instanceHeader
    // that is, both pinstanceHeadStart and pchar point to the same thing
     // 
     // move to the end of <instanceHeader
     pchar+=15;
    // burn any whitespace
    BURNWHITESPACE( pchar );
    // pchar better be pointing to the '>' in the <instanceHeader> element
    // or to /> if we have <instanceHeader />
    if( *pchar == '/'){
        pchar++;
        // better point to a '>'
        if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
        // there is no instanceHeader data
        pchar++;
        *p = pchar;
        return true;
    }
    else{
        // pchar better be '>' or there is an error
        if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
    }
    pchar++;
    // we are pointing to the character after <instanceHeader>
    //
    // The next element could be </instanceHeader or one of the content elements (in arbitrary order):
    // <name
    // <source
    // <description
    // <fileCreator
    // <licence

    for (;;)
    {
        // first burn any whitespace and comments
        FINDNEXTTAG( pchar );
        // remember where we are
        *p = pchar;
        // The next character should be '<'
        if (*pchar != '<') {osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
        pchar++;
        switch (*pchar)
        {
            case 'n':    // <name
                if (namePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <name> element"); 
                    return false;
                }
                else
                    namePresent = true;
                pchar++;
                while(*startName++  == *pchar) pchar++;
                if( (pchar - *p)  != 5) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a name element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <name> element");
                             return false;
                        }
                        pchar++;
                        // process <name> element text
                        // there better be a </name
                        ptemp = strstr( pchar, endName);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->name = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </name
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </name
                        // move to first char after </name
                        pchar += 6;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of name
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 's':    // <source
                if (sourcePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <source> element"); 
                    return false;
                }
                else
                    sourcePresent = true;
                pchar++;
                while(*startSource++  == *pchar) pchar++;
                if( (pchar - *p)  != 7) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a source element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <source> element");
                             return false;
                        }
                        pchar++;
                        // process <source> element text
                        // there better be a </source
                        ptemp = strstr( pchar, endSource);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->source = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </source
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </source
                        // move to first char after </source
                        pchar += 8;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of source
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'd':    // <description
                if (descriptionPresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <description> element"); 
                    return false;
                }
                else
                    descriptionPresent = true;
                pchar++;
                while(*startDescription++  == *pchar) pchar++;
                if( (pchar - *p)  != 12) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a description element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <description> element");
                             return false;
                        }
                        pchar++;
                        // process <description> element text
                        // there better be a </description
                        ptemp = strstr( pchar, endDescription);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->description = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </description
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </description
                        // move to first char after </description
                        pchar += 13;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of description
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'f':    // <fileCreator
                if (fileCreatorPresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <fileCreator> element"); 
                    return false;
                }
                else
                    fileCreatorPresent = true;
                pchar++;
                while(*startFileCreator++  == *pchar) pchar++;
                if( (pchar - *p)  != 12) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a fileCreator element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element");
                             return false;
                        }
                        pchar++;
                        // process <fileCreator> element text
                        // there better be a </fileCreator
                        ptemp = strstr( pchar, endFileCreator);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->fileCreator = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </fileCreator
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </fileCreator
                        // move to first char after </fileCreator
                        pchar += 13;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of fileCreator
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'l':    // <licence
                if (licencePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <licence> element"); 
                    return false;
                }
                else
                    licencePresent = true;
                pchar++;
                while(*startLicence++  == *pchar) pchar++;
                if( (pchar - *p)  != 8) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a licence element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element");
                             return false;
                        }
                        pchar++;
                        // process <licence> element text
                        // there better be a </licence
                        ptemp = strstr( pchar, endLicence);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->licence = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </licence
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </licence
                        // move to first char after </licence
                        pchar += 9;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of licence
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case '/':    // </instanceHeader
                pchar++;
                while(*endInstanceHeader++  == *pchar) pchar++;
                if( (pchar - *p)  != 16) 
                {
                    osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); 
                    return false;
                }
                // pchar now points to the first character after </instanceHeader
                // get rid of white space
                BURNWHITESPACE( pchar );
                // pchar must point to '>' or there is an error
                if(*pchar != '>')
                {  
                    osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); 
                    return false;
                }
                pchar++;
                *p = pchar;
                return true;

            default:
                {osilerror_wrapper( pchar,osillineno,"tag not recognized"); return false;}
        }
    }
    return false;
}//end parseInstanceHeader


bool parseInstanceData( const char **p, OSInstance *osinstance, int* osillineno){
    //
    const char *pchar = *p;
    const char *startInstanceData = "<instanceData";
    // at this point *pchar should be pointing to the first char after the > in </instanceHeader>
    // burn the white space and any comments
    FINDNEXTTAG( pchar );
    // pchar should be point to a '<', if not there is an error
    if(*pchar != '<'){  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData element"); return false;}
    // make sure the element is <instanceData    
    *p = pchar;
    while(*startInstanceData++  == *pchar) pchar++;
    if( (pchar - *p) != 13) {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); return false;}    
    // now burn whitespace
    BURNWHITESPACE( pchar );
    // pchar must point to '>' or there is an error
    if(*pchar == '>'){
        pchar++;
        // we are now pointing to the first char after <instanceData>
        // burn any whitespace and comments
        FINDNEXTTAG( pchar );    
        // we should be pointing to the '<' char in <variables>
        *p = pchar;
        if( parseVariables  ( p, osinstance, osillineno) != true) throw ErrorClass("error in parseVariables");
        if( parseObjectives ( p, osinstance, osillineno) != true) throw ErrorClass("error in parseObjectives");
        if( parseConstraints( p, osinstance, osillineno) != true) throw ErrorClass("error in parseConstraints");
        if( parseLinearConstraintCoefficients( p, osinstance, osillineno) != true) throw ErrorClass("error in parseLinearConstraintCoefficients");
    }else{
        //osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); 
        return true;
    }
    // we should be pointing to the '<' char in <variables>
    return true;
}// end parseInstanceData


bool parseVariables( const char **p,  OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();
    const char *c_numberOfVariables = "numberOfVariables";
    const char *startVariables = "<variables";
    const char *endVariables = "</variables";
    const char *startVar = "<var";
    const char *endVar = "</var";
    // the attributes
    char *attText = NULL;
    const char *name = "name";
    const char *type = "type";
    const char *mult = "mult";
    // others
    int i;
    int varcount = 0;
    int vt;
    int numberOfVariables = 0;
// variable attribute boolean variables
    bool varlbattON   = false;
    bool varubattON   = false;
    bool vartypeattON = false;
    bool varnameattON = false;
    bool varmultattON = false;
    bool foundVar = false;
    int varmult; 
    //
    // start parsing -- okay not to have variables 
    // burn white space and comments
    FINDNEXTTAG( ch );
    *p = ch;
    while(*startVariables++  == *ch) ch++;
    //if( (ch - *p) != 10) {  osilerror_wrapper( ch,osillineno,"incorrect <variables tag>"); return false;}
    if( (ch - *p) != 10) {   return true;}

    osinstance->instanceData->variables = new Variables();

    // find numberOfVariables attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while(*c_numberOfVariables++  == *ch) ch++;
    if( (ch - *p) != 17) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfVariables attribute in <variables tag>"); return false;}    
    // buf_index should be pointing to the first character after "numberOfVariables" attribute
    GETATTRIBUTETEXT;
    ch++;
    numberOfVariables = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // get rid of white space after the numberOfVariables element
    BURNWHITESPACE( ch );

    osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
    if (numberOfVariables > 0)
    {
        osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
        for (i = 0; i < numberOfVariables; i++)
        {
            osinstance->instanceData->variables->var[ i] = new Variable();
        } 
        // If there is at least one variable, this element must end with '>', not '/>' 
        // better have an > sign or not valid
        if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"variables element does not have a proper closing >"); return false;}
        ch++;
        // get rid of white space and comments
        FINDNEXTTAG( ch );
        // now loop over the var element when the numberOfVariables is strictly positive
        *p = ch;
        while(*startVar++  == *ch) ch++;
        if( (ch - *p) ==  4) foundVar = true;
        else {osilerror_wrapper( ch,osillineno,"there must be at least one <var> element"); return false;}
        startVar -= 5;
        while(foundVar)
        {
            varlbattON   = false;
            varubattON   = false;
            vartypeattON = false;
            varnameattON = false;
            varmultattON = false;
            varmult = 1;
            foundVar = false;
            vt = 0;
            // assume we are pointing to the first character after the r in <var
            // it should be whitespace
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>')
            {
                switch (*ch) 
                {
                case 'n':
                    *p = ch;
                    while(*name++  == *ch) ch++;
                    if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"error in variables name attribute"); return false;}
                    name -= 5;
                    if(varnameattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable name attributes"); return false;}
                    varnameattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->name=attText;
                    delete [] attText;
                    break;
                case 't':
                    *p = ch;
                    while(*type++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables type attribute"); return false;}
                    type -= 5;
                    if(vartypeattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable type attributes"); return false;}
                    vartypeattON = true;
                    GETATTRIBUTETEXT;
                    vt = returnVarType(attText[0]);
                    if( vt == 0 ) {  osilerror_wrapper( ch,osillineno,"variable type not recognized"); return false;}
                    osinstance->instanceData->variables->var[varcount]->type = attText[0];
                    delete [] attText;
                    break;
                case 'l':
                    ch++;
                    if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables lower bound attribute"); return false;}
                    if(varlbattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable lb attributes"); return false;}
                    varlbattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->lb = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'u':
                    ch++;
                    if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables upper bound attribute"); return false;}
                    if(varubattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable ub attributes"); return false;}
                    varubattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->ub = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while(*mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables mult attribute"); return false;}
                    mult -= 5;
                    if(varmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable mult attributes"); return false;}
                    varmultattON = true;
                    GETATTRIBUTETEXT;
                    varmult = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character"); 
                    return false;
                    break;
                }
                // reset default upper bound for binary variables
                if (vt == ENUM_VARTYPE_binary) 
                {
                    if (varubattON == false)
                        osinstance->instanceData->variables->var[varcount]->ub = 1.0;
                }
                ch++;
            }
            //
            // assume all the attributes have been processed
            // must have either /> or > and then whitespace and </var whitespace>
            if ( *ch != '/' && *ch != '>') 
            {  
                osilerror_wrapper( ch,osillineno,"incorrect end of <var> element");
                return false;
            }
            if (*ch == '/')
            {
                ch++;
                if(*ch != '>') 
                {
                    osilerror_wrapper( ch,osillineno,"incorrect end of <var> element");
                    return false;
                }
                // get rid of whitespace and comments
                ch++;
                FINDNEXTTAG( ch );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4)
                {
                    foundVar = true;
                    startVar -= 5;
                }
                else
                {
                    foundVar = false;
                    ch = *p;
                }
            }
            else
            {
                // the buf_index is the > at the end of the var element 
                // double check to make sure it really is a >
                if(*ch != '>') 
                {
                    osilerror_wrapper( ch,osillineno,"improper ending to a <var> element");
                    return false;
                }
                // look for </var
                // first get rid of white space
                ch++;
                BURNWHITESPACE( ch );
                // we should be at </var or there is an error
                *p = ch;
                while(*endVar++  == *ch) ch++;
                endVar -= 6;
                if( (ch - *p) != 5) 
                {
                    osilerror_wrapper( ch,osillineno,"</var> element missing");
                    return false;
                }
                // burn off the whitespace
                BURNWHITESPACE( ch );
                // better have an > to end </var
                if(*ch++ != '>')
                {
                    osilerror_wrapper( ch,osillineno,"</var> element missing >");
                    return false;
                }
                // look for a new <var> element
                // get rid of whitespace
                ch++;
                FINDNEXTTAG( ch );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4)
                {
                    foundVar = true;
                    startVar -= 5;
                }
                else
                {
                    foundVar = false;
                    ch = *p;
                }
            }
            if( ((varcount+varmult) <= numberOfVariables))
            {
                for (int k=1; k < varmult; k++)
                {
                    osinstance->instanceData->variables->var[varcount+k]->name 
                    = osinstance->instanceData->variables->var[varcount]->name;
                    osinstance->instanceData->variables->var[varcount+k]->type 
                    = osinstance->instanceData->variables->var[varcount]->type;
                    osinstance->instanceData->variables->var[varcount+k]->lb 
                    = osinstance->instanceData->variables->var[varcount]->lb;
                    osinstance->instanceData->variables->var[varcount+k]->ub 
                    = osinstance->instanceData->variables->var[varcount]->ub;
                }
            }
            varcount += varmult;

//            if( (varcount >= numberOfVariables) && (foundVar == true) ) 
        // foundVar is bool, so =1 if true, =0 if false
            if( (varcount+foundVar) > numberOfVariables)
            {
                osilerror_wrapper( ch,osillineno,"actual number of variables exceeds attribute numberOfVariables");
                return false;
            }
        }// end while(foundVar)
        if(varcount < numberOfVariables)
        {
            osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is greater than actual number found");   
            return false;
        }
        // get the </variables> tag
        *p = ch;
        while(*endVariables++  == *ch) ch++;
        if( (ch - *p) != 11)
        {
            osilerror_wrapper( ch,osillineno,"cannot find </variables> tag");
            return false;
        }
        BURNWHITESPACE( ch );
        // better have >
        if(*ch != '>')
        {
            osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag");
            return false;
        }
        ch++;
    }
    else
    {   // end if(numberOfVariables > 0)
        // error if the number is negative
        if (numberOfVariables < 0)
        {
            osilerror_wrapper( ch,osillineno,"cannot have a negative number of variables");
            return false;
        }
        // if we are here we have numberOfVariables = 0
        // must close with /> or </variables>
        // get rid of white space
        BURNWHITESPACE( ch );
        if( *ch == '/')
        {
            // better have a >
            ch++;
            if( *ch  != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly closed variables tag");
                return false;
            }
            ch++;
        }
        else
        {
            // if we are here we must have an '>' and then  </variables> tag
            if( *ch  != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly closed variables tag");
                return false;
            }
            ch++;
            // burn white space and comments
            FINDNEXTTAG( ch );
            *p = ch;
            while( *endVariables++  == *ch) ch++;
            if ( (ch - *p) != 11)
            {
                osilerror_wrapper( ch,osillineno, "cannot find </variables> tag");
                return false;
            }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag");
                return false;
            }
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE VARIABLES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseVariables


bool parseObjectives( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    int ki, numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();
    const char *c_numberOfObjectives = "numberOfObjectives";
    const char *startObjectives = "<objectives";
    const char *endObjectives = "</objectives";
    const char *startObj = "<obj";
    const char *endObj = "</obj";
    // attributes
    char *attText = NULL;
    const char *constant = "constant";
    const char *maxOrMin = "maxOrMin";
    const char *numberOfObjCoef = "numberOfObjCoef";
    const char *weight = "weight";
    const char *name = "name";
    const char *mult = "mult";
    // others
    int i;
    // objective function attribute boolean variables
    bool objmaxOrMinattON = false;
    bool objnameattON = false;
    bool objconstantattON = false;
    bool objweightattON = false;
    bool objmultattON = false;
    bool objnumberOfObjCoefattON = false;
    int objcount = 0;
    int numberOfObjectives;
    bool foundObj;
    int objmult; 
    // start parsing
    // burn white space and comments
    FINDNEXTTAG( ch );
    // if present, we should be pointing to <objectives element if there -- it is not required
    *p = ch;
    while( *startObjectives++  == *ch) ch++;
    if( (ch - *p) != 11) {
        //  note if we are here even though ch > *p we want to return *p
        return true;
    }

    osinstance->instanceData->objectives = new Objectives();

    // find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
    // However if the  number attribute is missing assume it is 1 
    // eat the white space
    BURNWHITESPACE( ch );
    // we just ate the white space. If numberOfObjectives is missing we assume it is 1
    // we therefore must have > char
    if(*ch == '>'){
        numberOfObjectives = 1;
        //ch++;
    }
    else{
        *p = ch;
        while( *c_numberOfObjectives++  == *ch) ch++;
        if( (ch - *p) != 18) {  osilerror_wrapper( ch,osillineno,"<objectives> tag needs numberOfObjectives or <obj> element"); return false;}    
        GETATTRIBUTETEXT;
        numberOfObjectives = atoimod1( osillineno, attText, attTextEnd);
        delete [] attText;
        ch++;
    }
    if(numberOfObjectives > 0){
        // get rid of white space after the numberOfObjectives attribute
        BURNWHITESPACE( ch );
        // we must have an >
        /*if(*ch == '/'){
            ch++;
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false; }
            else{
                if(numberOfObjectives > 0){   osilerror_wrapper( ch,osillineno,"numberOfObjectives positive but there are no objectives"); return false;}
                return false;
            }
        }*/
        //  we better have an > 
        if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false;} 
        osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
        if (numberOfObjectives < 0)
        {
            osilerror_wrapper( ch,osillineno,"cannot have a negative number of objectives");
            return false;
        }
        if (numberOfObjectives > 0)
            osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
        for(i = 0; i < numberOfObjectives; i++){
            osinstance->instanceData->objectives->obj[ i] = new Objective();
        }     
    // get rid of white space and any comments after the <objectives> element
    FINDNEXTTAG( ch );
    // now loop over the obj elements, there must be at least one obj element
    *p = ch;
    while( *startObj++  == *ch) ch++;
    if( (ch - *p) == 4) foundObj = true;
        else {  osilerror_wrapper( ch,osillineno,"there must be at least one <obj> element"); return false;}
    startObj -= 5;
    start = clock();    
    while(foundObj){
        objmaxOrMinattON = false;
        objnameattON = false;
        objconstantattON = false;
        objweightattON = false;
        objmultattON = false;
        objnumberOfObjCoefattON = false;
        objmult = 1;
        // assume we are pointing to the first character after the j in <obj
        // it should be a space so let's increment ch
        ch++;
        while(*ch != '/' && *ch != '>'){
            switch (*ch) {
            case 'n':
                if( *(ch+1) == 'u'){
                    *p = ch;
                    while( *numberOfObjCoef++  == *ch) ch++;
                    numberOfObjCoef -= 16;
                    if( ( (ch - *p) != 15)  ) {  osilerror_wrapper( ch,osillineno,"error in objective numberOfObjCoef attribute"); return false;}
                    else{
                        if(objnumberOfObjCoefattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj numberOfObjCoef attributes"); return false;}
                        objnumberOfObjCoefattON = true;
                        GETATTRIBUTETEXT;
                        osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod1( osillineno,attText, attTextEnd);
                        if(osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef > 0 && osinstance->instanceData->variables->numberOfVariables == 0){  osilerror_wrapper( ch,osillineno,"we have zero variables, but have objective function coefficients"); return false;}
                        osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
                        for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
                        delete [] attText;
                    }
                }
                else{
                    *p = ch;
                    while( *name++  == *ch) ch++;
                    name -= 5;
                    if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective name attribute"); return false;}
                    else{
                        if(objnameattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj name attributes"); return false;}
                        objnameattON = true;
                        GETATTRIBUTETEXT;
                        osinstance->instanceData->objectives->obj[objcount]->name=attText;
                        delete [] attText;
                    }
                }
                break;
            case 'c':
                *p = ch;
                while( *constant++  == *ch) ch++;
                constant -= 9;    
                if( ( (ch - *p) != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective constant attribute"); return false;}
                else{
                    if(objconstantattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj constant attributes"); return false;}
                    objconstantattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                }
                break;
            case 'w':
                *p = ch;
                while( *weight++  == *ch) ch++;
                weight -= 7;
                if( ( (ch - *p) != 6)  ) {  osilerror_wrapper( ch,osillineno,"error in objective weight attribute"); return false;}
                else{
                    if(objweightattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj weight attributes"); return false;}
                    objweightattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                }
                break;
            case 'm':
                if(*(ch+1) == 'a'){
                    *p = ch;
                    while( *maxOrMin++  == *ch) ch++;
                    maxOrMin -= 9;
                    if( ( ( ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective maxOrMin attribute"); return false;}
                    else{
                        if(objmaxOrMinattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj maxOrMin attributes"); return false;}
                        objmaxOrMinattON = true;
                        GETATTRIBUTETEXT;
                        if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror_wrapper( ch,osillineno,"maxOrMin attribute in objective must be a max or min"); return false;}
                        osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
                        delete [] attText;
                    }
                }
                else{
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    mult -= 5;
                    if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective mult attribute"); return false;}
                    else{
                        if(objmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj mult attributes"); return false;}
                        objmultattON = true;
                        GETATTRIBUTETEXT;
                        objmult = atoimod1( osillineno,attText, attTextEnd);
                        delete [] attText;
                    }
                }
                break;
            // come back and do multiplicity
            case ' ':
                break;
            case '\n':
                (*osillineno)++;
                break;
            case '\t':
                break;
            case '\r':
                break;
            default:
                 
                osilerror_wrapper( ch,osillineno,"invalid attribute character");
                return false;
                break;
            }
            ch++;
        }
        //
        // assume all the attributes have been processed
        // must have either /> or > and then whitespace and </obj whitespace>
        if( *ch != '/' && *ch != '>') {   osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
        if(*ch == '/'){
            ch++;
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
            // get rid of whitespace and comments
            ch++;
            FINDNEXTTAG( ch );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        else{
            // the ch is the > at the end of the obj element
            // double check to make sure it really is a >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to an <obj> element"); return false;}
            // look for </obj
            // fist get rid of white space
            ch++;
            // first get the <coef> elements
            parseObjCoef(&ch,  objcount, osinstance, osillineno);
            FINDNEXTTAG( ch );
            // we should be at </obj or there is an error
            for(i = 0; endObj[i]  == *ch; i++, ch++);
            if(i != 5) {  osilerror_wrapper( ch,osillineno,"</obj> element missing or too many <coef> elements"); return false;}
            // burn off the whitespace
            BURNWHITESPACE( ch );
            // better have an > to end </obj
            if(*ch++ != '>'){   osilerror_wrapper( ch,osillineno,"</obj> element ill-formed"); return false;}
            // look for a new <obj> element
            // get rid of whitespace
            FINDNEXTTAG( ch );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        if ( (objcount+objmult) <= numberOfObjectives)
        {
            for (int k=1; k < objmult; k++)
            {
                osinstance->instanceData->objectives->obj[objcount+k]->name 
                = osinstance->instanceData->objectives->obj[objcount]->name;
                osinstance->instanceData->objectives->obj[objcount+k]->maxOrMin 
                = osinstance->instanceData->objectives->obj[objcount]->maxOrMin;
                osinstance->instanceData->objectives->obj[objcount+k]->constant 
                = osinstance->instanceData->objectives->obj[objcount]->constant;
                osinstance->instanceData->objectives->obj[objcount+k]->weight 
                = osinstance->instanceData->objectives->obj[objcount]->weight;
                osinstance->instanceData->objectives->obj[objcount+k]->numberOfObjCoef 
                = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
                if (osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef > 0)
                {
                    osinstance->instanceData->objectives->obj[objcount+k]->coef
                    = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
                    for (int i = 0; 
                             i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef;
                             i++)
                    {
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i] = new ObjCoef();
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->idx = 
                          osinstance->instanceData->objectives->obj[objcount]->coef[i]->idx;
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->value = 
                          osinstance->instanceData->objectives->obj[objcount]->coef[i]->value;
                    }
                }
            }
        }
        objcount += objmult;
//        if( (objcount >= numberOfObjectives) && (foundObj == true))
        // foundObj is bool, so =1 if true, =0 if false
        if( (objcount+foundObj) > numberOfObjectives)
        {
            osilerror_wrapper( ch,osillineno,"actual number of objectives exceeds attribute numberOfObjectives"); return false;
        }
    }
    if(objcount < numberOfObjectives) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is greater than actual number found"); return false;}
    ch -= i;
    // get the </objectives> tag
    for(i = 0; endObjectives[i]  == *ch; i++, ch++);
    if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}    
    ch++;
    } // finish the (if numberOfObjectives > 0)
    else{
        // error if the number is negative
        if(numberOfObjectives < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of objectives"); return false;}
        // if we are here we have exactly 0 objectives 
        // must close with /> or </objectives>
        // get rid of white space
        BURNWHITESPACE( ch );
        if( *ch == '/'){
            // better have a >
            ch++;
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
            ch++;
        }
        else{
            // if we are here we must have an '>' and then  </objectives> tag
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
            ch++;
            // burn white space and comments
            FINDNEXTTAG( ch );
            for(i = 0; endObjectives[i]  == *ch; i++, ch++);
            if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}    
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseObjectives

bool parseConstraints( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();    
    const char *c_numberOfConstraints = "numberOfConstraints";
    const char *startConstraints = "<constraints";
    const char *endConstraints = "</constraints";
    const char *startCon = "<con";
    const char *endCon = "</con";
    // attributes
    char *attText = NULL;
    const char *name = "name";
    const char *constant = "constant";
    const char *mult = "mult";
    // others
    int i; 
    int concount = 0;
    int numberOfConstraints = 0;
    // constraint attribute boolean variables
    bool conlbattON = false ;
    bool conubattON  = false;
    bool connameattON = false;
    bool conconstantattON  = false;
    bool conmultattON = false;
    bool foundCon = false;
    int conmult;
    // 
    // start parsing -- ok not to have constraints
    // burn white space
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <constraints element if there -- it is not required
    *p = ch;
    for(i = 0; startConstraints[i]  == *ch; i++, ch++);
    while( *startConstraints++  == *ch) ch++;
    if( (ch - *p) != 12) {
        //  *p is the correct value for the pointer
        return true;
    }

    osinstance->instanceData->constraints = new Constraints();

    // find numberOfConstraints attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while( *c_numberOfConstraints++  == *ch) ch++;
    if( (ch - *p) != 19) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfConstraints attribute in <constraints> tag"); return false;}    
    // ch should be pointing to the first character after numberOfConstraints
    GETATTRIBUTETEXT;
    ch++;
    numberOfConstraints = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // key if
    //
    if(numberOfConstraints > 0){
        osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
        osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
        for(i = 0; i < numberOfConstraints; i++){
            osinstance->instanceData->constraints->con[ i] = new Constraint();
        } 
    // get rid of white space after the numberOfConstraints element
    BURNWHITESPACE( ch );
    //  we better have an > 
    if( *ch++ != '>') {   osilerror_wrapper( ch,osillineno,"the constraints element does not have a proper closing"); return false;} 
    // get rid of white space and comments after the <constraints> element
    FINDNEXTTAG( ch );
    // now loop over the con elements, there must be at least one con element
    *p = ch;
    while( *startCon++  == *ch) ch++;
    if( (ch - *p) == 4) foundCon = true;
        else {  osilerror_wrapper( ch,osillineno,"there must be at least one <con> element"); return false;}
    startCon -= 5;
    while(foundCon){
        conlbattON = false ;
        conubattON  = false;
        connameattON = false;
        conconstantattON  = false;
        conmultattON = false;
        conmult = 1;

        // assume we are pointing to the first character after the n in <con
        // it should be a space so let's increment ch
        BURNWHITESPACE( ch );
        while(*ch != '/' && *ch != '>'){
            switch (*ch) {
            case 'n':
                *p = ch;
                while( *name++  == *ch) ch++;
                if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints name attribute"); return false;}
                if(connameattON == true) {  osilerror_wrapper( ch,osillineno,"too many con name attributes"); return false;}
                name -= 5;
                connameattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->name=attText;
                delete [] attText;
                break;
            case 'c':
                *p = ch;
                while( *constant++  == *ch) ch++;
                if( ((ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in constraint constant attribute"); return false;}
                if(conconstantattON == true) {  osilerror_wrapper( ch,osillineno,"too many con constant attributes"); return false;}
                constant -= 9;
                conconstantattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->constant=atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'l':
                ch++;
                if(*ch++ != 'b') {   osilerror_wrapper( ch,osillineno,"error in constraint lb attribute"); return false;}
                if(conlbattON == true) {  osilerror_wrapper( ch,osillineno,"too many con lb attributes"); return false;}
                conlbattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->lb = atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'u':
                ch++;
                if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in constraint ub attribute"); return false;}
                if(conubattON == true) {  osilerror_wrapper( ch,osillineno,"too many con ub attributes"); return false;}
                conubattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->ub = atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'm':
                *p = ch;
                while( *mult++  == *ch) ch++;
                if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints mult attribute"); return false;}
                if(conmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many con mult attributes"); return false;}
                mult -= 5;
                conmultattON = true;
                GETATTRIBUTETEXT;
                conmult = atoimod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case ' ':
                break;
            case '\n':
                (*osillineno)++;
                break;
            case '\t':
                break;
            case '\r':
                break;
            default:
                osilerror_wrapper( ch,osillineno,"invalid attribute character");
                return false;
                break;
            }
            ch++;
        }
        //
        // assume all the attributes have been processed
        // must have either /> or > and then whitespace and </con whitespace>
        if( *ch != '/' && *ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
        if(*ch == '/'){
            ch++;
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
            // get rid of whitespace
            ch++;
            FINDNEXTTAG( ch );
            // either have another <con> element or foundCon = false;
            *p = ch;
            while( *startCon++  == *ch) ch++;
            if( (ch - *p) == 4){
                 foundCon = true;
                 startCon -= 5;
            }
            else{
                foundCon = false;
                ch = *p;
            }
        }
        else{
            // the ch is the > at the end of the con element 
            // double check to make sure it really is a >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <con> element"); return false;}
            // look for </con
            // fist get rid of white space
            ch++;
            FINDNEXTTAG( ch );
            // we should be at </con or there is an error
            *p = ch;
            while( *endCon++  == *ch) ch++;
            if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</con> element missing"); return false;}
            endCon -= 6;
            // burn off the whitespace
            BURNWHITESPACE( ch );
            // better have an > to end </con
            if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</con> element missing >"); return false;}
            // look for a new <con> element
            // get rid of whitespace
            ch++;
            FINDNEXTTAG( ch );
            // either have another <con> element or foundVar = false;
            *p = ch;
            while( *startCon++  == *ch) ch++;
            if( (ch - *p) == 4){
                 foundCon = true;
                 startCon -= 5;
            }
            else{
                 foundCon = false;
                 ch = *p;
            }
        }
        if( (concount+conmult) <= numberOfConstraints)
        {
            for (int k=1; k < conmult; k++)
            {
                osinstance->instanceData->constraints->con[concount+k]->name
                = osinstance->instanceData->constraints->con[concount]->name;
                osinstance->instanceData->constraints->con[concount+k]->constant
                = osinstance->instanceData->constraints->con[concount]->constant;
                osinstance->instanceData->constraints->con[concount+k]->lb
                = osinstance->instanceData->constraints->con[concount]->lb;
                osinstance->instanceData->constraints->con[concount+k]->ub
                = osinstance->instanceData->constraints->con[concount]->ub;
            }
        }
        concount += conmult;

//        if( (concount >= numberOfConstraints) && (foundCon == true))
        // foundCon is bool, so =1 if true, =0 if false
        if( (concount+foundCon) > numberOfConstraints)
        {
            osilerror_wrapper( ch,osillineno,"actual number of constraints exceeds attribute numberOfConstraints");
            return false;
        }
    }
    if(concount < numberOfConstraints) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is greater than actual number found"); return false;}
    // get the </constraints> tag
    *p = ch;
    while( *endConstraints++  == *ch) ch++;
    if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag");    return false;}
    ch++;
    }// end if(numberOfConstraints > 0)
    else{
        // error if the number is negative
        if(numberOfConstraints < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of constraints"); return false;}
        // if we are here we have numberOfConstraints = 0
        // must close with /> or </constraints>
        // get rid of white space
        FINDNEXTTAG( ch );
        if( *ch == '/'){
            // better have a >
            ch++;
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
            ch++;
        }
        else{
            // if we are here we must have an '>' and then  </constraints> tag
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
            ch++;
            // burn white space
            FINDNEXTTAG( ch );
            *p = ch;
            while( *endConstraints++  == *ch) ch++;
            if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false; }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag"); return false;}    
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients( const char **p, OSInstance *osinstance, int* osillineno){;
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;    
    const char *c_numberOfValues = "numberOfValues";
    const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
    const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
    // attributes
    char *attText = NULL;
    // others
    int numberOfValues;
    // start parsing
    // burn white space and comments
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
    *p = ch;
    while( *startlinearConstraintCoefficients++  == *ch) ch++;
    if( (ch - *p) != 29) {
        //reset ch
        ch = *p;
        return true;
    }

    osinstance->instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients();

    // find numberOfValues attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while( *c_numberOfValues++  == *ch) ch++;
    if( (ch - *p) != 14) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
    // ch should be pointing to the first character after numberOfValues
    GETATTRIBUTETEXT;
    ch++;
    numberOfValues = atoimod1( osillineno, attText, attTextEnd);
    if(numberOfValues > 0 && osinstance->instanceData->variables->numberOfVariables == 0){  osilerror_wrapper( ch,osillineno,"we have zero variables, but A matrix coefficients"); return false;}
    delete [] attText;
    if(numberOfValues <= 0) {  osilerror_wrapper( ch,osillineno,"the number of nonlinear nonzeros must be positive"); return false;}
    osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
    // get rid of white space after the numberOfConstraints element
    BURNWHITESPACE( ch );
    // we should have either an />  OR an >
    if(*ch == '/'){
        ch++;
        if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the linearConstraintCoefficients element does not have a proper closing"); return false;} 
        else{
            if(numberOfValues > 0) {  osilerror_wrapper( ch,osillineno,"numberOfValues positive, but there are no values"); return false;}
            return false;
        }        
    }
    //  we better have an > 
    if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
    // get rid of white space and commentsafter the <linearConstraintCoefficients> element
    FINDNEXTTAG( ch );
    if(  parseStart(  &ch, osinstance, osillineno) != true) {osilerror_wrapper( ch,osillineno,"error processing <start> element"); return false;}
//    if( (parseColIdx( &ch, osinstance, osillineno) != true) && (parseRowIdx( &ch, osinstance, osillineno) != true)) return false;
//    if( (parseColIdx( &ch, osinstance, osillineno) == true) && (parseRowIdx( &ch, osinstance, osillineno) == true)) {osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); return false;}

    if(  parseColIdx( &ch, osinstance, osillineno) == true) // <colIdx> is found as first element
    {
        if( parseRowIdx( &ch, osinstance, osillineno) == true) //also have <rowIdx> --- can't happen
        {
            osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); 
            return false;
        }
    }
    else //<colIdx> is not the first element
    {
        if( parseRowIdx( &ch, osinstance, osillineno) != true) // neither <rowIdx> nor <colIdx> is present
        {
            osilerror_wrapper( ch,osillineno,"must have either RowIdx or ColIdx"); 
            return false;
        }
        else //<rowIdx> is found as first element
        {
            if ( parseColIdx( &ch, osinstance, osillineno) == true ) //also have <colIdx> --- can't happen 
            {
                osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); 
                return false;
            }
        }
    }

    if(  parseValue(  &ch, osinstance, osillineno) != true) {osilerror_wrapper( ch,osillineno, "could not parse <value> element"); return false;}
    // get the </linearConstraintCoefficients> tag
    FINDNEXTTAG( ch );
    *p = ch;
    while( *endlinearConstraintCoefficients++  == *ch) ch++;
    if( (ch - *p) != 30) {  osilerror_wrapper( ch,osillineno, "cannot find </linearConstraintCoefficients> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </linearConstraintCoefficients> tag"); return false;}
    ch++;    
    *p = ch;
    return true;
}//end parseLinearConstraintCoefficients

bool parseStart(const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startStart = "<start";
    const char* endStart = "</start";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    FINDNEXTTAG( ch );
    // if, present we should now be pointing to <start element 
    *p = ch;
    while( *startStart++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <start
    BURNWHITESPACE( ch );
    // we should have an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <start> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL) {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
        intvec = (int*)&base64decodeddata[0];
        int k, kp;
        kp = 0;
        for (i = 0; i < (base64decodeddatalength/dataSize); i++)
        {
            k = *(intvec++);
            if (k < kp)
            {
                osilerror_wrapper( ch,osillineno,"<start> must have nondecreasing entries ");
                 return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = k;
            kp = k;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        osinstance->instanceData->linearConstraintCoefficients->start->el = 
        new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
        osinstance->instanceData->variables->numberOfVariables) + 1];
        while(foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in starts incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    if (elincr < 0)
                    {
                        osilerror_wrapper( ch,osillineno,"incr of start array cannot be negative");
                        return false;
                    }
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in starts mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }

            // start eating white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            
            // we better not exceed allocation
            if(kount + elmult > std::max(osinstance->instanceData->constraints->numberOfConstraints,
                                         osinstance->instanceData->variables->numberOfVariables) + 1 )
            {
                osilerror_wrapper( ch, osillineno,"number of start elements exceeds the maximum number of rows or columns plus  1");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);
            int kp;
            if (kount == 0)
                kp = 0;
            else
                kp = osinstance->instanceData->linearConstraintCoefficients->start->el[ kount-1];

            for (int j=0; j < elmult; j++)
            {
                if (k < kp)
                {
                    osilerror_wrapper( ch,osillineno,
                        "column starts in linear constraint coefficient matrix must be non-decreasing"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->start->el[ kount+j] = k;
                kp = k;
                k += elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p)  == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                 foundEl = false;
                 ch = *p;
            }
        }    
        
        if(osinstance->instanceData->linearConstraintCoefficients->start->el[ kount - 1 ] != 
        osinstance->instanceData->linearConstraintCoefficients->numberOfValues ) 
        osilerror_wrapper( ch, osillineno,"the value of the last start element is not equal to numberOfValues");    
    }
    // get the </start> tag
    *p = ch;
    while( *endStart++  == *ch) ch++;
    if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </start> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </start> tag");    return false;}
    ch++;    
    // get the end element
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE STARTS  = %f\n", duration);
    #endif
    *p = ch;
    osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements = kount;

    return true;
}//end parseStart

bool parseRowIdx( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startRowIdx = "<rowIdx";
    const char* endRowIdx = "</rowIdx";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    int numberOfEl;
    
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <rowIdx element 
    *p = ch;
    while( *startRowIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <rowIdx
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <rowIdx> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<rowIdx> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        numberOfEl = (base64decodeddatalength/dataSize);
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[numberOfEl ];
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = numberOfEl;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->variables->numberOfVariables + 1;
        intvec = (int*)&base64decodeddata[0];
        int k;
        for(i = 0; i < numberOfEl; i++)
        {
            k = *(intvec++);
            if (k < 0 || k >= osinstance->instanceData->constraints->numberOfConstraints)
            {
                osilerror_wrapper( ch,osillineno,"row index out of bounds"); 
                return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = k;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        // if we are here we are storing the problem by column
        // this means the number of start elements must equal the number of columns + 1
        if( osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->variables->numberOfVariables  + 1)
        osilerror_wrapper( ch, osillineno,"we are storing in column major format, but number of start elements not equal number of variables + 1");
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->variables->numberOfVariables + 1;
        while(foundEl){
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in rowIdx incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in rowIdx mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }

            // start munging white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // mung white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {   osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of rowIdx elements exceeds the number declared");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);

            for (int j=0; j < elmult; j++)
            {
                if (k < 0 || k >= osinstance->instanceData->constraints->numberOfConstraints)
                {
                    osilerror_wrapper( ch,osillineno,
                        "row index out of bounds in linear constraint coefficient matrix"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount+j] = k;
                k += elincr;
            }

            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p)  != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start munging white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                foundEl = true;
                startEl -= 4;
            }
            else{
                foundEl = false;
                ch = *p;
            }
        }
    }
    // get the </rowIdx> tag
    *p = ch;
    while( *endRowIdx++  == *ch) ch++;
    if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </rowIdx> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </rowIdx> tag");}    
    ch++;    
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
    #endif
    *p = ch;
     return true;
}//end parseRowIdx


bool parseColIdx( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startColIdx = "<colIdx";
    const char* endColIdx = "</colIdx";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    int numberOfEl;
    
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <colIdx element 
    *p = ch;
    while( *startColIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <colIdx
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <colIdx> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<colIdx> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        numberOfEl = (base64decodeddatalength/dataSize);
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[numberOfEl ];
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = numberOfEl;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->constraints->numberOfConstraints + 1;
        intvec = (int*)&base64decodeddata[0];
        int k;
        for(i = 0; i < numberOfEl; i++)
        {
            k = *(intvec++);
            if (k < 0 || k >= osinstance->instanceData->variables->numberOfVariables)
            {
                osilerror_wrapper( ch,osillineno,"col index out of bounds"); 
                return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = k;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        // if we are here we are storing the problem by row
        // this means the number of start elements must equal the number of rows + 1
        if(osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->constraints->numberOfConstraints  + 1)
        osilerror_wrapper( ch, osillineno,"we are storing in row major format, but number of start elements not equal number of rows + 1");
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->constraints->numberOfConstraints + 1;
        while(foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in colIdx incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in colIdx mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }
        
            // start eating white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of colIdx elements exceeds the number declared");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);

            for (int j=0; j < elmult; j++)
            {
                if (k < 0 || k >= osinstance->instanceData->variables->numberOfVariables)
                {
                    osilerror_wrapper( ch,osillineno,
                        "col index out of bounds in linear constraint coefficient matrix"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount+j] = k;
                k += elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                 foundEl = false;
                 ch = *p;
            }
        }
    }
    // get the </colIdx> tag
    *p = ch;
    while( *endColIdx++  == *ch) ch++;        
    if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </colIdx> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </colIdx> tag"); return false;}    
    ch++;    
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
    #endif
    *p = ch;
     return true;
}//end parseColIdx

bool parseValue( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startValue = "<value";
    const char* endValue = "</value";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    double elincr;
    FINDNEXTTAG( ch );
    // if present we should be pointing to <value element 
    *p = ch;
    while( *startValue++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <value
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <value> element"); return false;}
    ch++;
    // get rid of white space
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;};
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
        int kountChar = 0;
        int kj;
        /* Take care of Lou's memory alignment problem */
        /* dataSize had better equal sizeof( double) or we need to abandon ship */
        if( sizeof( double)  != dataSize ) {  
            osilerror_wrapper( ch, osillineno, 
                "base 64 encoded with a size of double different than on this machine"); 
            return false;
        }    
        union doubleBuffer{
            char memAlign[sizeof(double)];
            double dble;
        };
        doubleBuffer dbuf;
        for(i = 0; i < (base64decodeddatalength/dataSize); i++){
            for(kj = 0; kj < dataSize; kj++){
                dbuf.memAlign[ kj] = base64decodeddata[kountChar];
                kountChar++;
            }
            osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = dbuf.dble;
            //std::cout << dbuf.dble << std::endl;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        osinstance->instanceData->linearConstraintCoefficients->value->el = 
            new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        while( foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in values incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in values mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }
        
            // start eat white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            *p = ch;
            // find the end of the number, it better be an </el>
            // find the < which begins the </el
            while( *ch != '<' && *ch != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of nonzero elements exceeds the number declared");
                return false;           
            }
            osinstance->instanceData->linearConstraintCoefficients->value->el[ kount] = atofmod1( osillineno, *p, ch);
            for (int k=1; k < elmult; k++)
            {
                osinstance->instanceData->linearConstraintCoefficients->value->el[ kount+k] 
                = osinstance->instanceData->linearConstraintCoefficients->value->el[ kount] + k*elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                foundEl = false;
                ch = *p;
            }
        }    
    }
    osinstance->instanceData->linearConstraintCoefficients->value->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
    
    // get the </value> tag
    *p = ch;
    while( *endValue++  == *ch) ch++;
    if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </value> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </value> tag");     return false;}
    ch++;    
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients greater than number of values found"); return false;}
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients less than the number of values found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE VALUES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseValue

bool parseObjCoef( const char **p, int objcount, OSInstance *osinstance, int* osillineno){
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    const char* startCoef = "<coef";
    const char* endCoef = "</coef";
    const char* c_idx = "idx";
    char *attText = NULL;
    int k;
    int numberOfObjCoef = 0; 
    if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {  osilerror_wrapper( ch,osillineno,"we can't have objective function coefficients without an objective function"); return false;}
    numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
    if(numberOfObjCoef > 0)    {
    for(k = 0; k < numberOfObjCoef; k++){
        FINDNEXTTAG( ch );
        // if, present we should be pointing to <coef element 
        *p = ch;
        while( *startCoef++  == *ch) ch++;
        if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"improper <coef> element"); return false;}
        startCoef -= 6;
        // get the idx attribute
        // eat the white space after <coef
        BURNWHITESPACE( ch );
        *p = ch;
        while( *c_idx++  == *ch) ch++;
        if( (ch - *p) != 3) {  osilerror_wrapper( ch,osillineno,"incorrect idx attribute in objective function <idx> tag"); return false;}    
        c_idx -= 4;
        // ch should be pointing to the first character after idx attribute
        GETATTRIBUTETEXT;
        int idx = atoimod1( osillineno, attText, attTextEnd);
        if (idx < 0 || idx >= osinstance->instanceData->variables->numberOfVariables)
        {
            osilerror_wrapper( ch,osillineno,"incorrect variable idx in objective function specification");
            return false;
        }
        osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx = idx;
        delete [] attText;
        ch++;    
        // eat white space
        BURNWHITESPACE( ch );
        // if we don't have a > there is an error
        if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect <coef> element")    ; return false;}    
        // we should be pointing to first character after <coef>
        *p = ch;
        // eat characters until we find <
        for(; *ch != '<' && *ch != EOF; ch++); 
        // put back here

        // we should be pointing to a < in the </coef> tag    
        if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"improper </coef> tag"); return false;}
        osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( osillineno, *p, ch);
        *p = ch;
        while( *endCoef++  == *ch) ch++;
        if( (ch - *p) != 6)  {  osilerror_wrapper( ch,osillineno,"improper </coef> element"); return false;}
        endCoef -= 7;
        // get rid of white space after </coef
        BURNWHITESPACE( ch );
        // if we don't have a > there is an error
        if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect </coef> element")    ; return false;}
    }
    }// end if(numberOfObjCoef > 0)
    *p = ch;
    return true;
}//end parseObjCoef

char *parseBase64(const char **p, long int *dataSize, int* osillineno ){
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    const char *sizeOf = "sizeOf";
    //char *numericType = "numericType";
    const char *startBase64BinaryData = "<base64BinaryData";
    const char *endBase64BinaryData = "</base64BinaryData";
    char *attText = NULL;
    char *b64string = NULL;
    int i;
    // start parsing
    for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
    if(i != 17) {
        ch -= i;
        *p = ch;
        return b64string;
    }
    // find sizeOf attribute
    // eat the white space
    BURNWHITESPACE( ch );
    for(i = 0; sizeOf[i]  == *ch; i++, ch++);
    if(i != 6) {  osilerror_wrapper( ch,osillineno,"incorrect sizeOf attribute in <base64BinaryData> element"); return false;}    
    // ch should be pointing to the first character after sizeOf
    GETATTRIBUTETEXT;
    ch++;
    *dataSize = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // since the element must contain b64 data,  this element must end with > 
    // eat the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"<base64BinaryData> element does not have a proper closing >"); return false;}
    ch++;
    // we are now pointing start of the data
    const char *b64textstart = ch;
    // eat characters until we get to the </base64BinaryData element
    for(; *ch != '<' && *ch != EOF; ch++);
    const char *b64textend = ch;
    // we should be pointing to </base64BinaryData>
    for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
    if(i != 18) { osilerror_wrapper( ch,osillineno," problem with <base64BinaryData> element"); return false;}
    long int b64len = b64textend - b64textstart;
    b64string = new char[ b64len + 1]; 
    for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
    b64string[ki] = '\0';    
    // burn the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"</base64BinaryData> element does not have a proper closing >"); return false;}
    ch++;
    BURNWHITESPACE( ch );
    *p = ch;
    return b64string;
}


double atofmod1(int* osillineno, const char *number, const char *numberend){
    double val;
       char *pEnd;
    val = os_strtod_wrap(number, &pEnd);
    // pEnd should now point to the first character after the number;
    // burn off any white space    
    for( ; ISWHITESPACE( *pEnd) || isnewline( *pEnd, osillineno); pEnd++ ) ;
    // pEnd should now point to numberend, if not we have an error
    if(pEnd != numberend) osilerror_wrapper( pEnd,   osillineno, "error in parsing an XSD:double");
    return val;
}//end atofmod



int atoimod1(int* osillineno, const char *number, const char *numberend){
    // modified atoi from Kernighan and Ritchie
    int ival;
    int i, sign;
    int endWhiteSpace;
    for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
    endWhiteSpace = i;
    sign = (number[ i] == '-') ? -1 : 1;
    if (number[ i] == '+' || number[ i] == '-') i++;
    for(ival = 0; ISDIGIT( number[ i]); i++){
        ival = 10*ival + (number[ i] - '0') ;
    }
    if(i == endWhiteSpace) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int" );     }
    // if we are here we should having nothing but white space until the end of the number
    for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
    if(number[i] == *numberend){
        return sign*ival;
    }
    else {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int"); return OSINT_MAX;    }
}//end atoimod1

void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg){
    const int numErrorChar = 20;
    char errorArray[100] = "";
    strncpy(errorArray, ch, numErrorChar);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "PARSER ERROR:  Input is either invalid or ill-formed: "  + error;
    outStr << error << endl;
    outStr << "Here are " ;
    outStr << numErrorChar ;
    outStr << " characters currently being pointed to in the input string: ";
    outStr << errorArray;
    outStr << endl;
    outStr << "See line number: " << *osillineno << endl;  
    error = outStr.str();
    //osillex_destroy(scanner);
    throw ErrorClass( error);
}//end osilerror_wrapper

void osil_empty_vectors( OSiLParserData* parserData){
/*
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for( k = 0; k < numOtherVarVec; k++){
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarText != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarText;
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarIndex;
            
        if( parserData->otherVarVec[ k]  != NULL) delete parserData->otherVarVec[ k];
    }

      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for(k = 0; k < numDualVals; k++){
          if( parserData->dualVals[ k]  != NULL  ) 
            delete parserData->dualVals[ k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for(k = 0; k < numObjVals; k++){
          if( parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for(k = 0; k < numPrimalVals; k++){    
          if( parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
*/      
}//end osil_empty_vectors

