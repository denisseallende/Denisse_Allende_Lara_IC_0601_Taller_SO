#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STRING				100
#define MAX_PROCESOS			100

#define UN_SEGUNDO				1
#define DOS_SEGUNDOS			2
#define TRES_SEGUNDOS			3
#define CUATRO_SEGUNDOS			4
#define VEINTIDOS_SEGUNDOS            22
	
#define ACTIVO 					1
#define NO_ACTIVO				0

int cont_procesos;

typedef struct PROCESS process;
typedef struct ARRAY_PROCESS array_procesos;

/* Puntero a función que no retorna y no recibe nada. */
typedef void (*FN_ACCION)(void); 

// Definición de la estructura PROCESS
struct PROCESS{
	int id;
	int delay;
	char nombrePROCESO[MAX_STRING];
	FN_ACCION proceso_realizar;
	int estado;
};

struct ARRAY_PROCESS{
	process proceso;
	int empty;
};

process *crear_Proceso(int _id, int _delay, char *_nombreProceso, FN_ACCION _proceso_realizar, int _estado);
void agregar_Proceso(array_procesos *_array, process _p);
void ejecutar_Procesos(array_procesos *_array);
array_procesos *crear_ArrayProcesos(void);

//-----------------------------Datos para los hilos------------------------------------
pthread_t hilo1, hilo2, hilo3, hilo4, hilo5, hilo6, hilo7, hilo8;

typedef struct dato{
    char *cadena;
}parametro;

int musica();
int youtube();
int word();
int dArchivo();
int sArchivo();
int cPrograma();
int ePrograma();
int terminal();

#endif
