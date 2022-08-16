#include<iostream>
#include <time.h>
#include "struct.h"
#include "prototipo.h"
#include <string.h>
void Menu(){ //MUESTRO MENU PRINCIPAL
	system("cls");
	printf("				[Menu principal]:\n\n\t\t\t\t1.Registrar jugador.\n\t\t\t\t2.Iniciar sesion.\n\t\t\t\t3.Ranking.\n\t\t\t\t4.Finalizar Programa.\n\n");
}
int IngOpcion(int op){ //INGRESA OPCION DEL MENU
	printf("\t\t\t\tIngrese opcion: ");
	scanf("%d",&op);
	while(op<1||op>6){
		printf("Ingrese opcion valida: ");
		scanf("%d",&op);
	}
	fflush(stdin);
	return op;
}
nick Ingreso_usuario(){ //RETORNA NICK
	int num=0;
	nick auxci;
	printf("Ingrese su nick, no debe superar los 10 caracteres: ");
	while(num<12&&(auxci.nick[num]=getchar())!='\n'){
		num++;
	}
	auxci.largo=num;
	return auxci;
}
cadena Ingreso_usuario2(){ // RETORNA NOMBRE
	int num=0;
	cadena auxci;
	printf("Ingrese su nombre, no debe superar los 15 caracteres: ");
	while(num<15&&(auxci.nombre[num]=getchar())!='\n'){
		num++;
	}
	auxci.largo=num;
	return auxci;
}
				
bool serepite(jugador lista[],int cp){ //VERIFICA SI SE REPITE EL JUGADOR EN LA LISTA
	nick aux;
	aux=Ingreso_usuario();
	for(int i=0;i<11;i++){
		if(strcmp(lista[i].letra.nick,aux.nick)==0){
		return true;
	}
	}
	lista[cp].letra=aux;
	return false;
}
int serep(jugador lista[],int cp){ //VERIFICA SI SE REPITE EL JUGADOR EN LA LISTA SIN GUERDAR RETORNANDO LA POSICION 
	nick aux;
	aux=Ingreso_usuario();
	for(int i=0;i<11;i++){
		if(strcmp(lista[i].letra.nick,aux.nick)==0){
		return i;
		}
	}
	return -1;
}

void IngresoJugador(jugador lista[],int &cp){	//REGISTRA NOMBRE Y SE VERIFICA SI EL NICK YA SE ENCUETRA REGISTRADO
	if(serepite(lista,cp)==true){
		printf("El jugador ya se encuentra en el sistema.");
	}
	else{
		lista[cp].nombre=Ingreso_usuario2();
		cp++;	
	}
}
int Ingresa(jugador lista[],int cp){ //RETORNA LA POSICION DONDE SE REPITE EL NICK EN LA LISTA
	return serep(lista,cp);
}

void Juega_Jugador (jugador lista[],int cp,int s[9][9]){ //INICIA EL MENU DE JUEGO
	void menu_juego(int s[9][9],jugador lista[],int cp);
	menu_juego(s,lista,Ingresa(lista,cp));
}
void ranking (jugador lista[],jugador listaaux[],int cp){ //MENU DE RANKING
int op=0;
do{
	system("cls");
	printf("Elija el orden en el cual desea ver a los jugadores:\n1- En el orden que fueron ingresados.\n2- Ordenada por puntos.\n3- Volver al menú principal.\n\n");
	scanf("%d",&op);
	fflush(stdin);
	switch(op){
	case 1:
		if(cp>0){
			for(int y=0;y<cp;y++){
				
				printf("\n[Datos del jugador n°%d]",y);
				printf("\nNOMBRE: ");
				
				for(int x=0;x<lista[y].nombre.largo;x++){     
					printf("%c",lista[y].nombre.nombre[x]);
				}
				printf("\tPUNTOS:%d",lista[y].puntos);
				
				printf("\nNICK: ");
				for(int x=0;x<lista[y].letra.largo;x++){
					printf("%c",lista[y].letra.nick[x]);
				}
			}
		}
		else{
			printf("No hay usuarios registrados");
		}
		break;
	case 2:
		if(cp>0){
			for(int i=0;i<cp;i++){
				listaaux[i]=lista[i];
			}
			system("cls");
			ordenoxseleccion(listaaux,cp);
		}
		else{printf("No hay usuarios registrados");}
		break;
	default:
		op=3;
		break;
	}
	if(op<3){
		printf("\n[Presione cualquier tecla para continuar]");
		getchar();
	}
}while(op<3);

}
void ordenoxseleccion(jugador listaaux[], int cp){ //ORDENO EN FUNCION DE PUNTOS
	int i,j,pos,nropos,aux;
	for(i=0;i<cp;i++)
	{
		pos=i;
		nropos=listaaux[i].puntos;
		for(j=i+1;j<cp;j++)
		{
			if (listaaux[j].puntos>=nropos)
			{
				nropos=listaaux[j].puntos;
				pos=j;
			}
		}
		//Intercambio
		aux = listaaux[pos].puntos;
		listaaux[pos].puntos=listaaux[i].puntos;
		listaaux[i].puntos=aux;
		for(int k=0;k<listaaux[i].letra.largo;k++){
			aux = listaaux[pos].letra.nick[k];
			listaaux[pos].letra.nick[k]=listaaux[i].letra.nick[k];;
			listaaux[i].letra.nick[k]=aux;
		}
		
		for(int k=0;k<listaaux[i].nombre.largo;k++){
			aux = listaaux[pos].nombre.nombre[k];
			listaaux[pos].nombre.nombre[k]=listaaux[i].nombre.nombre[k];;
			listaaux[i].nombre.nombre[k]=aux;
		}
		
	}
	for(int y=0;y<cp;y++){
		
		printf("\n[Datos del jugador n°%d]",y);
		printf("\nNOMBRE: ");
		
		for(int x=0;x<listaaux[y].nombre.largo;x++){     
			printf("%c",listaaux[y].nombre.nombre[x]);
		}
		printf("\tPUNTOS:%d",listaaux[y].puntos);
		
		printf("\nNICK: ");
		for(int x=0;x<listaaux[y].letra.largo;x++){
			printf("%c",listaaux[y].letra.nick[x]);
		}
		
		
	}
	
	
}
	
