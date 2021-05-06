#include "scheduler.h"

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}
//------------------------------Hilo Reproducir musica------------------
void *r_music(void *arg){
 musica();
 return NULL;
}

void reproducir_musica(void){
	pthread_t hiloMusica;
	pthread_create(&hiloMusica, NULL, (void*)r_music, NULL);
	pthread_join(hiloMusica, NULL);
}

//------------------------------Hilo Abrir youtube------------------
void *a_youtube(void *arg){
    youtube();
    return NULL;
}

void abrir_youtube(void){
	pthread_t hiloYoutube;
	pthread_create(&hiloYoutube, NULL, (void*)a_youtube, NULL);
	pthread_join(hiloYoutube, NULL);
}

//------------------------------Hilo Escribiendo en Word------------------
void *e_word(void *arg){
   word();
   return NULL;
}

void escribir_texto_word(void){
	pthread_t hiloWord;
	pthread_create(&hiloWord, NULL, (void*)e_word, NULL);
	pthread_join(hiloWord, NULL);	
}

//------------------------------Hilo Descargando Archivo-----------------
void *d_archivo(void *arg){
   dArchivo();
   return NULL;
}

void descargar_archivo(void){
	pthread_t hiloDArchivo;
	pthread_create(&hiloDArchivo, NULL, (void*)d_archivo, NULL);
	pthread_join(hiloDArchivo, NULL);	
}

//------------------------------Hilo Subiendo Archivo------------------
void *s_archivo(void *arg){
      sArchivo();
      return NULL;
}

void subiendo_archivo(void){
	pthread_t hiloSArchivo;
	pthread_create(&hiloSArchivo, NULL, (void*)s_archivo, NULL);
	pthread_join(hiloSArchivo, NULL);	
}

//------------------------------Hilo Compilando programa------------------
void *c_programa(void *arg){
   cPrograma();
   return NULL;
}

void compilando_programa(void){
	pthread_t hiloCPrograma;
	pthread_create(&hiloCPrograma, NULL, (void*)c_programa, NULL);
	pthread_join(hiloCPrograma, NULL);	
}

//------------------------------Hilo Ejecutando programa------------------
void *e_programa(void *arg){
	ePrograma();
	return NULL;
}

void ejecutando_programa(void){
	pthread_t hiloEPrograma;
	pthread_create(&hiloEPrograma, NULL, (void*)e_programa, NULL);
	pthread_join(hiloEPrograma, NULL);	
}

//------------------------------Hilo Usando la terminal------------------
void *u_terminal(void *arg){
	terminal();
	return NULL;
}

void usando_terminal(void){
	pthread_t hiloTerminal;
	pthread_create(&hiloTerminal, NULL, (void*)u_terminal, NULL);
	pthread_join(hiloTerminal, NULL);	
}
