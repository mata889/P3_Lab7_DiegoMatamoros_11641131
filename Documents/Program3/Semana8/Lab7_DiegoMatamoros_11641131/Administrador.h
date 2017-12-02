#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

class Administrador:public Personal{
private:
	vector<Personal>contratados;
	vector<Personal>despedidos;

public:
	Administrador(string, string);
	Administrador();

	vector<Personal> getContratados();
	vector<Personal> getDespedidos();

	void setContratados(vector<Personal>);
	void setDespedidos(vector<Personal>);

	virtual ~Administrador();

};
#endif
