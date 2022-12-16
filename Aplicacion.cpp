#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "menu.h"
#include "algNumericos.h"
#include "registro.h"
#include "stdpanel.h"
#include "puntosTablero.h"
#include "personaje.h"
#include <fstream>
#include <cstdio>
using namespace std;
string volveraingresar = "Esta no es una opcion valida,\n Por favor, vuelva a ingresar una opcion:\n";

void empezar();
void funMenuAlg();
void funMenuJue();
void algRaizIte();
void algRaizRec();
void algNumFeliz();
void algGranFun();
void simulacionA();
void empezarSimulacion();

int main(int argc, char *argv[]) {
	int menuAcce,t0=0,t1;
	
	
	system("mode con: cols=100 lines=30");
	SetConsoleTitle("Lucas**/**Jime**/**Luciano**/**Franco**/**--Distrito '18'--**/** console");
	system("color 03");
	t0=clock();
	Logo();
	Logo2();
	Sleep(3000);
	system("cls");

	do{	
		menuacceso();
		cin>>menuAcce;
		
		while(menuAcce!=1 && menuAcce!=2 && menuAcce!=3 && menuAcce!=9){
			cout << volveraingresar;
			Sleep(1000);
			fflush(stdin);
			system("cls");
			menuacceso();
			cin>>menuAcce;
		}
		
		switch(menuAcce){
			case 1: if(registrar()==true){
				empezar();
				}break;
			case 2: if(iniciar()==true){
				empezar();
				}break;
		}
	}while(menuAcce!=9);
	
	system ("cls");
	Cerrar();
	t1=clock();
	int time = (int(t1-t0)/CLOCKS_PER_SEC);
	cout<< time/3600 <<":"<< time/60 <<":"<< time;
	
	Sleep(2000);
	gotoxy(35,25);
	exit(0);
}

void empezar(){
		
	int menu;
		//submenu,menualg,valor;
	do{
		MenuPrincipal();
		cin >> menu;
		
		while(menu!=1 and menu !=2 and menu!=9){
			cout << volveraingresar;
			Sleep(1000);
			fflush(stdin);
			system("cls");
			MenuPrincipal();
			cin >> menu;
		}
			
		switch(menu){
		case 1: funMenuAlg();
			system("cls");
		 break;
		case 2: funMenuJue();
			system("cls");
		 break;	
		}
	}while(menu!=9);
	system("cls");
}

void funMenuAlg(){
	
	int submenu;
	do{
		system("cls");
		MenuAlgoritmosNumericos();
		cin >> submenu;
		while(submenu<0 and (submenu>4 and submenu<9) and submenu>9){
			cout<<endl << volveraingresar;
			Sleep(1000);
			system("cls");
			MenuAlgoritmosNumericos();
			fflush(stdin);
			cin >> submenu;
		}
			
		switch(submenu){
		case 1: system ("cls");
				algRaizIte();
		 break;
		case 2: system("cls");
				algRaizRec();
		 break;
		case 3:	system("cls");
				algNumFeliz();
		 break;
		case 4: system("cls");
				algGranFun();
		 break;
		}		
	} while(submenu!=9);
}

void algRaizIte(){
	
	int menu, submenu, valor;

	do{
		system("cls");
		gotoxy(25,1);
		cout <<"Algoritmo Raiz cuadrada de 10(Solucion iterativa)\n";
		Linea();	
		MenuDef();
		cin >> menu;
		while(menu!=1 and menu!=2 and menu!=9){
			system("cls");
			gotoxy(25,1);
			cout <<"Algoritmo Raiz cuadrada de 10(Solucion iterativa)\n";
			Linea();	
			MenuDef();
			cin >> menu;
		}
		switch(menu){
			case 1: system("cls");
				DefRaiz10();
				cin >> submenu;
				while(submenu!=9)
					cin >> submenu;
				system("cls");
			 break;
			case 2: system("cls");
				cout <<"Ingrese un numero de aproximaciones:";
				cin >> valor;
				if(valor>-1){
					cout <<"El valor de la raiz de 10 es: "<<fixed<<setprecision(10)<<Raiz(valor)<< endl;
					cout <<"aproximandola un total de "<<valor<<" veces.\n\n";
				}
				else
					cout<<"Valores fuera de rango\n\n";
						
				cout <<"Volviendo al menu anterior...";
				Sleep(4000);
			 break;
		}
		
	}while(menu!=9);
}
	
