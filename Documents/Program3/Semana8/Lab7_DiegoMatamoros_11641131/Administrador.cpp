#include "Personal.h"
#include "Administrador.h"
#include <iostream>
#include <string>
using namespace std;

Administrador::Administrador(){
	this->contratados = 0;
	this->despedidos = 0;
}
//string pusername ,string ppassword,string pnombre ,int pedad ,string pid,string pnumero,string pyear,double psueldo,int pcontratados,int pdespedidos):Personal(pusername,ppassword,pnombre,pedad,pid,pnumero,pyear,psueldo
Administrador::Administrador(string username ,string password,string nombre ,string edad ,string id,string numero,string contratacion,int sueldo,int pContratados,int pDespedidos):Personal( username, password, nombre, edad, id, numero, contratacion, sueldo){
	contratados =pContratados;
	despedidos =pDespedidos;
}


int Administrador::getContratados(){
	return contratados;
}

int Administrador::getDespedidos(){
	return despedidos;
}

void Administrador::setContratados(int pContratados){
	contratados =pContratados;
}

void Administrador::setDespedidos(int pDespedidos){
	despedidos =pDespedidos;
}
Administrador::~Administrador(){

}
