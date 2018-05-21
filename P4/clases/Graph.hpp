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
// #include "Vertex.hpp"
// #include "Punto.hpp"
#include <vector>
namespace ed{
   class Graph{
      //! @name Atributos de la clase Graph
      private:
         std::vector<Vertex> vertexes_; //!< Vector de la STL que contiene todos los vertices del grafo
         std::vector<Edge> edges_; //!< Vector de la STL que contiene todos los lados del grafo
         std::vector<std::vector<int>> matrix_; //!< Matriz que representa la matriz de adyacencias del grafo
         Vertex *currentVertex;
         Edge *currentEdge;
         int etiquetas;
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
          * @return Devuelve un valor booleano
          */
         bool hasCurrVertex() const;
         /**
          * @fn Vertex currVertex() const
          * @brief Nos devuelve el vertice al que apunta el cursor
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre hasCurrVertex()
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
          * @pre hasCurrEdge()
          * @return Devuelve un objeto de la clase Edge
          */
         Edge currEdge() const;
         //! @name Modificadores de la clase Graph
         /**
          * @fn void addVertex(Punto p)
          * @brief Crea un nuevo vertice
          * @note Modificador de la clase Graph
          * @param p Posicion del vertice
          * @post hasCurrVertex() && currVertex.getData()=d
          */
         void addVertex(Punto p);
         /**
          * @fn void addEdge(Vertex u, Vertex v, float distancia)
          * @brief Crea un enlace entre el vertice u y v
          * @note Modificador de la clase Graph
          * @param u Vertice inicio
          * @param v Vertice final
          * @param distancia Distancia entre el vertice inicio y final
          * @pre U y V son vertices del grafo
          * @post hasCurrEdge() && currEdge().has(v) && currEdge().other(v)=u && currEdge().getData()=e
          * @post hasCurrVertex() && currVertex.getData()=d
          */
         void addEdge(Vertex u, Vertex v, float distancia);
         /**
          * @fn void removeVertex()
          * @brief Borra el vertice actual y todas sus conexiones o lados
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void removeVertex();
         /**
          * @fn void removeEdge()
          * @brief Borra el lado actual
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void removeEdge();
         //! @name Modificadores de la clase Graph que se encarga del movimiento del cursor
         /**
          * @fn void findFirstVertex(Punto const & p)
          * @brief Busca el vertice con la posicion que se la ha pasado por argumentos
          * @param p Objeto de la clase Punto que representa la posicion del vertice
          * @note Modificador de la clase Graph
          * @post hasCurrVertex() implies currVertex().getData()=d
          */
         void findFirstVertex(Punto const & p);
         // void findNextVertex(Punto const & p); No codificar esta funcion, no tiene sentido
         /**
          * @fn void findFirstEdge(float distancia)
          * @brief Busca el lado que tenga la distancia que se le ha pasado por argumentos
          * @param distancia Distancia entre un vertice y otro
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge() implies currEdge().getData()=d
          */
         void findFirstEdge(float distancia);
         /**
          * @fn void findNextEdge(float distancia)
          * @brief Busca el siguiente lado utlizando el argumento pasado a la funcion
          * @param distancia Distancia entre un vertice y otro
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge() implies currEdge().getData()=d
          */
         void findNextEdge(float distancia);
         /**
          * @fn void gotoVertex(Vertex const & v)
          * @brief Mueve el cursor al vertice pasado por argumentos
          * @param v Objeto de la clase Vertex
          * @note Modificador de la clase Graph
          * @pre v es un vértice del grafo
          * @post currVertex().getData()=v.getData()
          */
         void gotoVertex(Vertex const & v);
         /**
          * @fn void gotoEdge(Vertex const & u, Vertex const & v)
          * @brief Mueve el cursor hacia el lado que conectan los dos vertices pasados por argumentos
          * @param u Objeto de la clase Vertex
          * @param v Objeto de la clase Vertex
          * @note Modificador de la clase Graph
          * @pre u,v son vértices del grafo
          * @post hasCurrEdge() implies currVertex()=u
          * @post currEdge().first()=u
          * @post currEdge().second()=v
          */
         void gotoEdge(Vertex const & u, Vertex const & v);
         /**
          * @fn void goToFirstVertex()
          * @brief El cursor se mueve al primer vértice
          * @note Modificador de la clase Graph
          * @post isEmpty() implies not hasCurrVertex()
          */
         void goToFirstVertex();
         /**
          * @fn void nextVertex()
          * @brief El cursor se mueve al siguiente vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void nextVertex();
         /**
          * @fn void goToFirstEdge()
          * @brief El cursor se mueve a la primera conexión del vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge()
          * @post isDirected() implies currVertex()==currEdge().first()
          * @post not isDirected( implies currEdge().has(currVertex())
          */
         void goToFirstEdge();
         /**
          * @fn void nextEdge()
          * @brief El cursor se mueve a la siguiente conexión del vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge()
          * @post isDirected() implies currVertex()==currEdge().first()
          * @post not isDirected( implies currEdge().has(currVertex())
          */
         void nextEdge();
         //! @name Operadores de la clase Graph
         /**
          * @fn Graph & operator=(Graph const &g)
          * @brief Operador = sobrecargado
          * @note Operador sobrecargado de la clase Graph
          * @pre *this != g
          * @return Objeto de la clase Graph
          */
         Graph & operator=(Graph const &g);
   };
}
#endif
