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

   return v_[i];
}
void ed::MonticuloMediciones::setElement(int i, Medicion medicion){
   if(i==0){
      v_[0]=medicion;
      shiftDown(i);
   }
   else{
      removeMedition(i);
      insert(medicion);
   }
}
int ed::MonticuloMediciones::getLeftChild(int i) const{
   #ifndef NDEBUG
   assert(i>=0);
   #endif

   if(2*i+1<size()){
      return getElement(2*i+1)==ed::Medicion(ed::Fecha(1,1,1), 0.0) ? -1 : 2*i+1; //Si devuelve -1 es que la posicion en la que está el hijo izquierdo está vacia.
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
      return getElement(2*i+2)==ed::Medicion(ed::Fecha(1,1,1), 0.0) ? -1 : 2*i+2; //Si devuelve -1 es que la posicion en la que está el hijo izquierdo está vacia.
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

   #ifndef NDEBUG
   if(!(top()==getElement(i))){
      assert(getElement(i).getPrecipitacion()<=getElement(i).getPrecipitacion());
   }
   if(getLeftChild(i)!=-1 && getLeftChild(i)!=-2){
      assert(getElement(i).getPrecipitacion()>=getElement(getLeftChild(i)).getPrecipitacion());
   }
   if(getRightChild(i)!=-1 && getRightChild(i)!=-2){
      assert(getElement(i).getPrecipitacion()>=getElement(getRightChild(i)).getPrecipitacion());
   }
   #endif
}
void ed::MonticuloMediciones::shiftDown(int i){
   #ifndef NDEBUG
   assert(i>=0);
   assert(i<size());
   #endif

   int n=i, lC=getLeftChild(i), rC=getRightChild(i);
   if(lC >= 0 && lC < size()-1 && v_[lC].getPrecipitacion()>v_[n].getPrecipitacion()){
      n=lC;
   }
   if(rC >= 0 && rC < size()-1 && v_[rC].getPrecipitacion()>v_[n].getPrecipitacion()){
      n=rC;
   }
   if(i!=n){
      std::swap(v_[i], v_[n]);
      shiftDown(n);
   }

   #ifndef NDEBUG
   if(!(top()==getElement(i))){
      assert(getElement(i).getPrecipitacion()<=getElement(i).getPrecipitacion());
   }
   if(getLeftChild(i)!=-1 && getLeftChild(i)!=-2){
      assert(getElement(i).getPrecipitacion()>=getElement(getLeftChild(i)).getPrecipitacion());
   }
   if(getRightChild(i)!=-1 && getRightChild(i)!=-2){
      assert(getElement(i).getPrecipitacion()>=getElement(getRightChild(i)).getPrecipitacion());
   }
   #endif
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
void ed::MonticuloMediciones::insert(ed::Medicion medicion){
   if(size()==0){
      v_.resize(1, ed::Medicion(ed::Fecha(1,1,1), 0.0));
      v_[0]=medicion;
   }
   else{
      int ultimo=size();
      v_.resize(size()+1, ed::Medicion(ed::Fecha(1,1,1), 0.0));
      v_[ultimo]=medicion;
      if(v_[ultimo].getPrecipitacion()>v_[getParent(ultimo)].getPrecipitacion()){
         this->shiftUp(ultimo);
      }
   }

   #ifndef NDEBUG
   assert(!isEmpty() && has(medicion));
   #endif
}
void ed::MonticuloMediciones::remove(){
   #ifndef NDEBUG
   assert(!isEmpty());
   #endif

   std::swap(v_[0], v_[size()-1]);
   this->shiftDown(0);
   v_.resize(size()-1);
}
void ed::MonticuloMediciones::removeMedition(int indice){
   #ifndef NDEBUG
   assert(!isEmpty() && has(getElement(indice)));
   #endif

   std::swap(v_[indice], v_[size()-1]);
   this->shiftDown(indice);
   v_.resize(size()-1);
}
void ed::MonticuloMediciones::removeAll(){
   while(!isEmpty()){
      this->remove();
   }

   #ifndef NDEBUG
   assert(isEmpty());
   #endif
}
void ed::MonticuloMediciones::modify(ed::Medicion medicion){
   #ifndef NDEBUG
   assert(!isEmpty());
   #endif

   if(size()==0){
      v_[0]=medicion;
   }
   else{
      v_[0]=medicion;
      shiftDown(0);
   }
}
void ed::MonticuloMediciones::modificarMedicion(int indice, ed::Medicion medicion){
   setElement(indice, medicion);
}
int ed::MonticuloMediciones::busquedaMedicion(ed::Fecha const & fecha) const{
   int valorDevuelto=-1;
   ed::Medicion buscado(fecha);

   for(int i=0; i<size(); i++){
      if(buscado==getElement(i)){
         valorDevuelto=i;
         break;
      }
   }

   #ifndef NDEBUG
   if(valorDevuelto<0){
      assert(!has(buscado));
   }
   else{
      assert(has(buscado));
   }
   #endif

   return valorDevuelto;
}
ed::Medicion ed::MonticuloMediciones::obtenerElemento(int const & indice) const{
   return getElement(indice);
}
ed::MonticuloMediciones& ed::MonticuloMediciones::operator=(ed::MonticuloMediciones & m){
   #ifndef NDEBUG
   assert(this->v_!=m.v_);
   #endif

   this->v_=m.v_;

   return *this;
}
void ed::MonticuloMediciones::print() const{
   for(int i=0; i<size(); i++){
      std::cout<<v_[i];
   }
}
