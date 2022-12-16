#ifndef REGISTRO_H
#define REGISTRO_H
#define USER 20
#define PASS 40

struct Fecha{
	int dia, mes, anio;
};

struct Usuarios{
	char user[USER];
	char password[PASS];
	Fecha ultSesion;
};

void menuacceso();
bool registrar();
bool iniciar();
void iniFecha(Usuarios &usu);
#endif
