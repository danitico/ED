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
            grafo.setMatrix(grafo.getVertexVector()[j].getLabel(), grafo.getVertexVector()[i].getLabel(), grafo.getMatrix()[grafo.getVertexVector()[i].getLabel()][grafo.getVertexVector()[j].getLabel()]);
         }
      }

      std::cout<<"Fichero cargado con éxito"<<std::endl;
   }
}
ed::Graph ed::prim_algorithm(ed::Graph & grafo, float & coste_total){
   ed::Graph resultante; //grafo resultante

   // Vector objetivo. Que todos los nodos se visiten
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);
   // Vector que representa el vector de visitados
   std::vector<int> visitados(grafo.getVertexVector().size(), 0);
   // Vector que tienen el vertice de inicio
   std::vector<int> verticeInicio(grafo.getVertexVector().size(), -1);
   // Vector que representa el coste desde el verticeInicio hasta el vertice actual
   std::vector<int> coste(grafo.getVertexVector().size(), 1000);

   grafo.goToFirstVertex();
   // Metemos el primer vertice en el grafo resultante
   resultante.addVertex(grafo.currVertex().getData());
   std::cout<<grafo.currVertex().getLabel()<<" -> "<<resultante.currVertex().getLabel()<<std::endl;
   // Ponemos que ese nodo ya ha sido visitado
   visitados[grafo.currVertex().getLabel()]=1;
   // Ponemos que el primer nodo no tiene un predecesor
   verticeInicio[grafo.currVertex().getLabel()]=-1;
   // Ponemos que su coste es 0
   coste[grafo.currVertex().getLabel()]=0;
   // Mientras no tengamos el objetivo, es decir, visitar todos...
   while(visitados!=objetivo){
      float minimo=800;
      int candidato=-1;

      // Nos vamos a la primera conexion del primer vertice
      grafo.goToFirstEdge();
      //grafo.currEdge().other(grafo.currVertex()).getData().escribirPunto();
      // Mientras haya nodos adyacentes
      while(grafo.hasCurrEdge()){
         // obtenemos el indice del extremo de ese lado, es decir, aquel que no es vertex
         int a=grafo.currEdge().other(grafo.currVertex()).getLabel();
            // si vemos que no ha sido visitado
            if(visitados[a]==0){
               float coste1=coste[a];
               float coste2=grafo.currEdge().getData();
               // Vemos si el coste para llegar a este vertice desde este lado
               // es mejor que su coste anterior (es decir, que sea menor)
               // Si es asi se actualiza y actualizamos su predecesor
               if(coste2 < coste1){
                  coste[a]=coste2;
                  verticeInicio[a]=grafo.currVertex().getLabel();
               }
            }
         // Nos movemos a la siguiente conexion
         grafo.nextEdge();
      }
      // Vemos si este es el de menor coste, y actualizamos informacion
      for(int i=0; i<coste.size(); i++){
         if(visitados[i]==0 && coste[i]<1000 && coste[i]<minimo){
            minimo=coste[i];
            candidato=i;
         }
      }

      // Una vez aqui, el nodo candidato, es decir, aquel que tenemos a menos distancia
      // lo marcamos como visitado y decimos que su precedente es el vertice actual
      visitados[candidato]=1;

      // Obtenemos el nodo origen y lo guardamos en el vector de verticeInicio
      for(int l=0; l<grafo.getEdgeVector().size(); l++){
         if(grafo.getEdgeVector()[l].has(grafo.getVertexVector()[candidato])){
            if(visitados[grafo.getEdgeVector()[l].other(grafo.getVertexVector()[candidato]).getLabel()]==1){
               if(std::abs(grafo.getEdgeVector()[l].getData()-coste[candidato])<COTA_ERROR){
                  verticeInicio[candidato]=grafo.getEdgeVector()[l].other(grafo.getVertexVector()[candidato]).getLabel();//aqui esta el fallo
                  break;
               }
            }
         }
      }

      // En esta variable guardamos cual va a ser la longitud del arbol abarcador
      // std::cout << "---->>>> " << coste[candidato] <<'\n';
      coste_total+=coste[candidato];

      // Añadimos este vertice al grafo resultante
      resultante.addVertex(grafo.getVertexVector()[candidato].getData());
      // Añadimos la conexion entre el vertice candidato y el vertice actual con su distancia
      // std::cout<<grafo.getVertexVector()[candidato].getLabel()<<" -> "<<resultante.currVertex().getLabel()<<std::endl;


      Vertex destinoLado=resultante.currVertex();
      resultante.gotoVertex(grafo.getVertexVector()[verticeInicio[candidato]]);
      Vertex origenNuevoLado=resultante.currVertex();

      resultante.addEdge(origenNuevoLado, destinoLado, coste[candidato]);
      resultante.setMatrix(destinoLado.getLabel(), origenNuevoLado.getLabel(), resultante.getMatrix()[origenNuevoLado.getLabel()][destinoLado.getLabel()]);

      // Le decimos que el siguiente nodo que hay que desplegar es el candidato
      grafo.gotoVertex(grafo.getVertexVector()[candidato]);
   }
   //devolvemos el grafo
   return resultante;
}
ed::Graph ed::kruskal_algorithm(ed::Graph const & grafo, float & coste_total){
   ed::Graph resultante;
   // Vector ordenado que tiene las conexiones del grafo original
   std::vector<ed::Edge> vector_ordenado=grafo.getEdgeVector();
   // Vector que contiene los nodos que estan en un mismo conjunto
   std::vector<int> nodos(grafo.getVertexVector().size(), 0);
   // El objetivo es que todos esten en el mismo conjunto, es decir, que todos los elementos sean = 1
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);

   // Ordenamos los lados de menor a mayor
   std::sort(vector_ordenado.begin(), vector_ordenado.end());

   // Ponemos el nodo 0 en el conjunto 1
   nodos[0]=1;
   // Añadimos el nodo 0 al grafo resultante
   resultante.addVertex(grafo.getVertexVector()[0].getData());

   int indice=0; //Indice del vertice deseado que se va a poner en el mismo conjunto
   int minimo=0; //Declaramos una variable para obtener el coste minimo
   ed::Edge ladocandidato;
   ed::Edge ladoDeseado;

   while (nodos!=objetivo){
      ladocandidato.setData(-1);
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
         // Se distinguen dos casos, que el vertice que se ha desplegado sea second o first
         // Para saber esto, vemos cual no esta en el conjunto
         // gracias al vector nodos
         if(nodos[ladoDeseado.first().getLabel()]==1){
            indice=ladoDeseado.second().getLabel();

            //Preparamos la etiquetas para el grafo resultante
            resultante.addVertex(ladoDeseado.second().getData());
            ed::Vertex aux=ladoDeseado.second();
            aux.setLabel(resultante.getCurrentVertex());
            ladoDeseado.setSecondVertex(aux);

            resultante.gotoVertex(ladoDeseado.first());
            aux=ladoDeseado.first();
            aux.setLabel(resultante.getCurrentVertex());
            ladoDeseado.setFirstVertex(aux);
         }
         else{
            // En el caso que first sea el que se ha desplegado
            if(nodos[ladoDeseado.second().getLabel()]==1){
               indice=ladoDeseado.first().getLabel();

               resultante.addVertex(ladoDeseado.first().getData());
               ed::Vertex aux=ladoDeseado.first();
               aux.setLabel(resultante.getCurrentVertex());
               ladoDeseado.setFirstVertex(aux);

               resultante.gotoVertex(ladoDeseado.second());
               aux=ladoDeseado.second();
               aux.setLabel(resultante.getCurrentVertex());
               ladoDeseado.setSecondVertex(aux);
            }
         }

         //añadir el lado entre el vertice anterior y el vector conjunto visitados
         // std::cout << "----> " << ladoDeseado.getData() <<'\n';
         // Vamos obteniendo la suma del arbol abarcador minimo
         coste_total+=ladoDeseado.getData();
         // std::cout << "pipo -> " << resultante.getMatrix().size() << '\n';
         // std::cout << ladoDeseado.first().getLabel() <<" " << ladoDeseado.second().getLabel() <<'\n';
         //Añadimos la conexion entre los dos vertices
         resultante.addEdge(ladoDeseado.first(), ladoDeseado.second(), ladoDeseado.getData());
         resultante.setMatrix(ladoDeseado.second().getLabel(), ladoDeseado.first().getLabel(), resultante.getMatrix()[ladoDeseado.first().getLabel()][ladoDeseado.second().getLabel()]);
         // Ponemos el vertice añadido en el mismo conjunto
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
void ed::Dijkstra(Graph & grafo, ed::Vertex comienzo, std::vector<float> & distancias, std::vector<int> & predecesor){
   std::vector<int> visitados(grafo.getVertexVector().size(), 0);
   std::vector<int> objetivo(grafo.getVertexVector().size(), 1);
   distancias.resize(grafo.getVertexVector().size(), 1000);
   predecesor.resize(grafo.getVertexVector().size(), -1);

   visitados[comienzo.getLabel()]=1;
   grafo.gotoVertex(comienzo);
   grafo.goToFirstEdge();

   while(grafo.hasCurrEdge()){
      distancias[grafo.currEdge().other(comienzo).getLabel()]=grafo.currEdge().getData();
      predecesor[grafo.currEdge().other(comienzo).getLabel()]=comienzo.getLabel();
      // std::cout << grafo.getCurrentEdge() << '\n';
      grafo.nextEdge();
   }

   ed::Vertex siguiente;
   int minimo, x, indice;
   while(visitados!=objetivo){
      minimo=800;
      for(int i=0; i<visitados.size(); i++){
         if(visitados[i]==0 && distancias[i]<1000 && distancias[i]<=minimo){
            minimo=distancias[i];
            x=i;
         }
      }
      visitados[x]=1;
      for(int k=0; k<grafo.getVertexVector().size(); k++){
         if(grafo.getVertexVector()[k].getLabel()==x){
            siguiente=grafo.getVertexVector()[k];
            break;
         }
      }

      grafo.gotoVertex(siguiente);
      grafo.goToFirstEdge();
      // std::cout << grafo.getCurrentEdge() << '\n';
      indice=grafo.currEdge().other(siguiente).getLabel();
      int pipo=0;
      while(true){
         if(visitados[indice]==0 && distancias[indice]<1000 && distancias[indice] > distancias[x] + grafo.currEdge().getData()){
            distancias[indice]=distancias[x] + grafo.currEdge().getData();
            predecesor[indice]=x;
         }
         grafo.nextEdge();
         std::cout << grafo.getCurrentEdge() << '\n';
         if(-1==-1){
            break;
         }
      }
   }
}
