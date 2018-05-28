#include <iostream>
#include "./clases/Graph.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   ed::Graph a,b;

   a.addVertex(ed::Punto(0.0, 0.1));
   a.addVertex(ed::Punto(0.0, 0.2));
   a.addVertex(ed::Punto(0.0, 0.3));
   a.addVertex(ed::Punto(0.0, 0.4));
   a.addVertex(ed::Punto(0.0, 0.5));

   // for(int i=0; i<5; i++){
   //    for(int j=0; j<5; j++){
   //       std::cout<<a.getMatrix()[i][j]<<" ";
   //    }
   //    std::cout<<std::endl;
   // }

   a.addEdge(a.getVertexVector()[0], a.getVertexVector()[1], 8.0);
   a.addEdge(a.getVertexVector()[0], a.getVertexVector()[2], 4.0);
   a.addEdge(a.getVertexVector()[0], a.getVertexVector()[3], 6.0);
   a.addEdge(a.getVertexVector()[0], a.getVertexVector()[1], 2.0);
   a.addEdge(a.getVertexVector()[1], a.getVertexVector()[4], 5.0);
   a.addEdge(a.getVertexVector()[1], a.getVertexVector()[2], 9.0);
   a.addEdge(a.getVertexVector()[2], a.getVertexVector()[3], 7.0);
   a.addEdge(a.getVertexVector()[3], a.getVertexVector()[4], 3.0);

   // for(int i=0; i<5; i++){
   //    for(int j=0; j<5; j++){
   //       std::cout<<a.getMatrix()[i][j]<<" ";
   //    }
   //    std::cout<<std::endl;
   // }
   float coste=0;
   // b=ed::prim_algorithm(a, coste);
   b=ed::kruskal_algorithm(a, coste);
   std::cout<<"El coste total del árbol abarcador de coste mínimo es "<<coste<<std::endl;
   for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
         std::cout<<b.getMatrix()[i][j]<<" ";
      }
      std::cout<<std::endl;
   }

}
