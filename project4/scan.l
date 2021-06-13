/*                                                                                                                             
 Filename    scan.l                                                                                                           
 Date        4/9/2021                                                                                                         
 Author      Brianna Murray                                                                                                   
 Email       bnm180003@utdallas.edu                                                                                           
 Version     1.0                                                                                                              
 Copyright   2021, All Rights Reserved                                                                                                                                                                                                                  
 Description                                                                                                                                                                                                                                                 Scan file containting tokens and regular expressions                                                                     
*/

%option noyywrap
%option nounput
%option noinput

%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[ \t\r]+            { /* Take care of whitespace */ }
[A-Z]\.?         { yylval.str = yytext; return NAME_INITIAL_TOKEN; }
[a-zA-Z]{2,}       { yylval.str = strdup(yytext); return NAMETOKEN; } 
[0-9]+              { yylval.value = atoi (yytext); return INTTOKEN; }
[\n]              { yylval.str = yytext; return EOLTOKEN; }  
","                 { yylval.str = yytext; return COMMATOKEN; } 
[I|V|X]+          { yylval.str = yytext; return ROMANTOKEN; }
"Sr."               {  yylval.str = yytext; return SRTOKEN; }
"Jr."               {  yylval.str = yytext; return JRTOKEN; }
"#"                 { yylval.str = yytext; return HASHTOKEN; }
"-"                 { yylval.str = yytext; return DASHTOKEN; }
^[(A-Z)|(0-9)]{2,}  { yylval.str = yytext; return IDENTIFIERTOKEN; }

%%
