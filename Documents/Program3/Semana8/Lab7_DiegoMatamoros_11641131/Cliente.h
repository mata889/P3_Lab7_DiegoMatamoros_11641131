#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>

class Cliente:public Usuario{
private:
	string direccion,numeral;
public:
	Cliente();
	Cliente(string, string,string,string,string,string,string,string);
	string getDireccion();
	string getNumeral();


	void setDireccion(string);
	void setNumeral(string);


	~Cliente();
};
#endif
