/*                                                                                                                            
*Filename    parse.y                                                                                                         
*Date        4/9/2021                                                                                                       *Version      1.0                                                                                                             
*Copyright   2021, All Rights Reserved                                                                                       
*                                                                                                                            
*Description                                                                                                                 
*                                                                                                                            
* Parser with postal addresses grammar                                                                   
*/


%{
#include <stdio.h>
int yylex(void);
 void yyerror(char *);
 extern char* yytext;
 %}

%union
 {
   int value;
   char *str;
}

// Tokens and token types
%type <value> INTTOKEN
%type <str> NAMETOKEN
%type <str> NAME_INITIAL_TOKEN
%type <str> IDENTIFIERTOKEN
%type <str> EOLTOKEN
%type <str> ROMANTOKEN
%type <str> JRTOKEN
%type <str> SRTOKEN
%type <str> COMMATOKEN
%type <str> DASHTOKEN
%type <str> HASHTOKEN

%token INTTOKEN
%token NAMETOKEN
%token NAME_INITIAL_TOKEN
%token IDENTIFIERTOKEN
%token EOLTOKEN
%token ROMANTOKEN
%token JRTOKEN
%token SRTOKEN
%token COMMATOKEN
%token DASHTOKEN
%token HASHTOKEN

%start postal_addresses

%%

postal_addresses: 
                    address_block EOLTOKEN postal_addresses
		 |  address_block
		    ;

address_block:
                    name_part street_address location_part
		    ;

name_part:
                    personal_part last_name suffix_part EOLTOKEN
                 |  personal_part last_name EOLTOKEN
                 |  error EOLTOKEN {printf("Bad name_part...skipping to newline \n");}
                 ;

personal_part:
                    NAMETOKEN {fprintf(stderr, "<FirstName>%s</FirstName>\n", $1);}
                 |  NAME_INITIAL_TOKEN {fprintf(stderr, "<FirstName>%s</FirstName>\n", $1);} 
                 ;

last_name:
                    NAMETOKEN {fprintf(stderr, "<LastName>%s</LastName>\n", $1);}
                 ;

suffix_part:
                    SRTOKEN {fprintf(stderr, "<Suffix>%s</Suffix>\n", yytext);}
                 |  JRTOKEN {fprintf(stderr, "<Suffix>%s</Suffix>\n", yytext);}
                 |  ROMANTOKEN {fprintf(stderr, "<Suffix>%s</Suffix>\n", yytext);}
                 ;

street_address:
                    street_number street_name INTTOKEN {fprintf(stderr, "<AptNum>%d</AptNum>\n", $3);} EOLTOKEN
		 |  street_number street_name HASHTOKEN INTTOKEN {fprintf(stderr, "<AptNum>%d</AptNum>\n", $4);} EOLTOKEN
                 |  street_number street_name EOLTOKEN
		 |  error EOLTOKEN {printf("Bad street_address...skipping to newline \n");}
                 ;

street_number:
                    INTTOKEN {fprintf(stderr, "<HouseNumber>%d</HouseNumber>\n", $1);}
                 |  IDENTIFIERTOKEN {fprintf(stderr, "<HouseNumber>%s</HouseNumber>\n", $1);}
                 ;

street_name:
                    NAMETOKEN {fprintf(stderr, "<StreetName>%s</StreetName>\n", $1);}
                 ;
 
location_part:
                    town_name COMMATOKEN state_code zip_code EOLTOKEN
		 |  error EOLTOKEN {printf("Bad location_part...skipping to newline \n");}
                 ;

town_name:
                    NAMETOKEN {fprintf(stderr, "<City>%s</City>\n", $1);}
                 ;

state_code:
                    NAMETOKEN {fprintf(stderr, "<State>%s</State>\n", $1);}

zip_code:
                    INTTOKEN {fprintf(stderr, "<Zip5>%d</Zip5>\n\n", $1);}
                 |  INTTOKEN {fprintf(stderr, "<Zip5>%d</Zip5> \n", $1);} zip_right
		 ;

zip_right:

		 DASHTOKEN INTTOKEN {fprintf(stderr, "<Zip4>%d</Zip4> \n\n", $2);}
                ;

%%

void yyerror(char *s)
{
}
