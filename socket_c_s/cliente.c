#include "headers.h"
//Función principal
int main(int argc, char *argv[])
{
	if(argc > 2)
	{
 		//Primer paso, definir variables
 		char *ip;
 		int fd, numbytes,puerto;
 		char buf[100];
 		puerto=atoi(argv[2]);
 		ip=argv[1];

		struct hostent *he;
 		/* estructura que recibirá información sobre el nodo remoto */
 		struct sockaddr_in server;
 		/* información sobre la dirección del servidor */

		if ((he=gethostbyname(ip))==NULL){
 			/* llamada a gethostbyname() */
 			printf("gethostbyname() error\n");
 			exit(-1);
 		}

		//Paso 2, definicion de socket
 		if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
 			/* llamada a socket() */
 			printf("socket() error\n");
 			exit(-1);
 		}
		//Datos del servidor
 		server.sin_family = AF_INET;
 		server.sin_port = htons(puerto);
 		server.sin_addr = *((struct in_addr *)he->h_addr);
 		/*he->h_addr pasa la información de ``*he'' a "h_addr" */
 		bzero(&(server.sin_zero),8);

 		//Paso 3, conectarnos al servidor
 		if(connect(fd, (struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
 			/* llamada a connect() */
 			printf("connect() error\n");
 			exit(-1);
 		}

		get_datos(fd);
		close(fd);
	}
	else{
		printf("No se ingreso el ip y puerto por parametro\n");
	}

}

//Función para pedir los datos y mostrar el resultado
void get_datos(int conexion)
{
	char buff[1000];
	char n1[1000];
	char n2[1000];
	char r[1000];

	bzero(buff, sizeof(buff));
	bzero(r,sizeof(r));
	bzero(n1, sizeof(n1));
	bzero(n2,sizeof(n2));


	printf("--->Ingrese el primer numero: ");
	scanf("%s", n1);

	write(conexion, n1, sizeof(n1));
	
	printf("--->Ingrese el segundo numero: ");
	scanf("%s", n2);

	write(conexion, n2, sizeof(n2));
	

	bzero(buff, sizeof(buff));
	bzero(r,sizeof(r));

	read(conexion, buff, sizeof(buff));
	strcpy(r,buff);
	printf("\t--->El resultado es: %s\n", r);
}

