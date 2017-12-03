#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>

class Cliente:public Usuario{
private:
	string direccion;
	int numeral;
public:
	Cliente();
	Cliente(string, string,string,string,string,string,string,int);
	string getDireccion();
	int getNumeral();


	void setDireccion(string);
	void setNumeral(int);


	virtual~Cliente();
};
#endif
