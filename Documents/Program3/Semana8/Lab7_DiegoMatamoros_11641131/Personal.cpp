#include "Personal.h"
#include "Usuario.h"

Personal::Personal(){
	this->contratacion="";
	this->sueldo=0;
}
Personal::Personal(string username,string password,string nombre,string edad,string id,string numero,string pContratacion,int pSueldo):Usuario(nombre,edad,id,numero,username,password){
	contratacion=pContratacion;
	sueldo=pSueldo;
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
Personal::~Personal(){
	
}
