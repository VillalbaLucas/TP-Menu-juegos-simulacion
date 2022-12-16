#ifndef ACCIONES_H
#define ACCIONES_H
#define USER 20
#define PASS 40

//usuario
bool caracteresPerm(char[USER], int);
bool mayusculas(char[USER], int);
bool numeros(char[USER], int);

//contraseña
bool caracterPass(char [PASS], int);
bool Mayus(char[PASS], int);
bool Minim(char[PASS], int);
bool Num(char[PASS], int);

//cifrado
void cifrar_texto(char[]);

#endif
