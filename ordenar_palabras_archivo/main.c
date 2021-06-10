#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_NOMBRE 100
#define TAM_ARCHIVO 5

FILE *abrir_Archivo_Entrada(char *nom_archivo);
int tiene_datos_arch(char *archivo_entrada);
void cerrar_archivo(FILE *ptrArchivo, char *archivo_entrada);
void vaciar (char temp[]);
void copiar(char temp[], int i);
char mostrar_Datos(char *archivo_entrada);
void ordenar_Datos (char *vector_original);
int contar_palabras(char *archivo_entrada, int i);
int palabras_totales;
char vectorPrincipal;


int main(int argc, char *argv[]){
	char *nom_archivo_entrada;
	char *nom_archivo_salida;
	int comprobar=0;
	
	printf("\n\t  ---------------> ARCHIVOS USADOS <-------------- \n");
	for (int i=0; i < argc; i++){
		if(i==1){
			nom_archivo_entrada=argv[i];
			printf(" El archivo de entrada --> %s",nom_archivo_entrada);
		}
		if(i==2){
			nom_archivo_salida=argv[i];
			printf("\n El archivo de salida --> %s \n",nom_archivo_salida);
		}
	}
	
	printf("\n\n\t  ---------------> ABRIR ARCHIVO [ENTRADA] <-------------- \n");
	abrir_Archivo_Entrada(nom_archivo_entrada);
	printf("\n\t  ---------------> COMPROBAR QUE TENGA DATOS <-------------- \n");
	comprobar=tiene_datos_arch(nom_archivo_entrada);
	
	if(comprobar==1){
	printf("\n\n\t  ---------------> IMPRIMIR EL CONTENIDO DEL ARCHIVO [ENTRADA] <-------------- \n");
		vectorPrincipal=mostrar_Datos(nom_archivo_entrada);
	}
	palabras_totales=contar_palabras(nom_archivo_entrada,0);
	printf("\n Palabras --> %i \n",palabras_totales);
}

FILE *abrir_Archivo_Entrada(char *archivo_entrada){
	FILE *ptrArchivo;
	ptrArchivo = fopen(archivo_entrada, "r");
	if( ptrArchivo == NULL ){
		printf("---> El archivo -> %s <- NO pudo abrirse. \n", archivo_entrada);
	}	
	else{
		printf("---> Archivo -> %s <- Abierto.\n", archivo_entrada);
	}
	return ptrArchivo;
}

int tiene_datos_arch(char *archivo_entrada){
	int hay_Datos = 0;
	FILE *ptrArchivo;
	int lee_linea = 0, contador = 0;
	ptrArchivo = abrir_Archivo_Entrada(archivo_entrada);
	if(ptrArchivo == NULL){
		printf("El archivo -> %s <- NO se pudo abrir desde tiene_datos_arch. \n", archivo_entrada);			
		hay_Datos = 0;
	}
	else{
		// leo si hay datos
		fscanf(ptrArchivo, "%d", &lee_linea);
		// mientras no sea fin de archivo.
		while(!feof(ptrArchivo)){
			contador++;
			// leo si hay datos
			fscanf(ptrArchivo, "%d", &lee_linea);
			if(contador > 0){
				printf("\n El archivo contiene datos \n");
				hay_Datos = 1;
				break;
			}
		}
		if (hay_Datos==0){
				printf("El archivo NO contiene datos. Se recomienda crear uno nuevo \n");
		}
		cerrar_archivo(ptrArchivo, archivo_entrada);
	}	
	return hay_Datos;
}



void cerrar_archivo(FILE *ptrArchivo, char *archivo_entrada){
	fclose(ptrArchivo);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", archivo_entrada);
}

//---------------------------------MOSTRAR DATOS-------------------------------

//-----ESTRUCTURA-----
typedef struct{

	char *palabra;
}arreglo;

arreglo *arr;

char mostrar_Datos(char *archivo_entrada){
	int cont = 0;
	char temp[1000];
	int aux='0';
	int i;
	char *vector;
	
	
	FILE *f;
	f=fopen(archivo_entrada,"r");
	if (f==NULL){
		printf("\n No se puedo abrir el archivo desde mostrar_Datos");
	}
	
	while (!feof(f)){
		fgets(temp,1000,f);
		cont++;
	}
	rewind(f);
	
	arr = (arreglo*)malloc(cont*sizeof(arreglo));
	if(arr==NULL){
		printf("\n No se pudo reservar la memoria");
	}
	for (i=0; !feof(f); i++){
		//vaciar(temp);
		for(int j=0; aux!=' '; j++){
			aux = fgetc(f);
			if (aux!=' '){
				temp[j]=aux;
			}			
		}
		copiar(temp,i);
		if(i==0){
			vector=(arr[i].palabra);
			printf("\n Palabra--> %s",vector);
		}
	//cerrar_archivo(f, archivo_entrada);
	}
	
	return *vector;
}


void vaciar (char temp[]){ //Vaciar la cadena de caracteres
	int i;
	for (i=0; i<1000; i++){
		temp[i] ='\0';
	}
}

void copiar(char temp[], int i){
	int N = strlen(temp)+1;
	arr[i].palabra=(char*)malloc(N*sizeof(char));
	if(arr==NULL){
		printf("\n No se pudo reservar la memoria");
	}
	strcpy(arr[i].palabra,temp);
}

int contar_palabras(char *archivo_entrada, int i){
	char frase[i];
	frase[i]=mostrar_Datos(archivo_entrada);
	int total=0;
	while(frase[i]==' '){
		total=total+1;
	}
	
	return total;
}

void ordenar_Datos (char *vector_original){
	
}

