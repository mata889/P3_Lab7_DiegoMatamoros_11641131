#ifndef MESEROS_H
#define MESEROS_H

#include <string>
#include <vector>

#include "Personal.h"

class Meseros:public Personal{
private:
	vector<string*> platillos;
public:
	Meseros();
	Meseros(string ,int,vector<string*>);

	vector <string*> getPlatillos();

	void setPlatillos(vector<string*>);

	virtual ~Meseros();
};
#endif
