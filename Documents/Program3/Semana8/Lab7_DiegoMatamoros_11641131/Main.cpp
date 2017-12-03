#include "Administrador.h"
#include "Chef.h"
#include "Cliente.h"
#include "Lavaplatos.h"
#include "Meseros.h"
#include "Personal.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

vector<Usuario*> Contratar(vector<Usuario*>,Usuario*);
vector<Usuario*> Despedir(vector<Usuario*>,Usuario*);
string menorSueldo(vector<Usuario*> );
Meseros* agregarPlato(vector<Usuario*> ,int );
string mayorSueldo(vector<Usuario*> );
double promedioSuedlo(vector<Usuario*> );
void EscribirArchivo(vector<Usuario*> );
vector<Usuario*> leer();
//primero guardar archivos, despues analizar si se guardaron __registrar administradores y login
int main(){

	int menu;
	vector<Usuario*>lista;
	lista=leer();
	Usuario* actual;
	do {

		int sueldo;
		string nombre,edad,id,numero,username,password,fecha;
		cout<<"1.CrearAdministrador \n2.LoginUsuario\n3.EscribirTodoEnArchivo\n0.salir"<<endl;
		cin>>menu;
		if (menu==1) {
			//Personal(fecha, sueldo, nombre, edad, id, numero, username, password)

			cout<<"Introduzca su nombre"<<endl;
			cin>>nombre;
			cout<<"Introduzca su edad"<<endl;
			cin>>edad;
			cout<<"Introduzca su id"<<endl;
			cin>>id;
			cout<<"Introduzca su username"<<endl;
			cin>>username;
			cout<<"Introduzca su password"<<endl;
			cin>>password;
			cout<<"Introduzca su fecha"<<endl;
			cin>>fecha;
			cout<<"Introduzca su numero"<<endl;
			cin>>numero;


			bool entro=false;
			while (entro==false) {
				cout<<"Introduzca su sueldo"<<endl;
				cin>>sueldo;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					entro=false;
				}else{
					entro=true;
				}
			}
			//cout<<"Username:"<<username<<"."<<endl;
			Usuario* persona=new Administrador(username,password,nombre,edad,id,numero,fecha,sueldo,0,0);
			lista.push_back(persona);
			//cout<<"Usuario:"<<lista.at(0)->getUsername()<<endl;
			//cout<<"Usuario:"<<lista.at(0)->getNumero()<<endl;
			//cout<<"Usuario:"<<lista.at(0)->getEdad()<<endl;
			//cout<<"Usuario:"<<lista.at(0)->getPassword()<<endl;
		}
		else if (menu==2) {
			string LoginUsuario,LoginPass;
			cout<<"Introduzca su Usuario"<<endl;
			cin>>LoginUsuario;
			cout<<"Introduzca su password"<<endl;
			cin>>LoginPass;
			//cout<<"Usuario:"<<lista.at(0)->getUsername()<<endl;
			for (int i = 0; i < lista.size(); i++) {
				if (lista.at(i)->getUsername()==LoginUsuario) {
					//cout<<"entrousu"<<endl;
					if (lista.at(i)->getPassword()==LoginPass) {
						cout<<"Ha entrado:"<<LoginUsuario<<endl;
						actual=lista.at(i);
						//viendo que tipo de usuarios son
						if (dynamic_cast<Administrador*>(actual)) {
							int opcionAdmi;
							cout<<"1.Contratar a alguien\n2.despedir\n3.empleado con el sueldo mas bajo\n4.Agregar plato\n5.Conseguir Empleado con mayor sueldo\n6.PromedioDelSueldo"<<endl;
							cin>>opcionAdmi;
							switch (opcionAdmi) {
								case 1:{//contratar
									lista=Contratar(lista,actual);
									int cont=1;
									dynamic_cast<Administrador*>(actual)->setContratados(dynamic_cast<Administrador*>(actual)->getContratados()+cont);
								}break;
								case 2:{//despedir
									lista=Despedir(lista,actual);
									//int cont=1;
									//actual->setDespedidos(cont);
								}break;
								case 3:{//menorsueldo
									string menorsueldo;
									menorsueldo=menorSueldo(lista);
									cout<<"Menor SUeldo:"<<menorsueldo<<endl;
								}break;
								case 4:{//agregar plato
									int donde;
									string platillo;
									for (int i = 0; i < lista.size(); i++) {//listando meseros
										if (dynamic_cast<Meseros*>(lista.at(i))) {
											cout<<i<<"-- "<<lista.at(i)->getNombre()<<endl;
										}
									}

									cout<<"ingrese a quien desea agregar: ";
									cin>>donde;
									cout<<"nombre del plato: ";
									cin>>platillo;
									Meseros* amigo=dynamic_cast<Meseros*>(lista.at(donde));
									amigo->getPlatillos().push_back(platillo);
								}break;
								case 5:{//mayor sueldo
									string MayorSueldo;
									MayorSueldo=mayorSueldo(lista);
									cout<<"mayorSueldo::"<<MayorSueldo<<endl;//imprimiendo sueldos
								}break;
								case 6:{//PromedioDelSueldo
									double promedio;
									promedio=promedioSuedlo(lista);
									cout<<"EL PROMEdio es:"<<promedio<<endl;
								}break;
							}
						}else if (dynamic_cast<Meseros*>(actual)) {
							int opcion;
							cout<<"1.DejarUnPlato\n2.DejarTodosLosPlatos\nIngrese Opcion"<<endl;
							cin>>opcion;
							switch (opcion) {
								case 1:{
									vector<string>platos;
									platos=dynamic_cast<Meseros*>(actual)->getPlatillos();
									for (size_t i = 0; i < platos.size(); i++) {
										cout<<"["<<i<<"]"<<platos.at(i)<<endl;
									}
									int opPlato;
									cout<<"Introduzca el numero plato"<<endl;
									cin>>opPlato;
									platos.erase(platos.begin()+opPlato);
								}break;
								case 2:{
									vector<string>platos;
									platos=dynamic_cast<Meseros*>(actual)->getPlatillos();
									for (size_t i = 0; i < platos.size(); i++) {
										platos.erase(platos.begin()+i);
									}
								}break;
							}
						}else if (dynamic_cast<Cliente*>(actual)) {
							int conta = 0,acum= 0;
							for (int i = 0; i < lista.size(); i++) {
								if (dynamic_cast<Cliente*>(lista.at(i))) {
									Cliente* temp = dynamic_cast<Cliente*>(lista.at(i));
									acum+=temp->getNumeral();
									conta++;
								}
							}
							cout<<"EL promedio es:"<<(acum/conta)<<endl;
						}else if (dynamic_cast<Lavaplatos*>(actual)) {
							int opLava;
							cout<<"1.PuedeRenunciar\n2.PuedePedirAumento\n escoja "<<endl;
							cin>>opLava;
							switch (opLava) {
								case 1:{
									Lavaplatos* pobrecito=dynamic_cast<Lavaplatos*>(actual);
									if (pobrecito->getMotivacion()<=25) {
										for (size_t i = 0; i < lista.size(); i++) {
											Usuario* f = dynamic_cast<Lavaplatos*>(lista.at(i));
											if(dynamic_cast<Lavaplatos*>(lista.at(i)) &&  actual->getId() == f->getId()){
												lista.erase(lista.begin()+i);
											}
										}
									}else{
										cout<<"Hermano Brother no puedo renunciar, aguantela"<<endl;
									}
								}break;
								case 2:{
									Lavaplatos* pobrecito=dynamic_cast<Lavaplatos*>(actual);
									if (pobrecito->getMotivacion()>=100) {
										int aumento;
										cout<<"Ingrese su aumento"<<endl;
										cin>>aumento;
										for (size_t i = 0; i < lista.size(); i++) {
											Usuario* crack = dynamic_cast<Lavaplatos*>(lista.at(i));
											if(dynamic_cast<Lavaplatos*>(lista.at(i)) &&  actual->getId() == crack->getId()){
												dynamic_cast<Personal*>(lista.at(i))->setSueldo(  dynamic_cast<Personal*>(lista.at(i))->getSueldo()+aumento);
											}
										}
									}
								}break;
							}
						}else if(dynamic_cast<Chef*>(actual)){
							int opChef;
							cout<<"1.Gritar\n2.agradecer\nINTRODUZCA LA OPCION"<<endl;
							cin>>opChef;
							switch (opChef) {
								case 1:{
									int cont=0;
									for (size_t i = 0; i < lista.size(); i++) {
										if (dynamic_cast<Lavaplatos*>(lista.at(i))) {
											cout<<i<<") "<<lista.at(i)->getNombre()<<endl;
											cont++;
										}
									}
									if (cont>0) {

										int Quien,dolor;
										cout<<"Escoja a quien gritar"<<endl;
										cin>>Quien;
										cout<<"Que tanto lo quiere sentir como un insecto"<<endl;
										cin>>dolor;
										Lavaplatos* Pobre = dynamic_cast<Lavaplatos*>(lista.at(Quien));
										Pobre->setMotivacion(Pobre->getMotivacion()-dolor);
									}else{
										cout<<"No hay nadie a quien gritar"<<endl;
									}

								}break;
								case 2:{
									int cont=0;
									for (size_t i = 0; i < lista.size(); i++) {
										if (dynamic_cast<Lavaplatos*>(lista.at(i))) {
											cout<<i<<") "<<lista.at(i)->getNombre()<<endl;
											cont++;
										}
									}
									if (cont>0) {

										int Quien,amor;
										cout<<"Escoja a quien le quiere decir gracias por primera vez"<<endl;
										cin>>Quien;
										cout<<"Que tanto lo quiere sentir como un CRACK #cuchao"<<endl;
										cin>>amor;
										Lavaplatos* Crack = dynamic_cast<Lavaplatos*>(lista.at(Quien));
										Crack->setMotivacion(Crack->getMotivacion()+amor);
									}else{
										cout<<"No hay nadie a quien agradecer"<<endl;
									}

								}break;

							}

						}
					}else{
						cout<<"No ha podido entrar"<<endl;
					}
				}
			}
		}else if(menu ==3){
			if (lista.size()>0) {
				EscribirArchivo(lista);
				cout<<"Se ha guardado el archivo"<<endl;
			}else{
				cout<<"no hay nada que guardar"<<endl;
			}

		}
	} while(menu!=0);

	return 0;
}


