#include "funcionesAuxiliares.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cfloat>
#include <algorithm>
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
            //grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[grafo.getVertexVector()[i].getLabel()][grafo.getVertexVector()[j].getLabel()]);
         }
      }

      std::cout<<"Fichero cargado con éxito"<<std::endl;
   }
}
ed::Graph ed::prim_algorithm(ed::Graph & grafo, float & coste_total){
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
      coste_total+=coste[candidato];

      resultante.addVertex(grafo.getVertexVector()[candidato].getData());
      resultante.addEdge(grafo.getVertexVector()[verticeInicio[candidato]], grafo.getVertexVector()[candidato], ed::distancia(grafo.getVertexVector()[verticeInicio[candidato]].getData(), grafo.getVertexVector()[candidato].getData()));
      grafo.gotoVertex(grafo.getVertexVector()[candidato]);
   }
   return resultante;
}
ed::Graph ed::kruskal_algorithm(ed::Graph const & grafo, float & coste_total){
   ed::Graph resultante;
   std::vector<ed::Edge> vector_ordenado=grafo.getEdgeVector();
   std::vector<int> nodos(grafo.getVertexVector().size(), 0);
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);

   std::sort(vector_ordenado.begin(), vector_ordenado.end());

   nodos[0]=1;
   resultante.addVertex(grafo.getVertexVector()[0].getData());

   int indice=0;

   int minimo=0;
   while (nodos!=objetivo){
      ed::Edge ladocandidato;
      ladocandidato.setData(-1);
      ed::Edge ladoDeseado;
      ladoDeseado.setData(-1);
      minimo=1000;
      for(int i=0; i<nodos.size(); i++){
         if(nodos[i]==1){
            for(int j=0; j<nodos.size(); j++){
               if(nodos[j]==0){
                  for(int k=0; k<vector_ordenado.size(); k++){
                     if(vector_ordenado[k].has(grafo.getVertexVector()[i]) && vector_ordenado[k].has(grafo.getVertexVector()[j])){
                        ladocandidato.setFirstVertex(vector_ordenado[k].first());
                        ladocandidato.setSecondVertex(vector_ordenado[k].second());
                        ladocandidato.setData(vector_ordenado[k].getData());
                        break;
                     }
                  }
                  if(ladocandidato.getData() < minimo){
                     minimo=ladocandidato.getData();
                     ladoDeseado=ladocandidato;
                  }
               }
            }
         }
      }
      if(ladoDeseado.getData()>-1){
         //añadir el vertice que se ha desplegado
         if(nodos[ladoDeseado.first().getLabel()]==1){
            indice=ladoDeseado.second().getLabel();
            resultante.addVertex(ladoDeseado.second().getData());
         }
         else{
            if(nodos[ladoDeseado.second().getLabel()]==1){
               indice=ladoDeseado.first().getLabel();
               resultante.addVertex(ladoDeseado.first().getData());
            }
         }
         //añadir el lado entre el vertice anterior y el vector conjunto visitados
         coste_total+=ladoDeseado.getData();
         resultante.addEdge(ladoDeseado.first(), ladoDeseado.second(), ladoDeseado.getData());
         nodos[indice]=1;

         //borrar lado del vector ordenado y ordenarlo otra vez
         int etiqueta=0;
         for(; etiqueta<vector_ordenado.size(); etiqueta++){
            if(vector_ordenado[etiqueta].has(ladoDeseado.first()) && vector_ordenado[etiqueta].has(ladoDeseado.second())){
               break;
            }
         }
         std::swap(vector_ordenado[etiqueta], vector_ordenado[vector_ordenado.size()-1]);
         vector_ordenado.resize(vector_ordenado.size()-1);

         std::sort(vector_ordenado.begin(), vector_ordenado.end());
      }
   }
   return resultante;
}
