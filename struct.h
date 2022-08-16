#ifndef STRUCT_H
#define STRUCT_H

typedef struct{
	char nick[10];
	int largo;
}nick;

typedef struct{
	char nombre[15];
	int largo;
}cadena;

typedef struct{
	nick letra;
	cadena nombre;
	int puntos;
	char estado;
}jugador;



#endif
