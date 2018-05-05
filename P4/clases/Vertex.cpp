/*!
   \file Vertex.cpp
   \brief Fichero de la clase Vertex
   \author Daniel Ranchal Parrado
   \date
*/
#include "Vertex.hpp"
bool ed::Vertex::operator==(ed::Vertex const & vertice) const{
   if(this->getData() == vertice.getData()){
      return true;
   }
   else{
      return false;
   }
}
bool ed::Vertex::operator!=(ed::Vertex const & vertice) const{
   if(this->getData() != vertice.getData()){
      return true;
   }
   else{
      return false;
   }
}
