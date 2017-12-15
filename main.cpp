#include <iostream>
#include <cctype>
#include "Empleados.h"
#include "funciones.cpp"

using namespace std;
using namespace funciones;
using namespace empleadosFn;

int main(){

	do{

		int numeroDeEmpleados = 0, choice;

		introduccion();
		choice = calculaNumeroDeEmpleados(numeroDeEmpleados);

		Empleados empleadoNumero[numeroDeEmpleados];

		initialize(empleadoNumero, numeroDeEmpleados, choice);

		for(int i = 0; i < numeroDeEmpleados; i++){
			
			compute(empleadoNumero[i]);
		}

		cout << "\n\nPaga de la semana\n";
		cout << "(Empleado -- Paga Total)\n";

		for(int i = 0; i < numeroDeEmpleados; i++){
			
			result(empleadoNumero[i]);
		}

	}while(seguir());

	cout << "\n\nGracias por usar el programa. Tenga un buen dia.\n\n";

	return 0;
}