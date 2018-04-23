/*!
	\file principalMonticulo.cpp
	\brief Programa principal de la practica 3 de Estructuras de Datos
*/
/*!
 \mainpage Implementación de un montículo de mediciones
 \author   Daniel Ranchal Parrado
 \date     2018-3-7
 \version  1.0
*/
#include <iostream>
#include <string>
#include "funcionesAuxiliares.hpp"
#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"
#include "macros.hpp"
/*!
		\brief   Programa principal de la práctica 2: montículo de mediciones
		\return  int
*/
int main(int argc, char *argv[]){
	ed::MonticuloMediciones monticulo;

	int opcion;

	do{
		// Se elige la opción del menú
		opcion = ed::menu();

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion){
			case 0:
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
				break;

			///////////////////////////////////////////////////////////////////
			case 1:
				std::cout <<  "[1] Tamaño del montículo" << std::endl;
				std::cout << "Tamaño del montículo " << monticulo.size() << std::endl;
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 2:
				std::cout << "[2] Cargar los datos de precipitaciones desde un fichero" << std::endl;
				ed::cargarMonticuloDeFichero(monticulo);
				break;

			case 3:
				std::cout << "[3] Grabar los datos de precipitaciones ordenados de forma descendente en un fichero" << std::endl;
				ed::grabarMonticuloEnFichero(monticulo);
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 4:
				std::cout << "[4] Consultar datos de precipitación de un día" << std::endl;
				ed::consultarDatosdePrecipitacion(monticulo);
				break;

			case 5:
				std::cout << "[5] Mostrar los datos de precipitación de forma descendente" << std::endl;
				ed::mostrarPrecipitacionDescendente(monticulo);
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 6:
				std::cout << "[6] Modificar un elemento del monticulo" << std::endl;
				modificarElementoMonticulo(monticulo);
				break;

			case 7:
				std::cout << "[7] Modificar la cima del monticulo" << std::endl;
				ed::modificarCimaMonticulo(monticulo);
				break;

			case 8:
				std::cout << "[8] Insertar una medicion en el montículo" << std::endl;
				ed::insertarMedicionMonticulo(monticulo);
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 9:
				std::cout << "[9] Borrar un medicion del montículo por fecha" << std::endl;
				ed::borrarElementoMedicion(monticulo);
				break;

			case 10:
				std::cout << "[10] Borrar todas las mediciones del montículo" << std::endl;
				ed::borrarMonticulo(monticulo);
				break;

			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
				std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
		}

		if (opcion !=0){
			std::cout << std::endl << std::endl;
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú";
			std::cout << RESET;

			std::cin.ignore();

			std::cout << CLEAR_SCREEN;
		}
 	}while(opcion!=0);
	return 0;
}
