#include "Chef.h"
#include "Personal.h"
using namespace std;

Chef::Chef(){
	this->PlatoFavorito="";
}
Chef::Chef(string username ,string password,string nombre ,string edad ,string id,string numero,string contratacion,int sueldo,string pPlatoFavorito):Personal(username, password, nombre, edad, id, numero, contratacion, sueldo){
	PlatoFavorito=pPlatoFavorito;
}
string Chef::getPlatoFavorito(){
	return PlatoFavorito;
}
void Chef::setPlatoFavorito(string pPlatoFavorito){
	pPlatoFavorito=PlatoFavorito;
}
Chef::~Chef(){
	
}
