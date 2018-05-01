/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/
// Ficheros de cabecera
#include <iostream>
// atoi, atof
#include "Medicion.hpp"
void ed::Medicion::setFecha(ed::Fecha fecha){
   fecha_=fecha;

   #ifndef NDEBUG
   assert(getFecha()==fecha);
   #endif
}
void ed::Medicion::setPrecipitacion(float precipitacion){
   if(precipitacion < 0.0){
      precipitacion_=0.0;
   }
   else{
      precipitacion_=precipitacion;
   }

   #ifndef NDEBUG
   assert(abs(getPrecipitacion()-precipitacion)<=COTA_ERROR && getPrecipitacion()>=0.0);
   #endif
}
bool ed::Medicion::operator==(ed::Medicion const medicion) const{
   bool res;
   if(this->getFecha() == medicion.getFecha()){
      res=true;
   }
   else{
      res=false;
   }

   #ifndef NDEBUG
   assert(res==(getFecha() == medicion.getFecha()));
   #endif

   return res;
}
ed::Medicion & ed::Medicion::operator=(ed::Medicion const &medicion){
   if(this!=&medicion){
      this->setFecha(medicion.getFecha());
      this->setPrecipitacion(medicion.getPrecipitacion());
	}

   #ifndef NDEBUG
   assert(getFecha()==medicion.getFecha() && abs(getPrecipitacion()-medicion.getPrecipitacion())<=COTA_ERROR);
   #endif

	return *this;
}
void ed::Medicion::leerMedicion(){
   ed::Fecha fecha;
   float precipitacion;

   std::cout<<"Introduzca la fecha de la medición"<<std::endl;
   std::cout<<BIRED<<"Se lee la fecha teniendo en cuenta el formato: DD-MM-AAAA -> "<<RESET;
   std::cin>>fecha;
   std::cout<<std::endl;

   std::cout<<"Introduzca la cantidad de precipitación -> ";
   std::cin>>precipitacion;
   std::cout<<std::endl;

   this->setFecha(fecha);
   this->setPrecipitacion(precipitacion);
}
void ed::Medicion::escribirMedicion(){
   std::cout<<"| "<<getFecha()<<" | "<<getPrecipitacion()<<" |"<<std::endl;
}
// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed
namespace ed{
// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion){
   stream<<medicion.getFecha()<<" "<<medicion.getPrecipitacion()<<std::endl;

   return stream;
}
// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion){
   ed::Fecha fecha;
   std::string cadena;

   std::getline(stream,cadena,'-');
   fecha.setDia(atoi(cadena.c_str()));

   std::getline(stream,cadena,'-');
   fecha.setMes(atoi(cadena.c_str()));

   std::getline(stream,cadena,' ');
   fecha.setAgno(atoi(cadena.c_str()));
   medicion.setFecha(fecha);

   std::getline(stream, cadena, '\n');
   medicion.setPrecipitacion(atof(cadena.c_str()));

   return stream;
}
} // Fin del espacio de nombres ed
