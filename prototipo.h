#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "struct.h"

void Menu();
int IngOpcion(int op);
nick Ingreso_usuario(int cp);

void IngresoJugador (jugador lista[],int &cp);
void Juega_Jugador  (jugador lista[],int cp,int s[9][9]);
void ranking (jugador lista[],jugador listaaux[],int cp);
void inicializar_sudoku (int s [9][9]);

void imprimir_sudoku (int s [9][9]);
void generar_sudoku_valido (int s [9][9], int cant_elem);	
void crear_candidatos (int s [9][9], int fila, int columna, bool candidatos[9]);
bool es_candidato (int s [9][9], int num, int fila, int columna);
bool sudoku_valido (int s [9][9]);
bool sudoku_resuelto (int s [9][9]);
int solucionador(int s[9][9],int x,int y);
void menu();
int ingresoopcion();
void menu_juego(int s[9][9],jugador lista[],int &cp);
void coloco(int s[9][9],jugador lista[],int cp);
void ordenoxseleccion(jugador listaaux[], int cp);
cadena Ingreso_usuario2();
bool serepite(jugador lista[],int cp);
int serep(jugador lista[],int cp);
bool Ingreso_Jugador(jugador lista[],int cp);
int Posicion(jugador lista[],int cp);
int Ingresa(jugador lista[],int cp);

#endif