vector<Usuario*>Contratar(vector<Usuario*>lista,Usuario* act){
	string username,password,nombre,id,numero,edad;
	cout<<" "<<endl;
	cout<<"Ingrese usuario"<<endl;
	cin>>username;
	cout<<"Ingrese password"<<endl;
	cin>>password;
	cout<<"Ingrese Nombre"<<endl;
	cin>>nombre;
	cout<<"Ingrese Id"<<endl;
	cin>>id;
	cout<<"ingrese numero telefonico"<<endl;
	cin>>numero;
	cout<<"ingrese edad"<<endl;
	cin>>edad;
	int menuContra;
	cout<<"____Escoja!!!\n1.Cliente\n2.Administrador\n3.chef\n4.Mesero\n5.Lavaplatos"<<endl;
	cin>>menuContra;
	switch (menuContra) {
		case 1:{//string pDireccion,int pNumeral
			string direccion;
			int numeral;
			cout<<"Introduzca direccion"<<endl;
			cin>>direccion;
			cout<<"Introduzca su calificacion sobre el restaurante brother"<<endl;
			cin>>numeral;
			while (numeral<=0 || numeral>=6) {
				cout<<"Introduzca su calificacion sobre el restaurante brother"<<endl;
				cin>>numeral;
			}
			//string username ,string password,string nombre ,string edad ,string id,string numero,string pDireccion,int pNumeral
			lista.push_back(new Cliente(username,password,nombre,edad,id,numero,direccion,numeral));
		}break;
		case 2:{//Administrador(username,password,nombre,edad,id,numero,fecha,sueldo,0,0)
			string fecha;
			int sueldo;
			cout<<"ingrese la fecha en que empezo a trabajar"<<endl;
			cin>>fecha;
			cout<<"ingrese sueldo"<<endl;
			cin>>sueldo;
			lista.push_back(new Administrador(username,password,nombre,edad,id,numero,fecha,sueldo,0,0));
		}break;
		case 3:{//string username ,string password,string nombre ,string edad ,string id,string numero,string contratacion,int sueldo,string pPlatoFavorito
			string contratacion,PlatoFavorito;
			int sueldo;
			cout<<"ano de contratacion"<<endl;
			cin>>contratacion;
			cout<<"PlatoFavorito???"<<endl;
			cin>>PlatoFavorito;
			cout<<"Ingrese sueldo"<<endl;
			cin>>sueldo;
			lista.push_back(new Chef( username , password, nombre , edad , id, numero, contratacion, sueldo, PlatoFavorito));
		}break;
		case 4:{
			string fecha;
			int sueldo;
			cout<<"ingrese fecha en que empezo a jugar"<<endl;
			cin>>fecha;
			cout<<"ingrese su sueldo"<<endl;
			cin>>sueldo;
			lista.push_back(new Meseros(username , password, nombre , edad , id, numero, fecha, sueldo));
		}break;
		case 5:{
			string fecha;
			int sueldo;
			cout<<"ingrese fecha en que empezo a jugar"<<endl;
			cin>>fecha;
			cout<<"ingrese su sueldo"<<endl;
			cin>>sueldo;
			lista.push_back(new Lavaplatos(username , password, nombre , edad , id, numero, fecha, sueldo,50));
		}break;
	}
	return lista;
}


