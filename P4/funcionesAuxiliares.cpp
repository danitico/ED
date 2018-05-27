#include "funcionesAuxiliares.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cfloat>
void ed::cargarVertices(ed::Graph & grafo, std::string fichero){
   std::ifstream archivo(fichero.c_str());

   if(!archivo.is_open()){
      std::cout<<"Error al abrir el fichero"<<std::endl;
   }
   else{
      std::string stream;
      ed::Punto a;

      while(getline(archivo, stream, ' ')){
         a.setX(atof(stream.c_str()));

         getline(archivo, stream, '\n');
         a.setY(atof(stream.c_str()));

         grafo.addVertex(a);
      }
      archivo.close();

      for(int i=0; i<grafo.getVertexVector().size(); i++){
         for(int j=i+1; j<grafo.getVertexVector().size(); j++){
            grafo.addEdge(grafo.getVertexVector()[i], grafo.getVertexVector()[j], ed::distancia(grafo.getVertexVector()[i].getData(), grafo.getVertexVector()[j].getData()));
            grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[grafo.getVertexVector()[i].getLabel()][grafo.getVertexVector()[j].getLabel()]);
         }
      }

      std::cout<<"Fichero cargado con éxito"<<std::endl;
   }
}
ed::Graph ed::prim_algorithm(ed::Graph & grafo){
   ed::Graph resultante;
   float meow=0;
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);
   std::vector<int> visitados(grafo.getVertexVector().size(), 0);
   std::vector<int> verticeInicio(grafo.getVertexVector().size(), -1);
   std::vector<int> coste(grafo.getVertexVector().size(), 1000);

   grafo.goToFirstVertex();
   resultante.addVertex(grafo.currVertex().getData());

   visitados[grafo.currVertex().getLabel()]=1;
   verticeInicio[grafo.currVertex().getLabel()]=-1;
   coste[grafo.currVertex().getLabel()]=0;
   while(visitados!=objetivo){
      float minimo=800;
      int candidato=-1;
      for(int i=0; i<coste.size(); i++){
         if(visitados[i]==0 && coste[i]<1000 && coste[i]<minimo){
            minimo=coste[i];
            candidato=i;
         }
      }
      grafo.goToFirstEdge();
      while(grafo.hasCurrEdge()){
         int a=grafo.currEdge().other(grafo.currVertex()).getLabel();
            if(visitados[a]==0){
               float coste1=coste[a];
               float coste2=grafo.currEdge().getData();

               if(coste2 < coste1){
                  coste[a]=coste2;
                  verticeInicio[a]=grafo.currVertex().getLabel();
               }

               for(int i=0; i<coste.size(); i++){
                  if(visitados[i]==0 && coste[i]<1000 && coste[i]<minimo){
                     minimo=coste[i];
                     candidato=i;
                  }
               }
            }
         grafo.nextEdge();
      }

      visitados[candidato]=1;
      verticeInicio[candidato]=grafo.currVertex().getLabel();
      meow+=coste[candidato];

      resultante.addVertex(grafo.getVertexVector()[candidato].getData());
      resultante.addEdge(grafo.getVertexVector()[verticeInicio[candidato]], grafo.getVertexVector()[candidato], ed::distancia(grafo.getVertexVector()[verticeInicio[candidato]].getData(), grafo.getVertexVector()[candidato].getData()));
      grafo.gotoVertex(grafo.getVertexVector()[candidato]);
   }
   std::cout<<"hey ->"<<meow<<std::endl;
   return resultante;
}
