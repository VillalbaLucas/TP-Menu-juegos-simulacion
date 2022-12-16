#include <iostream>
#include <windows.h> 
#include "registro.h"
#include "acciones.h"
#define USER 20
#define PASS 40
#include <fstream>
#include <ctime>
#include <conio.h>

bool registerUser(Usuarios &registro);
bool registerPass(Usuarios &registro);
void pautasUser();
void pautasPass();
bool validacionUser(Usuarios registro);
bool validacionPass(Usuarios registro);
bool passValida(char passIngre[]);
bool busquedaUser(char nameIngre[], int &pos);
bool iguales(char nombreArchivo[], char nombreIngre[]);
void gotoxy(int x,int y);
void Linea();
void actualizar(char[]);

using namespace std;

/*void gotoxy(int x,int y){  
	
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}*/
	
void menuacceso(){
	system("cls");
	gotoxy(43,2);
	cout<<"MENU DE ACCESO"<<endl<<endl;
	Linea();
	gotoxy(0,26);
	Linea();
	
	gotoxy(40,6);
	cout<<"1.- Registro"<<endl;
	gotoxy(40,7);
	cout<<"2.- Iniciar Sesion"<<endl;
	gotoxy(40,8);
	cout<<"9.- Cerrar la aplicacion"<<endl;
	gotoxy(40,10);
	cout<<"Ingrese una opcion: ";
}
	
/*void Linea(){
	for(int i=0; i<10; i++)
		cout<<"-._.-._.-.";	
}	
*/
	
bool registrar(){
		ofstream archivoB;
		int x=1;
		bool valido=false;
		char opc;
		
		archivoB.open("Lista.dat", ios::app | ios::binary);
		
		if(archivoB.fail()){
			cout<<"No se pudo abrir el archivo"<<endl;
			exit(1);
		}
		
		Usuarios registro;
		
		do{
			fflush(stdin);
			if(registerUser(registro)==true){
				if(registerPass(registro)==true){
					valido = true;
				}else {
					system("cls");
					system("pause");
					cout<<"¡Demasiados intentos!"<<endl;
					x++;
				}
			}else{
				system("cls");
				system("pause");
				cout<<"¡Demasiados intentos!"<<endl;
				x++;
			}
			
			if(x==3){
				system("cls");
				system("pause");
				cout<<"Ultimo intento para registrarte!"<<endl;
			}
		} while(x<=3 && valido==false);
		
		if(valido==false && x>3){
			system("cls");
			cout<<"Llegaste al limite de intentos"<<endl<<endl;
			cout<<"Volviendo al menu de acceso..."<<endl;
			Sleep(2000);
		}else{
			system("cls");
			
			iniFecha(registro);
			
			cifrar_texto(registro.user);
			cifrar_texto(registro.password);
			
			archivoB.write((char *)&registro, sizeof(Usuarios));
			cout<<endl;
			Linea();
			gotoxy(40,4);
			cout<<"Registrado con exito!";
			gotoxy(36,5);
			cout<<"Quiere iniciar sesion? (s/n): "; cin>>opc;
			if(opc=='n'){
				valido=false;
			}
		}
		
		archivoB.close();
	return valido;
}

bool registerUser(Usuarios &registro){
	
	bool valido=false;
	int x=1;
	do{
		fflush(stdin);
		system("cls");
		
		cout<<endl;
		Linea();
		cout<<"\n\n\n\n";
		pautasUser();
	
		cout<<"\t\tIngrese su nombre de usuario: "; 
		cin.getline(registro.user,USER);
		fflush(stdin);
			
		if(validacionUser(registro)==false){
			cout<<endl;
			cout<<"\t\t\t\t¡User no valido!"<<endl<<endl;
			system("pause > NULL");
			x++;
		}else{
			valido=true;
			cout<<endl;
			cout<<"\t\t\t\t¡Usuario Valido!"<<endl<<endl;
			system("pause > NULL");
		}
	} while(x<=3 && valido==false);

	if(valido==false && x>3){
		system("cls");
		cout<<endl;
		Linea();
		cout<<"\n\n\n\n";
		cout<<"\t\t\tLlegaste al limite de intentos"<<endl<<endl;
		cout<<"\t\t\tVolviendo al menu principal..."<<endl;
		Sleep(2000);
	}
	
	return valido;
}