vector<Usuario*> Despedir(vector <Usuario*> lista, Usuario* act){
	for (int i = 0; i < lista.size(); i++) {
		if (dynamic_cast<Personal*>(lista.at(i))) {
			cout<<i<<") "<<lista.at(i)->getNombre()<<endl;
		}
	}
	int eso;
	cout<<"Cual desea eliminiar: ";
	cin>>eso;
	lista.erase(lista.begin()+eso);
	dynamic_cast<Administrador*>(act)->setDespedidos(dynamic_cast<Administrador*>(act)->getDespedidos()+1);
	return lista;
}

string menorSueldo(vector<Usuario*> lista){
	vector<Usuario*> menor;
	string persona;
	Personal* aux;

	int low = 200000000;
	for (int i = 0; i < lista.size(); i++) {
		if (dynamic_cast<Personal*>(lista.at(i))) {
			aux = dynamic_cast<Personal*>(lista.at(i));
			if (aux->getSueldo() < low) {
				menor.push_back(aux);
				low = aux->getSueldo();
			}
		}
	}
	for (int i = 0; i < menor.size(); i++) {
		persona+=menor.at(i)->getNombre();
		persona+="->";
		delete menor.at(i);
	}
	return persona;
}

Meseros* agregarPlato(vector<Usuario*> lista,int donde){

	Meseros* d = dynamic_cast<Meseros*>(lista.at(donde));
	return d;

}

