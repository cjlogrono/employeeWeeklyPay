#include <iostream>
#include <fstream>
#include <string>
#include "Empleados.h"
using namespace empleadosFn;

namespace funciones{
	
	bool validoresFunciones(int choice, int opcion, char character){

		bool truefalse;

		switch(choice){

			case 1:

				if(character == 'Y' || character == 'y' || character == 'N' || character == 'n'){

					truefalse = false;

				}else{

					truefalse = true;
					cout << "\n**Introdujo un caracter invalido**\n";

				}

				break;

			case 2:

				if(character == 'Y' || character == 'y'){

					truefalse = true;

				}
				else{

					truefalse = false;

				}

				break;

			case 3:

				switch(opcion){

					case 1:
						truefalse = false;
						break;

					case 2:
						truefalse = false;
						break;

					default:
						truefalse = true;
				}
				break;

		}

		return truefalse;
	}

	bool seguir(){

		char contestacion;

			do{

				cout << "\n\nDesea seguir usando el programa? (Y/N)\n";
				cout << "Contestacion: ";
				cin >> contestacion;

			}while(validoresFunciones(1, 0,contestacion));

			return validoresFunciones(2,0,contestacion);
	}

	void introduccion(){

		cout << "\n\nBienvenidos, este programa calculara la paga semanal de todos los empleados\n que tenga en employees.txt.\n";
	 	cout << "El usuario deberá entrar por teclado los valores de cuantas horas hizo cada\n dia de la semana (Lunes a Viernes) y a cuanto cobra la hora.\n";
	}

	int calculaNumeroDeEmpleados(int &numeroDeEmpleados){

		string data;
		int counter = 0, choice;
		bool invalid;

		do{

			cout << "\n\nLa informacion de los empleados se va a leer de un file o lo introducira usted?\n";
			cout << "(ponga el numero)\n";
			cout << "1) Manual\n";
			cout << "2) Del file\n";
			cout << "Informacion de empleados sera: ";
			cin >> choice;

			if(cin.fail()){

				cin.clear();
				cin.ignore();
				invalid = true;

				cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";

			}else if(validoresFunciones(3, choice, '0')){

				invalid = true;
				cout << "\n\n** Introdujo una opcion incorrecta, tratelo denuevo **\n\n";

			}else{

				invalid = false;
			}

		}while(invalid);

		if(choice == 1){

			do{
				cout << "\nCuantos empleados son?\n";
				cout << "Numero de Empleados: ";
				cin >> counter;

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";

				}else if(counter < 0){

					invalid = true;
					cout << "\n\n** Introdujo un numero negativo, tratelo denuevo **\n\n";

				}else{

					invalid = false;
				}

			}while(invalid);

			numeroDeEmpleados = counter;

		}else{

			ifstream fileRead;
			fileRead.open("employees.txt");

			while(fileRead){

				getline(fileRead, data, '\n');

				for(int i = 0; i < 6; i++){

					fileRead >> data;
				}

				counter++;
			}

			numeroDeEmpleados = counter - 1;

			fileRead.close();
		}

		return choice;
	}

	void initialize(Empleados empleadoNumero[], int numeroDeEmpleados, int choice){

		ifstream fileRead;
		fileRead.open("employees.txt");

		string nombre;
		double dummyValue;
		bool invalid;

		for(int i = 0; i < numeroDeEmpleados; i++){

			if(choice == 2){

				getline(fileRead, nombre, '\n');
				empleadoNumero[i].agregaApellido(nombre);

				for(int x = 0; x < 6; x++){

					fileRead >> dummyValue;

					if(x == 5){

						empleadoNumero[i].agregaPagaHora(dummyValue);

					}else{

						empleadoNumero[i].agregaHoras(choice, dummyValue, x);
					}
				}

				fileRead.ignore();

			}else{

				cin.ignore(); 
				
				cout << "\n\nComo se llama el empleado numero #" << (i + 1) << "?\n";
				cout << "Nombre: ";
				getline(cin, nombre);
				empleadoNumero[i].agregaApellido(nombre);

				cout << "\n\nHoras trabajadas por " << empleadoNumero[i].extraeApellido();
				empleadoNumero[i].agregaHoras(0, 0, 0);

				do{

					cout << "\n\nCuanto dinero hace por hora?\n";
					cout << "Dinero*Hora: ";
					cin >> dummyValue;

					if(cin.fail()){

						cin.clear();
						cin.ignore();
						invalid = true;

						cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";

					}else if(dummyValue < 0){

						invalid = true;
						cout << "\n\n** Introdujo un numero negativo, tratelo denuevo **\n\n";

					}else{

						invalid = false;
					}

				}while(invalid);

				empleadoNumero[i].agregaPagaHora(dummyValue);

			}
		}

		fileRead.close();
	}

	void compute(Empleados &empleado){

		double totalHoras = 0;
		double pagaTotal;

		for(int i = 0; i < 5; i++){
			
			totalHoras += empleado.extraeHoras(i);
		}

		pagaTotal = totalHoras * empleado.extraePagaHora();

		empleado.agregaPagaSemana(pagaTotal);

	}

	void result(Empleados empleado){

		cout << endl << empleado.extraeApellido() << " -- $" << empleado.extraePagaSemana();
	}

}