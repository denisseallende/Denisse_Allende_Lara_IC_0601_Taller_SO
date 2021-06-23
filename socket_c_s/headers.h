#ifndef __HEADERS_H
#define __HEADERS_H

// Ficheros de cabecera
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
//netbd.h es necesitada por la estructura hostent

void get_datos(int conexion);

long long1;
long long2;
char cnum1[100000];
char cnum2[100000];
char resultado[100000];
char auxCorden[100000];

void set_resultado(int conexion);

#endif
