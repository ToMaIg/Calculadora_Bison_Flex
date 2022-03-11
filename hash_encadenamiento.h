#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TamHash 503 // Número de entradas de la tabla Hash, primo para cuando se recoloque no entre en un bucle infinito
#define primo 89 // Número primo empleado para la funcion hash

#pragma once

typedef lista TablaHash[TamHash];

// Función para inicializar la tabla hash
void InicializarTablaHash (TablaHash t);

// Función para destruuitar la tabla hash
void DestruirTablaHash (TablaHash t);

// Función para realizar la función hash sobre una cadena
int Hash (char *cad);

// Función para buscar un elemento en la tabla hash que lo devuelve en el puntero de tipoelem si existe, sino ese puntero será NULL
int Busqueda(TablaHash t, char *clave, tipoelem *e);

// Función para comprobar si el elemento pertenece a la tabla hash
int MiembroHash (TablaHash t, tipoelem e);

// Función para comprobar si la cadena pertenece a la tabla hash
int MiembroHashClave(TablaHash t, char * clave);

// Función para insertar en la tabla hash un elemento
void InsertarHash (TablaHash *t, tipoelem elemento);

// Función para borrar de la tabla hash un elemento
void BorrarHash (TablaHash *t, tipoelem elemento);

//funcion para modificar la tabla
void ModificarHash(TablaHash *t,tipoelem elemento);