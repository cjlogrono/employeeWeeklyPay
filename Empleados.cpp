#ifndef EMPLEADOS_CPP
#define EMPLEADOS_CPP

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Empleados.h"

using namespace std;

namespace empleadosFn{
	
	Empleados::Empleados(){
	}

	Empleados::~Empleados(){

		/*T siguiente;

		while(!vacia()){

			siguiente = extrae();
		}*/
	}

	void Empleados::agregaApellido(string nombre){

		empleado.apellido = nombre;
	}

	void Empleados::agregaHoras(int choice, int horas, int index){

		int dia = 1;
		double tiempo;
		bool invalid;

		if(choice == 2){

			empleado.horas[index] = horas;

		}else{

			cout << endl;

			for(int i = 0; i < 5; i++){

				do{

					cout << "\nCuantas horas trabajo el ";

					switch(dia){

						case 1:

							cout << "Lunes?";
							break;

						case 2:

							cout << "Martes?";
							break;

						case 3:

							cout << "Miercoles?";
							break;

						case 4:

							cout << "Jueves?";
							break;

						case 5:

							cout << "Viernes?";
							break;
					}

					cout << "\nHoras: ";
					cin >> tiempo;

					if(cin.fail()){

						cin.clear();
						cin.ignore();
						invalid = true;

						cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";

					}else if(tiempo < 0){

						invalid = true;
						cout << "\n\n** Introdujo un numero negativo, tratelo denuevo **\n\n";

					}else{

						invalid = false;
					}

				}while(invalid);

				empleado.horas[i] = tiempo;
				dia++;
			}
		}
	}

	void Empleados::agregaPagaHora(double valor){

		empleado.pph = valor;
	}

	void Empleados::agregaPagaSemana(double paga){

		empleado.pagaSemana = paga;
	}

	string Empleados::extraeApellido(){

		return empleado.apellido;
	}

	double Empleados::extraeHoras(int index){

		return empleado.horas[index];
	}

	double Empleados::extraePagaHora(){

		return empleado.pph;
	}

	double Empleados::extraePagaSemana(){

		return empleado.pagaSemana;
	}


}
#endif //EMPLEADOS_CPP