#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
#include <string>
#include "Personal.h"

class Lavaplatos:public Personal{
private:
	double motivacion;
public:
	Lavaplatos();
	Lavaplatos(string,string,string,string,string,string,string,int,double);
	double getMotivacion();
	void setMotivacion(double);

	virtual~Lavaplatos();
};
#endif
