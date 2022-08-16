#include<iostream>
#include "prototipo.h"
#include "struct.h"
using namespace std;


int main (int argc, char *argv[]) {  //INCICALIZO VARIABLES
	int cp=0,op=0; 
	int s[9][9];
	jugador lista[10]; 
	jugador listaaux[10];
	
	for(int i=0;i<10;i++){
		lista[i].puntos=0;
		for(int x=0;x<15;x++){
		lista[i].nombre.nombre[x]=' ';
		}
	}
	do{
		system("cls");
		Menu();
		op=IngOpcion(op);
		switch(op){
		case 1: //RegistroJugador
			system("cls");
			if(cp>9){
				printf("Limite de jugadores alcanzado.");
			}
			else{
				IngresoJugador (lista,cp);
			}
			break;
		case 2: //Inicia sesion y juega
			system("cls");
			Juega_Jugador (lista,cp,s);
			break;
		case 3: //Ranking de jugadores
			system("cls");
			ranking (lista,listaaux,cp);
			break;
		default: //Fin
			op=4;
			break;
		}
		if(op<4){
			printf("\n[presione cualquier tecla para continuar]");
			getchar();
		}
	}while(op<4);
	
	return 0;
}
