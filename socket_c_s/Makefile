all:
	gcc -g -c -Wall cliente.c -o cliente.o
	gcc -g -c -Wall servidor.c -o servidor.o
	gcc -g -Wall cliente.o servidor.o -o application

clean:
	rm *.o
	rm application
