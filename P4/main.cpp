#include <iostream>
#include "./clases/Graph.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   ed::Graph a,b,c;

   // a.addVertex(ed::Punto(0.0, 0.1));
   // a.addVertex(ed::Punto(0.0, 0.2));
   // a.addVertex(ed::Punto(0.0, 0.3));
   // a.addVertex(ed::Punto(0.0, 0.4));
   // a.addVertex(ed::Punto(0.0, 0.5));
   // a.addVertex(ed::Punto(0.0, 0.6));
   // a.addVertex(ed::Punto(0.0, 0.7));
   // a.addVertex(ed::Punto(0.0, 0.8));
   //
   // // for(int i=0; i<5; i++){
   // //    for(int j=0; j<5; j++){
   // //       std::cout<<a.getMatrix()[i][j]<<" ";
   // //    }
   // //    std::cout<<std::endl;
   // // }
   //
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[1], 4.0);
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[2], 1.0);
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[6], 6.0);
   // a.addEdge(a.getVertexVector()[1], a.getVertexVector()[3], 2.0);
   // a.addEdge(a.getVertexVector()[1], a.getVertexVector()[7], 2.0);
   // a.addEdge(a.getVertexVector()[2], a.getVertexVector()[6], 2.0);
   // a.addEdge(a.getVertexVector()[2], a.getVertexVector()[4], 1.0);
   // a.addEdge(a.getVertexVector()[3], a.getVertexVector()[7], 1.0);
   // a.addEdge(a.getVertexVector()[3], a.getVertexVector()[5], 1.0);
   // a.addEdge(a.getVertexVector()[4], a.getVertexVector()[5], 3.0);
   // a.addEdge(a.getVertexVector()[6], a.getVertexVector()[7], 10.0);

   ed::cargarVertices(a, "vertices.txt");

   // a.addVertex(ed::Punto(0.0, 0.1));
   // a.addVertex(ed::Punto(0.0, 0.2));
   // a.addVertex(ed::Punto(0.0, 0.3));
   // a.addVertex(ed::Punto(0.0, 0.4));
   // a.addVertex(ed::Punto(0.0, 0.5));
   //
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[1], 8.0);
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[2], 4.0);
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[3], 6.0);
   // a.addEdge(a.getVertexVector()[0], a.getVertexVector()[4], 2.0);
   // a.addEdge(a.getVertexVector()[1], a.getVertexVector()[4], 5.0);
   // a.addEdge(a.getVertexVector()[1], a.getVertexVector()[2], 9.0);
   // a.addEdge(a.getVertexVector()[2], a.getVertexVector()[3], 7.0);
   // a.addEdge(a.getVertexVector()[3], a.getVertexVector()[4], 3.0);

   float coste=0;
   c=ed::prim_algorithm(a, coste);
   for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
         std::cout<<c.getMatrix()[i][j]<<" ";
      }
      std::cout<<std::endl;
   }
   std::cout<<"El coste total del árbol abarcador de coste mínimo es "<<coste<<std::endl;
   // coste=0;
   // b=ed::kruskal_algorithm(a, coste);
   // std::cout<<"El coste total del árbol abarcador de coste mínimo es "<<coste<<std::endl;
   // for(int i=0; i<5; i++){
   //    for(int j=0; j<5; j++){
   //       std::cout<<b.getMatrix()[i][j]<<" ";
   //    }
   //    std::cout<<std::endl;
   // }

   // std::vector<float> distancias;
   // std::vector<int> predecesor;
   // ed::Vertex comienzo;
   //
   // comienzo.setData(ed::Punto(0.0, 0.0));
   // comienzo.setLabel(0);

   // ed::Dijkstra(a, comienzo, distancias, predecesor);

   // for(int i=0; i<a.getVertexVector().size(); i++){
   //    std::cout << distancias[i] << " " << predecesor[i] << '\n';
   // }


}
