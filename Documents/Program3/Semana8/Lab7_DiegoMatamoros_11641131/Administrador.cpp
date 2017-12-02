#include "Personal.h"
#include "Administrador.h"
#include <iostream>
#include <string>
using namespace std;

Administrador::Administrador(){
	this->contratados = 0;
	this->despedidos = 0;
}

Administrador::Administrador(int pContratados, int pDespedidos, string fecha, int sueldo):Personal(fecha, sueldo, nombre, edad, id, numero, username, password){
	contratados =pContratados;
	despedidos =pDespedidos;
}


int Administrador::getContratados(){
	return contratados;
}

int Administrador::getDespedidos(){
	return despedidos;
}

void Administrador::setContratados(int pContratados){
	contratados =pContratados;
}

void Administrador::setDespedidos(int pDespedidos){
	despedidos =pDespedidos;
}

Administrador::~Administrador(){
}
