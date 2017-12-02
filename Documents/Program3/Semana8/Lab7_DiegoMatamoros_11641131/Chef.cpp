#include "Chef.h"
#include "Personal.h"
using namespace std;

Chef::Chef(){
	this->PlatoFavorito="";
}
Chef::Chef(string pPlatoFavorito,string fecha, int sueldo):Personal(fecha, sueldo, nombre, edad, id, numero, username, password){
	pPlatoFavorito=PlatoFavorito;
}
string Chef::getPlatoFavorito(){
	return PlatoFavorito;
}
void Chef::setPlatoFavorito(string pPlatoFavorito){
	pPlatoFavorito=PlatoFavorito;
}

Chef::~Chef(){

}
