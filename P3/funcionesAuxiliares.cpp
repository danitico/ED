/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Daniel Ranchal Parrado
  \date
*/
#include <iostream>
#include <fstream>
#include <string>
#include "funcionesAuxiliares.hpp"
#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"
#include "macros.hpp"
int ed::menu(){
   int opcion;
   int posicion;

   // Se muestran las opciones del menú
   posicion=2;

   // Se borra la pantalla
   std::cout << CLEAR_SCREEN;

   PLACE(1,10);
   std::cout << BIBLUE;
   std::cout << "Programa principial | Opciones del menú";
   std::cout << RESET;

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout <<  "[1] Tamaño del montículo";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << "[2] Cargar los datos de precipitaciones desde un fichero";

   PLACE(posicion++,10);
   std::cout << "[3] Grabar los datos de precipitaciones ordenados de forma descendente en un fichero";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << "[4] Consultar datos de precipitación de un día";

   PLACE(posicion++,10);
   std::cout <<  "[5] Mostrar los datos de precipitación de forma descendente";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << "[6] Modificar la cima del monticulo";

   PLACE(posicion++,10);
   std::cout << "[7] Insertar una medicion en el montículo";

   PLACE(posicion++,10);
   std::cout << "[8] Borrar un medicion del montículo por fecha";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << BIRED << "[0] Salir";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << BIGREEN;
   std::cout << "Opción: ";
   std::cout << RESET;

   // Se lee el número de opción
   std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

   return opcion;
}
void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo){
   std::ifstream file(nombreFichero.c_str());
   std::string stream;
   Fecha fecha;
   Medicion medicion;

   if(file.is_open()){
      while(getline(file, stream, '-')){
         fecha.setDia(atoi(stream.c_str()));

         getline(file, stream, '-');
         fecha.setMes(atoi(stream.c_str()));

         getline(file, stream, ' ');
         fecha.setAgno(atoi(stream.c_str()));

         getline(file, stream, '\n');
         medicion.setFecha(fecha);
         medicion.setPrecipitacion(atof(stream.c_str()));

         monticulo.insert(medicion);
      }
   }
   return;
}
void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo){
   std::ofstream file(nombreFichero.c_str());
   ed::MonticuloMediciones copia=monticulo;

   if(file.is_open()){
      while(!copia.isEmpty()){
         file<<copia.top();
         copia.remove();
      }
   }

	return;
}
