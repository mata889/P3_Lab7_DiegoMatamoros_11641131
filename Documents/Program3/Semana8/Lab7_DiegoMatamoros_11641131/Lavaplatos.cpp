#include "Lavaplatos.h"
#include "Personal.h"

Lavaplatos::Lavaplatos(){
	this->motivacion=50.0;
}
Lavaplatos::Lavaplatos(double pMotivacion,string fecha, int sueldo):Personal(fecha, sueldo, nombre, edad, id, numero, username, password){
	pMotivacion=motivacion;
}
double Lavaplatos::getMotivacion(){
	return motivacion;
}
void Lavaplatos::setMotivacion(double pMotivacion){
	pMotivacion=motivacion;
}
Lavaplatos::~Lavaplatos(){

}
