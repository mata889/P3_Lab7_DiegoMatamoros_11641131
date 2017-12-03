lab7: Main.o Administrador.o Chef.o Cliente.o Lavaplatos.o Meseros.o Personal.o Usuario.o
	g++ Main.o Administrador.o Chef.o Cliente.o Lavaplatos.o Meseros.o Personal.o Usuario.o -o lab7

Main.o:	Administrador.h Chef.h Cliente.h Lavaplatos.h Meseros.h Personal.h Usuario.h Main.cpp
	g++ -c Main.cpp

Administrador.o:	Administrador.h Administrador.cpp
	g++ -c Administrador.cpp

Chef.o:	Chef.h Chef.cpp
	g++ -c Chef.cpp

Cliente.o:	Cliente.h Cliente.cpp
	g++ -c Cliente.cpp

Lavaplatos.o:	Lavaplatos.h Lavaplatos.cpp
	g++ -c Lavaplatos.cpp

Meseros.o:	Meseros.h Meseros.cpp
	g++ -c Meseros.cpp

Personal.o:	Personal.h Personal.cpp
	g++ -c Personal.cpp

Usuario.o: 	Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

clear:
	rm *.o run
