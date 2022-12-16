#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include "personaje.h"
#include "puntosTablero.h"
#include "menu.h"
#include <cctype>
using namespace std;

void crearP(Personaje &p, string nom, char apar){
	srand(time(NULL));
	int lado;
	int pos;
	
	lado = rand()%2;
	pos = rand()%20;
	
	p.nombre = nom;
	p.apariencia = toupper(apar);
	p.posicion = pos;
	lado==1? p.orientacion = 'd': p.orientacion = 'i';
}
void saludar(Personaje p){
	cout << "Hola soy " << p.nombre;
	Sleep(1000);
}
	
void girar(Personaje &p){
		
	if(p.orientacion == 'd')
		p.orientacion = 'i';
	else
		p.orientacion = 'd';
}

void caminar(Personaje &p, char tabl[][MAXIMO], int &mov){
	
	//Si estamos en algun borde del mapa giramos.
	if(p.posicion == 0 and p.orientacion == 'i')
		girar(p);
	else if(p.posicion == 19 and p.orientacion == 'd')
		girar(p);
	
	//vemos si hay algun obstaculo, si lo hay contar la altura de este.
	int y = 9;
	int altura=0;
	int trepo=0;

	
	while(p.orientacion == 'd' and acierto(tabl, y,p.posicion+1)){
		y--;
		altura++;
		
	}
	
	while(p.orientacion == 'i' and acierto(tabl, y,p.posicion-1)){
		y--;
		altura++;
	}
	
	/*if(p.vertigo){
		
		bajar(p, tabl,mov);
		p.vertigo = false;
		trepo++;
	}*/
	if(altura > 0){
		saltarEscalar(p, altura, mov);
		trepo++;
		p.vertigo = true;
		bajar(p,tabl);
	}
	
	if(trepo !=1){
		
		if( p.orientacion == 'd' and !acierto(tabl, 9,p.posicion+1) ){
			if(p.posicion==0){
				gotoxy(p.posicion,9);
				cout <<"_";
			}
			else{
				gotoxy(p.posicion*3,9);
				cout <<"_";
			}
			p.posicion ++;
		}
		else if( p.orientacion == 'i' and !acierto(tabl, 9,p.posicion-1) ){
			if(p.posicion==0){
				gotoxy(p.posicion,9);
				cout <<"_";
			}
			else{
				gotoxy(p.posicion*3,9);
				cout <<"_";
			}
			p.posicion --;
		}
		if(p.posicion==0){
			gotoxy(p.posicion,9);
			cout <<p.apariencia;
			Sleep(1000);
		}
		else{
			gotoxy(p.posicion*3,9);
			cout <<p.apariencia;
			Sleep(1000);
		}
		mov++;
	}
	
}
	
void saltarEscalar(Personaje &p, int alt,int &mov){
	//Este for crea la "animacion" de que sube.
	for(int i=0; i<=alt; i++){
		gotoxy(p.posicion*3,9-i); 			  
		cout << p.apariencia;						 						
		Sleep(500);
		//esto rellena los espacios anteriores para q no quede el personake.
		if(p.posicion==0){
			if(i==0){
				gotoxy(p.posicion,9-i); 			
				cout << "_";
			}
			else if(i>0){
				gotoxy(p.posicion,9-i); 			
				cout << ".";
			}
		}
		else{
			if(i==0){
				gotoxy(p.posicion*3,9-i); 			
				cout << "_";
			}
			else if(i>0){
				gotoxy(p.posicion*3,9-i); 			
				cout << ".";
			}
		}
	}
	
	p.orientacion == 'd'? p.posicion++: p.posicion--;
	mov++;
	
	gotoxy(p.posicion*3, 9-alt); 
	cout << p.apariencia;
	
	if(p.orientacion == 'd'){
		gotoxy((p.posicion-1)*3, 9-alt); 
		cout << ".";
	}
	else{
		gotoxy((p.posicion+1)*3, 9-alt); 
		cout << "."; 
	}
	Sleep(500);
}
	
void mostrarP(Personaje &p){
	if(p.posicion==0){
		gotoxy(p.posicion,9);
		cout <<p.apariencia;
		Sleep(800);
	}
	else{
		gotoxy(p.posicion*3,9);
		cout <<p.apariencia;
		Sleep(800);
	}
}

void bajar(Personaje &p, char tabl[][MAXIMO]){
	int y=9;
	int alt=0;
	
	while(acierto(tabl, y, p.posicion)){
		alt++;
		y--;
	}
	
	p.orientacion == 'd'? p.posicion++ : p.posicion--;
	
	gotoxy(p.posicion*3, 9-alt); 
	cout << p.apariencia;
	
	if(p.orientacion == 'd'){
		gotoxy((p.posicion-1)*3, 9-alt); 
		cout << ".";
	}
	else{
		gotoxy((p.posicion+1)*3, 9-alt); 
		cout << "."; 
	}
	
	
	for(int i=y; i<=9; i++){
		
		gotoxy(p.posicion*3,i); 			  
		cout << p.apariencia;						 						
		Sleep(500);
		//esto rellena los espacios anteriores para q no quede el personake.
		if(i<9){
			gotoxy(p.posicion*3,i); 			
			cout << ".";
		}
	}
	
}
	
void bros(Personaje &p, char tabl[][MAXIMO]){
	int alt=0;
	int y=9;
	
	while(acierto(tabl, y, p.posicion)){
		alt++;
		y--;
	}
	
	gotoxy(p.posicion*3,y);
	cout <<"B";
	Sleep(1000);
}	

