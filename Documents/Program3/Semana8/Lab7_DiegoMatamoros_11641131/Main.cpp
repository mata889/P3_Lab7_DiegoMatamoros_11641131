#include "Administrador.h"
#include "Chef.h"
#include "Cliente.h"
#include "Lavaplatos.h"
#include "Meseros.h"
#include "Personal.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//primero guardar archivos, despues analizar si se guardaron __registrar administradores y login
int main(){
int menu;
do {
	cout<<"1.CrearAdministrar \n2.LoginUsurio\n0.salir"<<endl;
	cin>>menu;
	if (menu==1) {
		vector<Usuario*>crear;
	}
	else if (menu==2) {

	}else{
		cout<<"Introdujo algo mal"<<endl;
	}
} while(menu!=0);

return 0;
}
