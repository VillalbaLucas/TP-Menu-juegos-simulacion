#include "menu.h"
#include <iostream>
#include <windows.h>

using namespace std;

void MenuPrincipal(){
	system("cls");
	gotoxy(40,1);
	cout <<"    MENU PRINCIPAL\n";
	Linea();
	
	gotoxy(40,5);
	cout <<"1.- Algoritmos Numéricos\n";
	gotoxy(40,6);
	cout <<"2.- Juegos\n";
	gotoxy(40,7);
	cout <<"9.- Volver al menu de acceso\n\n";
	gotoxy(40,9);
	cout <<"Ingrese una opcion: ";
}
	
void MenuAlgoritmosNumericos(){
	gotoxy(35,1);
	cout <<" MENU ALGORITMOS NUMERICOS\n";
	Linea();
	
	gotoxy(30,5);
	cout <<"1.- Algoritmo Raiz cuadrada de 10 (Solución iterativa)\n";
	gotoxy(30,6);
	cout <<"2.- Algoritmo Raiz cuadrada de 10 (Solución recursiva)\n";
	gotoxy(30,7);
	cout <<"3.- Numero Feliz (Solución iterativa)\n";
	gotoxy(30,8);
	cout <<"4.- Algoritmo La gran funcion (Solución iterativa)\n";
	gotoxy(30,9);
	cout <<"9.- Salir\n\n";
	gotoxy(30,11);
	cout <<"Ingrese una opcion: ";
}