void algRaizRec(){
	int menu, submenu, valor;
	
	do{
		system ("cls");
		gotoxy(25,1);
		cout <<"Algoritmo Raiz cuadrada de 10(Solucion recursiva)\n";
		Linea();	
		MenuDef();
		cin>>menu;
		
		while(menu!=1 and menu!=2 and menu!=9){
			system ("cls");
			gotoxy(25,1);
			cout <<"Algoritmo Raiz cuadrada de 10(Solucion recursiva)\n";
			Linea();	
			MenuDef();
			cin>>menu;
		}
		switch(menu){
		case 1:system("cls");
					DefRaiz10();
					cin >> submenu;
				while(submenu!=9)
					cin >> submenu;
				system("cls");
		 break;
		case 2: system("cls");
				cout <<"Ingrese un numero de aproximaciones: ";
				cin >> valor;
							
				if(valor>-1){
					cout <<"El valor de la aproximacion es: "<<fixed<<setprecision(10)<<3+RaizR(valor)<<endl;
					cout <<"aproximandola un total de "<<valor<<" veces.\n\n";
				}
				else
					cout <<"Valores fuera de rango.\n\n";
							
				cout <<"Volviendo al menu anterior...";
				Sleep(4000);
		 break;
		} 
	}while(menu!=9);
}

void algNumFeliz(){
	int menu, submenu, valor;
	
	do{
		system ("cls");
		gotoxy(25,1);
		cout <<"Algoritmo Numero feliz (solucion iterativa)\n";
		Linea();	
		MenuDef();
		cin>>menu;
		
		while(menu!=1 and menu!=2 and menu!=9){
			system ("cls");
			gotoxy(25,1);
			cout <<"Algoritmo Numero feliz (solucion iterativa)\n";
			Linea();	
			MenuDef();
			cin>>menu;
		}
		switch(menu){
			case 1: system("cls");
					DefNumF();
					cin >> submenu;
					while(submenu!=9)
						cin >> submenu;
					system("cls");
			 break;
			case 2: system("cls");
					cout <<"Ingrese un numero: ";
					cin >> valor;
					if(valor>-1){
						if(Nfeliz(valor)==1)
							cout << valor <<" "<< "Es un numero feliz\n\n";
						else
							cout << valor <<" "<< "No es un numero feliz\n\n";
					}
					else 
						cout <<"Valores fuera de rango.\n\n";
					cout <<"Volviendo al menu anterior...";
					Sleep(4000);
			break;
		} 
	}while(menu!=9);
}
	
void algGranFun(){

	int menu, submenu,valork, valor;

	do{
		system ("cls");
		gotoxy(25,1);
		cout <<"Algoritmo La gran funcion(solucion iterativa)\n";
		Linea();	
		MenuDef();
		cin>>menu;
		
		while(menu!=1 and menu!=2 and menu!=9){
			system ("cls");
			gotoxy(25,1);
			cout <<"Algoritmo La gran funcion(solucion iterativa)\n";
			Linea();	
			MenuDef();
			cin>>menu;
		}
		
		switch(menu){
		case 1: system("cls");
				DefFuncion();
				cin >> submenu;
				while(submenu!=9)
					cin >> submenu;
				system("cls");
		 break;
		case 2: system("cls");
				cout <<"Ingrese un valor para n: "<< endl;
				cin >> valor;
				cout <<"Ingrese un valor para k: "<< endl;
				cin >> valork;
				if(valor>-1 and (valork>-1 and valork<51))
					cout <<"El resultado de elevar los divisores de n al valor k es: "<<LaGranFuncion(valor,valork)<<"\n\n";
				else 
					cout <<"Valores fuera de rango\n\n";
			cout <<"Volviendo al menu anterior...";
			Sleep(6000);
		 break;
		} 
	}while(menu!=9);
}

void funMenuJue(){
	system("cls");
	int submenu;
	
	do{
		menuJuegos();
		cin >> submenu;
		while(submenu!=1 and submenu!=9){
			cout << volveraingresar;
			system("cls");
			fflush(stdin);
			menuJuegos();
			cin >> submenu;
		}
		
		switch(submenu){
			case 1: simulacionA();
				system("cls");
			 break;
		}
	} while(submenu!=9);
}

void simulacionA(){
	system("cls");
	int menualg, valor;
	
	do{
		menuSimulacion();
		cin >> menualg;
		while(menualg!=1 and menualg!=2 and menualg!=9){
			cout << volveraingresar;
			Sleep(1000);
			system("cls");
			fflush(stdin);
			menuSimulacion();
			cin >> menualg;
		}
		switch(menualg){
			case 1: system("cls");
				simulacionDef();
				cin >> valor;
				while(valor!=9){
				cout << volveraingresar;
				cin >> valor;
				}
				system("cls");
			 break;
			case 2: system("cls");
					empezarSimulacion();
			 break;
		}
	}while(menualg != 9);
}
	