string mayorSueldo(vector<Usuario*> lista){
	vector<Usuario*> mayor;
	int alto = 0;
	string personas;
	Personal* aux;

	for (int i = 0; i < lista.size(); i++) {
		if (dynamic_cast<Personal*>(lista.at(i))) {
			aux = dynamic_cast<Personal*>(lista.at(i));
			if (aux->getSueldo() > alto) {
				mayor.push_back(aux);
				alto = aux->getSueldo();
			}
		}
	}

	for (int i = 0; i < mayor.size(); i++) {
		personas+=mayor.at(i)->getNombre();
		personas+="->";
		delete mayor.at(i);
	}
	return personas;
}

double promedioSuedlo(vector<Usuario*> lista){
	int acumulador=0,contador=0;
	for (int i = 0; i < lista.size(); i++) {
		if (dynamic_cast<Personal*>(lista.at(i))) {
			acumulador+=dynamic_cast<Personal*>(lista.at(i))->getSueldo();
			contador++;
		}
	}
	int promedioSueldo=(acumulador/contador);
	return promedioSueldo;
}

void EscribirArchivo(vector<Usuario*> lista){
	Usuario* actual;
	ofstream afile("restaurante.txt");
	if (afile.is_open()) {
		for (size_t i = 0; i < lista.size(); i++) {
			actual=lista.at(i);
			if (dynamic_cast<Administrador*>(actual)) {//username,password,nombre,edad,id,numero,fecha,sueldo,0,0
				char a='A';
				string archivo;
				Administrador* admi=dynamic_cast<Administrador*>(actual);
				string username,password,nombre,edad,id,numero,fecha;
				int sueldo,contratacion,despedidos;
				username=admi->getUsername();
				password=admi->getPassword();
				nombre=admi->getNombre();
				edad=admi->getEdad();
				id=admi->getId();
				numero=admi->getNumero();
				fecha=admi->getContratacion();
				sueldo=admi->getSueldo();
				contratacion=admi->getContratados();
				despedidos=admi->getDespedidos();
				archivo+=a;
				archivo+=",";
				archivo+=username;
				archivo+=",";
				archivo+=password;
				archivo+=",";
				archivo+=nombre;
				archivo+=",";
				archivo+=edad;
				archivo+=",";
				archivo+=id;
				archivo+=",";
				archivo+=numero;
				archivo+=",";
				archivo+=fecha;
				archivo+=",";
				archivo+=to_string(sueldo);
				archivo+=",";
				archivo+=to_string(contratacion);
				archivo+=",";
				archivo+=to_string(despedidos);
				archivo+=";";
				afile<<archivo;
			}
			else if (dynamic_cast<Chef*>(actual)) {//username , password, nombre , edad , id, numero, contratacion, sueldo, PlatoFavorito
				string archivo;
				char c='C';
				string username,password,nombre,edad,id,numero,fecha,PlatoFavorito;
				int sueldo;
				Chef* chef=dynamic_cast<Chef*>(actual);
				username=chef->getUsername();
				password=chef->getPassword();
				nombre=chef->getNombre();
				edad=chef->getEdad();
				id=chef->getId();
				numero=chef->getNumero();
				fecha=chef->getContratacion();
				sueldo=chef->getSueldo();
				PlatoFavorito=chef->getPlatoFavorito();

				archivo+=c;
				archivo+=",";
				archivo+=username;
				archivo+=",";
				archivo+=password;
				archivo+=",";
				archivo+=nombre;
				archivo+=",";
				archivo+=edad;
				archivo+=",";
				archivo+=id;
				archivo+=",";
				archivo+=numero;
				archivo+=",";
				archivo+=fecha;
				archivo+=",";
				archivo+=to_string(sueldo);
				archivo+=",";
				archivo+=PlatoFavorito;
				archivo+=";";
				afile<<archivo;
			}
			else if (dynamic_cast<Lavaplatos*>(actual)) {
				string archivo;
				char l='L';
				string username,password,nombre,edad,id,numero,fecha;
				int sueldo;
				double motivacion;
				Lavaplatos* lava=dynamic_cast<Lavaplatos*>(actual);
				username=lava->getUsername();
				password=lava->getPassword();
				nombre=lava->getNombre();
				edad=lava->getEdad();
				id=lava->getId();
				numero=lava->getNumero();
				fecha=lava->getContratacion();
				sueldo=lava->getSueldo();
				motivacion=lava->getMotivacion();

				archivo+=l;
				archivo+=",";
				archivo+=username;
				archivo+=",";
				archivo+=password;
				archivo+=",";
				archivo+=nombre;
				archivo+=",";
				archivo+=edad;
				archivo+=",";
				archivo+=id;
				archivo+=",";
				archivo+=numero;
				archivo+=",";
				archivo+=fecha;
				archivo+=",";
				archivo+=to_string(sueldo);
				archivo+=",";
				archivo+=to_string(motivacion);
				archivo+=";";
				afile<<archivo;

			}
			else if (dynamic_cast<Meseros*>(actual)) {//Meseros(username , password, nombre , edad , id, numero, fecha, sueldo)
				string archivo;
				char m='M';
				string username,password,nombre,edad,id,numero,fecha;
				int sueldo;
				Meseros* mes=dynamic_cast<Meseros*>(actual);
				username=mes->getUsername();
				password=mes->getPassword();
				nombre=mes->getNombre();
				edad=mes->getEdad();
				id=mes->getId();
				numero=mes->getNumero();
				fecha=mes->getContratacion();
				sueldo=mes->getSueldo();

				archivo+=m;
				archivo+=",";
				archivo+=username;
				archivo+=",";
				archivo+=password;
				archivo+=",";
				archivo+=nombre;
				archivo+=",";
				archivo+=edad;
				archivo+=",";
				archivo+=id;
				archivo+=",";
				archivo+=numero;
				archivo+=",";
				archivo+=fecha;
				archivo+=",";
				archivo+=to_string(sueldo);
				archivo+=";";
				afile<<archivo;

			}
			else if (dynamic_cast<Cliente*>(actual)) {//Cliente(username,password,nombre,edad,id,numero,direccion,numeral
				string archivo;
				char c='c';
				string username,password,nombre,edad,id,numero,direccion;
				int numeral;
				Cliente* cli=dynamic_cast<Cliente*>(actual);
				username=cli->getUsername();
				password=cli->getPassword();
				nombre=cli->getNombre();
				edad=cli->getEdad();
				id=cli->getId();
				numero=cli->getNumero();
				direccion=cli->getDireccion();
				numeral=cli->getNumeral();
				archivo+=c;
				archivo+=",";
				archivo+=username;
				archivo+=",";
				archivo+=password;
				archivo+=",";
				archivo+=nombre;
				archivo+=",";
				archivo+=edad;
				archivo+=",";
				archivo+=id;
				archivo+=",";
				archivo+=numero;
				archivo+=",";
				archivo+=direccion;
				archivo+=",";
				archivo+=to_string(numeral);
				archivo+=";";
				afile<<archivo;

			}
		}
		afile.close();
	}

}

