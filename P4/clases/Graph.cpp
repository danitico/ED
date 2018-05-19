/*!
   \file Graph.cpp
   \brief Fichero de la clase Graph
   \author Daniel Ranchal Parrado
   \date
*/
#include "Graph.hpp"
bool ed::Graph::isEmpty() const{
   return vertexes_.empty();
}
bool ed::Graph::isDirected() const{
   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if(matrix_[i][j] != matrix_[j][i]){
            return false;
         }
      }
   }

   return true;
}
bool ed::Graph::adjacent(ed::Vertex u, ed::Vertex v) const{
   if(matrix_[u.getLabel()][v.getLabel()] >= 0){
      return true;
   }
   else{
      return false;
   }
}
bool ed::Graph::hasCurrVertex() const{
   if(currentVertex==NULL){
      return false;
   }
   else{
      return true;
   }
}
ed::Vertex ed::Graph::currVertex() const{
   return *currentVertex;
}
bool ed::Graph::hasCurrEdge() const{
   if(currentEdge==NULL){
      return false;
   }
   else{
      return true;
   }
}
ed::Edge ed::Graph::currEdge() const{
   return *currentEdge;
}
