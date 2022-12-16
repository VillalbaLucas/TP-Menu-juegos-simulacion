#include <iostream>
#include <cstring>
#include <cstdio>
#include <tuple>
#include <cctype>
#include "acciones.h"
using namespace std;

void invertir(char[], int);

bool caracteresPerm(char nombre[], int tl){
	bool noPerm=false;
	int contador=0;
	
	while(noPerm && contador<tl){
		if(nombre[contador]==42 or nombre[contador]==43 or nombre[contador]==45 or nombre[contador]==47 or isalpha(nombre[contador]!=0)){
			contador++;
		}else noPerm=true;
	}
	return noPerm;
}
	
bool mayusculas(char nombre[], int tl){
	bool valido=false;
	int contador=0, i=0;
	
	while(contador<tl && i<2){
		if(nombre[contador]>=65 && nombre[contador]<=90){
			i++;
			if(i>1)valido=true;
		}
		contador++;
	}
		
	return valido;
}

bool numeros(char nombre[], int tl){
	bool valido=false;
	int i=0, contador=0;
	
	while(contador<tl && i<=3){
		if(nombre[contador]>=0 && nombre[contador]<=9){
			i++;
		}
		contador++;
	}
	
	if(i<=3){
		valido=true;
	}
	return valido;
}
	
bool caracterPass(char contra[PASS], int tl){
	bool valido=false;
	int aux=0;
	char i;
		
	while(valido==false && aux<tl){
		i = tolower(contra[aux]);
		
		if(isalnum(i)!=0 && i != 160 && i != 130 && i !=161 
			&& i !=162 && i !=163){
			aux++;
		}else valido = true;
	}
		
	return valido;
}

bool Mayus(char contra[PASS], int tl){
	bool valido=false;
	int aux=0;
	
	while(valido==false && aux<tl){
		if(contra[aux]>=65 && contra[aux]<=90){
		valido=true;
		}else aux++;
	}
	
	return valido;
}

bool Minim(char contra[PASS], int tl){
	bool valido=false;
	int aux=0;
				
	while(valido==false && aux<tl){
		if(contra[aux]>=97 && contra[aux]<=122){
			valido=true;
		}else aux++;
	}
	
	return valido;
}

bool Num(char contra[PASS], int tl){
	bool valido=false;
	int aux=0;
	
	while(valido==false && aux<tl){
		if(contra[aux]>=48 && contra[aux]<=57){
			valido=true;
		}else aux++;
	}
	
	return valido;
}	


void cifrar_texto(char text[]){
	int longitud=0;
	longitud = strlen(text);
		
	//cambia las letras por 3 ubicaciones mas adelante
	for(int i=0; i<longitud; i++){
		if((text[i]>=65 && text[i]<=90) || (text[i]>=97 && text[i]<=122)){
			text[i]+=3;
		}
	}
	
	invertir(text, longitud);
		
	for(int i=longitud/2; i<longitud; i++){
		text[i]--;
	}
	
}
void invertir(char text[], int tam){
	int aux;
	for(int i=0; i<tam/2; i++){
		aux = text[i];
		text[i] = text[tam-i-1];
		text[tam-i-1] = aux;
	}
}	
