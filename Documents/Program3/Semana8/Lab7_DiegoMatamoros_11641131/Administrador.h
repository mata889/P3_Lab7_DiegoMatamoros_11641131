#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

#include "Personal.h"

using namespace std;

class Administrador:public Personal{
private:
	int contratados, despedidos;

public:
	Administrador(int, int, string, int);
	Administrador();

	int getContratados();
	int getDespedidos();

	void setContratados(int);
	void setDespedidos(int);

	virtual ~Administrador();

};
#endif
