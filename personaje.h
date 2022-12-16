#define tam 10
#include "stdpanel.h"
#include <string>
using namespace std;

struct Personaje{
	string nombre;
	char apariencia;
	int posicion;
	char orientacion;
	bool vertigo=false;
};

void crearP(Personaje &p, string, char);
void mostrarP(Personaje &p);
void saludar(Personaje);
void caminar(Personaje &p, char tabl[][MAXIMO], int&);
void saltarEscalar(Personaje &p, int alt, int&);
void girar(Personaje &p);
void bajar(Personaje &p, char tabl[][MAXIMO]);
void bros(Personaje &p, char tabl[][MAXIMO]);
