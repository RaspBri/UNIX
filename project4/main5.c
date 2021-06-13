/*
*Filename    main5.c
*Date        4/9/2021
*Version     1.0
*Copyright   2021, All Rights Reserved
*
*Description
*
* Main file which calls the scanner and parser to function
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "y.tab.h"

int yyparse (void);
int yylex (void);
extern char *yytext;

int main(int argc, char *argv[]){
  
  int token;

  // Calling scanner
  if(strcmp(argv[0], "./scanner") == 0){
    printf("\nOperating in scan mode\n\n");
    token = yylex();

    // while loop continues until no more tokens found
    // prints token type to user
    while(token != 0){
      printf("yylex returned ");
      switch(token){
      case NAME_INITIAL_TOKEN:
	printf("NAME_INITIAL_TOKEN token(%s)\n", yytext);
	break;
      case IDENTIFIERTOKEN:
	printf("IDENTIFIERTOKEN token (%s)\n", yytext);
        break;
      case NAMETOKEN:
	printf("NAMETOKEN token (%s)\n", yytext);
	break;
      case EOLTOKEN:
	printf("EOLTOKEN token (%d)\n", token);
	break;
      case INTTOKEN:
	printf("INTTOKEN token (%s)\n", yytext);
	break;
      case ROMANTOKEN:
	printf("ROMANTOKEN (%s)\n", yytext);
	break;
      case SRTOKEN:
     	printf("SRTOKEN (%s)\n", yytext);
        break;
      case JRTOKEN:
        printf("JRTOKEN (%s)\n", yytext);
        break;
      case HASHTOKEN:
	printf("HASHTOKEN (%d)\n", token);
	break;
      case COMMATOKEN:
	printf("COMMATOKEN (%d)\n", token);
	break;
      case DASHTOKEN:
	printf("DASHTOKEN (%d)\n", token);
	break;
      }
      token = yylex();
    }
  }



  // Calling parser
  if(strcmp(argv[0], "./parser") == 0){
    printf("\nOperating in parse mode\n\n");
    // Switch statement for yyparse return statements
    switch(yyparse()){
       case 0:
	 printf("\n Parse Successful! \n");
	      break;
       case 1:
	      printf("Parse Failed!\n");
              break;
       case 2:
	      printf("Out of Memory\n");
	      break;
       default:
	      printf("Unknown result from yyparse()\n");
	      break;
    } 
  }

    printf("Done!\n");
    return 0;

}
