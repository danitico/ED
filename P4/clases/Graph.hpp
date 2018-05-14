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
         std::vector<Vertex> vertexes_; //!< Vector de la STL que contiene todos los vertices del grafo
         std::vector<Edge> edges_; //!< Vector de la STL que contiene todos los lados del grafo
         std::vector<std::vector<int>> matrix_; //!< Matriz que representa la matriz de adyacencias del grafo
      //! @name Metodos publicos de la clase Graph
      public:
         //! @name Constructor de la clase Graph
         /**
          * @fn inline Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitacion=0.0)
          * @brief Inicializa un objeto de la clase Medicion
          * @param fecha Objeto de tipo fecha cuyo valor por defecto es Fecha(1,1,1)
          * @param precipitacion Variable de tipo flotante cuyo valor por defecto es 0.0
          * @note Constructor de la clase Medicion
          * @note Función de tipo inline
          * @post getFecha() == fecha
          * @post getPrecipitacion() == precipitacion
          */
         Graph();
         //! @name Observadores de la clase Graph
         /**
          * @fn bool isEmpty() const
          * @brief Nos dice si el grafo esta vacio, es decir, que no tenga ningun vertice
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un valor booleano
          */
         bool isEmpty() const;
         /**
          * @fn bool isDirected() const
          * @brief Nos dice si el grafo es dirigido
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un valor booleano
          */
         bool isDirected() const;
         /**
          * @fn bool adjacent(Vertex u, Vertex v) const
          * @brief Devuelve true si los dos vertices son adyacentes y false en el caso contrario
          * @param u Objeto de la clase Vertex
          * @param v Objeto de la clase Vertex
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre u y v son vertices del grafo
          * @return Devuelve un valor booleano
          */
         bool adjacent(Vertex u, Vertex v) const;
         /**
          * @fn bool hasCurrVertex() const
          * @brief Nos dice si el cursor de vertices apunta a uno de ellos
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un valor booleano
          */
         bool hasCurrVertex() const;
         /**
          * @fn Vertex currVertex() const
          * @brief Nos devuelve el vertice al que apunta el cursor
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un objeto de la clase Vertex
          */
         Vertex currVertex() const;
         /**
          * @fn bool hasCurrEdge() const
          * @brief Devuelve true si el cursor apunta a un lado
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @return Devuelve un valor booleano
          */
         bool hasCurrEdge() const;
         /**
          * @fn Edge currEdge() const
          * @brief Devuelve el lado al que apunta el cursor
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre hasCurrVertex()
          * @return Devuelve un valor booleano
          */
         Edge currEdge() const;
         //! @name Modificadores de la clase Graph
         /**
          * @fn void addVertex(std::vector<float> v)
          * @brief Crea un nuevo vertice
          * @note Modificador de la clase Graph
          * @post hasCurrVertex() && currVertex.getData()=d
          * @return Devuelve un valor booleano
          */
         void addVertex(std::vector<float> v);
         /**
          * @fn void addEdge(Vertex u, Vertex v, float distancia)
          * @brief Crea un enlace entre el vertice u y v
          * @note Modificador de la clase Graph
          * @pre U y V son vertices del grafo
          * @post hasCurrEdge() && currEdge().has(v) && currEdge().other(v)=u && currEdge().getData()=e
          * @post hasCurrVertex() && currVertex.getData()=d
          * @return Devuelve un valor booleano
          */
         void addEdge(Vertex u, Vertex v, float distancia);
         /**
          * @fn void removeVertex()
          * @brief Crea un enlace entre el vertice u y
          * @note Modificador de la clase Graph
          * @pre U y V son vertices del grafo
          * @post hasCurrEdge() && currEdge().has(v) && currEdge().other(v)=u && currEdge().getData()=e
          * @post hasCurrVertex() && currVertex.getData()=d
          * @return Devuelve un valor booleano
          */
         void removeVertex();
         void removeEdge();
         //! @name Modificadores de la clase Graph que se encarga del movimiento del cursor
         void findFirstVertex(Punto const & p);
         // void findNextVertex(Punto const & p); No codificar esta funcion, no tiene sentido
         void findFirstEdge(float distancia);
         void findNextEdge(float distancia);
         void gotoVertex(Vertex const & v);
         void gotoEdge(Vertex const & u, Vertex const & v);
         void goToFirstVertex();
         void nextVertex();
         void goToFirstEdge();
         void nextEdge();
   };
}
#endif