void Cerrar(){
	gotoxy(40,10);
	cout <<" Hasta luego !!!\n\n";
	Linea();
	
	gotoxy(35,14);
	cout <<"Duración de la sesión: ";
}
	
	
void gotoxy(int x,int y){  
	
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
	
void Linea(){
	for(int i=0; i<10; i++)
		cout<<"-._.-._.-.";	
}

void Logo(){
	gotoxy(25,1);
	cout<<"   __^__                                      __^__\n";
	gotoxy(25,2);
	cout<<"  ( ___ )------------------------------------( ___ )\n";
	gotoxy(25,3);
	cout<<"   |   |                                      |   | \n";
	gotoxy(25,4);
	cout<<"   |   |          Lucas A. Villalba.          |   |\n";
	gotoxy(25,5);
	cout<<"   |   |                                      |   |\n";
	gotoxy(25,6);
	cout<<"   |   |          Franco N. Peñaloza          |   |\n";
	gotoxy(25,7);
	cout<<"   |   |                                      |   |\n";
	gotoxy(25,8);
	cout<<"   |   |          Luciano A. Marchese.        |   |\n";
	gotoxy(25,9);
	cout<<"   |   |                                      |   |\n";
	gotoxy(25,10);
	cout<<"   |   |                R.I.P                 |   |\n";
	gotoxy(25,11);
	cout<<"   |___|          Jimena Bertuzzi.            |___|\n";
	gotoxy(25,12);
	cout<<"  (_____)------------------------------------(_____)\n";
}
void Logo2(){
	for(int x=1; x<75; x++){
		gotoxy(x,22);
		cout<<"           _             \n";
		gotoxy(x,23);
		cout<<"  _  _    | |_    _ _    \n";
		gotoxy(x,24);
		cout<<" | |_||   |  _|  | '  |   \n";
		gotoxy(x,25);
		cout<<" |__,_|   |___|  |_||_|  \n";
		gotoxy(x,26);
		cout<<"  _____   _____   _____  \n";
		gotoxy(x,27);
		cout<<"_|     |_|     |_|     | \n";
		gotoxy(x,28);
		cout<<" `-0-0-' `-0-0-' `-0-0-' \n";
		Sleep(60);
	}
}
void DefNumF(){
	gotoxy(35,1);
	cout <<"Algoritmo Numero Feliz(Solucion iterativa)\n";
	Linea();
	cout<<"    Los numeros felices son aquellos que se definen por el siguiente procedimiento:\n";
	cout<<"  Empezando con cualquier numero entero positivo, se reemplaza el numero por la suma de los cuadrados";
	cout<<"de sus digitos, y se repite el proceso hasta que el numero es igual a 1 o hasta que se entra en un\n";
	cout<<"bucle que no incluye el 1.\n\n";
	cout<<"Presione 9 para volver al menu anterior.\n";
}
void MenuDef(){
	gotoxy(40,3);
	cout<<"1.Ver definicion.\n";
	gotoxy(40,4);
	cout<<"2.Ejecutar\n";
	gotoxy(40,6);
	cout<<"9.Volver al menu anterior.\n";
	gotoxy(40,7);
	cout<<"Ingrese una opcion: ";
}
void DefRaiz10(){
	gotoxy(30,1);
	cout <<"Algoritmo Raiz cuadrada de 10\n";
	Linea();
	cout<<"El método de fracciones continuas periódicas es una de las muchas formas de calcular la raíz\n";
	cout<<"cuadrada de un número natural. Es decir, para este algoritmo podemos ir aproximando el valor\n";
	cout<<"de la raiz de 10 mediante suma de fracciones sucesivas.\n";
	cout<<"Esta repetición se puede realizar un número fijo de veces.\n\n\n";
	cout<<"Presione 9 para volver al menu anterior.\n";
}
void DefFuncion(){
	gotoxy(30,1);
	cout <<"Algoritmo La gran funcion (Solución iterativa)\n";
	Linea();
	cout<<"Este algoritmo lo que hace es llamar una funcion f(n,k). Donde \n";
	cout<<"a todos los divisores de n se les eleva a una  potencia k y se los suma. \n";
	cout<<"El resultado, entonces va a ser la suma de todos los divisores de n elevados\n";
	cout<<"a una potencia de valor k.\n\n\n";
	cout<<"Presione 9 para volver al menu anterior.\n";
}

void menuJuegos(){
	
	gotoxy(35,1);
	cout <<"Menu de Juego Super Mario Bros              \n";
	Linea();
	gotoxy(30,4);
	cout <<"1.- Simulacion de encuentro entre Mario y Luigi\n";
	gotoxy(30,6);
	cout <<"9.- Volver al menu anterior\n";
	gotoxy(30,9);
	cout <<"Ingrese una opcion: ";
}
	
void menuSimulacion(){
	
	gotoxy(35,1);
	cout <<"Juego Super Mario Bros - Simulacion 1\n";
	Linea();
	gotoxy(30,4);
	cout <<"1.- Ver instrucciones\n";
	gotoxy(30,5);
	cout <<"2.- Jugar y simular\n";
	gotoxy(30,7);
	cout <<"9.- Volver al menu anterior\n";
	gotoxy(30,10);
	cout <<"Ingrese una opcion: ";

}

void simulacionDef(){
	gotoxy(40,0);
	cout<<"Instrucciones";
	gotoxy(0,1);
	Linea();
	gotoxy(2,5);
	cout<<"Primera parte, Tablero escondido:";
	gotoxy(2,7);
	cout<<"En este juego aparecera arriba de todo un vacio que representa un tablero invisible";
	gotoxy(2,8);
	cout<<"que el usuario debera encontrar.";
	gotoxy(2,9);
	cout<<"Las instrucciones son ingresar los valores de X e Y en el rango permitido.";
	gotoxy(2,10);
	cout<<"A medida que vaya ingresando vazlores se ira descubriendo el tablero en esta.";
	gotoxy(2,11);
	cout<<"Si en esa posicion hay algun ave() o piedra(X) se indicara 'Acierto' y se le dara 1 punto";
	gotoxy(2,12);
	cout<<"En caso contrario se mostrara 'Aire o Tierra' y se rellenara con esto";
	gotoxy(2,13);
	cout<<"Para rendirse y pasar a la segunda parte debera ingresar 99";
	gotoxy(2,15);
	cout<<"Segunda parte, Simulacion del encuentro";
	gotoxy(2,17);
	cout<<"En esta etapa se generara una simulacion automatica de Mario y Luigi";
	gotoxy(2,18);
	cout<<"Esta consiste en que los hermanos aparecen en posiciones aleatorias del tablero,";
	gotoxy(2,19);
	cout<<"una vez ahi los destapa tuberias caminaran, saltaran, treparan.";
	gotoxy(2,20);
	cout<<"Todo esto segun los obstaculos que tengan adelante hasta encontrarse con su hermano.";
	gotoxy(2,22);
	cout<<"Presione 9 para volver: ";
}

void rangoxy(){
	gotoxy(0,13);
	cout << "Rango valido permitido:" << endl;
	cout <<"0 <= X < 20\n0 <= Y < 10\n";
}
