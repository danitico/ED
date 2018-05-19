/*!
   \file Punto.cpp
   \brief Fichero de la clase Punto
   \author Daniel Ranchal Parrado
   \date 
*/
#include "Punto.hpp"
#include <iostream>
ed::Punto & ed::Punto::operator=(Punto const &p){
   if(this != &v){
      setX(p.getX());
      setY(p.getY());
   }
   return *this;
}
bool ed::Punto::operator==(Punto const &p);{
   if( (std::abs(getX() - this->getX()) < COTA_ERROR) && (std::abs(getY() - this->getY()) < COTA_ERROR) ){
      return true;
   }
   else{
      return false;
   }
}
void ed::Punto::leerPunto(){
   float x, y;
   std::cout<<"Introduzca las coordenadas del punto"<<std::endl;
   std::cout<<"Introduzca el valor de x";
   std::cin>>x;

   std::cout<<"Introduzca el valor de y";
   std::cin>>y;

   this->setX(x);
   this->setY(y);
}
void ed::Punto::escribirPunto(){
   std::cout<<"("<<this->getX()<<", "<<this->getY()<<")"<<std::endl;
}
float ed::distancia(Punto const &p1, Punto const &p2){
   return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}
