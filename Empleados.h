#ifndef EMPLEADOS_H
#define EMPLEADOS_H

using namespace std;

namespace empleadosFn{

	class Empleados{

	public:

		Empleados();

		~Empleados();

		void agregaApellido(string nombre);

		void agregaHoras(int choice, int horas, int index);

		void agregaPagaHora(double valor);

		void agregaPagaSemana(double paga);

		string extraeApellido();

		double extraeHoras(int index);

		double extraePagaHora();

		double extraePagaSemana();

	private:

		struct empleadosDato{

			string apellido;
			double horas[5];
			double pph;
			double pagaSemana;
		};

		empleadosDato empleado;

	};
} //empleados
#endif //EMPLEADOS_H

#include "Empleados.cpp"