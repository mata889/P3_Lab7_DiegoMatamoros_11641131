#include "Lavaplatos.h"
#include "Personal.h"

Lavaplatos::Lavaplatos(){
	this->motivacion=0;
}
Lavaplatos::Lavaplatos(string username ,string password,string nombre ,string edad ,string id,string numero,string contratacion,int sueldo,double pMotivacion):Personal(username, password, nombre, edad, id, numero, contratacion, sueldo){
	motivacion=pMotivacion;
}
double Lavaplatos::getMotivacion(){
	return motivacion;
}
void Lavaplatos::setMotivacion(double pMotivacion){
	pMotivacion=motivacion;
}
Lavaplatos::~Lavaplatos(){
	
}
