#include "workspace.h"
#include <stdio.h>
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//VARIABLES EXTERNAS
extern int yyparse();
extern FILE* yyin;
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//MAIN
int main(){
	inicializar_workspace();
	printf("_____CALCULADORA BISON-FLEX_____\n");
	printf("NOTAS: escriba help para leer el manual||echo está activado por defecto.\n");
	yyin = stdin;
    	yyparse();
	destruir_workspace();
	return 0;
}