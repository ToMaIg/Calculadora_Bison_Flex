//imprime la ayuda
void help();
//imprimo las variables del workspace
void workspace();
//destruyo y vuelvo a crear el workspace
void clean();
//elimino la variable de la tabla hash
void cleanVariable(char *var);
//destruyo el workspace 
void quit();
//lee el fichero "archivo" yyin pasa leer
void load(char *nombre_archivo);
//cuando se llama a echo si está en 1 pasa a 0 y viceversa
void echo();
//devuelve el valor de echo
int esEcho();
//cuando se llama a comando si está en 1 pasa a 0 y viceversa
void comando();
//devuelve el valor de comando o error
int esComando();