/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author Daniel Ranchal Parrado
	\date
*/
#include <vector>
#include <cassert>
#include <algorithm>
#include "Medicion.hpp"
#include "MonticuloMediciones.hpp"
////////////////////////////////////////////////////////////////////
// Métodos privados de la clase MonticuloMediciones
ed::Medicion ed::MonticuloMediciones::getElement(int i) const{
   #ifndef NDEBUG
   assert(i>=0 && i<size());
   #endif

   if(v_[i]==ed::Medicion(ed::Fecha(0,0,0), 0.0)){
      return ed::Medicion(ed::Fecha(0,0,0), 0.0);
   }
   return v_[i];
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
int ed::MonticuloMediciones::getParent(int i) const{
   #ifndef NDEBUG
   assert(i>=1);
   #endif

   return (i-1)/2;
}
void ed::MonticuloMediciones::shiftUp(int i){
   #ifndef NDEBUG
   assert(i>=0 && i<size());
   #endif

   if(i>0 && v_[i].getPrecipitacion()>v_[getParent(i)].getPrecipitacion()){
      std::swap(v_[i], v_[getParent(i)]);
      shiftUp(getParent(i));
   }

   //codificar asertos

}
void ed::MonticuloMediciones::shiftDown(int i){
   #ifndef NDEBUG
   assert(i>=0 && i<size());
   #endif

   int n=i, lC=getLeftChild(i), rC=getRightChild(i);
   if(lC < size()-1 && v_[lC].getPrecipitacion()>v_[n].getPrecipitacion()){
      n=lC;
   }
   if(rC < size()-1 && v_[rC].getPrecipitacion()>v_[n].getPrecipitacion()){
      n=rC;
   }
   if(i!=n){
      std::swap(v_[i], v_[n]);
      shiftDown(n);
   }

   //codificar asertos

}
bool ed::MonticuloMediciones::has(ed::Medicion medicion) const{
   for(int i=0; i<size(); i++){
      if(v_[i]==medicion){
         return true;
      }
   }
   return false;
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
   return v_.size();
}
ed::Medicion ed::MonticuloMediciones::top() const{
   return v_[0];
}
ed::MonticuloMediciones& ed::MonticuloMediciones::operator=(ed::MonticuloMediciones & m){
   #ifndef NDEBUG
   assert(this->v_!=m.v_);
   #endif

   this->v_=m.v_;

   return *this;
}