bool registerPass(Usuarios &registro){
	bool valido=false;
	int x=1;
	do{
		fflush(stdin);
		system("cls");
			
		
		cout<<endl;
		Linea();
		cout<<"\n\n\n\n";
		
		pautasPass();
			
		char caracter;
		int i=0;
		
		cout<<"\t\tIngrese su contraseña: "; 
		while(true){
			caracter = getch();
			if(caracter == 13){
				registro.password[i]='\0';
				break;
			}else if(caracter==8){
				if(i>0){
					i--;
					cout<<"\b \b";
				}
			}
			else{
				if(i<PASS){
				cout<<"*";
				registro.password[i] = caracter;
				i++;
				}
				else
					break;
				
			}
		}
		
		fflush(stdin);
		if(validacionPass(registro)==false){
			cout<<endl;
			cout<<"\t\t\t\t¡Password no valida!"<<endl<<endl;
			system("pause");
			x++;
		}	else{
			valido=true;
			cout<<endl;
			cout<<"\t\t\t\t¡Password Valida!"<<endl<<endl;
			system("pause > NULL");
		}
	} while(x<=3 && valido==false);
		
	if(valido==false && x>3){
		system("cls");
		
		cout<<endl;
		Linea();
		cout<<"\n\n\n\n";
		
		cout<<"\t\t\tLlegaste al limite de intentos"<<endl<<endl;
		cout<<"\t\t\tVolviendo al menu principal..."<<endl;
		Sleep(2000);
	}
	
	return valido;
}	
	
void pautasUser(){
	cout<<"\t\tPautas a tener en cuenta a la hora de crear su nombre de usuario: "<<endl;
	cout<<"\t\t*Debe tener un minimo de  6(seis) y un maximo de 10(diez) caracteres*"<<endl;
	cout<<"\t\t*Debe comenzar con una letra minuscula*"<<endl;
	cout<<"\t\t*Debe tener al menos 2 letras mayusculas*"<<endl;
	cout<<"\t\t*Debe tener como maximo 3 digitos numericos*"<<endl;
	cout<<endl;
}

void pautasPass(){
	cout<<"\t\tPautas a tener en cuenta a la hora de crear su contraseña: "<<endl;
	cout<<"\t\t*Debe tener un minimo de 6 y un maximo de 32 caracteres*"<<endl;
	cout<<"\t\t*Debe tener al menos una letra minuscula*"<<endl;
	cout<<"\t\t*Debe tener al menos una letra mayuscula*"<<endl;
	cout<<"\t\t*Debe tener al menos un numero*"<<endl;
	cout<<"\t\t*No puede contener ningun caracter de puntuacion, acento o espacio*"<<endl;
	cout<<endl;
}	
	
bool validacionUser(Usuarios registro){
	bool valido=false;
	int tam, pos=0;
	tam = strlen(registro.user);
	
	if(tam>=6 && tam<=10){
		if(caracteresPerm(registro.user, tam)==false){
			if(registro.user[0]>=97 && registro.user[0]<=122){
				if(mayusculas(registro.user, tam)==true){
					if(numeros(registro.user, tam)==true){
						if(busquedaUser(registro.user,pos)==false){
							valido=true;
						}else{cout<<"\n\t\t\t\tYa existe ese user"<<endl;}
					}else{cout<<"\n\t\t\t\tPosee mas de 3 digitos"<<endl;}
				}else{cout<<"\n\t\t\tNo posee al menos 2 letras mayusculas"<<endl;}
			}else{cout<<"\n\t\t\tNo comienza con una letra minuscula"<<endl;}
		}else {cout<<"\n\t\t\t\tCaracteres no permitidos"<<endl;}	
	}else {cout<<"\n\t\t\t\tTamaño no valido"<<endl;}		
	
	return valido;
}
	
bool validacionPass(Usuarios registro){
	bool valido=false;
	int tam;
		
	tam = strlen(registro.password);
		
	if(tam>=6 && tam<=32){
		if(caracterPass(registro.password, tam)==false){
			if(Mayus(registro.password,tam)==true){
				if(Minim(registro.password,tam)==true){
					if(Num(registro.password,tam)==true){
						valido=true;
					}else{cout<<"\n\t\t\t\tNo posee un numero"<<endl;}
				}else{cout<<"\n\t\t\t\tNo posee una minuscula"<<endl;}
			}else{cout<<"\n\t\t\t\tNo posee una mayuscula"<<endl;}
		}else{cout<<"\n\t\t\tCaracter(es) no permitido(s)"<<endl;}
	}else{cout<<"\n\t\t\tNo cumple con el tamaño pautado"<<endl;}
	return valido;
}
	
