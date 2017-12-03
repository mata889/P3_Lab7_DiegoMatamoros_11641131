#include "Usuario.h"

using namespace std;

Usuario::Usuario(){//string nombre,edad,id,numero,username,password;
	this->nombre="";
	this->edad="";
	this->id="";
	this->numero="";
	this->username="";
	this->password="";
}
Usuario::Usuario(string pNombre,string pEdad,string pId,string pNumero,string pUsername,string pPassword){
	nombre=pNombre;
	edad=pEdad;
	id=pId;
	numero=pNombre;
	username=pUsername;
	password=pPassword;
}

string Usuario::getNombre(){
	return nombre;
}
string Usuario::getEdad(){
	return edad;
}
string Usuario::getId(){
	return id;
}
string Usuario::getNumero(){
	return numero;
}
string Usuario::getPassword(){
	return password;
}
string Usuario::getUsername(){
	return username;
}
void Usuario::setNombre(string pNombre){
	pNombre=nombre;
}
void Usuario::setEdad(string pEdad){
	pEdad=edad;
}
void Usuario::setId(string pId){
	pId=id;
}
void Usuario::setNumero(string pNumero){
	pNumero=numero;
}
void Usuario::setUsername(string pUsername){
	pUsername=username;
}
void Usuario::setPassword(string pPassword){
	pPassword=password;
}
Usuario::~Usuario(){
	
}
