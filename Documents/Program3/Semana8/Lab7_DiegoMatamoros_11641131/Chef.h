#ifndef CHEF_H
#define CHEF_H

#include <string>
#include "Personal.h"

class Chef:public Personal{
private:
	string PlatoFavorito;
public:
	Chef();
	Chef(string,string,int);
	string getPlatoFavorito();
	void setPlatoFavorito(string);

	virtual~Chef();
};
#endif
