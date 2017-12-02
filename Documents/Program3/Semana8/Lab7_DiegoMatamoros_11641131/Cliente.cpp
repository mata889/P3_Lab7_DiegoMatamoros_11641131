#include "Cliente.h"
#include "Usuario.h"
Cliente::Cliente(){
	this->direccion	="";
	this->numeral="";
}
Cliente::Cliente(string pDireccion,string pNumeral,string nombre,string edad,string id,string numero,string username,string password):Usuario(nombre,edad,id,numero,username,password){
	pDireccion=direccion;
	pNumeral=numeral;
}
string Cliente::getDireccion(){
	return direccion;
}
string Cliente::getNumeral(){
	return numeral;
}
void Cliente::setDireccion(string pDireccion){
	pDireccion=direccion;
}
void Cliente::setNumeral(string pNumeral){
	pNumeral=numeral;
}
