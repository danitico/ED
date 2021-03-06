/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Daniel Ranchal Parrado
  \date 01-05-2018
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
   std::cout << "[6] Modificar un elemento del monticulo";

   PLACE(posicion++,10);
   std::cout << "[7] Modificar la cima del monticulo";

   //////////////////////////////////////////////////////////////////////////////
   posicion++;

   PLACE(posicion++,10);
   std::cout << "[8] Insertar una medicion en el montículo";

   PLACE(posicion++,10);
   std::cout << "[9] Borrar un medicion del montículo por fecha";

   PLACE(posicion++,10);
   std::cout << "[10] Borrar todas las mediciones del montículo";

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
void ed::estadoMonticulo(ed::MonticuloMediciones const & monticulo){
   if(monticulo.isEmpty()){
      std::cout<<BIRED<<"El monticulo no tiene ninguna medicion"<<RESET<<std::endl;
   }
   else{
      std::cout<<BIGREEN<<"El monticulo tiene "<<RESET<<UNDERLINE<<BIGREEN<<monticulo.size()<<RESET<<BIGREEN<<" mediciones"<<RESET<<std::endl;
   }
}
void ed::cargarMonticuloDeFichero(ed::MonticuloMediciones & monticulo){
   std::string nombreFichero;
   std::cout<<BIPURPLE<<"Introduzca el nombre del archivo del que cargar los datos: "<<RESET;
   std::cin>>nombreFichero;

   std::ifstream file(nombreFichero.c_str());

   if(file.is_open()){
      std::string stream;
      Fecha fecha;
      Medicion medicion;

      while(getline(file, stream, '-')){
         fecha.setDia(atoi(stream.c_str()));

         getline(file, stream, '-');
         fecha.setMes(atoi(stream.c_str()));

         getline(file, stream, ' ');
         fecha.setAgno(atoi(stream.c_str()));

         getline(file, stream, '\n');
         medicion.setFecha(fecha);
         medicion.setPrecipitacion(atof(stream.c_str()));

         if(monticulo.busquedaMedicion(fecha)<0){
            monticulo.insert(medicion);
         }
      }
      std::cin.ignore();
      std::cout<<BIGREEN<<"Fichero cargado con exito"<<std::endl;
      file.close();
   }
   else{
      std::cin.ignore();
      std::cout<<BIRED<<"Error al abrir el fichero"<<RESET<<std::endl;
   }
   return;
}
void ed::grabarMonticuloEnFichero(ed::MonticuloMediciones const & monticulo){
   std::string nombreFichero;
   std::cout<<BIPURPLE<<"Introduzca el nombre del archivo en el que guardar los datos: "<<RESET;
   std::cin>>nombreFichero;

   std::ofstream file(nombreFichero.c_str());
   ed::MonticuloMediciones copia=monticulo;

   if(file.is_open()){
      while(!copia.isEmpty()){
         file<<copia.top();
         copia.remove();
      }
      std::cin.ignore();
      file.close();
      std::cout<<BIGREEN<<"Fichero guardado con exito"<<std::endl;
   }
   else{
      std::cin.ignore();
      std::cout<<BIRED<<"Error al guardar los datos en el fichero"<<RESET<<std::endl;
   }

	return;
}
void ed::consultarDatosdePrecipitacion(ed::MonticuloMediciones const & monticulo){
   ed::Fecha fecha;
   std::cout<<BIPURPLE<<"Introduzca la fecha para ver la cantidad de precipitacion de ese dia"<<RESET<< " -> ";
   std::cin>>fecha;
   // Se lee la fecha teniendo en cuenta el formato: DD-MM-AAAA

   int indice=monticulo.busquedaMedicion(fecha);

   if(indice>=0){
      std::cout<<BIGREEN<<"La cantidad de lluvia caida en ese día fue "<<RESET<<monticulo.obtenerElemento(indice).getPrecipitacion()<<BIGREEN<<" mm"<<RESET<<std::endl;
   }
   else{
      std::cout<<BIRED<<"Esa fecha no se encuentra registrada en los datos"<<RESET<<std::endl;
   }

   return;
}
void ed::mostrarPrecipitacionDescendente(ed::MonticuloMediciones const & monticulo){
   if(!monticulo.isEmpty()){
      ed::MonticuloMediciones copia=monticulo;
      int contador=0;
      std::cout<<BIYELLOW<<"Fecha"<<RESET<<"\t\t"<<BICYAN<<"Precipitación"<<RESET<<std::endl;
      std::cout<<"-----------------------------"<<std::endl;
      while(!copia.isEmpty()){
         contador++;
         std::cout<<BIYELLOW<<copia.top().getFecha()<<RESET<<"\t"<<BICYAN<<copia.top().getPrecipitacion()<<RESET<<std::endl;
         copia.remove();

         if(contador==34){
            contador=0;
            std::cout <<"Pulse "<<BIGREEN<<"INTRO"<<RESET<<" para seguir viendo los datos";
            std::cin.ignore();
            std::cout<<CLEAR_SCREEN;
            PLACE(1,1);
            std::cout<<BIYELLOW<<"Fecha"<<RESET<<"\t\t"<<BICYAN<<"Precipitación"<<RESET<<std::endl;
            std::cout<<"-----------------------------"<<std::endl;
         }
      }
   }
   else{
      std::cout<<BIRED<<"El monticulo esta vacio, por lo que no se puede mostrar ningun dato"<<RESET<<std::endl;
   }
}
void ed::modificarElementoMonticulo(ed::MonticuloMediciones & monticulo){
   if(monticulo.isEmpty()){
      std::cout<<BIRED<<"El monticulo está vacio, por lo que no se puede modificar ninguna medicion"<<RESET<<std::endl;
   }
   else{
      ed::Medicion medicion;
      ed::Fecha fecha;
      float precipitacion=0;
      std::cout<<BIPURPLE<<"Introduzca la fecha de la medicion que se quiere modificar -> "<<RESET;
      std::cin>>fecha;
      int indice=monticulo.busquedaMedicion(fecha);

      if(indice<0){
         std::cout<<BIRED<<"Esa fecha no se encuentra entre las mediciones"<<RESET<<std::endl;
      }
      else{
         std::cout<<BIBLUE<<"Usted va a modificar la precipitacion de la siguiente medicion -> "<<RESET<<monticulo.obtenerElemento(indice);
         std::cout<<BIPURPLE<<"Introduzca la nueva precipitación -> "<<RESET;
         std::cin>>precipitacion;

         medicion.setFecha(fecha);
         medicion.setPrecipitacion(precipitacion);
         monticulo.modificarMedicion(indice, medicion);

         std::cin.ignore();
         std::cout<<BIGREEN<<"Medicion modificada con exito"<<RESET<<std::endl;
      }
   }
}
void ed::modificarCimaMonticulo(ed::MonticuloMediciones & monticulo){
   if(monticulo.isEmpty()){
      std::cout<<BIRED<<"El monticulo está vacio, por lo que no se puede modificar la cima"<<RESET<<std::endl;
   }
   else{
      ed::Medicion medicion;
      float precipitacion=0.0;
      std::cout<<BIBLUE<<"La medicion actual de la cima es "<<RESET<<monticulo.top();
      std::cout<<BIPURPLE<<"Introduca la nueva medida de precipitacion -> "<<RESET;
      std::cin>>precipitacion;
      std::cin.ignore();

      medicion.setPrecipitacion(precipitacion);
      medicion.setFecha(monticulo.top().getFecha());

      if(precipitacion==monticulo.top().getPrecipitacion()){
         std::cout<<BIRED<<"Se ha metido la misma medida de precipitacion, no se modifica la medicion"<<std::endl;
      }
      else{
            monticulo.modify(medicion);
            std::cout<<BIGREEN<<"Se ha modificado el monticulo con éxito"<<RESET<<std::endl;
      }
   }
}
void ed::insertarMedicionMonticulo(ed::MonticuloMediciones & monticulo){
   ed::Medicion medicion;
   std::cout<<BIPURPLE<<"Introduzca la medicion a insertar (DD-MM-YY xx.xx) -> "<<RESET;
   std::cin>>medicion;

   if(monticulo.busquedaMedicion(medicion.getFecha())>=0){
      std::cout<<BIRED<<"Se ha introducido una medicion que se encuentra en el heap, por lo que no se inserta"<<RESET<<std::endl;
   }
   else{
      monticulo.insert(medicion);
      std::cout<<BIGREEN<<"Se ha insertado la medicion en el monticulo con éxito"<<RESET<<std::endl;
   }
}
void ed::borrarElementoMedicion(ed::MonticuloMediciones & monticulo){
   if(monticulo.isEmpty()){
      std::cout<<BIRED<<"El monticulo está vacio, por lo que no se puede borrar ninguna medicion"<<RESET<<std::endl;
   }
   else{
      ed::Fecha fecha;
      std::cout<<BIPURPLE<<"Introduzca la fecha de la medicion que se quiere borrar -> "<<RESET;
      std::cin>>fecha;
      int indice=monticulo.busquedaMedicion(fecha);

      if(indice < 0){
         std::cout<<BIRED<<"Esa fecha no se encuentra en los datos del heap, por lo que no se puede borrar"<<RESET<<std::endl;
      }
      else{
         monticulo.removeMedition(indice);
         std::cout<<BIGREEN<<"Se ha borrado la medicion deseada del monticulo con éxito"<<RESET<<std::endl;
      }
   }
}
void ed::borrarMonticulo(ed::MonticuloMediciones & monticulo){
   if(monticulo.isEmpty()){
      std::cout<<BIRED<<"El monticulo ya está vacio"<<RESET<<std::endl;
   }
   else{
      monticulo.removeAll();
      std::cout<<BIGREEN<<"Se han borrado todas las mediciones con éxito"<<RESET<<std::endl;
   }
}
