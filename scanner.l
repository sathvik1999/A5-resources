%{
# include "parser.tab.h"
# include "storetokens.hh"
%}
digit [0-9]
let_ [a-zA-Z_]
ident [a-zA-Z_0-9]
%%
[/][/].*		{;}
[ \t]			{;}
int 			{store_token_name("INTEGER",yytext,yylineno);return INTEGER;}
float 			{store_token_name("FLOAT",yytext,yylineno);return FLOAT;}
void 			{store_token_name("VOID",yytext,yylineno);return VOID;}
return 			{store_token_name("RETURN",yytext,yylineno);return RETURN;}
if 			{store_token_name("IF",yytext,yylineno);return IF;}
else 			{store_token_name("ELSE",yytext,yylineno);return ELSE;}
while 			{store_token_name("WHILE",yytext,yylineno);return WHILE;}
do 			{store_token_name("DO",yytext,yylineno);return DO;}
==			{store_token_name("EQUAL",yytext,yylineno);return EQUAL;}
[<]=			{store_token_name("LESS_THAN_EQUAL",yytext,yylineno);return LESS_THAN_EQUAL;}
[>]=			{store_token_name("GREATER_THAN_EQUAL",yytext,yylineno);return GREATER_THAN_EQUAL;}
[!]=			{store_token_name("NOT_EQUAL",yytext,yylineno);return NOT_EQUAL;}
[!]			{store_token_name("NOT",yytext,yylineno);return NOT;}
=			{store_token_name("ASSIGN_OP",yytext,yylineno);return ASSIGN;}
[<]			{store_token_name("LESS_THAN",yytext,yylineno);return LESS_THAN;}
[>]			{store_token_name("GREATER_THAN",yytext,yylineno);return GREATER_THAN;}
&&			{store_token_name("AND",yytext,yylineno);return AND;}
[|][|]			{store_token_name("OR",yytext,yylineno);return OR;}
{digit}+\.{digit}+	{store_token_name("FNUM",yytext,yylineno);yylval.fval = atof(yytext);return DOUBLE_NUMBER;}
{digit}+    		{store_token_name("NUM",yytext,yylineno);yylval.ival = atoi(yytext);return INTEGER_NUMBER;}
{let_}{ident}*		{store_token_name("NAME",yytext,yylineno);yylval.sval = new std::string(yytext);return NAME;}
[{},;()?:]		{store_token_name("META CHAR",yytext,yylineno);return yytext[0];}
[-+*/]  		{store_token_name("ARITHOP",yytext,yylineno); return yytext[0];}
[\n]			{}
.			{printf("Error cannot recognise this character %s\n",yytext);}
