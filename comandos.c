#include <stdio.h>
#include "comandos.h"
#include "Error.h"
#include "workspace.h"
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//VARIABLES EXTERNAS
extern FILE* yyin;
extern void yyterminate();
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//VARIABLES GLOBALES
int g_echo=1;
int g_cmd=0;
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//FUNCIONES
//imprime la ayuda
void help(){
    printf("\n");
    printf("               ---HELP---\n");
    printf("----------------------------------------\n");
    printf("OPERACIONES:\n");
    printf("- a+b\n");
    printf("- a-b\n");
    printf("- a*b\n");
    printf("- a/b\n");
    printf("- a^b\n");
    printf("FUNCIONES:\n");
    printf("- cos(x) -> devuelve el coseno de la expresión x.\n");
    printf("- sin(x) -> devuelve el seno de la expresión x.\n");
    printf("- tan(x) -> devuelve la tangente de la expresión x.\n");
    printf("- exp(x) -> devuelve el valor exponencial de la expresión x.\n");
    printf("- log(x) -> devuelve el logarítmica de la expresión x.\n");
    printf("- sqrt(x) -> devuelve la raíz cuadrada de la expresión x. \n");
    printf("COMANDOS:\n");
    printf("- worskpace -> ver variables del workspace.\n");
    printf("- clean -> limpiar todas variables del workspace.\n");
    printf("- cleanVariable \"x\" -> elimina la variable \"x\" del workspace.\n");
    printf("- load \"archivo\" -> lee el fichero \"archivo\".\n") ;
    printf("- quit -> finaliza el programa.\n");
    printf("NOTA: se podrá escribir de la forma a+b+c o a+b+c; ya sean comandos funciones u operaciones.\n");
    printf("----------------------------------------\n");
    printf("\n");
}

//imprimo las variables del workspace
void workspace(){
    printf("\n");
    printf("----------------------------------------\n");
    printf("VARIABLES\n");
    imprimir_workspace();
    printf("----------------------------------------\n");
    printf("\n");
}
//destruyo y vuelvo a crear el workspace
void clean(){
    destruir_workspace();
    inicializar_workspace();
    printf("El workspace se ha limpiado!\n");
    printf("\n");
}
//elimino la variable de la tabla hash
void cleanVariable(char *var){
	tipoelem *lex=insertar_workspace(var);
	borrar_elemento_workspace(*lex);
	printf("Se ha eliminado la variable %s del workspace!\n",var);
	printf("\n");
}
//destruyo el workspace 
void quit(){
    printf("Saliendo...\n");
}
//lee el fichero "archivo"
void load(char *archivo){
    printf("Leyendo el archivo: %s\n", archivo);
    //lee el archivo que se pasa
    yyin = fopen(archivo, "r");
    //si no se puede abrir el archivo paso como entrada el stdin
    if(yyin == 0){
    	printf("No se pudo abrir el archivo.\n");
        yyin = stdin;
    }
}
//cuando se llama a echo si está en 1 pasa a 0 y viceversa
void echo(){
	if(g_echo==1){
		g_echo=0;
	}
	else{
		g_echo=1;
	}
}
//devuelve el valor de echo
int esEcho(){	
	return g_echo;
}
//cuando se llama a comando si está en 1 pasa a 0 y viceversa para detectar si es un error o comando
void comando(){
	if(g_cmd==1){
		g_cmd=0;
	}
	else{
		g_cmd=1;
	}
}
//devuelve el valor de comando
int esComando(){	
	return g_cmd;
}
