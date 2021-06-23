#include "headers.h"
//Función principal
int main(int argc, char **argv)
{
	if(argc > 1)
	{
		//Primer paso, definir variables
		int fd,fd2,longitud_cliente,puerto;
		puerto=atoi(argv[1]);

		//Se necesitan dos estructuras del tipo sockaddr
		//La primera guarda info del server
		//La segunda del cliente
 		struct sockaddr_in server;
 		struct sockaddr_in client;

		//Configuracion del servidor
 		server.sin_family= AF_INET; //Familia TCP/IP
 		server.sin_port = htons(puerto); //Puerto
 		server.sin_addr.s_addr = INADDR_ANY; //Cualquier cliente puede conectarse
 		bzero(&(server.sin_zero),8); //Funcion que rellena con 0's

 		//Paso 2, definicion de socket
 		if (( fd=socket(AF_INET,SOCK_STREAM,0) )<0){
 			perror("Error de apertura de socket");
 			exit(-1);
 		}

 		//Paso 3, avisar al sistema que se creo un socket
 		if(bind(fd,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1) {
 			printf("error en bind() \n");
		 	exit(-1);
 		}

 		//Paso 4, establecer el socket en modo escucha
		if(listen(fd,5) == -1) {
 			printf("error en listen()\n");
 			exit(-1);
 		}
 		else{
 			printf("*******************************************************************\n");
 			printf("             El servidor esta esperando peticion\n");
 			printf("*******************************************************************\n");
 		}

 		//Paso5, aceptar conexiones
 		longitud_cliente= sizeof(struct sockaddr_in);
 		/* A continuación la llamada a accept() */
 		fd2 = accept(fd,(struct sockaddr *)&client,&longitud_cliente);
 		if (fd2 < 0) {
			printf("El servidor NO acepto la peticion...\n");
			exit(0);
		}
		else
			printf("-------->El servidor ha ACEPTADO la peticion <--------\n\n");
 
		
 	set_resultado(fd2);
	close(fd);
	}
	else{
		printf("NO se ingreso el puerto por parametro\n");
	}

return 0;

}

//Función para hacer la suma y mostrar el resultado
void set_resultado(int conexion)
{
	read(conexion, cnum1, sizeof(cnum1));
	long1 = strlen(cnum1);
	char num1[long1];
	strcpy(num1, cnum1);

	read(conexion, cnum2, sizeof(cnum2));
	long2 = strlen(cnum2);
	char num2[long2];
	strcpy(num2, cnum2);

	int longest_num;

	if(long1 >= long2){

		longest_num = long1+1;
	}else{
		strcpy(auxCorden, num1);
		strcpy(num1, num2);
		strcpy(num2,auxCorden);
		long1 = strlen(num1);
		long2 = strlen(num2);
		longest_num = long2+1;
	}

	printf("\n -----> SUMANDO....");
	int acarreo = 0;
	int aux, auxNum1, auxNum2;
	int j = long2 - 1;
	if(long1 >= long2){
		for(int i = long1 - 1; i >= 0; i--){
			auxNum1 = (num1[i]) - '0';
			if (j >= 0){
				auxNum2 = (num2[j]) - '0';
				j--;
			} else {
				auxNum2 = 0;
			}
			aux = auxNum1 + auxNum2 + acarreo;

			if (aux >= 10){
				resultado[i+1] = (aux - 10)+'0';

				acarreo = 1;
			} else {
				resultado[i+1] = (aux)+'0';
				acarreo = 0;
			}
		}
	}
		
	if(resultado[0] = '0'){

		for(int i=0; i<longest_num;i++){

			resultado[i] = resultado[i+1];
		}
	}	

	printf("\nResultado obtenido: %s\n", resultado);

	write(conexion, resultado, sizeof(resultado));
	printf("\n-------------------------------------------------------------------\n");
	printf("                 RESPUESTA ENVIADA AL CLIENTE\n");
	printf("-------------------------------------------------------------------\n");
}

