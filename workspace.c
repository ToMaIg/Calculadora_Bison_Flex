#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include "workspace.h"
#include "hash_encadenamiento.h"
#include "comandos.h"
#define CTE 2
#define CMD 7
#define FNCT 6
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//VARIABLES GLOBALES
//workspace
TablaHash worksp;
//funciones
char *funciones[FNCT]={"sin","cos","tan","log","exp","sqrt"};
void *val_fun[FNCT]={(double(*)(double)) sin,(double(*)(double)) cos,(double(*)(double)) tan,(double(*)(double)) log,(double(*)(double)) exp,(double(*)(double)) sqrt};
//constantes
char *constantes[CTE]={"e","pi"};
double val_cte[CTE]={M_E,M_PI};
//comandos
char *comandos[CMD] = {"help", "workspace", "clean", "quit", "load", "echo", "cleanVariable"};
void *val_cmd[CMD] = {(void (*)(void)) help, (void (*)(void)) workspace,(void (*)(void)) clean, (void (*)(void)) quit,(void (*)(char*)) load,(void (*)(void)) echo, (void(*)(char*)) cleanVariable};
//variable inicializada (1) o no (0)
int init=1;
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//FUNCIONES
void inicializar_workspace(){
	//primero inicializo la tabla hash
	InicializarTablaHash(worksp);
	//meto en la tabla las constantes, las funciones y los comandos
	int i=0;
	tipoelem *elem=(tipoelem*) malloc(sizeof(tipoelem));
	for(i=0;i<CTE;i++){
		
        	strncpy(elem->lexema, constantes[i],(int)strlen(constantes[i]));
        	elem->lexema[(int)strlen(constantes[i])]='\0';

        	elem->compLex = 0;
       	 	elem->tiene_valor = 1;
        	elem->valor.var = val_cte[i];
		//inserta en la tabla hash
        	InsertarHash(&worksp,*elem);
	}
	for(i=0;i<FNCT;i++){
		
        	strncpy(elem->lexema, funciones[i],(int)strlen(funciones[i]));
        	elem->lexema[(int)strlen(funciones[i])]='\0';

        	elem->compLex = 1;
       	 	elem->tiene_valor = 1;
        	elem->valor.fun = val_fun[i];
        	//inserta en la tabla hash
        	InsertarHash(&worksp,*elem);
	}
	for(i=0;i<CMD;i++){
		
        	strncpy(elem->lexema, comandos[i],(int)strlen(comandos[i]));
        	elem->lexema[(int)strlen(comandos[i])]='\0';

        	elem->compLex = 2;
       	 	elem->tiene_valor = 1;
        	elem->valor.fun = val_cmd[i];
        	//inserta en la tabla hash
        	InsertarHash(&worksp,*elem);
	}
	free(elem);
}
//libera memoria de la tabla hash
void destruir_workspace(){
	DestruirTablaHash(worksp);
}
//imprime la tabla hash
void imprimir_workspace(){
    posicion p;
    tipoelem *ele = (tipoelem*)malloc(sizeof(tipoelem));
    for(int i=0; i<TamHash; i++){
        //p apunta el primero de la lista y la reccore hasta que no encuentra el final
        p = primero(worksp[i]);
        while (p != fin(worksp[i])){
            //comprueba si está vacío el nodo
            if(!esvacia(worksp[i])){
            	//si no lo está recupera el nodo
                recupera(worksp[i], p,ele);
                //comprueba si es una variable
                if(ele->compLex == 3){
                    printf("{%s --> %lf}\n",ele->lexema, ele->valor.var);
                }
            }
            //avanza
            p = siguiente(worksp[i], p);
        }
    }

    free(ele);
}
//inserta o devuelve un nodo de la tabla hash
tipoelem* insertar_workspace(char* lex){
    tipoelem *ele = (tipoelem*)malloc(sizeof(tipoelem));
    memset(ele->lexema, 0, TAM+1);

    //si ya existe un nodo con ese lexema se devuelve
    if(Busqueda(worksp, lex,ele)){
    	return ele;
    }
    //si no existe ese nodo, se inserta ese lexema como una variable sin inicializar
    else{
        ele = (tipoelem*)malloc(sizeof(tipoelem));
        //inserto como variable
        ele->compLex = 3;
        strncpy(ele->lexema, lex,(int)strlen(lex));
        //no inicializada
        ele->tiene_valor=0;
        InsertarHash(&worksp, *ele);
        return ele;
    }
}
//modifica un tipoelemento de la tabla hash
void modificar_workspace(tipoelem el){
	ModificarHash(&worksp,el);
}
//elimina el elemento lez de la tabla hash
void borrar_elemento_workspace(tipoelem lex){
    BorrarHash(&worksp, lex);
}
//cuando se llama a init si está en 1 pasa a 0 y viceversa para detectar si es hay una variable inicializada
void initial(){
	if(init==1){
		init=0;
	}
	else{
		init=1;
	}
}
//devuelve el valor de comando
int esInitial(){	
	return init;
}