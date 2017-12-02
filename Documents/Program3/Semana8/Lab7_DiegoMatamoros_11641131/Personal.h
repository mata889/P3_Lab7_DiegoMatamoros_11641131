#ifndef PERSONAL_H
#define PERSONAL_H
#include "Usuario.h"

class Personal:public Usuario{
private:
	string contratacion;
	int sueldo;
public:
	Personal(string,int,string,string,string,string,string,string);
	Personal();
	string getContratacion();
	int getSueldo();

	void setContratacion(string);
	void setSueldo(int);

	virtual~Personal();
};
#endif
