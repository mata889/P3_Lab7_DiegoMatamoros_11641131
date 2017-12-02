#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
using namespace std;

class Usuario{
private:
	string nombre,edad,id,numero,username,password;
public:
	Usuario();
	Usuario(string,string,string,string,string,string);
	//get
	string getNombre();
	string getEdad();
	string getId();
	string getNumero();
	string getUsername();
	string getPassword();
	//set
	void setNombre(string);
	void setEdad(string);
	void setId(string);
	void setNumero(string);
	void setUsername(string);
	void setPassword(string);

	~Usuario();
};
#endif
