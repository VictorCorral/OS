/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
