%option nounput yylineno
%option noyywrap
%option noinput
%{
#include "Sintactico.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "workspace.h"
#include "Error.h"
#include "lista.h"

%}
LIT_CADENA \"[^\n\"]*\"
ALPHA [a-zA-Z]
DIGITO [0-9]
BINDIGITO [0-1]
OCTDIGITO [0-7]
HEXDIGITO [a-fA-F]|{DIGITO}
NOCERODIGITO [1-9]
DIGITPART {DIGITO}(["_"]|{DIGITO})*
FRACTION  "."{DIGITPART}
EXPONENT      ("e"|"E")([+]|[-])?{DIGITPART}
POINTFLOAT    {DIGITPART}{FRACTION}|{DIGITPART}"."
EXPONENTFLOAT ({DIGITPART}|{POINTFLOAT}){EXPONENT}
FLOAT         {POINTFLOAT}|{EXPONENTFLOAT}
INT           {NOCERODIGITO}(["_"]|{DIGITO})*|"0"+(["_"]|"0")*
%%
	
<<EOF>> {printf("Fin del archivo!\n");printf("\n");yyrestart(stdin);}
[\t]		;
			
" "		;

{LIT_CADENA} {strncpy(yylval.archivo, &yytext[1], yyleng-2);yylval.archivo[yyleng-2]='\0';return T_CADENA;}

({ALPHA}|"_")+({ALPHA}|{DIGITO}|"_")* 	{tipoelem *elem = insertar_workspace(yytext);yylval.ele=elem;return T_VAR;}

{FLOAT}|{INT}   {yylval.dval = atof(yytext); return T_DOUBLE;}

\n		{return T_NEWLINE;}

"="		{return T_EQUAL;}

"+"		{return T_PLUS;}

"-"		{return T_MINUS;}

"*"		{return T_MULTIPLY;}

"/"		{return T_DIVIDE;}

"^"             {return T_POW;}

"("		{return T_LEFT;}

")"		{return T_RIGHT;}

";" 		{return T_CF;}

. {return T_ERROR;}
%%