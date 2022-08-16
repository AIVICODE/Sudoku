#include<iostream>
#include <time.h>
#include "struct.h"
#include "prototipo.h"

void inicializar_sudoku (int s [9][9]){ //coloco ceros(0) en toda la matriz
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){ 
			s[i][j]=0;
		}
	}
}
void imprimir_sudoku (int s [9][9]){ //recorre la matriz mostrando su contenido.
	printf("               	  	---0---1---2---3---4---5---6---7---8--              \n");
	for(int i=0;i<9;i++){  
		printf("\t\t        %d|",i);
		for(int j=0;j<9;j++){
		printf(" %d |",s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void generar_sudoku_valido (int s [9][9], int cant_elem){
	inicializar_sudoku(s);
	srand(time(NULL));
	void generocandidatos(int s[9][9]);
	bool sudoku_valido (int s [9][9]);
	void crear_candidatos (int s [9][9], int fila, int columna, bool candidatos[9]);
	bool es_candidato (int s [9][9], int num, int fila, int columna);
	int solucionador(int s[9][9],int x,int y);

	int elem=0;
	elem = 81-cant_elem;
	int cant=0;
	int i=0;
	for(int j=0;j<9;j++){
		int num;
		if(s[i][j]==0){
			bool candidatos[9]={0};
			crear_candidatos(s,i,j,candidatos);
			int numprob[9]={0};
			cant=0;
			
			for(int k=0;k<9;k++){
				
				if(candidatos[k]){
					
					num=k+1;
					numprob[k]=num;
					
					cant++;
				}
				
			}
			int ran=rand()%cant;
			
			s[i][j]=numprob[ran];
			if(s[i][j]==0){
				s[i][j]=num;
			}
		}
	}
	
	solucionador(s,0,0);
	
	int cont=0;
	do{
		int randf=0;
		int randj=0;
		
		for(int i=0;i<9;i++){
			randf=rand()%9;
			randj=rand()%9;
		}
		int num=0;
		if(s[randf][randj]!=0){
			s[randf][randj]=num;
			cont++;
			
		}
	}
	while(cont<elem);
	
}
int solucionador(int s[9][9],int i,int j){
bool es_candidato (int s [9][9], int num, int fila, int columna);
bool sudoku_resuelto (int s [9][9]);
int num=1;
int auxx=0; //variable auxiliar
int auxy=0; // variable auxiliar

if(s[i][j]!=0){
	if(sudoku_resuelto(s)){ // lleno todos los valores incluso el ultimo
		return 1;
	}
	
	if(i<8){ // Si columna =8, vuelve a la posicion 0 y aumenta la fila de modo que recorre la matriz
		i++;
	}else{
		if(j<8){ // 
			i=0;
			j++;
		}
	}
	
	if(solucionador(s,i,j)){
		return 1;				// para control en posterior llamada en *##
	}else{
		return 0;
	}
}

if(s[i][j]==0){  // verifica que el lugar se encuentre vacio.
	while(num<10){
		if(es_candidato(s,num,i,j)){ // llama a la funcion candidato la cual verifica las 3 primeras reglas.
			s[i][j]=num; // prueba numero
			
			if(i==8&&j==8){ // si llega al final de la fila y la columna significa que termino de reciclar candidatos.
				return 1;
			}
			
			if(i<8){
				auxx=i+1; // uso variable auxiliar para deja la original en la funcion.
			}else{
				if(j<8){ 
					auxx=0;//  ya que x llego al maximo en la columna la vuelvo a llevar al principio
					auxy=j+1; // asigno auxiliar para luego pasar a la siguiente llamada ##;
				}
			}
			
			if(solucionador(s,auxx,auxy)){ // *##- ## le paso los valores auxiliares probando en la siguiente casilla
				return 1;
			}
		}
		num++; // aumento posible
	}
	s[i][j]=0;
	return 0;
	
}
return 0;
}


void crear_candidatos (int s [9][9], int fila, int columna, bool candidatos[9]){ //Guardo true en el arreglo si la posicion del mismo corresponde a un numero valido para esa celda de la matriz
 bool es_candidato (int s [9][9], int num, int fila, int columna);
	
	for(int i=0;i<9;i++){
		if(es_candidato(s,i+1,fila,columna)==true){ 
			candidatos[i]=true;
		}
		
	}
	
}
	
bool es_candidato (int s [9][9], int num, int fila, int columna){
	int i;
	for(i=0;i<9;i++){				
		if(num==s[fila][i]){ // verifico que no exista en fila
			return false;
		}
		if(num==s[i][columna]){ // verifico que no exista en columna
			return false;
		}
	}
	
	int filacuadrante= fila/3;                    // verifico que no exista en el cuadrante
	int columnacuadrante= columna/3;
	int j;
	for(i=(filacuadrante*3);i<(filacuadrante*3+3);i++){
		for(j=(columnacuadrante*3);j<(columnacuadrante*3+3);j++){
			if(num==s[i][j]){
				return false;
			}
		}
	}
	return true;
}	
bool sudoku_valido (int s [9][9]){ // Verifico si el tablero cumple con las caracteristicas de un sudoku
	int num;
	for(int fila=0;fila<9;fila++){
		for(int columna=0;columna<9;columna++){ 
			if(s[fila][columna]!=0){
				num=s[fila][columna]; 
				s[fila][columna]=0;
				if(es_candidato(s,num,fila,columna )==false){
					return false;
				}
				s[fila][columna]=num;
			}
			
		}
	}
	return true;
}
bool sudoku_resuelto (int s [9][9]){ // Verifica si el sudoku se encuentra con todas sus casillas ocupadas por num!=0.
	for(int fila=0;fila<9;fila++){
		for(int columna=0;columna<9;columna++){ 
			if(s[fila][columna]==0){
			return false;
			}
		}
	}
	return true;
}
				
				
void coloco(int s[9][9],jugador lista[],int cp){
	int t[9][9];
	inicializar_sudoku(t);
	int rendirse;
	int reinicio;
	int fila=-1;
	int columna=-1;
	int num=-1;
	int cont=0;
					
	do{
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				t[i][j]=s[i][j];
				if(s[i][j]==0){
					cont++;
				}
			}
		}
		
		do{
			system("cls");
			imprimir_sudoku(t);
			printf("\n Para jugar presione cualquier numero, para rendirse 0: "); 
			scanf("%d",&rendirse);
			if(rendirse == 0){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						t[i][j]=s[i][j];
					}
				}
				solucionador(t,0,0);
				system("cls");
				imprimir_sudoku(t);
			}
			else{
				printf("\ningrese fila del 0 al 8:"); 
				scanf("%d",&fila);
				
				printf("\ningrese columna del 0 al 8:");
				scanf("%d",&columna);
				printf("\ningrese numero del 1 al 9:");
				scanf("%d",&num);
				system("cls");
				if(t[fila][columna]!=0){
					printf("Casilla ocupada intentelo nuevamente");
				}else{
					t[fila][columna]=num;
				}	imprimir_sudoku(t);
				printf("\n Presione 0 para reiniciar sudoku: "); 
				scanf("%d",&reinicio);
				if(reinicio == 0){
					system("cls");
					for(int i=0;i<9;i++){
						for(int j=0;j<9;j++){
							t[i][j]=s[i][j];
						}
					}
				}
			}
		}while(sudoku_resuelto(t)==false);
		if(sudoku_valido(t)==false){
			printf("No lo logro intentelo nuevamente");
		}
	}while(sudoku_valido(t)==false);
	if(rendirse==0){
		printf("SE RINDE  +0 PS");
	}else{
		printf("LO LOGRASTEEE!");
		printf("\n +%dPS",cont);
		lista[cp].puntos=lista[cp].puntos+cont;
		
	}
}
int ingresoopcion(){
	int op;
	scanf("%d",&op);
	fflush(stdin);
	return op;
}
void menu_juego(int s[9][9],jugador lista[],int cp){
	if(cp>-1){
		system("cls");
		int op;
		do{
			printf("\n-------Ingrese dificultad-------");
			printf("\nN1:MUY FACIL ");
			printf("\nN2:FACIL");
			printf("\nN3:NORMAL");
			printf("\nN4:DIFICIL");
			printf("\nN5:MUY DIFICIL");
			printf("\nN6:EXTREMO");
			printf("\nN7:SALIR");
			printf("\n ingrese opcion:");
			op=ingresoopcion();
			system("cls");
			switch(op){
			case 1:
				generar_sudoku_valido(s,70);
				coloco(s,lista,cp);
				
				
				break;
			case 2:
				
				generar_sudoku_valido(s,60);
				coloco(s,lista,cp);
				
				break;
			case 3:
				generar_sudoku_valido(s,50);
				coloco(s,lista,cp);
				
				break;
			case 4:
				generar_sudoku_valido(s,35);
				coloco(s,lista,cp);
				
				break;
				
			case 5: 
				generar_sudoku_valido(s,30);
				coloco(s,lista,cp);
				break;
				
			case 6: 
				generar_sudoku_valido(s,25);
				coloco(s,lista,cp);
				break;
			}
			
		}while(op!=7);
	}
	else{
		
		printf("El jugador no se encuentra registrado");
	}
}
