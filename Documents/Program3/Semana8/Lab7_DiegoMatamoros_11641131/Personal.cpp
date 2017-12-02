#include "Personal.h"
#include "Usuario.h"

Personal::Personal(){
	this->contratacion="";
	this->sueldo=0;
}
Personal::Personal(string pContratacion,int pSueldo,string nombre,string edad,string id,string numero,string username,string password):Usuario(nombre,edad,id,numero,username,password){
	pContratacion=contratacion;
	pSueldo=sueldo;
}
string Personal::getContratacion(){
	return contratacion;
}
int Personal::getSueldo(){
	return sueldo;
}
void Personal::setContratacion(string pContratacion){
	pContratacion=contratacion;
}
void Personal::setSueldo(int pSueldo){
	pSueldo=sueldo;
}
