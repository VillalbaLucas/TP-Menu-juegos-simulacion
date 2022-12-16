#include "puntosTablero.h"
#include "iostream"
#include "menu.h"
using namespace std;

void tableroMostrar(char tablero[][MAXIMO], int fila, int columna){
	
	for(int i=0; i<fila; i++){
		int aux=0;
		for(int j=0; j<columna; j++){
			if(!acierto(tablero, i, j) and i == 9){
				gotoxy(aux,i);
				cout << "_";
			}	
			else if(!acierto(tablero, i, j) and i < 9){
			   gotoxy(aux,i);
				cout << ".";
			}
			else{
				gotoxy(aux,i);
				cout << tablero[i][j];
			}
			aux+=3;	
		}
	}
}

void mostrarTablero1(char tablero2[][MAXIMO]){
	/*
	char ave = '^';
	char piedra = 'X';
	*/
	
	
	for(int i=0; i<10; i++){
		int aux=0;
		for(int j=0; j<MAXIMO; j++){
			
			gotoxy(aux, i);
			cout<<tablero2[i][j];
			
			aux+=3;
		}
	}
	/*else if(y<=9 and y>=7){
		for(int i=0; i<10; i++){
			int aux=0;
			for(int j=0; j<MAXIMO; j++){
				if(i=9){
					gotoxy(aux, i);
					cout<<'.';
				}else {
					gotoxy(aux, i);
					cout<<'_';
				}
				aux+=3;
			}
		}
	}*/
}

	
void objTablero(char tablero[][MAXIMO], char tablero2[][MAXIMO], int fila, int columna, int obj){
	
	if(obj){
		for(int i=0; i<10; i++){
			for(int j=0; j<MAXIMO; j++){
				if(i == 9){
					tablero2[i][j] = '_';
				}
				else{
					tablero2[i][j] = '.';
				}
			}
		}
	}	
	else if(!obj){
		tablero2[fila][columna] = tablero[fila][columna];
	}
	
}

bool acierto(char tablero[][MAXIMO], int fila, int columna){
	return (tablero[fila][columna] == 'X' or tablero[fila][columna] == '^');
}

void bordes(){
	int punta=62, i;
		
	//coordenadas Y
	for(i=0; i<10; i++){
		gotoxy(punta,i);
		cout << i;
	}
	gotoxy(punta, i++);
	cout<<"Y";
	//coordenadas X
	punta = 11;
	int aux=0;
	for( i=0; i<20; i++){
		gotoxy(aux,punta);
		cout << i;
		aux+=3;
	}
	gotoxy(aux,punta);
	cout<<"X";
	/*
	//puntas
	gotoxy(0,0);
	cout << char(201);
	gotoxy(0,11);
	cout << char(200);
	gotoxy(21,0);
	cout << char(187);
	gotoxy(21,11);
	cout << char(188);
	*/
}
