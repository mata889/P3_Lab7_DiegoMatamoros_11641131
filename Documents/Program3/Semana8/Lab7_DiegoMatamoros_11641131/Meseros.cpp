#include "Meseros.h"

Meseros::Meseros(){
	vector<string*>platillos;
}
vector<string*> Meseros::getPlatillos(){
	return platillos;
}
void Meseros::setPlatillos(vector<string*>pPlatillos){
	pPlatillos=platillos;
}
Meseros::~Meseros(){

}
