/*!
   \file Graph.hpp
   \brief Fichero de la clase Graph
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Edge.hpp"
#include <vector>
namespace ed{
   class Graph{
      //! @name Atributos de la clase Graph
      private:
         std::vector<Vertex> vertexs_;
         std::vector<Edge> edges_;
         std::vector<std::vector<int>> matrix_;
      //! @name Metodos publicos de la clase Graph
      public:
         //! @name Constructor de la clase Graph
         Graph();
         //! @name Observadores de la clase Graph
         bool isEmpty() const;
         bool isDirected() const;
         bool adjacent(Vertex u, Vertex v) const;
         bool hasCurrVertex() const;
         Vertex currVertex() const;
         bool hasCurrEdge() const;
         Edge currEdge() const;
         //! @name Modificadores de la clase Graph
         void addVertex(std::vector<float> v);
         void addEdge(Vertex u, Vertex v, float distancia);
         void removeVertex();
         void removeEdge();
         // void findFirstVertex(std::vector<float> v){}
   }:
}
#endif
