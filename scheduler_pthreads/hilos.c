#include "scheduler.h"

void *saludo(void *args){
    parametro *par = (parametro *)args;
    int i;
    for(i = 0; i < strlen(par->cadena); i++){
        fflush(stdout);
        printf("%c", par->cadena[i]);
        usleep(50000);
    }
    printf("\n");
    return 0;
}

int musica(){
    parametro p1;
    p1.cadena="Reproduciendo Música\n";
    pthread_create(&hilo1,NULL,saludo,(void *)&p1);
    pthread_join(hilo1,NULL);
    return 0;
}


int youtube(){
    parametro p2;
    p2.cadena="Usando Youtube\n";
    pthread_create(&hilo2,NULL,saludo,(void *)&p2);
    pthread_join(hilo2,NULL);
    return 0;
}

int word(){
    parametro p3;
    p3.cadena="Escribiendo Texto en Word\n";
    pthread_create(&hilo3,NULL,saludo,(void *)&p3);
    pthread_join(hilo3,NULL);
    return 0;
}

int dArchivo(){
    parametro p4;
    p4.cadena="Descargando Archivo\n";
    pthread_create(&hilo4,NULL,saludo,(void *)&p4);
    pthread_join(hilo4,NULL);
    return 0;
}

int sArchivo(){
    parametro p5;
    p5.cadena="Subiendo Archivo\n";
    pthread_create(&hilo5,NULL,saludo,(void *)&p5);
    pthread_join(hilo5,NULL);
    return 0;
}

int cPrograma(){
    parametro p6;
    p6.cadena="Compilando programa\n";
    pthread_create(&hilo6,NULL,saludo,(void *)&p6);
    pthread_join(hilo6,NULL);
    return 0;
}

int ePrograma(){
    parametro p7;
    p7.cadena="Ejecutando programa\n";
    pthread_create(&hilo7,NULL,saludo,(void *)&p7);
    pthread_join(hilo7,NULL);
    return 0;
}

int terminal(){
    parametro p8;
    p8.cadena="Usando la terminal\n";
    pthread_create(&hilo8,NULL,saludo,(void *)&p8);
    pthread_join(hilo8,NULL);
    return 0;
}
