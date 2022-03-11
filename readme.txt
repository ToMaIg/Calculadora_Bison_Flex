Sistema Operativo:
Distributor ID: Kali
Description:    Kali GNU/Linux Rolling
Release:        2021.2

Compilador:
gcc (Debian 10.2.1-6) 10.2.1 20210110

Flex:
flex 2.6.4

Bison:
bison 3.8.2

Procedimiento para compilar:
1-flex Lexico.l
2-bison Sintactico.y -d
2- gcc *.c -Wall -lm
3- ./a.out