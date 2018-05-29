#include <iostream>
#include "./clases/Graph.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
int main(int argc, char *argv[]){
	ed::Graph grafo, arbol_abarcador;
   float coste_total=0;
   std::string fichero;

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
				std::cout <<  "[1] Cargar vértices desde fichero" << std::endl;
            std::cout << BIPURPLE << "Introduzca el nombre del fichero con los vértices: " << RESET;
            std::cin>>fichero;
            ed::cargarVertices(grafo, fichero);
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 2:
				std::cout << "[2] Añadir vértice al grafo" << std::endl;

				break;

			case 3:
				std::cout << "[3] Añadir conexión entre dos vértices" << std::endl;

				break;

			//////////////////////////////////////////////////////////////////////////////
			case 4:
				std::cout << "[4] Modificar coste de un lado" << std::endl;

				break;

			case 5:
				std::cout << "[5] Borrar un vértice" << std::endl;

				break;

			//////////////////////////////////////////////////////////////////////////////
			case 6:
				std::cout << "[6] Borrar una conexión" << std::endl;

				break;

			case 7:
				std::cout << "[7] Mostrar el grafo" << std::endl;

				break;

			case 8:
				std::cout << "[8] Aplicar el algoritmo de Dijkstra" << std::endl;

				break;

			case 9:
				std::cout << "[9] Aplicar el algoritmo de Prim" << std::endl;
            if(grafo.getVertexVector().size()==0){
               std::cout << BIRED << "El grafo no tiene ningún vértice. No se puede aplicar el algoritmo" << RESET << std::endl;
            }
            else{
               arbol_abarcador=prim_algorithm(grafo, coste_total);
               std::cout << BIGREEN << "El algoritmo se ha aplicado correctamente" << std::endl;
            }
				break;

			//////////////////////////////////////////////////////////////////////////////
			case 10:
				std::cout << "[10] Aplicar el algoritmo de Kruskal" << std::endl;
            if(grafo.getVertexVector().size()==0){
               std::cout << BIRED << "El grafo no tiene ningún vértice. No se puede aplicar el algoritmo" << RESET << std::endl;
            }
            else{
               arbol_abarcador=kruskal_algorithm(grafo, coste_total);
               std::cout << BIGREEN << "El algoritmo se ha aplicado correctamente" << std::endl;
            }
				break;

			case 11:
				std::cout << "[11] Mostrar árbol abarcador mínimo generado" << std::endl;
            if(coste_total==0){
               std::cout << BIRED << "El árbol abarcador de coste mínimo no ha sido generado" << '\n';
            }
            else{
               //hacer funcion que pase matriz a la referencia etiquetas grafo
            }
				break;

         case 12:
            std::cout << "[12] Mostrar longitud del árbol abarcador mínimo" << std::endl;
            if(coste_total==0){
               std::cout << BIRED << "El árbol abarcador de coste mínimo no ha sido generado, por lo que no se puede mostrar la longitud" << RESET <<std::endl;
            }
            else{
               std::cout << BIBLUE << "La longitud total del árbol abarcador mínimo es " << UNDERLINE << coste_total << RESET << std::endl;
               coste_total=0;
            }
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