void empezarSimulacion(){
	char tablero[10][MAXIMO], tablero2[10][MAXIMO];
	cargarTablero(tablero,10,20);	
	int puntos=0;
	int x,y;
	rangoxy();
	bordes();
	
	objTablero(tablero, tablero2,0,0,1);
	mostrarTablero1(tablero2);
	
	gotoxy(0,17);
	cout << "Elija posicion x: ";
	cin >> x;
	
	while(x != 99){
		
		gotoxy(0,18);
		cout << "Elija una posicion y: ";
		cin	>> y;
		
		if( (y>=0 and x>=0) and (x<20 and y<10) ){
			
			if(acierto(tablero, y, x)){
				gotoxy(0,20);
				cout << "Acierto      " << endl;
				objTablero(tablero, tablero2, y, x, 0);
				mostrarTablero1(tablero2);
				puntos++;
			} 
			else if(!acierto(tablero, y, x)){
				gotoxy(0,20);
				cout << "Aire o Tierra" << endl;
				//objTablero(tablero, tablero2, y, x, 1);
				mostrarTablero1(tablero2);
			}
			gotoxy(0,19);
			cout << "Puntuacion: " << puntos;
		}
		
		gotoxy(18,17);
		cout <<"        ";
		gotoxy(22,18);
		cout <<"        ";
		gotoxy(0,17);
		cout << "Elija posicion x: ";
		cin >> x;
		
	}
	system("cls");
	gotoxy(0,0);
	tableroMostrar(tablero, 10,20);
	
	//Aca empezaria la simulacion.
	srand(time(NULL));
	Personaje pMario,pLuigi;
	
	crearP(pMario,"Mario", 'm');
	Sleep(1000);
	crearP(pLuigi, "Luigi",'l');
	
	//Para que Mario ni Luigi esten en la posicion con piedras o en la misma.
	while( acierto(tablero,9,pMario.posicion) )
		pMario.posicion = rand()%20;
	
	while(pLuigi.posicion == pMario.posicion or acierto(tablero, 9, pLuigi.posicion))
		pLuigi.posicion = rand()%20;
	
	
	int movM=0, movL=0;
	gotoxy(70,2);
	saludar(pMario);
	mostrarP(pMario);
	Sleep(800);
	
	gotoxy(70,2);
	saludar(pLuigi);
	mostrarP(pLuigi);
	Sleep(800);
	int turno=0;
	
	while(pLuigi.posicion != pMario.posicion){
		gotoxy(25,4);
		srand(time(NULL));
		int accion = rand()%11;
		if(turno%2==0){
			gotoxy(70,2);
			cout<<"Turno de Mario";
			Sleep(800);
			if(accion>0){
				caminar(pMario,tablero,movM);
				gotoxy(70,4);
				cout<<"Mario se movio";
				Sleep(1000);
				gotoxy(70,4);
				cout<<"              ";
			}else{
				gotoxy(70,4); 
				cout<<"MARIO TE SALUDA! :D";
				gotoxy(70,5);
				saludar(pMario);
				gotoxy(70,4);
				cout<<"                   ";
				gotoxy(70,5);
				cout<<"              ";
			}
		}
		else{
			gotoxy(70,2);
			cout<<"Turno de Luigi";
			Sleep(800);
			if(accion>0){
				caminar(pLuigi,tablero, movL);
				gotoxy(70,4);
				cout<<"Luigi se movio";
				Sleep(1000);
				gotoxy(70,4);
				cout<<"              ";
			}
			else{
				gotoxy(70,4);
				cout<<"LUIGI TE SALUDA! :D";
				gotoxy(70,5);
				saludar(pLuigi);	
				gotoxy(70,4);
				cout<<"                   ";
				gotoxy(70,5);
				cout<<"              ";
			}
		}
		Sleep(1000);
		turno++;
	}
	gotoxy(70,2);
	cout<<"              ";
	gotoxy(70,4);
	cout<<"              ";
	
	bros(pMario,tablero);
	
	gotoxy(62, 1);
	cout<<"BROS! Los hermanos se han encontrado";
	
	gotoxy(70,3);
	cout<<"Movimientos de Mario: "<<movM;
	gotoxy(70,4);
	cout<<"Movimientos de Luigi: "<<movL;
	
	
	if(movM>movL){
		gotoxy(70,6);
		cout<<"LUIGI GANO LA SIMULACION"<<endl;
	}
	else if(movL>movM) {
		gotoxy(70,7);
		cout<<"MARIO GANO LA SIMULACION"<<endl;
	}
	else {
		gotoxy(70,8);
		cout<<"LA SIMULACION TERMINO CON UN EMPATE"<<endl;
	}
	
	system("pause>NULL");
	
	system("cls");
}
