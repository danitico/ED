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
