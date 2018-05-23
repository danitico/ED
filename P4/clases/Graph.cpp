/*!
   \file Graph.cpp
   \brief Fichero de la clase Graph
   \author Daniel Ranchal Parrado
   \date
*/
#include "Graph.hpp"
bool ed::Graph::isEmpty() const{
   return vertexes_.empty() && edges_.empty() && matrix_.empty();
}
bool ed::Graph::isDirected() const{
   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if((matrix_[i][j] != matrix_[j][i]) && i!=j){
            return true;
         }
      }
   }

   return false;
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
   if(currentVertex==-1){
      return false;
   }
   else{
      return true;
   }
}
ed::Vertex ed::Graph::currVertex() const{
   return vertexes_[currentVertex];
}
bool ed::Graph::hasCurrEdge() const{
   if(currentEdge==-1){
      return false;
   }
   else{
      return true;
   }
}
ed::Edge ed::Graph::currEdge() const{
   return edges_[currentEdge];
}
void ed::Graph::addVertex(Punto p){
   ed::Vertex a;

   a.setData(p);
   a.setLabel(etiquetas);
   etiquetas++;
   vertexes_.push_back(a);
   currentVertex=vertexes_.size()-1;

   matrix_.resize(matrix_.size() + 1);
   for(int i=0; i<matrix_.size(); i++){
      matrix_[i].resize(matrix_.size(), -1);
   }
}
void ed::Graph::addEdge(Vertex const & u, Vertex const & v, float distancia){
   ed::Edge e;

   e.setFirstVertex(u);
   e.setSecondVertex(v);
   e.setData(distancia);

   edges_.push_back(e);
   // currentEdge=edges_.size()-1;

   matrix_[u.getLabel()][v.getLabel()]=edges_.size()-1;
   matrix_[v.getLabel()][u.getLabel()]=edges_.size()-1;
}
void ed::Graph::removeVertex(){//de la manera qu lo voy a hacer, hay que hacer el operator =
   ed::Graph aux;

   //Recorremos el vector de vertices y solo metemos en el nuevo grafo aquel que no sea el current
   for(int i=0; i<vertexes_.size(); i++){
      if(!(vertexes_[i].getData() == vertexes_[currentVertex].getData())){
         aux.addVertex(vertexes_[i].getData());
      }
   }

   //Vamos viendo las distintas conexiones, ya que es un grafo conexo
   for(int j=0; j<aux.vertexes_.size(); j++){
      for(int k=j+1; k<aux.vertexes_.size(); k++){
         aux.addEdge(aux.vertexes_[j], aux.vertexes_[k], ed::distancia(aux.vertexes_[j].getData(), aux.vertexes_[k].getData()));
      }
   }

   *this=aux;
}
void ed::Graph::removeEdge(){
   int posicion=currentEdge;

   std::swap(edges_[currentEdge], edges_[edges_.size() - 1]);
   currentEdge=edges_.size()-1;

   for(int i=0; i<matrix_.size(); i++){
      for(int j=0; j<matrix_.size(); j++){
         if(matrix_[i][j]==currentEdge){
            matrix_[i][j]=posicion;
         }
         else{
            if(matrix_[i][j]==posicion){
               matrix_[i][j]=-1;
            }
         }
      }
   }
   currentEdge=-1;
   edges_.resize(edges_.size()-1);
}
void ed::Graph::gotoVertex(ed::Vertex const & v){
   for(int i=0; i<vertexes_.size(); i++){
      if(vertexes_[i]==v){
         currentVertex=i;
         break;
      }
   }
}
void ed::Graph::gotoEdge(ed::Vertex const & u, ed::Vertex const & v){
   for(int i=0; i<edges_.size(); i++){
      if(edges_[i].has(u) && edges_[i].has(v)){
         currentEdge=i;
         break;
      }
   }
}
void ed::Graph::goToFirstVertex(){
   if(vertexes_.size()==0){
      currentVertex=-1;
   }
   else{
      currentVertex=0;
   }
}
void ed::Graph::nextVertex(){
   if(currentVertex+1 < vertexes_.size()){
      currentVertex++;
   }
   else{
      currentVertex=-1;
   }
}
void ed::Graph::goToFirstEdge(){
   if(edges_.size()==0){
      currentEdge=-1;
   }
   else{
      currentEdge=-1;
      for(int i=0; i<edges_.size(); i++){
         if(edges_[i].has(vertexes_[currentVertex])){
            currentEdge=i;
            break;
         }
      }
   }
}
void ed::Graph::nextEdge(){
   int ultimoEdgeconocido=currentEdge;
   currentEdge=-1;
   for(int i=ultimoEdgeconocido+1; i<edges_.size(); i++){
      if(edges_[i].has(vertexes_[currentVertex])){
         currentEdge=i;
         break;
      }
   }
}
ed::Graph & ed::Graph::operator=(Graph const &g){
   this->vertexes_=g.vertexes_;
   this->edges_=g.edges_;
   this->matrix_=g.matrix_;
   this->etiquetas=g.etiquetas;
   this->currentVertex=g.currentVertex;
   this->currentEdge=g.currentEdge;

   return *this;
}