bool busquedaUser(char nameIngre[], int &pos){
	bool valido=false;
		
	ifstream archivoB{"Lista.dat", ios::in | ios::binary};
		
	if(archivoB.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	Usuarios inicio;
	
	do{
		archivoB.read((char *)&inicio, sizeof(Usuarios));
		if(iguales(inicio.user,nameIngre)==true){
			valido = true;
		}	
	} while(valido==false && !archivoB.eof());
		
	pos = archivoB.tellg();
	archivoB.close();
	
	return valido;
}	
	
bool iguales(char nombreArchivo[], char nombreIngre[]){
	bool valido=true;
	int tI, tA;
	char copia[USER];
	
	strcpy(copia,nombreIngre);
	cifrar_texto(copia);
	
	tI = strlen(copia);
	tA = strlen(nombreArchivo);
	
	if(tI==tA){
		int i=0;
		while(i<tI && valido == true){
			if(nombreArchivo[i]!=copia[i]){
				valido=false;
			}else i++;
		}
	}else valido=false;
	
	return valido;
}
	
bool iniciar(){
	int x=0, i=0, pos;
	bool ingresar=false;
	
	char name[USER];
	char pass[PASS];
	
	do{
		system("cls");
		fflush(stdin);
		
		cout<<endl;
		Linea();
		cout<<"\n\n\n";
		
		gotoxy(33,4);
		cout<<"Por favor ingrese su usuario: ";
		cin.getline(name,USER);
		fflush(stdin);
		if(busquedaUser(name, pos)==true){
			ingresar = true;
		}else{
			gotoxy(45,5);
			cout<<"Usuario no encontrado!"<<endl;
			i++;
			Sleep(2000);
		}
	} while(ingresar==false && i<=3);
	
	if(ingresar==false){
		gotoxy(44,5);
		cout<<"Demasiados intentos!"<<endl;
		gotoxy(40,6);
		cout<<"Volviendo al menu de acceso..."<<endl;
		Sleep(2000);
		return ingresar;
	}else{
		ingresar=false;
		i=0;
	}
	
	do{
		system("cls");
		fflush(stdin);
		
		cout<<endl;
		Linea();
		cout<<"\n\n";
		char caracter;
		
		gotoxy(32,4);
		cout<<"Por favor ingrese su password: ";
		
		x=0;
		
		while(true){
			fflush(stdin);
			caracter = getch();
			if(caracter == 13){
				pass[x]='\0';
				break;
			}else if(caracter==8){
				if(x>0){
					x--;
					cout<<"\b \b";
				}
			}
			else{
				if(x<PASS){
				cout<<"*";
				pass[x] = caracter;
				x++;
				}
				else{
					pass[x++]='\0';
				   break;
				}
			}
		}
		
		fflush(stdin);
		if(passValida(pass)==true){
			ingresar=true;
		}else{
			gotoxy(45,6);
			cout<<"Password no valida!"<<endl;
			i++;
			Sleep(2000);
		}
	} while(ingresar==false && i<=3);
	
	if(ingresar==false){
		gotoxy(43,8);
		cout<<"Demasiados intentos!"<<endl;
		gotoxy(40,9);
		cout<<"Volviendo al menu de acceso..."<<endl;
		Sleep(2000);
	}
	
	if(ingresar==true){
		ifstream archivoB{"Lista.dat", ios::in | ios::binary};
		
		if(archivoB.fail()){
			cout<<"No se pudo abrir el archivo"<<endl;
			exit(1);
		}
		
		Usuarios inicio={"","",{0,0,0}};
		
		archivoB.seekg(pos-sizeof(Usuarios));
		
		archivoB.read((char *)&inicio, sizeof(Usuarios));
		gotoxy(41,8);
		cout<<"Bienvenido: "<<name<<"!"<<endl;
		gotoxy(39,9);
		cout<<"Ultima Sesion: "<<inicio.ultSesion.dia<<"/"<<inicio.ultSesion.mes<<"/"<<inicio.ultSesion.anio<<endl;
		Sleep(3000);
		
		actualizar(name);
		
		archivoB.close();
	}
	
	return ingresar;
}
	
bool passValida(char passIngre[]){
	
	ifstream archivoB("Lista.dat", ios::in | ios::binary);
	bool valido=false;
		
	if(archivoB.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	Usuarios inicio;
	
	do{
		archivoB.read((char *)&inicio, sizeof(Usuarios));
		if(iguales(inicio.password,passIngre)==true){
			valido=true;
		}
	} while(valido==false && !archivoB.eof());
	
	archivoB.close();
	
	return valido;
	
}	
	
void actualizar(char nombre[]){
	fstream archivoB;
	
	archivoB.open("Lista.dat", ios::in | ios::out | ios::binary);
	
	if(archivoB.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	//Usuarios s = {"","",{0,0,0}};
	Usuarios p[100];
	
	int i=0;
	
	archivoB.read((char *)&p[i], sizeof(Usuarios));
	i++;
	while(!archivoB.eof()){
		archivoB.read((char *)&p[i], sizeof(Usuarios));
		i++;
	}
	
	int x=0;
	while(iguales(p[x].user,nombre)==false){
		x++;
	}
	
	iniFecha(p[x]);
	
	archivoB.write((char *)&p, ((i)*sizeof(Usuarios)));
	archivoB.close();
}
	
	
void iniFecha(Usuarios &usu){
	time_t ahora;
	struct tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	
	usu.ultSesion.dia =	(fecha->tm_mday);
	usu.ultSesion.mes = (fecha->tm_mon+1);
	usu.ultSesion.anio = (fecha->tm_year+1900);
}
	
	
