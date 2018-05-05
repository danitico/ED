/*!
   \file Edge.cpp
   \brief Fichero de la clase Edge
   \author Daniel Ranchal Parrado
   \date
*/
#include "Edge.hpp"
bool ed::Edge::has(ed::Vertex const & u) const{
   if(u==first() || u==second()){
      return true;
   }
   else{
      return false;
   }
}
ed::Vertex ed::Edge::other(ed::Vertex const & u) const{
   if(u==first()){
      return second();
   }
   else{
      if(u==second()){
         return first();
      }
   }
}
