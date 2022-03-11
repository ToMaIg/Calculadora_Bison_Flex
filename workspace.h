#include "lista.h"
#include "comandos.h"
//crea la tabla hash y la inicializa con las constantes, funciones y comandos
void inicializar_workspace();
//libera memoria de la tabla hash
void destruir_workspace();
//imprime la tabla hash
void imprimir_workspace();
//devuelve un nodo con el lexema lex o inserta lex como una variable sin inicializar
tipoelem* insertar_workspace(char* lex);
//modifica el workspace para que si existe un nodo con el mixmo lecema que tipoelem apunte hacia el.
void modificar_workspace(tipoelem el);
//elimina el elemento lex de la tabla hash
void borrar_elemento_workspace(tipoelem lex);
//cuando se llama a init si está en 1 pasa a 0 y viceversa para detectar si es hay una variable inicializada
void initial();
//devuelve el valor de comando
int esInitial();
