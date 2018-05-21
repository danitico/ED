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
void ed::Graph::addVertex(Punto p){
   ed::Vertex a;

   a.setData(p);
   a.setLabel(etiquetas);
   etiquetas++;
   vertexes_.push_back(a);
   currentVertex=&vertexes_[vertexes_.size() - 1];

   matrix_.resize(matrix_.size() + 1, -1);
   for(int i=0; i<matrix_.size(); i++){
      matrix_[i].resize(matrix_[i].size() + 1, -1);
   }
}
void ed::Graph::addEdge(Vertex const & u, Vertex const & v, float distancia){
   ed::Edge e;

   e.setFirstVertex(u);
   e.setSecondVertex(v);
   e.setData(distancia);

   edges_.push_back(e);
   currentEdge=&edges_[edges_.size() - 1];

   matrix_[u.getLabel()][v.getLabel()]=edges_.size()-1;
   matrix_[v.getLabel()][u.getLabel()]=edges_.size()-1;
}
void ed::Graph::removeVertex(){//de la manera qu lo voy a hacer, hay que hacer el operator =
   ed::Graph aux;

   //Recorremos el vector de vertices y solo metemos en el nuevo grafo aquel que no sea el current
   for(int i=0; i<vertexes_.size(); i++){
      if(vertexes_[i].getData() != currentVertex->getData()){
         aux.addVertex(vertexes_[i].getData());
      }
   }

   //Vamos viendo las distintas conexiones, ya que es un grafo conexo
   for(int j=0; j<aux.vertexes_.size(); j++){
      for(int k=j+1; k<aux.vertexes_.size(); k++){
         addEdge(aux.vertexes_[j], aux.vertexes_[k], distancia(aux.vertexes_[j], aux.vertexes_[k]));
      }
   }

   *this=aux;//Hay que implementar el operador = en la clase grafo
}
void ed::Graph::removeEdge(){

}
