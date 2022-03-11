#include "hash_encadenamiento.h"

// Función para inicializar la tabla Hash
void InicializarTablaHash (TablaHash t) {
    int i=0;
    while(i<TamHash){ // Mientras no se supere el tamaño de la tabla hash creamos listas para alojar los elementos
        crea(&t[i]);
        i++;
    }
}

// Función para destruir la tabla hash
void DestruirTablaHash (TablaHash t){ // Mientras no se supere el tamaño de la tabla hash destruimos las listas que se crearon para alojar los elementos
    int i=0;
    while(i<TamHash){
        destruye(&t[i]);
        i++;
    }
}

// Función Hash que utiliza un número primo para calcularse y asi disminuir el posibke número de colisiones
 int Hash (char *cad){
    int i=strlen(cad),hash=0;
    while(i>=0){
        hash = ((primo * hash + cad[i]) % TamHash);
        i--;
    }

    return hash;
 }
 
//Busca un elemento en la tabla por la clave hash y mete el valor de ese elemento en el puntero e
int Busqueda(TablaHash t, char *clave, tipoelem *e){
    posicion p;
    int enc;
    tipoelem ele;
    int pos=Hash(clave); // Obtenemos la posición de la lista en la que estará el elemento hasheando la clave
    p=primero(t[pos]); // Obtenemos el primer elemento de esa lista
    enc=0;
    while (p!=fin(t[pos]) && !enc) { // Mientras no se acaba la lista ni se encuentra el elemento
        recupera(t[pos],p,&ele); // Recuperamos el elemento de esa posición
        if (strcmp(ele.lexema,clave)==0){ // Comprobamos si es el que buscamos
            enc=1;
            *e=ele;
        }
        else{
            p=siguiente(t[pos],p); // Pasamos al siguiente elemento
        }
    }
    return enc;
}

// Función para comprobar si la cadena ya está insertada en la tabla hash
int MiembroHashClave(TablaHash t, char * clave){
    posicion p;
    int enc;
    tipoelem elemclave;
    int pos=Hash(clave); // Obtenemos la posición de la lista en la que estará el elemento hasheando la clave
    p=primero(t[pos]); // Obtenemos el primer elemento de esa lista
    enc=0;

    while (p!=fin(t[pos]) && !enc){ // Mientras no se acaba la lista ni se encuentra el elemento
        recupera(t[pos],p,&elemclave); // Recuperamos el elemento de esa posición
        if(strcmp(clave,elemclave.lexema)==0){ // Comprobamos si la cadena esta  en el elemento que comparamos
            enc=1;
         }
        else{
             p=siguiente(t[pos],p); // Pasamos al siguiente elemento
        }
    }
    return enc;
}

// Función para comprobar si el elemento es miembro de la tabla hash
int MiembroHash(TablaHash t, tipoelem e){
    posicion p;
    int enc;
    tipoelem elemclave;
    int pos=Hash(e.lexema); // Obtenemos la posición de la lista en la que estará el elemento hasheando la clave
    p=primero(t[pos]); // Obtenemos el primer elemento de esa lista
    enc=0;

    while (p!=fin(t[pos]) && !enc){ // Mientras no se acaba la lista ni se encuentra el elemento
        recupera(t[pos],p,&elemclave);  // Recuperamos el elemento de esa posición
        if(strcmp(e.lexema,elemclave.lexema)==0 && e.compLex==elemclave.compLex){ // Comprobamos si el elemento que comparamos es el mismo que el que tenemos
            enc=1;
         }
        else{
             p=siguiente(t[pos],p); // Pasamos al siguiente elemento
        }
    }
   return enc;
}
// Función para insertar en la tabla
void InsertarHash (TablaHash *t, tipoelem e){
    int pos;
    pos=Hash(e.lexema); // Calculamos la posición de la tabla hash en la que se insertará
    if (MiembroHash(*t,e)){ // Comprobamos si ya es miembro
    	return;
    }
    else{
    	inserta(&(*t)[pos],primero((*t)[pos]),e); // Insertamos el elemento en la lista que está en la posición anterior
    }
}

// Funcion para borrar en la tabla
void BorrarHash (TablaHash *t, tipoelem elemento){
    posicion p;
    tipoelem elemclave;
    int pos=Hash(elemento.lexema); // Calculamos la posición del elemento en la tabla hash

    p=primero((*t)[pos]); // Obtenemos el primer elemento de esa lista
    recupera((*t)[pos],p,&elemclave); // Obtenemos el elemento correspondiente
    while (p!=fin((*t)[pos]) && strcmp(elemento.lexema,elemclave.lexema)!=0 && (elemento.compLex!=elemclave.compLex)){ // Mientras no lleguemos al final de la lista ni el elemento sea el que buscamos
        p=siguiente((*t)[pos],p); // Obtenemos el siguiente elemento
        recupera((*t)[pos],p,&elemclave); // Obtenemos el elemento correspondiente
    }
    if (p!=fin((*t)[pos])){ // Si no llegamos al elemento final de la lista en la que estamos buscando
        suprime(&(*t)[pos],p); // Eliminamos el elemento
    }
}

//funcion para modificar la tabla
void ModificarHash(TablaHash *t,tipoelem elemento){
	posicion p;
	int enc=0;
        tipoelem elemclave;
    	int pos=Hash(elemento.lexema); // Calculamos la posición del elemento en la tabla hash

   	p=primero((*t)[pos]); // Obtenemos el primer elemento de esa lista
    	while(p!=fin((*t)[pos])&&enc==0){
    		recupera((*t)[pos],p,&elemclave); // Obtenemos el elemento correspondiente
    		if(strcmp(elemento.lexema,elemclave.lexema)==0){//comparamos para ver si es el mismo lexema
    			modifica(t[pos],p,elemento);
    			enc=1;
    		}
    		else{
    		 	p=siguiente((*t)[pos],p);//obtenermos el siguiente elemento
    		}
    	}
	
}