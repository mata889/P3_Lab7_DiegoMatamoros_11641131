#ifndef PERSONAL_H
#define PERSONAL_H
#include "Usuario.h"

class Personal:public Usuario{
private:
	string contratacion;
	int sueldo;
public:
	Personal(string ,string ,string ,string ,string ,string ,string ,int );
	Personal();
	string getContratacion();
	int getSueldo();

	void setContratacion(string);
	void setSueldo(int);

	virtual~Personal();
};
#endif
//string pusername ,string ppassword,string pnombre ,int pedad ,string pid,string pnumero,string pyear,double psueldo,int pcontratados,int pdespedidos):Personal(pusername,ppassword,pnombre,pedad,pid,pnumero,pyear,psueldo
