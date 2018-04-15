/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author Daniel Ranchal Parrado
	\date
*/
#include <vector>
#include <cassert>
#include "Medicion.hpp"
#include "MonticuloMediciones.hpp"
////////////////////////////////////////////////////////////////////
// Métodos privados de la clase MonticuloMediciones
ed::Medicion ed::MonticuloMediciones::getElement(int i) const{
   #ifndef NDEBUG
   assert(i>=0 && i<size());
   #endif

   if(v[i]==ed::Medicion(ed::Fecha(0,0,0), 0.0)){
      return ed::Medicion(ed::Fecha(0,0,0), 0.0);
   }
   return v[i];
}
int ed::MonticuloMediciones::getLeftChild(int i) const{
   #ifndef NDEBUG
   assert(i>=0);
   #endif

   if(2*i+1<size()){
      return getElement(2*i+1)==ed::Medicion(ed::Fecha(0,0,0), 0.0) ? -1 : 2*i+1; //Si devuelve -1 es que la posicion en la que está el hijo izquierdo está vacia.
   }
   else{
      return -2;//Esto significa que el vector no tiene el suficiente espacio para albergar esa posicion.
   }
}
int ed::MonticuloMediciones::getRightChild(int i) const{
   #ifndef NDEBUG
   assert(i>=0);
   #endif

   if(2*i+2<size()){
      return getElement(2*i+2)==ed::Medicion(ed::Fecha(0,0,0), 0.0) ? -1 : 2*i+2; //Si devuelve -1 es que la posicion en la que está el hijo izquierdo está vacia.
   }
   else{
      return -2;//Esto significa que el vector no tiene el suficiente espacio para albergar esa posicion.
   }
}
////////////////////////////////////////////////////////////////////////////////////7
// Métodos públicos de la clase MonticuloMediciones
bool ed::MonticuloMediciones::isEmpty() const{
   if(size()==0){
      return true;
   }
   else{
      return false;
   }
}
int ed::MonticuloMediciones::size() const{
   return v.size();
}
ed::Medicion ed::MonticuloMediciones::top() const{
   return v[0];
}
