#include <stdio.h>
#include <stdlib.h>

int ejercicio1();
int x=10;
int *p =&x;
int y=20;
int *puntero=&y;

int ejercicio2();
int i;
int arrayInt[5];
int *punteroInt;
int *punteroIntDos;

int main(int argc, char const *argv[]){
	ejercicio1();
	ejercicio2();
	return 0;
}

int ejercicio1(){
	printf("->El contenido del puntero 'P' es: %i \n",*p);
	*p=*p+1;
	printf("->El contenido del puntero 'P+1' es: %i \n", *p);
	*p=*p+2;
	printf("->El contenido del puntero '(P+1)+2' es: %i \n", *p);
	printf("->El contenido del puntero 'puntero' es: %i \n", *puntero);
	return 0;
}

int ejercicio2(){
	
	for (i=0; i<5; i++){
	 	arrayInt[i]=i;
	}
	
	punteroInt=&arrayInt[0];
	punteroIntDos=&arrayInt[0];
	punteroIntDos+=0;
	
	printf("\n El contenido del primer elemento array 'arrayInt' es: %i \n", arrayInt[0]);
	printf(" El contenido del primer elemento del puntero 'punteroInt' es: %i \n", *(punteroInt+0));
	printf(" El contenido del primer elemento del 'punteroIntDos' es: %i \n", punteroIntDos[0]);
	
	printf(" El contenido del quinto elemento 'arrayInt' es: %i \n", arrayInt[4]);
	printf(" El contenido del quinto elemento 'punteroInt' es: %i \n", *(punteroInt+4));
	printf(" El contenido del quinto elemento 'punteroIntDos' es: %i \n", *(punteroIntDos+4));
	printf(" -------Contenido del todos los elementos del puntero 'punteroInt'-------");
	for (i=0; i<5; i++){
		printf("\n punteroInt[%i]-> %i",i,*(punteroInt+i));
	}
	printf("\n");
	printf(" -------Contenido del todos los elementos del puntero 'punteroIntDos'-------");
	for (i=0; i<5; i++){
		printf("\n punteroIntDos[%i]-> %i",i,*(punteroIntDos+i));
	}
	printf("\n");
	return 0;
}
