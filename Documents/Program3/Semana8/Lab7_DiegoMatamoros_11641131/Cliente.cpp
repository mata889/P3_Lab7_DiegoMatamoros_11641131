#include "Cliente.h"
#include "Usuario.h"
Cliente::Cliente(){
	this->direccion	="";
	this->numeral=0;
}
Cliente::Cliente(string username ,string password,string nombre ,string edad ,string id,string numero,string pDireccion,int pNumeral):Usuario(nombre,edad,id,numero,username,password){
	direccion=pDireccion;
	numeral=pNumeral;
}
string Cliente::getDireccion(){
	return direccion;
}
int Cliente::getNumeral(){
	return numeral;
}
void Cliente::setDireccion(string pDireccion){
	pDireccion=direccion;
}
void Cliente::setNumeral(int pNumeral){
	pNumeral=numeral;
}
Cliente::~Cliente(){

}
