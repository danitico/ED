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
int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		std::cout << "Modo de ejecución" << std::endl;
		std::cout << argv[0] << "<fichero-de-mediciones>  <fichero-ordenado> "  << std::endl;

		return -1;
	}

	ed::MonticuloMediciones monticulo;
	std::string nombreFicheroEntrada(argv[1]);
	std::string nombreFicheroSalida(argv[2]);

	int opcion;

	do{
		// Se elige la opción del menún
		opcion = ed::menu();

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
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
					ed::cargarMonticuloDeFichero(nombreFicheroEntrada,monticulo);
				break;

			case 3:
					std::cout << "[3] Grabar los datos de precipitaciones ordenados de forma descendente en un fichero" << std::endl;
					ed::grabarMonticuloEnFichero(nombreFicheroSalida,monticulo);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4:
					std::cout << "[4] Consultar datos de precipitación de un día" << std::endl;

					break;

			case 5:
					std::cout << "[5] Mostrar los datos de precipitación de forma descendente" << std::endl;

					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6:
					std::cout << "[6] Modificar la cima del monticulo" << std::endl;

					break;


			case 7:
					std::cout << "[7] Insertar una medicion en el montículo" << std::endl;

					break;

			//////////////////////////////////////////////////////////////////////////////
			case 8:
					std::cout << "[8] Borrar un medicion del montículo por fecha" << std::endl;

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

	 if (opcion !=0)
	 {
		std::cout << std::endl << std::endl;
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú";
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
	 }
	  }while(opcion!=0);
	//
//	std::cout << "Se cargan las mediciones desde el fichero " << nombreFicheroEntrada << std::endl;
//	std::cout << " Se crea un montículo de máximos " << std::endl;


	// Se graba el montículo en el fichero: las mediciones son grabadas en orden descendente
//	std::cout << "Se graba el montículo en el fichero " << nombreFicheroSalida << std::endl;
//	std::cout << "Las mediciones son grabadas en orden descendente " << std::endl;

	return 0;
}
