#include "Meseros.h"

Meseros::Meseros(){
	vector<string>platillos;
}
Meseros::Meseros(string username ,string password,string nombre ,string edad ,string id,string numero,string contratacion,int sueldo):Personal(username, password, nombre, edad, id, numero, contratacion, sueldo){

}
vector<string> Meseros::getPlatillos(){
	return platillos;
}
void Meseros::setPlatillos(vector<string>pPlatillos){
	pPlatillos=platillos;
}
Meseros::~Meseros(){

}