vector<Usuario*> leer(){
  vector<Usuario*> lista;
  fstream file("restaurante.txt");
  if (file.is_open()) {
  while(!file.eof()){
    string line,tipo,user,pass,nombre,id,numero,edadS,fecha,salrioS;

    int salario;
    getline(file,tipo,',');
    if (tipo == "A") {
      int contra, desp;
      string contras,despes;
      getline(file,user,',');
      getline(file,pass,',');
      getline(file,nombre,',');
      getline(file,edadS,',');
      getline(file,id,',');
      getline(file,numero,',');
      getline(file,fecha,',');
      getline(file,salrioS,',');
      salario = stoi(salrioS);
      getline(file,contras,',');
      contra = stoi(contras);
      getline(file,despes,';');
      desp = stoi(despes);
      lista.push_back(new Administrador(user,pass,nombre,edadS,id,numero,fecha,salario,contra,desp));
    }

    if (tipo == "C") {
      string plato;
      getline(file,user,',');
      getline(file,pass,',');
      getline(file,nombre,',');
      getline(file,edadS,',');
      getline(file,id,',');
      getline(file,numero,',');
      getline(file,fecha,',');
      getline(file,salrioS,',');
      salario = stoi(salrioS);
      getline(file,plato,';');
      lista.push_back(new Chef(user,pass,nombre,edadS,id,numero,fecha,salario,plato));
    }


    if (tipo == "c") {
      string direccion,srate;
      int rate;
      getline(file,user,',');
      getline(file,pass,',');
      getline(file,nombre,',');
      getline(file,edadS,',');
      getline(file,id,',');
      getline(file,numero,',');
      getline(file,direccion,',');
      getline(file,srate,';');
      rate = stoi(srate);
      lista.push_back(new Cliente(user,pass,nombre,edadS,id,numero,direccion,rate));
    }
    if (tipo == "M") {
      getline(file,user,',');
      getline(file,pass,',');
      getline(file,nombre,',');
      getline(file,edadS,',');
      getline(file,id,',');
      getline(file,numero,',');
      getline(file,fecha,',');
      getline(file,salrioS,';');
      salario = stoi(salrioS);
      lista.push_back(new Meseros(user,pass,nombre,edadS,id,numero,fecha,salario));
    }
    if (tipo == "L") {
      string motiv;
      int motivacion;
      getline(file,user,',');
      getline(file,pass,',');
      getline(file,nombre,',');
      getline(file,edadS,',');
      //edad = stoi(edadS);
      getline(file,id,',');
      getline(file,numero,',');
      getline(file,fecha,',');
      getline(file,salrioS,',');
      salario = stoi(salrioS);
      getline(file,motiv,';');
      motivacion = stod(motiv);
      lista.push_back(new Lavaplatos(user,pass,nombre,edadS,id,numero,fecha,salario,motivacion));
    }
  }

    file.close();
    return lista;

  }
}
