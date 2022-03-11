#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Error.h"
/*
	 Funci�n: imprime los distintos tipos de errores
	 Valor de retorno: no tiene
*/
void print_Error(int id,char* value,int linea){
    switch(id){
        case 0:
            printf("[ERROR %d EN LINEA %d]:El valor %s es un carácter ASCII que Python no reconoce.\n",id,linea,value);
        break;
        case 1:
            printf("[ERROR %d EN LINEA %d]:El valor %s no es reconocido por el analizador léxico.\n",id,linea,value);
        break;
        case 2:
            printf("[ERROR %d EN LINEA %d]:El valor %s es un número mal formado.\n",id,linea,value);
        break;
            
    }
}